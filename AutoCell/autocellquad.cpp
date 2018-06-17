#include "autocellquad.h"
#include "Automaton.h"
#include "QuadLife.h"
#include "simulator.h"
#include "randomGridGenerator.h"
#include "symmetricDGridGenerator.h"
#include "symmetricHGridGenerator.h"
#include "symmetricVGridGenerator.h"
#include "saveuicontext.h"
#include "dbManager.h"

extern DbManager dbTest;

AutoCellQuad::AutoCellQuad(QWidget *parent) : QWidget(parent){
    stepSimulation=false;
    playSimulation=false;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(launchSimulationStep()));

    namel = new QLabel("Quadlife", this);

    min_n = new QSpinBox(this);
    min_n->setRange(0, 8);
    min_n->setValue(0);
    min_nl = new QLabel("Min neighbours to stay alive", this);

    max_n = new QSpinBox(this);
    max_n->setRange(0, 8);
    max_n->setValue(0);
    max_nl = new QLabel("Max neighbours to stay alive", this);

    dim1 = new QSpinBox(this);
    dim1->setRange(0, 25);
    dim1->setValue(0);
    dim1l = new QLabel("Grid dimension 1", this);

    dim2 = new QSpinBox(this);
    dim2->setRange(0, 25);
    dim2->setValue(0);
    dim2l = new QLabel("Grid dimension 2", this);

    nb_step = new QSpinBox(this);
    nb_step->setRange(0, 255);
    nb_step->setValue(0);
    nb_stepl = new QLabel("Simulator's number of grids", this);

    numc = new QVBoxLayout;
    numc->addWidget(namel);
    numc->addWidget(min_nl);
    numc->addWidget(min_n);
    numc->addWidget(max_nl);
    numc->addWidget(max_n);
    numc->addWidget(dim1l);
    numc->addWidget(dim1);
    numc->addWidget(dim2l);
    numc->addWidget(dim2);
    numc->addWidget(nb_stepl);
    numc->addWidget(nb_step);

    numeroc = new QHBoxLayout;
    numeroc->addLayout(numc);


    couche = new QVBoxLayout;
    couche->addLayout(numeroc);


    saveAutomaton = new QPushButton("Save Automaton", this);
    connect(saveAutomaton, SIGNAL(clicked()), this, SLOT(saveAutom()));
    couche->addWidget(saveAutomaton);


    loadAutomatonl = new QLabel("Choose an automaton to load (min neigbours, max neigbours)", this);
    couche->addWidget(loadAutomatonl);
    loadAutomaton = new QComboBox(this);
    couche->addWidget(loadAutomaton);
    connect(loadAutomaton, SIGNAL(activated(int)), this, SLOT(choiceAutomChanged()));

    loadAutomList();

    depart=nullptr;
    grid = new QPushButton("New Grid", this);
    connect(grid, SIGNAL(clicked()), this, SLOT(newGrid()));
    couche->addWidget(grid);

    choiceGrid = new QComboBox(this);
    choiceGrid->addItem("Manual filling");
    choiceGrid->addItem("Generate random grid");
    choiceGrid->addItem("Generate symmetric diagonal grid");
    choiceGrid->addItem("Generate symmetric horizontal grid");
    choiceGrid->addItem("Generate symmetric vertical grid");
    connect(choiceGrid, SIGNAL(currentTextChanged(QString)), this, SLOT(choiceGridChanged(QString)));
    couche->addWidget(choiceGrid);


    simLayout = new QHBoxLayout;
    simulation = new QPushButton("Start/Resume continuous simulation", this);
    connect(simulation, SIGNAL(clicked()), this, SLOT(launchSimulation()));
    simLayout->addWidget(simulation);
    pauseButton = new QPushButton("Pause Simulation",this);
    connect(pauseButton,SIGNAL(clicked()), this, SLOT(pause()));
    simLayout->addWidget(pauseButton);

    speed = new QSpinBox(this);
    speed->setRange(0, 50);
    speed->setValue(0);
    speedl = new QLabel("Simulation speed (in sec)", this);
    simLayout->addWidget(speedl);
    simLayout->addWidget(speed);

    simulationStep = new QPushButton("Simulation step by step", this);
    connect(simulationStep, SIGNAL(clicked()), this, SLOT(launchSimulationStep()));
    simLayout->addWidget(simulationStep);
    couche->addLayout(simLayout);

    setLayout(couche);
    loadSettings();
    connect(QApplication::instance(), SIGNAL(aboutToQuit()), this, SLOT(saveSettings()));
}

