#include "Dialog_Add_Component.h"
#include <ui_Dialog_Add_Component.h>
#include <iostream>
#include <Component.h>
#include <mainwindow.h>

int progressivo_component=0;

Dialog_Add_Component::Dialog_Add_Component(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Add_Component)
{
    ui->setupUi(this);
}
Dialog_Add_Component::~Dialog_Add_Component()
{
    delete ui;
}

void Dialog_Add_Component::on_pushButton_clicked()
{
    //inserisco nelle stringhe il testo presente nelle aree di input
    component_name = ui->add_name->text().toStdString();
    component_package = ui->add_package->text().toStdString();
    component_type = ui->add_type->text().toStdString();

    //controllo che i campi non siano vuoti
    if(component_name.compare("") == 0 || component_package.compare("") == 0 || component_type.compare("") == 0)
           std::cout << "\nERROR! Incomplete data!\n" << std::endl;


    else {
        //Inserisco la nuova activity nel vettore di activity
        Component component;
        component.id=progressivo_component;
        progressivo_component++;
        component.category = component_name;
        component.package = component_package;
        component.type = component_type;

        local_comp->push_back(component);
        //emetto il segnale per aggiornare l'albero
        emit update_component();



    }

    //pulisco l'area di input
    ui->add_name->setText("");
    ui->add_package->setText("");
    ui->add_type->setText("");


}



