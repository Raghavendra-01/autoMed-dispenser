# 💊 AutoMed — Automated Medicine Dispenser

> An ESP32-based automatic medicine dispenser with an I2C LCD display, servo-driven drum, and LED alert — built to help patients never miss a dose.

---

## 📸 Demo

▶️ **Watch the full demo on YouTube:** [https://youtu.be/41HkbPN6JoI](https://youtu.be/41HkbPN6JoI)

[![AutoMed Demo](https://img.youtube.com/vi/41HkbPN6JoI/maxresdefault.jpg)](https://youtu.be/41HkbPN6JoI)

Open `docs/index.html` in your browser for the interactive project showcase.

---

## 🔧 Hardware

| Component | Detail |
|-----------|--------|
| Microcontroller | ESP32 (any 38-pin variant) |
| Display | 16×2 I2C LCD (address `0x27`) |
| Actuator | Standard servo motor |
| Indicator | LED |

### Pin Map

| Signal | ESP32 Pin |
|--------|-----------|
| Servo PWM | 18 |
| LED | 25 |
| I2C SDA | 21 |
| I2C SCL | 22 |

---

## 📚 Libraries

Install these via the Arduino Library Manager:

- **ESP32Servo** — servo control on ESP32 PWM channels
- **LiquidCrystal_I2C** — I2C LCD driver

---

## ⚙️ How It Works

1. Servo holds at **0°** (compartment closed) for 5 seconds.
2. Servo rotates to **180°** (compartment open) — releasing one dose.
3. LCD displays **"TAKE MEDICINE"** and LED turns ON for 5 seconds.
4. LCD clears, LED turns OFF, and the cycle repeats.

Adjust `CLOSED_DURATION` and `OPEN_DURATION` at the top of `AutoMed.ino` to change timing.

---

## 🚀 Getting Started

```bash
# 1. Clone the repo
git clone https://github.com/YOUR_USERNAME/autoMed-dispenser.git

# 2. Open in Arduino IDE
#    File → Open → AutoMed/AutoMed.ino

# 3. Install libraries (Tools → Manage Libraries)
#    - ESP32Servo
#    - LiquidCrystal_I2C

# 4. Select board: ESP32 Dev Module
#    Tools → Board → ESP32 Arduino → ESP32 Dev Module

# 5. Upload and open Serial Monitor at 115200 baud
```

---

## 📁 Repository Structure

```
autoMed-dispenser/
├── AutoMed/
│   └── AutoMed.ino       ← Arduino sketch
├── docs/
│   └── index.html        ← Interactive project webpage
├── .gitignore
└── README.md
```

---

## 👨‍💻 Team

| Name | Role |
|------|------|
| Devineni Prem Nag | Team Member |
| D. Shanmukha Venkata Sai | Team Member |
| M. Hemanth Kumar | Team Member |
| SK. Sajeeth Shareef | Team Member |

**Guided by:** Dr. A V. Prabhu, Associate Professor, Dept of ECE  
**Institution:** KL Deemed to be University

---

## 📊 Presentation

📥 **[Download PPT](docs/Embedded_Prototype.pptx)** — Full project presentation (17 slides)

Slides cover: Introduction · Circuit Diagram · Hardware & Software Requirements · Flowchart · Advantages · Applications · Results · Future Scope · Conclusion

---

## 🔭 Future Scope

- AI integration for dosage analysis and patient behavior monitoring
- Mobile app with prescription upload and tracking
- Cloud storage for long-term medication history
- Voice assistant support (Alexa / Google Assistant)
- Camera-based verification to confirm medicine intake
- Biometric authentication (fingerprint / face recognition)
- Auto refill notification system

---

## 📄 License

MIT © 2024 — feel free to use, modify, and share.
