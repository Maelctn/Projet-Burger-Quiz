#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*!
 * \file MainWindow.h
 * \brief Fenêtre principale de login
 * \author Balan Pierre
 * \version 0.1
 */

#include "secondmainwindow.h"

namespace Ui {
class MainWindow;
}

/*! \class MainWindow
* \brief classe représentant la fenêtre principale
*
*  La classe gère la page de login
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
   *  \brief Constructeur
   *
   *  Constructeur de la classe MainWindow
   *
   *  \param QWidget parent de la MainWindow
   */
    explicit MainWindow(QWidget *parent = 0);
    /*!
   *  \brief Destructeur
   *
   *  Destructeur de la classe MainWindow
   */
    ~MainWindow();

private slots:

/*!
 *  \brief Bouton login
 *
 *  Permet de se login si infos correctes
 */
    void on_button_login_clicked();

private:
    Ui::MainWindow *ui;
    SecondMainWindow *secondMainWindow;
    Driver* driver;
    Connection *con;
    string inser_name;
};

#endif // MAINWINDOW_H
