#ifndef ALTERASENHA_H
#define ALTERASENHA_H

#include <QDialog>

namespace Ui {
class AlteraSenha;
}

class AlteraSenha : public QDialog
{
    Q_OBJECT

public:
    explicit AlteraSenha(QWidget *parent = nullptr);
    ~AlteraSenha();

private slots:
    void on_confirmar_clicked();

private:
    Ui::AlteraSenha *ui;
};

#endif // ALTERASENHA_H
