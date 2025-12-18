### Project Wilhelm - Motor Driver
***
Wilhelm is a ground-based ISR drone and it's drive section is controlled over UART via a Raspberry Pi Pico
***

#### Command Format
Replace the x's with the speed (duty cycle) for PWM
Forward    - "FXXX"
Backward   - "BXXX"
Right Turn - "RXXX"
Left Turn  - "LXXX"
Stop       - "STOP"


The commands are accepted over UART with a baudrate of 115200

