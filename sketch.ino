// Kinetic Piezoelectric Extractor - Arduino Uno / Wokwi simulation
// Joystick 1: A0 frequency, A1 base vibration amplitude
// Joystick 2: A2 equivalent electrical load resistance
// This is a mathematical model, NOT a real piezoelectric transducer.

const float M = 0.001;      // effective cantilever mass [kg]
const float C = 50e-9;      // piezoelectric capacitance [F]
const float FN = 60.0;      // assumed natural frequency [Hz]
const float ZM = 0.01;      // mechanical damping ratio
const float ZMAX = 0.03;    // maximum electrical damping ratio
const float CS = 100e-6;   // simulated storage capacitor [F]
const float V_ON = 2.5;     // sensor activation voltage [V]
const float DT = 0.2;      // assumed step [s]; delay() is 200 ms
const float SENSOR_POWER = 200e-6; // simulated sensor load [W]
const int PIN_F = A0;
const int PIN_Y = A1;
const int PIN_R = A2;
const int LED_STANDBY = 8;
const int LED_ACTIVE = 9;
float energy = 0.0;        // simulated capacitor energy [J]

float calcPower(float f, float R, float Y_m) {
  float w = 2.0 * PI * f;
  float wn = 2.0 * PI * FN;
  float r = w / wn;
  float x = w * R * C;
  float ze = 2.0 * ZMAX * x / (1.0 + x * x);
  float z = ZM + ze;
  float den = sqrt(pow(1.0 - r * r, 2) + pow(2.0 * z * r, 2));
  float Z = Y_m * r * r / den;
  return ze * M * wn * pow(w * Z, 2);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_STANDBY, OUTPUT);
  pinMode(LED_ACTIVE, OUTPUT);
  Serial.println("Kinetic Piezo Extractor - SIMULATED MODEL");
  Serial.println("f_Hz,R_ohm,amp_mm,power_uW,voltage_V,sensor_state");
}

void loop() {
  float f = 1.0 + 299.0 * analogRead(PIN_F) / 1023.0;
  float amp_mm = 0.01 + 0.49 * analogRead(PIN_Y) / 1023.0;
  float Y = amp_mm * 1e-3;
  float R = pow(10.0, 2.0 + 4.0 * analogRead(PIN_R) / 1023.0);
  float P = calcPower(f, R, Y);
  energy += P * DT;
  // Energy in an ideal capacitor. Idealized 5 V voltage clamp.
  float V = sqrt(2.0 * energy / CS);
  if (V > 5.0) {
    V = 5.0;
    energy = 0.5 * CS * V * V;
  }
  bool active = V >= V_ON;
  if (active) {
    energy -= SENSOR_POWER * DT;
    if (energy < 0) energy = 0;
    V = sqrt(2.0 * energy / CS);
  }
  digitalWrite(LED_ACTIVE, active ? HIGH : LOW);
  digitalWrite(LED_STANDBY, active ? LOW : HIGH);
  // A single CSV-style row per time step for easy recording.
  Serial.print(f, 2); Serial.print(",");
  Serial.print(R, 0); Serial.print(",");
  Serial.print(amp_mm, 3); Serial.print(",");
  Serial.print(P * 1e6, 3); Serial.print(",");
  Serial.print(V, 3); Serial.print(",");
  Serial.println(active ? "ACTIVE" : "STANDBY");
  delay(200);
}
