#include "keyboard.h"
#include "ui_keyboard.h"

KeyBoard::KeyBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
    ui->lineEdit->setFocusPolicy(Qt::NoFocus);
     QList<QPushButton *> list= this->findChildren<QPushButton *>();
     foreach(QPushButton *a,list)
     {

         a->setFocusPolicy(Qt::NoFocus);
         if(a->text()!="Enter"&&a->text()!="×")
         connect(a,&QPushButton::clicked,this,&KeyBoard::addword);
     }
}
void KeyBoard::addword()
{
    QPushButton * send=qobject_cast<QPushButton *>(sender());
    data.append(send->text());
    ui->lineEdit->setText(data);

}
KeyBoard::~KeyBoard()
{
    delete ui;
}

void KeyBoard::on_backspace_clicked()
{
    data.chop(1);
    ui->lineEdit->setText(data);
}
