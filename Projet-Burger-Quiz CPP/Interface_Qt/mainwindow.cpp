#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_ip->setPlaceholderText("Entrez l'ip de la base");
    ui->line_name->setPlaceholderText("Entrez le nom de la base");
    ui->line_username->setPlaceholderText("Entrez le username de la base");
    ui->line_password->setPlaceholderText("Entrez le mot de passe de la base");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_login_clicked()
{

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

    try{

        driver = get_driver_instance();

        con = driver->connect(inser_ip,inser_username,inser_password);

        con->setSchema(inser_name);

        QMessageBox::information(this,"Login","Informations de connexion correctes");
        hide();
        secondMainWindow=new SecondMainWindow(this, driver, con);
        secondMainWindow->show();

    }catch(SQLException &e){
        QMessageBox::warning(this,"Login","Informations de connexion incorrectes");
    }
}
