#include "mainwindow.h"
#include "ui_mainwindow.h"

/* implementation of basic constructor */
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect between signals and slots
    connect(ui->pushButtonLoginning, SIGNAL(clicked()), this, SLOT(processAuthorization()));
    connect(ui->pushButtonRegistration, SIGNAL(clicked()), this, SLOT(processRegistration()));
}

/* implementation of basic destructor */
MainWindow::~MainWindow()
{
    delete ui;
}

/* implementation of slot which allows open new window for Authorization */
void MainWindow::processAuthorization()
{
    authorization.show();
}

/* implementation of slot which allows open new window for Registration */
void MainWindow::processRegistration()
{
    registration.show();
}
