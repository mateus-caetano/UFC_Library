#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_consultar_acervo_clicked();

    void on_sair_clicked();

    void on_cadastrar_livro_clicked();

    void on_cadastrar_usuario_clicked();

    void on_alterar_senha_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
