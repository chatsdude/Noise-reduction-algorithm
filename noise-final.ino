const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;
int check=0,lastread=0,d2,d1=0,d3;
int diff;
void setup()
{
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop()
{



digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
//Serial.print("Distance: ");
//Serial.println(distance);

if(check>=2)
{
if(distance>=(d3 - 3) && distance<=(d3 + 3))
{
  Serial.print("                      CONTINUE");
}
else
{
  Serial.print("                      STOP");
}
check=3;
}

d2=distance-d1;
d1=distance;
Serial.print("Difference ");
Serial.println(d2);

d3=distance + d2;

check++;

/*

if(check==0)
{
d1=distance;
check=1;
if(lastread==1)
{
  diff=d3-d2;
}

}

else if(check==1)
{
d2=d1;
d3=distance;
check=0;
lastread=1;
}
*/}
