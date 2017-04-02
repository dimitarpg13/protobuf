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
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (false == file.fail()) {
      person.ParseFromIstream(&file);
    }
  
}