void AutoCellQuad::cellActivation(const QModelIndex& index) {
    if(stepSimulation==false && playSimulation==false){
        if(depart->item(index.row(), index.column())->backgroundColor()==Qt::white){
            depart->item(index.row(), index.column())->setBackgroundColor(Qt::blue);
            return;
        }

        if(depart->item(index.row(), index.column())->backgroundColor()==Qt::blue){
            depart->item(index.row(), index.column())->setBackgroundColor(Qt::red);
            return;
        }
        if(depart->item(index.row(), index.column())->backgroundColor()==Qt::red){
            depart->item(index.row(), index.column())->setBackgroundColor(Qt::yellow);
            return;
        }
        if(depart->item(index.row(), index.column())->backgroundColor()==Qt::yellow){
            depart->item(index.row(), index.column())->setBackgroundColor(Qt::green);
            return;
        }
        if(depart->item(index.row(), index.column())->backgroundColor()==Qt::green){
            depart->item(index.row(), index.column())->setBackgroundColor(Qt::white);
            return;
        }
    }
}

void AutoCellQuad::choiceGridChanged(const QString &s){
    if(s=="Manual filling"){
        this->newGrid();
        return;
    }
    if(s=="Generate random grid"){
        this->randomGrid();
        return;
    }
    if(s=="Generate symmetric diagonal grid"){
        this->symmetricDGrid();
        return;
    }
    if(s=="Generate symmetric horizontal grid"){
        this->symmetricHGrid();
        return;
    }
    if(s=="Generate symmetric vertical grid"){
        this->symmetricVGrid();
        return;
    }
}


void AutoCellQuad::newGrid(){
    Simulator::freeInstance();
    if(depart!=nullptr){
        delete depart;
    }
    if(stepSimulation)
        stepSimulation=false;
    if(playSimulation)
        playSimulation=false;

    depart = new QTableWidget(dim1->value(), dim2->value(), this); //dim1 lignes, dim2 colonnes
    depart->setFixedSize(dim2->value()*25, dim1->value()*25);
    depart->horizontalHeader()->setVisible(false); // masque le header horizontal
    depart->verticalHeader()->setVisible(false); // masque le header vertical
    depart->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // désactive la scroll barre
    depart->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // idem
    // création des items du QTableWidget, initialisés à "" avec un fond blanc
    for(unsigned int counterV = 0; counterV < dim1->value(); ++counterV) {
        depart->setRowHeight(counterV, 25);
        for(unsigned int counterH = 0; counterH < dim2->value(); ++counterH) {
            depart->setColumnWidth(counterH, 25);
            depart->setItem(counterV, counterH, new QTableWidgetItem(""));
            depart->item(counterV, counterH)->setBackgroundColor("white");
            depart->item(counterV, counterH)->setTextColor("white");
        }
    }
    connect(depart, SIGNAL(clicked(QModelIndex)), this,
            SLOT(cellActivation(QModelIndex)));
    couche->addWidget(depart);
}

