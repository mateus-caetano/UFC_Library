#include "consulta.h"
#include "ui_consulta.h"
#include "mainwindow.h"
#include <QtSql>
#include <QMessageBox>
#include <QList>

static QString p;

Consulta::Consulta(QWidget *parent, QString nome) :
    QDialog(parent),
    ui(new Ui::Consulta)
{
    p = nome;
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from livros");
    if(query.exec()){
        int cont = 0 ;
        ui->tableWidget->setColumnCount(4);
        while(query.next()){
            ui->tableWidget->insertRow(cont);
            ui->tableWidget->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));

            QStringList list = {"id", "nome", "tema", "quantidade"} ;
            ui->tableWidget->setHorizontalHeaderLabels(list);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableWidget->verticalHeader()->setVisible(false);

        }
    }else{
        QMessageBox::information(this, "Erro", "Erro");
    }

}

Consulta::~Consulta()
{
    delete ui;
}

void Consulta::on_filtro_clicked()
{
    QSqlQuery query, q;
    QString mat_usuario, id;
    int linha;
    query.prepare("SELECT * FROM usuarios WHERE nome='" + p + "'");
    if(query.exec()){

        if(query.next()){
            mat_usuario = query.value(0).toString();
            linha = ui->tableWidget->currentRow();
            id = ui->tableWidget->item(linha, 0)->text();
            q.prepare("INSERT INTO aluguel (mat_usuario, id_livro) VALUES ('" + mat_usuario + "', '" + id + "')");
            qDebug() << id;
            qDebug() << mat_usuario ;
            if(q.exec()){
                QMessageBox::information(this, "empréstimo", "Empréstimo realizado com sucesso");
            }
            else {
                QMessageBox::information(this, "err", "deu ruim");
            }
        }
    }
}
