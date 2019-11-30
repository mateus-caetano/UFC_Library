#ifndef CONSULTA_H
#define CONSULTA_H

#include <QDialog>

namespace Ui {
class Consulta;
}

class Consulta : public QDialog
{
    Q_OBJECT

public:
    explicit Consulta(QWidget *parent = nullptr, QString nome = "");
    ~Consulta();

private slots:
    void on_filtro_clicked();

private:
    Ui::Consulta *ui;
};

#endif // CONSULTA_H
