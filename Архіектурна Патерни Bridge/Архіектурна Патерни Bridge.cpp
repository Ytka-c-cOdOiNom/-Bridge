#include <iostream>
#include <memory>
#include <windows.h>
using namespace std;

// Інтерфейс кольору
class Color {
public:
    virtual void applyColor() const = 0;
    virtual ~Color() = default;
};

// Конкретний колір: червоний
class Red : public Color {
public:
    void applyColor() const override {
        cout << "Червоний колір";
    }
};

// Конкретний колір: синій
class Blue : public Color {
public:
    void applyColor() const override {
        cout << "Синій колір";
    }
};

// Абстрактний клас форми
class Shape {
protected:
    unique_ptr<Color> color; // Композиція з інтерфейсом Color

public:
    Shape(unique_ptr<Color> color) : color(move(color)) {}
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// Конкретна форма: Коло
class Circle : public Shape {
public:
    Circle(unique_ptr<Color> color) : Shape(move(color)) {}

    void draw() const override {
        cout << "Коло, пофарбоване в ";
        color->applyColor();
        cout << endl;
    }
};

// Конкретна форма: Квадрат
class Square : public Shape {
public:
    Square(unique_ptr<Color> color) : Shape(move(color)) {}

    void draw() const override {
        cout << "Квадрат, пофарбований в ";
        color->applyColor();
        cout << endl;
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    unique_ptr<Shape> redCircle = make_unique<Circle>(make_unique<Red>());
    unique_ptr<Shape> blueSquare = make_unique<Square>(make_unique<Blue>());

    cout << "Малювання фігур з різними кольорами:" << endl;
    redCircle->draw();
    blueSquare->draw();


}
