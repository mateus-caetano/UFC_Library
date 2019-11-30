#ifndef CONFIRM_H
#define CONFIRM_H

#include <QDialog>

namespace Ui {
class Confirm;
}

class Confirm : public QDialog
{
    QString nome;
    Q_OBJECT

public:
    explicit Confirm(QWidget *parent = nullptr);
    ~Confirm();

private slots:
    void on_confirmar_clicked();

private:
    Ui::Confirm *ui;
};

#endif // CONFIRM_H
