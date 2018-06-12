#include "autocellElem.h"
#include "Automaton.h"
#include "ElementaryAutomaton.h"
#include "simulator.h"
#include "randomGridGenerator.h"
#include "symmetricDGridGenerator.h"
#include "symmetricHGridGenerator.h"
#include "symmetricVGridGenerator.h"



AutoCellElem::AutoCellElem(QWidget *parent) : QWidget(parent) {
    namel = new QLabel("Elementary automaton", this);

    num = new QSpinBox(this);
    num->setRange(0, 255);
    num->setValue(0);
    numl = new QLabel("Rule Number", this);
    numc = new QVBoxLayout;
    numc->addWidget(numl);
    numc->addWidget(num);
    numeroc = new QHBoxLayout;
    numeroc->addLayout(numc);
    zeroOneValidator = new QIntValidator(this);
    zeroOneValidator->setRange(0, 1);
    numeroBitl[0] = new QLabel("111");
    numeroBitl[1] = new QLabel("110");
    numeroBitl[2] = new QLabel("101");
    numeroBitl[3] = new QLabel("100");
    numeroBitl[4] = new QLabel("011");
    numeroBitl[5] = new QLabel("010");
    numeroBitl[6] = new QLabel("001");
    numeroBitl[7] = new QLabel("000");
    for(unsigned int counter = 0; counter < 8; ++counter) {
        numeroBit[counter] = new QLineEdit(this);
        numeroBit[counter]->setFixedWidth(20); //pixels
        numeroBit[counter]->setMaxLength(1); //caractères
        numeroBit[counter]->setText("0");
        numeroBit[counter]->setValidator(zeroOneValidator);
        bitc[counter] = new QVBoxLayout;
        bitc[counter]->addWidget(numeroBitl[counter]);
        bitc[counter]->addWidget(numeroBit[counter]);
        numeroc->addLayout(bitc[counter]);
        connect(numeroBit[counter], SIGNAL(textChanged(QString)), this, SLOT(synchronizeNumBitToNum(QString)));
    }
    connect(num, SIGNAL(valueChanged(int)), this, SLOT(synchronizeNumToNumBit(int)));


    couche = new QVBoxLayout;
    couche->addWidget(namel);
    couche->addLayout(numeroc);
    dimension = new QSpinBox(this);
    dimension->setRange(0, 255);
    dimension->setValue(0);
    dimensionl = new QLabel("Number of columns", this);
    couche->addWidget(dimensionl);
    couche->addWidget(dimension);
    nb_step = new QSpinBox(this);
    nb_step->setRange(0, 255);
    nb_step->setValue(0);
    nb_stepl = new QLabel("Number of steps", this);
    couche->addWidget(nb_stepl);
    couche->addWidget(nb_step);

    depart=nullptr;
    grids=nullptr;

    grid = new QPushButton("New Grid", this);
    connect(grid, SIGNAL(clicked()), this, SLOT(newGrid()));
    couche->addWidget(grid);

    choice = new QComboBox(this);
    choice->addItem("Manual filling");
    choice->addItem("Generate random grid");
    choice->addItem("Generate symmetric vertical grid");
    connect(choice, SIGNAL(currentTextChanged(QString)), this, SLOT(choiceChanged(QString)));
    couche->addWidget(choice);

    simLayout = new QHBoxLayout;
    simulation = new QPushButton("Play simulation", this);
    connect(simulation, SIGNAL(clicked()), this, SLOT(launchSimulation()));
    simLayout->addWidget(simulation);
    simulationStep = new QPushButton("Simulation step by step", this);
    connect(simulationStep, SIGNAL(clicked()), this, SLOT(launchSimulationStep()));
    simLayout->addWidget(simulationStep);
    couche->addLayout(simLayout);
    setLayout(couche);
}

void AutoCellElem::choiceChanged(const QString& s){
    if(s=="Manual filling"){
        this->newGrid();
        return;
    }
    if(s=="Generate random grid"){
        this->randomGrid();
        return;
    }
    if(s=="Generate symmetric vertical grid"){
        this->symmetricVGrid();
        return;
    }
}


