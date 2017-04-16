lib_path:=/usr/local/lib

all: restserver restclient

restserver:
	g++ -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0 -fno-strict-aliasing -O3 -DNDEBUG restserver.cpp -o restserver -L/usr/lib64 -lstdc++ -rdynamic ./libcpprest.so.2.6 $(lib_path)/libboost_random.so $(lib_path)/libboost_chrono.so $(lib_path)/libboost_system.so $(lib_path)/libboost_thread.so $(lib_path)/libboost_regex.so $(lib_path)/libboost_filesystem.so $(lib_path)/libboost_date_time.so $(lib_path)/libboost_atomic.so -lpthread -lpthread $(lib_path)/libboost_random.so $(lib_path)/libboost_chrono.so $(lib_path)/libboost_system.so $(lib_path)/libboost_thread.so -lssl -lcrypto $(lib_path)/libboost_atomic.so -Wl,-rpath

restclient:
	g++ -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0 -fno-strict-aliasing -O3 -DNDEBUG restclient.cpp -o restclient -L/usr/lib64 -lstdc++ -rdynamic ./libcpprest.so.2.6 $(lib_path)/libboost_random.so $(lib_path)/libboost_chrono.so $(lib_path)/libboost_system.so $(lib_path)/libboost_thread.so $(lib_path)/libboost_regex.so $(lib_path)/libboost_filesystem.so $(lib_path)/libboost_date_time.so $(lib_path)/libboost_atomic.so -lpthread -lpthread $(lib_path)/libboost_random.so $(lib_path)/libboost_chrono.so $(lib_path)/libboost_system.so $(lib_path)/libboost_thread.so -lssl -lcrypto $(lib_path)/libboost_atomic.so -Wl,-rpath
