#include "Dialog_Add_Activity.h"
#include "ui_Dialog_Add_Activity.h"
#include <iostream>
#include <CmpActivity.h>
#include <Dialog_Add_Activity.h>

int progressivo_activity=0;

Dialog_Add_Activity::Dialog_Add_Activity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Add_Activity)
{
    ui->setupUi(this);
}

Dialog_Add_Activity::~Dialog_Add_Activity()
{
    delete ui;
}

void Dialog_Add_Activity::on_pushButton_clicked()
{
    //inserisco nelle stringhe il testo presente nelle aree di input
    activity_name = ui->add_name->text().toStdString();
    activity_periodic = ui->add_periodic->text().toStdString();
    activity_type = ui->add_type->text().toStdString();
    activity_m = ui->add_m->text().toStdString();

    //controllo che i campi non siano vuoti
    if(activity_name.compare("") == 0 || activity_periodic.compare("") == 0 || activity_type.compare("") == 0 || activity_m.compare("") == 0)
           std::cout << "\nERROR! Incomplete data!\n" << std::endl;

    else {
            //Inserisco il nuovo componente nel vettore di componenti
            CmpActivity activity;
            activity.id=progressivo_activity;
            progressivo_activity++;
            activity.name = activity_name;
            activity.package = activity_periodic;
            activity.type = activity_type;
            activity.id_component = component_id;

            local_act->push_back(activity);
            //emetto il segnale per aggiornare l'albero
            emit update_activity();


        }

    //pulisco l'area di input
    ui->add_name->setText("");
    ui->add_periodic->setText("");
    ui->add_type->setText("");
    ui->add_m->setText("");
}
