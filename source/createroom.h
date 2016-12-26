#ifndef CREATEROOM_H
#define CREATEROOM_H

#include <QDialog>

namespace Ui {
class createroom;
}

class createroom : public QDialog
{
    Q_OBJECT

public:

    explicit createroom(QWidget *parent = 0);

    ~createroom();

    QPair<QString,int> getPair();

signals:

    void newroom(const QPair<QString,int> pair);

private slots:

    void on_pushButton_clicked();

private:

    Ui::createroom *ui;

    QPair<QString,int> pair;
};

#endif // CREATEROOM_H
