#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

#include "authorization.h"
#include "registration.h"

namespace Ui {
class MainWindow;
}

//!
//! \brief The MainWindow class \n
//! class \b MainWindow presents window
//! with two \e buttons: \n
//! \e first - Authorization \n
//! \e second - Registration \n
//! \b Authorization allows for \a user see
//! all information about him. \n
//! \b Registration allows for \a user
//! made new \a account for next using.
//!
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    Authorization authorization;    //!< A \e variable which presents \a class for \b Authorization
    Registration registration;      //!< A \e variable which presents \a class for \b Registration

public slots:
    void processAuthorization();    //!< A \e slot for processing of \a Authorization
    void processRegistration();     //!< A \e slot for processing of \a Registration
};

#endif // MAINWINDOW_H
