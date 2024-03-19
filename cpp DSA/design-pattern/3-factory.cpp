#include <iostream>
#include <memory>

// Abstract base class for shapes
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

// Concrete class for Circle
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

// Concrete class for Rectangle
class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

// Factory class for creating shapes
class ShapeFactory {
public:
    // Factory method to create shapes
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "Circle") {
            return std::make_unique<Circle>();
        } else if (type == "Rectangle") {
            return std::make_unique<Rectangle>();
        } else {
            std::cerr << "Invalid shape type!" << std::endl;
            return nullptr;
        }
    }
};

int main() {
    // Create Circle
    std::unique_ptr<Shape> circle = ShapeFactory::createShape("Circle");
    circle->draw();

    // Create Rectangle
    std::unique_ptr<Shape> rectangle = ShapeFactory::createShape("Rectangle");
    rectangle->draw();

    return 0;
}
