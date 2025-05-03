#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int potPin = 34;  // Analog pin for potentiometer

void setup() {
  Serial.begin(115200);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Booting...");
  display.display();
  delay(1000);
}

void loop() {
  int potValue = analogRead(potPin);

  Serial.print("Potentiometer: ");
  Serial.println(potValue);

  int scaledpotvalue = map(potValue, 0, 4095, 0, 180);

  display.clearDisplay();
  display.setCursor(0, 30);
  display.print(scaledpotvalue);
  display.display();

  delay(10);
}