void AutoCellQuad::symmetricDGrid(){
    this->newGrid();
    Grid g(dim1->value(),dim2->value(),5);
    SymmetricDGridGenerator gridGenerator;
    g.executeGridGenerator(gridGenerator);
    for(unsigned int i = 0; i < dim1->value(); ++i) {
        for(unsigned int j = 0; j < dim2->value(); ++j) {
            if(g.getCell(i,j)== 0){
                 depart->item(i, j)->setBackgroundColor(Qt::white);
            }
            if(g.getCell(i,j)== 1){
                 depart->item(i, j)->setBackgroundColor(Qt::blue);
            }
            if(g.getCell(i,j)== 2){
                 depart->item(i, j)->setBackgroundColor(Qt::red);
            }
            if(g.getCell(i,j)== 3){
                 depart->item(i, j)->setBackgroundColor(Qt::yellow);
            }
            if(g.getCell(i,j)== 4){
                 depart->item(i, j)->setBackgroundColor(Qt::green);
            }
        }
    }
}

void AutoCellQuad::symmetricHGrid(){
    this->newGrid();
    Grid g(dim1->value(),dim2->value(),5);
    SymmetricHGridGenerator gridGenerator;
    g.executeGridGenerator(gridGenerator);
    for(unsigned int i = 0; i < dim1->value(); ++i) {
        for(unsigned int j = 0; j < dim2->value(); ++j) {
            if(g.getCell(i,j)== 0){
                 depart->item(i, j)->setBackgroundColor(Qt::white);
            }
            if(g.getCell(i,j)== 1){
                 depart->item(i, j)->setBackgroundColor(Qt::blue);
            }
            if(g.getCell(i,j)== 2){
                 depart->item(i, j)->setBackgroundColor(Qt::red);
            }
            if(g.getCell(i,j)== 3){
                 depart->item(i, j)->setBackgroundColor(Qt::yellow);
            }
            if(g.getCell(i,j)== 4){
                 depart->item(i, j)->setBackgroundColor(Qt::green);
            }
        }
    }
}

void AutoCellQuad::symmetricVGrid(){
    this->newGrid();
    Grid g(dim1->value(),dim2->value(),5);
    SymmetricVGridGenerator gridGenerator;
    g.executeGridGenerator(gridGenerator);
    for(unsigned int i = 0; i < dim1->value(); ++i) {
        for(unsigned int j = 0; j < dim2->value(); ++j) {
            if(g.getCell(i,j)== 0){
                 depart->item(i, j)->setBackgroundColor(Qt::white);
            }
            if(g.getCell(i,j)== 1){
                 depart->item(i, j)->setBackgroundColor(Qt::blue);
            }
            if(g.getCell(i,j)== 2){
                 depart->item(i, j)->setBackgroundColor(Qt::red);
            }
            if(g.getCell(i,j)== 3){
                 depart->item(i, j)->setBackgroundColor(Qt::yellow);
            }
            if(g.getCell(i,j)== 4){
                 depart->item(i, j)->setBackgroundColor(Qt::green);
            }
        }
    }
}

void AutoCellQuad::randomGrid(){
    this->newGrid();
    Grid g(dim1->value(),dim2->value(),5);
    RandomGridGenerator gridGenerator;
    g.executeGridGenerator(gridGenerator);
    for(unsigned int i = 0; i < dim1->value(); ++i) {
        for(unsigned int j = 0; j < dim2->value(); ++j) {
            if(g.getCell(i,j)== 0){
                 depart->item(i, j)->setBackgroundColor(Qt::white);
            }
            if(g.getCell(i,j)== 1){
                 depart->item(i, j)->setBackgroundColor(Qt::blue);
            }
            if(g.getCell(i,j)== 2){
                 depart->item(i, j)->setBackgroundColor(Qt::red);
            }
            if(g.getCell(i,j)== 3){
                 depart->item(i, j)->setBackgroundColor(Qt::yellow);
            }
            if(g.getCell(i,j)== 4){
                 depart->item(i, j)->setBackgroundColor(Qt::green);
            }
        }
    }
}

