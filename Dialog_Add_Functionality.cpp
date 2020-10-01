#include "Dialog_Add_Functionality.h"
#include "ui_Dialog_Add_Functionality.h"

#include <iostream>
#include <CmpFunctionality.h>

Dialog_Add_Functionality::Dialog_Add_Functionality(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Add_Functionality)
{
    ui->setupUi(this);
}

Dialog_Add_Functionality::~Dialog_Add_Functionality()
{
    delete ui;
}

void Dialog_Add_Functionality::on_pushButton_clicked()
{
    //inserisco nelle stringhe il testo presente nelle aree di input
    functionality_name = ui->add_name->text().toStdString();
    functionality_plugin_interfaces = ui->add_plugi_int->text().toStdString();

    //controllo che i campi non siano vuoti
    if(functionality_name.compare("") == 0 || functionality_plugin_interfaces.compare("") == 0)
            std::cout << "\nERROR! Incomplete data!\n" << std::endl;

    else {
            // creo un nuovo elemento CmpFunctionality
            CmpFunctionality functionality;
            functionality.name = functionality_name;
            //functionality.id_plugin_int = functionality_plugin_interfaces;  il campo non esiste nella libreria


        }

    //pulisco l'area di input
    ui->add_name->setText("");
    ui->add_plugi_int->setText("");


}
