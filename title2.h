#ifndef TITLE2_H
#define TITLE2_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class title2;
}

class title2 : public QWidget
{
    Q_OBJECT

public:
    explicit title2(QWidget *parent = 0);
    ~title2();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void on_pushButton_3_clicked();
    void setLable(const QString &text);
    void seticon(const QString &line);
    void pushbutton(int &a);

private slots:

    void onClicked();
signals:
    void clicked123();

private:
    Ui::title2 *ui;

    QPoint m_start;  //起始点
    QPoint m_end;    //结束点
    bool m_leftButtonPressed;   //鼠标左键按下标记
};

#endif // TITLE2_H
