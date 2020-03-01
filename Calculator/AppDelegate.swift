//
//  AppDelegate.swift
//  Calculator
//
//  Created by VirgilChan on 2020/2/5.
//  Copyright © 2020 VirgilChan. All rights reserved.
//

import Cocoa
import SwiftUI

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    var window: NSWindow!


    func applicationDidFinishLaunching(_ aNotification: Notification) {
        // Create the SwiftUI view that provides the window contents.
        // 设置全局变量
        let calcData = CalculatorData()
        let contentView = ContentView().environmentObject(calcData)
        
        // Create the window and set the content view. 
        window = NSWindow(
            contentRect: NSRect(x: 0, y: 0, width: 232, height: 300),
            styleMask: [.titled, .closable, .miniaturizable, .resizable, .fullSizeContentView],
            backing: .buffered, defer: false)
        window.center()
        window.setFrameAutosaveName("Main Window")
        window.contentView = NSHostingView(rootView: contentView)
        // 设置标题栏颜色
        window.titlebarAppearsTransparent = true
        window.backgroundColor = NSColor.init(hex: "565658")
        window.makeKeyAndOrderFront(nil)
        
        // 监听键盘
        let calc = Calculation()
        NSEvent.addLocalMonitorForEvents(matching: .keyDown) { (event) -> NSEvent? in
            let char = event.characters ?? ""
            // 数字，加减乘除小数点百分比
            let regex = try! NSRegularExpression(pattern: "\\d|\\+|\\-|\\*|\\/|\\.|\\%", options: .caseInsensitive)
            let matches = regex.matches(in: char, options: [], range: NSRange(location: 0, length: char.count))
            if matches.count > 0 {
                calc.onInput(char)
                calcData.setScreenResult(val: calc.getScreenResult())
                return nil
            }
            // 删除
            if event.keyCode == 51 {
                calc.clearStack()
                calcData.setScreenResult(val: calc.getScreenResult())
                return nil
            }
            // 回车
            if event.keyCode == 36 || char == "=" {
                calc.onInput("=")
                calcData.setScreenResult(val: calc.getScreenResult())
                return nil
            }
            return event
        }
    }

    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }


}

