#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Dialog_Add_Component.h"
#include "Dialog_Add_Activity.h"
#include "Dialog_Add_Functionality.h"
#include "Dialog_Add_Property.h"
#include "Dialog_Add_Port.h"
#include "Dialog_Add_PluginInt.h"

//---includo le librerie di QTCreator---
#include <QPushButton>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
//---includo le librerie di QGV---
#include "QGVScene.h"
#include "QGVNode.h"
#include "QGVEdge.h"
#include "QGVSubGraph.h"

extern int progressivo_component;
extern int progressivo_activity;
extern int progressivo_port;

static int selezione_activity;
static int selezione_port;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    selezione_activity=-1;
    selezione_port=-1;
    _scene = nullptr;

//---imposto regole di visulalizzazione alle tabelle---
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_7->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_8->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_12->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_11->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

//---inizializzazione treewidget---
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(5);
    ui->treeWidget->hideColumn(1);
    ui->treeWidget->hideColumn(2);
    ui->treeWidget->hideColumn(3);
    ui->treeWidget->hideColumn(4);
    QStringList title;
    title<<"Database Content";
    ui->treeWidget->setHeaderLabels(title);
//-----------------------------------------------------------------------------------------------------------------
//Popolo i vettori, in modo da non dover perdere tempo ogni volta che compilo a inserire dati

//---popolazione vettore COMPONENT---
    Component pippo ("comp1", "package1", "type1",progressivo_component++);
    componenti.push_back(pippo);
    onUpdate_component();
    Component pippo2 ("comp2", "package2", "type2",progressivo_component++);
    componenti.push_back(pippo2);
    onUpdate_component();
    Component pippo3 ("comp3", "package3", "type3",progressivo_component++);
    componenti.push_back(pippo3);
    onUpdate_component();
    Component pippo4 ("comp4", "package4", "type4",progressivo_component++);
    componenti.push_back(pippo4);
    onUpdate_component();
    Component pippo5 ("comp5", "package5", "type5",progressivo_component++);
    componenti.push_back(pippo5);
    onUpdate_component();
    Component pippo6 ("comp6", "package6", "type6",progressivo_component++);
    componenti.push_back(pippo6);
    onUpdate_component();


//---popolazione vettore ACTIVITY---
    CmpActivity act1("act1_1", "p1_1","t1_1",progressivo_activity++,0);
    attivita.push_back(act1);
    onUpdate_activity();
    CmpActivity act2("act2_1", "p2_1","t2_1",progressivo_activity++,0);
    attivita.push_back(act2);
    onUpdate_activity();

    CmpActivity act3("act1_2", "p1_2","t1_2",progressivo_activity++,1);
    attivita.push_back(act3);
    onUpdate_activity();
    CmpActivity act4("act2_2", "p2_2","t2_2",progressivo_activity++,1);
    attivita.push_back(act4);
    onUpdate_activity();

    CmpActivity act5("act1_3", "p1_3","t1_3",progressivo_activity++,2);
    attivita.push_back(act5);
    onUpdate_activity();
    CmpActivity act6("act2_3", "p2_3","t2_3",progressivo_activity++,2);
    attivita.push_back(act6);
    onUpdate_activity();

    CmpActivity act7("act1_4", "p1_4","t1_4",progressivo_activity++,3);
    attivita.push_back(act7);
    onUpdate_activity();
    CmpActivity act8("act2_4", "p2_4","t2_4",progressivo_activity++,3);
    attivita.push_back(act8);
    onUpdate_activity();

    CmpActivity act9("act1_5", "p1_5","t1_5",progressivo_activity++,4);
    attivita.push_back(act9);
    onUpdate_activity();
    CmpActivity act10("act2_5", "p2_5","t2_5",progressivo_activity++,4);
    attivita.push_back(act10);
    onUpdate_activity();

    CmpActivity act11("act1_6", "p1_6","t1_6",progressivo_activity++,5);
    attivita.push_back(act11);
    onUpdate_activity();
    CmpActivity act12("act2_6", "p2_6","t2_6",progressivo_activity++,5);
    attivita.push_back(act12);
    onUpdate_activity();


