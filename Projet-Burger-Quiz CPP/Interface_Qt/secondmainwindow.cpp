#include "secondmainwindow.h"
#include "ui_secondmainwindow.h"

SecondMainWindow::SecondMainWindow(QWidget *parent, Driver* driver, Connection *con) :
    QMainWindow(parent),
    ui(new Ui::SecondMainWindow)
{

    ui->setupUi(this);
    ui->table_joueur->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_partie->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_theme->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_question->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_proposition->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->line_theme->setPlaceholderText("Entrez un thème");
    ui->line_login->setPlaceholderText("Entrez un login");
    ui->line_password->setPlaceholderText("Entrez un password");
    ui->line_question->setPlaceholderText("Entrez une question");
    ui->line_choix1->setPlaceholderText("Entrez le choix 1");
    ui->line_choix2->setPlaceholderText("Entrez le choix 2");
    ui->line_proposition->setPlaceholderText("Entrez une proposition");

    Pagelogin=parent;
    driver_bdd=driver;
    connect_bdd=con;
    bdd=connect_bdd->getSchema();
    stmt=connect_bdd->createStatement();

    rempli_tab_joueur();
    rempli_table_joueur();
    rempli_tab_partie();
    rempli_table_partie();
    rempli_tab_theme();
    rempli_table_theme();
    rempli_tab_question();
    rempli_table_question();
    rempli_tab_proposition();
    rempli_table_proposition();

    if(tab_question.size()!=0){
        charge_question();
    }else{
        ui->comboBox_q1->clear();
        ui->comboBox_q2->clear();
        ui->comboBox_q3->clear();
        ui->comboBox_question->clear();
        ui->comboBox_reponse->clear();
    }
    if(tab_theme.size()!=0){
        charge_theme();
    }else{
        ui->comboBox_theme->clear();
    }
    if(tab_proposition.size()!=0){
        combobox_reponse_default();
    }else{
        ui->comboBox_reponse->clear();
    }
}

SecondMainWindow::~SecondMainWindow()
{
    delete ui;
}

void SecondMainWindow::on_button_deconnexion_clicked()
{
    hide();
    Pagelogin->show();
}

void SecondMainWindow::on_supprimer_joueur_clicked()
{
    QModelIndexList selectedRows = ui->table_joueur->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Suppression joueur","Veuillez séléctionner un joueur à supprimer");
    }else{
        int button_on = QMessageBox::warning(this, tr("Suppression"),tr("Voulez vous vraiment supprimer ce(s) joueur(s) ?\n"),QMessageBox::No|QMessageBox::Yes,QMessageBox::Yes);
        switch (button_on) {
          case QMessageBox::Yes:
            foreach( QModelIndex index, selectedRows )
            {
                int ligne_suppr=index.row();
                QString convert=tab_joueur[ligne_suppr][0]->text();
                QByteArray convert1 = convert.toUtf8();
                string id_suppr = convert1.data();
                stmt->execute("DELETE FROM Joue WHERE id_login="+id_suppr);
                stmt->execute("DELETE FROM Joueur WHERE id_login="+id_suppr);
            }

            rempli_tab_joueur();
            rempli_table_joueur();
            if(tab_question.size()!=0){
                charge_question();
            }else{
                ui->comboBox_q1->clear();
                ui->comboBox_q2->clear();
                ui->comboBox_q3->clear();
                ui->comboBox_question->clear();
                ui->comboBox_reponse->clear();
            }
            if(tab_theme.size()!=0){
                charge_theme();
            }else{
                ui->comboBox_theme->clear();
            }
            QMessageBox::information(this,"Suppression","Suppression réussie");
              break;
          case QMessageBox::No:
              break;
          default:
              break;
        }
    }
}

void SecondMainWindow::on_supprimer_partie_clicked()
{
    QModelIndexList selectedRows = ui->table_partie->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Suppression partie","Veuillez séléctionner une partie à supprimer");
    }else{
        int button_on = QMessageBox::warning(this, tr("Suppression"),tr("Voulez vous vraiment supprimer cette/ces partie(s) ?\n"),QMessageBox::No|QMessageBox::Yes,QMessageBox::Yes);
        switch (button_on) {
          case QMessageBox::Yes:
            foreach( QModelIndex index, selectedRows )
            {
                int ligne_suppr=index.row();
                QString convert=tab_partie[ligne_suppr][0]->text();
                QByteArray convert1 = convert.toUtf8();
                string id_suppr = convert1.data();
                stmt->execute("DELETE FROM Partie_Question WHERE id_partie="+id_suppr);
                stmt->execute("DELETE FROM Joue WHERE id_partie="+id_suppr);
                stmt->execute("DELETE FROM Partie WHERE id_partie="+id_suppr);
            }

            rempli_tab_partie();
            rempli_table_partie();
            if(tab_question.size()!=0){
                charge_question();
            }else{
                ui->comboBox_q1->clear();
                ui->comboBox_q2->clear();
                ui->comboBox_q3->clear();
                ui->comboBox_question->clear();
                ui->comboBox_reponse->clear();
            }
            if(tab_theme.size()!=0){
                charge_theme();
            }else{
                ui->comboBox_theme->clear();
            }
            QMessageBox::information(this,"Suppression","Suppression réussie");
              break;
          case QMessageBox::No:
              break;
          default:
              break;
        }
    }
}

void SecondMainWindow::on_supprimer_theme_clicked()
{
    QModelIndexList selectedRows = ui->table_theme->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Suppression thème","Veuillez séléctionner un thème à supprimer");
    }else{
        int button_on = QMessageBox::warning(this, tr("Suppression"),tr("Voulez vous vraiment supprimer ce(s) thème(s) ?\n"),QMessageBox::No|QMessageBox::Yes,QMessageBox::Yes);
        switch (button_on) {
          case QMessageBox::Yes:

            foreach( QModelIndex index, selectedRows )
            {
                int ligne_suppr=index.row();
                QString convert=tab_theme[ligne_suppr][0]->text();
                QByteArray convert1 = convert.toUtf8();
                string id_suppr = convert1.data();
                ResultSet* res_theme=NULL;
                ResultSet* res_suppr=NULL;

                res_theme=stmt->executeQuery("SELECT id_question FROM Question WHERE id_theme="+id_suppr);
                while(res_theme->next()){
                    string id_quest=res_theme->getString(1);

                    res_suppr=stmt->executeQuery("SELECT id_partie FROM Partie_Question WHERE id_question="+id_quest);
                    while(res_suppr->next()){
                        string recup=res_suppr->getString(1);
                        stmt->execute("DELETE FROM Joue WHERE id_partie="+recup);
                        stmt->execute("DELETE FROM Partie_Question WHERE id_partie="+recup);
                        stmt->execute("DELETE FROM Partie WHERE id_partie="+recup);
                    }
                    delete res_suppr;
                    stmt->execute("DELETE FROM Proposition WHERE id_question="+id_quest);
                    stmt->execute("DELETE FROM Question WHERE id_question="+id_quest);
                }
                stmt->execute("DELETE FROM Theme WHERE id_theme="+id_suppr);
                delete res_theme;
            }

            rempli_tab_partie();
            rempli_table_partie();
            rempli_tab_theme();
            rempli_table_theme();
            rempli_tab_question();
            rempli_table_question();
            rempli_tab_proposition();
            rempli_table_proposition();

            if(tab_question.size()!=0){
                charge_question();
            }else{
                ui->comboBox_q1->clear();
                ui->comboBox_q2->clear();
                ui->comboBox_q3->clear();
                ui->comboBox_question->clear();
                ui->comboBox_reponse->clear();
            }
            if(tab_theme.size()!=0){
                charge_theme();
            }else{
                ui->comboBox_theme->clear();
            }
            QMessageBox::information(this,"Suppression","Suppression réussie");
              break;
          case QMessageBox::No:
              break;
          default:
              break;
        }
    }
}

