#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <optional>

// Advanced template metaprogramming challenge
template <typename T, typename = void>
class SmartContainer {
private:
    std::vector<T> data;
    
public:
    // Intentionally complex insertion with type constraints
    template <typename U = T, 
              typename = std::enable_if_t<std::is_arithmetic_v<U>>>
    void insert(U value) {
        data.push_back(static_cast<T>(value));
    }
    
    // Constrained retrieval method
    std::optional<T> get(size_t index) const {
        if (index < data.size()) {
            return data[index];
        }
        return std::nullopt;
    }
    
    // Placeholder for future advanced operations
    void advanced_transform();
};

// Base class for a polymorphic type hierarchy
class Shape {
public:
    virtual double get_area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
    
public:
    explicit Circle(double r) : radius(r) {
        if (r <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }
    
    double get_area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) {
            throw std::invalid_argument("Dimensions must be positive");
        }
    }
    
    double get_area() const override {
        return width * height;
    }
};

// Main function demonstrating complex interactions
int main() {
    // Template container with type restrictions
    SmartContainer<int> int_container;
    int_container.insert(10);
    int_container.insert(20);
    
    // Polymorphic shape management
    std::vector<std::unique_ptr<Shape>> shapes;
    
    try {
        shapes.push_back(std::make_unique<Circle>(5.0));
        shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid shape: " << e.what() << std::endl;
    }
    
    return 0;
}