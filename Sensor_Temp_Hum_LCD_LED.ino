#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3f, 16, 2);
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int pinAlarma = 3;
byte degr [8] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

void setup() {
lcd.begin();
lcd.backlight();
dht.begin();
lcd.createChar(0,degr);
pinMode (pinAlarma,OUTPUT);
}

void loop() {
delay(5000);
lcd.clear();
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(h) || isnan(t))
{
  lcd.clear();
  lcd.print("FALLO SENSOR");
  return;
}
float ic = dht.computeHeatIndex(t, h, false);
lcd.print("Hum:");
lcd.print(round(h));
lcd.print("%");
lcd.print("Tem:");
lcd.print(round(t));
lcd.write(0);
lcd.print("C");
lcd.setCursor(0, 1);
lcd.print("ST:");
lcd.print(round(ic));
lcd.write(0);
lcd.print("C");
if (t<13 || t>25)
{
  digitalWrite(pinAlarma,HIGH);
}
else
{
  digitalWrite(pinAlarma,LOW);
}
}