void SecondMainWindow::on_supprimer_question_clicked()
{
    QModelIndexList selectedRows = ui->table_question->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Suppression question","Veuillez séléctionner une question à supprimer");
    }else{
        int button_on = QMessageBox::warning(this, tr("Suppression"),tr("Voulez vous vraiment supprimer ce(s) question(s) ?\n"),QMessageBox::No|QMessageBox::Yes,QMessageBox::Yes);
        switch (button_on) {
          case QMessageBox::Yes:
            foreach( QModelIndex index, selectedRows )
            {
                int ligne_suppr=index.row();
                QString convert=tab_question[ligne_suppr][0]->text();
                QByteArray convert1 = convert.toUtf8();
                string id_suppr = convert1.data();
                ResultSet* res_suppr=NULL;

                res_suppr=stmt->executeQuery("SELECT id_partie FROM Partie_Question WHERE id_question="+id_suppr);
                while(res_suppr->next()){
                    string recup=res_suppr->getString(1);
                    stmt->execute("DELETE FROM Partie_Question WHERE id_partie="+recup);
                    stmt->execute("DELETE FROM Partie WHERE id_partie="+recup);
                }
                delete res_suppr;
                stmt->execute("DELETE FROM Proposition WHERE id_question="+id_suppr);
                stmt->execute("DELETE FROM Question WHERE id_question="+id_suppr);
            }

            rempli_tab_partie();
            rempli_table_partie();
            rempli_tab_question();
            rempli_table_question();
            rempli_tab_proposition();
            rempli_table_proposition();

            if(tab_question.size()!=0){
                charge_question();
            }else{
                ui->comboBox_q1->clear();
                ui->comboBox_q2->clear();
                ui->comboBox_q3->clear();
                ui->comboBox_question->clear();
                ui->comboBox_reponse->clear();
            }
            if(tab_theme.size()!=0){
                charge_theme();
            }else{
                ui->comboBox_theme->clear();
            }
            QMessageBox::information(this,"Suppression","Suppression réussie");
              break;
          case QMessageBox::No:
              break;
          default:
              break;
        }
    }
}

void SecondMainWindow::on_supprimer_proposition_clicked()
{
    QModelIndexList selectedRows = ui->table_proposition->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Suppression proposition","Veuillez séléctionner une proposition à supprimer");
    }else{
        int button_on = QMessageBox::warning(this, tr("Suppression"),tr("Voulez vous vraiment supprimer cette/ces proposition(s) ?\n"),QMessageBox::No|QMessageBox::Yes,QMessageBox::Yes);
        switch (button_on) {
          case QMessageBox::Yes:
            foreach( QModelIndex index, selectedRows )
            {
                int ligne_suppr=index.row();
                QString convert=tab_proposition[ligne_suppr][0]->text();
                QByteArray convert1 = convert.toUtf8();
                string id_suppr = convert1.data();
                stmt->execute("DELETE FROM Proposition WHERE id_proposition="+id_suppr);
            }

            rempli_tab_proposition();
            rempli_table_proposition();

            if(tab_question.size()!=0){
                charge_question();
            }else{
                ui->comboBox_q1->clear();
                ui->comboBox_q2->clear();
                ui->comboBox_q3->clear();
                ui->comboBox_question->clear();
                ui->comboBox_reponse->clear();
            }
            if(tab_theme.size()!=0){
                charge_theme();
            }else{
                ui->comboBox_theme->clear();
            }
            QMessageBox::information(this,"Suppression","Suppression réussie");
              break;
          case QMessageBox::No:
              break;
          default:
              break;
        }
    }
}

void SecondMainWindow::charge_question(){
    ResultSet* res_questions=NULL;
    ui->comboBox_q1->clear();
    ui->comboBox_q2->clear();
    ui->comboBox_q3->clear();
    ui->comboBox_question->clear();
    ui->comboBox_reponse->clear();
    res_questions=stmt->executeQuery("SELECT question FROM Question");
    while(res_questions->next()){
        ui->comboBox_q1->addItem((res_questions->getString(1)).c_str());
        ui->comboBox_q2->addItem((res_questions->getString(1)).c_str());
        ui->comboBox_q3->addItem((res_questions->getString(1)).c_str());
        ui->comboBox_question->addItem((res_questions->getString(1)).c_str());
    }
    delete res_questions;
    if(tab_proposition.size()!=0){
        combobox_reponse_default();
    }else{
        ui->comboBox_reponse->clear();
    }
}

void SecondMainWindow::charge_theme(){
    ResultSet* res_themes=NULL;
    ui->comboBox_theme->clear();
    res_themes=stmt->executeQuery("SELECT theme FROM Theme");
    while(res_themes->next()){
        ui->comboBox_theme->addItem((res_themes->getString(1)).c_str());
    }
    delete res_themes;
}

void SecondMainWindow::on_comboBox_question_activated(const QString &arg1)
{
    ResultSet* res_quest=NULL;
    QByteArray convert = arg1.toUtf8();
    string question = convert.data();
    PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("SELECT * FROM Question WHERE question=?");
    prepa_stmt->setString(1,question);
    res_quest=prepa_stmt->executeQuery();
    delete prepa_stmt;
    res_quest->next();
    ui->comboBox_reponse->clear();
    ui->comboBox_reponse->addItem((res_quest->getString("Choix_1")).c_str());
    ui->comboBox_reponse->addItem((res_quest->getString("Choix_2")).c_str());
    ui->comboBox_reponse->addItem("Les deux");
    delete res_quest;
}

void SecondMainWindow::rempli_table_joueur(){
    ResultSet* res_tabjoueur=NULL;
    res_tabjoueur=stmt->executeQuery("SELECT * FROM Joueur");
    int ligne_joueur=tab_joueur.size();
    int colonne_joueur=res_tabjoueur->getMetaData()->getColumnCount();
    ui->table_joueur->clear();
    ui->table_joueur->setRowCount(ligne_joueur);
    ui->table_joueur->setColumnCount(colonne_joueur);

        for(int i=0;i<colonne_joueur;i++){
            string rep=res_tabjoueur->getMetaData()->getColumnName(i+1);
            const char* p = rep.c_str();
            QTableWidgetItem* header=new QTableWidgetItem();
            header->setText(p);
            ui->table_joueur->setHorizontalHeaderItem(i,header);
        }

    for(int i=0;i<ligne_joueur;i++){
        for(int j=0;j<colonne_joueur;j++){
            ui->table_joueur->setCellWidget(i,j,tab_joueur[i][j]);
        }
    }
    delete res_tabjoueur;
}

void SecondMainWindow::rempli_table_partie(){
    ResultSet* res_tabpartie=NULL;
    ResultSet* res_partie_question=NULL;
    ResultSet* res_intitule_question=NULL;
    res_tabpartie=stmt->executeQuery("SELECT * FROM Partie");
    int ligne_partie=tab_partie.size();
    int colonne_partie=res_tabpartie->getMetaData()->getColumnCount()+3;
    ui->table_partie->clear();
    ui->table_partie->setRowCount(ligne_partie);
    ui->table_partie->setColumnCount(colonne_partie);

    for(int i=0;i<colonne_partie;i++){
        if(i<colonne_partie-3){
            string rep=res_tabpartie->getMetaData()->getColumnName(i+1);
            const char* p = rep.c_str();
            QTableWidgetItem* header=new QTableWidgetItem();
            header->setText(p);
            ui->table_partie->setHorizontalHeaderItem(i,header);
        }else{
            string num_question=to_string(i-1);
            string rep="Question "+num_question;
            const char* p = rep.c_str();
            QTableWidgetItem* header=new QTableWidgetItem();
            header->setText(p);
            ui->table_partie->setHorizontalHeaderItem(i,header);
        }
    }

    for(int i=0;i<ligne_partie;i++){
        QByteArray convert = tab_partie[i][0]->text().toUtf8();
        string id_partie = convert.data();
        res_partie_question=stmt->executeQuery("SELECT id_question FROM Partie_Question WHERE id_partie="+id_partie);

        for(int j=0;j<colonne_partie;j++){
            if(j<colonne_partie-3){
                ui->table_partie->setCellWidget(i,j,tab_partie[i][j]);
            }else{
                res_partie_question->next();
                string id_question=res_partie_question->getString(1);
                res_intitule_question=stmt->executeQuery("SELECT question FROM Question WHERE id_question="+id_question);

                res_intitule_question->next();
                string question=res_intitule_question->getString(1);
                const char* p = question.c_str();
                ui->table_partie->setCellWidget(i,j,new QLabel(p));
            }
        }
        delete res_partie_question;
        delete res_intitule_question;
    }
    delete res_tabpartie;
}

