
#include<DHT.h>

//define sensors
#define dhtpin 2 
#define light A0 

//define actuators
#define bulb 3
#define fan 4  
#define pump 5
#define buzzer 6 //this is for warning incase temp/humidity is uncontrollable

//define control limits
#define maxTemp 25 //temperature in *C
#define minTemp 10

#define minLight 1000 //minimum light

#define maxHumidity 80 //maximum humidity
#define minHumidity 20

#define minMoisture 60 //soil moisture



class controller
{
 public:
     //constructor is empty for now
    controller()
     {
       
     }
   
       //light controller
   void lightControl(int value)
   {
     //method for regulating temperature and humidity
     if(value < minLight)
     {
        digitalWrite(bulb,HIGH); //light the bulb
        Serial.println("Bulb is powered on");
     }
     else
     {
       digitalWrite(bulb,LOW);
       Serial.println("bulb is switched off");
     }
   }
 
      //humidity controller
   void humidityControl(float value)
   {
     if(value > maxHumidity)
      {
        digitalWrite(fan,1);//switch on the fan
        Serial.println("Fan is powered on due to humidity");
      }
      else
      {
        digitalWrite(fan,0);
        Serial.println("Fan is switched off");
      }
   }
   
   //function overload for humidity
   void humidityControl(int value)
   {
     if(value > maxHumidity)
      {
        digitalWrite(fan,1);
         Serial.println("Fan is powered on due to high humidity");
      }
      else
      {
        digitalWrite(fan,0);
      }
   }
   
       //Temperature controller
   void tempControl(float value)
   {
     if(value > maxTemp)
      {
        digitalWrite(fan,1);
         Serial.println("Fan is powered on due to high temperature");
      }
      else
      {
        digitalWrite(fan,0);
      }
   }
   
      //function overload for Temperature controller
   void tempControl(int value)
   {
     if(value > maxTemp)
      {
        digitalWrite(fan,1);
         Serial.println("Fan is powered on due to high temperature");
      }
      else
      {
        digitalWrite(fan,0);
      }
   }
   
   //this method lights the buzzer for warning incase the temperature or humidity is too low for control
   
   
 
};


DHT dht(dhtpin,DHT11);

void setup()
{
  pinMode(light,INPUT);
  
  pinMode(bulb,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(pump,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  Serial.begin(9600);
  dht.begin();
}

//loop
void loop()
{
  float temp,humidity;
  int brightness;
  
  temp=dht.readTemperature();
  humidity=dht.readHumidity();
  
  brightness=analogRead(light);
  
  //implement extreme and control limits with buzzer warning
  if(temp <= minTemp || humidity <= minHumidity)
  {
    digitalWrite(buzzer,HIGH);
  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
  
  //implement controller for controllable variables
  controller control;
  control.lightControl(brightness);
  control.humidityControl(humidity);
  control.tempControl(temp);
  
  Serial.print("current temperature ");
  Serial.print(temp);
  Serial.print("*C current humidity ");
  Serial.print(humidity);
  Serial.print("%");
  Serial.println();
  Serial.print("Current light level ");
  Serial.print(brightness);
  
  Serial.println();
  
  delay(1500);
  
}
