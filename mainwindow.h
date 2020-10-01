#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "/home/alessandro/STAR-GUI/Core/include/star/core/dbcmp/DBComponentAPIX.hpp"
#include <QMainWindow>
#include <QTextEdit>
#include <QDialog>
#include <QTableWidget>
#include <QTreeWidgetItem>

#include <Component.h>
#include <CmpActivity.h>
#include <CmpFunctionality.h>
#include <CmpProperty.h>
#include <CmpPort.h>
#include <CmpPlugin.h>
#include "QGVCore/QGVScene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAdd_component_triggered();
    void onUpdate_component();

    void on_actionAdd_Activity_triggered();
    void onUpdate_activity();

    void on_actionAdd_Port_triggered();
    void onUpdate_port();

    void on_actionAdd_Property_triggered();

    void on_actionAdd_Functionality_triggered();

    void on_actionAdd_Plugin_triggered();

    //funzioni che lavorano sull'albero
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    //funzioni che lavorano sul grafo
     void drawGraph();
    void nodeDoubleClick(QGVNode* node);
    void VerificaPercorso(QGVNode *a, QGVNode *b);




private:
    Ui::MainWindow *ui;
    //vettori che memorizzano tutti gli oggetti inseriti
    std::vector<Component> componenti;
    std::vector<CmpActivity> attivita;
    std::vector<CmpFunctionality> funzionalita;
    std::vector<CmpProperty> proprieta;
    std::vector<CmpPort> porte;

    QGVScene *_scene;
    //dichiarazione strutture per tenere traccia di quello disegnato
    struct INFO_PORT{
        QGVNode *nodo;
        int id_port;
        bool selezionato;
        INFO_PORT(QGVNode *node, int port){nodo=node; id_port=port; selezionato=false;};
    };

    struct INFO_ACTIVITY{
        QGVNode *activity;
        int id;
        bool selezionato;
        INFO_ACTIVITY(QGVNode *act, int act_id){activity=act; id=act_id; selezionato=false;};
    };
    struct INFO_EDGE{
        QGVNode *partenza;
        QGVNode *arrivo;
        INFO_EDGE(QGVNode *p, QGVNode *a){partenza=p;arrivo=a;};
    };

    //vettori che mi associano quello disegnato con l'id dell'oggetto corrispondente
    std::vector<INFO_PORT> lista_port;
    std::vector<INFO_ACTIVITY> lista_activity;
    std::vector<INFO_PORT> lista_edge;
    std::vector<INFO_EDGE> percorsi;

};
#endif // MAINWINDOW_H
