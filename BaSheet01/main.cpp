#include"mainIncludes.h"

#include <iostream>

#include <future>

int main(){
  std::cout << "Starting task 3..." << std::endl;
  std::async(std::launch::async, main3);
  std::cout << "Starting task 6..." << std::endl;
  std::async(std::launch::async, main6);
  std::cout << "Starting task 9..." << std::endl;
  main9();
  std::cout << "Over and out." << std::endl << std::endl;
  return 0;
}
