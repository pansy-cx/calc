#include <iostream>
#include <boost/algorithm/string/replace.hpp>
#include <string>
#include "utils/hash.h"

using namespace std;
using namespace boost::algorithm;

int main()
{
  int result = 0;
  string expr = "";
  cout << "Input Calc Function" << endl;
  cin >> expr;
  replace_all(expr, " ", "");
  cout << "expr: " << expr << endl;

  // switch (hash_(sign))
  // {
  // case "+"_hash:
  //   result = num1 + num2;
  //   break;
  // case "-"_hash:
  //   result = num1 - num2;
  //   break;
  // case "*"_hash:
  //   result = num1 * num2;
  //   break;
  // case "/"_hash:
  //   result = num1 / num2;
  //   break;
  // case "%"_hash:
  //   result = int(num1) % int(num2);
  //   break;
  // default:
  //   break;
  // }
  cout << "result is: " << result << endl;
}