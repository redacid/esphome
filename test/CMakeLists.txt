cmake_minimum_required(VERSION 3.16)

project(rfm69_test)

# Встановлюємо C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Шляхи до заголовкових файлів
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/../components/rfm69
        ${CMAKE_CURRENT_SOURCE_DIR}/mock_esphome
)

# Додаємо mock SPI source
add_library(mock_spi
        mock_esphome/esphome/components/spi/spi.cpp
)

# Створюємо виконуваний файл для тестування
add_executable(rfm69_test
        main.cpp
        ../components/rfm69/rfm69.cpp
)

# Лінкуємо mock бібліотеки
target_link_libraries(rfm69_test mock_spi)