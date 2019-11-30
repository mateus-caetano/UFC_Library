#include "mainuser.h"
#include "ui_mainuser.h"
#include "consulta.h"
#include "alterasenha.h"
#include "delvolucao.h"

static QString p;

MainUser::MainUser(QWidget *parent, QString nome) :
    QDialog(parent),
    ui(new Ui::MainUser)
{
    p = nome;
    ui->setupUi(this);
}

MainUser::~MainUser()
{
    delete ui;
}

void MainUser::on_sair_clicked()
{
    close();
}

void MainUser::on_consulta_clicked()
{
    Consulta c(this, p);
    c.exec();
}

void MainUser::on_alterar_senha_clicked()
{
    AlteraSenha a;
    a.exec();
}

void MainUser::on_pushButton_clicked()
{
    Delvolucao d;
    d.exec();
}
