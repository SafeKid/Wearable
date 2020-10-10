#include <ESP8266WiFi.h>
//#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
//#include <ArduinoJson.h>
// #include <ESP8266HTTPClient.h>

// Set these to run example.
#define FIREBASE_HOST "nodemcutest-e3dc01.firebaseio.com"
#define FIREBASE_AUTH "W2JKo1aKnnASbApkMr95MdOFXeym5OSJv1XvH9Ip"
#define WIFI_SSID "Navagamuwa Residence"
#define WIFI_PASSWORD "i@home123"

int val=0, val3=1000;

void setup() {

  Serial.begin(115200);

  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase
delay(1000);
}

void loop() { 

// Firebase Error Handling ************************************************
  if (Firebase.failed())
  { delay(500);
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Serial.println(Firebase.error());
  Serial.println("Connection to firebase failed. Reconnecting...");
  delay(500);
  }
  
 else { 
    Serial.println("Everything is ready!");
    delay(300); Serial.println("Everything is ready!");
    delay(300); Serial.println("Everything is ready! \n \n \n");
    delay(300);


    Firebase.setInt("/data/test",val);
   Serial.println(val);
    delay(300); Serial.println("uploaded val to firebase \n \n \n");

      Firebase.setInt("/test/val3",val3);
   Serial.println(val3);
    delay(300); Serial.println("uploaded val3 to firebase \n \n \n");
  

  val++; val3++;
 }



  
} 
