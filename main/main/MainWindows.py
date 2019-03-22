from Standard_UI import Ui_MainWindow
from Science_UI import Ui_Form
from PyQt5 import QtCore, QtGui, QtWidgets

global calc_text
calc_text=''

class Standard_MainWindow(QtWidgets.QMainWindow,Ui_MainWindow):

    def __init__(self):
        super(Standard_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        self.button_init()
        self.other_init()
        
    def button_init(self):
        self.pb0.clicked.connect(lambda:lambda:self.msg_input(0))
        self.pb1.clicked.connect(lambda:self.msg_input(1))
        self.pb2.clicked.connect(lambda:self.msg_input(2))
        self.pb3.clicked.connect(lambda:self.msg_input(3))
        self.pb4.clicked.connect(lambda:self.msg_input(4))
        self.pb5.clicked.connect(lambda:self.msg_input(5))
        self.pb6.clicked.connect(lambda:self.msg_input(6))
        self.pb7.clicked.connect(lambda:self.msg_input(7))
        self.pb8.clicked.connect(lambda:self.msg_input(8))
        self.pb9.clicked.connect(lambda:self.msg_input(9))
        self.pbac.clicked.connect(lambda:self.msg_input('AC'))
        self.pbdel.clicked.connect(lambda:self.msg_input('DEL'))
        self.pb100.clicked.connect(lambda:self.msg_input('%'))
        self.pbdivision.clicked.connect(lambda:self.msg_input('/'))
        self.pbmultiply.clicked.connect(lambda:self.msg_input('*'))
        self.pbsubstraction.clicked.connect(lambda:self.msg_input('-'))
        self.pbaddition.clicked.connect(lambda:self.msg_input('+'))
        self.pbpoint.clicked.connect(lambda:self.msg_input('.'))
        self.pbequal.clicked.connect(lambda:self.msg_input('='))
        #self.quit.clicked.connect(lambda:self.msg_input('Q'))
        
  
    def close_win(self):
        self.close()

    def other_init(self):
        self.label.setAlignment(QtCore.Qt.AlignRight)
        self.label_2.setAlignment(QtCore.Qt.AlignRight)

    def set_text_size(self,size):
        font=QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(size)
        self.label.setFont(font)

    def msg_input(self,arg):
        global calc_text
        if arg=='AC':
            calc_text=''
            self.label.setText('')
            self.label_2.setText('')
            self.set_text_size(36)
        elif arg=='Q':
            qApp.quit()
        elif arg=='DEL':
            calc_text=calc_text[:-1]
        elif arg=='%':
            self.label_2.setText(str(float(calc_text)*100)+'%')
        elif arg=='=':
            self.set_text_size(20)
            self.label.setText(calc_text+'=')
            self.label_2.setText(str(eval(calc_text)))
            calc_text=self.label_2.text()
            return
        else:
            calc_text+=str(arg)
        self.label.setText(calc_text)


class Science_MainWindow(QtWidgets.QMainWindow,Ui_Form):
    def __init__(self):
        super(Science_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)