/*
g++ list_dir.cpp -std=c++17 -o list_dir_cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <filesystem>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
  string path;
  vector<string> dir_entries;

  if (argc == 1) {
    path = getenv("HOME");
  }
  else if (argc == 2) {
    path = argv[1];
  }

  for (const auto &entry : filesystem::directory_iterator(path)) {
    dir_entries.push_back(entry.path().filename().string());
  }

  sort(dir_entries.begin(), dir_entries.end());

  for (auto dir_entry : dir_entries) {
    cout << dir_entry << endl;
  }

  return 0;
}
