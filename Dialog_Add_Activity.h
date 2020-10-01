#ifndef DIALOG_ADD_ACTIVITY_H
#define DIALOG_ADD_ACTIVITY_H

#include <QDialog>
#include <CmpActivity.h>
#include <Component.h>

namespace Ui {
class Dialog_Add_Activity;
}

class Dialog_Add_Activity : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Add_Activity(QWidget *parent = nullptr);
    ~Dialog_Add_Activity();

    //creo un vettore locale di activity
    std::vector<CmpActivity>* local_act;

    //funzione che passa i dati presenti nel vettore di activity
    void setActivityVector(std::vector<CmpActivity>* act_vec, int component_id){
       this->component_id = component_id;
       this->local_act = act_vec;
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Add_Activity *ui;

    std::string activity_name;
    std::string activity_periodic;
    std::string activity_type;
    std::string activity_m;

    int component_id;
signals:
    void update_activity();
};

#endif // DIALOG_ADD_ACTIVITY_H
