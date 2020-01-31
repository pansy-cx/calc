#include <iostream>
#include <string>
#include <sstream>
#include "utils/maths.h"

using namespace std;

int main() {
  string expr = "";
  cout << "请输入算术表达式" << endl;
  while (true) {
    getline(cin, expr);
    if (expr == "Q" || expr == "q") return 0;
    auto postExpr = mid2post(expr);
    double result = calcPost(postExpr);
    cout << "= " << result << endl;
  }
  return 0;
}