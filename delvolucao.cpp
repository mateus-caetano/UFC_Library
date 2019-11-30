#include "delvolucao.h"
#include "ui_delvolucao.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

Delvolucao::Delvolucao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delvolucao)
{
    ui->setupUi(this);
}

Delvolucao::~Delvolucao()
{
    delete ui;
}

void Delvolucao::on_devolver_clicked()
{
    QSqlQuery q;
    QString id_livro, mat_aluno;

    id_livro = ui->id->text();
    mat_aluno = ui->mat->text();
    qDebug() << id_livro;
    qDebug() << mat_aluno;

    q.prepare("DELETE FROM aluguel WHERE id_livro='" + id_livro + "' AND mat_usuario='" + mat_aluno + "'");
    if(q.exec()){
        QMessageBox::information(this, "delete", "deleção realizada com sucesso");
        close();
    }
    else{
        QMessageBox::information(this, "erro", "deleção não realizada");
        close();
    }

}
