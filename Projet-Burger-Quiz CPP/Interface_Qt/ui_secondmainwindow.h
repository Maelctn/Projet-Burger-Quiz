/********************************************************************************
** Form generated from reading UI file 'secondmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDMAINWINDOW_H
#define UI_SECONDMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton;
    QVBoxLayout *layout_tableau;
    QTabWidget *tableau_onglet;
    QWidget *onglet_joueur;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *layout_joueur;
    QVBoxLayout *layout_table_joueur;
    QTableWidget *table_joueur;
    QPushButton *supprimer_joueur;
    QVBoxLayout *layout_champs_joueur;
    QHBoxLayout *layou_login;
    QLabel *label_login;
    QLineEdit *line_login;
    QHBoxLayout *layout_password;
    QLabel *label_password;
    QLineEdit *line_password;
    QCheckBox *checkBox_password;
    QHBoxLayout *layout_bestscore;
    QLabel *label_bestscore;
    QSpinBox *line_bestscore;
    QCheckBox *checkBox_bestscore;
    QCheckBox *checkBox_score_only;
    QHBoxLayout *layout_button_joueur;
    QPushButton *inserer_joueur;
    QPushButton *modifier_joueur;
    QWidget *onglet_partie;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *layout_partie;
    QVBoxLayout *layout_table_partie;
    QTableWidget *table_partie;
    QPushButton *supprimer_partie;
    QVBoxLayout *layout_champs_partie;
    QHBoxLayout *layout_score;
    QLabel *label_score;
    QSpinBox *line_score;
    QCheckBox *checkBox_score;
    QCheckBox *checkBox_score2;
    QHBoxLayout *layout_q1;
    QLabel *label_q1;
    QComboBox *comboBox_q1;
    QHBoxLayout *layout_q2;
    QLabel *label_q2;
    QComboBox *comboBox_q2;
    QHBoxLayout *layout_q3;
    QLabel *label_q3;
    QComboBox *comboBox_q3;
    QHBoxLayout *layout_button_partie;
    QPushButton *inserer_partie;
    QPushButton *modifier_partie;
    QWidget *onglet_theme;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *layout_theme;
    QVBoxLayout *layout_table_theme;
    QTableWidget *table_theme;
    QPushButton *supprimer_theme;
    QVBoxLayout *layout_champs_theme;
    QHBoxLayout *layout_line_theme;
    QLabel *label_theme;
    QLineEdit *line_theme;
    QHBoxLayout *layout_button_theme;
    QPushButton *inserer_theme;
    QPushButton *modifier_theme;
    QWidget *onglet_question;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *layout_question;
    QVBoxLayout *layout_table_question;
    QTableWidget *table_question;
    QPushButton *supprimer_question;
    QVBoxLayout *layout_champs_question;
    QHBoxLayout *layout_choix_theme;
    QLabel *label_choix_theme;
    QComboBox *comboBox_theme;
    QHBoxLayout *layout_line_question;
    QLabel *label_question;
    QLineEdit *line_question;
    QHBoxLayout *layout_choix1;
    QLabel *label_choix1;
    QLineEdit *line_choix1;
    QHBoxLayout *layout_choix2;
    QLabel *label_choix2;
    QLineEdit *line_choix2;
    QHBoxLayout *layout_button_question;
    QPushButton *inserer_question;
    QPushButton *modifier_question;
    QWidget *onglet_proposition;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *layout_proposition;
    QVBoxLayout *layout_table_proposition;
    QTableWidget *table_proposition;
    QPushButton *supprimer_proposition;
    QVBoxLayout *layout_champs_proposition;
    QHBoxLayout *layout_choix_question;
    QLabel *label_choix_question;
    QComboBox *comboBox_question;
    QHBoxLayout *layout_line_proposition;
    QLabel *label_proposition;
    QLineEdit *line_proposition;
    QHBoxLayout *layout_choix_reponse;
    QLabel *label_choix_reponse;
    QComboBox *comboBox_reponse;
    QHBoxLayout *button_proposition;
    QPushButton *inserer_proposition;
    QPushButton *modifier_proposition;
    QWidget *onglet_deconnexion;
    QVBoxLayout *verticalLayout_3;
    QPushButton *button_deconnexion;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SecondMainWindow)
    {
        if (SecondMainWindow->objectName().isEmpty())
            SecondMainWindow->setObjectName(QStringLiteral("SecondMainWindow"));
        SecondMainWindow->setWindowModality(Qt::WindowModal);
        SecondMainWindow->resize(629, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SecondMainWindow->sizePolicy().hasHeightForWidth());
        SecondMainWindow->setSizePolicy(sizePolicy);
        SecondMainWindow->setMaximumSize(QSize(1200, 800));
        centralwidget = new QWidget(SecondMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        verticalLayout->addWidget(toolButton);

        layout_tableau = new QVBoxLayout();
        layout_tableau->setObjectName(QStringLiteral("layout_tableau"));
        tableau_onglet = new QTabWidget(centralwidget);
        tableau_onglet->setObjectName(QStringLiteral("tableau_onglet"));
        tableau_onglet->setEnabled(true);
        tableau_onglet->setMaximumSize(QSize(1200, 800));
        tableau_onglet->setSizeIncrement(QSize(0, 0));
        tableau_onglet->setBaseSize(QSize(0, 0));
        onglet_joueur = new QWidget();
        onglet_joueur->setObjectName(QStringLiteral("onglet_joueur"));
        verticalLayout_5 = new QVBoxLayout(onglet_joueur);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        layout_joueur = new QHBoxLayout();
        layout_joueur->setObjectName(QStringLiteral("layout_joueur"));
        layout_table_joueur = new QVBoxLayout();
        layout_table_joueur->setObjectName(QStringLiteral("layout_table_joueur"));
        table_joueur = new QTableWidget(onglet_joueur);
        if (table_joueur->columnCount() < 4)
            table_joueur->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_joueur->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_joueur->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_joueur->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_joueur->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_joueur->setObjectName(QStringLiteral("table_joueur"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(table_joueur->sizePolicy().hasHeightForWidth());
        table_joueur->setSizePolicy(sizePolicy1);
        table_joueur->setMaximumSize(QSize(800, 600));
        table_joueur->setLineWidth(1);
        table_joueur->horizontalHeader()->setStretchLastSection(true);

        layout_table_joueur->addWidget(table_joueur);

        supprimer_joueur = new QPushButton(onglet_joueur);
        supprimer_joueur->setObjectName(QStringLiteral("supprimer_joueur"));

        layout_table_joueur->addWidget(supprimer_joueur);


        layout_joueur->addLayout(layout_table_joueur);

        layout_champs_joueur = new QVBoxLayout();
        layout_champs_joueur->setObjectName(QStringLiteral("layout_champs_joueur"));
        layou_login = new QHBoxLayout();
        layou_login->setObjectName(QStringLiteral("layou_login"));
        label_login = new QLabel(onglet_joueur);
        label_login->setObjectName(QStringLiteral("label_login"));

        layou_login->addWidget(label_login);

        line_login = new QLineEdit(onglet_joueur);
        line_login->setObjectName(QStringLiteral("line_login"));

        layou_login->addWidget(line_login);


        layout_champs_joueur->addLayout(layou_login);

        layout_password = new QHBoxLayout();
        layout_password->setObjectName(QStringLiteral("layout_password"));
        label_password = new QLabel(onglet_joueur);
        label_password->setObjectName(QStringLiteral("label_password"));

        layout_password->addWidget(label_password);

        line_password = new QLineEdit(onglet_joueur);
        line_password->setObjectName(QStringLiteral("line_password"));
        line_password->setEchoMode(QLineEdit::Password);

        layout_password->addWidget(line_password);


        layout_champs_joueur->addLayout(layout_password);

        checkBox_password = new QCheckBox(onglet_joueur);
        checkBox_password->setObjectName(QStringLiteral("checkBox_password"));

        layout_champs_joueur->addWidget(checkBox_password);

        layout_bestscore = new QHBoxLayout();
        layout_bestscore->setObjectName(QStringLiteral("layout_bestscore"));
        label_bestscore = new QLabel(onglet_joueur);
        label_bestscore->setObjectName(QStringLiteral("label_bestscore"));

        layout_bestscore->addWidget(label_bestscore);

        line_bestscore = new QSpinBox(onglet_joueur);
        line_bestscore->setObjectName(QStringLiteral("line_bestscore"));
        line_bestscore->setMaximum(100000);

        layout_bestscore->addWidget(line_bestscore);

        checkBox_bestscore = new QCheckBox(onglet_joueur);
        checkBox_bestscore->setObjectName(QStringLiteral("checkBox_bestscore"));

        layout_bestscore->addWidget(checkBox_bestscore);


        layout_champs_joueur->addLayout(layout_bestscore);

        checkBox_score_only = new QCheckBox(onglet_joueur);
        checkBox_score_only->setObjectName(QStringLiteral("checkBox_score_only"));

        layout_champs_joueur->addWidget(checkBox_score_only);

        layout_button_joueur = new QHBoxLayout();
        layout_button_joueur->setObjectName(QStringLiteral("layout_button_joueur"));
        inserer_joueur = new QPushButton(onglet_joueur);
        inserer_joueur->setObjectName(QStringLiteral("inserer_joueur"));

        layout_button_joueur->addWidget(inserer_joueur);

        modifier_joueur = new QPushButton(onglet_joueur);
        modifier_joueur->setObjectName(QStringLiteral("modifier_joueur"));

        layout_button_joueur->addWidget(modifier_joueur);


        layout_champs_joueur->addLayout(layout_button_joueur);


        layout_joueur->addLayout(layout_champs_joueur);


        verticalLayout_5->addLayout(layout_joueur);

        tableau_onglet->addTab(onglet_joueur, QString());
        onglet_partie = new QWidget();
        onglet_partie->setObjectName(QStringLiteral("onglet_partie"));
        verticalLayout_7 = new QVBoxLayout(onglet_partie);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        layout_partie = new QHBoxLayout();
        layout_partie->setObjectName(QStringLiteral("layout_partie"));
        layout_table_partie = new QVBoxLayout();
        layout_table_partie->setObjectName(QStringLiteral("layout_table_partie"));
        table_partie = new QTableWidget(onglet_partie);
        if (table_partie->columnCount() < 5)
            table_partie->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_partie->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_partie->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_partie->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_partie->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_partie->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        table_partie->setObjectName(QStringLiteral("table_partie"));
        table_partie->setMaximumSize(QSize(800, 600));
        table_partie->horizontalHeader()->setStretchLastSection(true);

        layout_table_partie->addWidget(table_partie);

        supprimer_partie = new QPushButton(onglet_partie);
        supprimer_partie->setObjectName(QStringLiteral("supprimer_partie"));
        supprimer_partie->setIconSize(QSize(16, 16));

        layout_table_partie->addWidget(supprimer_partie);


        layout_partie->addLayout(layout_table_partie);

        layout_champs_partie = new QVBoxLayout();
        layout_champs_partie->setObjectName(QStringLiteral("layout_champs_partie"));
        layout_score = new QHBoxLayout();
        layout_score->setObjectName(QStringLiteral("layout_score"));
        label_score = new QLabel(onglet_partie);
        label_score->setObjectName(QStringLiteral("label_score"));

        layout_score->addWidget(label_score);

        line_score = new QSpinBox(onglet_partie);
        line_score->setObjectName(QStringLiteral("line_score"));
        line_score->setMaximum(100000);

        layout_score->addWidget(line_score);

        checkBox_score = new QCheckBox(onglet_partie);
        checkBox_score->setObjectName(QStringLiteral("checkBox_score"));

        layout_score->addWidget(checkBox_score);


        layout_champs_partie->addLayout(layout_score);

        checkBox_score2 = new QCheckBox(onglet_partie);
        checkBox_score2->setObjectName(QStringLiteral("checkBox_score2"));

        layout_champs_partie->addWidget(checkBox_score2);

        layout_q1 = new QHBoxLayout();
        layout_q1->setObjectName(QStringLiteral("layout_q1"));
        label_q1 = new QLabel(onglet_partie);
        label_q1->setObjectName(QStringLiteral("label_q1"));

        layout_q1->addWidget(label_q1);

        comboBox_q1 = new QComboBox(onglet_partie);
        comboBox_q1->setObjectName(QStringLiteral("comboBox_q1"));

        layout_q1->addWidget(comboBox_q1);


        layout_champs_partie->addLayout(layout_q1);

        layout_q2 = new QHBoxLayout();
        layout_q2->setObjectName(QStringLiteral("layout_q2"));
        label_q2 = new QLabel(onglet_partie);
        label_q2->setObjectName(QStringLiteral("label_q2"));

        layout_q2->addWidget(label_q2);

        comboBox_q2 = new QComboBox(onglet_partie);
        comboBox_q2->setObjectName(QStringLiteral("comboBox_q2"));

        layout_q2->addWidget(comboBox_q2);


        layout_champs_partie->addLayout(layout_q2);

        layout_q3 = new QHBoxLayout();
        layout_q3->setObjectName(QStringLiteral("layout_q3"));
        label_q3 = new QLabel(onglet_partie);
        label_q3->setObjectName(QStringLiteral("label_q3"));

        layout_q3->addWidget(label_q3);

        comboBox_q3 = new QComboBox(onglet_partie);
        comboBox_q3->setObjectName(QStringLiteral("comboBox_q3"));

        layout_q3->addWidget(comboBox_q3);


        layout_champs_partie->addLayout(layout_q3);

        layout_button_partie = new QHBoxLayout();
        layout_button_partie->setObjectName(QStringLiteral("layout_button_partie"));
        inserer_partie = new QPushButton(onglet_partie);
        inserer_partie->setObjectName(QStringLiteral("inserer_partie"));

        layout_button_partie->addWidget(inserer_partie);

        modifier_partie = new QPushButton(onglet_partie);
        modifier_partie->setObjectName(QStringLiteral("modifier_partie"));

        layout_button_partie->addWidget(modifier_partie);


        layout_champs_partie->addLayout(layout_button_partie);


        layout_partie->addLayout(layout_champs_partie);


        verticalLayout_7->addLayout(layout_partie);

        tableau_onglet->addTab(onglet_partie, QString());
        onglet_theme = new QWidget();
        onglet_theme->setObjectName(QStringLiteral("onglet_theme"));
        verticalLayout_8 = new QVBoxLayout(onglet_theme);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        layout_theme = new QHBoxLayout();
        layout_theme->setObjectName(QStringLiteral("layout_theme"));
        layout_table_theme = new QVBoxLayout();
        layout_table_theme->setObjectName(QStringLiteral("layout_table_theme"));
        table_theme = new QTableWidget(onglet_theme);
        if (table_theme->columnCount() < 2)
            table_theme->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_theme->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_theme->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        table_theme->setObjectName(QStringLiteral("table_theme"));
        table_theme->setMaximumSize(QSize(800, 600));
        table_theme->horizontalHeader()->setStretchLastSection(true);

        layout_table_theme->addWidget(table_theme);

        supprimer_theme = new QPushButton(onglet_theme);
        supprimer_theme->setObjectName(QStringLiteral("supprimer_theme"));

        layout_table_theme->addWidget(supprimer_theme);


        layout_theme->addLayout(layout_table_theme);

        layout_champs_theme = new QVBoxLayout();
        layout_champs_theme->setObjectName(QStringLiteral("layout_champs_theme"));
        layout_line_theme = new QHBoxLayout();
        layout_line_theme->setObjectName(QStringLiteral("layout_line_theme"));
        label_theme = new QLabel(onglet_theme);
        label_theme->setObjectName(QStringLiteral("label_theme"));

        layout_line_theme->addWidget(label_theme);

        line_theme = new QLineEdit(onglet_theme);
        line_theme->setObjectName(QStringLiteral("line_theme"));

        layout_line_theme->addWidget(line_theme);


        layout_champs_theme->addLayout(layout_line_theme);

        layout_button_theme = new QHBoxLayout();
        layout_button_theme->setObjectName(QStringLiteral("layout_button_theme"));
        inserer_theme = new QPushButton(onglet_theme);
        inserer_theme->setObjectName(QStringLiteral("inserer_theme"));

        layout_button_theme->addWidget(inserer_theme);

        modifier_theme = new QPushButton(onglet_theme);
        modifier_theme->setObjectName(QStringLiteral("modifier_theme"));

        layout_button_theme->addWidget(modifier_theme);


        layout_champs_theme->addLayout(layout_button_theme);


        layout_theme->addLayout(layout_champs_theme);


        verticalLayout_8->addLayout(layout_theme);

        tableau_onglet->addTab(onglet_theme, QString());
        onglet_question = new QWidget();
        onglet_question->setObjectName(QStringLiteral("onglet_question"));
        verticalLayout_9 = new QVBoxLayout(onglet_question);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        layout_question = new QHBoxLayout();
        layout_question->setObjectName(QStringLiteral("layout_question"));
        layout_table_question = new QVBoxLayout();
        layout_table_question->setObjectName(QStringLiteral("layout_table_question"));
        table_question = new QTableWidget(onglet_question);
        if (table_question->columnCount() < 5)
            table_question->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_question->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_question->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_question->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_question->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_question->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        table_question->setObjectName(QStringLiteral("table_question"));
        table_question->setMaximumSize(QSize(800, 600));
        table_question->horizontalHeader()->setStretchLastSection(true);

        layout_table_question->addWidget(table_question);

        supprimer_question = new QPushButton(onglet_question);
        supprimer_question->setObjectName(QStringLiteral("supprimer_question"));

        layout_table_question->addWidget(supprimer_question);


        layout_question->addLayout(layout_table_question);

        layout_champs_question = new QVBoxLayout();
        layout_champs_question->setObjectName(QStringLiteral("layout_champs_question"));
        layout_choix_theme = new QHBoxLayout();
        layout_choix_theme->setObjectName(QStringLiteral("layout_choix_theme"));
        label_choix_theme = new QLabel(onglet_question);
        label_choix_theme->setObjectName(QStringLiteral("label_choix_theme"));

        layout_choix_theme->addWidget(label_choix_theme);

        comboBox_theme = new QComboBox(onglet_question);
        comboBox_theme->setObjectName(QStringLiteral("comboBox_theme"));

        layout_choix_theme->addWidget(comboBox_theme);


        layout_champs_question->addLayout(layout_choix_theme);

        layout_line_question = new QHBoxLayout();
        layout_line_question->setObjectName(QStringLiteral("layout_line_question"));
        label_question = new QLabel(onglet_question);
        label_question->setObjectName(QStringLiteral("label_question"));

        layout_line_question->addWidget(label_question);

        line_question = new QLineEdit(onglet_question);
        line_question->setObjectName(QStringLiteral("line_question"));

        layout_line_question->addWidget(line_question);


        layout_champs_question->addLayout(layout_line_question);

        layout_choix1 = new QHBoxLayout();
        layout_choix1->setObjectName(QStringLiteral("layout_choix1"));
        label_choix1 = new QLabel(onglet_question);
        label_choix1->setObjectName(QStringLiteral("label_choix1"));

        layout_choix1->addWidget(label_choix1);

        line_choix1 = new QLineEdit(onglet_question);
        line_choix1->setObjectName(QStringLiteral("line_choix1"));

        layout_choix1->addWidget(line_choix1);


        layout_champs_question->addLayout(layout_choix1);

        layout_choix2 = new QHBoxLayout();
        layout_choix2->setObjectName(QStringLiteral("layout_choix2"));
        label_choix2 = new QLabel(onglet_question);
        label_choix2->setObjectName(QStringLiteral("label_choix2"));

        layout_choix2->addWidget(label_choix2);

        line_choix2 = new QLineEdit(onglet_question);
        line_choix2->setObjectName(QStringLiteral("line_choix2"));

        layout_choix2->addWidget(line_choix2);


        layout_champs_question->addLayout(layout_choix2);

        layout_button_question = new QHBoxLayout();
        layout_button_question->setObjectName(QStringLiteral("layout_button_question"));
        inserer_question = new QPushButton(onglet_question);
        inserer_question->setObjectName(QStringLiteral("inserer_question"));

        layout_button_question->addWidget(inserer_question);

        modifier_question = new QPushButton(onglet_question);
        modifier_question->setObjectName(QStringLiteral("modifier_question"));

        layout_button_question->addWidget(modifier_question);


        layout_champs_question->addLayout(layout_button_question);


        layout_question->addLayout(layout_champs_question);


        verticalLayout_9->addLayout(layout_question);

        tableau_onglet->addTab(onglet_question, QString());
        onglet_proposition = new QWidget();
        onglet_proposition->setObjectName(QStringLiteral("onglet_proposition"));
        verticalLayout_10 = new QVBoxLayout(onglet_proposition);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        layout_proposition = new QHBoxLayout();
        layout_proposition->setObjectName(QStringLiteral("layout_proposition"));
        layout_proposition->setSizeConstraint(QLayout::SetMinAndMaxSize);
        layout_proposition->setContentsMargins(0, -1, -1, -1);
        layout_table_proposition = new QVBoxLayout();
        layout_table_proposition->setObjectName(QStringLiteral("layout_table_proposition"));
        table_proposition = new QTableWidget(onglet_proposition);
        if (table_proposition->columnCount() < 4)
            table_proposition->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table_proposition->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table_proposition->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table_proposition->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        table_proposition->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        table_proposition->setObjectName(QStringLiteral("table_proposition"));
        table_proposition->setMaximumSize(QSize(800, 600));
        table_proposition->horizontalHeader()->setStretchLastSection(true);

        layout_table_proposition->addWidget(table_proposition);

        supprimer_proposition = new QPushButton(onglet_proposition);
        supprimer_proposition->setObjectName(QStringLiteral("supprimer_proposition"));

        layout_table_proposition->addWidget(supprimer_proposition);


        layout_proposition->addLayout(layout_table_proposition);

        layout_champs_proposition = new QVBoxLayout();
        layout_champs_proposition->setObjectName(QStringLiteral("layout_champs_proposition"));
        layout_choix_question = new QHBoxLayout();
        layout_choix_question->setObjectName(QStringLiteral("layout_choix_question"));
        label_choix_question = new QLabel(onglet_proposition);
        label_choix_question->setObjectName(QStringLiteral("label_choix_question"));

        layout_choix_question->addWidget(label_choix_question);

        comboBox_question = new QComboBox(onglet_proposition);
        comboBox_question->setObjectName(QStringLiteral("comboBox_question"));

        layout_choix_question->addWidget(comboBox_question);


        layout_champs_proposition->addLayout(layout_choix_question);

        layout_line_proposition = new QHBoxLayout();
        layout_line_proposition->setObjectName(QStringLiteral("layout_line_proposition"));
        label_proposition = new QLabel(onglet_proposition);
        label_proposition->setObjectName(QStringLiteral("label_proposition"));

        layout_line_proposition->addWidget(label_proposition);

        line_proposition = new QLineEdit(onglet_proposition);
        line_proposition->setObjectName(QStringLiteral("line_proposition"));

        layout_line_proposition->addWidget(line_proposition);


        layout_champs_proposition->addLayout(layout_line_proposition);

        layout_choix_reponse = new QHBoxLayout();
        layout_choix_reponse->setObjectName(QStringLiteral("layout_choix_reponse"));
        label_choix_reponse = new QLabel(onglet_proposition);
        label_choix_reponse->setObjectName(QStringLiteral("label_choix_reponse"));

        layout_choix_reponse->addWidget(label_choix_reponse);

        comboBox_reponse = new QComboBox(onglet_proposition);
        comboBox_reponse->setObjectName(QStringLiteral("comboBox_reponse"));

        layout_choix_reponse->addWidget(comboBox_reponse);


        layout_champs_proposition->addLayout(layout_choix_reponse);

        button_proposition = new QHBoxLayout();
        button_proposition->setObjectName(QStringLiteral("button_proposition"));
        inserer_proposition = new QPushButton(onglet_proposition);
        inserer_proposition->setObjectName(QStringLiteral("inserer_proposition"));

        button_proposition->addWidget(inserer_proposition);

        modifier_proposition = new QPushButton(onglet_proposition);
        modifier_proposition->setObjectName(QStringLiteral("modifier_proposition"));

        button_proposition->addWidget(modifier_proposition);


        layout_champs_proposition->addLayout(button_proposition);


        layout_proposition->addLayout(layout_champs_proposition);


        verticalLayout_10->addLayout(layout_proposition);

        tableau_onglet->addTab(onglet_proposition, QString());
        onglet_deconnexion = new QWidget();
        onglet_deconnexion->setObjectName(QStringLiteral("onglet_deconnexion"));
        verticalLayout_3 = new QVBoxLayout(onglet_deconnexion);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        button_deconnexion = new QPushButton(onglet_deconnexion);
        button_deconnexion->setObjectName(QStringLiteral("button_deconnexion"));

        verticalLayout_3->addWidget(button_deconnexion);

        tableau_onglet->addTab(onglet_deconnexion, QString());

        layout_tableau->addWidget(tableau_onglet);


        verticalLayout->addLayout(layout_tableau);

        SecondMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SecondMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 629, 25));
        SecondMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SecondMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SecondMainWindow->setStatusBar(statusbar);

        retranslateUi(SecondMainWindow);

        tableau_onglet->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SecondMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SecondMainWindow)
    {
        SecondMainWindow->setWindowTitle(QApplication::translate("SecondMainWindow", "MainWindow", 0));
        toolButton->setText(QApplication::translate("SecondMainWindow", "Rafraichir", 0));
        QTableWidgetItem *___qtablewidgetitem = table_joueur->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SecondMainWindow", "id_login", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_joueur->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SecondMainWindow", "Login", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_joueur->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SecondMainWindow", "Password", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_joueur->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SecondMainWindow", "Best_score", 0));
        supprimer_joueur->setText(QApplication::translate("SecondMainWindow", "SUPPRIMER", 0));
        label_login->setText(QApplication::translate("SecondMainWindow", "Login ", 0));
        label_password->setText(QApplication::translate("SecondMainWindow", "Password ", 0));
        checkBox_password->setText(QApplication::translate("SecondMainWindow", "Ne pas modifier le mot de passe", 0));
        label_bestscore->setText(QApplication::translate("SecondMainWindow", "Best score ", 0));
        checkBox_bestscore->setText(QApplication::translate("SecondMainWindow", "Pas de best score", 0));
        checkBox_score_only->setText(QApplication::translate("SecondMainWindow", "Modifier uniquement le best score", 0));
        inserer_joueur->setText(QApplication::translate("SecondMainWindow", "INSERER", 0));
        modifier_joueur->setText(QApplication::translate("SecondMainWindow", "MODIFIER", 0));
        tableau_onglet->setTabText(tableau_onglet->indexOf(onglet_joueur), QApplication::translate("SecondMainWindow", "Joueur", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_partie->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("SecondMainWindow", "id_partie", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_partie->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("SecondMainWindow", "Score", 0));
        QTableWidgetItem *___qtablewidgetitem6 = table_partie->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("SecondMainWindow", "Nouvelle colonne", 0));
        QTableWidgetItem *___qtablewidgetitem7 = table_partie->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("SecondMainWindow", "Question 2", 0));
        QTableWidgetItem *___qtablewidgetitem8 = table_partie->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("SecondMainWindow", "Question 3", 0));
        supprimer_partie->setText(QApplication::translate("SecondMainWindow", "SUPPRIMER", 0));
        label_score->setText(QApplication::translate("SecondMainWindow", "Score ", 0));
        checkBox_score->setText(QApplication::translate("SecondMainWindow", "Pas de score", 0));
        checkBox_score2->setText(QApplication::translate("SecondMainWindow", "Modifier uniquement le score", 0));
        label_q1->setText(QApplication::translate("SecondMainWindow", "Question 1 ", 0));
        label_q2->setText(QApplication::translate("SecondMainWindow", "Question 2 ", 0));
        label_q3->setText(QApplication::translate("SecondMainWindow", "Question 3 ", 0));
        inserer_partie->setText(QApplication::translate("SecondMainWindow", "INSERER", 0));
        modifier_partie->setText(QApplication::translate("SecondMainWindow", "MODIFIER", 0));
        tableau_onglet->setTabText(tableau_onglet->indexOf(onglet_partie), QApplication::translate("SecondMainWindow", "Partie", 0));
        QTableWidgetItem *___qtablewidgetitem9 = table_theme->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("SecondMainWindow", "id_theme", 0));
        QTableWidgetItem *___qtablewidgetitem10 = table_theme->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("SecondMainWindow", "Th\303\250me", 0));
        supprimer_theme->setText(QApplication::translate("SecondMainWindow", "SUPPRIMER", 0));
        label_theme->setText(QApplication::translate("SecondMainWindow", "Th\303\250me ", 0));
        inserer_theme->setText(QApplication::translate("SecondMainWindow", "INSERER", 0));
        modifier_theme->setText(QApplication::translate("SecondMainWindow", "MODIFIER", 0));
        tableau_onglet->setTabText(tableau_onglet->indexOf(onglet_theme), QApplication::translate("SecondMainWindow", "Th\303\250me", 0));
        QTableWidgetItem *___qtablewidgetitem11 = table_question->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("SecondMainWindow", "id_question", 0));
        QTableWidgetItem *___qtablewidgetitem12 = table_question->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("SecondMainWindow", "Question", 0));
        QTableWidgetItem *___qtablewidgetitem13 = table_question->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("SecondMainWindow", "Choix 1", 0));
        QTableWidgetItem *___qtablewidgetitem14 = table_question->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("SecondMainWindow", "Choix 2", 0));
        QTableWidgetItem *___qtablewidgetitem15 = table_question->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("SecondMainWindow", "id_theme", 0));
        supprimer_question->setText(QApplication::translate("SecondMainWindow", "SUPPRIMER", 0));
        label_choix_theme->setText(QApplication::translate("SecondMainWindow", "Th\303\250me ", 0));
        label_question->setText(QApplication::translate("SecondMainWindow", "Question ", 0));
        label_choix1->setText(QApplication::translate("SecondMainWindow", "Choix 1 ", 0));
        label_choix2->setText(QApplication::translate("SecondMainWindow", "Choix 2 ", 0));
        inserer_question->setText(QApplication::translate("SecondMainWindow", "INSERER", 0));
        modifier_question->setText(QApplication::translate("SecondMainWindow", "MODIFIER", 0));
        tableau_onglet->setTabText(tableau_onglet->indexOf(onglet_question), QApplication::translate("SecondMainWindow", "Question", 0));
        QTableWidgetItem *___qtablewidgetitem16 = table_proposition->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("SecondMainWindow", "id_proposition", 0));
        QTableWidgetItem *___qtablewidgetitem17 = table_proposition->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("SecondMainWindow", "Proposition", 0));
        QTableWidgetItem *___qtablewidgetitem18 = table_proposition->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("SecondMainWindow", "R\303\251ponse", 0));
        QTableWidgetItem *___qtablewidgetitem19 = table_proposition->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("SecondMainWindow", "id_question", 0));
        supprimer_proposition->setText(QApplication::translate("SecondMainWindow", "SUPPRIMER", 0));
        label_choix_question->setText(QApplication::translate("SecondMainWindow", "Question", 0));
        label_proposition->setText(QApplication::translate("SecondMainWindow", "Proposition ", 0));
        label_choix_reponse->setText(QApplication::translate("SecondMainWindow", "R\303\251ponse", 0));
        inserer_proposition->setText(QApplication::translate("SecondMainWindow", "INSERER", 0));
        modifier_proposition->setText(QApplication::translate("SecondMainWindow", "MODIFIER", 0));
        tableau_onglet->setTabText(tableau_onglet->indexOf(onglet_proposition), QApplication::translate("SecondMainWindow", "Proposition", 0));
        button_deconnexion->setText(QApplication::translate("SecondMainWindow", "Deconnexion", 0));
        tableau_onglet->setTabText(tableau_onglet->indexOf(onglet_deconnexion), QApplication::translate("SecondMainWindow", "Deconnexion", 0));
    } // retranslateUi

};

namespace Ui {
    class SecondMainWindow: public Ui_SecondMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDMAINWINDOW_H
