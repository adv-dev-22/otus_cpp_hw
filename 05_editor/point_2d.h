#ifndef _POINT_2D_H_
#define _POINT_2D_H_

namespace GraphicalEditorCore {

template <typename T>
class Point2D final {
public:
    Point2D();
    Point2D(const T x, const T y);
    ~Point2D();

    Point2D(const Point2D & rhs) noexcept;
    Point2D(Point2D && rhs_data) noexcept;

    Point2D & operator= (const Point2D & rhs) noexcept;
    Point2D & operator= (Point2D && rhs_data) noexcept;

    const T x() const noexcept;
    const T y() const noexcept;

    T & x() noexcept;
    T & y() noexcept;

private:
    T x_;
    T y_;
};

} // End of the namespace GraphicalEditorCore.

#endif  //_POINT_2D_H_

// End of the file
