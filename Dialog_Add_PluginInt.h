#ifndef DIALOG_ADD_PLUGININT_H
#define DIALOG_ADD_PLUGININT_H

#include <QDialog>
#include <CmpPlugin.h>

namespace Ui {
class Dialog_Add_PluginInt;
}

class Dialog_Add_PluginInt : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Add_PluginInt(QWidget *parent = nullptr);
    ~Dialog_Add_PluginInt();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Add_PluginInt *ui;

    std::string plugin_package;
    std::string plugin_type;
};

#endif // DIALOG_ADD_PLUGININT_H
