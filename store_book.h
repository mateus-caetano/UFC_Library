#ifndef STORE_BOOK_H
#define STORE_BOOK_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Store_book;
}

class Store_book : public QDialog
{
    Q_OBJECT

public:
    explicit Store_book(QWidget *parent = nullptr);
    ~Store_book();

private slots:
    void on_salvar_clicked();

private:
    Ui::Store_book *ui;
};

#endif // STORE_BOOK_H
