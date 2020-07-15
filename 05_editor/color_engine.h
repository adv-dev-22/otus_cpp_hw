#ifndef _COLOR_ENGINE_H_
#define _COLOR_ENGINE_H_

#include <cstdint>
#include <array>

namespace GraphicalEditorCore {

enum class RgbColor : uint8_t {Undefined = 0,
                               Red   = 1,
                               Green = 2,
                               Blue  = 4};
template <RgbColor>
struct color_index {
};

template <>
struct color_index<RgbColor::Red> {
    static constexpr uint8_t value();
};

template <>
struct color_index<RgbColor::Green> {
    static constexpr uint8_t value();
};

template <>
struct color_index<RgbColor::Blue> {
    static constexpr uint8_t value();
};


class ColorEngineBase {
public:
    ColorEngineBase() = default;
    virtual ~ColorEngineBase() = default;

    virtual uint8_t red  (const size_t i_x, const size_t j_y) const = 0;
    virtual uint8_t green(const size_t i_x, const size_t j_y) const = 0;
    virtual uint8_t blue (const size_t i_x, const size_t j_y) const = 0;

private:
    ColorEngineBase(const ColorEngineBase & ) = delete;
    ColorEngineBase(ColorEngineBase && ) = delete;
    ColorEngineBase & operator = (const ColorEngineBase & ) = delete;
    ColorEngineBase & operator = (ColorEngineBase && ) = delete;
};


class ColorEngineUniform final : public ColorEngineBase {
public:
    ColorEngineUniform();
    ColorEngineUniform(const uint8_t r, const uint8_t g, const uint8_t b);

    virtual ~ColorEngineUniform() = default;

    ColorEngineUniform(const ColorEngineUniform & rhs);
    ColorEngineUniform & operator = (const ColorEngineUniform & );

    virtual uint8_t red  (const size_t i_x, const size_t j_y) const override;
    virtual uint8_t green(const size_t i_x, const size_t j_y) const override;
    virtual uint8_t blue (const size_t i_x, const size_t j_y) const override;

private:
    std::array<uint8_t, 3> rgb_color_;

private:
    ColorEngineUniform(ColorEngineUniform && rhs) = delete;
    ColorEngineUniform & operator = (ColorEngineUniform && ) = delete;
};


class ColorEngineLinearGradient final : public ColorEngineBase {
public:
    ColorEngineLinearGradient();
    virtual ~ColorEngineLinearGradient() = default;

    virtual uint8_t red  (const size_t i_x, const size_t j_y) const override;
    virtual uint8_t green(const size_t i_x, const size_t j_y) const override;
    virtual uint8_t blue (const size_t i_x, const size_t j_y) const override;

    // ..
};

} // End of namespace GraphicalEditorCore.

#endif  // _COLOR_ENGINE_H_

// End of the file
