#ifndef DIALOG_ADD_PROPERTY_H
#define DIALOG_ADD_PROPERTY_H

#include <QDialog>
#include <CmpProperty.h>

namespace Ui {
class Dialog_Add_Property;
}

class Dialog_Add_Property : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Add_Property(QWidget *parent = nullptr);
    ~Dialog_Add_Property();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Add_Property *ui;

    std::string property_name;
    std::string property_type;
    std::string property_domain;
};

#endif // DIALOG_ADD_PROPERTY_H
