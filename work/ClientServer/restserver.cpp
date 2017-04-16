#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#pragma comment(lib, "cpprest290_1_1")

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

#define TRACE(msg)	cout << msg
#define TRACE_ACTION(a, k, v) cout << a << u8" (" << k << u8", " << v << u8")\n"

map<utility::string_t, utility::string_t> dictionary;

/* handlers declarations */
void handle_get(http_request request);
void handle_post(http_request request);
void handle_put(http_request request);
void handle_del(http_request request);

int main()
{
   utility::string_t uri_str = u8"http://localhost/restdemo";
   uri myuri(uri_str);
   http_listener mylistener(u8"http://localhost:34568/restdemo");

   mylistener.support(methods::GET, handle_get);
   mylistener.support(methods::POST, handle_post);
   mylistener.support(methods::PUT, handle_put);
   mylistener.support(methods::DEL, handle_del); 

   try
   {
     mylistener
        .open()
        .then([&mylistener](){TRACE(u8"\nstarting to listen\n");})
        .wait();

     while (true);
   }
   catch (exception const & e)
   {
     cout << e.what() << endl;
   }

   return 0;

}

/* hanlders implemenations */

void handle_get(http_request request)
{
  TRACE(u8"\nhandle GET\n");

  json::value answer;

  for (auto const & p : dictionary)
  {
    answer[p.first] = json::value::string(p.second);
  } 

  request.reply(status_codes::OK, answer);
}

void handle_request(http_request request,
                    function<void(json::value &, json::value &)> action)
{
   json::value answer;

   request
       .extract_json()
       .then([&answer, &action](pplx::task<json::value> task) {
          try
          {
            auto temp = task.get();
            auto & jvalue = temp;
            if (!jvalue.is_null())
            {
              action(jvalue, answer);
            }
          }
          catch (http_exception const & e)
          {
             cout << e.what() << endl;
          }
       })
       .wait();
     
     request.reply(status_codes::OK, answer);
}

void handle_post(http_request request)
{
   TRACE(u8"\nhandle POST\n");

   handle_request(
       request,
       [](json::value & jvalue, json::value & answer)
       {
         for (auto const & e : jvalue.as_object())
         {
            if (e.second.is_string())
            {
               auto key = e.second.as_string();
               auto pos = dictionary.find(key);
               if (pos == dictionary.end())
               {
                 answer[key] = json::value::string(u8"<nil>");
               }
               else
               {
                 answer[pos->first]= json::value::string(pos->second);
               }
            }
         }
       }
    );
}

void handle_put(http_request request)
{
   TRACE(u8"\nhandle PUT\n");

   handle_request(
       request,
       [](json::value & jvalue, json::value & answer)
       {
           for (auto const & e : jvalue.as_object())
           {
               //if (e.is_string())
               {
                  auto key = e.first;
                  auto value = e.second;

                  if (dictionary.find(key) == dictionary.end())
                  {
                     TRACE_ACTION(u8"added", key, value);
                     answer[key] = json::value::string(u8"<put>");
                  }
                  else
                  {
                     TRACE_ACTION(u8"updated", key, value);
                     answer[key] = json::value::string(u8"<updated>");
                  }

                  dictionary[key] = value.as_string();
               }
           }
       }
    );
}


void handle_del(http_request request)
{
   TRACE(u8"\nhandle DEL\n");

   handle_request(
       request,
       [](json::value & jvalue, json::value & answer)
       {
          set<utility::string_t> keys;
          for (auto const & e : jvalue.as_object())
          {
             if (e.second.is_string())
             {
                auto key = e.second.as_string();
                auto pos = dictionary.find(key);
                if (pos == dictionary.end())
                {
                   answer[key] = json::value::string(u8"<failed>");
                }
                else
                {
                   TRACE_ACTION(u8"deleted", pos->first, pos->second);
                   answer[key] = json::value::string(u8"<deleted>");
                   keys.insert(key); 
                }
             }
          }
      
          for (auto const & key : keys)
              dictionary.erase(key);

       }
   );
}
