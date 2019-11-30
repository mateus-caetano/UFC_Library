#ifndef CADASTRO_USUARIOS_H
#define CADASTRO_USUARIOS_H

#include <QDialog>

namespace Ui {
class Cadastro_usuarios;
}

class Cadastro_usuarios : public QDialog
{
    Q_OBJECT

public:
    explicit Cadastro_usuarios(QWidget *parent = nullptr);
    ~Cadastro_usuarios();

private slots:
    void on_salvar_clicked();

private:
    Ui::Cadastro_usuarios *ui;
};

#endif // CADASTRO_USUARIOS_H
