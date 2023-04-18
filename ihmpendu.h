#ifndef IHMPENDU_H
#define IHMPENDU_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
QT_BEGIN_NAMESPACE

namespace Ui { class IHMPendu; }
QT_END_NAMESPACE

class IHMPendu : public QMainWindow
{
    Q_OBJECT
private:
    Ui::IHMPendu* ui;
     class CUjeuDuPendu* addJeuDuPendu;
    QPushButton* Bouton[26];
    QWidget* addFenetre;
    QLineEdit* addLineEdit;
    int pendu;
public slots:

    void boutonclic0();
  void  boutonclic1();
  void boutonclic2();
public:
    IHMPendu(QWidget *parent = nullptr);
    ~IHMPendu();
    QWidget* adresseconfigpouferme;
    void initIHM();
    void RecupAddJeu( CUjeuDuPendu* );
     void recuppAddfenetreconfig(QWidget*);
    void RecupAddLineEdit(QLineEdit*);
    void LabelMotATrouverVisible(bool);
    void boutonJOUEROnOff(bool);
    void boutonCONFIGOnOff(bool);
    void NomOnOff(bool);
    void afficher(QString);
    void afficherPendu(int);
    void afficherNomFichierMots(QString);
    void afficherNombreDeMots(int);
    QString saisirNom();
    void slotBouton();
    void slotBoutonActualiser();
    void slotBoutonParcourir();
    void slotBoutonAnnuler();
    void nombreimage();
    void ihmrefin();
    QString nomDUFichierselectionner;
private slots:
    void on_on_JOUER_clicked();

    void on_on_CONFIG_clicked();



    void on_pushButton_clicked();
};
#endif // IHMPENDU_H
