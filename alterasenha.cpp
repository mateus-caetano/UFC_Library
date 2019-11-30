#include "alterasenha.h"
#include "ui_alterasenha.h"
#include <QSqlQuery>
#include <QMessageBox>

AlteraSenha::AlteraSenha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlteraSenha)
{
    ui->setupUi(this);
}

AlteraSenha::~AlteraSenha()
{
    delete ui;
}

void AlteraSenha::on_confirmar_clicked()
{
    QString nome = "admin";
    QString atual = ui->atual->text(), nova = ui->nova->text(), confim = ui->confirm->text();
    QSqlQuery query ;
    query.prepare("SELECT * from usuarios where nome='" + nome + "' and senha='" + atual + "'");
    if(query.exec()){
        if(nova == confim){
            if(query.exec("UPDATE usuarios SET senha='" + nova + "'  WHERE nome='" + nome + "'")){
                QMessageBox::information(this, "Alteração", "Senha alterada com sucesso");
                close();
            }else{
                QMessageBox::information(this, "Alteração", "Erro ao tentar alterar a senha");
            }
        }
    }
    ui->atual->clear();
    ui->nova->clear();
    ui->confirm->clear();
    ui->atual->setFocus();
}
