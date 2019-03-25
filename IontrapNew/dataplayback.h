#ifndef DATAPLAYBACK_H
#define DATAPLAYBACK_H

#include <QWidget>

namespace Ui {
class DataPlayBack;
}

class DataPlayBack : public QWidget
{
    Q_OBJECT

public:
    explicit DataPlayBack(QWidget *parent = 0);
    ~DataPlayBack();

private:
    Ui::DataPlayBack *ui;
};

#endif // DATAPLAYBACK_H
