#include <iostream>
#include <sstream>
#include <cstring>

#include "rtreenode.h"
#include "rtree.h"
#include "greeneSplit.h"
#include "linearsplit.h"

using namespace std;

enum SPLIT_TYPE {
  GREENE_SPLIT,
  LINEAR_SPLIT
};

int M, split_type;
std::string directory = "default";
Split* split;

inline bool parse_error(const std::string& error_message) {
  cerr << error_message << endl;
  return false;
}

int parse_int(const char* arg) {
  stringstream ss;
  ss << arg;
  int result;
  ss >> result;
  return result;
}

bool parse_args(int argc, char const *argv[]) {
  M = 500;
  split_type = SPLIT_TYPE::LINEAR_SPLIT;
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], " ") == 0) continue;
    if (strcmp(argv[i], "-M") == 0) {
        if (i + 1 >= argc) return parse_error("invalid argument");
        else M = parse_int(argv[++i]);
    } else if (strcmp(argv[i], "-split") == 0) {
        if (i + 1 >= argc) return parse_error("invalid argument");
        else {
          if (strcmp(argv[i + 1], "greene") == 0) split_type = SPLIT_TYPE::GREENE_SPLIT;
          else if (strcmp(argv[i + 1], "linear") == 0) split_type = SPLIT_TYPE::LINEAR_SPLIT;
          i++;
        }
    } else if (strcmp(argv[i], "-d") == 0) {
        if (i + 1 >= argc) parse_error("invalid argument");
        else directory = argv[++i];
    } else return parse_error("invalid argument");
  }
  return true;
}

int main(int argc, char const *argv[]) {

  if (!parse_args(argc, argv)) return 1;
  int m = int(0.4 * M);
  switch (split_type) {
    case LINEAR_SPLIT:
      split = new LinearSplit(m, M);
      break;
    case GREENE_SPLIT:
      split = new GreeneSplit(m, M);
      break;
    default:
      split = new LinearSplit(m, M);
      break;
  }
  delete split;
}