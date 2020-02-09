//
//  Calculation.hpp
//  Calculator
//
//  Created by VirgilChan on 2020/2/7.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

#ifndef Calculation_hpp
#define Calculation_hpp

#include <iostream>
#include <string>
#include <vector>
#include "Field.hpp"
#include "../Utils/hash.hpp"

using namespace std;

class Calculation_cpp {
private:
    char screen_result;    // 当前屏幕显示的结果
    CALC_TYPE last_type;     // 上次输入的状态
    vector<Field> vexpr;    // 表达式堆栈
private:
    static Calculation_cpp *pSingle;
    Calculation_cpp() = default;
    ~Calculation_cpp();
    Calculation_cpp(const Calculation_cpp&) = default;
    Calculation_cpp operator=(const Calculation_cpp&);
public:
    static Calculation_cpp* getInstance();
    void get_input(const string &str);
};
// private
Calculation_cpp* Calculation_cpp::pSingle = new (std::nothrow)Calculation_cpp;
Calculation_cpp::~Calculation_cpp() {
    delete pSingle;
    pSingle = NULL;
}
// public
Calculation_cpp* Calculation_cpp::getInstance() {
    return pSingle;
}
void Calculation_cpp::get_input(const string &str) {
    if (vexpr.size() == 0) {
        Field f(DIGITAL, "0");
        vexpr.push_back(f);
    }
    switch (hash_(str.c_str())) {
        case "+"_hash: case "-"_hash: case "×"_hash: case "÷"_hash:
            if (last_type == DIGITAL) {
                Field f(SIGN, str);
                vexpr.push_back(f);
            }
            last_type = SIGN;
            break;
        case "AC"_hash: case "C"_hash:
            cout << "acc: " << str << endl;
            break;
        case "="_hash: {
            vector<Field>::iterator it = vexpr.end();
            while(it != vexpr.begin()) {
                cout << (*(--it)).value << endl;
            }
//            Field f = vexpr.back();
//            vexpr.pop_back();
//            string second = f.value;
//            f = vexpr.back();
//            vexpr.pop_back();
//            string sign = f.value;
//            f = vexpr.back();
//            vexpr.pop_back();
//            string first = f.value;
//            cout << first << " " << sign << " " << second << endl;
            break;
        }
        default:
            // number
            string _str = str;
            if (last_type == DIGITAL) {
                Field *f = &vexpr.back();
                string value = f->value;
                f->value = value == "0" ? _str : value + _str;
                f = NULL;
                delete f;
            } else {
                Field f(DIGITAL, _str == "." ? "0." : _str);
                vexpr.push_back(f);
            }
            last_type  = DIGITAL;
            break;
    }
}

#endif /* Calculation_hpp */
