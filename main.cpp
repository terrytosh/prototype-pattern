#include <iostream>
#include <vector>

class Shape {
public:
    virtual ~Shape() {}
    virtual Shape* clone() const = 0;
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    Shape* clone() const override {
        Shape* obj = new Rectangle(width, height);
        return obj;
    }
};

class Square : public Shape {
private:
    int length;

public:
    Square(int l) : length(l) {}

    int getLength() const {
        return length;
    }

    Shape* clone() const override {
        Shape* obj = new Square(length);
        return obj;
    }
};

class Test {
public:
    std::vector<Shape*> cloneShapes(const std::vector<Shape*>& shapes) {
        std::vector<Shape*> output;
        for (int i = 0; i < shapes.size(); i++) {
            output.push_back(shapes[i]->clone());
        }
        return output;
    }
};

int main() {
    Shape* square = new Square(10); // 10 is the length
    Shape* anotherSquare = square->clone(); // Clone with length 10
    if (square == anotherSquare) { 
        std::cout << "True" << std::endl;
    }                                       // Output: "False"
    else {
        std::cout << "False" << std::endl;
    }

    Shape* rectangle = new Rectangle(10, 20); // 10 is width, 20 is height
    Shape* anotherRectangle = rectangle->clone(); // Clone with width 10 and height 20
    if (rectangle == anotherRectangle) {
        std::cout << "True" << std::endl;
    }                                       // Output: "False"
    else {
        std::cout << "False" << std::endl;
    }
        
    return 0;
}