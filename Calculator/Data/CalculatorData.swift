//
//  CalculatorData.swift
//  Calculator
//
//  Created by XiChen on 2020/2/28.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

import Foundation

final class CalculatorData: ObservableObject {
    @Published private(set) var screenResult: String = "0"
    func setScreenResult(val: String) { screenResult = val }
}
