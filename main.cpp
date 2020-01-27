#include <iostream>
#include <string>

using namespace std;

int main()
{
  double num1, num2, result = 0;
  string sign = "";
  cout << "Input First Number" << endl;
  cin >> num1;
  cout << "Input Sign" << endl;
  cin >> sign;
  cout << "Input Second Number" << endl;
  cin >> num2;
  if (sign == "+") {
    result = num1 + num2;
  } else if (sign == "-") {
    result = num1 - num2;
  } else if (sign == "*") {
    result = num1 * num2;
  } else if (sign == "/") {
    result = num1 / num2;
  } else if (sign == "%") {
    result = int(num1) % int(num2);
  }
  cout << "result is: " << result << endl;
}