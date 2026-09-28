# Rapid Fire Fighting Rover

An Arduino Uno-based autonomous rover that detects fire using IR flame sensors and extinguishes it with a servo-mounted water spray.

![Rover](images/rover.jpg)

## Overview

The rover uses three IR flame sensors (front, left, right) to scan its surroundings for fire. When a sensor detects flame, the rover turns toward it or, if the fire is directly ahead, stops and sweeps a servo-mounted nozzle while a relay-driven pump sprays water until the flame is out.

## Components

- Arduino Uno
- 3x IR flame sensor modules (LM393 comparator output)
- L298N-style dual H-bridge motor driver
- 2x DC gear motors + 1 caster wheel (3-wheel drivetrain)
- SG90 (or similar) micro servo for nozzle sweep
- 5V relay module driving a small water pump
- LM2596 DC-DC buck converter for regulated power
- 3.7V Li-ion battery pack
- Wooden chassis, tubing, and a water reservoir

## How It Works

1. The rover drives forward while continuously polling the three flame sensors.
2. If the **front** sensor detects fire, the rover stops, activates the pump, and sweeps the servo across the flame until the sensor clears.
3. If the **left** or **right** sensor detects fire, the rover turns briefly toward that side.
4. Once a fire is extinguished, the rover backs away and resumes scanning.

## Files

- [`Fire_Fighting_Robot.ino`](Fire_Fighting_Robot.ino) — Arduino sketch controlling sensors, motors, servo, and pump.
- [`docs/final_report.docx`](docs/final_report.docx) — Full project report, including methodology, build log, and component list.

## Author

Built by **Usman Alhassan Mohammed**.
