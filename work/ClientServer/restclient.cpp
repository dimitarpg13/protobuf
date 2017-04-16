#include <cpprest/http_client.h>
#include <cpprest/json.h>
#pragma comment(lib, "cpprest290_1_1")

using namespace web;
using namespace web::http;
using namespace web::http::client;

#include <iostream>
using namespace std;

void display_field_map_json(json::value & jvalue)
{
   if (!jvalue.is_null())
   {
      for (auto const & e : jvalue.as_object())
      {
        cout << e.first << L" : " << e.second << endl;
      }

   }

}


pplx::task<http_response> make_task_request(http_client & client,
					    method mtd,
 					    json::value const & jvalue)
{
   return (mtd == methods::GET || mtd == methods::HEAD) ?
      client.request(mtd, u8"/restdemo") :
      client.request(mtd, u8"/restdemo", jvalue);
}


void make_request(http_client & client, method mtd, json::value const & jvalue)
{
  make_task_request(client, mtd, jvalue)
      .then([](http_response response)
      {
         if (response.status_code() == status_codes::OK)
         {
            return response.extract_json();
         }
         return pplx::task_from_result(json::value());
      })
      .then([](pplx::task<json::value> previousTask)
      {
         try
         {
            json::value temp =previousTask.get();
            display_field_map_json(temp);
         }
         catch (http_exception const & e)
         {
           cout << e.what() << endl;
         }
      })
      .wait();
}

int main()
{
   http_client client(u8"http://localhost:34568/restdemo");
   
   json::value putvalue;
   putvalue[u8"one"]= json::value::string(u8"100");
   putvalue[u8"two"]= json::value::string(u8"200");

   cout << u8"\ninput values\n";
   make_request(client, methods::PUT, putvalue);

   auto getvalue = json::value::array();
   getvalue[0] = json::value(u8"one");
   getvalue[1] = json::value(u8"two");
   getvalue[2] = json::value(u8"three");

   wcout << u8"\nget values (POST)\n";
   make_request(client, methods::POST, getvalue);

   auto delvalue = json::value::array();
   delvalue[0] = json::value(u8"one");
  
   wcout << u8"\ndelete values\n";
   make_request(client, methods::DEL, delvalue);

   wcout << u8"\nget values (POST)\n";
   make_request(client, methods::POST, getvalue); 

   wcout << u8"\nget values (GET)\n";
   make_request(client, methods::GET, json::value::null());

   return 0;

}
