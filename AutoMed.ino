#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

// ── Pin Configuration ─────────────────────────────────────────────────────────
const int SERVO_PIN   = 18;   // Servo signal pin
const int LED_PIN     = 25;   // Indicator LED
const int SDA_PIN     = 21;   // I2C Data
const int SCL_PIN     = 22;   // I2C Clock

// ── Timing ────────────────────────────────────────────────────────────────────
const unsigned long CLOSED_DURATION = 5000;  // ms servo stays closed
const unsigned long OPEN_DURATION   = 5000;  // ms servo stays open (dispense window)

// ── Hardware Objects ──────────────────────────────────────────────────────────
Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Address 0x27, 16 cols, 2 rows

void setup() {
  Serial.begin(115200);

  // Servo
  myServo.setPeriodHertz(50);               // Standard 50 Hz
  myServo.attach(SERVO_PIN, 500, 2400);     // Min / Max pulse width (µs)

  // LED
  pinMode(LED_PIN, OUTPUT);

  // LCD
  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.init();
  lcd.backlight();

  Serial.println("AutoMed Dispenser Ready.");
}

void loop() {
  // ── CLOSED position ──────────────────────────────────────────────────────
  myServo.write(0);
  delay(CLOSED_DURATION);

  // ── OPEN position + alert ─────────────────────────────────────────────────
  digitalWrite(LED_PIN, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("TAKE            ");   // trailing spaces clear old chars
  lcd.setCursor(0, 1);
  lcd.print("MEDICINE        ");

  myServo.write(180);
  delay(OPEN_DURATION);

  // ── Reset ──────────────────────────────────────────────────────────────────
  lcd.clear();
  digitalWrite(LED_PIN, LOW);
}
