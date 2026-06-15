#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C
#define I2C_SDA 32
#define I2C_SCL 33

#define BTN_HIT   25
#define BTN_STAND 26
#define BTN_RESET 27

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int playerScore = 0;
int dealerScore = 0;
bool playerDone = false;
bool gameEnded = false;

int drawCard() {
  return random(2, 12); // 2 to 11
}

void showText(String line1, String line2 = "", String line3 = "") {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(line1);
  if (line2 != "") display.println(line2);
  if (line3 != "") display.println(line3);
  display.display();
}

void resetGame() {
  playerScore = drawCard() + drawCard();
  dealerScore = drawCard() + drawCard();
  playerDone = false;
  gameEnded = false;
  showText("BLACKJACK",
           "You: " + String(playerScore),
           "25=Hit 26=Stand");
}

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  randomSeed(analogRead(0));
  pinMode(BTN_HIT, INPUT_PULLUP);
  pinMode(BTN_STAND, INPUT_PULLUP);
  pinMode(BTN_RESET, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Eroare OLED"));
    while (1);
  }

  resetGame();
}

void loop() {
  if (!playerDone) {
    // HIT (GPIO 25)
    if (digitalRead(BTN_HIT) == LOW) {
      delay(200);
      int card = drawCard();
      playerScore += card;
      Serial.println("HIT: " + String(card));
      if (playerScore > 21) {
        playerDone = true;
        gameEnded = true;
        showText("You BUST!",
                 "Score: " + String(playerScore),
                 "27=Reset");
      } else {
        showText("You: " + String(playerScore),
                 "25=Hit 26=Stand");
      }
    }

    // STAND (GPIO 26)
    if (digitalRead(BTN_STAND) == LOW) {
      delay(200);
      playerDone = true;
      while (dealerScore < 17) {
        dealerScore += drawCard();
      }
      String result;
      if (dealerScore > 21 || playerScore > dealerScore)
        result = "You win!";
      else if (playerScore < dealerScore)
        result = "Dealer wins!";
      else
        result = "Draw";

      showText("You: " + String(playerScore),
               "Dealer: " + String(dealerScore),
               result + " | 27=Reset");
      gameEnded = true;
    }
  }

  // RESET (GPIO 27)
  if (gameEnded && digitalRead(BTN_RESET) == LOW) {
    delay(300);
    resetGame();
  }
}
