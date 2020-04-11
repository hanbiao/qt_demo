This is a note introduce how to use QT.



创建界面时需要选择基类（base class）。有 3 种基类可以选择：

1. QMainWindow 是主窗口类，主窗口具有主菜单栏、工具栏和状态栏，类似于一般的应用程序的主窗口；
2. QWidget 是所有具有可视界面类的基类，选择 QWidget 创建的界面对各种界面组件都可以 支持；
3. QDialog 是对话框类，可建立一个基于对话框的界面；



表 6 UI设计器工具栏各按钮的功能

| 按钮及快捷键                     | 功能                                                         |
| -------------------------------- | ------------------------------------------------------------ |
| Edit Widget (F3)                 | 界面设计进入编辑状态，就是正常的设计状态                     |
| Edit Signals/Slots(F4)           | 进入信号与槽的可视化设计状态                                 |
| Edit Buddies                     | 进入伙伴关系编辑状态，可以设置一个Label 与一个组件成为伙伴关系 |
| Edit Tab Order                   | 进入Tab 顺序编辑状态，Tab 顺序是在键盘上按Tab 键时，输入焦点在界面各组件之间跳动的顺序 |
| Lay Out Horizontally (Ctrl+H)    | 将窗体上所选组件水平布局                                     |
| Lay Out Vertically (Ctrl+L)      | 将窗体上所选组件垂直布局                                     |
| Lay Out Horizontally in Splitter | 将窗体上所选组件用一个分割条进行水平分割布局                 |
| Lay Out Vertically in Splitter   | 将窗体上所选组件用一个分割条进行垂直分割布局                 |
| Lay Out in a Form Layout         | 将窗体上所选组件按窗体布局                                   |
| Lay Out in a Grid                | 将窗体上所选组件网格布局                                     |
| Break Layout                     | 解除窗体上所选组件的布局，也就是打散现有的布局               |
| Adjust Size(Ctrl+J)              | 自动调整所选组件的大小                                       |



