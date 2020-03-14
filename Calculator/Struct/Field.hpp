//
//  Field.hpp
//  Calculator
//
//  Created by VirgilChan on 2020/2/9.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

#ifndef Field_hpp
#define Field_hpp

#include <stdio.h>
#include <string>
#include "type.h"

using namespace std;

class Field {
public:
    CALC_TYPE type;
    string value;
    // 使用 member initalization list(成员初始值列) 替换赋值语句
    // 见《Effective C++》条款04，确定s对象被使用前已被初始化
    Field(CALC_TYPE t, string v): type(t), value(v) {};
};

#endif /* Field_hpp */