void AutoCellQuad::launchSimulation() {
    playSimulation=true;
    if(stepSimulation){
       stepSimulation=false;
    }

    // création de l'état
    Grid g(dim1->value(),dim2->value(),5);
    // on récupère les données de l'état de l'interface graphique pour que ça corresponde à l'objet qu'on vient de créer

    for(unsigned int i = 0; i < dim1->value(); ++i) {
        for(unsigned int j = 0; j < dim2->value(); ++j) {
            if(depart->item(i,j)->backgroundColor()==Qt::white){
                    g.setCell(i,j,0);
            }
            if(depart->item(i,j)->backgroundColor()==Qt::blue){
                    g.setCell(i,j,1);
            }
            if(depart->item(i,j)->backgroundColor()==Qt::red){
                    g.setCell(i,j,2);
            }
            if(depart->item(i,j)->backgroundColor()==Qt::yellow){
                    g.setCell(i,j,3);
            }
            if(depart->item(i,j)->backgroundColor()==Qt::green){
                    g.setCell(i,j,4);
            }
        }
    }
    Simulator::freeInstance();
    QuadLife ql(min_n->value(),max_n->value());
    // on construit l'objet simulateur correspondant
    Simulator* sim = &(Simulator::getSimulator(ql,g,5));

    // on applique les transitions au simulateur en affichant le résultat dans l'interface graphique


    timer->start(speed->value()*1000);
}


void AutoCellQuad::launchSimulationStep() {
    stepSimulation=true;
    if(playSimulation){
       playSimulation=false;
    }

    // création de l'état
    Grid g1(dim1->value(),dim2->value(),5);
    // on récupère les données de l'état de l'interface graphique pour que ça corresponde à l'objet qu'on vient de créer

    for(unsigned int i = 0; i < dim1->value(); ++i) {
        for(unsigned int j = 0; j < dim2->value(); ++j) {
            if(depart->item(i,j)->backgroundColor()==Qt::white){
                    g1.setCell(i,j,0);
            }
            if(depart->item(i,j)->backgroundColor()==Qt::blue){
                    g1.setCell(i,j,1);
            }
            if(depart->item(i,j)->backgroundColor()==Qt::red){
                    g1.setCell(i,j,2);
            }
            if(depart->item(i,j)->backgroundColor()==Qt::yellow){
                    g1.setCell(i,j,3);
            }
            if(depart->item(i,j)->backgroundColor()==Qt::green){
                    g1.setCell(i,j,4);
            }
        }
    }
    Simulator::freeInstance();
    QuadLife ql(min_n->value(),max_n->value());
    // on construit l'objet simulateur correspondant
    Simulator* sim = &(Simulator::getSimulator(ql,g1,nb_step->value()));


    // on applique la transition
    sim->next();
    // on récupère le dernier état
    const Grid& g = sim->last();
    // on l'affiche
    for(unsigned int i = 0; i < dim1->value(); ++i) {
        for(unsigned int j = 0; j < dim2->value(); ++j) {
            if(g.getCell(i,j)== 0){
                 depart->item(i, j)->setBackgroundColor(Qt::white);
            }
            if(g.getCell(i,j)== 1){
                 depart->item(i, j)->setBackgroundColor(Qt::blue);
            }
            if(g.getCell(i,j)== 2){
                 depart->item(i, j)->setBackgroundColor(Qt::red);
            }
            if(g.getCell(i,j)== 3){
                 depart->item(i, j)->setBackgroundColor(Qt::yellow);
            }
            if(g.getCell(i,j)== 4){
                 depart->item(i, j)->setBackgroundColor(Qt::green);
            }
        }
    }
}


