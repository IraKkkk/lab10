#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

class Triangle {
public:
    virtual double calculateArea() const = 0;

    // ������� ��� ���������� ������� ������ ����������
    virtual double calculateMedian(double side1, double side2, double side3) const {
        // ��� �������� ������������� ������� ������ �� �������� �� � ������������� ����������
        return 0.5 * sqrt(2 * pow(side1, 2) + 2 * pow(side2, 2) - pow(side3, 2));
    }

    // ������� ��� ����������� ���������� �������� �� �� �������� ��������
    virtual double calculateParallelMedian(double side) const {
        return 0.5 * side;
    }
};

class TriangleByVertices : public Triangle {
private:
    double x1, y1, x2, y2, x3, y3;

public:
    TriangleByVertices(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    double calculateArea() const override {
        return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    }
};

class TriangleBySides : public Triangle {
private:
    double side1, side2, side3;

public:
    TriangleBySides(double side1, double side2, double side3)
        :side1(side1), side2(side2), side3(side3) {}

    double calculateArea() const override {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // ������� ��� ���������� ������ ��������� ����
    double calculateInradius() const {
        return calculateArea() / (0.5 * (side1 + side2 + side3));
    }

    // ������� ��� ���������� ������ ��������� ����
    double calculateCircumradius() const {
        return (side1 * side2 * side3) / (4 * calculateArea());
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double x1, y1, x2, y2, x3, y3;
    cout << "������ ���������� ������ ���������� (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    TriangleByVertices triangleVertices(x1, y1, x2, y2, x3, y3);

    double side1, side2, side3;
    cout << "������ ������� ����� ����������: ";
    cin >> side1 >> side2 >> side3;

    TriangleBySides triangleSides(side1, side2, side3);

    cout << "����� ���������� �� ���������: " << triangleVertices.calculateArea() << endl;
    cout << "����� ���������� �� ���������: " << triangleSides.calculateArea() << endl;
    cout << "������ ���������� �� ���������: " << triangleSides.calculateMedian(side1, side2, side3) << endl;
    cout << "���������� ������� ��� ���������� �� �������� " << side1 << ": "
        << triangleSides.calculateParallelMedian(side1) << endl;

    // ���������� �� �������� ������ ��������� � ��������� ���� 
    cout << "����� ��������� ����: " << triangleSides.calculateCircumradius() << endl;
    cout << "����� ��������� ����: " << triangleSides.calculateInradius() << endl;

    return 0;
}
