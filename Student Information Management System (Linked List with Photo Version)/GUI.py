# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'GUI.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(912, 521)
        palette = QtGui.QPalette()
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.Button, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.Button, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.Button, brush)
        MainWindow.setPalette(palette)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.Add = QtWidgets.QPushButton(self.centralwidget)
        self.Add.setGeometry(QtCore.QRect(45, 389, 81, 31))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(12)
        self.Add.setFont(font)
        self.Add.setObjectName("Add")
        self.Change = QtWidgets.QPushButton(self.centralwidget)
        self.Change.setGeometry(QtCore.QRect(155, 390, 81, 31))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(12)
        self.Change.setFont(font)
        self.Change.setObjectName("Change")
        self.Delete = QtWidgets.QPushButton(self.centralwidget)
        self.Delete.setGeometry(QtCore.QRect(265, 390, 81, 31))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(12)
        self.Delete.setFont(font)
        self.Delete.setObjectName("Delete")
        self.Search = QtWidgets.QPushButton(self.centralwidget)
        self.Search.setGeometry(QtCore.QRect(710, 20, 161, 41))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(20)
        self.Search.setFont(font)
        self.Search.setObjectName("Search")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(35, 162, 201, 51))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(16)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(40, 241, 54, 41))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(16)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(40, 301, 71, 51))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(16)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(40, 91, 61, 51))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(16)
        self.label_4.setFont(font)
        self.label_4.setObjectName("label_4")
        self.lineEdit = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit.setGeometry(QtCore.QRect(40, 20, 641, 41))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit.setFont(font)
        self.lineEdit.setObjectName("lineEdit")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_2.setGeometry(QtCore.QRect(90, 100, 251, 41))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit_2.setFont(font)
        self.lineEdit_2.setText("")
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_3.setGeometry(QtCore.QRect(90, 170, 251, 41))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit_3.setFont(font)
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.comboBox = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox.setGeometry(QtCore.QRect(90, 240, 251, 41))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.comboBox.setFont(font)
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.setItemText(0, "")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox_2 = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox_2.setGeometry(QtCore.QRect(90, 311, 251, 41))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.comboBox_2.setFont(font)
        self.comboBox_2.setObjectName("comboBox_2")
        self.comboBox_2.addItem("")
        self.comboBox_2.setItemText(0, "")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.listWidget = QtWidgets.QListWidget(self.centralwidget)
        self.listWidget.setGeometry(QtCore.QRect(620, 101, 251, 281))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(14)
        font.setBold(False)
        font.setWeight(50)
        self.listWidget.setFont(font)
        self.listWidget.setObjectName("listWidget")
        self.lineEdit_4 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_4.setGeometry(QtCore.QRect(700, 391, 141, 31))
        font = QtGui.QFont()
        font.setFamily("Mongolian Baiti")
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit_4.setFont(font)
        self.lineEdit_4.setObjectName("lineEdit_4")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(650, 391, 35, 31))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(14)
        self.label_5.setFont(font)
        self.label_5.setObjectName("label_5")
        self.image = QtWidgets.QLabel(self.centralwidget)
        self.image.setGeometry(QtCore.QRect(370, 100, 221, 321))
        self.image.setText("")
        self.image.setObjectName("image")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 912, 20))
        self.menubar.setObjectName("menubar")
        self.menuManagement = QtWidgets.QMenu(self.menubar)
        self.menuManagement.setObjectName("menuManagement")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionLogin = QtWidgets.QAction(MainWindow)
        self.actionLogin.setObjectName("actionLogin")
        self.actionQuit = QtWidgets.QAction(MainWindow)
        self.actionQuit.setObjectName("actionQuit")
        self.actionImport = QtWidgets.QAction(MainWindow)
        self.actionImport.setObjectName("actionImport")
        self.actionTerminal = QtWidgets.QAction(MainWindow)
        self.actionTerminal.setObjectName("actionTerminal")
        self.actionDatabase = QtWidgets.QAction(MainWindow)
        self.actionDatabase.setObjectName("actionDatabase")
        self.actionSave = QtWidgets.QAction(MainWindow)
        self.actionSave.setObjectName("actionSave")
        self.actionExport = QtWidgets.QAction(MainWindow)
        self.actionExport.setObjectName("actionExport")
        self.actionShutdown = QtWidgets.QAction(MainWindow)
        self.actionShutdown.setObjectName("actionShutdown")
        self.menuManagement.addAction(self.actionImport)
        self.menuManagement.addAction(self.actionExport)
        self.menuManagement.addAction(self.actionShutdown)
        self.menubar.addAction(self.menuManagement.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle('Student Information Management System')
        self.Add.setText(_translate("MainWindow", "Add"))
        self.Change.setText(_translate("MainWindow", "Change"))
        self.Delete.setText(_translate("MainWindow", "Delete"))
        self.Search.setText(_translate("MainWindow", "Search(Enter)"))
        self.label.setText(_translate("MainWindow", "Name"))
        self.label_2.setText(_translate("MainWindow", "Sex"))
        self.label_3.setText(_translate("MainWindow", "Age"))
        self.label_4.setText(_translate("MainWindow", "ID"))
        self.comboBox.setItemText(1, _translate("MainWindow", "Male"))
        self.comboBox.setItemText(2, _translate("MainWindow", "Female"))
        self.comboBox_2.setItemText(1, _translate("MainWindow", "1"))
        self.comboBox_2.setItemText(2, _translate("MainWindow", "2"))
        self.comboBox_2.setItemText(3, _translate("MainWindow", "3"))
        self.comboBox_2.setItemText(4, _translate("MainWindow", "4"))
        self.comboBox_2.setItemText(5, _translate("MainWindow", "5"))
        self.comboBox_2.setItemText(6, _translate("MainWindow", "6"))
        self.comboBox_2.setItemText(7, _translate("MainWindow", "7"))
        self.comboBox_2.setItemText(8, _translate("MainWindow", "8"))
        self.comboBox_2.setItemText(9, _translate("MainWindow", "9"))
        self.comboBox_2.setItemText(10, _translate("MainWindow", "10"))
        self.comboBox_2.setItemText(11, _translate("MainWindow", "11"))
        self.comboBox_2.setItemText(12, _translate("MainWindow", "12"))
        self.comboBox_2.setItemText(13, _translate("MainWindow", "13"))
        self.comboBox_2.setItemText(14, _translate("MainWindow", "14"))
        self.comboBox_2.setItemText(15, _translate("MainWindow", "15"))
        self.comboBox_2.setItemText(16, _translate("MainWindow", "16"))
        self.comboBox_2.setItemText(17, _translate("MainWindow", "17"))
        self.comboBox_2.setItemText(18, _translate("MainWindow", "18"))
        self.comboBox_2.setItemText(19, _translate("MainWindow", "19"))
        self.comboBox_2.setItemText(20, _translate("MainWindow", "20"))
        self.comboBox_2.setItemText(21, _translate("MainWindow", "21"))
        self.comboBox_2.setItemText(22, _translate("MainWindow", "22"))
        self.comboBox_2.setItemText(23, _translate("MainWindow", "23"))
        self.comboBox_2.setItemText(24, _translate("MainWindow", "24"))
        self.comboBox_2.setItemText(25, _translate("MainWindow", "25"))
        self.comboBox_2.setItemText(26, _translate("MainWindow", "26"))
        self.comboBox_2.setItemText(27, _translate("MainWindow", "27"))
        self.comboBox_2.setItemText(28, _translate("MainWindow", "28"))
        self.comboBox_2.setItemText(29, _translate("MainWindow", "29"))
        self.comboBox_2.setItemText(30, _translate("MainWindow", "30"))
        self.comboBox_2.setItemText(31, _translate("MainWindow", "31"))
        self.comboBox_2.setItemText(32, _translate("MainWindow", "32"))
        self.comboBox_2.setItemText(33, _translate("MainWindow", "33"))
        self.comboBox_2.setItemText(34, _translate("MainWindow", "34"))
        self.comboBox_2.setItemText(35, _translate("MainWindow", "35"))
        self.comboBox_2.setItemText(36, _translate("MainWindow", "36"))
        self.comboBox_2.setItemText(37, _translate("MainWindow", "37"))
        self.comboBox_2.setItemText(38, _translate("MainWindow", "38"))
        self.comboBox_2.setItemText(39, _translate("MainWindow", "39"))
        self.comboBox_2.setItemText(40, _translate("MainWindow", "40"))
        self.comboBox_2.setItemText(41, _translate("MainWindow", "41"))
        self.comboBox_2.setItemText(42, _translate("MainWindow", "42"))
        self.comboBox_2.setItemText(43, _translate("MainWindow", "43"))
        self.comboBox_2.setItemText(44, _translate("MainWindow", "44"))
        self.comboBox_2.setItemText(45, _translate("MainWindow", "45"))
        self.comboBox_2.setItemText(46, _translate("MainWindow", "46"))
        self.comboBox_2.setItemText(47, _translate("MainWindow", "47"))
        self.comboBox_2.setItemText(48, _translate("MainWindow", "48"))
        self.comboBox_2.setItemText(49, _translate("MainWindow", "49"))
        self.comboBox_2.setItemText(50, _translate("MainWindow", "50"))
        self.comboBox_2.setItemText(51, _translate("MainWindow", "51"))
        self.comboBox_2.setItemText(52, _translate("MainWindow", "52"))
        self.comboBox_2.setItemText(53, _translate("MainWindow", "53"))
        self.comboBox_2.setItemText(54, _translate("MainWindow", "54"))
        self.comboBox_2.setItemText(55, _translate("MainWindow", "55"))
        self.comboBox_2.setItemText(56, _translate("MainWindow", "56"))
        self.comboBox_2.setItemText(57, _translate("MainWindow", "57"))
        self.comboBox_2.setItemText(58, _translate("MainWindow", "58"))
        self.comboBox_2.setItemText(59, _translate("MainWindow", "59"))
        self.comboBox_2.setItemText(60, _translate("MainWindow", "60"))
        self.comboBox_2.setItemText(61, _translate("MainWindow", "61"))
        self.comboBox_2.setItemText(62, _translate("MainWindow", "62"))
        self.comboBox_2.setItemText(63, _translate("MainWindow", "63"))
        self.comboBox_2.setItemText(64, _translate("MainWindow", "64"))
        self.comboBox_2.setItemText(65, _translate("MainWindow", "65"))
        self.comboBox_2.setItemText(66, _translate("MainWindow", "66"))
        self.comboBox_2.setItemText(67, _translate("MainWindow", "67"))
        self.comboBox_2.setItemText(68, _translate("MainWindow", "68"))
        self.comboBox_2.setItemText(69, _translate("MainWindow", "69"))
        self.comboBox_2.setItemText(70, _translate("MainWindow", "70"))
        self.comboBox_2.setItemText(71, _translate("MainWindow", "71"))
        self.comboBox_2.setItemText(72, _translate("MainWindow", "72"))
        self.comboBox_2.setItemText(73, _translate("MainWindow", "73"))
        self.comboBox_2.setItemText(74, _translate("MainWindow", "74"))
        self.comboBox_2.setItemText(75, _translate("MainWindow", "75"))
        self.comboBox_2.setItemText(76, _translate("MainWindow", "76"))
        self.comboBox_2.setItemText(77, _translate("MainWindow", "77"))
        self.comboBox_2.setItemText(78, _translate("MainWindow", "78"))
        self.comboBox_2.setItemText(79, _translate("MainWindow", "79"))
        self.comboBox_2.setItemText(80, _translate("MainWindow", "80"))
        self.comboBox_2.setItemText(81, _translate("MainWindow", "81"))
        self.comboBox_2.setItemText(82, _translate("MainWindow", "82"))
        self.comboBox_2.setItemText(83, _translate("MainWindow", "83"))
        self.comboBox_2.setItemText(84, _translate("MainWindow", "84"))
        self.comboBox_2.setItemText(85, _translate("MainWindow", "85"))
        self.comboBox_2.setItemText(86, _translate("MainWindow", "86"))
        self.comboBox_2.setItemText(87, _translate("MainWindow", "87"))
        self.comboBox_2.setItemText(88, _translate("MainWindow", "88"))
        self.comboBox_2.setItemText(89, _translate("MainWindow", "89"))
        self.comboBox_2.setItemText(90, _translate("MainWindow", "90"))
        self.comboBox_2.setItemText(91, _translate("MainWindow", "91"))
        self.comboBox_2.setItemText(92, _translate("MainWindow", "92"))
        self.comboBox_2.setItemText(93, _translate("MainWindow", "93"))
        self.comboBox_2.setItemText(94, _translate("MainWindow", "94"))
        self.comboBox_2.setItemText(95, _translate("MainWindow", "95"))
        self.comboBox_2.setItemText(96, _translate("MainWindow", "96"))
        self.comboBox_2.setItemText(97, _translate("MainWindow", "97"))
        self.comboBox_2.setItemText(98, _translate("MainWindow", "98"))
        self.comboBox_2.setItemText(99, _translate("MainWindow", "99"))
        self.comboBox_2.setItemText(100, _translate("MainWindow", "100"))
        self.label_5.setText(_translate("MainWindow", "Total"))
        self.menuManagement.setTitle(_translate("MainWindow", "Management"))
        self.actionLogin.setText(_translate("MainWindow", "Login"))
        self.actionQuit.setText(_translate("MainWindow", "Quit"))
        self.actionImport.setText(_translate("MainWindow", "Import"))
        self.actionTerminal.setText(_translate("MainWindow", "Terminal"))
        self.actionDatabase.setText(_translate("MainWindow", "Database"))
        self.actionSave.setText(_translate("MainWindow", "Save"))
        self.actionExport.setText(_translate("MainWindow", "Export"))
        self.actionShutdown.setText(_translate("MainWindow", "Shutdown"))

