//
//  Calculation.h
//  Calculator
//
//  Created by VirgilChan on 2020/2/7.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../Struct/type.h"

NS_ASSUME_NONNULL_BEGIN

@interface Calculation : NSObject
- (void)onInput:(NSString *)str;
- (NSString *)getScreenResult;
- (enum CALC_TYPE)getCurrentStatus;
@end

NS_ASSUME_NONNULL_END