//---popolazione vettore PORT---
    CmpPort port1("port1_1_1","S","topic4",progressivo_port++,0);
    porte.push_back(port1);
    onUpdate_port();
    CmpPort port2("port1_2_1","S","topic1",progressivo_port++,1);
    porte.push_back(port2);
    onUpdate_port();

    CmpPort port3("port1_1_2","P","topic4",progressivo_port++,2);
    porte.push_back(port3);
    onUpdate_port();
    CmpPort port4("port1_2_2","P","topic1",progressivo_port++,3);
    porte.push_back(port4);
    onUpdate_port();

    CmpPort port5("port1_1_3","S","topic10",progressivo_port++,4);
    porte.push_back(port5);
    onUpdate_port();
    CmpPort port6("port1_2_3","P","topic6",progressivo_port++,5);
    porte.push_back(port6);
    onUpdate_port();

    CmpPort port7("port1_1_4","S","topic17",progressivo_port++,6);
    porte.push_back(port7);
    onUpdate_port();
    CmpPort port8("port1_2_4","P","topic17",progressivo_port++,7);
    porte.push_back(port8);
    onUpdate_port();

    CmpPort port9("port1_1_5","P","topic6",progressivo_port++,8);
    porte.push_back(port9);
    onUpdate_port();
    CmpPort port10("port1_2_5","S","topic7",progressivo_port++,9);
    porte.push_back(port10);
    onUpdate_port();

    CmpPort port11("port1_1_6","P","topic7",progressivo_port++,10);
    porte.push_back(port11);
    onUpdate_port();
    CmpPort port12("port1_2_6","S","topic1",progressivo_port++,11);
    porte.push_back(port12);
    onUpdate_port();
    CmpPort port15("port2_1_3","P","topic1",progressivo_port++,4);
    porte.push_back(port15);
    onUpdate_port();

}

//---distruttore---
MainWindow::~MainWindow()
{
    delete ui;
}

//---al premere "table->add Component" si apre una nuova winodw necessaria per l'aggiunta del component---
void MainWindow::on_actionAdd_component_triggered(){
    Dialog_Add_Component dialog_component;
    dialog_component.setModal(true);
    dialog_component.setWindowTitle("Add Component");
    dialog_component.setComponentVector(&componenti);
    connect(&dialog_component, SIGNAL (update_component()), this, SLOT (onUpdate_component()));

    dialog_component.exec();
    dialog_component.close();

}

//---Prossime 5 funzioni aprono la window corrispondente e fanno inserire dati (implementazione futura)
void MainWindow::on_actionAdd_Activity_triggered(){
    Dialog_Add_Activity dialog_activity;
    dialog_activity.setModal(true);
    dialog_activity.setWindowTitle("Add Activity");
    dialog_activity.exec();
    dialog_activity.close();
}
void MainWindow::on_actionAdd_Property_triggered(){
    Dialog_Add_Property dialog_property;
    dialog_property.setModal(true);
    dialog_property.setWindowTitle("Add Property");
    dialog_property.exec();
    dialog_property.close();
}
void MainWindow::on_actionAdd_Port_triggered(){
    Dialog_Add_Port dialog_port;
    dialog_port.setModal(true);
    dialog_port.setWindowTitle("Add Port");
    dialog_port.exec();
}
void MainWindow::on_actionAdd_Functionality_triggered(){
   Dialog_Add_Functionality dialog_functionality;
   dialog_functionality.setModal(true);
   dialog_functionality.setWindowTitle("Add Functionality");
   dialog_functionality.exec();
   dialog_functionality.close();
}
void MainWindow::on_actionAdd_Plugin_triggered(){
    Dialog_Add_PluginInt dialog_plugin;
    dialog_plugin.setModal(true);
    dialog_plugin.setWindowTitle("Add Plugin");
    dialog_plugin.exec();
    dialog_plugin.close();
}

//---aggiunta del component appena inserito nell'albero---
void MainWindow::onUpdate_component(){

       int i=componenti.size()-1;
       if (i<0)
           return;
        QTreeWidgetItem *root = new QTreeWidgetItem(/*ui->treeWidget*/);
        root->setText(0,componenti[i].category.c_str());
        root->setText(1,componenti[i].package.c_str());
        root->setText(2,componenti[i].type.c_str());
        root->setText(3,std::to_string(componenti[i].id).c_str());
        root->setText(4,componenti[i].info.c_str());
        ui->treeWidget->addTopLevelItem(root);

}


