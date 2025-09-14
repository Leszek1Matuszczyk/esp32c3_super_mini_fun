#define PWM_LED 1   // Pin 2 used for PWM output (controls LED brightness)
#define ANALOG A0   // Analog input pin A0 for reading sensor/potentiometer value

void setup() {
  pinMode(PWM_LED, OUTPUT);        // Set pin 2 as an output for the LED
  ledcAttach(PWM_LED, 2000, 12);   // Attach PWM to pin 2 with 2 kHz frequency and 12-bit resolution
  Serial.begin(9600);              // Initialize serial communication at 9600 baud
}

void loop() {
  // Read the analog input value (0–4095 for 12-bit ADC)
  // and send it directly as PWM duty cycle to control LED brightness
  ledcWrite(PWM_LED, analogRead(ANALOG));

  // Print the analog input value to the Serial Monitor
  Serial.println(analogRead(ANALOG));

  delay(50);  // Small delay to smooth updates and avoid excessive serial output
}