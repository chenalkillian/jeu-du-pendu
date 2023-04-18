#include "ihmpendu.h"
#include "ui_ihmpendu.h"
#include <qmessagebox.h>
#include "cujeudupendu.h"
#include <QPushButton>
#include <QLineEdit>
#include <qlayout.h>
#include <QSignalMapper>
#include <QtGui>
#include <qfiledialog.h>
using namespace std;
IHMPendu::IHMPendu(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::IHMPendu)
{
ui->setupUi(this);
initIHM();
}



IHMPendu::~IHMPendu()
{
delete ui;
}




//procedure qui inialise les widgets de la fenêtre
void IHMPendu::initIHM()
{
ui->on_JOUER->setEnabled(true);
ui->on_CONFIG->setEnabled(true);
ui->nomdujoueur->setEnabled(true);
ui->nbrerreur->setText("");
ui->image->setText("");
pendu=1;
}

//procedure qui reccupere l'adresse de la classe cujeudupendu pour pouvoir l'utiliser dans ihm
void IHMPendu::RecupAddJeu( CUjeuDuPendu *jeu)
{
addJeuDuPendu = jeu;
}

//procedure qui renvoie le nom rentrer
QString IHMPendu::saisirNom()
{
QString nom,x;QMessageBox msgBox;

nom=ui->nomdujoueur->text();

return nom;
}


//procedure qui afiche l'image selectionner
void IHMPendu::afficherPendu(int nbr)
{
QString nomImage;

ui->image->setPixmap(QPixmap( "ImagePendu"+QString::number(nbr)+".png"));
ui->image->adjustSize();

}

//procedure qui créer 26 boutons dans une case, contenant chaque lettre de l'alphabet
void IHMPendu::slotBouton()
{
int a=97;

QSignalMapper *signalMapper = new QSignalMapper(this);
for (int i=0;i<26;i++)
{
Bouton[i]=new QPushButton (QString(a++));
Bouton[i]->setMinimumWidth(5);
Bouton[i]->setMinimumHeight(5);

ui->gridLayout->addWidget(Bouton[i],i/10,i%10);
signalMapper->setMapping(Bouton[i],i);
QObject::connect(Bouton[i], SIGNAL(clicked()), this, SLOT(boutonclic0()));}
//https://www.siloged.fr/cours/QTCreator/Evenements.html
//https://www.siloged.fr/cours/QTCreator/Damierabasedeboutons.html site qui peut aider

}
//procedure qui affiche les "_" qui corresponde au mot a trouver
void IHMPendu::afficher(QString contenu)
{
ui->motatrouver->setText(contenu);
}

//procedure qui affiche le nom du fichier
void IHMPendu::afficherNomFichierMots(QString a)
{
ui->nomdufichier->setText(a);
}

//procedure qui permet de voir si une lettre correspond ou pas au mot a trouver, il permet de detecter si on perd ou on gagne

void IHMPendu::boutonclic0()
{
QPushButton *button = (QPushButton *)sender();
QString letterclick = button->text();
QString lettremot;
QString nom;
nom=saisirNom();
QString a; a=addJeuDuPendu->getmotEnCours();
int boll=0;
for(int i=0;i<addJeuDuPendu->getmotEnCours().size();i++)
{

lettremot=a[i];

if(lettremot==letterclick)
{
boll=1;
button->setEnabled(false);

QString motc =addJeuDuPendu->getmotChoisi();
motc[i] = lettremot[0]; //remplacer la ieme lettre du mot par la lettre cliquee

addJeuDuPendu->setMotChoisi(motc);
ui->motatrouver->setText(motc);
QString motfini = addJeuDuPendu->getmotChoisi();
if(ui->nbrerreur->text()!="10" && motfini.contains('_',Qt::CaseSensitivity())==false)
{
QMessageBox msgBox; QString x;
msgBox.setIcon(QMessageBox::Information);
x=nom+" VOUS AVEZ gagner  !";
msgBox.setText(x);
msgBox.exec();
ihmrefin();            }
}
else
{
button->setEnabled(false);


}
}
if(boll==0)
{
afficherPendu(pendu);


ui->nbrerreur->setText(QString::number( pendu));pendu++;
button->setStyleSheet("QPushButton { background-color:  red; }\n"
"QPushButton:enabled { background-color: rgb(200,0,0); }\n");

if(ui->nbrerreur->text()=="10")
{

QMessageBox msgBox; QString x;
msgBox.setIcon(QMessageBox::Information);
x=nom+" VOUS AVEZ PERDU , le mot était: "+a;
msgBox.setText(x);
msgBox.exec();
ihmrefin();



}


}
else {
if(boll==1)
{
button->setStyleSheet("QPushButton { background-color: green; }\n"
"QPushButton:enabled { background-color: rgb(200,0,0); }\n");
//mettre le fond verts du bouton ici
}
}

}

