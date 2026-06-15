# 🃏 Blackjack pe ESP32 cu display OLED

A hardware-based Blackjack game implemented on an ESP32 microcontroller, featuring an I2C OLED display and physical GPIO button inputs. The project demonstrates finite state machine logic, hardware debouncing, and peripheral communication in C/C++.

---

## 📋 Descriere

Jucătorul trage cărți (HIT) sau se oprește (STAND) folosind butoane conectate la GPIO-urile ESP32. Dealerul joacă automat conform regulilor clasice de Blackjack (trage până la minim 17 puncte). Rezultatul este afișat în timp real pe ecranul OLED.

---

## 🔧 Componente Hardware

| Componentă | Detalii |
|---|---|
| Microcontroller | ESP32 |
| Display | OLED 128x64 (SSD1306) via I2C |
| Buton HIT | GPIO 25 |
| Buton STAND | GPIO 26 |
| Buton RESET | GPIO 27 |
| Comunicație I2C | SDA → GPIO 32, SCL → GPIO 33 |

---

## 📦 Biblioteci necesare

Instalează din **Arduino Library Manager**:

- `Adafruit SSD1306`
- `Adafruit GFX Library`
- `Wire` (inclusă implicit în Arduino IDE)

---

## ⚡ Cum încarci codul

1. Instalează [Arduino IDE](https://www.arduino.cc/en/software)
2. Adaugă suportul pentru ESP32: `File → Preferences → Additional Boards Manager URLs` → adaugă:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
3. Mergi la `Tools → Board → Boards Manager` și instalează **esp32 by Espressif Systems**
4. Selectează placa: `Tools → Board → ESP32 Dev Module`
5. Instalează bibliotecile de mai sus
6. Deschide `blackjack_esp32.ino` și apasă **Upload**

---

## 🎮 Cum se joacă

- La pornire, jucătorul primește automat 2 cărți (valori între 2 și 11)
- **GPIO 25 (HIT)** → trage o carte nouă
- **GPIO 26 (STAND)** → oprești și dealerul joacă automat
- **GPIO 27 (RESET)** → repornești jocul după ce s-a terminat

### Reguli
- Dacă depășești 21 → **BUST** (ai pierdut)
- Dealerul trage cărți până ajunge la minim 17 puncte
- Cel cu scorul mai mare câștigă; dacă sunt egale → **remiză**

---

## 📁 Structura repo-ului

```
blackjack-esp32/
├── blackjack_esp32.ino   # Codul sursă principal
├── prezentare_pia.pptx   # Prezentarea proiectului
├── demo.mp4              # Video demonstrativ (display în funcțiune)
└── README.md             # Acest fișier
```

---

## 🎥 Demo

Vezi fișierul `demo.mp4` din repo pentru o demonstrație a jocului pe hardware real.

---
