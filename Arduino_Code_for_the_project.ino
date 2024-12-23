const int opAmpOutput = A0;  // Analog pin for op-amp signal
const int triggerOutput = 8; // Digital pin to trigger the 555 Timer
const float threshold = 2.5; // Set your threshold voltage (adjust as needed)

void setup() {
    pinMode(triggerOutput, OUTPUT);
    digitalWrite(triggerOutput, LOW); // Ensure output is low initially
}

void loop() {
    // Read the op-amp's output voltage
    int sensorValue = analogRead(opAmpOutput);
    float voltage = sensorValue * (5.0 / 1023.0); // Convert ADC value to voltage

    // Compare voltage with threshold
    if (voltage > threshold) {
        digitalWrite(triggerOutput, HIGH); // Trigger the 555 Timer
    } else {
        digitalWrite(triggerOutput, LOW); // Reset the trigger
    }

    delay(10); // Small delay to stabilize readings
}
