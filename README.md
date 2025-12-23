### Project Wilhelm - Motor Driver
***
Wilhelm is a ground-based ISR drone and it's drive section is controlled over UART via a Raspberry Pi Pico
***
Motor Driver Module
  The motor driver module consists of a Raspberry Pi Pico, L298N Motor Driver, and XL4015 Buck Converter
  The PCB (design below) consists of mapping Pi pins between the battery, L298N, and Buck

#### Command Format
*The commands are accepted over UART with a baudrate of 115200*
*Replace the x's with the speed (duty cycle) for PWM*
- Forward    - "FXXX"
- Backward   - "BXXX"
- Right Turn - "RXXX"
- Left Turn  - "LXXX"
- Stop       - "STOP"

***
#### System Component Design
<img width="1138" height="766" alt="Drive module 3" src="https://github.com/user-attachments/assets/61489419-c511-4a6c-8525-4e2377ad9809" />


#### Electrical Schematic
<img width="1280" height="926" alt="electr_schematic" src="https://github.com/user-attachments/assets/be979ed4-55bc-4135-8905-47f38e4747fe" />


#### PCB Layout
<img width="720" height="905" alt="pcb_layout" src="https://github.com/user-attachments/assets/ba2a8792-ef77-44a8-8edc-12b9abfcd5d2" />


#### PCB 3D View
<img width="588" height="474" alt="pcb_3d_view" src="https://github.com/user-attachments/assets/4591f329-d942-44db-8b64-e7846a1439e9" />