void SecondMainWindow::rempli_table_theme(){
    ResultSet* res_tabtheme=NULL;
    res_tabtheme=stmt->executeQuery("SELECT * FROM Theme");
    int ligne_theme=tab_theme.size();
    int colonne_theme=res_tabtheme->getMetaData()->getColumnCount();
    ui->table_theme->clear();
    ui->table_theme->setRowCount(ligne_theme);
    ui->table_theme->setColumnCount(colonne_theme);

    for(int i=0;i<colonne_theme;i++){
        string rep=res_tabtheme->getMetaData()->getColumnName(i+1);
        const char* p = rep.c_str();
        QTableWidgetItem* header=new QTableWidgetItem();
        header->setText(p);
        ui->table_theme->setHorizontalHeaderItem(i,header);
    }

    for(int i=0;i<ligne_theme;i++){
        for(int j=0;j<colonne_theme;j++){
            ui->table_theme->setCellWidget(i,j,tab_theme[i][j]);
        }
    }
    delete res_tabtheme;
}

void SecondMainWindow::rempli_table_question(){
    ResultSet* res_tabquestion=NULL;
    res_tabquestion=stmt->executeQuery("SELECT * FROM Question");
    int ligne_question=tab_question.size();
    int colonne_question=res_tabquestion->getMetaData()->getColumnCount();
    ui->table_question->clear();
    ui->table_question->setRowCount(ligne_question);
    ui->table_question->setColumnCount(colonne_question);

    for(int i=0;i<colonne_question;i++){
        string rep=res_tabquestion->getMetaData()->getColumnName(i+1);
        const char* p = rep.c_str();
        QTableWidgetItem* header=new QTableWidgetItem();
        header->setText(p);
        ui->table_question->setHorizontalHeaderItem(i,header);
    }

    for(int i=0;i<ligne_question;i++){
        for(int j=0;j<colonne_question;j++){
            ui->table_question->setCellWidget(i,j,tab_question[i][j]);
        }
    }
    delete res_tabquestion;
}

void SecondMainWindow::rempli_table_proposition(){
    ResultSet* res_tabproposition=NULL;
    res_tabproposition=stmt->executeQuery("SELECT * FROM Proposition");
    int ligne_proposition=tab_proposition.size();
    int colonne_proposition=res_tabproposition->getMetaData()->getColumnCount();
    ui->table_proposition->clear();
    //ui->table_proposition->viewport()->repaint();
    ui->table_proposition->setRowCount(ligne_proposition);
    ui->table_proposition->setColumnCount(colonne_proposition);

    for(int i=0;i<colonne_proposition;i++){
        string rep=res_tabproposition->getMetaData()->getColumnName(i+1);
        const char* p = rep.c_str();
        QTableWidgetItem* header=new QTableWidgetItem();
        header->setText(p);
        ui->table_proposition->setHorizontalHeaderItem(i,header);
    }

    for(int i=0;i<ligne_proposition;i++){
        for(int j=0;j<colonne_proposition;j++){
            ui->table_proposition->setCellWidget(i,j,tab_proposition[i][j]);
        }
    }
    ui->table_proposition->viewport()->repaint();
    QCoreApplication::processEvents();
    delete res_tabproposition;
}

void SecondMainWindow::rempli_tab_joueur(){
    ResultSet* res_tabjoueur=NULL;
    res_tabjoueur=stmt->executeQuery("SELECT * FROM Joueur");
    int colonne_joueur=res_tabjoueur->getMetaData()->getColumnCount();

    for(int i=0;i<tab_joueur.size();i++){
        for(int j=0;j<tab_joueur[i].size();j++){
            delete tab_joueur[i][j];
        }
        tab_joueur[i].clear();
    }
    tab_joueur.clear();

    for(int j=0;res_tabjoueur->next();j++){
        QVector<QLabel*> line;
        for(int i=0;i<colonne_joueur;i++){
            string rep=res_tabjoueur->getString(i+1);
            const char* p = rep.c_str();
            line.push_back(new QLabel(p));
        }
        tab_joueur.push_back(line);
    }
    delete res_tabjoueur;
}

void SecondMainWindow::rempli_tab_partie(){
    ResultSet* res_tabpartie=NULL;
    res_tabpartie=stmt->executeQuery("SELECT * FROM Partie");
    int colonne_partie=res_tabpartie->getMetaData()->getColumnCount();

    for(int i=0;i<tab_partie.size();i++){
        for(int j=0;j<tab_partie[i].size();j++){
            delete tab_partie[i][j];
        }
        tab_partie[i].clear();
    }
    tab_partie.clear();

    for(int j=0;res_tabpartie->next();j++){
        QVector<QLabel*> line;
        for(int i=0;i<colonne_partie;i++){
            string rep=res_tabpartie->getString(i+1);
            const char* p = rep.c_str();
            line.push_back(new QLabel(p));
        }
        tab_partie.push_back(line);
    }
    delete res_tabpartie;
}

void SecondMainWindow::rempli_tab_theme(){
    ResultSet* res_tabtheme=NULL;
    res_tabtheme=stmt->executeQuery("SELECT * FROM Theme");
    int colonne_theme=res_tabtheme->getMetaData()->getColumnCount();

    for(int i=0;i<tab_theme.size();i++){
        for(int j=0;j<tab_theme[i].size();j++){
            delete tab_theme[i][j];
        }
        tab_theme[i].clear();
    }
    tab_theme.clear();

    for(int j=0;res_tabtheme->next();j++){
        QVector<QLabel*> line;
        for(int i=0;i<colonne_theme;i++){
            string rep=res_tabtheme->getString(i+1);
            const char* p = rep.c_str();
            line.push_back(new QLabel(p));
        }
        tab_theme.push_back(line);
    }
    delete res_tabtheme;
}

void SecondMainWindow::rempli_tab_question(){
    ResultSet* res_tabquestion=NULL;
    res_tabquestion=stmt->executeQuery("SELECT * FROM Question");
    int colonne_question=res_tabquestion->getMetaData()->getColumnCount();

    for(int i=0;i<tab_question.size();i++){
        for(int j=0;j<tab_question[i].size();j++){
            delete tab_question[i][j];
        }
        tab_question[i].clear();
    }
    tab_question.clear();

    for(int j=0;res_tabquestion->next();j++){
        QVector<QLabel*> line;
        for(int i=0;i<colonne_question;i++){
            string rep=res_tabquestion->getString(i+1);
            const char* p = rep.c_str();
            line.push_back(new QLabel(p));
        }
        tab_question.push_back(line);
    }
    delete res_tabquestion;
}

void SecondMainWindow::rempli_tab_proposition(){
    ResultSet* res_tabproposition=NULL;
    ResultSet* res_proposition_rep=NULL;
    ResultSet* res_choix=NULL;

    res_tabproposition=stmt->executeQuery("SELECT * FROM Proposition");
    int colonne_proposition=res_tabproposition->getMetaData()->getColumnCount();

    for(int i=0;i<tab_proposition.size();i++){
        for(int j=0;j<tab_proposition[i].size();j++){
            delete tab_proposition[i][j];
        }
        tab_proposition[i].clear();
    }
    tab_proposition.clear();

    for(int j=0;res_tabproposition->next();j++){
        QVector<QLabel*> line;
        for(int i=0;i<colonne_proposition;i++){
            if(i==2){
                QString convert1=line[0]->text();
                QByteArray convert = convert1.toUtf8();
                string id_proposition = convert.data();

                res_proposition_rep=stmt->executeQuery("SELECT reponse,id_question FROM Proposition WHERE id_proposition="+id_proposition);
                res_proposition_rep->next();
                string rep=res_proposition_rep->getString(1);

                res_choix=stmt->executeQuery("SELECT choix_1,choix_2 FROM Question WHERE id_question="+res_proposition_rep->getString(2));
                res_choix->next();

                if(rep=="1"){
                    string rep1=res_choix->getString(1);
                    const char* p1 = rep1.c_str();
                    line.push_back(new QLabel(p1));
                }else if(rep=="2"){
                    string rep2=res_choix->getString(2);
                    const char* p2 = rep2.c_str();
                    line.push_back(new QLabel(p2));
                }else{
                    string rep3="Les deux";
                    const char* p3 = rep3.c_str();
                    line.push_back(new QLabel(p3));
                }
                delete res_proposition_rep;
                delete res_choix;
            }else{
                string rep=res_tabproposition->getString(i+1);
                const char* p = rep.c_str();
                line.push_back(new QLabel(p));
            }
        }
        tab_proposition.push_back(line);
    }
    delete res_tabproposition;
}

