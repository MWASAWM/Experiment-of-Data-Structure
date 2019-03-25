#include "dataplayback.h"
#include "ui_dataplayback.h"

#include <QtSql>
#include <QSqlQuery>
#include <QSqlTableModel>


DataPlayBack::DataPlayBack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataPlayBack)
{
    ui->setupUi(this);

 }

DataPlayBack::~DataPlayBack()
{
    delete ui;
}
