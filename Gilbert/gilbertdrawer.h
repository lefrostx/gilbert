#ifndef GILBERTDRAWER_H
#define GILBERTDRAWER_H

#include <QPixmap>

class GilbertDrawer {
public:

    enum class Side {
        Up,
        Down,
        Left,
        Right
    };

    void drawGilbertCurve(Side side = Side::Right, int depth = 2);
    void setPixmapSize(int width);

    QPixmap getPixmap();

    static constexpr int maxDepth = 10;
    static constexpr int maxPixmapSize = 1080;

private:
    void drawLine(int stepX, int stepY);
    void drawUp(int depth);
    void drawDown(int depth);
    void drawLeft(int depth);
    void drawRight(int depth);

    int x{step};
    int y{step};
    Side curveSide{Side::Right};
    int curveDepth{6};
    int pixmapSize{800};
    int step{10};
    QPixmap pixmap{pixmapSize, pixmapSize};
};

#endif // GILBERTDRAWER_H
