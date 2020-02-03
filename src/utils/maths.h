#ifndef __MATHS__
#define __MATHS__
#include <vector>
#include <string>
#include <stack>
#include <ctype.h>
#include "type_change.h"
#include "format.h"

using namespace std;

// 优先级
// 比较当前字符与栈顶字符的优先级，若栈顶高，返回true
static bool cmpPriority(char top, char cur) {
	if ((top == '+' || top == '-') && (cur == '+' || cur == '-'))
		return true;
	if ((top == '*' || top == '/') && (cur == '+' || cur == '-' || top == '*' || top == '/'))
		return true;
	if (cur == ')')
		return true;
	return false;
}

// 中缀表达式 -> 后缀表达式
static vector<string> mid2post(const string &str) {
  vector<string>vStr;
  stack<char> signStack;
  string _str = removeSpace(str);
  int strLength = _str.size();
  for (int i = 0; i < strLength; i++) {
    char ch = _str[i];
    if (ch == ' ' || ch == '\t') continue;

    if (isdigit(ch)) {
      string tmp = "";
      tmp += ch;
      while (i + 1 < strLength && (isdigit(_str[i+1]) || _str[i+1] == '.')) {
        tmp += _str[i+1];
        i++;
      }
      vStr.push_back(tmp);
    } else if (signStack.empty() || ch == '(') {
      signStack.push(ch);
    } else if (cmpPriority(signStack.top(), ch)) {
      if (ch == ')') {
        string sign = "";
        while(!signStack.empty() && signStack.top() != '(') {
          sign += signStack.top();
          signStack.pop();
          vStr.push_back(sign);
        }
        signStack.push(ch);
      } else {
        while (!signStack.empty() && cmpPriority(signStack.top(), ch)) {
          string sign = "";
          sign += signStack.top();
          signStack.pop();
          vStr.push_back(sign);
        }
        signStack.push(ch);
      }
    } else {
      signStack.push(ch);
    }
  }
  while (!signStack.empty()) {
    string sign = "";
    sign += signStack.top();
    signStack.pop();
    if (!(sign == "(" || sign == ")")) {
      vStr.push_back(sign);
    }
  }
  return vStr;
}

double calcPost(vector<string> &vStr) {
  double op1, op2;
  stack<double>opStack;
  for (int i = 0; i < vStr.size(); i++) {
    string tmp = vStr[i];
    if (isDigit(tmp)) {
      opStack.push(stringToDouble(tmp));
    } else {
      op2 = opStack.top();
			opStack.pop();
			op1 = opStack.top();
			opStack.pop();
      switch (tmp[0]) {
        case '+':
          opStack.push(op1 + op2);
          break;
        case '-':
          opStack.push(op1 - op2);
          break;
        case '*':
          opStack.push(op1 * op2);
          break;
        case '/':
          opStack.push(op1 / op2);
          break;
        case '%':
          opStack.push(int(op1) % int(op2));
          break;
      }
    }
  }
  return opStack.top();
}

#endif