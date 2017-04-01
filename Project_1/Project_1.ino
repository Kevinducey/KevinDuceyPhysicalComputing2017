void setup() {
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(3, INPUT);
pinMode(12, OUTPUT);
pinMode(5, OUTPUT);
}

void loop() {
  
int pot = analogRead(A0);
int onOff = digitalRead(A1);
int del = digitalRead(3);

Serial.print(del);
Serial.print("    ");
Serial.print(pot);
Serial.print("    ");
Serial.println(onOff);

 if( onOff ){
    tone(12, pot);
    digitalWrite(5, HIGH);
    delay(pot);
    digitalWrite(5, LOW);
    delay(pot);
  }
 else if ( del ){
    tone(12, pot);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);
    delay(100);
    tone(12, pot * 2);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);
    delay(100); 
    tone(12, pot * 2.5);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);
    delay(100); 
    tone(12, pot * 2.75);
    digitalWrite(5, HIGH);
    delay(12);
    digitalWrite(5, LOW);
    delay(100);     
    }
 else {
    tone(12, -100);
    digitalWrite(5, LOW);
 }
 }

