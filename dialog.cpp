#include "dialog.h"
#include "ui_dialog.h"
#include <string>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    std::string var1 = "prova stringa";
    var1 += " seconda frase";
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
