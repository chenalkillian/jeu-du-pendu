#include "cujeudupendu.h"
#include "ihmpendu.h"
#include <qfile.h>
#include <qmessagebox.h>
#include <fstream>
#include <algorithm>
#include <QTextStream>

//procedure qui permet de récupérer l'adresse de la classe ihm
void CUjeuDuPendu::recupAddIHM(class IHMPendu *jeu2)
{
    addIHMPendu= jeu2;
}
//destructeur
CUjeuDuPendu:: ~CUjeuDuPendu()
{

}
//commande qui permet de donner l'adre de ihm a addihppendu
CUjeuDuPendu::CUjeuDuPendu()
{
    recupAddIHM(addIHMPendu);
}

//Ici on crée une procedure qui va calculer le nombre de mot du fichier sélectionner.
void CUjeuDuPendu::nbrdemot()
{
    QFile leFichier(nomFichierDeMots);
    leFichier.open(QIODevice::ReadOnly);
int nb=0;
while(leFichier.readLine()!="")
{
    nb++;
}

setnbrmot(nb);
}


//procedure qui met à jour le nombre de mot total.
void CUjeuDuPendu::setnbrmot(int nbr)
{
    nombredeMot=nbr;
}



//fonction qui renvoi le nombre de mot.
int CUjeuDuPendu::getnbrmot()
{
    return nombredeMot;
}

//fonction
void CUjeuDuPendu::commencerUnePartie()
{

    QString nomjoueur=addIHMPendu->saisirNom();
    addIHMPendu->boutonJOUEROnOff(0);
    addIHMPendu->NomOnOff(0);
    addIHMPendu->slotBouton();
   QFile leFichier(addIHMPendu->nomDUFichierselectionner);
   setnomFichierDeMots(addIHMPendu->nomDUFichierselectionner);
           leFichier.open(QIODevice::ReadOnly);
   nbrdemot();
    int b=tirageAleatoire(1,nombredeMot);
    for (int i=0;i<b;i++){
    motEnCours = leFichier.readLine(nombredeMot );}

    QString nomfichier;
    nomfichier=getnomFichierDeMots();
    addIHMPendu->afficherNomFichierMots(nomfichier);
    addIHMPendu->afficherNombreDeMots(nombredeMot);

for(int i=0;i<(motEnCours.size()-2);i++) // -2 car 2 caractere en trop
{
    motChoisi = motChoisi + "_";
}
 addIHMPendu->afficher(motChoisi);
}



// fonction qui tire un chiffre aléatoire et qui le renvoie afin de savoir quel mot sera choisi dans la liste.
int CUjeuDuPendu::tirageAleatoire(int mini, int maxi)
{
    //nombre aléatoire pour savoir quel mot sera prit
       srand(time(NULL));
       int nbr= rand()%(maxi-mini)+mini;
       return nbr;
}

//procedure qui renvoie le nom du fichier utilisé
QString CUjeuDuPendu::getnomFichierDeMots(){
    return nomFichierDeMots;
}

// procedure qui change le nom du fichier actuelle.
void CUjeuDuPendu::setnomFichierDeMots(QString nom)
{
    nomFichierDeMots=nom;
}

//fonction qui renvoie le nombre d'erreur faites.
int CUjeuDuPendu::getnombreErreur()
{
    return nombreErreur;
}

//procedure qui permet d'envoyer le nombre d'erreur
void CUjeuDuPendu::setnombreErreur(int nb)
{
    nombreErreur=nb;
}

// procedure qui donne le mot selectionner
QString CUjeuDuPendu::getmotEnCours()
{
    return motEnCours;
}
//procedure qui return le motchoisi
QString CUjeuDuPendu::getmotChoisi()
{
    return motChoisi;
}

//procedure qui met a jour le motchoisi
void CUjeuDuPendu::setMotChoisi(QString a)
{
    motChoisi = a;
}
