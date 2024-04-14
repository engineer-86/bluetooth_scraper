#include <Arduino.h>

// GPIO-Pin für die LED. Überprüfe die Dokumentation deines Boards.
const int ledPin = 8; // Angenommen, die LED ist an GPIO 2 angeschlossen.

void setup()
{
  pinMode(ledPin, OUTPUT); // Konfiguriere den LED-Pin als Ausgang.
  Serial.begin(115200);
  while (!Serial)
  {
    digitalWrite(ledPin, HIGH); // Schalte die LED ein.
    Serial.println("ESP32-C supermini, LED is ON");
  }
  Serial.println("Serial is ready!");
}

void loop()
{
  digitalWrite(ledPin, HIGH); // Schalte die LED ein.
  Serial.println("ESP32-C supermini, LED is ON");
  delay(500); // Warte 500 Millisekunden.

  digitalWrite(ledPin, LOW); // Schalte die LED aus.
  Serial.println("ESP32-C supermini, LED is OFF");
  delay(500); // Warte weitere 500 Millisekunden.
}
