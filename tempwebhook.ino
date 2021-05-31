
int led2 = D7; 
int led1 = D6;

int photoresistor = A0;
int analogValue;

String light = "";


void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(photoresistor, INPUT);
  Particle.variable("light", light);
  digitalWrite(led1, HIGH);

}


void loop() {
    
    analogValue = analogRead(photoresistor);
    light = analogValue;
    Particle.publish("light", light, PRIVATE);
    if (analogValue <= 45)
    {
        digitalWrite(led1, LOW);
    }
    else
    {
        digitalWrite(led1, HIGH);
    }
    delay(2000);
    
}