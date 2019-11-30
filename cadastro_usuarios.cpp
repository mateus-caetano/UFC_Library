#include "cadastro_usuarios.h"
#include "ui_cadastro_usuarios.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

Cadastro_usuarios::Cadastro_usuarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cadastro_usuarios)
{
    ui->setupUi(this);
}

Cadastro_usuarios::~Cadastro_usuarios()
{
    delete ui;
}

void Cadastro_usuarios::on_salvar_clicked()
{
    QString mat = ui->mat->text();
    QString nome = ui->nome->text();
    QString senha = ui->senha->text();
    QSqlQuery query;
    query.prepare("INSERT INTO usuarios (mat, nome, senha) VALUES"
                  " ('"+mat+"', '"+nome+"', '"+senha+"')");

    if(query.exec()){
        QMessageBox::information(this, "Cadastro", "Cadastro feito com sucesso!");
    }
    else {
        QMessageBox::information(this, "Cadastro", "Erro");
    }
    close();
}
