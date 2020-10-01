#ifndef MYDIALOG_ADD_H
#define MYDIALOG_ADD_H

#include <QDialog>
#include <Component.h>

namespace Ui {
class Dialog_Add_Component;
}

class Dialog_Add_Component : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Add_Component(QWidget *parent = nullptr);
    ~Dialog_Add_Component();

    //creo un vettore locale di component
    std::vector<Component>* local_comp;

    //funzione che passa i dati presenti nel vettore di componenti
    void setComponentVector(std::vector<Component>* comp_vec){
       this->local_comp = comp_vec;
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Add_Component *ui;

    std::string component_name;
    std::string component_package;
    std::string component_type;


signals:
    void update_component();

};

#endif // MYDIALOG_ADD_H
