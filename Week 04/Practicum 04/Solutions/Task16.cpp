#include <iostream>
#include <cmath>

double getDistanceBetweenTwoPoints(double x1, double y1, double x2, double y2) {
    double first = x1 - x2;
    double second = y1 - y2;
    return sqrt(first * first + second*second);
}

double getPerimeter(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = getDistanceBetweenTwoPoints(x1, y1, x2, y2);
    double b = getDistanceBetweenTwoPoints(x2, y2, x3, y3);
    double c = getDistanceBetweenTwoPoints(x1, y1, x3, y3);

    double perimeter = a + b + c;
    return perimeter;
}

double getArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = getDistanceBetweenTwoPoints(x1, y1, x2, y2);
    double b = getDistanceBetweenTwoPoints(x2, y2, x3, y3);
    double c = getDistanceBetweenTwoPoints(x1, y1, x3, y3);

    double semiPerimeter = (a + b + c) / 2;

    double area = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
    return area;
}

bool isInCircleWithRadius(double x1, double y1, double x2, double y2, double x3, double y3,double radius) {
    double distanceFirstVertexCenter = getDistanceBetweenTwoPoints(x1, y1, 0, 0);
    double distanceSecondVertexCenter = getDistanceBetweenTwoPoints(x2, y2, 0, 0);
    double distanceThirdVertexCenter = getDistanceBetweenTwoPoints(x3, y3, 0, 0);

    return (distanceFirstVertexCenter <= radius && 
            distanceSecondVertexCenter <= radius && 
            distanceThirdVertexCenter <= radius);
}

int main()
{
    double x1 = 1, y1 = 1;
    double x2 = 4, y2 = 1;
    double x3 = 2.5, y3 = 4;
    double radius = 5.0;

    std::cout << "Perimeter: " << getPerimeter(x1, y1, x2, y2, x3, y3) << std::endl;
    std::cout << "Area: " << getArea(x1, y1, x2, y2, x3, y3) << std::endl;
    std::cout << "Is in circle: " << std::boolalpha << isInCircleWithRadius(x1, y1, x2, y2, x3, y3, radius) << std::endl;
}

