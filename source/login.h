#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    QPair<QString,int> getpair();
    void reset();

signals:
    void Login(const QPair<QString,int> pair);

private slots:
    void on_pushButton_clicked();
private:
    QPair<QString,int> pair;
    Ui::login *ui;
};

#endif // LOGIN_H
