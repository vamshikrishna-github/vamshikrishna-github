

#include "DHT.h"

#define DHTPIN 4     // Digital pin connected to the DHT sensor
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
 dht.begin();
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }

}
void loop() {
delay(6000);
int ldrval=analogRead(15);
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");

  }
  else
  {
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("%  Temperature: ");
  Serial.println(t);
  Serial.print("°C ");
  Serial.println(f);
  Serial.print("the LDR intensity is:");
  Serial.println(ldrval);
  display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println(" ");
    display.print("the ldr intensity is ");
    display.println(ldrval);
    display.print("Humidity: ");
    display.print(h);
    display.println("%");
    display.print("Temparature: ");
    display.print(t);
    display.println("°C ");
    display.print(f)
    
    display.display();
}
}
