#include <TinyGPS.h>
#include <SoftwareSerial.h>
SoftwareSerial GPS(D3,D4); // configure software serial port 

// Create an instance of the TinyGPS object
TinyGPS shield;
void setup()
{
  Serial.begin(9600);
  GPS.begin(9600);
 
}

// The getgps function will interpret data from GPS and display on serial monitor
void getgps(TinyGPS &gps)
{
  int year;
  byte month, day, hour, minute, second, hundredths, kmh, mph;
  shield.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);

  // Print data and time
  kmh=gps.f_speed_kmph();

  Serial.print(kmh, DEC);
  Serial.print(" km/h      ");
/*  
  mph = kmh * 1.6;
  lcd.print(mph, DEC);
  lcd.print(" MPH   ");
*/
}

void loop()
{
  byte a;
  if ( GPS.available() > 0 ) // if there is data coming from the GPS shield
  {
    a = GPS.read(); // get the byte of data
    if(shield.encode(a)) // if there is valid GPS data...
    {
      getgps(shield); // then grab the data and display it on the LCD
    }
  }
}

