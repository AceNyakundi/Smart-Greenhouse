#A Smart-Greenhouse system using Arduino with a web application showing graphs for temperature and humidity variation 
SGS is an Arduino controlled Greenhouse system developed by Obed Nyakundi

Sensors I used were:
DHT11 attached to pin 2 in the digital pins
An LDR connected to Analog pin 0  

I used the following actuators
A light bulb connected to digital 3 via a relay
A fan connected to digital pin 4 via a power relay too  
A water pump to dogotal pin 5. in case you intend to use a bigger pump, you can as well use a relay
A buzzer at pin 6. The buzzer should warn you when temp/humidity rises or exceeds the uncontrollable measures by SGS system

The set extreme limits are: 
maximum temperature at 25*C 
minimum temperature is 10*C

minimum light measures (using the LDR resistance estimate) of 1000 ohms 

maximim humidity at 80% 
minimum Humidity at 20%

minimum moisture at 60 units //soil moisture

The current code is incomplete. I will update it when I get adequate time to progress with it.
