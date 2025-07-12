# ESPHome UART Read Line Sensor Component

This is an ESPHome [External Component](https://esphome.io/components/external_components.html) used to create a sensor component that gets fed from a UART bus. There are some UART devices that report their state through strings on the bus while updates to this state are signaled with line breaks, like the voice chip in the [ESPVoice](https://espvoice-documentation.readthedocs.io/en/latest/introduction.html). This component allows you to define a `text_sensor` that keeps track of the most current value on any UART bus.

See `example_component1.yaml` for an example on how to use this component.