void AutoCellElem::newGrid(){
    if(depart!=nullptr){
        delete depart;
    }
    stepSimulation=false;
    playSimulation=false;
    depart = new QTableWidget(1, dimension->value(), this); //1 ligne, dimension colonnes
    depart->setFixedSize(dimension->value()*25, 25); // largeur = nombre_cellules*25_cellule, hauteur = 25_cellule
    depart->horizontalHeader()->setVisible(false); // masque le header horizontal
    depart->verticalHeader()->setVisible(false); // masque le header vertical
    depart->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // désactive la scroll barre
    depart->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // idem
    // création des items du QTableWidget, initialisés à "" avec un fond blanc
    for(unsigned int counter = 0; counter < dimension->value(); ++counter) {
        depart->setColumnWidth(counter, 25);
        depart->setItem(0, counter, new QTableWidgetItem(""));
        depart->item(0, counter)->setBackgroundColor("white");
        depart->item(0, counter)->setTextColor("white");
    }
    connect(depart, SIGNAL(doubleClicked(QModelIndex)), this,
            SLOT(cellActivation(QModelIndex)));
    couche->addWidget(depart);


    if(grids!=nullptr){
        delete grids;
    }


    grids = new QTableWidget(nb_step->value(), dimension->value(), this);
    grids->setFixedSize(dimension->value()*25,nb_step->value()*25);
    grids->horizontalHeader()->setVisible(false);
    grids->verticalHeader()->setVisible(false);
    grids->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    grids->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    grids->setEditTriggers(QAbstractItemView::NoEditTriggers); // désactive la modification par l'utilisateur
    // on va créer les items, on utilise 2 boucles car on parcourt un tableau 2 dimensions
    for(unsigned int ligne = 0; ligne < nb_step->value(); ++ligne) {
        // fixe les dimensions des lignes et des colonnes
        grids->setRowHeight(ligne, 25);
        for(unsigned int colonne = 0; colonne < dimension->value(); ++colonne) {
            grids->setColumnWidth(colonne, 25);
            grids->setItem(ligne, colonne, new QTableWidgetItem(""));
            grids->item(ligne, colonne)->setBackgroundColor("white");
            grids->item(ligne, colonne)->setTextColor("white");
        }
    }
    couche->addWidget(grids);

}


void AutoCellElem::symmetricVGrid(){
    this->newGrid();
    Grid g(1,dimension->value(),2);
    SymmetricVGridGenerator gridGenerator;
    g.executeGridGenerator(gridGenerator);
    for(unsigned int j = 0; j < dimension->value(); ++j) {
        if(g.getCell(0,j)== 1){
             depart->item(0, j)->setText("_");
             depart->item(0, j)->setBackgroundColor("black");
             depart->item(0, j)->setTextColor("black");
         } else {
             depart->item(0, j)->setText("");
             depart->item(0, j)->setBackgroundColor("white");
             depart->item(0, j)->setTextColor("white");
         }
    }
}

void AutoCellElem::randomGrid(){
    this->newGrid();
    Grid g(1,dimension->value(),2);
    RandomGridGenerator gridGenerator;
    g.executeGridGenerator(gridGenerator);
    for(unsigned int j = 0; j < dimension->value(); ++j) {
        if(g.getCell(0,j)== 1){
             depart->item(0, j)->setText("_");
             depart->item(0, j)->setBackgroundColor("black");
             depart->item(0, j)->setTextColor("black");
         } else {
             depart->item(0, j)->setText("");
             depart->item(0, j)->setBackgroundColor("white");
             depart->item(0, j)->setTextColor("white");
         }
    }
}

void AutoCellElem::cellActivation(const QModelIndex& index) {
    if(stepSimulation==false && playSimulation==false){
        if (depart->item(0, index.column())->text() == "") {
            depart->item(0, index.column())->setText("_");
            depart->item(0, index.column())->setBackgroundColor("black");
            depart->item(0, index.column())->setTextColor("black");
        } else {
            depart->item(0, index.column())->setText("");
            depart->item(0, index.column())->setBackgroundColor("white");
            depart->item(0, index.column())->setTextColor("white");
        }
    }
}

void AutoCellElem::synchronizeNumToNumBit(int i) {
    std::string numBit = num2bits(i);
    for(unsigned int counter = 0; counter < 8; ++counter) {
        numeroBit[counter]->setText(QString(numBit[counter]));
    }
}

void AutoCellElem::synchronizeNumBitToNum(const QString& s) {
    if (s == "") {
        return;
    }
    std::string numBit = "";
    for(unsigned int counter = 0; counter < 8; ++counter) {
        numBit += numeroBit[counter]->text().toStdString();
    }
    num->setValue(bits2num(numBit));
}

