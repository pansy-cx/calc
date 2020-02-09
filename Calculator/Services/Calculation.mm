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
- (void)getInput:(NSString *)str {
    auto calc = Calculation_cpp::getInstance();
    calc->get_input([str UTF8String]);
}
@end