//---Permette l'apertura al doppioclick di una nuova window---
void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{

    //se l'item premuto è un component allora dovrà andare ad inserire una nuova activity
    if(item->text(4).toStdString()=="Component"){
        Dialog_Add_Activity dialog_activity;
        dialog_activity.setModal(true);
        dialog_activity.setWindowTitle("Add Activity");
        dialog_activity.setActivityVector(&attivita,std::atoi(item->text(3).toStdString().c_str()));
        connect(&dialog_activity, SIGNAL (update_activity()), this, SLOT (onUpdate_activity()));
        dialog_activity.exec();
        dialog_activity.close();
    }

    //se l'item premuto è una activity allora dovrà andare ad inserire una nuova port
    if(item->text(4).toStdString()=="Activity"){
        Dialog_Add_Port dialog_port;
        dialog_port.setModal(true);
        dialog_port.setWindowTitle("Add Port");
        dialog_port.setPortVector(&porte, std::atoi(item->text(3).toStdString().c_str()));
        connect(&dialog_port, SIGNAL (update_port()), this, SLOT (onUpdate_port()));
        dialog_port.exec();
        dialog_port.close();
    }
}

//---funzione che si attiva al singolo click in un item dell'albero---
void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    //imposto i campi della tabella in basso a sinistra
    ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(item->text(1)));
    ui->tableWidget_2->setItem(0,1, new QTableWidgetItem(item->text(2)));

    //Vado a cercare il corrispettivo item all'interno del grafo e lo rendo visibile (blu scuro)
    if(item->text(4).toStdString()=="Activity"){
        for(int i=0; i<static_cast<int>(lista_activity.size()); i++){
            if(std::atoi(item->text(3).toStdString().c_str())==lista_activity[i].id)
                selezione_activity=lista_activity[i].id;
        }
        drawGraph();
    }
    if(item->text(4).toStdString()=="Port"){
        for(int i=0; i<static_cast<int>(lista_port.size()); i++){
            if(std::atoi(item->text(3).toStdString().c_str())==lista_port[i].id_port)
                selezione_port=lista_port[i].id_port;
        }
        drawGraph();
    }
}

//---aggiunta dell'activity appena inserita nell'albero---
void MainWindow::onUpdate_activity(){
    int ia=attivita.size()-1;
    if (ia<0)
        return;
    int ic=attivita[ia].id_component;
    if (ic<0)
        return;
     QTreeWidgetItem *child = new QTreeWidgetItem();
     child->setText(0,attivita[ia].name.c_str());
     child->setText(1,attivita[ia].package.c_str());
     child->setText(2,attivita[ia].type.c_str());
     child->setText(3,std::to_string(attivita[ia].id).c_str());
     child->setText(4,attivita[ia].info.c_str());

     QTreeWidgetItem *root = ui->treeWidget->topLevelItem(ic);
     root->addChild(child);
     drawGraph();

}

//---aggiunta della port appena inserito nell'albero---
void MainWindow::onUpdate_port(){
    int ip=porte.size()-1;
    if (ip<0)
        return;
    int ia=porte[ip].id_activity;
    if (ia<0)
        return;
    int ic=attivita[ia].id_component;
    if (ic<0)
        return;
     QTreeWidgetItem *child = new QTreeWidgetItem();
     child->setText(0,porte[ip].name.c_str());
     child->setText(1,porte[ip].topic_type.c_str());
     child->setText(2,porte[ip].role.c_str());
     child->setText(3,std::to_string(porte[ip].id).c_str());
     child->setText(4,porte[ip].info.c_str());
     QTreeWidgetItem *root = ui->treeWidget->topLevelItem(ic);
     for( int k=0; k<(root->childCount());k++){
         //int box=(root->child(k)->text(3)).toInt();
         if((root->child(k)->text(3)).toInt() == ia)
              root->child(k)->addChild(child);
     }
     drawGraph();

}

