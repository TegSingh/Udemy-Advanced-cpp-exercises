#include <iostream>
using namespace std;

// Make this class abstract coz the shape class does not have any significance by itself. It will have certain functions whose implementations we can provide
class Shape {
    virtual void setX(int xcor) = 0; // Method made abstract by initializing to 0
    virtual void setY(int xcor) = 0;
    virtual int getX() const = 0; // const added so the function definition does not modify the class variables [obj conf]
    virtual int getY() const = 0;
    virtual void draw() const = 0;
};

// Create derived classes
class Circle : public Shape {
    private:
        int x, y, radius;
    public: 
        Circle (int xcor, int ycor, int r) {
            x = xcor; 
            y = ycor;
            radius = r;
        }
        virtual void setX (int xcor) {
            x = xcor;
        }
        virtual void setY (int ycor) {
            y = ycor;
        }
        // Since only the circle shape will have radius no need to make this virtual
        void setRadius(int r) {
            radius = r;
        }
        virtual int getX() const {
            return x;
        }
        virtual int getY() const {
            return y;
        }
        virtual int getRadius() const {
            return radius;
        }
        virtual void draw() const {
            cout << "Drawing circle at: " << getX() << ", " << getY() << ", with a radius of " << getRadius() << endl; 
        }
};

int main() {
    
    Circle c1(2, 2, 3);
    c1.draw();
    return 0;
}