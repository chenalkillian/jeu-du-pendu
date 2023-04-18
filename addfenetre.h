#ifndef ADDFENETRE_H
#define ADDFENETRE_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <qglobal.h>


QT_BEGIN_NAMESPACE

namespace Ui { class addfenetre; }
QT_END_NAMESPACE

class addfenetre : public QMainWindow
{
    Q_OBJECT
private:
    Ui::addfenetre* ui;


    void boutonclic0();
public:
    addfenetreQWidget *parent = nullptr);

private slots:
    void on_on_JOUER_clicked();

    void on_on_CONFIG_clicked();



};

#endif // ADDFENETRE_H

