#include "Dialog_Add_Port.h"
#include "ui_Dialog_Add_Port.h"

#include <CmpPort.h>
#include <iostream>

int progressivo_port=0;

Dialog_Add_Port::Dialog_Add_Port(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Add_Port)
{
    ui->setupUi(this);
}

Dialog_Add_Port::~Dialog_Add_Port()
{
    delete ui;
}

void Dialog_Add_Port::on_pushButton_clicked()
{
    //inserisco nelle stringhe il testo presente nelle aree di input
    port_name = ui->add_name->text().toStdString();
    port_topic_type = ui->add_topic_type->text().toStdString();
    port_role = ui->add_role->text().toStdString();

    //controllo che i campi non siano vuoti
    if(port_name.compare("") == 0 || port_role.compare("") == 0 || port_topic_type.compare("") == 0)
           std::cout << "\nERROR! Incomplete data!\n" << std::endl;

    else {
        //Inserisco la nuova port nel vettore di port
            CmpPort port;
            port.id=progressivo_port;
            progressivo_port++;
            port.name = port_name;
            port.topic_type = port_topic_type;
            port.role = port_role;
            port.id_activity=activity_id;

            local_port->push_back(port);
            //emetto il segnale per aggiornare l'albero
            emit update_port();

        }
    //pulisco l'area di input
    ui->add_name->setText("");
    ui->add_topic_type->setText("");
    ui->add_role->setText("");
}
