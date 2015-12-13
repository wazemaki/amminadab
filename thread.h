#ifndef THREAD_H
#define THREAD_H

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

#endif // THREAD_H
