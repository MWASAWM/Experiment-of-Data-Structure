import sys
import qdarkstyle
from GUI import Ui_MainWindow
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5 import *

class Student:

    def __init__(self,ID,name,sex,age):
        self.ID=ID
        self.name=name
        self.sex=sex
        self.age=age

class MainWindow(QtWidgets.QMainWindow,Ui_MainWindow):

    def __init__(self):
        super(MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        self.button_init()

    def button_init(self):
        self.Add.clicked.connect(self.add)
        self.Change.clicked.connect(self.change)
        self.Delete.clicked.connect(self.delete)
        self.Search.clicked.connect(self.search)
        self.Search.setShortcut(QtCore.Qt.Key_Return)
        self.actionQuit.triggered.connect(qApp.quit)
        self.actionQuit.setShortcut('Ctrl+Q')
        self.actionImport.triggered.connect(self.import_info)
        self.actionImport.setShortcut('Ctrl+I')
        self.actionExport.triggered.connect(self.export_info)
        self.actionExport.setShortcut('Ctrl+E')
        self.actionShutdown.triggered.connect(self.shutdown)
        self.actionShutdown.setShortcut('Ctrl+S')
        self.listWidget.itemClicked.connect(self.clicked)

    def shutdown(self):
        database.clear()
        self.clear_info()
        self.sync_info()

    def import_info(self):
        filename,filetype=QFileDialog.getOpenFileName(self,
                                    "Select File",
                                    "./",
                                    "All Files (*);;Text Files (*.txt)")
        if filename=='':
            return
        file=open(filename)
        for line in file.readlines():
            list=line.split()
            cur_info=Student(list[0],list[1],list[2],list[3])
            database.append(cur_info)
        self.sync_info()
        file.close()

    def export_info(self):
        filename,filetype=QFileDialog.getSaveFileName(self,  
                                    "Save Database",  
                                    "./",
                                    "All Files (*);;Text Files (*.txt)")
        if filename=='':
            return
        file=open(filename,'w')
        for i in database:
            new_line=i.ID+' '+i.name+' '+i.sex+' '+i.age+'\n'
            file.write(new_line)
        file.close()

    def clicked(self,item):
        self.lineEdit.setText(str(item.text()).split()[0])
        self.search()

    def delete_item(self,str):
        for i in range(self.listWidget.count()):
            item=self.listWidget.takeItem(i)
            if item==str:
                self.listWidget.removeItemWidget(item)
                return
            else:
                continue

    def clear_widget(self):
        self.listWidget.clear()
        self.clear_info()

    def sync_info(self):
        self.listWidget.clear()
        for i in database:
            new_item=i.name+'  ('+i.ID+')'
            self.listWidget.addItem(new_item)
        self.lineEdit_4.setText(str(len(database)))

    def update_info(self,Student):
        Student.ID=self.lineEdit_2.text()
        Student.name=self.lineEdit_3.text()
        Student.sex=self.comboBox.currentText()
        Student.age=self.comboBox_2.currentText()

    def clear_info(self):
        self.lineEdit.setText('')
        self.lineEdit_2.setText('')
        self.lineEdit_3.setText('')
        self.comboBox.setCurrentText('')
        self.comboBox_2.setCurrentText('')

    def show_info(self,Student):
        self.lineEdit_2.setText(Student.ID)
        self.lineEdit_3.setText(Student.name)
        self.comboBox.setCurrentText(Student.sex)
        self.comboBox_2.setCurrentText(Student.age)

    def add(self):
        ID=self.lineEdit_2.text()
        name=self.lineEdit_3.text()
        sex=self.comboBox.currentText()
        age=self.comboBox_2.currentText()
        add_student=Student(ID,name,sex,age)
        database.append(add_student)
        self.clear_info()
        self.sync_info()
        QMessageBox.information(self,"Tips","Successful Addition !")

    def delete(self):
        ID=self.lineEdit_2.text()
        name=self.lineEdit_3.text()
        for i in database:
            if ID==i.ID or name==i.name:
                database.remove(i)
                self.clear_info()
                self.sync_info()
                QMessageBox.information(self,"Tips","Deleted Successfully !")
                return
        QMessageBox.information(self,"Tips","Delete Failed !")

    def change(self):
        ID=self.lineEdit_2.text()
        name=self.lineEdit_3.text()
        for i in database:
            if ID==i.ID:
                self.update_info(i)
                self.sync_info()
                reply=QMessageBox.information(self,"Tips","Successful Modification !")
                return
            elif name==i.name:
                self.update_info(i)
                self.sync_info()
                reply=QMessageBox.information(self,"Tips","Successful Modification !")
                return
        reply=QMessageBox.information(self,"Tips","Operation Mistake !")

    def search(self):
        key=self.lineEdit.text()
        for i in database:
            if i.ID==key or i.name==key:
                self.show_info(i)
                return
        QMessageBox.information(self,"Tips","Not Found !")

if __name__=="__main__":
    database=[]
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    app=QtWidgets.QApplication(sys.argv)
    app.setStyleSheet(qdarkstyle.load_stylesheet_pyqt5())
    win=MainWindow()
    win.show()
    sys.exit(app.exec_())