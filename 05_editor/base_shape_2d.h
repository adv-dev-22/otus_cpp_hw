#ifndef _BASE_SHAPE_2D_H_
#define _BASE_SHAPE_2D_H_

#include <memory>

namespace GraphicalEditorCore {

template <typename T = double>
class BaseShape2D {
public:
    BaseShape2D();
    virtual ~BaseShape2D();

    virtual void rotate(const T clockwise_angle) = 0;
    virtual void move_center(const T dx, const T dy) = 0;
    virtual void move_vertex(const T dx, const T dy, const size_t index) = 0;
    virtual void scale(const T factor) = 0;

    void reset_color_engine(ColorEngineBase * );

private:
    std::unique_ptr<ColorEngineBase> uptr_color_engine_;
};

} // End of namespace GraphicalEditorCore.

#endif  // _BASE_SHAPE_2D_H_

// End of the file
