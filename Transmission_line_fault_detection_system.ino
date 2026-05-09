#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
int buzzer = 13;
#define sc A0
#define oc A1
#define voltage A2
int fire = 8;
void setup() 
{
  pinMode(13, OUTPUT);
  pinMode(sc, INPUT_PULLUP);
  pinMode(oc, INPUT_PULLUP);
  pinMode(voltage, INPUT_PULLUP);
  pinMode(fire, INPUT);
  digitalWrite(buzzer, LOW);
  Serial.begin(9600);
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("OVERHEAD FAULT  ");
  lcd.setCursor(0, 1);
  lcd.print("DETECTION       ");
  delay(4000);
  lcd.clear();
}

void loop() 
{
  lcd.clear();
  if (digitalRead(sc) == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("SHORTCRCT FAULT ");
    lcd.setCursor(0, 1);
    lcd.print("DETECTED        ");
    digitalWrite(buzzer,HIGH);
    sms1();
  }
  else if (digitalRead(oc) == HIGH)
  {
    lcd.setCursor(0, 0);
    lcd.print("OPENCRCT FAULT  ");
    lcd.setCursor(0, 1);
    lcd.print("DETECTED        ");
    digitalWrite(buzzer,HIGH);
    sms2();
  }
  else if (digitalRead(voltage) == HIGH)
  {
    lcd.setCursor(0, 0);
    lcd.print("HIGH VOLTAGE    ");
    lcd.setCursor(0, 1);
    lcd.print("DETECTED        ");
    digitalWrite(buzzer,HIGH);
    sms3();
  }
  else if (digitalRead(fire) == HIGH)
  {
    lcd.setCursor(0, 0);
    lcd.print("FIRE            ");
    lcd.setCursor(0, 1);
    lcd.print("DETECTED        ");
    digitalWrite(buzzer,HIGH);
    sms4();
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("LINES STABLE   ");
    lcd.setCursor(0, 1);
    lcd.print("V : ");
    lcd.print(random(230,240));
    digitalWrite(buzzer,LOW);
  }
  delay(1000);
}

void sms1()
{
  Serial.println("AT");
  delay(500);

  Serial.println("AT+CMGF=1");
  delay(500);

  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print("9399974447");    //mobile no. for SMS alert
  Serial.println('"');
  delay(500);

  Serial.print("Short Circuit Fault detected Near by Sri Vasavi Engineering College.");
  Serial.write(26);
  delay(3000);
  digitalWrite(buzzer,LOW);
}

void sms2()
{
  Serial.println("AT");
  delay(500);

  Serial.println("AT+CMGF=1");
  delay(500);

  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print("9399974447");    //mobile no. for SMS alert
  Serial.println('"');
  delay(500);

  Serial.print("Open Circuit Fault Detected Near By Sri Vasavi Engineering College.");
  Serial.write(26);
  delay(3000);
  digitalWrite(buzzer,LOW);
}

void sms3()
{
  Serial.println("AT");
  delay(500);

  Serial.println("AT+CMGF=1");
  delay(500);

  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print("9399974447");    //mobile no. for SMS alert
  Serial.println('"');
  delay(500);

  Serial.print("High Voltage Fault detected Near By Sri Vasavi Engineering College.");
  Serial.write(26);
  delay(3000);
  digitalWrite(buzzer,LOW);
}

void sms4()
{
  Serial.println("AT");
  delay(500);

  Serial.println("AT+CMGF=1");
  delay(500);

  Serial.print("AT+CMGS=");
  Serial.print('"');
  Serial.print("9399974447");    //mobile no. for SMS alert
  Serial.println('"');
  delay(500);

  Serial.print("Fire detected Near By Sri Vasavi Engineering College.");
  Serial.write(26);
  delay(3000);
  digitalWrite(buzzer,LOW);
}