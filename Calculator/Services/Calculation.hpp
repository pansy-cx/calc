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
#include "../Struct/Field.hpp"
#include "../Utils/hash.hpp"
#include "../Utils/math.hpp"

using namespace std;

class Calculation_cpp {
private:
    string screen_result;    // 当前屏幕显示的结果
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
    void on_input(const string &str);
    string get_screen_result();
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
void Calculation_cpp::on_input(const string &str) {
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
            if (str == "AC") vector<Field>().swap(vexpr);
            // TODO C
            break;
        case "="_hash: {
            auto post = mid_2_post(vexpr);
            double ret = calc_post(post);
            screen_result = double_to_string(ret);
            vector<Field>().swap(vexpr);
            break;
        }
        default:
            // number
            string _str = str;
            if (last_type == DIGITAL) {
                Field *f = &vexpr.back();
                string value = f->value;
                f->value = value == "0" ? _str : value + _str;
                screen_result = f->value;
                f = NULL;
                delete f;
            } else {
                Field f(DIGITAL, _str == "." ? "0." : _str);
                screen_result = f.value;
                vexpr.push_back(f);
            }
            last_type  = DIGITAL;
            break;
    }
}
string Calculation_cpp::get_screen_result() {
    return screen_result;
}

#endif /* Calculation_hpp */
