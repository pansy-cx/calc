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
#include "../Utils/type_change.hpp"

using namespace std;

class Calculation_cpp {
private:
    bool is_curr_clear;     // 清除状态，是清除当前栈或清除所有
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
    const string& get_screen_result();
    CALC_TYPE get_curr_type();
    const string& get_curr_sign();
    void clear_curr_stack();
    void clear_stack();
    bool get_curr_clear();
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
        Field f(CALC_DIGITAL, "0");
        vexpr.push_back(f);
    }
    is_curr_clear = true;
    switch (hash_(str.c_str())) {
        case "+"_hash: case "-"_hash: case "*"_hash: case "/"_hash: {
            Field *f = &vexpr.back();
            if (f->type == CALC_DIGITAL) {
                Field f(CALC_SIGN, str);
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
            vector<Field>::iterator iter = vexpr.end();
            while(iter-- != vexpr.begin()) {
                if (iter->type == CALC_DIGITAL && iter->value != "0") {
                    double res = string_to_double(iter->value) * (-1);
                    iter->value = double_to_string(res);
                    break;
                }
            }
            break;
        }
        case "="_hash: {
            is_curr_clear = false;
            auto post = mid_2_post(vexpr);
            double ret = calc_post(post);
            vector<Field>().swap(vexpr);
            Field f(CALC_DIGITAL, double_to_string(ret));
            vexpr.push_back(f);
            break;
        }
        case "."_hash: {
            if (vexpr.empty() || vexpr.back().type == CALC_SIGN) {
                Field new_field(CALC_DIGITAL, "0.");
                vexpr.push_back(new_field);
            } else {
                Field *f = &vexpr.back();
                if (f->type == CALC_DIGITAL && is_int(f->value)) f->value += ".";
                f = NULL;
                delete f;
            }
            break;
        }
        default:
            // number
            string _str = str;
            Field *f = &vexpr.back();
            if (f->type == CALC_DIGITAL) {
                string value = f->value;
                f->value = value == "0" ? _str : value + _str;
                f = NULL;
                delete f;
            } else {
                Field new_field(CALC_DIGITAL, _str);
                vexpr.push_back(new_field);
            }
            f = NULL;
            delete f;
            break;
    }
}
const string& Calculation_cpp::get_screen_result() {
    // 当前屏幕展示的结果，即堆栈里最后的数字
    static string result;
    result = "0";
    for (vector<Field>::iterator iter = vexpr.end(); iter != vexpr.begin();) {
        auto it = *(--iter);
        if (it.type == CALC_DIGITAL) {
            result = it.value;
            return result;
        } else {
            // 如果删除当前输入的数字，显示0，而不是显示上一个堆栈的数字
            if (!is_curr_clear) return result;
        }
    }
    return result;
}
CALC_TYPE Calculation_cpp::get_curr_type() {
    if (!vexpr.empty()) {
        Field f = vexpr.back();
        return f.type;
    } else {
        return CALC_INIT;
    }
}
void Calculation_cpp::clear_stack() {
    if (is_curr_clear) {
        if (!vexpr.empty()) {
            vexpr.pop_back();
        }
        is_curr_clear = false;
    } else {
        vector<Field>().swap(vexpr);
    }
}
bool Calculation_cpp::get_curr_clear() {
    return is_curr_clear;
}
const string& Calculation_cpp::get_curr_sign() {
    static string result;
    result = "";
    for (vector<Field>::iterator iter = vexpr.end(); iter != vexpr.begin();) {
        auto it = *(--iter);
        if (it.type == CALC_SIGN) {
            result = it.value;
            return result;
        }
    }
    return result;
}
#endif /* Calculation_hpp */
