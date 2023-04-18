#ifndef CUJEUDUPENDU_H
#define CUJEUDUPENDU_H
#include <qstring.h>

class CUjeuDuPendu
{
private:
    QString nomJoueur;
    QString nomFichierDeMots;
    int nombredeMot;
    QString motChoisi;
    QString motEnCours;
    int nombreErreur;
    class IHMPendu* addIHMPendu;


public:
    CUjeuDuPendu();
    ~CUjeuDuPendu();
    void recupAddIHM(class IHMPendu*);
    QString getnomFichierDeMots();
    void nbrdemot();
    void setnomFichierDeMots(QString);
    int getnombreErreur();
    void setnombreErreur(int);
    QString getmotEnCours();
    QString getmotChoisi();
    int tirageAleatoire(int mini, int maxi);
    void miseAJourFichierDeMots();
    void commencerUnePartie();
    int getnbrmot();
    void setnbrmot(int nbr);
    void setMotChoisi(QString);

};

#endif // CUJEUDUPENDU_H
