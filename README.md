# Custom RC Aircraft System (Arduino Nano & NRF24L01)
A custom-built remote-controlled airplane made from scratch using 5mm sun Board runs on an srduino sano uses an NRF24L01 radio module for communication. The plane has a 3-channel control system that manages throttle through a brushed ESC via ailerons and pitch using the elevator. Everything is controlled from a hand-built ground station transmitter.

## Project Motivation

Most people jump into this hobby using made radio systems and foam planes i wanted to build everything from the ground up by designing both the aircraft and the transmitter by my self  learned how flight dynamics work , how wireless radios communicate , how microcontroller firmware operates , how to model parts in CAD and how to cut boards by hand i also got experience with power distribution , signal routing and fixing hardware problems during test flights.  

# CAD design
the build start from here 
<img width="2072" height="1352" alt="image" src="https://github.com/user-attachments/assets/1d4e311e-83b6-4122-a362-8afded7b7732" />
this is where the aircraft comes to live 
<img width="983" height="1280" alt="image" src="https://github.com/user-attachments/assets/089b8274-af15-4a14-9d9a-93509e971c27" />
this is final build 

the motor will slide here 
<img width="690" height="448" alt="image" src="https://github.com/user-attachments/assets/2bbf2d86-5bcb-451d-ac60-770aad9a8c08" />
and is connected to receiver

<img width="2178" height="680" alt="image" src="https://github.com/user-attachments/assets/a617a2a0-d229-4d29-a9d8-7982137de2aa" />
airframe here thw sings have two ailerons which will move simultaneously mirrored when one is up other is down same other side which will help the aircraft to turn left ad right
<img width="1182" height="624" alt="image" src="https://github.com/user-attachments/assets/527a23da-8a5f-4109-94e4-1fc5dd0e0841" />
the elevator helps the aircraft to pitch up and down 

## Receiver circuit and CAD
<img width="950" height="571" alt="Screenshot 2026-10-31 at 6 50 51 PM" src="https://github.com/user-attachments/assets/924a0c5b-9288-48d5-b8f2-ad6a76c0f9f0" />

follow this path to connect the components

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

the full assembly will look like this 

<img width="1122" height="894" alt="image" src="https://github.com/user-attachments/assets/65817fc8-89fc-4881-823e-dbd6ad0aa9c5" />
held inside an enclosure which goes on board the flight


## Transmitter circuit and CAD
the transmitter i held in a box to make this look good
<img width="1358" height="412" alt="image" src="https://github.com/user-attachments/assets/71f0960d-76e1-41ef-9dd7-98e4373cb790" />

this is the final build has screws to hold them intact here the anteena nrf module and nano is one single component after build which can be kept and removed when necessary 
<img width="521" height="393" alt="Screenshot 2026-10-31 at 6 55 05 PM" src="https://github.com/user-attachments/assets/b96e441f-0d1a-4123-94a6-4fc649f7e185" />
and batteries can be swapped 

the circuit design goes like this 

<img width="961" height="588" alt="Screenshot 2026-10-31 at 6 57 54 PM" src="https://github.com/user-attachments/assets/1c69d2b9-15d8-470f-8c80-2b8bf209a89a" />

follow this path to solder 
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

this is how the final build looks like 

<img width="900" height="1600" alt="image" src="https://github.com/user-attachments/assets/598731ea-1ebc-4019-8722-8efcc1cc200b" />

## Airframe dimensions and CAD
follow this path for measurements 
<img width="1600" height="936" alt="image" src="https://github.com/user-attachments/assets/f207d141-7970-4785-83d9-a25333a1470e" />
be carefull while cutting through sun board as you need to use very sharp knife for this.  

| Component | Material | Dimension |
| :-- | :-- | :--
| **Fuselage Sides** | 5mm Sun Board | 50 cm length |
| **Main Wing Panel** | 5mm Sun Board |53 cm wingspan, 8 cm root chord |
| **Horizontal Stabilizer** | 5mm Sun Board | 28 cm span |
| **Vertical Fin** | 5mm Sun Board | 9–10 cm height |

# What goes where

<img width="1530" height="634" alt="image" src="https://github.com/user-attachments/assets/86d32ab9-3742-4689-9a1b-c4ae094333b6" />
this is final build 

<img width="1242" height="752" alt="image" src="https://github.com/user-attachments/assets/fd42638a-f075-41b5-9758-055c0b00db03" />

keep the batteries either side to prevent the aircrft from loosing balance up in the air

<img width="864" height="378" alt="image" src="https://github.com/user-attachments/assets/7f90f642-52ba-4124-8c3a-a57ed6429d6f" />
place one servo near the elevator to help the pudh rod movement correct 

and other at middle to operate both ailerons 

