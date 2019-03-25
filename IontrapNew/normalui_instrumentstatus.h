#ifndef NORMALUI_INSTRUMENTSTATUS_H
#define NORMALUI_INSTRUMENTSTATUS_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class NormalUI_InstrumentStatus;
}

class NormalUI_InstrumentStatus : public QWidget
{
    Q_OBJECT

public:
    explicit NormalUI_InstrumentStatus(QWidget *parent = nullptr);
    ~NormalUI_InstrumentStatus();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void renew();

private:
    Ui::NormalUI_InstrumentStatus *ui;
    QTimer *timer;
};

#endif // NORMALUI_INSTRUMENTSTATUS_H
