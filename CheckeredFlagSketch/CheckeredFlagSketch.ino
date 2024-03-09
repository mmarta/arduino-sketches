/**
* Konami's Checkered Flag
* Arduino Sketch for Accelerator & Gear Shift I/O
*/

const uint8_t PIN_INPUT_LOW_GEAR_BUTTON = 10,
    PIN_INPUT_HIGH_GEAR_BUTTON = 11,
    PIN_INPUT_ACCELERATOR_BUTTON = 8,
    PIN_OUTPUT_ACCELERATOR_SIGNAL = 12,
    PIN_OUTPUT_GEAR_SIGNAL = 4;

void setup() {
  // Set input pins for buttons
  pinMode(PIN_INPUT_LOW_GEAR_BUTTON, INPUT);
  pinMode(PIN_INPUT_HIGH_GEAR_BUTTON, INPUT);
  pinMode(PIN_INPUT_ACCELERATOR_BUTTON, INPUT);

  // Set output pins for signals
  pinMode(PIN_OUTPUT_GEAR_SIGNAL, OUTPUT);
  pinMode(PIN_OUTPUT_ACCELERATOR_SIGNAL, OUTPUT);

  // Set write on for both output pins
  digitalWrite(PIN_OUTPUT_ACCELERATOR_SIGNAL, HIGH); // Off Brake
  digitalWrite(PIN_OUTPUT_GEAR_SIGNAL, HIGH); // Start pin 4 as low gear (signal on)

  // Flow voltage to button input pins (no separate power)
  digitalWrite(PIN_INPUT_HIGH_GEAR_BUTTON, HIGH);
  digitalWrite(PIN_INPUT_LOW_GEAR_BUTTON, HIGH);
  digitalWrite(PIN_INPUT_ACCELERATOR_BUTTON, HIGH);
}

void loop() {
  // Shift buttons
  if(digitalRead(PIN_INPUT_HIGH_GEAR_BUTTON) == LOW) {
    digitalWrite(PIN_OUTPUT_GEAR_SIGNAL, LOW); // Signal off is High Gear
  } else if(digitalRead(PIN_INPUT_LOW_GEAR_BUTTON) == LOW) {
    digitalWrite(PIN_OUTPUT_GEAR_SIGNAL, HIGH); // Signal on is Low Gear
  }

  // Full accelerator signal on/off depending on state of button
  digitalWrite(PIN_OUTPUT_ACCELERATOR_SIGNAL, !digitalRead(PIN_INPUT_ACCELERATOR_BUTTON));

  // Pass back < 1 frame
  delay(5);
}
