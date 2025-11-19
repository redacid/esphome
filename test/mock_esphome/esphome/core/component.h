#pragma once
#include <cstdint>

namespace esphome {

class Component {
public:
    virtual ~Component() = default;
    virtual void setup() {}
    virtual void loop() {}
    virtual void dump_config() {}

    // Додаємо віртуальний метод get_setup_priority
    virtual float get_setup_priority() const { return 0.0f; }

    void mark_failed() {}

    void set_setup_priority(float priority) {}
    void set_update_interval(uint32_t interval) {}
};

}