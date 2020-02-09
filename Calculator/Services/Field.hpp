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

enum CALC_TYPE { DIGITAL, SIGN };

using namespace std;

class Field {
public:
    CALC_TYPE type;
    string value;
    Field(CALC_TYPE t, string v) { type = t; value = v; };
};

#endif /* Field_hpp */
