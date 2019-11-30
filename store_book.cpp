#include "store_book.h"
#include "ui_store_book.h"
#include <QSqlQuery>

Store_book::Store_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Store_book)
{
    ui->setupUi(this);
}

Store_book::~Store_book()
{
    delete ui;
}

void Store_book::on_salvar_clicked()
{
    QString titulo = ui->titulo->text();
    QString tema = ui->tema->text();
    QString autor = ui->autor->text();
    QString quantidade = ui->quantidade->text();

    QSqlQuery query;
    query.prepare("INSERT INTO livros (titulo, tema, autor, quantidade) VALUES "
                  " ('"+titulo+"', '"+tema+"', '"+autor+"', '"+quantidade+"')");

    if(query.exec()){
        QMessageBox::information(this, "Cadastro", "Cadastro realizado com sucesso!");
    } else {
        QMessageBox::information(this, "Cadastro", "Erro");
    }

    close();
}
