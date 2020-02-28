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
    CALC_TYPE current_status();
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
        case "+"_hash: case "-"_hash: case "×"_hash: case "÷"_hash: {
            Field *f = &vexpr.back();
            if (f->type == DIGITAL) {
                Field f(SIGN, str);
                vexpr.push_back(f);
            } else {
                f->value = str;
            }
            f = NULL;
            delete f;
            break;
        }
        case "%"_hash: {
            Field *f = &vexpr.back();
            string value = f->value;
            double res = string_to_double(value) / 100.0;
            value = double_to_string(res);
            f->value = value;
            f = NULL;
            delete f;
            break;
        }
        case "±"_hash: {
            Field *f = &vexpr.back();
            string value = f->value;
            double res = string_to_double(value) * (-1);
            value = double_to_string(res);
            f->value = value;
            f = NULL;
            delete f;
            break;
            break;
        }
        case "AC"_hash: case "C"_hash: {
            if (str == "AC") vector<Field>().swap(vexpr);
            // TODO C
            break;
        }
        case "="_hash: {
            auto post = mid_2_post(vexpr);
            double ret = calc_post(post);
            vector<Field>().swap(vexpr);
            Field f(DIGITAL, double_to_string(ret));
            vexpr.push_back(f);
            break;
        }
        default:
            // number
            string _str = str;
            Field *f = &vexpr.back();
            if (f->type == DIGITAL) {
                string value = f->value;
                f->value = value == "0" ? _str : value + _str;
                f = NULL;
                delete f;
            } else {
                Field new_field(DIGITAL, _str == "." ? "0." : _str);
                vexpr.push_back(new_field);
            }
            f = NULL;
            delete f;
            break;
    }
}
string Calculation_cpp::get_screen_result() {
    // 当前屏幕展示的结果，即堆栈里最后的数字
    for (vector<Field>::iterator iter = vexpr.end(); iter != vexpr.begin();) {
        auto it = *(--iter);
        if (it.type == DIGITAL) {
            return it.value;
        }
    }
    return "0";
}
CALC_TYPE Calculation_cpp::current_status() {
    Field f = vexpr.back();
    return f.type;
}

#endif /* Calculation_hpp */
