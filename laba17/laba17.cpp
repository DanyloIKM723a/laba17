#include <iostream>
#include <cmath>

class Vector3D {
public:
    double x1, y1, z1, x2, y2, z2;

    Vector3D(double _x1, double _y1, double _z1, double _x2, double _y2, double _z2)
        : x1(_x1), y1(_y1), z1(_z1), x2(_x2), y2(_y2), z2(_z2) {}

    double length() const {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    }
};

class DerivedVector : public Vector3D {
public:
    DerivedVector(double _x1, double _y1, double _z1, double _x2, double _y2, double _z2)
        : Vector3D(_x1, _y1, _z1, _x2, _y2, _z2) {}

    double dotProduct() const {
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
    }

    double vectorLength() const {
        return length();
    }

    double cosine() const {
        return dotProduct() / (vectorLength() * vectorLength());
    }
};

int main() {
    DerivedVector v(0, 0, 0, 3, 4, 5);

    std::cout << "Vector length: " << v.vectorLength() << std::endl;
    std::cout << "Dot product: " << v.dotProduct() << std::endl;
    std::cout << "Cosine of the angle between vectors: " << v.cosine() << std::endl;

    return 0;
}
