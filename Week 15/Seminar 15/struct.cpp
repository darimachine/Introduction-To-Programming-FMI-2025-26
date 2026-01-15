#include <iostream>

struct Point2D {
    int x;
    int y;
};

int getLengthSquared(const Point2D& point) {
    return point.x * point.x + point.y * point.y;
}

int main() {
    Point2D point = {1, 2};

    std::cout << getLengthSquared(point) << std::endl;

    return 0;
}
