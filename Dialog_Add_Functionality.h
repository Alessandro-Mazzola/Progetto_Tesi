#ifndef DIALOG_ADD_FUNCTIONALITY_H
#define DIALOG_ADD_FUNCTIONALITY_H

#include <QDialog>
#include <CmpFunctionality.h>

namespace Ui {
class Dialog_Add_Functionality;
}

class Dialog_Add_Functionality : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Add_Functionality(QWidget *parent = nullptr);
    ~Dialog_Add_Functionality();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Add_Functionality *ui;

    std::string functionality_name;
    std::string functionality_plugin_interfaces;
};

#endif // DIALOG_ADD_FUNCTIONALITY_H
