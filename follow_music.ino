/**
 * Project: Sound Reactive Relay Controller
 * Description: Toggles a relay state based on digital input from a sound sensor.
 * Author: Rubens Braz
 */

// --- Hardware Configuration ---
const int RELAY_PIN = 7;        // Pin connected to the Relay Module
const int SOUND_SENSOR_PIN = 2; // Pin connected to the Sound Sensor Digital Output (DO)

// --- Settings ---
const int BEAT_DELAY = 75;      // Delay in ms to prevent flickering (debounce)

// --- Global Variables ---
bool relayState = HIGH;         // Stores the current state of the relay

void setup() {
  // Initialize pins
  pinMode(SOUND_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Set initial relay state
  digitalWrite(RELAY_PIN, relayState);
}

void loop() {
  // Read the digital output from the sound sensor
  // HIGH usually means sound was detected above the threshold
  bool soundDetected = digitalRead(SOUND_SENSOR_PIN);

  if (soundDetected) {
    // Toggle the relay state (ON to OFF, or OFF to ON)
    relayState = !relayState;
    
    // Apply the new state to the hardware
    digitalWrite(RELAY_PIN, relayState);

    // Wait a short moment to debounce the sound peak
    // This prevents the light from flashing too frantically on a single beat
    delay(BEAT_DELAY);
  }
}
