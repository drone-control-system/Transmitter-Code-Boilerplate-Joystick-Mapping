# 🛸 Drone Transmitter – Arduino Nano + NRF24L01

This sketch reads joystick inputs from two analog joysticks and transmits the control data wirelessly using the NRF24L01 module. The control values include **throttle**, **yaw**, **pitch**, and **roll** – essential for quadcopter flight control.

---

## 📦 Features

- Reads analog input from 4 joystick axes
- Maps each value to the ESC-friendly range (1000–2000)
- Packs control data into a structured `ControlPacket`
- Sends the packet via NRF24L01 module using the RF24 library
- Serial Monitor output for testing/debugging

---

## ⚙️ Hardware Requirements

- Arduino Nano (or Uno)
- 2x Joystick Modules (with X/Y axes) - Try the joystick (Since we haven't gotten our NRF Module (future development))
- 
- NRF24L01 Module (transmitter side)
- Capacitor (10µF–100µF) across VCC and GND of NRF
- Jumper wires, breadboard

---

## 🔌 Pin Connections

| Function        | Arduino Pin | Notes                  |
|----------------|-------------|-------------------------|
| Throttle Axis   | A0          | Joystick vertical (left stick) |
| Yaw Axis        | A1          | Joystick horizontal (left stick) |
| Pitch Axis      | A2          | Joystick vertical (right stick) |
| Roll Axis       | A3          | Joystick horizontal (right stick) |

Not Yet Since we haven't gotten our NRF Module (future development)
| NRF CE          | D9          | Connect to CE pin on NRF24L01 |
| NRF CSN         | D10         | Connect to CSN pin on NRF24L01 |
| NRF VCC         | 3.3V        | ⚠️ **Do not use 5V** |
| NRF GND         | GND         | Shared with Arduino GND |

---

## 📤 Data Packet Format

```cpp
struct ControlPacket {
  int throttle;
  int yaw;
  int pitch;
  int roll;
};
