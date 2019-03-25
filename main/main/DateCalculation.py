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
        DateCalculation.resize(545, 786)
        self.push_button_menu = QtWidgets.QPushButton(DateCalculation)
        self.push_button_menu.setGeometry(QtCore.QRect(0, 0, 41, 41))
        self.push_button_menu.setObjectName("push_button_menu")
        self.mode_name = QtWidgets.QLabel(DateCalculation)
        self.mode_name.setGeometry(QtCore.QRect(40, 0, 200, 41))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(15)
        self.mode_name.setFont(font)
        self.mode_name.setObjectName("mode_name")
        self.calendarWidget = QtWidgets.QCalendarWidget(DateCalculation)
        self.calendarWidget.setGeometry(QtCore.QRect(0, 80, 400, 240))
        self.calendarWidget.setObjectName("calendarWidget")
        self.calendarWidget_2 = QtWidgets.QCalendarWidget(DateCalculation)
        self.calendarWidget_2.setGeometry(QtCore.QRect(0, 360, 400, 240))
        self.calendarWidget_2.setObjectName("calendarWidget_2")
        self.label = QtWidgets.QLabel(DateCalculation)
        self.label.setGeometry(QtCore.QRect(0, 42, 60, 35))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(15)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(DateCalculation)
        self.label_2.setGeometry(QtCore.QRect(0, 320, 60, 35))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(15)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(DateCalculation)
        self.label_3.setGeometry(QtCore.QRect(0, 600, 161, 35))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(15)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.ans = QtWidgets.QLabel(DateCalculation)
        self.ans.setGeometry(QtCore.QRect(0, 640, 401, 61))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(24)
        self.ans.setFont(font)
        self.ans.setText("")
        self.ans.setObjectName("ans")
        self.date1 = QtWidgets.QLabel(DateCalculation)
        self.date1.setGeometry(QtCore.QRect(70, 42, 331, 35))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(15)
        self.date1.setFont(font)
        self.date1.setText("")
        self.date1.setObjectName("date1")
        self.date2 = QtWidgets.QLabel(DateCalculation)
        self.date2.setGeometry(QtCore.QRect(60, 320, 331, 35))
        font = QtGui.QFont()
        font.setFamily("Microsoft YaHei UI")
        font.setPointSize(15)
        self.date2.setFont(font)
        self.date2.setText("")
        self.date2.setObjectName("date2")

        self.retranslateUi(DateCalculation)
        QtCore.QMetaObject.connectSlotsByName(DateCalculation)

    def retranslateUi(self, DateCalculation):
        _translate = QtCore.QCoreApplication.translate
        DateCalculation.setWindowTitle(_translate("DateCalculation", "Form"))
        self.push_button_menu.setText(_translate("DateCalculation", "="))
        self.mode_name.setText(_translate("DateCalculation", "DateCalculation"))
        self.label.setText(_translate("DateCalculation", "From"))
        self.label_2.setText(_translate("DateCalculation", "To"))
        self.label_3.setText(_translate("DateCalculation", "Difference"))