<img width="478" height="294" alt="image" src="https://github.com/user-attachments/assets/d6bfdf36-86cf-415e-91d2-288671516368" />


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
| :-- | :-- | :-- | :-- |
| **Arduino Nano**| 2 | $3 | https://robocraze.com/products/nano-board-r3-compatible-with-arduino?variant=40193265533081&country=IN&currency=INR&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&utm_source=google&utm_medium=cpc&utm_campaign=BL+%7C+Pmax+%7C+Feed+Only+%7C+GR+%3E+35%25+%7C+18%2F05&utm_source=googleads&utm_medium=ppc&utm_campaign=21311497592&utm_content=_&utm_term=&campaignid=21311497592&adgroupid=&campaign=21311497592&gad_source=1&gad_campaignid=21305067285&gbraid=0AAAAADgHQvasLJjjxNagelD3NzUApo0Sp&gclid=CjwKCAjwo5bXBhAEEiwAkgpgXEpGHAlByEkQQZUrwtucBQT5YaD8XUie1MPGX5yXGlxcU5bwbR5hMhoCUvEQAvD_BwE|
| **NRF24L01 Transceiver**| 2 | $2 | https://robocraze.com/products/nrf24l01-pa-lna?variant=40192567115929&country=IN&currency=INR&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&campaignid=22114711878&adgroupid=&keyword=&device=c&gad_source=1&gad_campaignid=22124708836&gbraid=0AAAAADgHQvZI-7LO5ZmIi9OUs8pY3KI-Z&gclid=CjwKCAjwo5bXBhAEEiwAkgpgXE-Sww5F5cShQoQK800GepznglX0j2dr1A6HsUtgsXfWZuKEAd_FpBoCvGAQAvD_BwE |
| **555 Brushed Motor**| 1 | $3 | https://robu.in/product/555-front-and-rear-ball-bearing-motors-dc-24v-12v-12000rpm/?gad_source=1&gad_campaignid=20387462343&gbraid=0AAAAADvLFWd-ZnjYc328hUHn8QzjO3BmC&gclid=CjwKCAjwo5bXBhAEEiwAkgpgXDKM3rA24BDH3kmB1cCAcbmhnOGLnzy1QiweXMlubQIRwY3ShttAexoC0qUQAvD_BwE|
| **30A Brushed ESC**| 1 | $7 | https://robu.in/product/30-a-brushed-esc-no-brake/?gad_source=1&gad_campaignid=17419548928&gbraid=0AAAAADvLFWfM2rqHCxcdv4dcC75Zk0A-1&gclid=CjwKCAjwo5bXBhAEEiwAkgpgXFI6ZAn_ETnHbwuOrR5YCiNNdoQGBY2zx4c3_ayVXg3f8-aJV8XLwRoC8SYQAvD_BwE|
| **LiPo Battery (7.4V 2200 mAh)**| 1 | $1 | https://robocraze.com/products/3-7v-2000mah-18650-li-ion-battery?variant=41414818758809&country=IN&currency=INR&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&campaignid=22114711878&adgroupid=&keyword=&device=c&gad_source=1&gad_campaignid=22124708836&gbraid=0AAAAADgHQvZI-7LO5ZmIi9OUs8pY3KI-Z&gclid=CjwKCAjwo5bXBhAEEiwAkgpgXPLakO6l_WEg3begUYDkZibh-AKcboLf7YLFGEMt3WPnYrhZvlS-oRoCYeIQAvD_BwE|
| **SG90 / MG90S Micro Servos**| 2 | $3 | https://robu.in/product/mg90s-9g-servo-metal-gear/ |
| **2-Axis Joystick Modules**| 2 | $1| https://robu.in/product/joystick-module-ps2-breakout-sensor/|
| **Sun Board (5mm)** | 1 Sheet | $7 | https://www.amazon.in/Foam-Board-Sun-Thickness-Size/dp/B0F2SYL8JF/ref=sr_1_4_sspa?dib=eyJ2IjoiMSJ9.HOqEdx4RBzaMEymgqocBI6eJbkmiGxpDIvb_o6fzxxF-CMQxCdJYnegUFJcjm26W3fvcSxGimKJ_zd_OIY2QEAMnPECaldV-T2ivAIJUxHwybqXEahcS96JUPcTSbiLzwzpnokhMh30ZjVHuewts4EnHrqKAu4oRPsie7RMKVHExA8HLN4QbXsck1zM4AL_2gUwUJL5u4eZcQOrylhYpvfqWv1MV1O6YbcLUbXz12yVmyoV7XbWgOyby8uvzPsWqRyI_xmJHIKBQI5irnYok86Quhs4sH69QQxKgtr9CqQ4.wGod8QdSKQq-J9LFfgOBwRnlqlRfYb7cnGwnuSZHDoI&dib_tag=se&keywords=sun+board+sheet+5mm+large+size&qid=1793454742&sr=8-4-spons&aref=DWKzZHbagg&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1|
| **100uF Capacitors** |2 | $2 | https://robu.in/product/100uf-250v-electrolytic-capacitor-dip-pack-of-2/|
| **Hardware & Linkages (Pushrods, Horns, Wires)**| 1 Set | $10 | https://robu.in/product/d1x700mm-z-type-push-pull-steel-rod-for-rc-aircraft-aero-modelling-2pcs/|
| **Total** | $40(aprox) | 

## Hard Lessons & Practical Fixes and Failure

* **Sun Board Snapping:** The 5mm Sun Board is strong under stress but it breaks very hard  at joints when it takes a hard hit nose dives often tear the glue points apart and this made my aircraft to fall off and everything snapped where ever possible.  

* **NRF Voltage Limits:** The NRF24L01 only works at 3.3V. powering it 5V will destroy it instantly(like i did) use 3.3V with capacitors for signal loss.

* **Transmitter Antenna Warning:** Never turn on the NRF module without attaching the antenna without the antenna the this will burn the modeul.
  
* **Power Dip Resets:** When both servos move at speed the power draw can cause the 5V line to drop below 4.2V which  resets the microcontroller add capacitors to avoid these brownouts.

# Credits
* **[Arduino](https://www.arduino.cc/)** - Microcontroller programming
* **[TMRh20 RF24](https://github.com/nRF24/RF24)** - Wireless communication library
* **[GrabCAD](https://grabcad.com/library)** - CAD electronic models for full CAD assembly
* **[Hack Club Forge](https://forge.hackclub.com/)** - For supporting projects in this format
