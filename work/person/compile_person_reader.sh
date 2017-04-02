#!/bin/bash

gcc person_reader.cpp person.pb.cc -o person_reader -pthread -I/usr/local/include -L/usr/local/lib -lprotobuf -lpthread -L/usr/lib64 -lstdc++
