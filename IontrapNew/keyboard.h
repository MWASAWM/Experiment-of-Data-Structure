#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>

namespace Ui {
class KeyBoard;
}

class KeyBoard : public QDialog
{
    Q_OBJECT

public:
    explicit KeyBoard(QWidget *parent = nullptr);
    ~KeyBoard();

private slots:
    void on_backspace_clicked();

private:
    Ui::KeyBoard *ui;
    void addword();
    QString data;
};

#endif // KEYBOARD_H
