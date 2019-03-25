#include "messagedialog.h"
#include "ui_messagedialog.h"

MessageDialog::MessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);


}

MessageDialog::~MessageDialog()
{
    delete ui;
}

void MessageDialog::SetMessage(QString message)
{

    ui->Message->setText(message);
}
