// define the stepper driver pins
#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11
#define LED 6

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;


double Delay;
double Rotation=0.083333333333333;
int PillNum;
int NumOfTime=5;
int Times [5];
int p;
double t;
double tm;

int speakerPin = 3;

int analogPin = 0;
int val = 0;           // variable to store the value read
const int threshold = 200;

// define how many cycles to a full rotation
#define CYCLES_PER_ROTATION 512

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(LED, OUTPUT);

    Wire.begin();
    RTC.begin();
  // Check to see if the RTC is keeping time.  If it is, load the time from your computer.
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // This will reflect the time that your sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }


    //Setting times for the show case at the presentation
  Times[0]=36;
  Times[1]=37;
  Times[2]=38;
  Times[3]=39;
  Times[4]=40;
  Delay=0;
  PillNum=1;
  p=0;

  pinMode (speakerPin, OUTPUT);
}

void loop()
{
//    Serial.print(DateTime(__DATE__,__TIME__));
    DateTime now = RTC.now();
   //Serial.print(now.minute(), DEC);
   //Serial.println();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    t = now.second();
    tm = now.minute();

    if (tm==Times[p])
    {

    turns(PillNum*Rotation);
    analogWrite (speakerPin, 300);
    delay(50);
    analogWrite (speakerPin, 0);
    digitalWrite(LED, HIGH);
      p=p+1;

      if (p==5)
      {
        p=0;
    Serial.print(p);
    Serial.print(" is the time, it managed to reset");
    Serial.println();
      }
      }
   /* else
    {
    Serial.print("Not yet");
    Serial.println();

    }*/

val = analogRead(analogPin);    // read the input pin

if (val >= threshold) {

    Serial.println("Pill taken");
    digitalWrite(LED, LOW);
  }

delay(500);


}

void turns(float rotations)
{
  // if the rotation count is -ve then it is CCW
 // Serial.println();
 // Serial.print("Turning : ");
 // Serial.print(rotations);
 // Serial.println(" rotations");
  bool clockwise = rotations > 0;
 // Serial.print("Clockwise = ");
 // Serial.println(clockwise);
  // calculate how many cycles the stepper will have to make
  int cycles = rotations * CYCLES_PER_ROTATION;
  // force the cycle count to be positive
  cycles = abs(cycles);
 // Serial.print("That is ");
 // Serial.print(cycles);
 // Serial.print(" Cycles ");
  // only move if the user specifed an actual movement
  if(rotations != 0)
  {
    if (clockwise)
    {
   //   Serial.println("Clockwise");
      // for each cycle
      for (int x=0; x<cycles; x++)
      {
        // for each phase
        for(int y=0; y<8; y++)
        {
          // go to phase y
          phaseSelect(y);
          // pause so the stepper has time to react
          delay(1);
        }
      }
    } else {
     // Serial.println("Counter Clockwise");
      // for each cycle
      for (int x=0; x<cycles; x++)
      {
        // for each phase (backwards for CCW rotation)
        for(int y=7; y>=0; y--)
        {
          // go to phase y
          phaseSelect(y);
          // pause so the stepper has time to react
          delay(1);
        }
      }
    }
  }
  // go to the default state (all poles off) when finished
  phaseSelect(8);
 // Serial.println("Done");
}

void phaseSelect(int phase)
{
  switch(phase){
     case 0:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, HIGH);
       break;
     case 1:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, HIGH);
       break;
     case 2:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);
       break;
     case 3:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);
       break;
     case 4:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       break;
     case 5:
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       break;
     case 6:
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       break;
     case 7:
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, HIGH);
       break;
     default:
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       break;
  }
}

