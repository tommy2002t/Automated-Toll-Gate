#include <Servo.h>
Servo servo;

int degrees=20;
int cm=0;
long distance(int trigPin, int echoPin)
{
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  digitalWrite(12, LOW);
  servo.attach(6);
  Serial.begin(9600);
}

void loop() {
  cm = 0.01723*distance(7,8);

  if(cm<30)
  {
    Serial.print(cm);
    Serial.print("cm");
  

    for (degrees=17; degrees<=120; degrees++)
    {
      servo.write(degrees);
      delay(15);
    }
    delay(1000);

    for(degrees=120; degrees>=17; degrees--)
    {
      servo.write(degrees);
      delay(15);
    }
    delay(5000);
  }
}
