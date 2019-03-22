import sys
import os
import qdarkstyle
import MainWindows
from PyQt5 import *
from MainWindows import Standard_MainWindow,Science_MainWindow
import MainWindows
from PyQt5 import QtCore, QtGui, QtWidgets



if __name__=='__main__':
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    app=QtWidgets.QApplication(sys.argv)
    app.setStyleSheet(qdarkstyle.load_stylesheet_pyqt5())
    win=Standard_MainWindow()
    sci_win=Science_MainWindow()
    win.quit.clicked.connect(win.close_win)
    win.quit.clicked.connect(sci_win.show)
    win.show()
    sys.exit(app.exec_())
