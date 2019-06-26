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
        QMessageBox::warning(this, "Success", "User has found!");
    }

    else
        QMessageBox::critical(this, "Input Error", "Lines can't be empty!");
}
