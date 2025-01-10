#define BLYNK_TEMPLATE_ID "TMPL3n_cZNxcz"
#define BLYNK_TEMPLATE_NAME "Smart Irrigation System"
#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT11.h>
//Initialize the LCD display
LiquidCrystal_I2C lcd(0x3F, 16, 2);
char auth[] = "zbRcOvZBwT54KdbZuXYElYSWpZpYgI9n";  
char ssid[] = "DHRISHITA1";  
char pass[] = "dhrishita@$051805";  

DHT11 dht11(D4); //D4 DHT11 Temperature Sensor
BlynkTimer timer;

#define soil A0     //A0 Soil Moisture Sensor
#define PIR D5      //D5 PIR Motion Sensor
int PIR_ToggleValue;

void checkPhysicalButton();
int relay1State = LOW;
int pushButton1State = HIGH;
#define RELAY_PIN_1       D3   //D3 Relay
#define PUSH_BUTTON_1     D7   //D7 Button
#define VPIN_BUTTON_1    V12 

//Creating three variables for pressure
double T, P;
char status;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  pinMode(PIR, INPUT);

 pinMode(RELAY_PIN_1, OUTPUT);
 digitalWrite(RELAY_PIN_1, LOW);
  pinMode(PUSH_BUTTON_1, INPUT_PULLUP);
  digitalWrite(RELAY_PIN_1, relay1State);


  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //dht11.begin();

  lcd.setCursor(0, 0);
  lcd.print("  Initializing  ");
  for (int a = 5; a <= 10; a++) 
  {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(500);
  }
  lcd.clear();
  lcd.setCursor(11, 1);
  lcd.print("W:OFF");
  timer.setInterval(100L, soilMoistureSensor);
  timer.setInterval(100L, DHT11sensor);
  timer.setInterval(500L, checkPhysicalButton);
}
//Getting the DHT11 sensor values
void DHT11sensor() 
{
  float h = dht11.readHumidity();
  float t = dht11.readTemperature();
  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);

  lcd.setCursor(8, 0);
  lcd.print("H:");
  lcd.print(h);

}
//Getting the soil moisture values
void soilMoistureSensor() {
  int value = analogRead(soil);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V3, value);
  lcd.setCursor(0, 1);
  lcd.print("S:");
  lcd.print(value);
  lcd.print(" ");
}
//Getting the PIR sensor values
void PIRsensor() {
  bool value = digitalRead(PIR);
  if (value) 
  {
    Blynk.logEvent("moisture_detection","WARNNG! Motion Detected!"); 
    WidgetLED LED(V5);
    LED.on();
  } 
  else 
  {
    WidgetLED LED(V5);
    LED.off();
  }  
  }

BLYNK_WRITE(V6)
{
 PIR_ToggleValue = param.asInt();  
}

BLYNK_CONNECTED() 
{
  Blynk.syncVirtual(VPIN_BUTTON_1);
}

BLYNK_WRITE(VPIN_BUTTON_1) 
{
  relay1State = param.asInt();
  digitalWrite(RELAY_PIN_1, relay1State);
}

void checkPhysicalButton()
{
  if (digitalRead(PUSH_BUTTON_1) == LOW) {
    if (pushButton1State != LOW) 
    {
      relay1State = !relay1State;
      digitalWrite(RELAY_PIN_1, relay1State);
      Blynk.virtualWrite(VPIN_BUTTON_1, relay1State);
    }
    pushButton1State = LOW;
  } 
  else 
  {
    pushButton1State = HIGH;
  }
}

void loop() 
{
    if (PIR_ToggleValue == 1)
    {
    lcd.setCursor(5, 1);
    lcd.print("M:ON ");
      PIRsensor();
      }
     else
     {
    lcd.setCursor(5, 1);
    lcd.print("M:OFF");
    WidgetLED LED(V5);
    LED.off();
     }

if (relay1State == HIGH)
{
  lcd.setCursor(11, 1);
  lcd.print("W:ON ");
  }
  else if (relay1State == LOW)
  {
    lcd.setCursor(11, 1);
    lcd.print("W:OFF");
    }
     
  Blynk.run(); 
  timer.run();
  }
