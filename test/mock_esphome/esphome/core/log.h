#pragma once
#include <cstdio>

#define ESP_LOGCONFIG(tag, format, ...) printf("[CONFIG][%s] " format "\n", tag, ##__VA_ARGS__)
#define ESP_LOGI(tag, format, ...) printf("[INFO][%s] " format "\n", tag, ##__VA_ARGS__)
#define ESP_LOGE(tag, format, ...) printf("[ERROR][%s] " format "\n", tag, ##__VA_ARGS__)
#define ESP_LOGD(tag, format, ...) printf("[DEBUG][%s] " format "\n", tag, ##__VA_ARGS__)
#define ESP_LOGW(tag, format, ...) printf("[WARN][%s] " format "\n", tag, ##__VA_ARGS__)