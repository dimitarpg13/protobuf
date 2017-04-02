#include "person.pb.h"
#include <fstream>
#include <iostream>
#include <cstring>

int main(int argc, char * argv[])
{
  if (argc < 2)
  {
     std::cout << "Insufficient number of arguments!" << std::endl;
     std::cout << "Specify at least -filename" << std::endl;
     return -1;
  }

  int filenameIdx = 1;
  
  char * cFilename = NULL; 
  if (argc > 2)
  {
    while (std::strcmp(argv[filenameIdx],"-f") != 0 && 
           std::strcmp(argv[filenameIdx],"-filename") != 0) 
    {

      filenameIdx++;
    }
    if (filenameIdx == 1 && 
        std::strcmp(argv[filenameIdx],"-f") != 0 &&
        std::strcmp(argv[filenameIdx],"-filename") != 0)
    {
      std::cout << "Filename needs to be specified using -fiename!" << std::endl; 

    }
  }
  cFilename=argv[filenameIdx];
  std::string filename(cFilename);

  Person person;
  person.set_id(1);
  person.set_name("Hans Mustermann");

  person.set_email("hans@muster.mann");

  // std::string *name = person.mutable_name();
  // *name = "Hans Mustermann";

  Person::PhoneNumber *phone;
  phone = person.add_phone();
  phone->set_number("030 12345678");
  phone->set_type(Person::WORK);
  phone = person.add_phone();
  phone->set_number("0170 987654321");
  phone->set_type(Person::MOBILE);

	// check for validity: person.IsInitialized() == true ?
  std::ofstream file(filename, std::ios::out | std::ios::binary);
  if (false == file.fail()) {
    person.SerializeToOstream(&file);
  }
}
