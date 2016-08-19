#include "gilbertdrawer.h"
#include <QPainter>

QPixmap GilbertDrawer::getPixmap()
{
    QPainter painter;
    painter.begin(&pixmap);
    painter.fillRect(0, 0, pixmap.width(), pixmap.height(), QBrush(Qt::white));
    painter.end();
    x = step;
    y = step;

    switch(curveSide) {
    case Side::Up:      y = pixmapSize - step;  drawUp(curveDepth);       break;
    case Side::Down:    x = pixmapSize - step;  drawDown(curveDepth);     break;
    case Side::Left:    x = pixmapSize - step;  drawLeft(curveDepth);     break;
    case Side::Right:   y = pixmapSize - step;  drawRight(curveDepth);    break;
    }

    return pixmap;
}

void GilbertDrawer::drawGilbertCurve(GilbertDrawer::Side side, int depth)
{
    if (depth < 0 || depth > maxDepth)
        throw std::runtime_error{"Curve depth value out of valid range"};

    curveSide = side;
    curveDepth = depth;
}

void GilbertDrawer::setPixmapSize(int width)
{
    if (width <= 0 || width > maxPixmapSize)
        throw std::runtime_error{"Pixmap Size out of valid range"};

    pixmapSize = width;
    pixmap = QPixmap{pixmapSize, pixmapSize};
}

void GilbertDrawer::drawLine(int stepX, int stepY)
{
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(QBrush(Qt::black), 1));
    painter.drawLine(x, y, x + stepX, y + stepY);
    x += stepX;
    y += stepY;
}

void GilbertDrawer::drawUp(int depth)
{
    if (depth <= 0)
        return;

    drawRight(depth - 1);
    drawLine(0, -step);
    drawUp(depth - 1);
    drawLine(step, 0);
    drawUp(depth - 1);
    drawLine(0, step);
    drawLeft(depth - 1);
}

void GilbertDrawer::drawDown(int depth)
{
    if (depth <= 0)
        return;

    drawLeft(depth - 1);
    drawLine(0, step);
    drawDown(depth - 1);
    drawLine(-step, 0);
    drawDown(depth - 1);
    drawLine(0, -step);
    drawRight(depth - 1);
}

void GilbertDrawer::drawLeft(int depth)
{
    if (depth <= 0)
        return;

    drawDown(depth - 1);
    drawLine(-step, 0);
    drawLeft(depth - 1);
    drawLine(0, step);
    drawLeft(depth - 1);
    drawLine(step, 0);
    drawUp(depth - 1);
}

void GilbertDrawer::drawRight(int depth)
{
    if (depth <= 0)
        return;

    drawUp(depth - 1);
    drawLine(step, 0);
    drawRight(depth - 1);
    drawLine(0, -step);
    drawRight(depth - 1);
    drawLine(-step, 0);
    drawDown(depth - 1);
}
