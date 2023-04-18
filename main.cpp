#include "ihmpendu.h"
#include "cujeudupendu.h"
#include "ihmpendu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

IHMPendu ihm;
CUjeuDuPendu jeu;

ihm.RecupAddJeu(&jeu);
jeu.recupAddIHM(&ihm);
    ihm.show();
    return a.exec();
}