void SecondMainWindow::on_inserer_theme_clicked()
{
    ResultSet* res_theme=NULL;
    ResultSet* theme_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Theme' AND column_name = 'theme'");
    theme_length_max->next();
    string rep=theme_length_max->getString(1);
    delete theme_length_max;

    int exist=0;
    unsigned int theme_min=2;
    unsigned int theme_max=stoi(rep);


    QString edit_theme=ui->line_theme->text();
    QByteArray convert = edit_theme.toUtf8();
    string theme = convert.data();
    res_theme=stmt->executeQuery("SELECT theme FROM Theme");

    while(res_theme->next()){
        if(theme==res_theme->getString(1)){
            exist=1;
        }
    }
    delete res_theme;

    if(theme.size()>theme_max){
        QMessageBox::warning(this,"Insertion thème","Champ thème trop long");
    }else if(theme.size()<theme_min){
        QMessageBox::warning(this,"Insertion thème","Champ thème trop court");
    }else if(!exist){
        PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("INSERT INTO Theme(theme) VALUES(?)");
        prepa_stmt->setString(1,theme);
        prepa_stmt->execute();
        delete prepa_stmt;
    }else{
        QMessageBox::warning(this,"Insertion thème","Ce thème existe déjà");
    }

    rempli_tab_theme();
    rempli_table_theme();
    if(tab_question.size()!=0){
        charge_question();
    }else{
        ui->comboBox_q1->clear();
        ui->comboBox_q2->clear();
        ui->comboBox_q3->clear();
        ui->comboBox_question->clear();
        ui->comboBox_reponse->clear();
    }
    if(tab_theme.size()!=0){
        charge_theme();
    }else{
        ui->comboBox_theme->clear();
    }
}



void SecondMainWindow::on_inserer_question_clicked()
{
    ResultSet* res_question=NULL;
    ResultSet* res_theme=NULL;
    ResultSet* question_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Question' AND column_name = 'question'");
    question_length_max->next();
    string rep=question_length_max->getString(1);
    delete question_length_max;

    ResultSet* choix_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Question' AND column_name = 'choix_1'");
    choix_length_max->next();
    string rep2=choix_length_max->getString(1);
    delete choix_length_max;

    int exist=0;
    unsigned int question_min=8;
    unsigned int question_max=stoi(rep);
    unsigned int choix_min=2;
    unsigned int choix_max=stoi(rep2);

    QString edit_question=ui->line_question->text();
    QByteArray convert = edit_question.toUtf8();
    string question = convert.data();

    QString edit_choix1=ui->line_choix1->text();
    QByteArray convert2 = edit_choix1.toUtf8();
    string choix1 = convert2.data();

    QString edit_choix2=ui->line_choix2->text();
    QByteArray convert3 = edit_choix2.toUtf8();
    string choix2 = convert3.data();

    QString combo_theme=ui->comboBox_theme->currentText();
    QByteArray convert4 = combo_theme.toUtf8();
    string theme = convert4.data();

    PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("SELECT id_theme FROM Theme WHERE theme=?");
    prepa_stmt->setString(1,theme);
    res_theme=prepa_stmt->executeQuery();
    delete prepa_stmt;
    res_question=stmt->executeQuery("SELECT question FROM Question");

    res_theme->next();
    string id_theme=res_theme->getString(1);
    while(res_question->next()){
        if(question==res_question->getString(1)){
            exist=1;
        }
    }
    delete res_question;

    if(question.size()<question_min){
        QMessageBox::warning(this,"Insertion question","Champ question trop court");
    }else if(question.size()>question_max){
        QMessageBox::warning(this,"Insertion question","Champ question trop long");
    }else if(choix1.size()<choix_min){
        QMessageBox::warning(this,"Insertion question","Champ choix1 trop court");
    }else if(choix1.size()>choix_max){
        QMessageBox::warning(this,"Insertion question","Champ choix1 trop long");
    }else if(choix2.size()<choix_min){
        QMessageBox::warning(this,"Insertion question","Champ choix2 trop court");
    }else if(choix2.size()>choix_max){
        QMessageBox::warning(this,"Insertion question","Champ choix2 trop long");
    }else if(!exist){
        PreparedStatement* prepa_stmt2=connect_bdd->prepareStatement("INSERT INTO Question(question,choix_1,choix_2,id_theme) VALUES(?,?,?,?)");
        prepa_stmt2->setString(1,question);
        prepa_stmt2->setString(2,choix1);
        prepa_stmt2->setString(3,choix2);
        prepa_stmt2->setString(4,id_theme);
        prepa_stmt2->execute();
        delete prepa_stmt2;
    }else{
        QMessageBox::warning(this,"Insertion question","Cette question existe déjà");
    }
    delete res_theme;

    rempli_tab_question();
    rempli_table_question();
    if(tab_question.size()!=0){
        charge_question();
    }else{
        ui->comboBox_q1->clear();
        ui->comboBox_q2->clear();
        ui->comboBox_q3->clear();
        ui->comboBox_question->clear();
        ui->comboBox_reponse->clear();
    }
    if(tab_theme.size()!=0){
        charge_theme();
    }else{
        ui->comboBox_theme->clear();
    }
}

void SecondMainWindow::on_inserer_proposition_clicked()
{
    ResultSet* res_proposition=NULL;
    ResultSet* res_question=NULL;
    ResultSet* proposition_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Proposition' AND column_name = 'proposition'");
    proposition_length_max->next();
    string rep=proposition_length_max->getString(1);
    delete proposition_length_max;

    int exist=0;
    unsigned int proposition_min=2;
    unsigned int proposition_max=stoi(rep);

    QString combo_question=ui->comboBox_question->currentText();
    QByteArray convert = combo_question.toUtf8();
    string question = convert.data();

    QString edit_proposition=ui->line_proposition->text();
    QByteArray convert1 = edit_proposition.toUtf8();
    string proposition= convert1.data();

    int reponse=ui->comboBox_reponse->currentIndex()+1;
    string id_reponse=to_string(reponse);

    res_proposition=stmt->executeQuery("SELECT proposition FROM Proposition");
    PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("SELECT id_question FROM Question WHERE question=?");
    prepa_stmt->setString(1,question);
    res_question=prepa_stmt->executeQuery();
    delete prepa_stmt;

    res_question->next();
    string id_question=res_question->getString(1);
    while(res_proposition->next()){
        if(proposition==res_proposition->getString(1)){
            exist=1;
        }
    }

    delete res_proposition;

    if(proposition.size()<proposition_min){
        QMessageBox::warning(this,"Insertion proposition","Champ proposition trop court");
    }else if(proposition.size()>proposition_max){
        QMessageBox::warning(this,"Insertion proposition","Champ proposition trop long");
    }else if(!exist){
        PreparedStatement* prepa_stmt2=connect_bdd->prepareStatement("INSERT INTO Proposition(proposition,reponse,id_question) VALUES(?,?,?)");
        prepa_stmt2->setString(1,proposition);
        prepa_stmt2->setString(2,id_reponse);
        prepa_stmt2->setString(3,id_question);
        prepa_stmt2->execute();
        delete prepa_stmt2;
    }else{
        QMessageBox::warning(this,"Insertion proposition","Cette proposition existe déjà");
    }
    delete res_question;

    rempli_tab_proposition();
    rempli_table_proposition();
    if(tab_question.size()!=0){
        charge_question();
    }else{
        ui->comboBox_q1->clear();
        ui->comboBox_q2->clear();
        ui->comboBox_q3->clear();
        ui->comboBox_question->clear();
        ui->comboBox_reponse->clear();
    }
    if(tab_theme.size()!=0){
        charge_theme();
    }else{
        ui->comboBox_theme->clear();
    }
}

