#ifndef MAINUSER_H
#define MAINUSER_H

#include <QDialog>

namespace Ui {
class MainUser;
}

class MainUser : public QDialog
{
    Q_OBJECT

public:
    explicit MainUser(QWidget *parent = nullptr, QString nome = "");
    ~MainUser();
    QString nome;

private slots:
    void on_sair_clicked();

    void on_consulta_clicked();

    void on_alterar_senha_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainUser *ui;
};

#endif // MAINUSER_H
