#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6qWeJoMhO"
#define BLYNK_TEMPLATE_NAME "feeding"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Define servo and Wi-Fi credentials
Servo myservo;
char auth[] = "tabEFsIsxiY7Zhh3T7FxYoz0GLIbvC2h";
char ssid[] = "Petchy";
char pass[] = "12345678910";
int Step = 0;
int State = 0;

BLYNK_WRITE(V0)
{
  if (param.asInt() == 1) {
    Step = 1;
  } else {
    Step = 0;
  }
}

void setup()
{
  myservo.attach(2);
  myservo.write(0);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); // เชื่อมต่อ auth , ssis , pass
}

void loop()
{
  Blynk.run();
  Serial.println(State);
  if (Step == 0 && State == 0) {
    myservo.write(0);
  } else if  (Step == 1 && State == 0) {
    State = 1;
  } else if (State == 1) {
    myservo.write(160);
    delay(500);
    myservo.write(0);
    delay(1000);
    State = 0;
  }
}
