#include <ESP8266Webhook.h>
#include <ESP8266WiFi.h>

#define _SSID "AndroidAP8159"      // Your WiFi SSID
#define _PASSWORD "sanskriti"  // Your WiFi Password
#define KEY "j3Xcnk9IC7OAtdTaSbSFpl50X3udWA0_Pchdlpqw3HE"        // Webhooks Key
#define EVENT "Emergency"      // Webhooks Event Name

const int flexPin = A0; //pin A0 to read analog input
int value; //save analog value
int led = 5;

Webhook webhook(KEY, EVENT);    // Create an object.

void setup() {
  Serial.begin(115200);
  pinMode(flexPin, INPUT);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  // Connect to WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  

//================================================================//

}

void loop() {
  value = analogRead(flexPin);         //Read and save analog value from potentiometer
  Serial.println(value);
  if(value<100){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
    webhook.trigger(String(value));
  }
  
  delay(5000);

}
