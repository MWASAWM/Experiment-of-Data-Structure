#ifndef CONNECTINSTRUMENT_H
#define CONNECTINSTRUMENT_H

#include <QDialog>

namespace Ui {
class connectinstrument;
}

class connectinstrument : public QDialog
{
    Q_OBJECT

public:
    explicit connectinstrument(QWidget *parent = nullptr);
    ~connectinstrument();

private:
    Ui::connectinstrument *ui;
};

#endif // CONNECTINSTRUMENT_H
