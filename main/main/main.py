import sys
import os
import qdarkstyle
from PyQt5 import *
import MainWindows
from MainWindows import Standard_MainWindow,Scientific_MainWindow,Programmer_MainWindow,DateCalculation_MainWindow,Menu_MainWindow
import MainWindows
from PyQt5 import QtCore, QtGui, QtWidgets


if __name__=='__main__':
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    app=QtWidgets.QApplication(sys.argv)
    app.setStyleSheet(qdarkstyle.load_stylesheet_pyqt5())
    global cur_win
    cur_win=Standard_MainWindow()
    #sta_win.push_button_menu.clicked.connect(men_win.show)
    cur_win.show()
    sys.exit(app.exec_())
