#include "authorization.h"
#include "ui_authorization.h"

/* implementation of basic constructor for class */
Authorization::Authorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);

    // connection between slots and signals
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(processAuthorization()));

    // setting mode for input
    this->ui->lineEditPassword->setEchoMode(QLineEdit::Password);
}

/* implementation of basic destructor */
Authorization::~Authorization()
{
    delete ui;
}

/* implementation of slot which allows made authorization for particular user */
void Authorization::processAuthorization()
{
    if (!ui->lineEditLogin->text().isEmpty() and !ui->lineEditPassword->text().isEmpty()) {
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("yourdatabase");
        db.setUserName("user");
        db.setPassword("password");
        db.open();

        QSqlQuery query = QSqlQuery(db);

        if (!query.exec("select * from QtTest"))
            QMessageBox::critical(this, "DataBase Error", "Problem with DataBase!");

        while (query.next()) {
            QString login = query.value(1).toString();
            QString password = query.value(2).toString();
            QString firstName = query.value(3).toString();
            QString lastName = query.value(4).toString();
            QString sex = query.value(5).toString();
            int age = query.value(6).toInt();

            if (ui->lineEditLogin->text() == login && ui->lineEditPassword->text() == password) {
                this->ui->lineEditFirstName->clear();
                this->ui->lineEditLastName->clear();
                this->ui->lineEditSex->clear();
                this->ui->lineEditAge->clear();

                this->ui->lineEditFirstName->insert(firstName);
                this->ui->lineEditLastName->insert(lastName);
                this->ui->lineEditSex->insert(sex);
                this->ui->lineEditAge->insert(QString::number(age));
                return;
            }
        }

        QMessageBox::critical(this, "Authorization Error", "Login or password are incorrect!");

        this->ui->lineEditFirstName->clear();
        this->ui->lineEditLastName->clear();
        this->ui->lineEditSex->clear();
        this->ui->lineEditAge->clear();
    }

    else
        QMessageBox::critical(this, "Input Error", "Lines can't be empty!");
}
