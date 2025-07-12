#include "uart_read_line_sensor.h"
#include "esphome/core/log.h"

namespace esphome {
    namespace uart_read_line_sensor {
        
        static const char *const TAG = "uart_read_line_sensor";
        
        void UartReadLineTextSensor::setup() {
            ESP_LOGI(TAG, "UART Read Line Sensor initialized");
        }
        
    }  // namespace uart_read_line_sensor
}  // namespace esphome
