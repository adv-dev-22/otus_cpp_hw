#include "color_engine.h"

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

}

ColorEngineUniform::ColorEngineUniform(const uint8_t r, const uint8_t g, const uint8_t b):
ColorEngineBase(),
rgb_color_{r, g, b} {

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

} // End of namespace GraphicalEditorCore

// End of the file
