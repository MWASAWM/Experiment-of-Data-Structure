# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Programmer.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Programmer(object):
    def setupUi(self, Programmer):
        Programmer.setObjectName("Programmer")
        Programmer.resize(585, 640)
        self.push_button_menu = QtWidgets.QPushButton(Programmer)
        self.push_button_menu.setGeometry(QtCore.QRect(0, 0, 41, 41))
        self.push_button_menu.setObjectName("push_button_menu")
        self.mode_name = QtWidgets.QLabel(Programmer)
        self.mode_name.setGeometry(QtCore.QRect(40, 0, 200, 41))
        font = QtGui.QFont()
        font.setPointSize(15)
        self.mode_name.setFont(font)
        self.mode_name.setText("")
        self.mode_name.setObjectName("mode_name")

        self.retranslateUi(Programmer)
        QtCore.QMetaObject.connectSlotsByName(Programmer)

    def retranslateUi(self, Programmer):
        _translate = QtCore.QCoreApplication.translate
        Programmer.setWindowTitle(_translate("Programmer", "Form"))
        self.push_button_menu.setText(_translate("Programmer", "="))

