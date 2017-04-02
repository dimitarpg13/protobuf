include_path:=/usr/local/include
library_path:=/usr/local/lib

objects = person_test.o person_writer.o person_reader.o socket_server.o socket_client.o

all: person_test person_reader person_writer socket_server socket_client

person_test:
	gcc person_test.cpp person.pb.cc -o person_test -pthread -I$(include_path) -L$(library_path) -lprotobuf -lpthread -L/usr/lib64 -lstdc++

person_reader: 
	gcc person_reader.cpp person.pb.cc -o person_reader -pthread -I$(include_path) -L$(library_path) -lprotobuf -lpthread -L/usr/lib64 -lstdc++

person_writer:
	gcc person_writer.cpp person.pb.cc -o person_writer -pthread -I$(include_path) -L$(library_path) -lprotobuf -lpthread -L/usr/lib64 -lstdc++


socket_server:
	gcc socket_server.c -o socket_server -lsocket++

socket_client:
	gcc socket_client.c -o socket_client -lsocket++

.PHONY: clean
clean:
	rm -f $(objects) person_test person_reader person_writer socket_server socket_client 

