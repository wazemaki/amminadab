#ifndef SAMUGUI_H
#define SAMUGUI_H

#include <QMainWindow>
#include <QThread>
#include <QtCore>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject* parent) :
        QThread(parent){
    }
    void run();
signals:
    void test(QString);

public slots:

};

namespace Ui {
class SamuGUI;
}

class SamuGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit SamuGUI(QWidget *parent = 0);
    ~SamuGUI();
    MyThread *mThread;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::SamuGUI *ui;
public slots:
    void teszteles(QString);
};

#endif // SAMUGUI_H
