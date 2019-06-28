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

    // setting mode for input
    this->ui->lineEditPassword->setEchoMode(QLineEdit::Password);
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
        if (ui->lineEditAge->text().toInt() and (ui->lineEditSex->text() == "male" or ui->lineEditSex->text() == "female")) {
            QString insert = "INSERT INTO QtTest (login, password, firstname, lastname, sex, age) ";
            QString values = "VALUES (";

            values += "\'" + ui->lineEditLogin->text() + "\', ";
            values += "\'" + ui->lineEditPassword->text() + "\', ";
            values += "\'" + ui->lineEditFirstName->text() + "\', ";
            values += "\'" + ui->lineEditLastName->text() + "\', ";
            values += "\'" + ui->lineEditSex->text() + "\', ";
            values += "\'" + ui->lineEditAge->text() + "\')";

            QSqlDatabase db;
            db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("localhost");
            db.setDatabaseName("yourdatabase");
            db.setUserName("user");
            db.setPassword("password");
            db.open();

            QSqlQuery query = QSqlQuery(db);

            if (!query.exec(insert+values))
                QMessageBox::critical(this, "DataBase Error", "Problem with DataBase!");
            else {
                QMessageBox::warning(this, "Success", "Registration has finished successfully!");
                db.close();
                this->close();
            }
        }

        else
            QMessageBox::critical(this, "Input Error", "Please write only correct data!");
    }

    else {
        QMessageBox::critical(this, "Input Error", "Lines can't be empty!");
    }
}