//procedure qui affiche le nombre de mot
void IHMPendu::afficherNombreDeMots(int a)
{

ui->nombremot->setText(QString::number(a));
}

//procedure qui active ou desactive la saisie de nom, selon le boleen reçu
void IHMPendu::NomOnOff(bool a)
{
if(a==1)
{
ui->nomdujoueur->setEnabled(true);
}
else if(a==0)
{
ui->nomdujoueur->setEnabled(false);
}
}



//procedure qui active ou desactive le bouton jouer, selon le boleen reçu
void IHMPendu::boutonJOUEROnOff(bool okonoff){
if(okonoff==0){
ui->on_JOUER->setEnabled(false);
}else if(okonoff==1){
ui->on_JOUER->setEnabled(true);
}
}

//procedure qui lance la partie si toutes les condition precisées sont bonnes lorqsue l'on appuie sur le bouton jouer
void IHMPendu::on_on_JOUER_clicked()
{
if(saisirNom()!="" & nomDUFichierselectionner!="")
{
ui->on_JOUER->setText("REJOUER");
addJeuDuPendu->commencerUnePartie();
}
else{
QMessageBox msgBox; QString x;
msgBox.setIcon(QMessageBox::Information);
x="Verifier si le nom du joueur et verifier si vous avez selectionner votre fichier  ";
msgBox.setText(x);
msgBox.exec();
}
}

//procedure du bouton config, créer une nouvelle fenêtre avec des widget intégrer et permet de selectionner la liste de mot
void IHMPendu::on_on_CONFIG_clicked()
{

QWidget* fenetreConfig = new QWidget(); // Création de la fenêtre
fenetreConfig->setFixedWidth(600);    // On fixe la largeur de la nouvelle fenetre
fenetreConfig->setFixedHeight(400);    // idem pour la hauteur
fenetreConfig->setWindowTitle("Configuration");  // Titre de la fenêtre
QPushButton *closebutton = new QPushButton("Selectionner fichier",fenetreConfig);
closebutton->setGeometry(100,100,100,100);//positionH, positionV, tailleH, tailleV
QObject::connect(closebutton, SIGNAL(clicked()), this, SLOT(boutonclic1()));
QPushButton *quitter=new QPushButton("quitter",fenetreConfig);
quitter->setGeometry(250,100,100,100);//positionH, positionV, tailleH, tailleV
QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(boutonclic2()));


fenetreConfig->show();

recuppAddfenetreconfig(fenetreConfig);
}

//procedure du bouton selectionner qui permet de choisir que les fichiers .txt grace à un filtrage
void IHMPendu::boutonclic1()
{
QFileDialog dialog(this);
dialog.setFileMode(QFileDialog::ExistingFile);
dialog.setNameFilter(tr("Text files (*.txt);"));

QString fileNames;

fileNames = dialog.getOpenFileName();
nomDUFichierselectionner=fileNames;
}

//procedure du boutton quitter qui prend en paramètre l'adresse de la fenêtre qu'on lui envoie pour ensuite la fermer
void IHMPendu::boutonclic2()
{
adresseconfigpouferme->close();
}

//procedure qui remet le jeu à zero pour pouvoir rejouer une partie
void IHMPendu::ihmrefin()
{
afficherPendu(0);
ui->motatrouver->setText("");
for (int a=0;a<26;a++){Bouton[a]->setEnabled(false);}
boutonJOUEROnOff(1);
ui->nomdujoueur->setText("");   NomOnOff(1);
addJeuDuPendu->setMotChoisi("");
ui->nbrerreur->setText("");
pendu=1;
}

//procedure qui reçois l'addresse de la fenetre config et la return
void IHMPendu::recuppAddfenetreconfig(QWidget * fenetre)
{
adresseconfigpouferme=fenetre;
}

//procedure du bouton quitter de la fenêtre du jeu pour pouvoir la fermer
void IHMPendu::on_pushButton_clicked()
{
this->close();
}

