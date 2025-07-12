import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor, uart
from esphome.const import CONF_ID

DEPENDENCIES = ["uart"]
AUTO_LOAD = ["text_sensor"]

uart_read_line_sensor_ns = cg.esphome_ns.namespace("uart_read_line_sensor")
UartReadLineTextSensor = uart_read_line_sensor_ns.class_("UartReadLineTextSensor", text_sensor.TextSensor, cg.Component)

CONFIG_SCHEMA = text_sensor.text_sensor_schema(UartReadLineTextSensor).extend({
    # component parameters
    cv.Required("uart_id"): cv.use_id(uart.UARTComponent),
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    uart_comp = await cg.get_variable(config["uart_id"])
    var = cg.new_Pvariable(config[CONF_ID], uart_comp)
    await cg.register_component(var, config)
    await text_sensor.register_text_sensor(var, config)
