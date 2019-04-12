import sys
import qdarkstyle
from GUI import Ui_MainWindow
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5 import *
from Datastructure_Linked_List import Student,Node,LinkedList

class MainWindow(QtWidgets.QMainWindow,Ui_MainWindow):

    def __init__(self):
        super(MainWindow,self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)
        self.button_init()
        self.image.setScaledContents(True)
        self.image.setFrameShape(QtWidgets.QFrame.Box)
        #self.setWindowFlags(QtCore.Qt.FramelessWindowHint)

    def button_init(self):
        self.Add.clicked.connect(self.add)
        self.Change.clicked.connect(self.change)
        self.Delete.clicked.connect(self.delete)
        self.Search.clicked.connect(self.search)
        self.Search.setShortcut(QtCore.Qt.Key_Return)
        self.actionImport.triggered.connect(self.import_info)
        self.actionImport.setShortcut('Ctrl+I')
        self.actionExport.triggered.connect(self.export_info)
        self.actionExport.setShortcut('Ctrl+E')
        self.actionShutdown.triggered.connect(self.shutdown)
        self.actionShutdown.setShortcut('Ctrl+S')
        self.Quit.triggered.connect(self.close)
        self.Quit.setShortcut('Ctrl+Q')
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
            list=line.split(' ')
            print (list)
            cur_info=Student(list[0],list[1],list[2],list[3],list[4])
            row_info.append(cur_info)
        database.init_list(row_info)
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
        for i in LinkedList.traverse(database):
            new_line=i.ID+' '+i.name+' '+i.sex+' '+i.age+' '+i.image+'\n'
            file.write(new_line)
        file.close()

    def add(self):
        ID=self.lineEdit_2.text()
        name=self.lineEdit_3.text()
        sex=self.comboBox.currentText()
        age=self.comboBox_2.currentText()
        add_student=Student(ID,name,sex,age,'./image/'+name+'.jpg')
        database.add(add_student)
        self.clear_info()
        self.sync_info()
        QMessageBox.information(self,"Tips","Successful Addition !")

    def delete(self):
        ID=self.lineEdit_2.text()
        name=self.lineEdit_3.text()
        database.remove(ID)
        database.remove(name)
        self.clear_info()
        self.sync_info()
        QMessageBox.information(self,"Tips","Deleted Successfully !")
        return
        QMessageBox.information(self,"Tips","Delete Failed !")

    def change(self):
        ID=self.lineEdit_2.text()
        name=self.lineEdit_3.text()
        sex=self.comboBox.currentText()
        age=self.comboBox_2.currentText()
        image='./image/'+name+'.jpg'
        changed_student=Student(ID,name,sex,age,image)
        check=database.change(changed_student)
        if check==True:
            self.sync_info()
            QMessageBox.information(self,"Tips","Successful Modification !")
        else:
            reply=QMessageBox.information(self,"Tips","Operation Mistake !")

    def search(self):
        key=self.lineEdit.text()
        for i in LinkedList.traverse(database):
            if i.ID==key or i.name==key:
                self.show_info(i)
                return
        QMessageBox.information(self,"Tips","Not Found !")

    def delete_item(self,str):
        for i in range(self.listWidget.count()):
            item=self.listWidget.takeItem(i)
            if item==str:
                self.listWidget.removeItemWidget(item)
                return
            else:
                continue

    def sync_info(self):
        self.listWidget.clear()
        for i in LinkedList.traverse(database):
            new_item=i.name
            self.listWidget.addItem(new_item)
        self.lineEdit_4.setText(str(LinkedList.len(database)))

    def clear_info(self):
        self.lineEdit.setText('')
        self.lineEdit_2.setText('')
        self.lineEdit_3.setText('')
        self.comboBox.setCurrentText('')
        self.comboBox_2.setCurrentText('')
        self.image.setPixmap(QPixmap(''))
        
    def show_info(self,Student):
        self.lineEdit_2.setText(Student.ID)
        self.lineEdit_3.setText(Student.name)
        self.comboBox.setCurrentText(Student.sex)
        self.comboBox_2.setCurrentText(Student.age)
        self.image.setPixmap(QPixmap(Student.image))

    def clicked(self,item):
        self.lineEdit.setText(str(item.text()).split()[0])
        self.search()

if __name__=="__main__":
    row_info=[]
    database=LinkedList()
    QtCore.QCoreApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling)
    app=QtWidgets.QApplication(sys.argv)
    app.setStyleSheet(qdarkstyle.load_stylesheet_pyqt5())
    win=MainWindow()
    win.show()
    sys.exit(app.exec_())
