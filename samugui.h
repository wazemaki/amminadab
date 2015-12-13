#ifndef SAMUGUI_H
#define SAMUGUI_H

#include <QMainWindow>
#include <QThread>
#include <QtCore>

class SamuThread : public QThread
{
    Q_OBJECT
public:
    explicit SamuThread(QObject* parent) :
        QThread(parent){
    }
    QString openfile="bbe";
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
    SamuThread *mThread;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SamuGUI *ui;
public slots:
    void teszteles(QString);
};

#endif // SAMUGUI_H
