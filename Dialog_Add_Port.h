#ifndef DIALOG_ADD_PORT_H
#define DIALOG_ADD_PORT_H

#include <QDialog>
#include <CmpPort.h>

namespace Ui {
class Dialog_Add_Port;
}

class Dialog_Add_Port : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Add_Port(QWidget *parent = nullptr);
    ~Dialog_Add_Port();

    //creo un vettore locale di port
    std::vector<CmpPort>* local_port;

    //funzione che passa i dati presenti nel vettore di port
    void setPortVector(std::vector<CmpPort>* port_vec, int activity_id){
         this->activity_id = activity_id;
         this->local_port = port_vec;
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Add_Port *ui;

    std::string port_name;
    std::string port_topic_type;
    std::string port_role;

    int activity_id;

signals:
    void update_port();
};

#endif // DIALOG_ADD_PORT_H
