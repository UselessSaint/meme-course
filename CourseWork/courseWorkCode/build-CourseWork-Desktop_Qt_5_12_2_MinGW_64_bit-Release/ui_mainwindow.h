/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QFrame *frame_4;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_6;
    QComboBox *comboBox_2;
    QLabel *label_44;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *icoTab;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_9;
    QLineEdit *icoY;
    QLabel *label_10;
    QSpinBox *blue;
    QLabel *label_11;
    QLabel *label_2;
    QSpinBox *red;
    QLineEdit *gloss;
    QSpinBox *green;
    QLabel *label_8;
    QLabel *label_13;
    QLabel *label_12;
    QDoubleSpinBox *dispertion;
    QLineEdit *icoX;
    QDoubleSpinBox *reflection;
    QLabel *label_6;
    QLineEdit *icoZ;
    QLineEdit *radius;
    QWidget *cubeTab;
    QGridLayout *gridLayout_3;
    QLineEdit *depth;
    QLabel *label_18;
    QLineEdit *height;
    QLabel *label_14;
    QLabel *label_22;
    QLineEdit *cubeZ;
    QLineEdit *cubeY;
    QLabel *label_23;
    QLabel *label_17;
    QLabel *label_15;
    QLabel *label_20;
    QLabel *label_16;
    QLineEdit *cubeX;
    QLabel *label_21;
    QSpinBox *cubeRed;
    QLabel *label_24;
    QLabel *label_19;
    QLineEdit *width;
    QSpinBox *cubeBlue;
    QSpinBox *cubeGreen;
    QLineEdit *cubeGloss;
    QLabel *label_27;
    QLabel *label_26;
    QLabel *label_25;
    QDoubleSpinBox *cubeDisp;
    QDoubleSpinBox *cubeRef;
    QWidget *tab;
    QWidget *light;
    QGridLayout *gridLayout_5;
    QLabel *label_28;
    QLineEdit *ltY;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_29;
    QLineEdit *ltZ;
    QLabel *label_37;
    QLabel *label_30;
    QLineEdit *ltX;
    QLabel *label_39;
    QLabel *label_38;
    QLabel *label_33;
    QLabel *label_31;
    QLabel *label_34;
    QLineEdit *intens;
    QFrame *frame_3;
    QGridLayout *gridLayout_6;
    QLabel *label_43;
    QLabel *label_46;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QLineEdit *rotZ;
    QLineEdit *rotY;
    QLineEdit *rotX;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *pushButton_5;
    QFrame *frame_5;
    QGridLayout *gridLayout_8;
    QLabel *label_32;
    QSpinBox *rtDepth;
    QRadioButton *gourand;
    QRadioButton *phong;
    QRadioButton *rt;
    QCheckBox *persp;
    QSpinBox *thrd;
    QLabel *label_45;
    QPushButton *pushButton_4;
    QWidget *widget;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 800);
        MainWindow->setMinimumSize(QSize(1280, 800));
        MainWindow->setMaximumSize(QSize(1400, 800));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(1280, 800));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(300, 800));
        frame->setMaximumSize(QSize(300, 800));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pushButton_6 = new QPushButton(frame_4);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout_7->addWidget(pushButton_6, 1, 1, 1, 1);

        comboBox_2 = new QComboBox(frame_4);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_7->addWidget(comboBox_2, 1, 0, 1, 1);

        label_44 = new QLabel(frame_4);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout_7->addWidget(label_44, 0, 0, 1, 2);


        gridLayout_2->addWidget(frame_4, 4, 0, 1, 2);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 7, 0, 1, 2);

        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMaximumSize(QSize(300, 350));
        icoTab = new QWidget();
        icoTab->setObjectName(QString::fromUtf8("icoTab"));
        gridLayout = new QGridLayout(icoTab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(icoTab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_7 = new QLabel(icoTab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 3);

        label_4 = new QLabel(icoTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(icoTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        label_5 = new QLabel(icoTab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        label_9 = new QLabel(icoTab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 6, 0, 1, 3);

        icoY = new QLineEdit(icoTab);
        icoY->setObjectName(QString::fromUtf8("icoY"));

        gridLayout->addWidget(icoY, 2, 1, 1, 1);

        label_10 = new QLabel(icoTab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 7, 1, 1, 1);

        blue = new QSpinBox(icoTab);
        blue->setObjectName(QString::fromUtf8("blue"));
        blue->setMaximum(255);

        gridLayout->addWidget(blue, 5, 2, 1, 1);

        label_11 = new QLabel(icoTab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 8, 0, 1, 2);

        label_2 = new QLabel(icoTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        red = new QSpinBox(icoTab);
        red->setObjectName(QString::fromUtf8("red"));
        red->setMaximum(255);

        gridLayout->addWidget(red, 5, 0, 1, 1);

        gloss = new QLineEdit(icoTab);
        gloss->setObjectName(QString::fromUtf8("gloss"));

        gridLayout->addWidget(gloss, 10, 2, 1, 1);

        green = new QSpinBox(icoTab);
        green->setObjectName(QString::fromUtf8("green"));
        green->setMaximum(255);

        gridLayout->addWidget(green, 5, 1, 1, 1);

        label_8 = new QLabel(icoTab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 3);

        label_13 = new QLabel(icoTab);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 10, 0, 1, 2);

        label_12 = new QLabel(icoTab);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 9, 0, 1, 2);

        dispertion = new QDoubleSpinBox(icoTab);
        dispertion->setObjectName(QString::fromUtf8("dispertion"));
        dispertion->setMaximum(1.000000000000000);
        dispertion->setSingleStep(0.100000000000000);

        gridLayout->addWidget(dispertion, 8, 2, 1, 1);

        icoX = new QLineEdit(icoTab);
        icoX->setObjectName(QString::fromUtf8("icoX"));

        gridLayout->addWidget(icoX, 2, 0, 1, 1);

        reflection = new QDoubleSpinBox(icoTab);
        reflection->setObjectName(QString::fromUtf8("reflection"));
        reflection->setMaximum(1.000000000000000);
        reflection->setSingleStep(0.100000000000000);

        gridLayout->addWidget(reflection, 9, 2, 1, 1);

        label_6 = new QLabel(icoTab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 2, 1, 1);

        icoZ = new QLineEdit(icoTab);
        icoZ->setObjectName(QString::fromUtf8("icoZ"));

        gridLayout->addWidget(icoZ, 2, 2, 1, 1);

        radius = new QLineEdit(icoTab);
        radius->setObjectName(QString::fromUtf8("radius"));

        gridLayout->addWidget(radius, 7, 2, 1, 1);

        tabWidget->addTab(icoTab, QString());
        cubeTab = new QWidget();
        cubeTab->setObjectName(QString::fromUtf8("cubeTab"));
        gridLayout_3 = new QGridLayout(cubeTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        depth = new QLineEdit(cubeTab);
        depth->setObjectName(QString::fromUtf8("depth"));

        gridLayout_3->addWidget(depth, 7, 2, 1, 1);

        label_18 = new QLabel(cubeTab);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 3, 0, 1, 3);

        height = new QLineEdit(cubeTab);
        height->setObjectName(QString::fromUtf8("height"));

        gridLayout_3->addWidget(height, 7, 1, 1, 1);

        label_14 = new QLabel(cubeTab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 1, 1, 1, 1);

        label_22 = new QLabel(cubeTab);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_3->addWidget(label_22, 6, 0, 1, 1);

        cubeZ = new QLineEdit(cubeTab);
        cubeZ->setObjectName(QString::fromUtf8("cubeZ"));

        gridLayout_3->addWidget(cubeZ, 2, 2, 1, 1);

        cubeY = new QLineEdit(cubeTab);
        cubeY->setObjectName(QString::fromUtf8("cubeY"));

        gridLayout_3->addWidget(cubeY, 2, 1, 1, 1);

        label_23 = new QLabel(cubeTab);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_3->addWidget(label_23, 6, 1, 1, 1);

        label_17 = new QLabel(cubeTab);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 0, 0, 1, 3);

        label_15 = new QLabel(cubeTab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 1, 0, 1, 1);

        label_20 = new QLabel(cubeTab);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_3->addWidget(label_20, 4, 0, 1, 1);

        label_16 = new QLabel(cubeTab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 1, 2, 1, 1);

        cubeX = new QLineEdit(cubeTab);
        cubeX->setObjectName(QString::fromUtf8("cubeX"));

        gridLayout_3->addWidget(cubeX, 2, 0, 1, 1);

        label_21 = new QLabel(cubeTab);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_3->addWidget(label_21, 4, 2, 1, 1);

        cubeRed = new QSpinBox(cubeTab);
        cubeRed->setObjectName(QString::fromUtf8("cubeRed"));
        cubeRed->setMaximum(255);
        cubeRed->setValue(255);

        gridLayout_3->addWidget(cubeRed, 5, 0, 1, 1);

        label_24 = new QLabel(cubeTab);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_3->addWidget(label_24, 6, 2, 1, 1);

        label_19 = new QLabel(cubeTab);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_3->addWidget(label_19, 4, 1, 1, 1);

        width = new QLineEdit(cubeTab);
        width->setObjectName(QString::fromUtf8("width"));

        gridLayout_3->addWidget(width, 7, 0, 1, 1);

        cubeBlue = new QSpinBox(cubeTab);
        cubeBlue->setObjectName(QString::fromUtf8("cubeBlue"));
        cubeBlue->setMaximum(255);

        gridLayout_3->addWidget(cubeBlue, 5, 2, 1, 1);

        cubeGreen = new QSpinBox(cubeTab);
        cubeGreen->setObjectName(QString::fromUtf8("cubeGreen"));
        cubeGreen->setMaximum(255);

        gridLayout_3->addWidget(cubeGreen, 5, 1, 1, 1);

        cubeGloss = new QLineEdit(cubeTab);
        cubeGloss->setObjectName(QString::fromUtf8("cubeGloss"));

        gridLayout_3->addWidget(cubeGloss, 10, 2, 1, 1);

        label_27 = new QLabel(cubeTab);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_3->addWidget(label_27, 10, 0, 1, 2);

        label_26 = new QLabel(cubeTab);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_3->addWidget(label_26, 9, 0, 1, 2);

        label_25 = new QLabel(cubeTab);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_3->addWidget(label_25, 8, 0, 1, 2);

        cubeDisp = new QDoubleSpinBox(cubeTab);
        cubeDisp->setObjectName(QString::fromUtf8("cubeDisp"));
        cubeDisp->setMaximum(1.000000000000000);
        cubeDisp->setSingleStep(0.100000000000000);
        cubeDisp->setValue(1.000000000000000);

        gridLayout_3->addWidget(cubeDisp, 8, 2, 1, 1);

        cubeRef = new QDoubleSpinBox(cubeTab);
        cubeRef->setObjectName(QString::fromUtf8("cubeRef"));
        cubeRef->setMaximum(1.000000000000000);
        cubeRef->setSingleStep(0.100000000000000);
        cubeRef->setValue(1.000000000000000);

        gridLayout_3->addWidget(cubeRef, 9, 2, 1, 1);

        tabWidget->addTab(cubeTab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        light = new QWidget();
        light->setObjectName(QString::fromUtf8("light"));
        gridLayout_5 = new QGridLayout(light);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_28 = new QLabel(light);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_5->addWidget(label_28, 1, 1, 1, 1);

        ltY = new QLineEdit(light);
        ltY->setObjectName(QString::fromUtf8("ltY"));

        gridLayout_5->addWidget(ltY, 2, 1, 1, 1);

        label_35 = new QLabel(light);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_5->addWidget(label_35, 5, 1, 1, 1);

        label_36 = new QLabel(light);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_5->addWidget(label_36, 6, 1, 1, 1);

        label_29 = new QLabel(light);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_5->addWidget(label_29, 1, 0, 1, 1);

        ltZ = new QLineEdit(light);
        ltZ->setObjectName(QString::fromUtf8("ltZ"));

        gridLayout_5->addWidget(ltZ, 2, 2, 1, 1);

        label_37 = new QLabel(light);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_5->addWidget(label_37, 7, 1, 1, 1);

        label_30 = new QLabel(light);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_5->addWidget(label_30, 1, 2, 1, 1);

        ltX = new QLineEdit(light);
        ltX->setObjectName(QString::fromUtf8("ltX"));

        gridLayout_5->addWidget(ltX, 2, 0, 1, 1);

        label_39 = new QLabel(light);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_5->addWidget(label_39, 9, 1, 1, 1);

        label_38 = new QLabel(light);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_5->addWidget(label_38, 8, 1, 1, 1);

        label_33 = new QLabel(light);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_5->addWidget(label_33, 3, 1, 1, 1);

        label_31 = new QLabel(light);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_5->addWidget(label_31, 0, 0, 1, 3);

        label_34 = new QLabel(light);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_5->addWidget(label_34, 4, 1, 1, 1);

        intens = new QLineEdit(light);
        intens->setObjectName(QString::fromUtf8("intens"));

        gridLayout_5->addWidget(intens, 4, 2, 1, 1);

        tabWidget->addTab(light, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setAutoFillBackground(true);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_43 = new QLabel(frame_3);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_6->addWidget(label_43, 0, 0, 1, 2);

        label_46 = new QLabel(frame_3);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        gridLayout_6->addWidget(label_46, 2, 0, 1, 1);

        widget_2 = new QWidget(frame_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        rotZ = new QLineEdit(widget_2);
        rotZ->setObjectName(QString::fromUtf8("rotZ"));

        gridLayout_4->addWidget(rotZ, 1, 2, 1, 1);

        rotY = new QLineEdit(widget_2);
        rotY->setObjectName(QString::fromUtf8("rotY"));

        gridLayout_4->addWidget(rotY, 1, 1, 1, 1);

        rotX = new QLineEdit(widget_2);
        rotX->setObjectName(QString::fromUtf8("rotX"));

        gridLayout_4->addWidget(rotX, 1, 0, 1, 1);

        label_40 = new QLabel(widget_2);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_4->addWidget(label_40, 0, 1, 1, 1);

        label_41 = new QLabel(widget_2);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_4->addWidget(label_41, 0, 0, 1, 1);

        label_42 = new QLabel(widget_2);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_4->addWidget(label_42, 0, 2, 1, 1);


        gridLayout_6->addWidget(widget_2, 3, 0, 1, 2);

        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_6->addWidget(pushButton_2, 4, 0, 1, 2);

        comboBox = new QComboBox(frame_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_6->addWidget(comboBox, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(frame_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_6->addWidget(pushButton_5, 1, 1, 1, 1);


        gridLayout_2->addWidget(frame_3, 2, 0, 1, 2);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_5);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_32 = new QLabel(frame_5);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_8->addWidget(label_32, 3, 1, 1, 1);

        rtDepth = new QSpinBox(frame_5);
        rtDepth->setObjectName(QString::fromUtf8("rtDepth"));
        rtDepth->setMaximum(4);

        gridLayout_8->addWidget(rtDepth, 3, 2, 1, 1);

        gourand = new QRadioButton(frame_5);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(gourand);
        gourand->setObjectName(QString::fromUtf8("gourand"));

        gridLayout_8->addWidget(gourand, 0, 0, 1, 1);

        phong = new QRadioButton(frame_5);
        buttonGroup_2->addButton(phong);
        phong->setObjectName(QString::fromUtf8("phong"));

        gridLayout_8->addWidget(phong, 1, 0, 1, 1);

        rt = new QRadioButton(frame_5);
        buttonGroup_2->addButton(rt);
        rt->setObjectName(QString::fromUtf8("rt"));

        gridLayout_8->addWidget(rt, 3, 0, 1, 1);

        persp = new QCheckBox(frame_5);
        persp->setObjectName(QString::fromUtf8("persp"));
        persp->setChecked(false);
        persp->setTristate(false);

        gridLayout_8->addWidget(persp, 5, 1, 1, 2);

        thrd = new QSpinBox(frame_5);
        thrd->setObjectName(QString::fromUtf8("thrd"));
        thrd->setMinimum(1);
        thrd->setMaximum(8);
        thrd->setValue(2);

        gridLayout_8->addWidget(thrd, 4, 2, 1, 1);

        label_45 = new QLabel(frame_5);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        gridLayout_8->addWidget(label_45, 4, 1, 1, 1);


        gridLayout_2->addWidget(frame_5, 5, 0, 1, 2);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 1, 0, 1, 2);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout_2->addWidget(widget, 8, 0, 1, 2);


        horizontalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272", nullptr));
        label_44->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\270 \321\201\320\262\320\265\321\202\320\260 \321\201\321\206\320\265\320\275\321\213", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200 \320\270\320\272\320\276\321\201\320\260\321\215\320\264\321\200\320\260:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "R", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Z", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "G", nullptr));
        label_9->setText(QString());
        icoY->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\321\203\321\201:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \320\264\320\270\321\204\321\204\321\203\320\267\320\275\320\276\320\263\320\276 \320\276\321\201\320\262\320\265\321\211\320\265\320\275\320\270\321\217:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Y", nullptr));
        gloss->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \320\261\320\273\320\265\321\201\320\272\320\260: ", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \320\267\320\265\321\200\320\272\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\276\321\201\320\262\320\265\321\211\320\265\320\275\320\270\321\217:", nullptr));
        icoX->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "B", nullptr));
        icoZ->setText(QApplication::translate("MainWindow", "0", nullptr));
        radius->setText(QApplication::translate("MainWindow", "0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(icoTab), QApplication::translate("MainWindow", "\320\230\320\272\320\276\321\201\320\260\321\215\320\264\321\200", nullptr));
        depth->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\277\320\260\321\200\320\260\320\273\320\273\320\265\320\273\320\265\320\277\320\270\320\277\320\265\320\264:", nullptr));
        height->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Y", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        cubeZ->setText(QApplication::translate("MainWindow", "0", nullptr));
        cubeY->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200 \320\277\320\260\321\200\320\260\320\273\320\273\320\265\320\273\320\265\320\277\320\270\320\277\320\265\320\264:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "R", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Z", nullptr));
        cubeX->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "B", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\320\223\320\273\321\203\320\261\320\270\320\275\320\260", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "G", nullptr));
        width->setText(QApplication::translate("MainWindow", "100", nullptr));
        cubeGloss->setText(QApplication::translate("MainWindow", "1000", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \320\261\320\273\320\265\321\201\320\272\320\260: ", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \320\267\320\265\321\200\320\272\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\276\321\201\320\262\320\265\321\211\320\265\320\275\320\270\321\217:", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204. \320\264\320\270\321\204\321\204\321\203\320\267\320\275\320\276\320\263\320\276 \320\276\321\201\320\262\320\265\321\211\320\265\320\275\320\270\321\217:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(cubeTab), QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\320\265\320\277\320\270\320\277\320\265\320\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "Y", nullptr));
        ltY->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_35->setText(QString());
        label_36->setText(QString());
        label_29->setText(QApplication::translate("MainWindow", "X", nullptr));
        ltZ->setText(QApplication::translate("MainWindow", "-300", nullptr));
        label_37->setText(QString());
        label_30->setText(QApplication::translate("MainWindow", "Z", nullptr));
        ltX->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_39->setText(QString());
        label_38->setText(QString());
        label_33->setText(QString());
        label_31->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260:", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214:", nullptr));
        intens->setText(QApplication::translate("MainWindow", "100", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(light), QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260", nullptr));
        label_43->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213 \321\201\321\206\320\265\320\275\321\213", nullptr));
        label_46->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\273\321\213 (\320\263\321\200\320\260\320\264\321\203\321\201\321\213):", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\272\321\200\321\203\320\263 Y", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\272\321\200\321\203\320\263 X", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\272\321\200\321\203\320\263 Z", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "/   \320\223\320\273\321\203\320\261\320\270\320\275\320\260", nullptr));
        gourand->setText(QApplication::translate("MainWindow", "Z \320\261\321\203\321\204\321\204\320\265\321\200 + \320\223\321\203\321\200\320\276", nullptr));
        phong->setText(QApplication::translate("MainWindow", "Z \320\261\321\203\321\204\321\204\320\265\321\200 + \320\244\320\276\320\275\320\263", nullptr));
        rt->setText(QApplication::translate("MainWindow", "\320\242\321\200\320\260\321\201\321\201\320\270\321\200\320\276\320\262\320\272\320\260 \320\273\321\203\321\207\320\265\320\271", nullptr));
        persp->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\321\201\320\277\320\265\320\272\321\202\320\270\320\262\320\260", nullptr));
        label_45->setText(QApplication::translate("MainWindow", "/   \320\237\320\276\321\202\320\276\320\272\320\270", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