//---Disegno il grafo ogni volta che ci sono dei cambiamenti nell'albero---
void MainWindow::drawGraph()
{
    //elimino la scena vecchia se esistente
    if (_scene!=nullptr)
        delete _scene;
    _scene=new QGVScene("DEMO", this);
    ui->graphicsView->setScene(_scene);
    _scene->clear();
    QGVScene *trash = new QGVScene ("", this);
    //imposto attributi generali del grafo
    _scene->setGraphAttribute("splines", "ortho");
    _scene->setGraphAttribute("nodesep", "0.4");
    _scene->setNodeAttribute("style", "filled");
    _scene->setNodeAttribute("fillcolor", "white");
    _scene->setNodeAttribute("height", "1.2");
    _scene->setEdgeAttribute("minlen", "3");

    //disegno effettivo del grafo
    lista_port.clear();
    lista_activity.clear();

    //aggiunta component al grafo
    for(int i=0; i<static_cast<int>(componenti.size()); i++){
        QString str = "SUB"+QString::number(i)+"C";
        QGVSubGraph *component_graph = _scene->addSubGraph(str);
        std::string name_c = std::string("COMPONENT: ") + componenti[i].category;
        component_graph->setAttribute("label", QString::fromStdString(name_c));

        //aggiunta activity al grafo
        for(int k=0; k<static_cast<int>(attivita.size()); k++){
            if(attivita[k].id_component == componenti[i].id){
                QString str2 = "SUB"+QString::number(k)+"A";
                QGVSubGraph *box = component_graph->addSubGraph(str2);
                box->setAttribute("color","light blue");
                box->setAttribute("style","filled");
                box->setAttribute("fillcolor","light blue");
                box->setAttribute("label", "");
                QGVNode *activity_graph = box->addNode(QString::fromStdString(attivita[k].name));
                INFO_ACTIVITY item(activity_graph, attivita[k].id);
                lista_activity.push_back(item);

                //controllo se l'activity è quella selezionata nell'albero e decido il colore
                if(selezione_activity==attivita[k].id){
                    activity_graph->setAttribute("fillcolor","blue");
                    activity_graph->setAttribute("color","light blue");
                }
                else{
                    activity_graph->setAttribute("fillcolor","light blue");
                    activity_graph->setAttribute("color","light blue");
                }

                //aggiunta nodo al grafo
                for(int j=0; j<static_cast<int>(porte.size()); j++){
                    if(porte[j].id_activity == attivita[k].id){
                        QGVNode *nodo = box->addNode(QString::fromStdString(porte[j].name));
                        INFO_PORT item(nodo, porte[j].id);
                        lista_port.push_back(item);
                        nodo->setAttribute("shape", "box");
                        nodo->setAttribute("fixedsize", "true");
                        nodo->setAttribute("height", "0.25");
                        nodo->setAttribute("width", "0.25");
                        nodo->setLabel("");

                        //controllo se la port è quella selezionata nel grafo e decido il colore
                        if(selezione_port==porte[j].id){
                            if(porte[j].role=="P")
                                nodo->setAttribute("fillcolor", "blue");
                            if (porte[j].role=="S")
                                nodo->setAttribute("fillcolor","blue");
                        }
                        else{
                            //a seconda del ruolo assegno un colore diverso
                            if(porte[j].role=="P")
                                nodo->setAttribute("fillcolor", "light green");
                            if (porte[j].role=="S")
                                nodo->setAttribute("fillcolor","red");
                        }

                    }
                }
            }
        }
    }

    //stampa delle frecce
    lista_edge.clear();
    percorsi.clear();
    for (int i=0; i<static_cast<int>(lista_port.size()); i++){
       for (int k=0; k<static_cast<int>(lista_port.size()); k++){
           if(porte[lista_port[i].id_port].role=="P" && porte[lista_port[k].id_port].role=="S" &&
              porte[lista_port[i].id_port].topic_type==porte[lista_port[k].id_port].topic_type){

               QGVNode *freccia = trash->addNode(QString::fromStdString(porte[lista_port[k].id_port].topic_type));
               //vado a controllare se nella lista_edge il topic è già presente
               bool check=false;
               int index=0;
               for(int l=0; l<static_cast<int>(lista_edge.size());l++){
                   if(freccia->label()== lista_edge[l].nodo->label()){
                       check=true;
                       index=l;
                    }
                }
               if(check){
                   //se il topic è già disegnato allora vado a disegnare le frecce
                   VerificaPercorso(lista_port[i].nodo, lista_edge[index].nodo);
                   VerificaPercorso(lista_edge[index].nodo, lista_port[k].nodo);

               }
               else{
                   //altrimenti prima disegno il topic e poi le frecce
                   freccia=_scene->addNode(QString::fromStdString(porte[lista_port[k].id_port].topic_type));
                   freccia->setAttribute("height", "0.1");
                   freccia->setAttribute("shape","box");
                   freccia->setAttribute("fillcolor","light yellow");
                   freccia->setAttribute("color","yellow");
                   VerificaPercorso(lista_port[i].nodo, freccia);
                   VerificaPercorso(freccia, lista_port[k].nodo);
                   INFO_PORT item(freccia, porte[lista_port[k].id_port].id);
                   lista_edge.push_back(item);
               }
           }
       }
    }
    //azzero i contatori che mi dicono gli item selezionati
    selezione_activity=-1;
    selezione_port=-1;

    //setto il layout e aspetto il doubleclick su un nodo
    _scene->applyLayout();
    connect(_scene, SIGNAL(nodeDoubleClick(QGVNode*)), SLOT(nodeDoubleClick(QGVNode*)));

}


