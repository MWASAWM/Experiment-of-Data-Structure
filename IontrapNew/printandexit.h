#ifndef PRINTANDEXIT_H
#define PRINTANDEXIT_H

#include <QWidget>

namespace Ui {
class PrintandExit;
}

class PrintandExit : public QWidget
{
    Q_OBJECT

public:
    explicit PrintandExit(QWidget *parent = 0);
    ~PrintandExit();

private slots:


private:
    Ui::PrintandExit *ui;
};

#endif // PRINTANDEXIT_H
