#ifndef TITLE2_H
#define TITLE2_H

#include <QWidget>

namespace Ui {
class title2;
}

class title2 : public QWidget
{
    Q_OBJECT

public:
    explicit title2(QWidget *parent = 0);
    ~title2();

private:
    Ui::title2 *ui;
};

#endif // TITLE2_H
