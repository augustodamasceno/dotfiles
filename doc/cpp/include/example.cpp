/**
 * @file example.cpp
 * @brief Dot Files — C++ example to test the dotfiles documentation pipeline.
 *
 * @details
 * Covers free functions, enums, structs, classes, templates, typedefs, and
 * macros so every section of the generated Markdown output can be exercised.
 *
 * @author Augusto Damasceno
 * @copyright BSD-2-Clause. See https://github.com/augustodamasceno/dotfiles
 */

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

/// @brief Maximum number of items the demo container will hold.
#define DEMO_MAX_ITEMS 64

/**
 * @brief Top-level namespace for all example entities.
 *
 * @details
 * Everything lives here to exercise the Namespaces section of the generated
 * documentation.
 */
namespace demo {

/**
 * @brief Severity levels used in logging.
 *
 * @details
 * Ordered from least to most severe. Use @ref LogLevel::Fatal only when the
 * process cannot continue.
 */
enum class LogLevel {
    Debug,   ///< Verbose diagnostic information.
    Info,    ///< General informational messages.
    Warning, ///< Potentially harmful situations.
    Error,   ///< Error events that might still allow the application to run.
    Fatal    ///< Severe errors that cause premature termination.
};

/**
 * @brief Colour channels supported by the image codec.
 */
enum class Channel : uint8_t {
    Red   = 0, ///< Red channel (index 0).
    Green = 1, ///< Green channel (index 1).
    Blue  = 2, ///< Blue channel (index 2).
    Alpha = 3  ///< Alpha (opacity) channel (index 3).
};

/// @brief Convenience alias for a vector of strings.
using StringList = std::vector<std::string>;

/**
 * @brief Immutable 2-D point in floating-point space.
 *
 * @tparam T Numeric type for the coordinates (default: `double`).
 */
template <typename T = double>
struct Point {
    T x; ///< Horizontal coordinate.
    T y; ///< Vertical coordinate.

    /**
     * @brief Construct a point at (x, y).
     * @param x Horizontal coordinate.
     * @param y Vertical coordinate.
     */
    Point(T x, T y) : x(x), y(y) {}

    /**
     * @brief Compute the squared distance to another point.
     *
     * @details
     * Uses squared distance to avoid the cost of `std::sqrt` when only
     * relative ordering is required.
     *
     * @param other The target point.
     * @return Squared Euclidean distance.
     *
     * @par Example
     * @code{.cpp}
     * Point<> a{0.0, 0.0};
     * Point<> b{3.0, 4.0};
     * double d2 = a.distanceSquared(b);  // 25.0
     * @endcode
     */
    T distanceSquared(const Point<T>& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return dx * dx + dy * dy;
    }
};

/**
 * @brief Abstract interface for renderable objects.
 *
 * @details
 * Any object that can be drawn on screen should inherit from this class and
 * implement draw().
 *
 * @see Shape
 */
class Renderable {
public:
    virtual ~Renderable() = default;

    /**
     * @brief Draw the object to the current output surface.
     * @pure
     */
    virtual void draw() const = 0;
};

/**
 * @brief A geometric shape with a name, colour, and visibility flag.
 *
 * @details
 * Inherits @ref Renderable and adds metadata. The default colour is
 * `"white"` and the shape is visible on construction.
 *
 * @par Example
 * @code{.cpp}
 * demo::Shape circle("circle", "red");
 * circle.draw();        // prints: [draw] circle (red)
 * circle.hide();
 * circle.draw();        // prints: [hidden] circle
 * @endcode
 *
 * @see Renderable
 * @see LogLevel
 */
class Shape : public Renderable {
public:
    /**
     * @brief Construct a shape.
     * @param name  Human-readable label for the shape.
     * @param color Fill colour string (e.g. `"red"`, `"#ff0000"`).
     */
    Shape(const std::string& name, const std::string& color = "white")
        : name_(name), color_(color), visible_(true) {}

    /// @brief Returns the shape's name.
    const std::string& name() const { return name_; }

    /// @brief Returns the fill colour string.
    const std::string& color() const { return color_; }

    /// @brief Returns `true` if the shape is currently visible.
    bool isVisible() const { return visible_; }

    /// @brief Make the shape visible.
    void show() { visible_ = true; }

    /// @brief Hide the shape from the output surface.
    void hide() { visible_ = false; }

    /**
     * @brief Change the fill colour.
     * @param color New colour string.
     * @throw std::invalid_argument if @p color is empty.
     */
    void setColor(const std::string& color) {
        if (color.empty())
            throw std::invalid_argument("color must not be empty");
        color_ = color;
    }

    /**
     * @brief Draw the shape if visible.
     *
     * @details
     * Prints `[draw] <name> (<color>)` when visible, or `[hidden] <name>`
     * when the shape has been hidden with hide().
     */
    void draw() const override {
        if (visible_)
            std::cout << "[draw] " << name_ << " (" << color_ << ")\n";
        else
            std::cout << "[hidden] " << name_ << "\n";
    }

private:
    std::string name_;  ///< Shape label.
    std::string color_; ///< Fill colour.
    bool visible_;      ///< Visibility flag.
};

/**
 * @brief Return the larger of two values.
 *
 * @tparam T Any type that supports `operator>`.
 * @param a First value.
 * @param b Second value.
 * @return The greater of @p a and @p b.
 *
 * @note When @p a == @p b, @p b is returned.
 */
template <typename T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

/**
 * @brief Builds a greeting message for the given name.
 *
 * @details
 * Concatenates `"Hello, "` with the supplied name and a trailing `"!"`.
 *
 * @par Example
 * @code{.cpp}
 * std::string msg = demo::greet("World");  // "Hello, World!"
 * @endcode
 *
 * @param name The name to greet.
 * @return A greeting string in the form `"Hello, <name>!"`.
 *
 * @note An empty @p name produces `"Hello, !"`.
 */
std::string greet(const std::string& name) {
    return "Hello, " + name + "!";
}

/**
 * @brief Convert a @ref LogLevel to a human-readable string.
 *
 * @param level The log severity level.
 * @return String representation (e.g. `"Warning"`).
 *
 * @see LogLevel
 */
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

/**
 * @brief Program entry point.
 *
 * @details
 * Exercises all demo entities and prints results to standard output.
 *
 * @param argc Number of command-line arguments (unused).
 * @param argv Array of command-line argument strings (unused).
 * @return 0 on success.
 *
 * @see demo::greet()
 * @see demo::Shape
 * @see demo::LogLevel
 */
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