void SecondMainWindow::combobox_reponse_default(){
    ResultSet* res_quest=NULL;
    res_quest=stmt->executeQuery("SELECT * FROM Question");
    res_quest->next();
    ui->comboBox_reponse->clear();
    ui->comboBox_reponse->addItem((res_quest->getString(3)).c_str());
    ui->comboBox_reponse->addItem((res_quest->getString(4)).c_str());
    ui->comboBox_reponse->addItem("Les deux");
    delete res_quest;
}

void SecondMainWindow::on_modifier_theme_clicked()
{
    QModelIndexList selectedRows = ui->table_theme->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Modification thème","Veuillez séléctionner un thème à modifier");
    }else if(nb_rows>1){
        QMessageBox::warning(this,"Modification thème","Veuillez séléctionner qu'un seul thème à modifier");
    }else{
        foreach( QModelIndex index, selectedRows )
        {
        int ligne_modif=index.row();
        QString convert1=tab_theme[ligne_modif][0]->text();
        QByteArray convert = convert1.toUtf8();
        string id_modif = convert.data();

        ResultSet* res_theme=NULL;
        ResultSet* theme_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Theme' AND column_name = 'theme'");
        theme_length_max->next();
        string rep=theme_length_max->getString(1);
        delete theme_length_max;

        int exist=0;
        unsigned int theme_min=2;
        unsigned int theme_max=stoi(rep);

        QString edit_theme=ui->line_theme->text();
        QByteArray convert2 = edit_theme.toUtf8();
        string theme = convert2.data();
        res_theme=stmt->executeQuery("SELECT theme FROM Theme");

        while(res_theme->next()){
            if(theme==res_theme->getString(1)){
                exist=1;
            }
        }
        delete res_theme;
        if(theme.size()>theme_max){
            QMessageBox::warning(this,"Modification thème","Champ thème trop long");
        }else if(theme.size()<theme_min){
            QMessageBox::warning(this,"Modification thème","Champ thème trop court");
        }else if(!exist){
            PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("UPDATE Theme SET theme=? WHERE id_theme=?");
            prepa_stmt->setString(1,theme);
            prepa_stmt->setString(2,id_modif);
            prepa_stmt->execute();
            delete prepa_stmt;
        }else{
            QMessageBox::warning(this,"Modification thème","Ce thème existe déjà");
        }

        rempli_tab_theme();
        rempli_table_theme();
        if(tab_question.size()!=0){
            charge_question();
        }else{
            ui->comboBox_q1->clear();
            ui->comboBox_q2->clear();
            ui->comboBox_q3->clear();
            ui->comboBox_question->clear();
            ui->comboBox_reponse->clear();
        }
        if(tab_theme.size()!=0){
            charge_theme();
        }else{
            ui->comboBox_theme->clear();
        }
        }
    }
}

void SecondMainWindow::on_modifier_question_clicked()
{
    QModelIndexList selectedRows = ui->table_question->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Modification question","Veuillez séléctionner une question à modifier");
    }else if(nb_rows>1){
        QMessageBox::warning(this,"Modification question","Veuillez séléctionner qu'une seule question à modifier");
    }else{

        foreach( QModelIndex index, selectedRows )
        {
            int ligne_modif=index.row();
            QString convert1=tab_question[ligne_modif][0]->text();
            QByteArray convert = convert1.toUtf8();
            string id_modif = convert.data();

            ResultSet* res_question=NULL;
            ResultSet* res_theme=NULL;
            ResultSet* question_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Question' AND column_name = 'question'");
            question_length_max->next();
            string rep=question_length_max->getString(1);
            delete question_length_max;

            ResultSet* choix_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Question' AND column_name = 'choix_1'");
            choix_length_max->next();
            string rep2=choix_length_max->getString(1);
            delete choix_length_max;

            int exist=0;
            unsigned int question_min=8;
            unsigned int question_max=stoi(rep);
            unsigned int choix_min=2;
            unsigned int choix_max=stoi(rep2);

            QString edit_question=ui->line_question->text();
            QByteArray convert2 = edit_question.toUtf8();
            string question = convert2.data();

            QString edit_choix1=ui->line_choix1->text();
            QByteArray convert3 = edit_choix1.toUtf8();
            string choix1 = convert3.data();

            QString edit_choix2=ui->line_choix2->text();
            QByteArray convert4 = edit_choix2.toUtf8();
            string choix2 = convert4.data();

            QString combo_theme=ui->comboBox_theme->currentText();
            QByteArray convert5 = combo_theme.toUtf8();
            string theme = convert5.data();

            PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("SELECT id_theme FROM Theme WHERE theme=?");
            prepa_stmt->setString(1,theme);
            res_theme=prepa_stmt->executeQuery();
            delete prepa_stmt;
            res_question=stmt->executeQuery("SELECT question FROM Question");

            res_theme->next();
            string id_theme=res_theme->getString(1);
            while(res_question->next()){
                if(question==res_question->getString(1)){
                    exist=1;
                }
            }
            delete res_question;

            if(question.size()<question_min){
                QMessageBox::warning(this,"Modification question","Champ question trop court");
            }else if(question.size()>question_max){
                QMessageBox::warning(this,"Modification question","Champ question trop long");
            }else if(choix1.size()<choix_min){
                QMessageBox::warning(this,"Modification question","Champ choix1 trop court");
            }else if(choix1.size()>choix_max){
                QMessageBox::warning(this,"Modification question","Champ choix1 trop long");
            }else if(choix2.size()<choix_min){
                QMessageBox::warning(this,"Modification question","Champ choix2 trop court");
            }else if(choix2.size()>choix_max){
                QMessageBox::warning(this,"Modification question","Champ choix2 trop long");
            }else if(!exist){
                PreparedStatement* prepa_stmt2=connect_bdd->prepareStatement("UPDATE Question SET question=?,choix_1=?,choix_2=?,id_theme=? WHERE id_question=?");
                prepa_stmt2->setString(1,question);
                prepa_stmt2->setString(2,choix1);
                prepa_stmt2->setString(3,choix2);
                prepa_stmt2->setString(4,id_theme);
                prepa_stmt2->setString(5,id_modif);
                prepa_stmt2->execute();
                delete prepa_stmt2;
            }else{
                QMessageBox::warning(this,"Insertion question","Cette question existe déjà");
            }
            delete res_theme;

            rempli_tab_question();
            rempli_table_question();
            if(tab_question.size()!=0){
                charge_question();
            }else{
                ui->comboBox_q1->clear();
                ui->comboBox_q2->clear();
                ui->comboBox_q3->clear();
                ui->comboBox_question->clear();
                ui->comboBox_reponse->clear();
            }
            if(tab_theme.size()!=0){
                charge_theme();
            }else{
                ui->comboBox_theme->clear();
            }
        }
    }
}

