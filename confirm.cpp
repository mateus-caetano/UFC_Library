#include "confirm.h"
#include "ui_confirm.h"
#include <QSqlQuery>

Confirm::Confirm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Confirm)
{
    ui->setupUi(this);
}

Confirm::~Confirm()
{
    delete ui;
}

void Confirm::on_confirmar_clicked()
{
    QString nome;
    QString senha;
    QSqlQuery query;
//    query.prepare("INSERT INTO  ")
}
