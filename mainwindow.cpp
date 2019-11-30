#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "mainuser.h"
//#include "variaveis.h"

//variável que representará a conexão com o banco de dados
//variável que representará o estado do banco (conectado ou desconectado)
static bool validacao;
static QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//  conexão com o banco de dados
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("library");
    db.setUserName("mateus");
    db.setPassword("mateus");

//  verifica se o banco está conctado e faz um print no prompt de acordo com o resultado
    validacao = db.open();
    if(!validacao) {
        qDebug() << "Erro database not connected";
    } else {
        qDebug() << "Database connected";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(!validacao){
        QMessageBox::information(this, "Erro", "Erro ao conectar-se ao banco de dados");
        db.close();
        close();
    }

    this->nome = ui->campo_nome->text();
    this->senha = ui->campo_senha->text();
    validar(nome, senha);
}

void MainWindow::validar(QString nome, QString senha){
    if(db.isOpen()){
        QSqlQuery query;
        query.exec("select * from usuarios where nome='" + nome + "' and senha='" + senha + "'");
        if(query.numRowsAffected() == 1){
           QMessageBox::information(this, "Validação", "Seja bem vindo, " + nome);
           if(nome=="admin"){
               Menu m;
               close();
               m.exec();
           }else{
               MainUser m(this, this->nome);
               close();
               m.exec();
           }
        }

        else {
            QMessageBox::information(this, "Validação", "Usuário ou senha inválido! \nTente novamente");
            ui->campo_nome->clear();
            ui->campo_senha->clear();
            ui->campo_nome->setFocus();
        }
    }
}
