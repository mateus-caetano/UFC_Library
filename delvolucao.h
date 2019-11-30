#ifndef DELVOLUCAO_H
#define DELVOLUCAO_H

#include <QDialog>

namespace Ui {
class Delvolucao;
}

class Delvolucao : public QDialog
{
    Q_OBJECT

public:
    explicit Delvolucao(QWidget *parent = nullptr);
    ~Delvolucao();

private slots:
    void on_devolver_clicked();

private:
    Ui::Delvolucao *ui;
};

#endif // DELVOLUCAO_H
