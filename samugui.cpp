#include "samugui.h"
#include "ui_samugui.h"
#include "moc_samugui.cpp"
#include <iostream>

SamuGUI::SamuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SamuGUI)
{
    ui->setupUi(this);
    mThread = new MyThread(this);
    connect(mThread,SIGNAL(test(QString)),this,SLOT(teszteles(QString)));
}
SamuGUI::~SamuGUI()
{
    delete mThread;
    delete ui;
}

void SamuGUI::teszteles(QString str){
    ui->textBrowser->append(str);
}

void SamuGUI::on_pushButton_clicked()
{
    mThread->start();
}


