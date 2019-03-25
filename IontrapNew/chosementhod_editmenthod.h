#ifndef CHOSEMENTHOD_EDITMENTHOD_H
#define CHOSEMENTHOD_EDITMENTHOD_H

#include <QWidget>
#include <QFile>
#include <menthodparameter.h>
#include <messagedialog.h>
#include <ui_top_para.h>


namespace Ui {
class ChoseMenthod_EditMenthod;
}

class ChoseMenthod_EditMenthod : public QWidget
{
    Q_OBJECT

public:
    explicit ChoseMenthod_EditMenthod(QWidget *parent = nullptr);
    ~ChoseMenthod_EditMenthod();

    MenthodParameter *menthod;

    void PutinMenthod(QString MenthodName);

    void updateTop();

    void changeTitle();

signals:

    void RenewSignal();


private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_MenthodDetermination_clicked();

    void on_Return_clicked();

    void on_AddRow_clicked();

    void on_DeleteRow_clicked();

    void on_AddStatus_clicked();

    void on_DeleteStatus_clicked();

    void RecordMenthod();

    void WriteMenthodtoFile(QString menthodname);

    void ReadMenthodfromFile(QString menthodname);

    void ShowMessage(QString mess);

    void ShowInput(QString mess);

    void InputFinish();






private:
    Ui::ChoseMenthod_EditMenthod *ui;
    struct HeatContol
    {
     int StageNumber;
     int StartTime;
     int EndTemperature;
     int HeatRate;
     int StorageTime;
    };





};

#endif // CHOSEMENTHOD_EDITMENTHOD_H
