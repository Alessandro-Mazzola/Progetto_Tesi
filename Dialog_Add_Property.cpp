#include "Dialog_Add_Property.h"
#include "ui_Dialog_Add_Property.h"
#include <CmpProperty.h>
#include <iostream>

Dialog_Add_Property::Dialog_Add_Property(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Add_Property)
{
    ui->setupUi(this);
}

Dialog_Add_Property::~Dialog_Add_Property()
{
    delete ui;
}

void Dialog_Add_Property::on_pushButton_clicked()
{
    //inserisco nelle stringhe il testo presente nelle aree di input
    property_name = ui->add_name->text().toStdString();
    property_type = ui->add_type->text().toStdString();
    property_domain = ui->add_domain->text().toStdString();

    //controllo che i campi non siano vuoti
    if(property_name.compare("") == 0 || property_type.compare("") == 0 || property_domain.compare("") == 0)
           std::cout << "\nERROR! Incomplete data!\n" << std::endl;

    else {
            // creo un nuovo elemento Cmpproperty
            CmpProperty property;
            property.name = property_name;
            property.type = property_type;
            property.domain = property_domain;

        }

    //pulisco l'area di input
    ui->add_domain->setText("");
    ui->add_name->setText("");
    ui->add_type->setText("");
}
