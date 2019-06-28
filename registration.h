#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Registration;
}

//!
//! \brief The Registration class \n
//! class \b Registration allows for \b users
//! to create new \a accounts for next using
//!
class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private:
    //!
    //! \brief ui
    //!
    Ui::Registration *ui;

private slots:
    //!
    //! \brief processRegistration \n
    //! slot which allows write information
    //! to \b DataBase about new \a user \n
    //!
    void processRegistration();
};

#endif // REGISTRATION_H
