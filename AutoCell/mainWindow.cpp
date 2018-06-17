#include "mainWindow.h"




MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

      //settingsFile = new QSettings(QDir::currentPath().left(1) + ":/settings.ini";

      couche = new QVBoxLayout;

      //choix = new QLabel("Veuillez choisir un type d'automate", this);
      //couche->addWidget(choix);

      elemButton = new QPushButton("Automate Elementaire", this);
      connect(elemButton, SIGNAL(clicked()), this, SLOT(openAutoElem()));
      couche->addWidget(elemButton);

      golButton = new QPushButton("Automate Game Of Life", this);
      connect(golButton, SIGNAL(clicked()), this, SLOT(openAutoGol()));
      couche->addWidget(golButton);

      quadButton = new QPushButton("Automate Quadlife", this);
      connect(quadButton, SIGNAL(clicked()), this, SLOT(openAutoQuad()));
      couche->addWidget(quadButton);

      fenetreAutomElem = new AutoCellElem;
      fenetreAutomGol = new AutoCellGol;
      fenetreAutomQl = new AutoCellQuad;
      setLayout(couche);

}

void MainWindow::openAutoElem(){
    fenetreAutomElem->show();
    this->close();
}


void MainWindow::openAutoGol(){
    fenetreAutomGol->show();
    this->close();
}


void MainWindow::openAutoQuad(){
    fenetreAutomQl->show();
    this->close();
}

void initGui(){

}
