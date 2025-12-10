# 🎵 Arduino Music Beat Follower

> **A sound-reactive lighting controller that syncs your lights to the music beat.**

## 📖 Description

This project utilizes an Arduino and a digital microphone sensor to control a high-voltage relay. It is designed to make an ordinary light bulb (or any other appliance connected to the relay) flash or toggle in synchronization with loud sounds, such as the beat of a song or a clap.

The logic is simple yet effective: when the sound sensor detects a signal above the threshold, the Arduino toggles the state of the relay, creating a dynamic strobe-like effect or a rhythmic light show.

## ⚡ Features

* **Sound Activation:** Reacts to music beats, claps, or loud noises.
* **Adjustable Sensitivity:** Relies on the hardware potentiometer usually found on microphone modules.
* **Debounce Logic:** Includes a specific delay to prevent flickering and ensure distinct state changes.
* **Versatile:** Can be used for parties, home automation (clap switch), or interactive installations.

## 🛠️ Hardware Required

* 1x Arduino Board (Uno, Nano, Mega, etc.)
* 1x Sound Sensor Module (e.g., KY-037, KY-038, or similar with Digital Output)
* 1x Relay Module (5V)
* 1x Light Bulb + Socket (and power source appropriate for the bulb)
* Jumper Wires

## 🔌 Wiring & Pinout

Connect your components according to the variables defined in the code:

| Component | Pin Name | Arduino Pin |
| :--- | :--- | :--- |
| **Sound Sensor** | Digital Out (DO) | **D2** (`SOUND_SENSOR_PIN`) |
| **Relay Module** | Signal (IN) | **D7** (`RELAY_PIN`) |
| **Sound Sensor** | VCC / GND | 5V / GND |
| **Relay Module** | VCC / GND | 5V / GND |

## 💻 Code Overview

The code continuously monitors the digital input from the microphone:

1.  **Reading:** It reads the state of the `SOUND_SENSOR_PIN`.
2.  **Triggering:** If the sound sensor sends a `HIGH` signal (sound detected):
    * The boolean state of the relay is inverted (`!relayState`).
    * The new state is written to the `RELAY_PIN`.
3.  **Debouncing:** A delay defined by `BEAT_DELAY` (default 75ms) is applied to prevent the relay from switching too rapidly or "chattering" during a single bass hit.

## ⚙️ How to Use

1.  **Upload:** Flash the `follow_music.ino` file to your Arduino.
2.  **Calibrate:** Power on the system. Play some music.
3.  **Adjust:** Use a small screwdriver to turn the potentiometer on your **Sound Sensor Module**.
    * Turn it until the LED on the module flickers only when a beat hits.
    * If it's always ON, the sensitivity is too high. If it never turns ON, it's too low.

## ⚠️ Safety Warning

**High Voltage Danger:**
This project involves controlling a Relay that may be switching AC Mains voltage (110V/220V).
* **Do not** touch the relay or the bulb wiring while the power is connected.
* Ensure the relay is properly isolated.
* If you are not comfortable working with AC voltage, use a 5V/12V LED strip instead of a light bulb.

## 📄 License

This project is open-source. Feel free to modify and improve it.

**Author:** Rubens Braz
