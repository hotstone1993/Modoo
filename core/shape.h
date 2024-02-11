#ifndef MODOO_CORE_SHAPE
#define MODOO_CORE_SHAPE

#include <vector>

namespace modoo::core {
    class Shape {
    public:
        Shape(std::initializer_list<unsigned int> lst): shapes(lst) {};
        Shape() = default;
        ~Shape() = default;

        bool operator==(const Shape& other) {
            if (shapes.size() == other.shapes.size()) {
                for(unsigned int i = 0; i < shapes.size(); ++i) {
                    if (shapes[i] != other.shapes[i]) {
                        return false;
                    }
                }
            }

            return true;
        }

        bool operator!=(const Shape& other) {
            return !(*this == other);
        }

    private:
        std::vector<unsigned int> shapes;
    };
}


#endif // MODOO_CORE_SHAPE