#include "menu.h"
#include "ui_menu.h"
#include <QSqlQuery>
#include "store_book.h"
#include "consulta.h"
#include "cadastro_usuarios.h"
#include "alterasenha.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_consultar_acervo_clicked()
{
    Consulta c;
    c.exec();
}

void Menu::on_sair_clicked()
{
    close();
}

void Menu::on_cadastrar_livro_clicked()
{
    Store_book s;
    s.exec();
}

void Menu::on_cadastrar_usuario_clicked()
{
    Cadastro_usuarios c;
    c.exec();
}

void Menu::on_alterar_senha_clicked()
{
    AlteraSenha a;
    a.exec();
}
