/****************************************
Please connect input P to digital pin 2, V to 3, S to 4, T to 5 and the output to 0.
It will run through each of the 16 logic combos and light up the 
on-board led if the breadboard led should be on. This evaluates PT + VST + PU + PS
****************************************/

#define ledPin 13
#define pPin 2
#define vPin 3
#define sPin 4
#define tPin 5
#define inPin 0
int delay_time = 5;
boolean on = false;
int errors = 0;

void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(pPin, OUTPUT);
pinMode(vPin, OUTPUT);
pinMode(sPin, OUTPUT);
pinMode(tPin, OUTPUT);
}

void loop() {

  for(int i = 0; i < 16; i++){
      int t = bitRead(i, 0);
      int s = bitRead(i, 1);
      int v = bitRead(i, 2);
      int p = bitRead(i, 3);
      if(p == v) 
        on = true;
      else if(p == s) 
        on = true;
      else if(p == t) 
        on = true;
      else if(s == t && s == v) 
        on = true;
      else
        on = false;
      digitalWrite(pPin, p);
      digitalWrite(vPin, v);
      digitalWrite(sPin, s);
      digitalWrite(tPin, t);
      delay(delay_time);

      boolean boolin = digitalRead(inPin);
      Serial.println("Expected: " + String(on) + " and Receved: " + String(boolin));
      if(boolin != on) 
        errors++;
    }
    
  if(errors != 0)
    fail();
  else 
    pass();
}
void fail() {
  while(true) {
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
  }
}
void pass() {
  while(true) {
    digitalWrite(13, HIGH);
    delay(1000);
  }
}
