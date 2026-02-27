# K.A.D-Ballers-Genius-Olympiad-Robot

Team **K.A.D Ballers**’ official repository for the **GENIUS Robotics — Genie Firefighter (2026)** master game.

This repo contains:
-  Robot control **code** (Arduino Nano + HC-05 Bluetooth)
-  **3D models** (all parts; PETG-printed robot)
-  Build + wiring + testing **photos**
-  Engineering documentation (**Design Book** + **Programming Book**)

---

## Team Info
- **Team Name:** K.A.D Ballers  
- **Team Members:** Kushal Sachdeva, Darsh Goel, Aaryan Singhania  
- **School/Organization:** Vasant Valley School, Delhi, India  
- **Competition:** GENIUS Robotics — Genie Firefighter (2026)

---

## Submission Video (YouTube)
**Official application/submission video (≤ 3 minutes):**  
 **YouTube Link:** 
 **Video Title Format:** `GENIUS Robotics_2026_KAD_Ballers` 

---

## Robot Overview (Quick Summary)
Our robot is a **tele-operated, 4-mecanum wheel** platform designed to:
1) **Remove debris (tennis balls)** from the safe zone and deposit into the debris bin  
2) **Collect water gel cubes** from the shared warehouse and place them into the fire zone  

**Manipulator system (3 servos):**
- Arm servo (up/down)
- Gripper servo (open/close)
- Basket/holder servo (flip dump)

**Manufacturing:** Entire robot is **3D printed in PETG** (with electronics + fasteners installed).

---

## Repository Contents (Only 4 Main Areas)

### 1) Code
Contains the Arduino program that reads Bluetooth serial commands and controls:
- Mecanum drive motion (forward/back/strafe/diagonal/rotate)
- Arm/gripper/basket servos

 `code/`  
- `genie_firefighter.ino`

---

### 2) 3D Models (All Parts)
All CAD exports / printable files for the robot (PETG).

 `models/`  
- *(STL / STEP / CAD source — whichever formats you used)*

**Print Notes (Recommended):**
- Material: PETG  
- Use higher wall count + infill for motor mounts and arm joints  
- Reinforce high-stress parts (arm pivot, servo horn mounts)

---

### 3) Photos
Build and testing photos used as evidence in the engineering book:
- Build stages
- Wiring
- Testing (pickup, dumping, driving)
- Final robot

 `photos/`

---

### 4) Engineering Books (Docs)
The official documentation for judging:
- Engineering Book — Robot Design
- Engineering Book — Programming

 `docs/`  
- `engineering-book-design.md`  
- `engineering-book-programming.md`

---

## How to Run (Quick Start)
1. Upload the code from `code/genie_firefighter.ino` to an **Arduino Nano**.
2. Pair your phone with **HC-05** (Bluetooth).
3. Open a Bluetooth serial controller app and connect to HC-05.
4. Press mapped buttons to drive and control the manipulator.

---

## Driver Command Map
### Movement
- `F` forward  
- `B` backward  
- `L` strafe left  
- `R` strafe right  
- `S` stop  
- `G` diagonal front-left  
- `H` diagonal front-right  
- `I` diagonal back-left  
- `J` diagonal back-right  
- `X` rotate clockwise  
- `Y` rotate counterclockwise  

### Manipulator
- `U` arm up  
- `D` arm down  
- `O` gripper open  
- `C` gripper close  
- `M` basket/holder load  
- `N` basket/holder unload  

---

## Hardware Summary
- **Microcontroller:** Arduino Nano  
- **Wireless:** HC-05 Bluetooth module  
- **Drive:** 4× 12V 50 RPM DC motors + mecanum wheels  
- **Motor Drivers:** 2× L298N  
- **Servos:** 3× metal gear high-torque servos (35 kg)  
- **Power:** 12V battery + buck converter to 5V for logic/servos  

---

## Future Implementations (Planned Upgrades)
- **Scissor lift under basket** to raise basket to debris bin height for consistent dumping
- **Rubber-band rotating intake** for faster automatic pickup of debris and cubes


---
