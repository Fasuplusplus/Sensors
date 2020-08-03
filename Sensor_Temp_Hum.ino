#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int R = 3;
int G = 4;
int B = 5;
void setup() {
Serial.begin(9600);
dht.begin();
pinMode(R, OUTPUT);
pinMode(G, OUTPUT);
pinMode(B, OUTPUT);

}

void loop() {
delay(5000);
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(h) || isnan(t))
{
  Serial.println("ERROR");
  return;
}
float ic = dht.computeHeatIndex(t, h, false);
if (ic >=25)
{
  digitalWrite(R,HIGH);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
}
else if (ic <10)
{
  digitalWrite(G,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(B,HIGH);
}
else
{
  digitalWrite(G,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(B,LOW);
}
Serial.print("Humedad: ");
Serial.print(h);
Serial.print("%\t");
Serial.print("Temperatura: ");
Serial.print(t);
Serial.print("ºC\t");
Serial.print("ST: ");
Serial.print(ic);
Serial.println("ºC");
}
