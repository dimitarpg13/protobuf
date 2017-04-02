#!/bin/bash

gcc person_writer.cpp person.pb.cc -o person_writer -pthread -I/usr/local/include -L/usr/local/lib -lprotobuf -lpthread -L/usr/lib64 -lstdc++
