#include "Dialog_Add_PluginInt.h"
#include "ui_Dialog_Add_PluginInt.h"

#include <CmpPlugin.h>
#include <iostream>

Dialog_Add_PluginInt::Dialog_Add_PluginInt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Add_PluginInt)
{
    ui->setupUi(this);
}

Dialog_Add_PluginInt::~Dialog_Add_PluginInt()
{
    delete ui;
}

void Dialog_Add_PluginInt::on_pushButton_clicked()
{
    //inserisco nelle stringhe il testo presente nelle aree di input
    plugin_package = ui->add_package->text().toStdString();
    plugin_type = ui->add_type->text().toStdString();

    //controllo che i campi non siano vuoti
    if(plugin_package.compare("") == 0 || plugin_type.compare("") == 0)
           std::cout << "\nERROR! Incomplete data!\n" << std::endl;

    else {
        // creo un nuovo elemento CmpPluginInt
            CmpPluginInt plugin;
            plugin.package = plugin_package;
            plugin.type = plugin_type;

        }

    //pulisco l'area di input
    ui->add_type->setText("");
    ui->add_package->setText("");
}
