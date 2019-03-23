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
        Programmer.resize(490, 295)
        self.calc_mode = QtWidgets.QComboBox(Programmer)
        self.calc_mode.setGeometry(QtCore.QRect(0, 0, 151, 41))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(18)
        self.calc_mode.setFont(font)
        self.calc_mode.setObjectName("calc_mode")
        self.calc_mode.addItem("")
        self.calc_mode.addItem("")
        self.calc_mode.addItem("")
        self.calc_mode.addItem("")

        self.retranslateUi(Programmer)
        QtCore.QMetaObject.connectSlotsByName(Programmer)

    def retranslateUi(self, Programmer):
        _translate = QtCore.QCoreApplication.translate
        Programmer.setWindowTitle(_translate("Programmer", "Form"))
        self.calc_mode.setItemText(0, _translate("Programmer", "Standard"))
        self.calc_mode.setItemText(1, _translate("Programmer", "Scientific"))
        self.calc_mode.setItemText(2, _translate("Programmer", "Programmer"))
        self.calc_mode.setItemText(3, _translate("Programmer", "Date Calculation"))

