#ifndef __TYPE_CHANGE__
#define __TYPE_CHANGE__

#include <regex>
#include <string>
#include <cmath> 
#include <iostream>

using namespace std;

static int charToInt(char ch) {
  // ch - '0' -> ch - 48 -> string -> int
  return ch - '0';
}
static bool isDigit(string &str) {
  return regex_match(str, regex("^\\d+(\\.\\d+)?$"));
}
static double stringToDouble(string &str) {
  if (!isDigit(str)) return NAN;
  int integer = 0;
  double decimal = 0.0;
  int decimalPlaces = 0; // 小数倍数
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    if (ch == '.')  {
      decimalPlaces = 10;
      continue;
    }
    if (decimalPlaces == 0) {
      integer = integer * 10 + charToInt(str[i]);
    } else {
      decimal += (charToInt(ch) * 1.0) / decimalPlaces;
      decimalPlaces *= 10;
    }
  }
  return integer + decimal;
}
#endif