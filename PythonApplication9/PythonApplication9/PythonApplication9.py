from PyQt5 import QtCore, QtGui, QtWidgets
from GUI import Ui_MainWindow

import sys
import qdarkstyle

class MainWindow(QtWidgets.QMainWindow,Ui_MainWindow):

    def __init__(self):
        super(MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        self.button_init()
        
    def button_init(self):
        self.pb0.clicked.connect(self.click_pb0)
        self.pb1.clicked.connect(self.click_pb1)
        self.pb2.clicked.connect(self.click_pb2)
        self.pb3.clicked.connect(self.click_pb3)
        self.pb4.clicked.connect(self.click_pb4)
        self.pb5.clicked.connect(self.click_pb5)
        self.pb6.clicked.connect(self.click_pb6)
        self.pb7.clicked.connect(self.click_pb7)
        self.pb8.clicked.connect(self.click_pb8)
        self.pb9.clicked.connect(self.click_pb9)
        self.pbac.clicked.connect(self.click_pbac)
        self.pbdel.clicked.connect(self.click_pbdel)
        self.pb100.clicked.connect(self.click_pb100)
        self.pbdivision.clicked.connect(self.click_pbdivision)
        self.pbmultiply.clicked.connect(self.click_pbmultiply)
        self.pbsubstraction.clicked.connect(self.click_pbsubstraction)
        self.pbaddition.clicked.connect(self.click_pbaddition)
        self.pbpoint.clicked.connect(self.click_pbpoint)
        self.pbequal.clicked.connect(self.click_pbequal)
        self.quit.clicked.connect(self.click_quit)

    def show(self):
        pass

    def click_pb0(self):
        input.append(0)
        self.show()

    def click_pb1(self):
        input.append(1)
        self.show()

    def click_pb2(self):
        input.append(2)
        self.show()

    def click_pb3(self):
        input.append(3)
        self.show()

    def click_pb4(self):
        input.append(4)
        self.show()

    def click_pb5(self):
        input.append(5)
        self.show()

    def click_pb6(self):
        input.append(6)
        self.show()

    def click_pb7(self):
        input.append(7)
        self.show()

    def click_pb8(self):
        input.append(8)
        self.show()

    def click_pb9(self):
        input.append(9)
        self.show()

    def click_pbac(self):
        input=''
        self.show()

    def click_pbdel(self):
        input=input[:-1]
        self.show()

    def click_pb100(self):
        pass

    def click_pbdivision(self):
        input.append('/')
        self.show()

    def click_pbmultiply(self):
        input.append('*')
        self.show()

    def click_pbsubstraction(self):
        input.append('-')
        self.show()

    def click_pbaddition(self):
        input.append('+')
        self.show()

    def click_quit(self):
        pass

    def click_pbpoint(self):
        input.append('.')
        self.show()

    def click_pbequal(self):
        input=eval(input)
        self.show()

if __name__=="__main__":
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    app=QtWidgets.QApplication(sys.argv)
    app.setStyleSheet(qdarkstyle.load_stylesheet_pyqt5())
    win=MainWindow()
    win.show()
    sys.exit(app.exec_())
