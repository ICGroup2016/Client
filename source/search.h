#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>

namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT
signals:
    void findfor(QString);
public:
    explicit search(QWidget *parent = 0);
    ~search();

private:
    Ui::search *ui;
    void startsearch();
};


#endif // SEARCH_H
