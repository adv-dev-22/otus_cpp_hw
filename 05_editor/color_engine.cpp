#include "color_engine.h"
#include <iostream>

namespace GraphicalEditorCore {

constexpr uint8_t color_index<RgbColor::Red>::value() {
    return 0;
}

constexpr uint8_t color_index<RgbColor::Green>::value() {
    return 1;
}

constexpr uint8_t color_index<RgbColor::Blue>::value() {
    return 2;
}

ColorEngineUniform::ColorEngineUniform():
ColorEngineBase(),
rgb_color_{0, 0, 0} {
    std::cout << "ColorEngineUniform default ctor" << std::endl;
}

ColorEngineUniform::ColorEngineUniform(const uint8_t r, const uint8_t g, const uint8_t b):
ColorEngineBase(),
rgb_color_{r, g, b} {
    std::cout << "ColorEngineUniform {r,g,b} ctor" << std::endl;
}

ColorEngineUniform::ColorEngineUniform(const ColorEngineUniform & rhs):
ColorEngineBase(),
rgb_color_{
    rhs.rgb_color_[color_index<RgbColor::Red>::value()],
    rhs.rgb_color_[color_index<RgbColor::Green>::value()],
    rhs.rgb_color_[color_index<RgbColor::Blue>::value()]} {

    std::cout << "ColorEngineUniform copy ctor" << std::endl;
}

ColorEngineUniform & ColorEngineUniform::operator = (const ColorEngineUniform & rhs) {

    std::cout << "ColorEngineUniform assignment operator" << std::endl;

    if (&rhs != this) {

        const auto ir = color_index<RgbColor::Red>::value();
        const auto ig = color_index<RgbColor::Green>::value();
        const auto ib = color_index<RgbColor::Blue>::value();

        rgb_color_[ib] = rhs.rgb_color_[ib];
        rgb_color_[ir] = rhs.rgb_color_[ir];
        rgb_color_[ig] = rhs.rgb_color_[ig];
    }

    return *this;
}

// virtual
uint8_t ColorEngineUniform::red(const size_t /*unused*/, const size_t /*unused*/) const {
    return rgb_color_[color_index<RgbColor::Red>::value()];
}

//virtual
uint8_t ColorEngineUniform::green(const size_t /*unused*/, const size_t /*unused*/) const {
    return rgb_color_[color_index<RgbColor::Green>::value()];
}

//virtual
uint8_t ColorEngineUniform::blue(const size_t /*unused*/, const size_t /*unused*/) const {
    return rgb_color_[color_index<RgbColor::Blue>::value()];
}

void ColorEngineUniform::append(std::ofstream & ofs) const {

    // TODO:
    // write its type
    // write necessary data
}

ColorEngineLinearGradient::ColorEngineLinearGradient():
ColorEngineBase() {

}

//virtual
uint8_t ColorEngineLinearGradient::red(const size_t /*i_x*/, const size_t /*j_y*/) const {
    return 0;
}

//virtual
uint8_t ColorEngineLinearGradient::green(const size_t /*i_x*/, const size_t /*j_y*/) const {
    return 0;
}

//virtual
uint8_t ColorEngineLinearGradient::blue(const size_t /*i_x*/, const size_t /*j_y*/) const {
    return 0;
}

void ColorEngineLinearGradient::append(std::ofstream & ofs) const {

    // TODO:
    // write its type
    // write necessary data
}


} // End of namespace GraphicalEditorCore

// End of the file