void AutoCellElem::launchSimulation() {
    playSimulation=true;
    // création de l'état
    Grid grille(1,dimension->value(),2);
    // on récupère les données de l'état de l'interface graphique pour que ça corresponde à l'objet qu'on vient de créer
    for(unsigned int counter =  0; counter < dimension->value(); ++counter) {
        if(depart->item(0, counter)->text() != "") {
                grille.setCell(0,counter,1);
        }
    }

    ElementaryAutomaton ea(num->value());
    // on construit l'objet simulateur correspondant
    if(stepSimulation){
        Simulator::freeInstance();
        stepSimulation=false;
        if(grids!=nullptr){
            delete grids;
        }

        grids = new QTableWidget(nb_step->value(), dimension->value(), this);
        grids->setFixedSize(dimension->value()*25,nb_step->value()*25);
        grids->horizontalHeader()->setVisible(false);
        grids->verticalHeader()->setVisible(false);
        grids->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grids->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grids->setEditTriggers(QAbstractItemView::NoEditTriggers); // désactive la modification par l'utilisateur
        // on va créer les items, on utilise 2 boucles car on parcourt un tableau 2 dimensions
        for(unsigned int ligne = 0; ligne < nb_step->value(); ++ligne) {
            // fixe les dimensions des lignes et des colonnes
            grids->setRowHeight(ligne, 25);
            for(unsigned int colonne = 0; colonne < dimension->value(); ++colonne) {
                grids->setColumnWidth(colonne, 25);
                grids->setItem(ligne, colonne, new QTableWidgetItem(""));
                grids->item(ligne, colonne)->setBackgroundColor("white");
                grids->item(ligne, colonne)->setTextColor("white");
            }
        }
        couche->addWidget(grids);
    }
    Simulator* sim = &(Simulator::getSimulator(ea,grille,nb_step->value()));

    // on applique les transitions au simulateur en affichant le résultat dans l'interface graphique
    for(unsigned int step = 0; step < nb_step->value(); ++step) {
        // on applique la transition
        sim->next();
        // on récupère le dernier état
        const Grid& g = sim->last();
        // on l'affiche
        for(unsigned int colonne = 0; colonne < dimension->value(); ++colonne) {
            if (g.getCell(0,colonne) == 1) {
                grids->item(step, colonne)->setText("_");
                grids->item(step, colonne)->setBackgroundColor("black");
                grids->item(step, colonne)->setTextColor("black");
            } else {
                grids->item(step, colonne)->setText("");
                grids->item(step, colonne)->setBackgroundColor("white");
                grids->item(step, colonne)->setTextColor("white");
            }
        }
    }
}


void AutoCellElem::launchSimulationStep() {
    stepSimulation=true;
    // création de l'état
    Grid grille(1,dimension->value(),2);
    // on récupère les données de l'état de l'interface graphique pour que ça corresponde à l'objet qu'on vient de créer
    for(unsigned int counter =  0; counter < dimension->value(); ++counter) {
        if(depart->item(0, counter)->text() != "") {
                grille.setCell(0,counter,1);
        }
    }
    ElementaryAutomaton ea(num->value());
    // on construit l'objet simulateur correspondant
    if(playSimulation){
        Simulator::freeInstance();
        playSimulation=false;
        if(grids!=nullptr){
            delete grids;
        }
        grids = new QTableWidget(nb_step->value(), dimension->value(), this);
        grids->setFixedSize(dimension->value()*25,nb_step->value()*25);
        grids->horizontalHeader()->setVisible(false);
        grids->verticalHeader()->setVisible(false);
        grids->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grids->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grids->setEditTriggers(QAbstractItemView::NoEditTriggers); // désactive la modification par l'utilisateur
        // on va créer les items, on utilise 2 boucles car on parcourt un tableau 2 dimensions
        for(unsigned int ligne = 0; ligne < nb_step->value(); ++ligne) {
            // fixe les dimensions des lignes et des colonnes
            grids->setRowHeight(ligne, 25);
            for(unsigned int colonne = 0; colonne < dimension->value(); ++colonne) {
                grids->setColumnWidth(colonne, 25);
                grids->setItem(ligne, colonne, new QTableWidgetItem(""));
                grids->item(ligne, colonne)->setBackgroundColor("white");
                grids->item(ligne, colonne)->setTextColor("white");
            }
        }
        couche->addWidget(grids);
    }
    Simulator* sim = &(Simulator::getSimulator(ea,grille,nb_step->value()));
    // on applique la transition
    sim->next();
    // on récupère le dernier état
    const Grid& g = sim->last();
    // on l'affiche
    for(unsigned int colonne = 0; colonne < dimension->value(); ++colonne) {
        if (g.getCell(0,colonne) == 1) {
            grids->item((sim->getCurRank()-1)%nb_step->value(), colonne)->setText("_");
            grids->item((sim->getCurRank()-1)%nb_step->value(), colonne)->setBackgroundColor("black");
            grids->item((sim->getCurRank()-1)%nb_step->value(), colonne)->setTextColor("black");
        } else {
            grids->item((sim->getCurRank()-1)%nb_step->value(), colonne)->setText("");
            grids->item((sim->getCurRank()-1)%nb_step->value(), colonne)->setBackgroundColor("white");
            grids->item((sim->getCurRank()-1)%nb_step->value(), colonne)->setTextColor("white");
        }
    }
}

