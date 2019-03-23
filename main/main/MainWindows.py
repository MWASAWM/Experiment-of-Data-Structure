from Standard_UI import Ui_Standard
from Scientific_UI import Ui_Scientific
from Programmer_UI import Ui_Programmer
from DateCalculation_UI import Ui_DateCalculation
from Menu_UI import Ui_Menu
from PyQt5 import QtCore, QtGui, QtWidgets

global calc_text
calc_text=''

class Standard_MainWindow(QtWidgets.QMainWindow,Ui_Standard):

    def __init__(self):
        super(Standard_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        #self.setWindowFlags(QtCore.Qt.FramelessWindowHint)
        self.button_init()
        self.other_init()
        
    def button_init(self):
        self.pb0.clicked.connect(lambda:self.msg_input(0))
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
        self.push_button_menu.clicked.connect(self.change_win)
        
        
        
    def change_win(self):
        x=self.geometry().x()
        y=self.geometry().y()
        global men_win
        men_win=Menu_MainWindow()
        men_win.move(x,y)
        men_win.my_show(self)
   

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
            self.label.setText(calc_text)
            self.label_2.setText(str(eval(calc_text)))
            calc_text=self.label_2.text()
            return
        else:
            calc_text+=str(arg)
        self.label.setText(calc_text)

class Scientific_MainWindow(QtWidgets.QMainWindow,Ui_Scientific):
    def __init__(self):
        super(Scientific_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)

class Programmer_MainWindow(QtWidgets.QMainWindow,Ui_Programmer):
    def __init__(self):
        super(Programmer_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)

class DateCalculation_MainWindow(QtWidgets.QMainWindow,Ui_DateCalculation):
    def __init__(self):
        super(DateCalculation_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)

class Menu_MainWindow(QtWidgets.QMainWindow,Ui_Menu):
    def __init__(self):
        super(Menu_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        self.setWindowFlags(QtCore.Qt.FramelessWindowHint)
        self.About.setStyleSheet('text-align:left;')
        self.button_init()

    def button_init(self):
        self.listWidget.itemClicked.connect(self.clicked)
        self.push_button_menu.clicked.connect(self.close_win)

        

    def close_win(self):
        self.close()

    def my_show(self,pre_win):
        self.show()
        global close_win
        close_win=pre_win


    def clicked(self,item):
        global new_win
        new_win_name=item.text()+'_MainWindow'
        new_win=eval(new_win_name+'()')
        new_win.show()
        self.close()
        close_win.close()



