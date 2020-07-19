#ifndef _SHAPES_2D_H_
#define _SHAPES_2D_H_

#include "color_engine.h"
#include "point_2d.h"
#include <memory>
#include <map>

namespace GraphicalEditorCore {

class DocumentWriterBase;

template <typename T = double>
class BaseShape2D {
public:
    BaseShape2D(const size_t id);
    virtual ~BaseShape2D();

    virtual void rotate(const T clockwise_angle) = 0;
    virtual void moveCenter(const T dx, const T dy) = 0;
    virtual void moveVertex(const T dx, const T dy, const size_t index) = 0;
    virtual void scale(const T factor) = 0;

    void resetColorEngine(ColorEngineBase * );
    const ColorEngineBase & colorEngine() const;

    const size_t id() const noexcept;
    virtual void debug_print();

    virtual void append(DocumentWriterBase & ) const;

private:
    size_t id_;
    std::unique_ptr<ColorEngineBase> uptr_color_engine_;

private:
    BaseShape2D(const BaseShape2D & ) = delete;
    BaseShape2D(BaseShape2D && )      = delete;
    BaseShape2D & operator= (const BaseShape2D & ) = delete;
    BaseShape2D & operator= (BaseShape2D && )      = delete;
};


// Triangle
template <typename T = double>
class TriangleShape2D : public BaseShape2D<T> {
public:
    TriangleShape2D(const size_t id);
    TriangleShape2D(const size_t id,
                    const Point2D<T> & p1,
                    const Point2D<T> & p2,
                    const Point2D<T> & p3);

    virtual ~TriangleShape2D();

    virtual void rotate(const T clockwise_angle) override;
    virtual void moveCenter(const T dx, const T dy) override;
    virtual void moveVertex(const T dx, const T dy, const size_t index) override;
    virtual void scale(const T factor) override;

    virtual void debug_print() override;

    virtual void append(DocumentWriterBase & ) const override;

private:
    std::array<Point2D<T>, 3> points_2d_;

private:
    TriangleShape2D(const TriangleShape2D & ) = delete;
    TriangleShape2D(TriangleShape2D && )      = delete;
    TriangleShape2D & operator= (const TriangleShape2D & ) = delete;
    TriangleShape2D & operator= (TriangleShape2D && )      = delete;
};

// Circle
template <typename T = double>
class CircleShape2D : public BaseShape2D<T> {
public:
    CircleShape2D(const size_t id);
    virtual ~CircleShape2D();

    virtual void rotate(const T clockwise_angle) override;
    virtual void moveCenter(const T dx, const T dy) override;
    virtual void moveVertex(const T dx, const T dy, const size_t index) override;
    virtual void scale(const T factor) override;

    virtual void append(DocumentWriterBase & ) const override;

private:
    Point2D<T> center_2d_;
    T radius_;

private:
    CircleShape2D(const CircleShape2D & ) = delete;
    CircleShape2D(CircleShape2D && )      = delete;
    CircleShape2D & operator= (const CircleShape2D & ) = delete;
    CircleShape2D & operator= (CircleShape2D && )      = delete;
};

template <typename T>
class CompositeShape2D;

template <typename T>
class Shape2DContainer final {

    friend class CompositeShape2D<T>;

public:
    Shape2DContainer();
    ~Shape2DContainer();

    void add(std::unique_ptr<BaseShape2D<T>> && shape_composite_2d);
    void remove(const size_t id);

    BaseShape2D<T> & find(const size_t id);

    void append(DocumentWriterBase & ) const;

private:
    std::map<size_t, std::unique_ptr<BaseShape2D<T>>> shapes_2d_;

private:
    Shape2DContainer(const Shape2DContainer & );
    Shape2DContainer(Shape2DContainer && );
    Shape2DContainer & operator= (const Shape2DContainer & );
    Shape2DContainer & operator= (Shape2DContainer && );
};

template <typename T>
class CompositeShape2D : public BaseShape2D<T> {
public:
    CompositeShape2D(const size_t id);
    virtual ~CompositeShape2D();

    void add(std::unique_ptr<BaseShape2D<T>> && shape_composite_2d);
    BaseShape2D<T> & shape2d(const size_t id);

    virtual void rotate(const T clockwise_angle) override;
    virtual void moveCenter(const T dx, const T dy) override;
    virtual void moveVertex(const T dx, const T dy, const size_t index) override;
    virtual void scale(const T factor) override;

    virtual void append(DocumentWriterBase & ) const override;

private:
    //std::map<size_t, std::unique_ptr<BaseShape2D<T>>> shapes_2d_;
    Shape2DContainer<T> shapes_2d_;

private:
    CompositeShape2D(const CompositeShape2D & );
    CompositeShape2D(CompositeShape2D && );
    CompositeShape2D & operator= (const CompositeShape2D & );
    CompositeShape2D & operator= (CompositeShape2D && );
};


} // End of namespace GraphicalEditorCore.

#endif  // _SHAPES_2D_H_

// End of the file
