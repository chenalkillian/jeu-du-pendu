#include "addfenetre.h"

addfenetre::addfenetre(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addfenetre)
{
    ui->setupUi(this);
    addfenetre();
}
