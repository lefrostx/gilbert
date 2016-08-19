#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawer.setPixmapSize(height());
    drawer.drawGilbertCurve(GilbertDrawer::Side::Right, 6);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPixmap pixmap = drawer.getPixmap();
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawPixmap(0, 0, pixmap.width(), pixmap.height(), pixmap);
}
