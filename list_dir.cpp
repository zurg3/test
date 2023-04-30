/*
g++ list_dir.cpp -std=c++20 -o list_dir_cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <filesystem>
#include <algorithm>
#include <cctype>
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

  sort(dir_entries.begin(), dir_entries.end(), [](const auto &a, const auto &b) {
    const auto comp_ci = mismatch(a.cbegin(), a.cend(), b.cbegin(), b.cend(), [](const auto &a, const auto &b) {
      return tolower(a) == tolower(b);
    });

    return comp_ci.second != b.cend() && (comp_ci.first == a.cend() || tolower(*comp_ci.first) < tolower(*comp_ci.second));
  });

  for (auto dir_entry : dir_entries) {
    cout << dir_entry << endl;
  }

  return 0;
}
