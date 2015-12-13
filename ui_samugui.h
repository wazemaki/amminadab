/********************************************************************************
** Form generated from reading UI file 'samugui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMUGUI_H
#define UI_SAMUGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SamuGUI
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SamuGUI)
    {
        if (SamuGUI->objectName().isEmpty())
            SamuGUI->setObjectName(QStringLiteral("SamuGUI"));
        SamuGUI->resize(679, 516);
        centralWidget = new QWidget(SamuGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 420, 99, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 420, 99, 27));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 0, 661, 411));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 420, 451, 27));
        SamuGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SamuGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 679, 25));
        SamuGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SamuGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SamuGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SamuGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SamuGUI->setStatusBar(statusBar);

        retranslateUi(SamuGUI);

        QMetaObject::connectSlotsByName(SamuGUI);
    } // setupUi

    void retranslateUi(QMainWindow *SamuGUI)
    {
        SamuGUI->setWindowTitle(QApplication::translate("SamuGUI", "SamuGUI", 0));
        pushButton->setText(QApplication::translate("SamuGUI", "Start", 0));
        pushButton_2->setText(QApplication::translate("SamuGUI", "Stop", 0));
        pushButton_3->setText(QApplication::translate("SamuGUI", "Open input file", 0));
    } // retranslateUi

};

namespace Ui {
    class SamuGUI: public Ui_SamuGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMUGUI_H
