#ifndef SECONDMAINWINDOW_H
#define SECONDMAINWINDOW_H

/*!
 * \file SecondMainWindow.h
 * \brief Fenêtre secondaire de gestion de BDD
 * \author Balan Pierre
 * \version 0.1
 */

#include <QMessageBox>
#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <iostream>
#include <string>
#include <QCryptographicHash>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

namespace Ui {
class SecondMainWindow;
}

/*! \class SecondMainWindow
* \brief classe représentant la fenêtre secondaire
*
*  La classe gère la page de gestion de BDD
*/

class SecondMainWindow : public QMainWindow
{
    Q_OBJECT

public:
  /*!
 *  \brief Constructeur
 *
 *  Constructeur de la classe SecondMainWindow
 *
 *  \param parent Qwidget parent de la SecondMainWindow
 *  \param[in] driver Driver pour se connecter à la BDD
 *  \param[in] con Connection pour se connecter à la BDD
 */
    explicit SecondMainWindow(QWidget *parent = 0, Driver* driver = 0, Connection *con = 0);
    /*!
   *  \brief Destructeur
   *
   *  Destructeur de la classe SecondMainWindow
   */
    ~SecondMainWindow();
    /*!
 *  \brief  Charge questions
 *
 *  Charge les questions dans les combobox
 */
    void charge_question();
    /*!
 *  \brief  Charge thèmes
 *
 *  Charge les thèmes dans la combobox
 */
    void charge_theme();
    /*!
 *  \brief  Rempli table joueur
 *
 *  Rempli le TableWidget de joueurs
 */
    void rempli_table_joueur();
    /*!
 *  \brief  Rempli tab joueur
 *
 *  Rempli le tableau 2 dim de joueurs
 */
    void rempli_tab_joueur();
    /*!
 *  \brief  Rempli table partie
 *
 *  Rempli le TableWidget de parties
 */
    void rempli_table_partie();
    /*!
 *  \brief  Rempli tab partie
 *
 *  Rempli le tableau 2 dim de parties
 */
    void rempli_tab_partie();
    /*!
 *  \brief  Rempli table thème
 *
 *  Rempli le TableWidget de thèmes
 */
    void rempli_table_theme();
    /*!
 *  \brief  Rempli tab thème
 *
 *  Rempli le tableau 2 dim de thèmes
 */
    void rempli_tab_theme();
    /*!
 *  \brief  Rempli table question
 *
 *  Rempli le TableWidget de questions
 */
    void rempli_table_question();
    /*!
 *  \brief  Rempli tab question
 *
 *  Rempli le tableau 2 dim de questions
 */
    void rempli_tab_question();
    /*!
 *  \brief  Rempli table proposition
 *
 *  Rempli le TableWidget de propositions
 */
    void rempli_table_proposition();
    /*!
 *  \brief  Rempli tab proposition
 *
 *  Rempli le tableau 2 dim de propositions
 */
    void rempli_tab_proposition();
    /*!
 *  \brief  Charge réponses
 *
 *  Charge les réponses par défaut dans la combobox
 */
    void combobox_reponse_default();
    /*!
 *  \brief  Vérifie l'existence de la partie
 *
 *  Vérifie si une partie correspond déjà à ces 3 questions
 */
    bool verif(string id, string q1, string q2, string q3);

private slots:
    /*!
  *  \brief  Slot bouton déconnexion
  *
  *  Déconnexion lors du clique sur le bouton
  */
    void on_button_deconnexion_clicked();
    /*!
   *  \brief  Slot bouton supprimer joueur
   *
   *  Supprime le(s) joueur(s) séléctionné(s)
   */
    void on_supprimer_joueur_clicked();
    /*!
   *  \brief  Slot bouton supprimer partie
   *
   *  Supprime le(s) partie(s) séléctionnée(s)
   */
    void on_supprimer_partie_clicked();
    /*!
   *  \brief  Slot bouton supprimer thème
   *
   *  Supprime le(s) thème(s) séléctionné(s)
   */
    void on_supprimer_theme_clicked();
    /*!
   *  \brief  Slot bouton supprimer question
   *
   *  Supprime le(s) question(s) séléctionnée(s)
   */
    void on_supprimer_question_clicked();
    /*!
   *  \brief  Slot bouton supprimer proposition
   *
   *  Supprime le(s) proposition(s) séléctionnée(s)
   */
    void on_supprimer_proposition_clicked();
    /*!
   *  \brief  Slot question séléctionée dans la combobox
   *
   *  Rempli la combobox réponse, avec celles associées à la question
   *
   *  \param[in] arg1
   */
    void on_comboBox_question_activated(const QString &arg1);
    /*!
   *  \brief  Slot bouton insérer thème
   *
   *  Insère le thème indiqué
   */
    void on_inserer_theme_clicked();
    /*!
   *  \brief  Slot bouton insérer question
   *
   *  Insère la question indiquée
   */
    void on_inserer_question_clicked();
    /*!
   *  \brief  Slot bouton insérer proposition
   *
   *  Insère la proposition indiquée
   */
    void on_inserer_proposition_clicked();
    /*!
   *  \brief  Slot bouton modifier thème
   *
   *  Modifie le thème séléctionné
   */
    void on_modifier_theme_clicked();
    /*!
   *  \brief  Slot bouton modifier question
   *
   *  Modifie la question séléctionnée
   */
    void on_modifier_question_clicked();
    /*!
   *  \brief  Slot bouton modifier proposition
   *
   *  Modifie la proposition séléctionnée
   */
    void on_modifier_proposition_clicked();
    /*!
   *  \brief  Slot bouton modifier partie
   *
   *  Modifie la partie séléctionnée
   */
    void on_modifier_partie_clicked();
    /*!
   *  \brief  Slot bouton insérer proposition
   *
   *  Insère la partie indiquée
   */
    void on_inserer_partie_clicked();
    /*!
   *  \brief  Slot bouton insérer joueur
   *
   *  Insère le joueur indiqué
   */
    void on_inserer_joueur_clicked();
    /*!
   *  \brief  Slot bouton modifier joueur
   *
   *  Modifie le joueur séléctionné
   */
    void on_modifier_joueur_clicked();
    /*!
   *  \brief  Slot cellule joueur cliquée
   *
   *  Récupère les infos de la ligne cliquée
   *
   *  \param[in] row Ligne de la cellule cliquée
   */
    void on_table_joueur_cellClicked(int row);
    /*!
   *  \brief  Slot cellule thème cliquée
   *
   *  Récupère les infos du thème cliqué
   *
   *  \param[in] row Ligne de la cellule cliquée
   */
    void on_table_theme_cellClicked(int row);
    /*!
   *  \brief  Slot cellule question cliquée
   *
   *  Récupère les infos de la question cliquée
   *
   *  \param[in] row Ligne de la cellule cliquée
   */
    void on_table_question_cellClicked(int row);
    /*!
   *  \brief  Slot cellule proposition cliquée
   *
   *  Récupère les infos de la proposition cliquée
   *
   *  \param[in] row Ligne de la cellule cliquée
   */
    void on_table_proposition_cellClicked(int row);
    /*!
   *  \brief  Slot cellule partie cliquée
   *
   *  Récupère les infos de la partie cliquée
   *
   *  \param[in] row Ligne de la cellule cliquée
   */
    void on_table_partie_cellClicked(int row);
    /*!
   *  \brief  Slot bouton rafraichir
   *
   *  Permet d'afficher les infos lorsqu'elles sont modifiées hors du programme
   */
    void on_toolButton_clicked();

private:
    Ui::SecondMainWindow *ui;
    QWidget *Pagelogin;
    Driver *driver_bdd;
    Connection *connect_bdd;
    Statement* stmt;
    string bdd;
    QVector < QVector<QLabel*> > tab_joueur;
    QVector < QVector<QLabel*> > tab_partie;
    QVector < QVector<QLabel*> > tab_theme;
    QVector < QVector<QLabel*> > tab_question;
    QVector < QVector<QLabel*> > tab_proposition;
};

#endif // SECONDMAINWINDOW_H
