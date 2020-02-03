#ifndef __FORMAT__
#define __FORMAT__
#include <string>
#include <iostream>

static string removeSpace(const string &str) {
  string s = "";
  for (int i = 0; i < str.size(); i++) {
    char tmp = str[i];
    if (tmp != ' ' || tmp != '\t') s += tmp;
  }
  return s;
}

#endif