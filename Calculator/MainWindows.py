import time  
import datetime
from Standard import Ui_Standard
from Scientific import Ui_Scientific
from Programmer import Ui_Programmer
from DateCalculation import Ui_DateCalculation
from Menu import Ui_Menu
from PyQt5 import QtCore, QtGui, QtWidgets

global calc_text
calc_text=''

def show_menu(pre_win):
    x=pre_win.geometry().x()
    y=pre_win.geometry().y()
    global men_win
    men_win=Menu_MainWindow()
    men_win.listWidget.setFixedHeight(pre_win.height()-pre_win.push_button_menu.height())
    men_win.move(x,y)
    men_win.setFixedHeight(pre_win.height())
    men_win.my_show(pre_win)

class Standard_MainWindow(QtWidgets.QMainWindow,Ui_Standard):

    def __init__(self):
        super(Standard_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        self.button_init()
        self.other_init()
        self.mode_name.setText('Standard')
        self.setWindowTitle('Calculator')
        #self.setWindowFlags(QtCore.Qt.FramelessWindowHint)
        
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
        self.pbce.clicked.connect(lambda:self.msg_input('CE'))
        self.pbdel.clicked.connect(lambda:self.msg_input('Backspace'))
        self.pb100.clicked.connect(lambda:self.msg_input('%'))
        self.pbdivision.clicked.connect(lambda:self.msg_input('/'))
        self.pbmultiply.clicked.connect(lambda:self.msg_input('*'))
        self.pbsubstraction.clicked.connect(lambda:self.msg_input('-'))
        self.pbaddition.clicked.connect(lambda:self.msg_input('+'))
        self.pbpoint.clicked.connect(lambda:self.msg_input('.'))
        self.pbequal.clicked.connect(lambda:self.msg_input('='))
        self.pbminus.clicked.connect(lambda:self.msg_input('±'))
        self.pbroot.clicked.connect(lambda:self.msg_input('√'))
        self.pbsquare.clicked.connect(lambda:self.msg_input('square'))
        self.pbreciprocal.clicked.connect(lambda:self.msg_input('1/x'))
        self.push_button_menu.clicked.connect(lambda:show_menu(self))
   

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
        if arg=='CE':
            calc_text=''
            self.label.setText('')
            self.label_2.setText('')
            self.set_text_size(36)
        elif arg=='Backspace':
            calc_text=calc_text[:-1]
        elif arg=='%':
            self.label_2.setText(str(float(calc_text)*100)+'%')
        elif arg=='±':
            return
        elif arg=='square':
            return
        elif arg=='1/x':
            return
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
        self.push_button_menu.clicked.connect(lambda:show_menu(self))
        self.setWindowTitle('Calculator')
        self.mode_name.setText('Scientific')

class Programmer_MainWindow(QtWidgets.QMainWindow,Ui_Programmer):
    def __init__(self):
        super(Programmer_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        self.push_button_menu.clicked.connect(lambda:show_menu(self))
        self.mode_name.setText('Programmer')
        self.setWindowTitle('Calculator')

class DateCalculation_MainWindow(QtWidgets.QMainWindow,Ui_DateCalculation):
    def __init__(self):
        super(DateCalculation_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        self.setWindowTitle('Calculator')
        self.push_button_menu.clicked.connect(lambda:show_menu(self))
        self.calendarWidget.selectionChanged.connect(self.showDate_1)
        self.calendarWidget_2.selectionChanged.connect(self.showDate_2)
        date=self.calendarWidget.selectedDate()
        self.date1.setText(str(date.toPyDate()))
        date=self.calendarWidget_2.selectedDate()
        self.date2.setText(str(date.toPyDate()))

    def showDate_1(self):
        date=self.calendarWidget.selectedDate()
        self.date1.setText(str(date.toPyDate()))
        self.ans.setText(str(self.Caltime()))

    def showDate_2(self):
        date=self.calendarWidget_2.selectedDate()
        self.date2.setText(str(date.toPyDate()))
        self.ans.setText(str(self.Caltime()))

    def Caltime(self):  
        date1=self.date1.text()
        date2=self.date2.text()
        date1=time.strptime(date1,"%Y-%m-%d")  
        date2=time.strptime(date2,"%Y-%m-%d")   
        date1=datetime.datetime(date1[0],date1[1],date1[2])  
        date2=datetime.datetime(date2[0],date2[1],date2[2])
        if date1==date2:
            return 'Same dates'
        else:
            ans=str(date2-date1)
            return ans.split(',')[0]

class Menu_MainWindow(QtWidgets.QMainWindow,Ui_Menu):
    def __init__(self):
        super(Menu_MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        self.setWindowFlags(QtCore.Qt.FramelessWindowHint)
        #self.About.setStyleSheet('text-align:left;')
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
        self.close_win()
        close_win.close()



