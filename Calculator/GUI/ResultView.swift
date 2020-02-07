//
//  ResultView.swift
//  Calculator
//
//  Created by VirgilChan on 2020/2/5.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

import SwiftUI

struct ResultView: View {
    let result: String
    var body: some View {
        VStack() {
            Text(result)
                .font(.system(size: 48))
                .fontWeight(.thin)
                .foregroundColor(Color.white)
                .lineLimit(1)
        }
        .padding(.trailing, 10)
        .frame(maxWidth: .infinity, maxHeight: 60, alignment: .trailing)
        .background(Color.init(hex: "565658"))
    }
}

struct ResultView_Previews: PreviewProvider {
    static var previews: some View {
        ResultView(result: "0")
    }
}
