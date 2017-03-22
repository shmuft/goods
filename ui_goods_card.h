/********************************************************************************
** Form generated from reading UI file 'goods_card.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODS_CARD_H
#define UI_GOODS_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_goods_card
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QPushButton *add_barcode;
    QTableView *view_barcode;
    QPushButton *del_barcode;
    QPushButton *cancel;
    QVBoxLayout *verticalLayout_7;
    QPushButton *addEgaisGood;
    QTableView *egais_goods;
    QPushButton *removeEgais;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label;
    QLineEdit *goods_edit;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLineEdit *code_edit;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *price_edit;
    QLineEdit *units_edit;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout;
    QLineEdit *group_edit;
    QLineEdit *volume_edit;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *excise;
    QCheckBox *alcohol;
    QTreeWidget *goodsGroup;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QWidget *goods_card)
    {
        if (goods_card->objectName().isEmpty())
            goods_card->setObjectName(QStringLiteral("goods_card"));
        goods_card->setEnabled(true);
        goods_card->resize(734, 375);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(goods_card->sizePolicy().hasHeightForWidth());
        goods_card->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(goods_card);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        add_barcode = new QPushButton(goods_card);
        add_barcode->setObjectName(QStringLiteral("add_barcode"));
        add_barcode->setEnabled(true);
        sizePolicy.setHeightForWidth(add_barcode->sizePolicy().hasHeightForWidth());
        add_barcode->setSizePolicy(sizePolicy);
        add_barcode->setFocusPolicy(Qt::NoFocus);

        verticalLayout_6->addWidget(add_barcode);

        view_barcode = new QTableView(goods_card);
        view_barcode->setObjectName(QStringLiteral("view_barcode"));
        view_barcode->setEnabled(true);
        sizePolicy.setHeightForWidth(view_barcode->sizePolicy().hasHeightForWidth());
        view_barcode->setSizePolicy(sizePolicy);
        view_barcode->setFocusPolicy(Qt::NoFocus);
        view_barcode->setTabKeyNavigation(false);

        verticalLayout_6->addWidget(view_barcode);

        del_barcode = new QPushButton(goods_card);
        del_barcode->setObjectName(QStringLiteral("del_barcode"));
        del_barcode->setEnabled(true);
        sizePolicy.setHeightForWidth(del_barcode->sizePolicy().hasHeightForWidth());
        del_barcode->setSizePolicy(sizePolicy);
        del_barcode->setFocusPolicy(Qt::NoFocus);

        verticalLayout_6->addWidget(del_barcode);


        gridLayout->addLayout(verticalLayout_6, 1, 0, 4, 1);

        cancel = new QPushButton(goods_card);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setEnabled(true);
        sizePolicy.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cancel, 4, 3, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        addEgaisGood = new QPushButton(goods_card);
        addEgaisGood->setObjectName(QStringLiteral("addEgaisGood"));
        addEgaisGood->setEnabled(true);
        sizePolicy.setHeightForWidth(addEgaisGood->sizePolicy().hasHeightForWidth());
        addEgaisGood->setSizePolicy(sizePolicy);
        addEgaisGood->setFocusPolicy(Qt::NoFocus);

        verticalLayout_7->addWidget(addEgaisGood);

        egais_goods = new QTableView(goods_card);
        egais_goods->setObjectName(QStringLiteral("egais_goods"));
        egais_goods->setEnabled(true);
        sizePolicy.setHeightForWidth(egais_goods->sizePolicy().hasHeightForWidth());
        egais_goods->setSizePolicy(sizePolicy);
        egais_goods->setFocusPolicy(Qt::NoFocus);

        verticalLayout_7->addWidget(egais_goods);

        removeEgais = new QPushButton(goods_card);
        removeEgais->setObjectName(QStringLiteral("removeEgais"));
        removeEgais->setEnabled(true);
        sizePolicy.setHeightForWidth(removeEgais->sizePolicy().hasHeightForWidth());
        removeEgais->setSizePolicy(sizePolicy);
        removeEgais->setFocusPolicy(Qt::NoFocus);

        verticalLayout_7->addWidget(removeEgais);


        gridLayout->addLayout(verticalLayout_7, 1, 1, 4, 1);

        pushButton_3 = new QPushButton(goods_card);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(pushButton_3, 4, 2, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(goods_card);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);

        verticalLayout_9->addWidget(label);

        goods_edit = new QLineEdit(goods_card);
        goods_edit->setObjectName(QStringLiteral("goods_edit"));
        goods_edit->setEnabled(true);

        verticalLayout_9->addWidget(goods_edit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_4 = new QLabel(goods_card);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);

        verticalLayout_5->addWidget(label_4);

        code_edit = new QLineEdit(goods_card);
        code_edit->setObjectName(QStringLiteral("code_edit"));
        code_edit->setEnabled(true);

        verticalLayout_5->addWidget(code_edit);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(goods_card);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(goods_card);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);

        verticalLayout_4->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        price_edit = new QLineEdit(goods_card);
        price_edit->setObjectName(QStringLiteral("price_edit"));
        price_edit->setEnabled(true);
        price_edit->setFrame(true);

        verticalLayout_3->addWidget(price_edit);

        units_edit = new QLineEdit(goods_card);
        units_edit->setObjectName(QStringLiteral("units_edit"));
        units_edit->setEnabled(true);

        verticalLayout_3->addWidget(units_edit);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(goods_card);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(goods_card);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(true);

        verticalLayout_2->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        group_edit = new QLineEdit(goods_card);
        group_edit->setObjectName(QStringLiteral("group_edit"));
        group_edit->setEnabled(true);

        verticalLayout->addWidget(group_edit);

        volume_edit = new QLineEdit(goods_card);
        volume_edit->setObjectName(QStringLiteral("volume_edit"));
        volume_edit->setEnabled(true);

        verticalLayout->addWidget(volume_edit);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(horizontalLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        excise = new QCheckBox(goods_card);
        excise->setObjectName(QStringLiteral("excise"));
        excise->setEnabled(true);
        sizePolicy.setHeightForWidth(excise->sizePolicy().hasHeightForWidth());
        excise->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(excise);

        alcohol = new QCheckBox(goods_card);
        alcohol->setObjectName(QStringLiteral("alcohol"));
        alcohol->setEnabled(true);
        sizePolicy.setHeightForWidth(alcohol->sizePolicy().hasHeightForWidth());
        alcohol->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(alcohol);


        horizontalLayout_3->addLayout(verticalLayout_8);

        goodsGroup = new QTreeWidget(goods_card);
        goodsGroup->setObjectName(QStringLiteral("goodsGroup"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(goodsGroup->sizePolicy().hasHeightForWidth());
        goodsGroup->setSizePolicy(sizePolicy1);
        goodsGroup->setColumnCount(1);

        horizontalLayout_3->addWidget(goodsGroup);


        verticalLayout_9->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_9, 0, 0, 1, 4);

        label_5 = new QLabel(goods_card);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(true);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_5, 1, 2, 1, 2);

        pushButton = new QPushButton(goods_card);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 3, 2, 1, 2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(goods_edit);
        label_4->setBuddy(code_edit);
        label_2->setBuddy(price_edit);
        label_3->setBuddy(units_edit);
        label_6->setBuddy(group_edit);
        label_7->setBuddy(volume_edit);
#endif // QT_NO_SHORTCUT

        retranslateUi(goods_card);

        QMetaObject::connectSlotsByName(goods_card);
    } // setupUi

    void retranslateUi(QWidget *goods_card)
    {
        goods_card->setWindowTitle(QApplication::translate("goods_card", "\320\232\320\260\321\200\321\202\320\276\321\207\320\272\320\260 \321\202\320\276\320\262\320\260\321\200\320\260", Q_NULLPTR));
        add_barcode->setText(QApplication::translate("goods_card", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\250\320\232", Q_NULLPTR));
        del_barcode->setText(QApplication::translate("goods_card", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\250\320\232", Q_NULLPTR));
        cancel->setText(QApplication::translate("goods_card", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
        addEgaisGood->setText(QApplication::translate("goods_card", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200 \320\225\320\223\320\220\320\230\320\241", Q_NULLPTR));
        removeEgais->setText(QApplication::translate("goods_card", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200 \320\265\320\263\320\260\320\270\321\201", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("goods_card", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("goods_card", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        label_4->setText(QApplication::translate("goods_card", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\270\320\271 \320\272\320\276\320\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("goods_card", "\320\246\320\265\320\275\320\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("goods_card", "\320\225\320\264\320\270\320\275\320\270\321\206\321\213 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("goods_card", "\320\223\321\200\321\203\320\277\320\277\320\260 \320\277\320\265\321\207\320\260\321\202\320\270", Q_NULLPTR));
        label_7->setText(QApplication::translate("goods_card", "\320\236\320\261\321\214\320\265\320\274", Q_NULLPTR));
        excise->setText(QApplication::translate("goods_card", "\320\220\320\272\321\206\320\270\320\267\320\275\321\213\320\271", Q_NULLPTR));
        alcohol->setText(QApplication::translate("goods_card", "\320\220\320\273\320\272\320\276\320\263\320\276\320\273\321\214\320\275\321\213\320\271", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = goodsGroup->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("goods_card", "\320\242\320\276\320\262\320\260\321\200\320\275\320\260\321\217 \320\223\321\200\321\203\320\277\320\277\320\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("goods_card", "<html><head/><body><p>\320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\272\320\275\320\276\320\277\320\272\321\203 \320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\320\262\320\260\321\200, </p><p>\320\236\321\201\320\272\320\260\320\275\320\270\321\200\321\203\320\271\321\202\320\265 \320\260\320\272\321\206\320\270\320\267\320\275\321\203\321\216 \320\274\320\260\321\200\320\272\321\203, </p><p>\320\237\321\200\320\270\320\262\321\217\320\266\320\270\321\202\320\265 \321\202\320\276\320\262\320\260\321\200 \320\265\320\263\320\260\320\270\321\201</p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("goods_card", "\320\236\320\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class goods_card: public Ui_goods_card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODS_CARD_H
