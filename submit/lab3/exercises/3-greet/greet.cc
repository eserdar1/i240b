#include <iostream>
#include <cstdlib>
#include <cstring>

#define GREET "hello"

static std::string
greetMsg(const char *name)
{
  printf("%ld\n", sizeof(std::string(GREET) + ' ' + std::string(name)));//std::string has a smart pointer behind that's why there is no delete
  return std::string(GREET) + ' ' + std::string(name); // adding char *pointer and std::string may occur weird output.
  	
}

int 
main(int argc, const char *argv[])
{
  if (argc == 1) {
    std::cerr << "usage: " << argv[0] << " NAME..." << std::endl;
    std::exit(1);
  }
  else {
    for (int i = 1; i < argc; i++) {
      std::cout << greetMsg(argv[i]) << std::endl;
    }
  }
}
