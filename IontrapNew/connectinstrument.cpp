#include "connectinstrument.h"
#include "ui_connectinstrument.h"

connectinstrument::connectinstrument(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectinstrument)
{
    ui->setupUi(this);
}

connectinstrument::~connectinstrument()
{
    delete ui;
}
