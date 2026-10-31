# Custom RC Aircraft System (Arduino Nano & NRF24L01)
A custom-built remote-controlled airplane made from scratch using 5mm sun Board runs on an srduino sano uses an NRF24L01 radio module for communication. The plane has a 3-channel control system that manages throttle through a brushed ESC via ailerons and pitch using the elevator. Everything is controlled from a hand-built ground station transmitter.

## Project Motivation

Most people jump into this hobby using made radio systems and foam planes i wanted to build everything from the ground up by designing both the aircraft and the transmitter by my self  learned how flight dynamics work , how wireless radios communicate , how microcontroller firmware operates , how to model parts in CAD and how to cut boards by hand i also got experience with power distribution , signal routing and fixing hardware problems during test flights.  

## Receiver circuit and CAD

| Component | Pin | Connected To | 
| :-- | :-- | :-- |
| **NRF24L01** | VCC / VSS | Arduino 3.3V |
| **NRF24L01** | GND | Arduino GND |
| **NRF24L01** | CE | Arduino D7 |
| **NRF24L01** CSN | Arduino D8 |
| **NRF24L01** | MOSI | Arduino D11 |
| **NRF24L01** | MISO | Arduino D12 |
| **NRF24L01** | SCK | Arduino D13 |
| **Aileron Servo** | Signal | Arduino D2 |
| **Aileron Servo** |+/-| 5V Rail / GND |
| **Elevator Servo** | Signal | Arduino D4 |
| **Elevator Servo** |+/-| 5V Rail / GND |
| **Brushless ESC** | Signal | Arduino D5 |
| **Brushed ESC** | BEC Red | Arduino 5V |
|**Brushed ESC** | BEC Black | Arduino GND |

## Transmitter circuit and CAD

| Component | Pin| Connected To |
| :-- | :-- | :-- |
| **NRF24L01** | VCC/VSS | Arduino 3.3V |
| **NRF24L01** | GND | Arduino GND |
| **NRF24L01** | CE | Arduino D7 |
| **NRF24L01** CSN | Arduino D8 |
| **NRF24L01** | MOSI | Arduino D11 |
| **NRF24L01** | MISO | Arduino D12 |
| **NRF24L01** | SCK | Arduino D13 |
| **Right Joystick (J1)** | VRX | Arduino A1 |
| **Right Joystick (J1)** | VRY Arduino A2 |
| **Right Joystick (J1)** | VCC / GND 5V / GND Rail |
| **Left Joystick (J2)** | VRY Arduino A0 |
| **Left Joystick (J2)** | VCC / GND 5V / GND Rail |

## Airframe dimensions and CAD

| Component | Material | Dimension |
| :-- | :-- | :--
| **Fuselage Sides** | 5mm Sun Board 48 cm length |
| **Main Wing Panel** | 5mm Sun Board 53 cm wingspan, 8 cm root chord |
| **Horizontal Stabilizer** | 5mm Sun Board 25 cm span |
| **Vertical Fin** | 5mm Sun Board | 9–10 cm height |

### Control Surface & Hardware Setup

* I cut custom slots in the fuselage to hold two SG90 micro servos. I attached linkages stopper and push rods to the control horns on the ailerons and elevator.

* The 555 motor slide to the nose plate and power wires flow to the 30A ESC , which is mounted on the side wall.

* I placed the 7.4V LiPo battery far forward as possible to keep the center of gravity balanced for stable flight.

### Electronics Assembly Notes

* I soldered socket pins onto a pcb so the Arduino Nano and NRF24L01 could be inserted and removed without soldering.

* I added a 100uF capacitor across the power pins of the NRF24 module to prevent voltage drops.

* All the joystick pots, power input and radio output were wired inside the transmitter box.

## Firmware Setup

* Install the Arduino IDE.

* Use the built-in library manager to install the **RF24** library by TMRh20.

### Upload Procedure

Connect the transmitter Arduino Nano to your PC using USB.

in the Arduino IDE select Arduino Nano as the board Transmitter.ino` choose the correct COM port and click Upload.

swap the Nano board with the unit.

Open `Receiver.ino` confirm the board is correct and upload the code.

## Bill of Materials (BOM)

| Item | Quantity | Aprox. Cost | Link/Source |

| :-- | :-- | :-- | :--
| **Arduino Nano** 2 | | |
| **NRF24L01 Transceiver** 2 | | |
| **A2212 Brushless Motor** 1 | | |
| **30A Brushless ESC** 1 | | |
| **2S LiPo Battery (7.4V 2200 mAh)** 1 | | |
| **SG90 / MG90S Micro Servos** 2 | | |
| **2-Axis Joystick Modules** 2 | | |
| **Sun Board (5mm)** | 1 Sheet | | |
| **100uF Capacitors** 2 | | |
| **Hardware & Linkages (Pushrods, Horns, Wires)** 1 Set | | |

## Hard Lessons & Practical Fixes

* **Sun Board Snapping:** The 5mm Sun Board is strong under stress but it breaks very hard  at joints when it takes a hard hit nose dives often tear the glue points apart and this made my aircraft to fall off and everything snapped where ever possible.  

* **NRF Voltage Limits:** The NRF24L01 only works at 3.3V. powering it 5V will destroy it instantly(like i did) use 3.3V with capacitors for signal loss.

* **Transmitter Antenna Warning:** Never turn on the NRF module without attaching the antenna without the antenna the this will burn the modeul.
  
* **Power Dip Resets:** When both servos move at speed the power draw can cause the 5V line to drop below 4.2V which  resets the microcontroller add capacitors to avoid these brownouts.
