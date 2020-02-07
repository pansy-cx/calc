//
//  Calculation.m
//  Calculator
//
//  Created by VirgilChan on 2020/2/7.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

#import "Calculation.h"
#import "Calculation.hpp"

using namespace std;

@implementation Calculation
- (void) print {
    auto calc = Calculation_cpp();
    calc.print();
}
@end
