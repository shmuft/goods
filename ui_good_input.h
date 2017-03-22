/********************************************************************************
** Form generated from reading UI file 'good_input.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOOD_INPUT_H
#define UI_GOOD_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_good_input
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_11;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *resetFind;
    QHBoxLayout *horizontalLayout;
    QLineEdit *filename;
    QPushButton *selectfile;
    QPushButton *load;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *settings;
    QTableView *tableView;

    void setupUi(QWidget *good_input)
    {
        if (good_input->objectName().isEmpty())
            good_input->setObjectName(QStringLiteral("good_input"));
        good_input->resize(671, 279);
        gridLayout = new QGridLayout(good_input);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(good_input);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit = new QLineEdit(good_input);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        pushButton_11 = new QPushButton(good_input);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_11);

        pushButton_9 = new QPushButton(good_input);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(good_input);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_10);

        resetFind = new QPushButton(good_input);
        resetFind->setObjectName(QStringLiteral("resetFind"));
        sizePolicy.setHeightForWidth(resetFind->sizePolicy().hasHeightForWidth());
        resetFind->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(resetFind);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        filename = new QLineEdit(good_input);
        filename->setObjectName(QStringLiteral("filename"));

        horizontalLayout->addWidget(filename);

        selectfile = new QPushButton(good_input);
        selectfile->setObjectName(QStringLiteral("selectfile"));
        sizePolicy.setHeightForWidth(selectfile->sizePolicy().hasHeightForWidth());
        selectfile->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(selectfile);

        load = new QPushButton(good_input);
        load->setObjectName(QStringLiteral("load"));
        sizePolicy.setHeightForWidth(load->sizePolicy().hasHeightForWidth());
        load->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(load);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_3 = new QPushButton(good_input);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton = new QPushButton(good_input);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_4 = new QPushButton(good_input);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_4);

        settings = new QPushButton(good_input);
        settings->setObjectName(QStringLiteral("settings"));
        sizePolicy.setHeightForWidth(settings->sizePolicy().hasHeightForWidth());
        settings->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(settings);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        tableView = new QTableView(good_input);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(tableView, 1, 0, 1, 1);


        retranslateUi(good_input);

        QMetaObject::connectSlotsByName(good_input);
    } // setupUi

    void retranslateUi(QWidget *good_input)
    {
        good_input->setWindowTitle(QApplication::translate("good_input", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("good_input", "\320\237\320\236\320\230\320\241\320\232", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("good_input", "\320\250-\320\232\320\276\320\264", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("good_input", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("good_input", "\320\232\320\276\320\264", Q_NULLPTR));
        resetFind->setText(QApplication::translate("good_input", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\276\320\270\321\201\320\272", Q_NULLPTR));
        selectfile->setText(QApplication::translate("good_input", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        load->setText(QApplication::translate("good_input", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("good_input", "\320\276\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        pushButton->setText(QApplication::translate("good_input", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("good_input", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        settings->setText(QApplication::translate("good_input", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class good_input: public Ui_good_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOOD_INPUT_H
