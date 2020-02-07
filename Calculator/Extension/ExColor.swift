//
//  ExColor.swift
//  Calculator
//
//  Created by VirgilChan on 2020/2/6.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

import Foundation
import SwiftUI

extension Color {
    init(hex: String) {
        var _hex = hex
        if hex.count == 6 { _hex += "FF" }
        let scanner = Scanner(string: _hex)
        var rgbValue: UInt64 = 0
        scanner.scanHexInt64(&rgbValue)

        let r = (rgbValue & 0xff000000) >> 24
        let g = (rgbValue & 0xff0000) >> 16
        let b = (rgbValue & 0xff00) >> 8
        let a = rgbValue & 0xff

        self.init(red: Double(r) / 0xff, green: Double(g) / 0xff, blue: Double(b) / 0xff, opacity: Double(a) / 0xff)

    }
}

extension NSColor {
    convenience init(hex: String) {
        var _hex = hex
        if hex.count == 6 { _hex += "FF" }
        let scanner = Scanner(string: _hex)
        var rgbValue: UInt64 = 0
        scanner.scanHexInt64(&rgbValue)

        let r = (rgbValue & 0xff000000) >> 24
        let g = (rgbValue & 0xff0000) >> 16
        let b = (rgbValue & 0xff00) >> 8
        let a = rgbValue & 0xff
        self.init(red: CGFloat(Double(r) / 0xff), green: CGFloat(Double(g) / 0xff), blue: CGFloat(Double(b) / 0xff), alpha: CGFloat(Double(a) / 0xff))

    }
}
