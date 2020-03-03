//
//  math.hpp
//  Calculator
//
//  Created by VirgilChan on 2020/2/9.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

#ifndef math_hpp
#define math_hpp

#include <vector>
#include <string>
#include <stack>
#include <ctype.h>
#include "../Struct/Field.hpp"
#include "type_change.hpp"
#include "hash.hpp"

using namespace std;

// 优先级
// 比较当前字符与栈顶字符的优先级，若栈顶高，返回true
static bool cmp_priority(Field top, Field cur) {
    string stop = top.value;
    string scur = cur.value;
    if ((stop == "+" || stop == "-") && (scur == "+" || scur == "-"))
        return true;
    if ((stop == "*" || stop == "/") && (scur == "+" || scur == "-" || stop == "*" || stop == "/"))
        return true;
    return false;
}

// 中缀表达式 -> 后缀表达式
static vector<Field> mid_2_post(const vector<Field> &vec) {
    vector<Field>ret;
    stack<Field> sign_stack;
    
    for (int i = 0; i < vec.size(); i++) {
        auto v = vec[i];
        if (v.type == CALC_DIGITAL) {
            ret.push_back(v);
        } else if (sign_stack.empty()) {
            sign_stack.push(v);
        } else if(cmp_priority(sign_stack.top(), v)) {
            while (!sign_stack.empty() && cmp_priority(sign_stack.top(), v)) {
              ret.push_back(sign_stack.top());
              sign_stack.pop();
            }
            sign_stack.push(v);
        } else {
            sign_stack.push(v);
        }
    }
    while (!sign_stack.empty()) {
        ret.push_back(sign_stack.top());
        sign_stack.pop();
    }
    return ret;
}

static double calc_post(vector<Field> &vec) {
    double op1, op2;
    stack<double>opStack;
    for (int i = 0; i < vec.size(); i++) {
        Field v = vec[i];
        if (v.type == CALC_DIGITAL) {
            opStack.push(string_to_double(v.value));
        } else {
            op2 = opStack.top();
            opStack.pop();
            op1 = opStack.top();
            opStack.pop();
            switch (hash_(v.value.c_str())) {
                case "+"_hash:
                    opStack.push(op1 + op2);
                    break;
                case "-"_hash:
                    opStack.push(op1 - op2);
                    break;
                case "*"_hash:
                    opStack.push(op1 * op2);
                    break;
                case "/"_hash:
                    opStack.push(op1 / op2);
                    break;
            }
        }
    }
    return opStack.top();
}

#endif /* math_hpp */
