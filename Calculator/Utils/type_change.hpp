//
//  type_change.hpp
//  Calculator
//
//  Created by VirgilChan on 2020/2/9.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

#ifndef type_change_hpp
#define type_change_hpp

#include <regex>
#include <string>
#include <cmath>

using namespace std;

static int char_to_int(char ch) {
    // ch - '0' -> ch - 48 -> string -> int
    return ch - '0';
}
static bool is_digit(const string &str) {
    return regex_match(str, regex("^-?\\d+(\\.\\d+)?$"));
}
static bool is_int(const string &str) {
    return regex_match(str, regex("^\\d+$"));
}
static double string_to_double(const string &str) {
    if (!is_digit(str)) return NAN;
    int sign = 1;
    int point = 0;
    if (str[0] == '-') {
        sign = -1;
        point = 1;
    }
    int integer = 0;
    double decimal = 0.0;
    int decimalPlaces = 0; // 小数倍数
    for (; point < str.size(); point++) {
        char ch = str[point];
        if (ch == '.')  {
            decimalPlaces = 10;
            continue;
        }
        if (decimalPlaces == 0) {
            integer = integer * 10 + char_to_int(str[point]);
        } else {
            decimal += (char_to_int(ch) * 1.0) / decimalPlaces;
            decimalPlaces *= 10;
        }
    }
    return (integer + decimal) * sign;
}
static string double_to_string(double num) {
    string str = std::to_string (num);
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    if (str[str.size() - 1] == '.') {
        str.erase(str.end() - 1);
    }
    return str;
}

#endif /* type_change_hpp */
