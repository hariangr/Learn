#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    Point topLeft;
    Point topRight;
    Point bottomRight;
    Point bottomLeft;
} Rectangle;

void printKordinat(Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

void printRectangle(Rectangle r) {
    printKordinat(r.topLeft);
    printKordinat(r.topRight);
    printKordinat(r.bottomRight);
    printKordinat(r.bottomLeft);
}

Rectangle createRectangleByCorner(Point topLeft, Point bottomRight) {
    Point _upperLeft = topLeft;
    Point _upperRight = {bottomRight.x, topLeft.y};
    Point _bottomLeft = {topLeft.x, bottomRight.y};
    Point _bottomRight = bottomRight;

    Rectangle temp = {_upperLeft, _upperRight, _bottomRight, _bottomLeft};
    return temp;
}

int main() {
    Point _upperLeft = {0,2};
    Point _upperRight = {4,2};
    Point _bottomLeft = {0,0};
    Point _bottomRight = {4,0};

    Rectangle rect = {_upperLeft, _upperRight, _bottomRight, _bottomLeft};
    printRectangle(rect);

    printf("Inferred\n");
    Rectangle rect2 = createRectangleByCorner(_upperLeft, _bottomRight);
    printRectangle(rect2);
}