void SecondMainWindow::on_modifier_proposition_clicked()
{
    QModelIndexList selectedRows = ui->table_proposition->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Modification proposition","Veuillez séléctionner une proposition à modifier");
    }else if(nb_rows>1){
        QMessageBox::warning(this,"Modification proposition","Veuillez séléctionner qu'une seule proposition à modifier");
    }else{

        foreach( QModelIndex index, selectedRows )
        {
            int ligne_modif=index.row();
            QString convert1=tab_proposition[ligne_modif][0]->text();
            QByteArray convert = convert1.toUtf8();
            string id_modif = convert.data();

            ResultSet* res_proposition=NULL;
            ResultSet* res_question=NULL;
            ResultSet* proposition_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Proposition' AND column_name = 'proposition'");
            proposition_length_max->next();
            string rep=proposition_length_max->getString(1);
            delete proposition_length_max;

            int exist=0;
            unsigned int proposition_min=2;
            unsigned int proposition_max=stoi(rep);

            QString combo_question=ui->comboBox_question->currentText();
            QByteArray convert2 = combo_question.toUtf8();
            string question = convert2.data();

            QString edit_proposition=ui->line_proposition->text();
            QByteArray convert3 = edit_proposition.toUtf8();
            string proposition= convert3.data();

            int reponse=ui->comboBox_reponse->currentIndex()+1;
            string id_reponse=to_string(reponse);

            res_proposition=stmt->executeQuery("SELECT proposition FROM Proposition");
            PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("SELECT id_question FROM Question WHERE question=?");
            prepa_stmt->setString(1,question);
            res_question=prepa_stmt->executeQuery();
            delete prepa_stmt;

            res_question->next();
            string id_question=res_question->getString(1);
            while(res_proposition->next()){
                if(proposition==res_proposition->getString(1)){
                    exist=1;
                }
            }
            delete res_proposition;

            if(proposition.size()<proposition_min){
                QMessageBox::warning(this,"Insertion proposition","Champ proposition trop court");
            }else if(proposition.size()>proposition_max){
                QMessageBox::warning(this,"Insertion proposition","Champ proposition trop long");
            }else if(!exist){
                PreparedStatement* prepa_stmt2=connect_bdd->prepareStatement("UPDATE Proposition SET proposition=?,reponse=?,id_question=? WHERE id_proposition=?");
                prepa_stmt2->setString(1,proposition);
                prepa_stmt2->setString(2,id_reponse);
                prepa_stmt2->setString(3,id_question);
                prepa_stmt2->setString(4,id_modif);
                prepa_stmt2->execute();
                delete prepa_stmt2;
            }else{
                QMessageBox::warning(this,"Insertion proposition","Cette proposition existe déjà");
            }
            delete res_question;

            rempli_tab_proposition();
            rempli_table_proposition();
            if(tab_question.size()!=0){
                charge_question();
            }else{
                ui->comboBox_q1->clear();
                ui->comboBox_q2->clear();
                ui->comboBox_q3->clear();
                ui->comboBox_question->clear();
                ui->comboBox_reponse->clear();
            }
            if(tab_theme.size()!=0){
                charge_theme();
            }else{
                ui->comboBox_theme->clear();
            }

        }
    }
}

void SecondMainWindow::on_modifier_partie_clicked()
{
    QModelIndexList selectedRows = ui->table_partie->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Modification partie","Veuillez séléctionner une partie à modifier");
    }else if(nb_rows>1){
        QMessageBox::warning(this,"Modification partie","Veuillez séléctionner qu'une seule partie à modifier");
    }else{
        foreach( QModelIndex index, selectedRows )
        {
            int ligne_modif=index.row();
            QString convert=tab_partie[ligne_modif][0]->text();
            QByteArray convertl = convert.toUtf8();
            string id_modif = convertl.data();
            string score=to_string(ui->line_score->value());

            if(ui->checkBox_score2->checkState()==2){
                if(ui->checkBox_score->checkState()==2){
                    PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("UPDATE Partie SET score=NULL WHERE id_partie=?");
                    prepa_stmt->setString(1,id_modif);
                    prepa_stmt->execute();
                    delete prepa_stmt;
                }else{
                    PreparedStatement* prepa_stmt2=connect_bdd->prepareStatement("UPDATE Partie SET score=? WHERE id_partie=?");
                    prepa_stmt2->setString(1,score);
                    prepa_stmt2->setString(2,id_modif);
                    prepa_stmt2->execute();
                    delete prepa_stmt2;
                }

                rempli_tab_partie();
                rempli_table_partie();
                if(tab_question.size()!=0){
                    charge_question();
                }else{
                    ui->comboBox_q1->clear();
                    ui->comboBox_q2->clear();
                    ui->comboBox_q3->clear();
                    ui->comboBox_question->clear();
                    ui->comboBox_reponse->clear();
                }
                if(tab_theme.size()!=0){
                    charge_theme();
                }else{
                    ui->comboBox_theme->clear();
                }

            }else{

                ResultSet* res_parties=NULL;
                ResultSet* res_quest1=NULL;
                ResultSet* res_quest2=NULL;
                ResultSet* res_quest3=NULL;

                bool verification=false;
                string quest1;
                string quest2;
                string quest3;

                QString edit_q1=ui->comboBox_q1->currentText();
                QByteArray convert1 = edit_q1.toUtf8();
                string question1 = convert1.data();
                PreparedStatement* prepa_stmt3=connect_bdd->prepareStatement("SELECT id_question FROM Question WHERE question=?");
                prepa_stmt3->setString(1,question1);
                res_quest1=prepa_stmt3->executeQuery();
                delete prepa_stmt3;
                res_quest1->next();
                quest1=res_quest1->getString(1);
                delete res_quest1;

                QString edit_q2=ui->comboBox_q2->currentText();
                QByteArray convert2 = edit_q2.toUtf8();
                string question2 = convert2.data();
                PreparedStatement* prepa_stmt4=connect_bdd->prepareStatement("SELECT id_question FROM Question WHERE question=?");
                prepa_stmt4->setString(1,question2);
                res_quest2=prepa_stmt4->executeQuery();
                delete prepa_stmt4;
                res_quest2->next();
                quest2=res_quest2->getString(1);
                delete res_quest2;

                QString edit_q3=ui->comboBox_q3->currentText();
                QByteArray convert3 = edit_q3.toUtf8();
                string question3 = convert3.data();
                PreparedStatement* prepa_stmt5=connect_bdd->prepareStatement("SELECT id_question FROM Question WHERE question=?");
                prepa_stmt5->setString(1,question3);
                res_quest3=prepa_stmt5->executeQuery();
                delete prepa_stmt5;
                res_quest3->next();
                quest3=res_quest3->getString(1);
                delete res_quest3;

                if(quest1!=quest2 && quest2!=quest3 && quest3!=quest1){

                    res_parties=stmt->executeQuery("SELECT id_partie FROM Partie");

                    while(res_parties->next()){
                        verification=verif(res_parties->getString(1),quest1,quest2,quest3);
                        if(verification){
                            break;
                        }
                    }

                    delete res_parties;

                    if(!verification){
                        if(ui->checkBox_score->checkState()==2){
                            PreparedStatement* prepa_stmt6=connect_bdd->prepareStatement("UPDATE Partie SET score=NULL WHERE id_partie=?");
                            prepa_stmt6->setString(1,id_modif);
                            prepa_stmt6->execute();
                            delete prepa_stmt6;
                        }else{
                            PreparedStatement* prepa_stmt7=connect_bdd->prepareStatement("UPDATE Partie SET score=? WHERE id_partie=?");
                            prepa_stmt7->setString(1,score);
                            prepa_stmt7->setString(2,id_modif);
                            prepa_stmt7->execute();
                            delete prepa_stmt7;
                        }
                        PreparedStatement* prepa_stmt8=connect_bdd->prepareStatement("DELETE FROM Partie_Question WHERE id_partie=?");
                        prepa_stmt8->setString(1,id_modif);
                        prepa_stmt8->execute();
                        delete prepa_stmt8;
                        PreparedStatement* prepa_stmt9=connect_bdd->prepareStatement("INSERT INTO Partie_Question(id_question,id_partie) VALUES(?,?)");
                        prepa_stmt9->setString(1,quest1);
                        prepa_stmt9->setString(2,id_modif);
                        prepa_stmt9->execute();
                        prepa_stmt9->setString(1,quest2);
                        prepa_stmt9->setString(2,id_modif);
                        prepa_stmt9->execute();
                        prepa_stmt9->setString(1,quest3);
                        prepa_stmt9->setString(2,id_modif);
                        prepa_stmt9->execute();
                        delete prepa_stmt9;

                        rempli_tab_partie();
                        rempli_table_partie();
                        if(tab_question.size()!=0){
                            charge_question();
                        }else{
                            ui->comboBox_q1->clear();
                            ui->comboBox_q2->clear();
                            ui->comboBox_q3->clear();
                            ui->comboBox_question->clear();
                            ui->comboBox_reponse->clear();
                        }
                        if(tab_theme.size()!=0){
                            charge_theme();
                        }else{
                            ui->comboBox_theme->clear();
                        }
                    }else{
                        QMessageBox::warning(this,"Insertion partie","Cette partie existe déjà");
                    }
                }else{
                    QMessageBox::warning(this,"Insertion partie","Veuillez séléctionner 3 questions différentes");
                }
            }
        }
    }
}

