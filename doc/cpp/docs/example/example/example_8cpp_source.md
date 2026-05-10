

# File example.cpp

[**File List**](files.md) **>** [**include**](dir_d44c64559bbebec7f509842c48db8b23.md) **>** [**example.cpp**](example_8cpp.md)

[Go to the documentation of this file](example_8cpp.md)


```C++


#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

#define DEMO_MAX_ITEMS 64

namespace demo {

enum class LogLevel {
    Debug,   
    Info,    
    Warning, 
    Error,   
    Fatal    
};

enum class Channel : uint8_t {
    Red   = 0, 
    Green = 1, 
    Blue  = 2, 
    Alpha = 3  
};

using StringList = std::vector<std::string>;

template <typename T = double>
struct Point {
    T x; 
    T y; 

    Point(T x, T y) : x(x), y(y) {}

    T distanceSquared(const Point<T>& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return dx * dx + dy * dy;
    }
};

class Renderable {
public:
    virtual ~Renderable() = default;

    virtual void draw() const = 0;
};

class Shape : public Renderable {
public:
    Shape(const std::string& name, const std::string& color = "white")
        : name_(name), color_(color), visible_(true) {}

    const std::string& name() const { return name_; }

    const std::string& color() const { return color_; }

    bool isVisible() const { return visible_; }

    void show() { visible_ = true; }

    void hide() { visible_ = false; }

    void setColor(const std::string& color) {
        if (color.empty())
            throw std::invalid_argument("color must not be empty");
        color_ = color;
    }

    void draw() const override {
        if (visible_)
            std::cout << "[draw] " << name_ << " (" << color_ << ")\n";
        else
            std::cout << "[hidden] " << name_ << "\n";
    }

private:
    std::string name_;  
    std::string color_; 
    bool visible_;      
};

template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

std::string greet(const std::string& name) {
    return "Hello, " + name + "!";
}

std::string toString(LogLevel level) {
    switch (level) {
        case LogLevel::Debug:   return "Debug";
        case LogLevel::Info:    return "Info";
        case LogLevel::Warning: return "Warning";
        case LogLevel::Error:   return "Error";
        case LogLevel::Fatal:   return "Fatal";
        default:                return "Unknown";
    }
}

} // namespace demo

int main(int argc, char* argv[]) {
    // Greeting
    std::cout << demo::greet("World") << "\n";

    // Enum → string
    std::cout << "Level: " << demo::toString(demo::LogLevel::Warning) << "\n";

    // Shape (polymorphism)
    demo::Shape circle("circle", "red");
    circle.draw();
    circle.hide();
    circle.draw();
    circle.setColor("blue");
    circle.show();
    circle.draw();

    // Template struct
    demo::Point<> a{0.0, 0.0};
    demo::Point<> b{3.0, 4.0};
    std::cout << "dist^2: " << a.distanceSquared(b) << "\n";

    // Template function
    std::cout << "max: " << demo::maxOf(3, 7) << "\n";

    return 0;
}
```


