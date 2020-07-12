void setup() {
  Serial.begin(9600);
}

void loop() {
  int x;
  x=random(67,70);
  Serial.print("Hear rate is ");
  Serial.print(x);
  Serial.println(" ");
  delay(800);
  

}
