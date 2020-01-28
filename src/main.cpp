#include <iostream>
#include "utils/hash.h"

using namespace std;

int main()
{
  double num1, num2, result = 0;
  char sign[] = "";
  cout << "Input First Number" << endl;
  cin >> num1;
  cout << "Input Sign" << endl;
  cin >> sign;
  cout << "Input Second Number" << endl;
  cin >> num2;
  switch (hash_(sign))
  {
  case "+"_hash:
    result = num1 + num2;
    break;
  case "-"_hash:
    result = num1 - num2;
    break;
  case "*"_hash:
    result = num1 * num2;
    break;
  case "/"_hash:
    result = num1 / num2;
    break;
  case "%"_hash:
    result = int(num1) % int(num2);
    break;
  default:
    break;
  }
  cout << "result is: " << result << endl;
}