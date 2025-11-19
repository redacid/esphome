#pragma once
#include <cstdint>
#include <memory>

namespace esphome {

// Mock setup_priority
namespace setup_priority {
  constexpr float DATA = 600.0f;
}

class GPIOPin {
public:
    virtual ~GPIOPin() = default;
    virtual void setup() {}
    virtual void digital_write(bool value) {}
    virtual bool digital_read() { return false; }
    virtual void pin_mode(uint8_t mode) {}

    // Методи для спільності з ESPHome
    void set_inverted(bool inverted) { inverted_ = inverted; }
    bool is_inverted() const { return inverted_; }

private:
    bool inverted_ = false;
};

using GPIOPin_t = std::shared_ptr<GPIOPin>;

// Mock функції
inline void delay(uint32_t ms) {
    // Mock delay
}

inline uint32_t millis() {
    static uint32_t counter = 0;
    return ++counter;
}

}