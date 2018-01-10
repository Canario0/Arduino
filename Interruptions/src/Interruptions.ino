 
// global variable for speed
volatile int speed = 20;
// Constant values for maximun , minimu speed the increase
const int maximun = 1000;
const int minimun = 20;
const int increase = 20;
 
// Array con los números de los pines donde están conectados
// los LEDs de las luces del coche fantástico
int leds[5] = {8, 9, 10, 11, 12};
 
void setup() {
  Serial.begin(9600);
  while(!Serial){

  }
  // set all led pins to output and low
  for (int i = 0; i < 5; i++)
  {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
 
  // set the initial speed to minimun value
  speed = minimun;
 
  // attach the interrup
  attachInterrupt(digitalPinToInterrupt(2), speedDecrease, RISING);
  attachInterrupt(digitalPinToInterrupt(3), speedIncrease, RISING);
 
}
 
void loop() {
  // go through all the elements in the array setting to high one pin and setting to low the one before
  for (int i = 0; i < 5; i++)
  {
    if (i > 0)
    {
      // set to low the pin before the one we are
      digitalWrite(leds[i - 1], LOW);
    }
 
    // set to high the actual pin
    digitalWrite(leds[i], HIGH);
 
    // delay the time set by the speed
    delay(speed);
  }
 
  // set to low the last high pin
  digitalWrite(leds[4], LOW);
 
   // go through all the elements backwards setting to high one pin and setting to low the one before
  for (int i = 4; i >= 0; i--)
  {
    // En el primer caso como ya está apagado el LED no hacemos nada
    // Cuidado que nos salimos del rango del array 4+1=5 no existe este elemento
    if (i < 4)
    {
      // set to low the pin before the one we are
      digitalWrite(leds[i + 1], LOW);
    }
    // set to high the actual pin
    digitalWrite(leds[i], HIGH);
 
    // delay the time set by the speed
    delay(speed);
  }
 
  // set to low the last high pin
  digitalWrite(leds[0], LOW);
 
}
 
// ISR pin 2, decrease the speed
void speedDecrease()
{
  speed = speed - increase;
 
  // if the value is lower than the minimun speed, set speed to the minimun value
  if (speed < minimun)
  {
    speed = minimun;
  }
}
 
// ISR pin 3, increase the speed
void speedIncrease()
{

  speed = speed + increase;
 
  // if the value is greater than the maximun speed, set speed to the maximun value
  if (speed > maximun)
  {
    speed = maximun;
  }
}