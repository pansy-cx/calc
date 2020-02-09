//
//  CalcButton.swift
//  Calculator
//
//  Created by VirgilChan on 2020/2/5.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

import SwiftUI

struct btnStyle: ButtonStyle {
    let color: Color
    let pressColor: Color
    let borderColor: Color
    let width: CGFloat
    let height: CGFloat
    func makeBody(configuration: Self.Configuration) -> some View {
        configuration.label
            .foregroundColor(Color.white)
            .background(configuration.isPressed ? pressColor : color)
            .frame(width: width, height: height)
            .border(borderColor, width: 0.5)
    }
}

struct CalcButton: View {
    let btnText: String
    let color: Color
    let pressColor: Color
    let borderColor: Color
    let action: () -> Void
    var width = 50
    var height = 50
    var body: some View {
        Button(action: action) {
            Text(btnText)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .font(.system(size: 20))
        }
        .buttonStyle(
            btnStyle(
                color: color,
                pressColor: pressColor,
                borderColor: borderColor,
                width: CGFloat(width),
                height: CGFloat(height)
            )
        )
    }
}

struct CalcButton_Previews: PreviewProvider {
    static var previews: some View {
        CalcButton(
            btnText: "+",
            color: Color.init(hex: "7d7e80"),
            pressColor: Color.init(hex: "7d7e80aa"),
            borderColor: Color.init(hex: "605755"),
            action: { print("Click") }
        )
    }
}
