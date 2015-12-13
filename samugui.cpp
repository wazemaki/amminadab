#include "samugui.h"
#include "ui_samugui.h"
#include "moc_samugui.cpp"
#include<QFileDialog>
#include <iostream>

SamuGUI::SamuGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SamuGUI)
{
    ui->setupUi(this);
    mThread = new SamuThread(this);
    connect(mThread,SIGNAL(test(QString)),this,SLOT(teszteles(QString)));
}
SamuGUI::~SamuGUI()
{
    mThread->terminate();
    while(!mThread->isFinished()){ }
    delete ui;
}

void SamuGUI::teszteles(QString str){
    ui->textBrowser->append(str);
}

void SamuGUI::on_pushButton_clicked()
{
    mThread->start();
}

void SamuGUI::on_pushButton_3_clicked()
{
    mThread->openfile=QFileDialog::getOpenFileName(this,"File megnyitása","/","Text File (*.txt)");
    ui->pushButton_3->setText(mThread->openfile+" opened");
}
