#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSettings>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QSettings settings("MaelPierre", "BurgerQuiz");
    ui->setupUi(this);
    ui->line_ip->setPlaceholderText("Entrez l'ip de la base");
    ui->line_name->setPlaceholderText("Entrez le nom de la base");
    ui->line_username->setPlaceholderText("Entrez le username de la base");
    ui->line_password->setPlaceholderText("Entrez le mot de passe de la base");
    ui->line_ip->setText(settings.value("ip").toString());
    ui->line_name->setText(settings.value("name").toString());
    ui->line_username->setText(settings.value("user").toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_login_clicked()
{

    QSettings settings("MaelPierre", "BurgerQuiz");
    QString username_bdd=ui->line_username->text();
    QByteArray convert1 = username_bdd.toUtf8();
    string inser_username = convert1.data();

    QString password_bdd=ui->line_password->text();
    QByteArray convert2 = password_bdd.toUtf8();
    string inser_password = convert2.data();

    QString ip_bdd=ui->line_ip->text();
    QByteArray convert3 = ip_bdd.toUtf8();
    string inser_ip = convert3.data();

    QString name_bdd=ui->line_name->text();
    QByteArray convert4 = name_bdd.toUtf8();
    string inser_name = convert4.data();
    settings.setValue("ip", ui->line_ip->text());
    settings.setValue("name", ui->line_name->text());
    settings.setValue("user", ui->line_username->text());

    try{

        driver = get_driver_instance();

        con = driver->connect("tcp://"+inser_ip+":3306",inser_username,inser_password);

        con->setSchema(inser_name);

        Statement* statement=con->createStatement();

        statement->executeQuery("SELECT * FROM Joue");
        statement->executeQuery("SELECT * FROM Joueur");
        statement->executeQuery("SELECT * FROM Partie");
        statement->executeQuery("SELECT * FROM Partie_Question");
        statement->executeQuery("SELECT * FROM Proposition");
        statement->executeQuery("SELECT * FROM Question");
        statement->executeQuery("SELECT * FROM Theme");

        QMessageBox::information(this,"Login","Informations de connexion correctes");
        hide();
        secondMainWindow=new SecondMainWindow(this, driver, con);
        secondMainWindow->show();

    }catch(SQLException &e){
        QMessageBox::warning(this,"Login","Informations de connexion incorrectes");
    }
}
