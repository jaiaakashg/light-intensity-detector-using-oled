#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LDR_PIN 34

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;);
  }
  
  display.display();
  delay(2000);
  display.clearDisplay();

  Serial.begin(115200);
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  int ldrValue = digitalRead(LDR_PIN);
  String lightCondition = (ldrValue == LOW) ? "Bright" : "Dark";

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.print("Light:");
  display.setTextSize(3);
  display.setCursor(0, 35);
  display.print(lightCondition);
  display.display();

  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" Light Condition: ");
  Serial.println(lightCondition);

  delay(500);
}

