#ifndef CARDS_H
#define CARDS_H

#include <QWidget>

namespace Ui {
class Cards;
}

class Cards : public QWidget
{
    Q_OBJECT

public:
    explicit Cards(QWidget *parent = 0);
    ~Cards();

private slots:

    void on_close_clicked();

    void on_Cards_objectNameChanged(const QString &objectName);

private:
    Ui::Cards *ui;
};

#endif // CARDS_H
