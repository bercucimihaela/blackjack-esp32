## ESP32 Blackjack Console
Joc de Blackjack implementat hardware pe un microcontroler ESP32, dotat cu un display OLED pe interfața I2C și butoane fizice conectate la pinii GPIO. Proiectul demonstrează logica de tip automat de stări (FSM), filtrarea semnalelor (hardware debouncing) și comunicarea cu perifericele în C/C++.
## Componente Hardware

| Componentă | Detalii |
|---|---|
| Microcontroller | ESP32 |
| Display | OLED 128x64 (SSD1306) via I2C |
| Buton HIT | GPIO 25 |
| Buton STAND | GPIO 26 |
| Buton RESET | GPIO 27 |
| Comunicație I2C | SDA → GPIO 32, SCL → GPIO 33 |

---
## Ce face

* Implementează regulile clasice de Blackjack printr-un automat de stări: la pornire primești 2 cărți (valori generate aleatoriu între 2 și 11).
* **HIT (GPIO 25):** Tragi o carte nouă. Depășirea a 21 de puncte declanșează starea de BUST (pierdere).
* **STAND (GPIO 26):** Oprești runda jucătorului, iar sistemul declanșează AI-ul dealerului (care trage cărți automat până la minim 17 puncte).
* **RESET (GPIO 27):** Reinițializează starea jocului după finalizarea rundei.
* Compară automat scorurile la final și afișează în timp real rezultatul pe display-ul OLED.
---
## Tech

* **Limbaj:** C/C++
* **Hardware:** Microcontroller ESP32 (ESP-WROOM-32)
* **Biblioteci externe:** `Adafruit SSD1306`, `Adafruit GFX Library`, `Wire`
---

## Run

Pentru a compila și încărca proiectul:
1. Adaugă suportul pentru placa ESP32 în Arduino IDE (URL-ul pachetului Espressif în Preferences).
2. Instalează bibliotecile `Adafruit SSD1306` și `Adafruit GFX` din Library Manager.
3. Selectează **ESP32 Dev Module** din meniul *Boards* și execută comanda Upload pentru `blackjack_esp32.ino`.
---
##  Structura 

```
blackjack-esp32/
  src/
  └── blackjack_esp32.ino
 demo/
   └── demo.mp4
 .gitignore
  README.md
```

---

## demo


https://github.com/user-attachments/assets/f913fe4f-be90-4de5-984c-78d011dcea74

