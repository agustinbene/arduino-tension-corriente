#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const float R1 = 98800; //101100;
const float R2 = 3300; //3210;
const float shunt = 0.19;
float vin, vout, input, vin2 = 0, iin, iin2, potencia;
float entradaV = A0, entradaI = A1;
long int ahora, antes = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
 
  analogReference(INTERNAL);
  pinMode (entradaV, INPUT);
  pinMode (entradaI, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("FUENTE VARIABLE");
  lcd.setCursor(0, 1);
  lcd.print("BENEGAS-GONZALEZ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tension: 1.5-32V");
  lcd.setCursor(0, 1);
  lcd.print("Corriente: 1.5A");
  delay(2000);
  lcd.clear();
}
void loop() {
  ahora = millis();
  if (ahora - antes > 333)
  {
    volt();
    amp();
    poten();
    antes = ahora;
  }
  Serial.println(vin);
}
void volt() {
  for (int i = 1; i <= 500; i++)
  {
    input = analogRead (entradaV) - (analogRead (entradaI) * 1.2);
    vout = ( input * 1.1) / 1024.0;
    vin = vout / (R2 / (R1 + R2));
    vin2 = vin2 + vin;
  }
  vin = vin2 / 500;
  vin2 = 0;
  if (vin <= 0.01) {
    vin = 0;
    lcd.setCursor (0, 0);
    lcd.print ("0");
    lcd.setCursor (5, 0);
    lcd.print ("V");
  }
  if (vin >= 10)
  {
    lcd.setCursor (0, 0);
    lcd.print (vin);
    lcd.setCursor (5, 0);
    lcd.print ("V");
  }
  else
  {
    lcd.setCursor (0, 0);
    lcd.print (vin);
    lcd.setCursor (4, 0);
    lcd.print ("V ");
  }
  Serial.print (vin);
  Serial.print ("V , ");
}
void amp() {
  for (int i = 1; i <= 1000; i++)
  {
    input = analogRead (entradaI);
    vout = (input * 1.1) / 1024;
    iin = vout / shunt;
    iin2 = iin2 + iin;
  }
  iin = iin2 / 1000;
  iin2 = 0;
  if (iin <= 0.005) {
    iin = 0;
  }
  if (iin <= 0.01)
  {
    lcd.setCursor (0, 1);
    lcd.print (iin * 1000);
    lcd.setCursor (4, 1);
    lcd.print ("mA ");
    Serial.print (iin * 1000);
    Serial.print ("mA , ");
  }
  else if (iin <= 0.1)
  {
    lcd.setCursor (0, 1);
    lcd.print (iin * 1000);
    lcd.setCursor (5, 1);
    lcd.print ("mA ");
    Serial.print (iin * 1000);
    Serial.print ("mA , ");
  }
  else if (iin <= 1)
  {
    lcd.setCursor (0, 1);
    lcd.print (iin * 1000);
    lcd.setCursor (6, 1);
    lcd.print ("mA");
    Serial.print (iin * 1000);
    Serial.print ("mA , ");
  }
  else if (iin == 0)
  {
    lcd.setCursor (0, 1);
    lcd.print (iin);
    lcd.setCursor (4, 1);
    lcd.print ("mA ");
    Serial.print (iin * 1000);
    Serial.print ("mA , ");
  }
  else if (iin < 10)
  {
    lcd.setCursor (0, 1);
    lcd.print (iin);
    lcd.setCursor (4, 1);
    lcd.print ("A ");
    Serial.print (iin);
    Serial.print ("A , ");
  }
}

void poten() {
  potencia = vin * iin;
  if (potencia >= 10)
  {
    lcd.setCursor (8, 0);
    lcd.print (potencia);
    lcd.setCursor (13, 0);
    lcd.print ("W");
  }
  else
  {
    lcd.setCursor (8, 0);
    lcd.print (potencia);
    lcd.setCursor (12, 0);
    lcd.print ("W ");
  }
  Serial.print (potencia);
  Serial.print ("W");
  Serial.print ("\n");
}
