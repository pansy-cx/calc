//
//  ContentView.swift
//  Calculator
//
//  Created by VirgilChan on 2020/2/5.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack() {
            ResultView(result: "0")
            GridButton()
        }
        .frame(width: 232, height: 300)
    }
}


struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
