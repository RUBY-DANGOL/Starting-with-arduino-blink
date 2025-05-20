const int trig = 9;
const int echo = 10;
int LED1=5;
int LED2=6;
int LED3=7;



long duration = 0;
int distance = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(LED1  , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  
}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);
  digitalWrite(LED1 , LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5;

  if(distance < 20){
    digitalWrite(LED1 , HIGH);
  }
  if (distance <30 ){
    digitalWrite (LED2 , HIGH);
  }
  if (distance < 40) {
    digitalWrite (LED3, HIGH);
  }

  
  Serial.println(distance);

}
