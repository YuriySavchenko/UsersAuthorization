#include "registration.h"
#include "ui_registration.h"

/* implementation of basic constructor */
Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

    // connection between slots and signals
    connect(ui->pushButtonSave, SIGNAL(clicked()), this, SLOT(processRegistration()));
}

/* implementation of basic destructor */
Registration::~Registration()
{
    delete ui;
}

/* implementation of slot which allows made registration for new user */
void Registration::processRegistration()
{
    if (!ui->lineEditAge->text().isEmpty() &&
        !ui->lineEditSex->text().isEmpty() &&
        !ui->lineEditLogin->text().isEmpty() &&
        !ui->lineEditLastName->text().isEmpty() &&
        !ui->lineEditPassword->text().isEmpty() &&
        !ui->lineEditFirstName->text().isEmpty())
    {
        if (ui->lineEditAge->text().toInt())
            QMessageBox::warning(this, "Success", "Age is correct!");
        else
            QMessageBox::critical(this, "Input Error", "Age must be digit!");
    }

    else {
        QMessageBox::critical(this, "Input Error", "Lines can't be empty!");
    }
}
