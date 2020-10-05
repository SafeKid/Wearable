//#include <SoftwareSerial.h>

//SoftwareSerial ss(4, 3); // GPS Module’s TX to D4 & RX to D3

void setup(){

Serial.begin(9600);

//ss.begin(9600);

}


void loop(){



Serial.write("teset");



}