//---Verifico se la freccia è già disegnata---
void MainWindow::VerificaPercorso(QGVNode *a, QGVNode *b){
    bool found=false;
    for(INFO_EDGE item:percorsi){
        if(item.partenza==a && item.arrivo==b)
            found=true;
    }
    if(!found){
        //se non esiste la disegno e la aggiungo nel vettore di quelle disegnate
       INFO_EDGE item(a,b);
       percorsi.push_back(item);
       _scene->addEdge(a,b);
    }
}

//---funzione che mi evidenzia nell'albero il nodo premuto---
void MainWindow::nodeDoubleClick(QGVNode *node)
{
    // ripristino il tree alle proprietà grafiche originarie
    for(int k=0; k<static_cast<int>(componenti.size()); k++){
        ui->treeWidget->topLevelItem(k)->setBackground(0,Qt::white);
        for(int i=0; i<(ui->treeWidget->topLevelItem(k)->childCount()); i++){
            QTreeWidgetItem *group = ui->treeWidget->topLevelItem(k)->child(i);
            group->setBackground(0,Qt::white);
            QFont font = group->font(0);
            font.setBold(false);
            group->setFont(0,font);
            for(int j=0; j<(ui->treeWidget->topLevelItem(k)->child(i)->childCount()); j++){
                group->child(j)->setBackground(0,Qt::white);
                QFont font = group->font(0);
                font.setBold(false);
                group->child(j)->setFont(0,font);
               }
            }
        }

    // evidenzio l'attività selezionata dal grafo
    for(int i=0; i<static_cast<int>(lista_activity.size()); i++){
        if (lista_activity[i].activity== node){
            for (int k=0; k<static_cast<int>(attivita.size()); k++){
                if(attivita[k].id==lista_activity[i].id){
                     QList<QTreeWidgetItem*> items = ui->treeWidget->findItems(attivita[k].name.c_str(),Qt::MatchRecursive);
                     QTreeWidgetItem *group = items.at(0);
                     group->setBackground(0,QColor(204,229,255));
                     QFont font = group->font(0);
                     font.setBold(true);
                     group->setFont(0,font);
                     group->parent()->setExpanded(true);
                }

            }
        }
    }

    // evidenzio la port selezionata dal grafo
    for(int i=0; i<static_cast<int>(lista_port.size()); i++){
        if (lista_port[i].nodo== node){
            for (int k=0; k<static_cast<int>(porte.size()); k++){
                if(porte[k].id==lista_port[i].id_port){
                     QList<QTreeWidgetItem*> items = ui->treeWidget->findItems(porte[k].name.c_str(),Qt::MatchRecursive);
                     QTreeWidgetItem *group = items.at(0);
                     if(porte[k].role=="P")
                         group->setBackground(0,QColor(204,255,204));
                     if (porte[k].role=="S")
                         group->setBackground(0,QColor(255,204,204));
                     QFont font = group->font(0);
                     font.setBold(true);
                     group->setFont(0,font);
                     group->parent()->parent()->setExpanded(true);
                     group->parent()->setExpanded(true);
                }

            }
        }
    }
    //evidenzio tutte le port collegate al topic selezionato
    for(int i=0; i<static_cast<int>(lista_edge.size()); i++){
        if (lista_edge[i].nodo== node){
            for (int k=0; k<static_cast<int>(porte.size()); k++){
                if(porte[k].id==lista_edge[i].id_port){
                     QList<QTreeWidgetItem*> items = ui->treeWidget->findItems(porte[k].topic_type.c_str(),Qt::MatchRecursive, 1);
                     for(int l=0; l<items.size();l++){
                         QTreeWidgetItem *group = items.at(l);
                         group->setBackground(0,QColor(255,255,204));
                         QFont font = group->font(0);
                         font.setBold(true);
                         group->setFont(0,font);
                         group->parent()->parent()->setExpanded(true);
                         group->parent()->setExpanded(true);
                     }
                }

            }
        }
    }
}

