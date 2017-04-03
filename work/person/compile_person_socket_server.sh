#!/bin/bash
gcc person_socket_server.cpp person.pb.cc -o person_socket_server -pthread -I/usr/local/include -L/usr/local/lib -lprotobuf -lpthread -lsocket++ -L/usr/lib64 -lstdc++
gcc person_socket_client.cpp person.pb.cc -o person_socket_client -pthread -I/usr/local/include -L/usr/local/lib -lprotobuf -lpthread -lsocket++ -L/usr/lib64 -lstdc++
gcc person_socket_server.cpp person.pb.cc -o person_socket_server -pthread -I/usr/local/include -L/usr/local/lib -lprotobuf -lpthread -lsocket++ -L/usr/lib64 -lstdc++
