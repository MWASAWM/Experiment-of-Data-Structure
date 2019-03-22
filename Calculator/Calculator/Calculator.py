
import sys
import qdarkstyle
from MainWindows import Standard_MainWindow,Science_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5 import *






if __name__=='__main__':
    calc_text=''
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    app=QtWidgets.QApplication(sys.argv)
    app.setStyleSheet(qdarkstyle.load_stylesheet_pyqt5())
    win=Standard_MainWindow()
    sci_win=Science_MainWindow()
    win.quit.clicked.connect(win.close_win)
    win.quit.clicked.connect(sci_win.show)
    
    win.show()
    sys.exit(app.exec_())
