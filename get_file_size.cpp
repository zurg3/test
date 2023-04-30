/*
g++ get_file_size.cpp -std=c++20 -o get_file_size_cpp
*/

#include <iostream>
#include <filesystem>
using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 2) {
    try {
      int size = filesystem::file_size(argv[1]);

      cout << argv[1] << " - " << size << " B" << endl;
    }
    catch(filesystem::filesystem_error &err) {
      cout << err.what() << endl;
    }
  }

  return 0;
}
