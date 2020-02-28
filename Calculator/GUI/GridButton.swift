//
//  GridButton.swift
//  Calculator
//
//  Created by VirgilChan on 2020/2/6.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

import SwiftUI
struct IBtnType {
    let value: String
    let color: String
    let pressColor: String
    var width = 58
    var height = 48
}
let btnArray: [IBtnType] = [
    IBtnType(value: "AC", color: "656567", pressColor: "656567aa"),
    IBtnType(value: "±", color: "656567", pressColor: "656567aa"),
    IBtnType(value: "%", color: "656567", pressColor: "656567aa"),
    IBtnType(value: "÷", color: "f99c2a", pressColor: "f99c2aaa"),
    IBtnType(value: "7", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "8", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "9", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "×", color: "f99c2a", pressColor: "f99c2aaa"),
    IBtnType(value: "4", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "5", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "6", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "-", color: "f99c2a", pressColor: "f99c2aaa"),
    IBtnType(value: "1", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "2", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "3", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "+", color: "f99c2a", pressColor: "f99c2aaa"),
    IBtnType(value: "0", color: "7d7e80", pressColor: "7d7e80aa", width: 116),
    IBtnType(value: ".", color: "7d7e80", pressColor: "7d7e80aa"),
    IBtnType(value: "=", color: "f99c2a", pressColor: "f99c2aaa")
]

let calc = Calculation()

struct _CalcButton: View {
    @EnvironmentObject var calcData: CalculatorData
    var btnType: IBtnType?
    @State private var btnText = "";
    init(btnType: IBtnType?, calcData: CalculatorData) {
        self.btnType = btnType
        _btnText = State(initialValue: btnType?.value ?? "")
    }
    var body: some View {
        if (btnType != nil) {
            let _btnType = btnType!
            return AnyView(CalcButton(
                btnText: self.btnText,
                color: Color.init(hex: _btnType.color),
                pressColor: Color.init(hex: _btnType.pressColor),
                borderColor: Color.init(hex: "605755"),
                action: {() -> Void in
                    calc.onInput(self.btnText)
                    self.calcData.setScreenResult(val: calc.getScreenResult())
                    // TODO
                    var type = "AC"
                    if (calc.getCurrentStatus() == DIGITAL) {
                        type = "C";
                    } else {
                        type = "AC";
                    }
                },
                width: _btnType.width,
                height: _btnType.height
            ))
        } else { return AnyView(EmptyView()) }
    }
}

struct GridButton: View {
    @EnvironmentObject var calcData: CalculatorData
    var body: some View {
        VStack() {
            ForEach(0..<5) { row in
                HStack(spacing: 0.0) {
                    ForEach(0..<4) { column -> _CalcButton in
                        let i = row * 4 + column
                        return _CalcButton(btnType: btnArray[safe: i], calcData: self.calcData)
                    }
                }
            }
        }
    }
}

struct GridButton_Previews: PreviewProvider {
    static var previews: some View {
        GridButton()
    }
}