void AutoCellQuad::saveSettings(){

    int  min_n_val = min_n->value();
    saveUiContext("min_n_key_quad",min_n_val);

    int  max_n_val = max_n->value();
    saveUiContext("max_n_key_quad",max_n_val);

    int  dim1_val = dim1->value();
    saveUiContext("dim1_key_quad",dim1_val);

    int  dim2_val = dim2->value();
    saveUiContext("dim2_key_quad",dim2_val);

    int  nb_step_val = nb_step->value();
    saveUiContext("nb_step_key_quad",nb_step_val);

    int choice_grid_quad_val = choiceGrid->currentIndex();
    saveUiContext("choice_grid_quad_key",choice_grid_quad_val);

    for(unsigned int i = 0; i < dim1->value(); ++i) {
        for(unsigned int j = 0; j < dim2->value(); ++j) {
            QString s1 = s1.number((i));
            QString s2 = s2.number((j));
            if(depart->item(i,j)->backgroundColor() == Qt::white) {
                saveUiContext("item_key_quad"+s1+","+s2,0);
            }
            if(depart->item(i,j)->backgroundColor() == Qt::blue) {
                saveUiContext("item_key_quad"+s1+","+s2,1);
            }
            if(depart->item(i,j)->backgroundColor() == Qt::red) {
                saveUiContext("item_key_quad"+s1+","+s2,2);
            }
            if(depart->item(i,j)->backgroundColor() == Qt::yellow) {
                saveUiContext("item_key_quad"+s1+","+s2,3);
            }
            if(depart->item(i,j)->backgroundColor() == Qt::green) {
                saveUiContext("item_key_quad"+s1+","+s2,4);
            }
        }
    }

    int  speed_val = speed->value();
    saveUiContext("speed_key_quad",speed_val);

}


void AutoCellQuad::loadSettings(){

    QVariant min_n_val = loadUiContext("min_n_key_quad",0);
    min_n->setValue(min_n_val.toInt());

    QVariant max_n_val = loadUiContext("max_n_key_quad",0);
    max_n->setValue(max_n_val.toInt());

    QVariant dim1_val = loadUiContext("dim1_key_quad",0);
    dim1->setValue(dim1_val.toInt());

    QVariant dim2_val = loadUiContext("dim2_key_quad",0);
    dim2->setValue(dim2_val.toInt());

    QVariant nb_step_val = loadUiContext("nb_step_key_quad",0);
    nb_step->setValue(nb_step_val.toInt());

    QVariant choice_grid_quad_val = loadUiContext("choice_grid_quad_key",0);
    choiceGrid->setCurrentIndex(choice_grid_quad_val.toInt());

    this->newGrid();

    for(unsigned int i = 0; i < dim1->value(); ++i) {
        for(unsigned int j = 0; j < dim2->value(); ++j) {
            QString s1 = s1.number((i));
            QString s2 = s2.number((j));

            QVariant item_val_quad = loadUiContext("item_key_quad"+s1+","+s2,0);
            if(item_val_quad.toInt()==0){
                depart->item(i,j)->setBackgroundColor(Qt::white);
            }
            if(item_val_quad.toInt()==1){
                depart->item(i,j)->setBackgroundColor(Qt::blue);
            }
            if(item_val_quad.toInt()==2){
                depart->item(i,j)->setBackgroundColor(Qt::red);
            }
            if(item_val_quad.toInt()==3){
                depart->item(i,j)->setBackgroundColor(Qt::yellow);
            }
            if(item_val_quad.toInt()==4){
                depart->item(i,j)->setBackgroundColor(Qt::green);
            }

        }
    }

    QVariant speed_val = loadUiContext("speed_key_quad",0);
    speed->setValue(speed_val.toInt());
}


void AutoCellQuad::saveAutom(){
    QuadLife ql(min_n->value(),max_n->value());
    ql.accept(dbTest);
    loadAutomList();
}


void AutoCellQuad::loadAutomList(){
    rankRules=0;
    loadAutomaton->clear();
    QSqlQuery query = dbTest.loadQuadLifeAutomaton();
    while (query.next())
    {
        std::vector<int> vec;
        vec.push_back(query.value(0).toInt());
        vec.push_back(query.value(1).toInt());
        rules.push_back(vec);
        loadAutomaton->addItem(query.value(0).toString()+" , "+query.value(1).toString(),rankRules);
        rankRules++;
    }
}

void AutoCellQuad::choiceAutomChanged(){
    min_n->setValue(rules[loadAutomaton->currentData().toInt()][0]);
    max_n->setValue(rules[loadAutomaton->currentData().toInt()][1]);
}

void AutoCellQuad::pause(){
    timer->stop();
}


