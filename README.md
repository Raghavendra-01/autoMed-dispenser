<div align="center">

```
 █████╗ ██╗   ██╗████████╗ ██████╗ ███╗   ███╗███████╗██████╗ 
██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗████╗ ████║██╔════╝██╔══██╗
███████║██║   ██║   ██║   ██║   ██║██╔████╔██║█████╗  ██║  ██║
██╔══██║██║   ██║   ██║   ██║   ██║██║╚██╔╝██║██╔══╝  ██║  ██║
██║  ██║╚██████╔╝   ██║   ╚██████╔╝██║ ╚═╝ ██║███████╗██████╔╝
╚═╝  ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚═╝     ╚═╝╚══════╝╚═════╝ 
```

### 💊 Automated Medical Dispenser using ESP32

<img src="https://readme-typing-svg.demolab.com?font=JetBrains+Mono&size=16&pause=1000&color=0BBFA0&center=true&vCenter=true&width=600&lines=Never+miss+a+dose+again.;ESP32+%2B+Servo+%2B+LCD+%2B+LED;Precision-timed+medication+dispensing.;Local-first.+Zero+internet+required." alt="Typing SVG" />

<br/>

[![Demo Video](https://img.shields.io/badge/▶_Demo_Video-YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://youtu.be/41HkbPN6JoI)
[![PPT](https://img.shields.io/badge/📊_Presentation-Download-1558D6?style=for-the-badge&logo=microsoftpowerpoint&logoColor=white)](Embedded%20Prototype.pptx)
[![Report](https://img.shields.io/badge/📄_Report-Download-0BBFA0?style=for-the-badge&logo=googledocs&logoColor=white)](AutomatedMedicalDispenser_Report.docx)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)](LICENSE)

<br/>

[![ESP32](https://img.shields.io/badge/ESP32-Espressif-E7352C?style=flat-square&logo=espressif&logoColor=white)](https://www.espressif.com)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=flat-square&logo=arduino&logoColor=white)](https://www.arduino.cc)
[![C++](https://img.shields.io/badge/Language-C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://isocpp.org)
[![KL University](https://img.shields.io/badge/KL_University-ECE_Dept-2C3E50?style=flat-square)](https://www.kluniversity.in)

</div>

---

## 🎬 Live Demo

<div align="center">

[![AutoMed Demo](https://img.youtube.com/vi/41HkbPN6JoI/maxresdefault.jpg)](https://youtu.be/41HkbPN6JoI)

*Click to watch — servo actuation, LCD alert & LED indicator on real hardware*

</div>

---

## 🧠 The Problem We Solved

> **50%** of chronic-condition patients fail to take medication as prescribed.  
> **125,000+** deaths per year in the US are linked to medication non-adherence.  
> **The elderly** managing multiple prescriptions face dangerous dosing confusion daily.

**AutoMed eliminates this** — a hardware-level solution requiring zero internet, zero app, zero cloud.

---

## ⚡ How It Works

```
┌─────────────────────────────────────────────────────────┐
│                   AUTOMED DISPENSE CYCLE                │
├─────────────────────────────────────────────────────────┤
│                                                         │
│   [IDLE]  ──►  Servo @ 0°    ──►  Wait 5 seconds       │
│                                                         │
│   [ALERT] ──►  Servo @ 180°  ──►  Compartment OPEN     │
│           ──►  LCD: "TAKE MEDICINE"                     │
│           ──►  LED: ON        ──►  Wait 5 seconds       │
│                                                         │
│   [RESET] ──►  LCD: Clear     ──►  LED: OFF             │
│           ──►  Loop back to [IDLE]                      │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

---

## 🔧 Hardware

<table>
<tr>
<td>

### Components

| Component | Model | Pin |
|-----------|-------|-----|
| 🧠 Microcontroller | ESP32 (38-pin) | — |
| 📺 Display | 16×2 I2C LCD | SDA: 21, SCL: 22 |
| ⚙️ Actuator | Servo Motor | PWM: 18 |
| 💡 Indicator | LED | GPIO: 25 |
| 🔌 Supply | 5V Power | VIN/GND |

</td>
<td>

### Wiring

```
ESP32 Pin 18  ──────► Servo Signal
ESP32 Pin 21  ──────► LCD SDA
ESP32 Pin 22  ──────► LCD SCL
ESP32 Pin 25  ──────► LED (+)
ESP32 3.3V    ──────► LCD VCC
ESP32 GND     ──────► Common GND
```

</td>
</tr>
</table>

---

## 📚 Libraries Required

```cpp
#include <ESP32Servo.h>         // Servo control on ESP32 PWM channels
#include <LiquidCrystal_I2C.h>  // I2C LCD 16x2 driver
```

Install via **Arduino IDE → Tools → Manage Libraries**

---

## 🚀 Quick Start

```bash
# 1. Clone the repository
git clone https://github.com/Raghavendra-01/autoMed-dispenser.git
cd autoMed-dispenser

# 2. Open in Arduino IDE
#    File → Open → AutoMed.ino

# 3. Install libraries
#    Tools → Manage Libraries → Search & install:
#    → ESP32Servo
#    → LiquidCrystal_I2C

# 4. Select your board
#    Tools → Board → ESP32 Arduino → ESP32 Dev Module

# 5. Upload & monitor
#    Upload → Serial Monitor @ 115200 baud
```

---

## 💻 Core Code

```cpp
void loop() {
  myServo.write(0);          // Compartment CLOSED
  delay(5000);

  digitalWrite(LED_PIN, HIGH);
  lcd.print("TAKE MEDICINE"); // Alert patient
  myServo.write(180);        // Compartment OPEN → dose released
  delay(5000);

  lcd.clear();
  digitalWrite(LED_PIN, LOW); // Reset
}
```

> 📂 Full source: [`AutoMed.ino`](AutoMed.ino)

---

## 📁 Repository Structure

```
autoMed-dispenser/
│
├── 📄  AutoMed.ino                          ← Arduino firmware
├── 🌐  index.html                           ← Interactive project webpage
├── 📊  Embedded Prototype.pptx             ← Full 17-slide presentation
├── 📝  AutomatedMedicalDispenser_Report.docx ← Technical report
├── 📜  LICENSE                              ← MIT
└── 🔧  .gitignore
```

---

## 🔭 Future Scope

| Feature | Status |
|---------|--------|
| 🤖 AI dosage analysis & behavior monitoring | 🔜 Planned |
| 📱 Mobile app with prescription upload | 🔜 Planned |
| ☁️ Cloud storage for medication history | 🔜 Planned |
| 🎙️ Voice assistant (Alexa / Google) | 🔜 Planned |
| 📷 Camera verification of medicine intake | 🔜 Planned |
| 🔐 Biometric authentication | 🔜 Planned |
| 📲 SMS / WhatsApp / Email alerts | 🔜 Planned |
| 🔋 Battery backup with power-fail alert | 🔜 Planned |

---

## 📊 Project Resources

<div align="center">

| 📊 Presentation | 📄 Report | ▶️ Demo |
|:-:|:-:|:-:|
| [Download PPT](Embedded%20Prototype.pptx) | [Download Report](AutomatedMedicalDispenser_Report.docx) | [Watch on YouTube](https://youtu.be/41HkbPN6JoI) |
| 17 slides · Full coverage | Technical deep-dive | Hardware in action |

</div>

---


## 📖 References

**Books:**
- *Getting Started with ESP32* — Neil Kolban
- *IoT: A Hands-On Approach* — Bahga & Madisetti
- *Exploring Arduino* — Jeremy Blum
- *Embedded Systems: ARM Cortex-M* — J. W. Valvano

**Web:**
- [espressif.com](https://www.espressif.com) · [arduino.cc](https://www.arduino.cc) · [ieeexplore.ieee.org](https://ieeexplore.ieee.org) · [randomnerdtutorials.com](https://randomnerdtutorials.com)

---

<div align="center">

**⭐ If this project helped you, please give it a star!**

[![Star History](https://img.shields.io/github/stars/Raghavendra-01/autoMed-dispenser?style=social)](https://github.com/Raghavendra-01/autoMed-dispenser)

<br/>

*Built with ❤️ at KL Deemed to be University · Department of ECE*

`ESP32` `Arduino` `Servo` `LCD` `I2C` `IoT` `Healthcare` `Embedded Systems` `Automation`

</div>
