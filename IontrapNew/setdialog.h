#ifndef SETDIALOG_H
#define SETDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <menthodparameter.h>
namespace Ui {
class SetDialog;
}
struct SetParameter
{
    int count;
    int length[10];
    int SW[10];
    int EW[10];
    int ionmodule=0;//0:fixed;1：AGC
    int scanmoudle=0;//0:fullscan;1:MS
    int PreIonTime;
    int ScanRate;
    int Ionsave;


};

class SetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetDialog(QWidget *parent = nullptr);
    ~SetDialog();

signals:
    void setPara(SetParameter *para);


private slots:

    void on_Add_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Delete_clicked();

    void on_OpenMenthod_clicked();

    void insertRow(int rowcount);

    void readmth(QString path);

private:
    Ui::SetDialog *ui;

    SetParameter *para;


    int column=0;
    int row=0;

    QLineEdit *lineedit_1;


    QComboBox *combox_1;
    QComboBox *combox_2;

    MenthodParameter menthod;

};

#endif // SETDIALOG_H
