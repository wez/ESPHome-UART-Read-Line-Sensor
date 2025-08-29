#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
    namespace uart_read_line_sensor {
        
        class UartReadLineTextSensor : public Component, public uart::UARTDevice, public text_sensor::TextSensor {
            public:
                UartReadLineTextSensor(uart::UARTComponent *parent) : uart::UARTDevice(parent) {}
                
                void setup() override;
                
                void loop() override {
                    while (available()) {
                        int byte = read();
                        switch (byte) {
                            case '\n':
                                break;
                            case '\r':
                                publish_state(m_buffer);
                                m_buffer.clear();
                                break;
                            default:
                                if (byte > 0) {
                                    m_buffer.push_back(byte);
                                }
                        }                                
                    }
                }
                
            protected:
                std::string m_buffer;
        };
    }  // namespace uart_read_line_sensor
}  // namespace esphome