void SecondMainWindow::on_inserer_partie_clicked()
{
    ResultSet* res_parties=NULL;
    ResultSet* res_quest1=NULL;
    ResultSet* res_quest2=NULL;
    ResultSet* res_quest3=NULL;

    bool verification;
    string quest1;
    string quest2;
    string quest3;

    QString edit_q1=ui->comboBox_q1->currentText();
    QByteArray convert1 = edit_q1.toUtf8();
    string question1 = convert1.data();
    PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("SELECT id_question FROM Question WHERE question=?");
    prepa_stmt->setString(1,question1);
    res_quest1=prepa_stmt->executeQuery();
    res_quest1->next();
    quest1=res_quest1->getString(1);
    delete res_quest1;

    QString edit_q2=ui->comboBox_q2->currentText();
    QByteArray convert2 = edit_q2.toUtf8();
    string question2 = convert2.data();
    prepa_stmt->setString(1,question2);
    res_quest2=prepa_stmt->executeQuery();
    res_quest2->next();
    quest2=res_quest2->getString(1);
    delete res_quest2;

    QString edit_q3=ui->comboBox_q3->currentText();
    QByteArray convert3 = edit_q3.toUtf8();
    string question3 = convert3.data();
    prepa_stmt->setString(1,question3);
    res_quest3=prepa_stmt->executeQuery();
    delete prepa_stmt;
    res_quest3->next();
    quest3=res_quest3->getString(1);
    delete res_quest3;

    if(quest1!=quest2 && quest2!=quest3 && quest3!=quest1){
        string score=to_string(ui->line_score->value());

        res_parties=stmt->executeQuery("SELECT id_partie FROM Partie");

        while(res_parties->next()){
            verification=verif(res_parties->getString(1),quest1,quest2,quest3);
            if(verification){
                break;
            }
        }

        delete res_parties;

        if(!verification){
            if(ui->checkBox_score->checkState()==2){
                stmt->execute("INSERT INTO Partie(score) VALUES(NULL)");
            }else{
                stmt->execute("INSERT INTO Partie(score) VALUES("+score+")");
            }
            ResultSet* res_id=stmt->executeQuery("SELECT LAST_INSERT_ID() as id");
            res_id->next();
            PreparedStatement* prepa_stmt2=connect_bdd->prepareStatement("INSERT INTO Partie_Question(id_question,id_partie) VALUES(?,?)");
            prepa_stmt2->setString(1,quest1);
            prepa_stmt2->setString(2,res_id->getString(1));
            prepa_stmt2->executeQuery();
            prepa_stmt2->setString(1,quest2);
            prepa_stmt2->setString(2,res_id->getString(1));
            prepa_stmt2->executeQuery();
            prepa_stmt2->setString(1,quest3);
            prepa_stmt2->setString(2,res_id->getString(1));
            prepa_stmt2->executeQuery();
            delete prepa_stmt2;

            rempli_tab_partie();
            rempli_table_partie();
            if(tab_question.size()!=0){
                charge_question();
            }else{
                ui->comboBox_q1->clear();
                ui->comboBox_q2->clear();
                ui->comboBox_q3->clear();
                ui->comboBox_question->clear();
                ui->comboBox_reponse->clear();
            }
            if(tab_theme.size()!=0){
                charge_theme();
            }else{
                ui->comboBox_theme->clear();
            }
        }else{
            QMessageBox::warning(this,"Insertion partie","Cette partie existe déjà");
        }
    }else{
        QMessageBox::warning(this,"Insertion partie","Veuillez séléctionner 3 questions différentes");
    }
}

bool SecondMainWindow::verif(string id, string q1, string q2, string q3){

    ResultSet* test1=NULL;
    ResultSet* test2=NULL;
    ResultSet* test3=NULL;
    bool verif1=false;
    bool verif2=false;
    bool verif3=false;
    bool verif=false;
    cout<<"Id partie: "<<id<<"\t";
    cout<<"q1: "<<q1<<"\t";
    cout<<"q2: "<<q2<<"\t";
    cout<<"q3: "<<q3<<"\t";
    test1=stmt->executeQuery("SELECT * FROM Partie_Question WHERE id_partie="+id+" AND id_question="+q1);
    while(test1->next()){
        verif1=true;
    }
    test2=stmt->executeQuery("SELECT * FROM Partie_Question WHERE id_partie="+id+" AND id_question="+q2);
    while(test2->next()){
        verif2=true;
    }
    test3=stmt->executeQuery("SELECT * FROM Partie_Question WHERE id_partie="+id+" AND id_question="+q3);
    while(test3->next()){
        verif3=true;
    }

    if(verif1 && verif2 && verif3){
        verif=true;
    }
    return verif;
}

void SecondMainWindow::on_inserer_joueur_clicked()
{
    ResultSet* res_joueur=NULL;
    ResultSet* joueur_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Joueur' AND column_name = 'login'");
    joueur_length_max->next();
    string rep=joueur_length_max->getString(1);
    delete joueur_length_max;
    ResultSet* mdp_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Joueur' AND column_name = 'password'");
    mdp_length_max->next();
    string rep2=mdp_length_max->getString(1);
    delete mdp_length_max;

    int exist=0;
    unsigned int joueur_min=2;
    unsigned int joueur_max=stoi(rep);
    unsigned int mdp_min=6;
    unsigned int mdp_max=stoi(rep2);

    QString edit_joueur=ui->line_login->text();
    QByteArray convert1= edit_joueur.toUtf8();
    string joueur = convert1.data();

    QString edit_mdp=ui->line_password->text();
    QByteArray convert2= edit_mdp.toUtf8();
    string mdp = convert2.data();
    QByteArray crypt= QCryptographicHash::hash(convert2, QCryptographicHash::Sha1);
    QString out=crypt.toHex();
    QByteArray convert3= out.toUtf8();
    string crypt_mdp= convert3.data();

    string best_score=to_string(ui->line_bestscore->value());

    res_joueur=stmt->executeQuery("SELECT login FROM Joueur");

    while(res_joueur->next()){
        if(joueur==res_joueur->getString(1)){
            exist=1;
        }
    }
    delete res_joueur;

    if(joueur.size()<joueur_min){
        QMessageBox::warning(this,"Insertion joueur","Login trop court");
    }else if(joueur.size()>joueur_max){
        QMessageBox::warning(this,"Insertion joueur","Login trop long");
    }else if(mdp.size()<mdp_min){
        QMessageBox::warning(this,"Insertion joueur","Mot de passe trop court");
    }else if(mdp.size()>mdp_max){
        QMessageBox::warning(this,"Insertion joueur","Mot de passe trop long");
    }else if(!exist){
        if(ui->checkBox_bestscore->checkState()==2){
            PreparedStatement* prepa_stmt=connect_bdd->prepareStatement("INSERT INTO Joueur(login,password) VALUES(?,?)");
            prepa_stmt->setString(1,joueur);
            prepa_stmt->setString(2,crypt_mdp);
            prepa_stmt->execute();
            delete prepa_stmt;
        }else{
            PreparedStatement* prepa_stmt2=connect_bdd->prepareStatement("INSERT INTO Joueur(login,password,best_score) VALUES(?,?,?)");
            prepa_stmt2->setString(1,joueur);
            prepa_stmt2->setString(2,crypt_mdp);
            prepa_stmt2->setString(3,best_score);
            prepa_stmt2->execute();
            delete prepa_stmt2;
        }

        rempli_tab_joueur();
        rempli_table_joueur();

    }else{
        QMessageBox::warning(this,"Insertion joueur","Ce login existe déjà");
    }

}

