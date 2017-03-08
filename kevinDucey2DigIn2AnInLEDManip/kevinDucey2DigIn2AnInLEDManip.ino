void setup() {
  Serial.begin(9600);
  pinMode(A2, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);    // initializing serial and setting outputs to LEDs
}

void loop() {
  int sensorValue1 = analogRead(A0) / 100; // taking in photocell value, dividing it by 100
  int sensorValue2 = analogRead(A1); // taking in pot value
  int sensorValue3 = digitalRead(2); // taking in switch value
  int sensorValue4 = digitalRead(4); // taking in other switch value
  int d1 = 1500; // first delay size
  int d2 = 750; // second delay size
  int d3 = 300; // third delay size

  Serial.print(sensorValue1);
  Serial.print("     ");
  Serial.print(sensorValue2);
  Serial.print("     ");
  Serial.print(sensorValue3);
  Serial.print("     ");
  Serial.println(sensorValue4);
  delay(10);                       //printing all sensor values and delaying prints by 10ms (depending how long rest of loop takes)

  if(sensorValue3 == 1){
    d1 = 10;
    d2 = 10;
    d3 = 10;
  }

  else if(sensorValue4 == 1){
    d1 = 150;
    d2 = 75;
    d3 = 30;
  }

  else {
    d1 = 1500;
    d2 = 750;
    d3 = 300;
  }
  
  if(sensorValue2 > 100) {   // i.e. if the pot is turned above 100
    analogWrite(A2, sensorValue2);   // turn on the LED next to the photocell
  }
  else{
    analogWrite(A2, 0); // if the pot is turned down, turn the LED off
  }
  
  if(sensorValue1 == 7) {   //i.e. if the LED is reading anywhere in the 700s ( will probably need to reconfigure this in different spaces.)
  digitalWrite(12, HIGH);   // this was the control state -- no manipulation
  delay(d1 / sensorValue1);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(d2 / sensorValue1);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);  
  delay(d3 / sensorValue1);
  digitalWrite(10, LOW);
  }
  else if(sensorValue1 == 8) {  // "  "
  digitalWrite(12, HIGH);       // this was the LED manipulated state
  delay(2 * d1 / sensorValue1);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(2 * d2 / sensorValue1);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);  
  delay(2 * d3 / sensorValue1);
  digitalWrite(10, LOW);
  }
  else if(sensorValue1 == 5) {  // "  "
  digitalWrite(12, HIGH);       // this was the covered-with-fingers state
  delay(d1 / 2 * sensorValue1);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(d2 / 2 * sensorValue1);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);  
  delay(d3 / 2 * sensorValue1);
  digitalWrite(10, LOW);
  }
  else{
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);  // if the photocell isn't showing any of these three conditional values, turn it off.
  }
  
}
