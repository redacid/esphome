#include <iostream>
#include <memory>
#include "rfm69.h"

// Створіємо mock GPIO pin
class MockGPIOPin : public esphome::GPIOPin {
public:
    void setup() override {
        std::cout << "GPIO Pin setup called" << std::endl;
    }
    
    void digital_write(bool value) override {
        std::cout << "GPIO Pin write: " << (value ? "HIGH" : "LOW") << std::endl;
    }
    
    bool digital_read() override {
        return false;
    }
};

int main() {
    std::cout << "=== Testing ESPHome RFM69 Component ===" << std::endl;
    
    // Створюємо компонент
    esphome::rfm69::RFM69Component rfm69;
    
    // Створюємо mock піни
    auto cs_pin = std::make_shared<MockGPIOPin>();
    auto irq_pin = std::make_shared<MockGPIOPin>();
    auto rst_pin = std::make_shared<MockGPIOPin>();
    
    // Налаштовуємо компонент
    rfm69.set_cs_pin(cs_pin);
    rfm69.set_irq_pin(irq_pin);
    rfm69.set_rst_pin(rst_pin);
    rfm69.set_frequency(868.0);
    rfm69.set_network_id(100);
    rfm69.set_node_id(1);
    rfm69.set_high_power(true);
    rfm69.set_power_level(20);
    rfm69.set_aes_key("MySecretKey12345"); // 16 bytes key

    // Тестуємо setup
    std::cout << "\n--- Testing setup() ---" << std::endl;
    rfm69.setup();

    // Тестуємо dump_config
    std::cout << "\n--- Testing dump_config() ---" << std::endl;
    rfm69.dump_config();

    // Тестуємо налаштування потужності
    std::cout << "\n--- Testing power control ---" << std::endl;
    rfm69.set_tx_power_level(15);
    std::cout << "Power level: " << (int)rfm69.get_tx_power_level() << " dBm" << std::endl;
    std::cout << "Power percent: " << (int)rfm69.get_tx_power_percent() << "%" << std::endl;

    rfm69.set_tx_power_percent(75);
    std::cout << "Power level after 75%: " << (int)rfm69.get_tx_power_level() << " dBm" << std::endl;

    // Тестуємо відправку повідомлення
    std::cout << "\n--- Testing send_message() ---" << std::endl;
    bool result = rfm69.send_message(2, "Hello from RFM69!");
    std::cout << "Send message result: " << (result ? "SUCCESS" : "FAILED") << std::endl;

    // Тестуємо відправку бінарних даних
    uint8_t binary_data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    result = rfm69.send_message(3, binary_data, sizeof(binary_data), true); // no ACK
    std::cout << "Send binary data result: " << (result ? "SUCCESS" : "FAILED") << std::endl;

    // Тестуємо перевірку наявності повідомлень
    std::cout << "\n--- Testing message availability ---" << std::endl;
    if (rfm69.is_message_available()) {
        uint8_t buffer[64];
        uint8_t len = rfm69.receive_message(buffer, sizeof(buffer));
        std::cout << "Received message length: " << (int)len << std::endl;
    } else {
        std::cout << "No messages available" << std::endl;
    }

    // Тестуємо режими радіо
    std::cout << "\n--- Testing radio modes ---" << std::endl;
    rfm69.standby();
    std::cout << "Radio set to standby" << std::endl;

    rfm69.sleep();
    std::cout << "Radio set to sleep" << std::endl;

    // Статистика
    std::cout << "\n--- Statistics ---" << std::endl;
    std::cout << "Packets sent: " << rfm69.get_packets_sent() << std::endl;
    std::cout << "Packets received: " << rfm69.get_packets_received() << std::endl;
    std::cout << "Packets lost: " << rfm69.get_packets_lost() << std::endl;
    
    std::cout << "\n=== Test completed successfully! ===" << std::endl;
    
    return 0;
}