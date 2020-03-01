### 计算器

本来想用 QT 写 GUI 的，想想也是在 Mac 系统里玩，所以改用 SwiftUI。

UI 部分用 Swift，逻辑部分用 C++，中间通过 Objective-C 连接。

- [v0.1](https://github.com/pansy-cx/Calc/tree/58e76feaeff80e5c0923a0c8273268e1def05906): 用输入输出语句完成基本计算。
- [v0.2](https://github.com/pansy-cx/Calc/tree/9aa3e69c36c41aee20bccc222e10296b5446eaab): 使用 switch 代替 if else。
- [v0.3](https://github.com/pansy-cx/Calc/tree/13f2f2853bc69e6b138717bbdeffaf6ba11f792f): 添加词法分析。
- [v0.4](https://github.com/pansy-cx/Calc/tree/e0d4757c21ae67c614482841561d54eb9df9a038) 添加 Swift UI 做 GUI 库。
- [v0.5](https://github.com/pansy-cx/Calc/tree/32b278060a1ea5219c29f2527e13a38d44d9cfef) 添加清除按钮功能

### 使用

XCode 打开 `./Calculator.xcodeproj`
Product -> Run

### TODO
- 使用大数数据类型计算
- 相应键盘事件
- 添加 Scientific 模式
