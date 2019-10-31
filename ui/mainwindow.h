#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLineEdit>
#include <QString>
#include <QGridLayout>
#include <QMessageBox>
#include <string.h>
#include <QDebug>
#include <unistd.h>
#include <QPixmap>
#include <QVector>
#include <vector>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_leaveButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
