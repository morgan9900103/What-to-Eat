#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <cstdlib>


int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Please provide restaurant list" << std::endl;
    std::cout << "Usage: " << argv[0] << " <list>" << std::endl;
    return -1;
  }
  
  // Read file
  std::ifstream input_file;
  input_file.open(std::string(argv[1]));
  std::vector<std::string> restaurants;
  if (input_file.is_open()) {
    std::string line;
    while (input_file.good()) {
      std::getline(input_file, line);
      if (line.empty() || line.at(0) == '#') {
        continue;
      }
      restaurants.emplace_back(line);
    }
  }

  // Init rand()
  srand(time(0));

  std::cout << restaurants.at(rand() % restaurants.size()) << std::endl;

  return 0;
}
