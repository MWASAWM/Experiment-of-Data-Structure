# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'DateCalculation.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_DateCalculation(object):
    def setupUi(self, DateCalculation):
        DateCalculation.setObjectName("DateCalculation")
        DateCalculation.resize(400, 300)
        self.calc_mode = QtWidgets.QComboBox(DateCalculation)
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

        self.retranslateUi(DateCalculation)
        QtCore.QMetaObject.connectSlotsByName(DateCalculation)

    def retranslateUi(self, DateCalculation):
        _translate = QtCore.QCoreApplication.translate
        DateCalculation.setWindowTitle(_translate("DateCalculation", "Form"))
        self.calc_mode.setItemText(0, _translate("DateCalculation", "Standard"))
        self.calc_mode.setItemText(1, _translate("DateCalculation", "Scientific"))
        self.calc_mode.setItemText(2, _translate("DateCalculation", "Programmer"))
        self.calc_mode.setItemText(3, _translate("DateCalculation", "Date Calculation"))

