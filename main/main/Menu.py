# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Menu.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Menu(object):
    def setupUi(self, Menu):
        Menu.setObjectName("Menu")
        Menu.resize(184, 660)
        self.push_button_menu = QtWidgets.QPushButton(Menu)
        self.push_button_menu.setGeometry(QtCore.QRect(0, 0, 41, 41))
        self.push_button_menu.setObjectName("push_button_menu")
        self.listWidget = QtWidgets.QListWidget(Menu)
        self.listWidget.setGeometry(QtCore.QRect(0, 40, 181, 611))
        font = QtGui.QFont()
        font.setPointSize(16)
        self.listWidget.setFont(font)
        self.listWidget.setObjectName("listWidget")
        item = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item)
        item = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item)
        item = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item)
        item = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item)
        item = QtWidgets.QListWidgetItem()
        self.listWidget.addItem(item)

        self.retranslateUi(Menu)
        QtCore.QMetaObject.connectSlotsByName(Menu)

    def retranslateUi(self, Menu):
        _translate = QtCore.QCoreApplication.translate
        Menu.setWindowTitle(_translate("Menu", "Form"))
        self.push_button_menu.setText(_translate("Menu", "="))
        __sortingEnabled = self.listWidget.isSortingEnabled()
        self.listWidget.setSortingEnabled(False)
        item = self.listWidget.item(0)
        item.setText(_translate("Menu", "Standard"))
        item = self.listWidget.item(1)
        item.setText(_translate("Menu", "Scientific"))
        item = self.listWidget.item(2)
        item.setText(_translate("Menu", "Programmer"))
        item = self.listWidget.item(3)
        item.setText(_translate("Menu", "DateCalculation"))
        item = self.listWidget.item(4)
        item.setText(_translate("Menu", "About"))
        self.listWidget.setSortingEnabled(__sortingEnabled)

