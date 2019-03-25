#include "sigcolletform.h"
#include "ui_sigcolletform.h"
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
#include <QDataStream>

#include <QFileDialog>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

#include <QPalette>
#include <QtWidgets/QListWidgetItem>
#include "setdialog.h"
#include "chartview.h"
#include "callout.h"
#include <QTimer>
#include <QList>
#include <QPointF>
#include <qfile.h>

#include "stdio.h"
#include "crcchecksum.h"
#include <instruomentpara.h>
#include <dataacquirethread.h>

using namespace std;


#define MAXCLOCKRATE 500000000

SigColletForm::SigColletForm(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::SigColletForm)
{
    ui->setupUi(this);





}





SigColletForm::~SigColletForm()
{
    delete ui;
}

