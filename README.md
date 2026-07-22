# K.A.D Ballers: Genie Firefighter Robot

A tele-operated, four-wheel mecanum robot built by Team K.A.D Ballers for the GENIUS Olympiad robotics competition (GENIUS Robotics, Genie Firefighter 2026 game). The robot's chassis and mechanical parts are fully 3D printed in PETG, and it is driven over Bluetooth, using a three-servo manipulator to clear debris and place water gel cubes in the game's fire zone.

[![Platform](https://img.shields.io/badge/Platform-Arduino%20Nano-blue)](Code/mecanumwheelrobot)
[![Drive](https://img.shields.io/badge/Drive-4x%20Mecanum-orange)](3D%20Models)
[![License](https://img.shields.io/badge/License-MIT-green)](LICENSE)

## Result

This project qualified as a GENIUS Olympiad finalist. The team did not attend the final round due to prior commitments.

## Team

- **Team name**: K.A.D Ballers
- **Members**: Kushal Sachdeva, Darsh Goel, Aaryan Singhania
- **School**: Vasant Valley School, Delhi, India

## Submission video

Official application video: [GENIUS Robotics_2026_KAD_Ballers on YouTube](https://youtu.be/bjkdxhQIA2E?si=Tjy7cpMIQIa94cFR)

## Robot overview

The Genie Firefighter game requires removing debris (tennis balls) from the safe zone into a debris bin, and collecting water gel cubes from the shared warehouse to place into the fire zone. Our robot handles both tasks with:

- **Mecanum drive**: four mecanum wheels for forward, backward, strafe, diagonal, and rotation movement. Each diagonal command drives exactly two of the four motors.
- **Three-servo manipulator**: an arm servo (smooth 1-degree stepped sweeps between down and up positions), a gripper servo (open/close), and a basket servo that flips to dump collected objects.
- **Bluetooth teleoperation**: an HC-05 module on a software serial port (9600 baud) receives single-character commands from a phone controller app.

## Hardware

| Component | Details |
| --- | --- |
| Microcontroller | Arduino Nano |
| Wireless | HC-05 Bluetooth module |
| Drive | 4x 12V 50 RPM DC motors with mecanum wheels |
| Motor drivers | 2x L298N dual H-bridge |
| Servos | 3x high-torque metal gear servos |
| Power | 12V battery with a buck converter to 5V for logic and servos |
| Chassis and parts | Fully 3D printed in PETG (SolidWorks sources and STL exports included) |

## Driver command map

| Movement | Key | Manipulator | Key |
| --- | --- | --- | --- |
| Forward / Backward | `F` / `B` | Arm up / down | `U` / `D` |
| Strafe left / right | `L` / `R` | Gripper open / close | `O` / `C` |
| Diagonals | `G` `H` `I` `J` | Basket load / unload | `M` / `N` |
| Rotate CW / CCW | `X` / `Y` | Stop | `S` |

## Repository contents

```
Code/mecanumwheelrobot/   # Arduino sketch: drive kinematics, servo control, Bluetooth command loop
3D Models/                # SolidWorks part files (.SLDPRT) with printable STL exports,
                          # plus the full assembled robot model
Photos/                   # Build, wiring, testing, and final robot photos
Docs/                     # Engineering books (Robot Design and Programming) as PDFs
```

## How to run

1. Upload `Code/mecanumwheelrobot/mecanumwheelrobot.ino` to an Arduino Nano.
2. Pair your phone with the HC-05 module.
3. Open a Bluetooth serial controller app and connect.
4. Drive and operate the manipulator with the mapped keys above.

## Related projects

Kushal and Darsh also compete as [Team VVS Ballers in RoboCupJunior Soccer](https://github.com/Kushal-Sachdeva78/VVS-Ballers-RoboCup), placing 9th at RoboCup 2026 in Incheon, South Korea.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
