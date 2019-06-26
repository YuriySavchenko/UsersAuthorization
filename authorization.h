#ifndef LOGINNING_H
#define LOGINNING_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Authorization;
}

//!
//! \brief The Authorization class\n
//! class \b Authorization allows made authorization for \a user
//! and gives all \e information about particular \a user
//!
class Authorization: public QWidget
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private:
    //!
    //! \brief ui
    //!
    Ui::Authorization *ui;

private slots:
    //!
    //! \brief processAuthorization \n
    //! slot which allows view \e information
    //! about \a user to him \n
    //!
    void processAuthorization();
};

#endif // LOGINNING_H
