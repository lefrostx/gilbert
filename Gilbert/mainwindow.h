#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gilbertdrawer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent * /* event */) override;

private:
    Ui::MainWindow *ui;
    GilbertDrawer drawer;
};

#endif // MAINWINDOW_H
