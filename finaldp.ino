// first check port
// upload the code and make sure yuy chane your phone number
// click on serial monitor


#define trigPin 12
#define echoPin 13
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);//connect RX to pin 10 , connect TX to pin 9

int duration, distance;

void setup()
{
  Serial.begin(9600); 

  // Setting the baud rate of GSM Module  
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT); //defin ultrasonic tri pin as out put pin 
  pinMode(echoPin, INPUT);  //defin ultrasonic echo as in put pin
  delay(100);
}


void loop()
{
 
    //setting for ultrasonic sensor reading

    
    digitalWrite(trigPin, HIGH); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;

    
  if (distance >= 7 || distance <= 0) 
        {
        Serial.println("bin is empty");
        Serial.print("distance= ");              
        Serial.print(distance);

        delay(1000);
        
        }
     
  else {
    
    
        Serial.println("bin is full \n");
        Serial.print("distance= ");              
        Serial.print(distance);    
           SendMessage();
           // code for send SMS
           }
            if (distance >= 15 || distance <= 0) 
        {
        Serial.println("bin is empty");
        Serial.print("distance= ");              
        Serial.print(distance);

        delay(1000);
        
        }
         else {
    
    
        Serial.println("bin is 50%full \n");
        Serial.print("distance= ");              
        Serial.print(distance);    
           SendMessage();
           // code for send SMS
           }
  }
void SendMessage()
  {
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918143674607\"\r"); // Replace x with your mobile number(not the number which insert in to gsm module)
  delay(1000);
  mySerial.println(" ");
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  }
