#include "Square.h"
#include <cmath>

bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    double diagonal1 = Point2D::distance(vertices[0], vertices[2]);
    double diagonal2 = Point2D::distance(vertices[1], vertices[3]);

    return (d01 == d12 && d12 == d23 && d23 == d30 && diagonal1 == diagonal2);
}

Square::Square() : Rectangle() {
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

Square::Square(const std::string &color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Vertices do not form a valid square");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Vertices do not form a valid square");
    }
    Rectangle::set_vertices(vertices);
}

void Square::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "[Square: color = " << square.color;
    out << "; v0 = " << square.vs[0];
    out << "; v1 = " << square.vs[1];
    out << "; v2 = " << square.vs[2];
    out << "; v3 = " << square.vs[3] << "]";
    return out;
}
