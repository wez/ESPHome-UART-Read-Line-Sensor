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
                    const int max_line_length = 80;
                    static char buffer[max_line_length];
                    while (available()) {
                        if (readline(read(), buffer, max_line_length) > 0) {
                            publish_state(buffer);
                        }
                    }
                }
                
            protected:
                int readline(int readch, char *buffer, int len) {
                    static int pos = 0;
                    int rpos;
                    if (readch > 0) {
                        switch (readch) {
                            case '\n': 
                                break;
                            case '\r':
                                rpos = pos;
                                pos = 0;
                                return rpos;
                            default:
                                if (pos < len - 1) {
                                    buffer[pos++] = readch;
                                    buffer[pos] = 0;
                                }
                        }
                    }
                    return -1;
                }
        };
        
    }  // namespace uart_read_line_sensor
}  // namespace esphome
