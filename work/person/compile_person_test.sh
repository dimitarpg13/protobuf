#!/bin/bash

gcc person_test.cpp person.pb.cc -o person_test -pthread -I/usr/local/include -L/usr/local/lib -lprotobuf -lpthread -L/usr/lib64 -lstdc++