void SecondMainWindow::on_modifier_joueur_clicked()
{
    QModelIndexList selectedRows = ui->table_joueur->selectionModel()->selectedRows();
    int nb_rows=selectedRows.size();

    if(nb_rows==0){
        QMessageBox::warning(this,"Modification joueur","Veuillez séléctionner un joueur à modifier");
    }else if(nb_rows>1){
        QMessageBox::warning(this,"Modification joueur","Veuillez séléctionner qu'un seul joueur à modifier");
    }else{

        foreach( QModelIndex index, selectedRows )
        {
            int ligne_modif=index.row();
            QString convert=tab_joueur[ligne_modif][0]->text();
            QByteArray convertl = convert.toUtf8();
            string id_modif = convertl.data();
            string best_score=to_string(ui->line_bestscore->value());

            ResultSet* res_joueur=NULL;
            ResultSet* joueur_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Joueur' AND column_name = 'login'");
            joueur_length_max->next();
            string rep=joueur_length_max->getString(1);
            delete joueur_length_max;
            ResultSet* mdp_length_max=stmt->executeQuery("SELECT CHARACTER_MAXIMUM_LENGTH AS length FROM information_schema.COLUMNS WHERE table_schema = '"+bdd+"' AND table_name = 'Joueur' AND column_name = 'password'");
            mdp_length_max->next();
            string rep2=mdp_length_max->getString(1);
            delete mdp_length_max;

            int exist=0;
            unsigned int joueur_min=2;
            unsigned int joueur_max=stoi(rep);
            unsigned int mdp_min=6;
            unsigned int mdp_max=stoi(rep2);

            QString edit_joueur=ui->line_login->text();
            QByteArray convert1= edit_joueur.toUtf8();
            string joueur = convert1.data();

            QString edit_mdp=ui->line_password->text();
            QByteArray convert2= edit_mdp.toUtf8();
            string mdp = convert2.data();
            QByteArray crypt= QCryptographicHash::hash(convert2, QCryptographicHash::Sha1);
            QString out=crypt.toHex();
            QByteArray convert3= out.toUtf8();
            string crypt_mdp= convert3.data();

            res_joueur=stmt->executeQuery("SELECT login FROM Joueur");

            for(int i=0;i<res_joueur->next();i++){
                if(joueur==res_joueur->getString(1)){
                    if(i!=ligne_modif){
                        exist=1;
                    }
                }
            }

            delete res_joueur;

            if(joueur.size()<joueur_min){
                QMessageBox::warning(this,"Insertion joueur","Login trop court");
            }else if(joueur.size()>joueur_max){
                QMessageBox::warning(this,"Insertion joueur","Login trop long");
            }else if(mdp.size()<mdp_min && ui->checkBox_password->checkState()==0 && ui->checkBox_score_only->checkState()==0){
                QMessageBox::warning(this,"Insertion joueur","Mot de passe trop court");
            }else if(mdp.size()>mdp_max && ui->checkBox_password->checkState()==0 && ui->checkBox_score_only->checkState()==0){
                QMessageBox::warning(this,"Insertion joueur","Mot de passe trop long");
            }else if(!exist){
                if(ui->checkBox_score_only->checkState()==2){
                    if(ui->checkBox_bestscore->checkState()==2){
                        stmt->execute("UPDATE Joueur SET best_score=NULL WHERE id_login="+id_modif);
                    }else{
                        stmt->execute("UPDATE Joueur SET best_score="+best_score+" WHERE id_login="+id_modif);
                    }
                }else{
                    if(ui->checkBox_password->checkState()==2){
                        if(ui->checkBox_bestscore->checkState()==2){
                            PreparedStatement* prepa_stmt1=connect_bdd->prepareStatement("UPDATE Joueur SET login=?, best_score=NULL WHERE id_login=?");
                            prepa_stmt1->setString(1,joueur);
                            prepa_stmt1->setString(2,id_modif);
                            prepa_stmt1->execute();
                            delete prepa_stmt1;
                        }else{
                            PreparedStatement* prepa_stmt2=connect_bdd->prepareStatement("UPDATE Joueur SET login=?, best_score=? WHERE id_login=?");
                            prepa_stmt2->setString(1,joueur);
                            prepa_stmt2->setString(2,best_score);
                            prepa_stmt2->setString(3,id_modif);
                            prepa_stmt2->executeQuery();
                            prepa_stmt2->execute();
                            delete prepa_stmt2;
                        }
                    }else{
                        if(ui->checkBox_bestscore->checkState()==2){
                            PreparedStatement* prepa_stmt3=connect_bdd->prepareStatement("UPDATE Joueur SET login=?, password=?, best_score=NULL WHERE id_login=?");
                            prepa_stmt3->setString(1,joueur);
                            prepa_stmt3->setString(2,crypt_mdp);
                            prepa_stmt3->setString(3,id_modif);
                            prepa_stmt3->execute();
                            delete prepa_stmt3;
                        }else{
                            PreparedStatement* prepa_stmt4=connect_bdd->prepareStatement("UPDATE Joueur SET login=?,password=?, best_score=? WHERE id_login=?");
                            prepa_stmt4->setString(1,joueur);
                            prepa_stmt4->setString(2,crypt_mdp);
                            prepa_stmt4->setString(3,best_score);
                            prepa_stmt4->setString(4,id_modif);
                            prepa_stmt4->execute();
                            delete prepa_stmt4;
                        }
                    }
                }

                rempli_tab_joueur();
                rempli_table_joueur();

            }else{
                QMessageBox::warning(this,"Insertion joueur","Ce login existe déjà");
            }
        }
    }
}

void SecondMainWindow::on_table_joueur_cellClicked(int row)
{
    ui->line_login->setText(tab_joueur[row][1]->text());
    if(tab_joueur[row][3]->text()!=NULL){
        ui->checkBox_bestscore->setCheckState(Qt::Unchecked);
        QString convert=tab_joueur[row][3]->text();
        QByteArray convert1=convert.toUtf8();
        string best_score = convert1.data();
        ui->line_bestscore->setValue(stoi(best_score));
    }else{
        ui->line_bestscore->setValue(0);
        ui->checkBox_bestscore->setCheckState(Qt::Checked);
    }
}

void SecondMainWindow::on_table_theme_cellClicked(int row)
{
    ui->line_theme->setText(tab_theme[row][1]->text());
}

void SecondMainWindow::on_table_question_cellClicked(int row)
{
    ui->line_question->setText(tab_question[row][1]->text());
    ui->line_choix1->setText(tab_question[row][2]->text());
    ui->line_choix2->setText(tab_question[row][3]->text());
}

void SecondMainWindow::on_table_proposition_cellClicked(int row)
{
    ui->line_proposition->setText(tab_proposition[row][1]->text());
}

void SecondMainWindow::on_table_partie_cellClicked(int row)
{
    if(tab_partie[row][1]->text()!=NULL){
        ui->checkBox_score->setCheckState(Qt::Unchecked);
        QString convert=tab_partie[row][1]->text();
        QByteArray convert1=convert.toUtf8();
        string score = convert1.data();
        ui->line_score->setValue(stoi(score));
    }else{
        ui->line_score->setValue(0);
        ui->checkBox_score->setCheckState(Qt::Checked);
    }
}

void SecondMainWindow::on_toolButton_clicked()
{
    rempli_tab_joueur();
    rempli_table_joueur();
    rempli_tab_partie();
    rempli_table_partie();
    rempli_tab_theme();
    rempli_table_theme();
    rempli_tab_question();
    rempli_table_question();
    rempli_tab_proposition();
    rempli_table_proposition();

    if(tab_question.size()!=0){
        charge_question();
    }else{
        ui->comboBox_q1->clear();
        ui->comboBox_q2->clear();
        ui->comboBox_q3->clear();
        ui->comboBox_question->clear();
        ui->comboBox_reponse->clear();
    }
    if(tab_theme.size()!=0){
        charge_theme();
    }else{
        ui->comboBox_theme->clear();
    }
    if(tab_proposition.size()!=0){
        combobox_reponse_default();
    }else{
        ui->comboBox_reponse->clear();
    }
}
