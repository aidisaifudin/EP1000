#include <UltraDistSensor.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x27,16,2);

UltraDistSensor mysensor;
float reading;
int redPin= 7;
int greenPin = 6;
int bluePin = 5;

const int buzzer = 11;

String message1 = String("      Welcome Aidi!");
String message2 = String("      Goodbye Aidi!");
int length;





void setup()
{
 
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  mysensor.attach(9,10); //trigger,echo
  length = message1.length();
  length = message2.length();

 pinMode(buzzer, OUTPUT);
   
 

}

void loop()
{

  reading = mysensor.distanceInCm();
  lcd.setCursor(0,0);
  


  
 
    for(int i = 0; i < length; i ++)
    {
    if(reading < 49) 
  {
    
     

    ClearRow(0);
    lcd.print(message1.substring(i,i+15));
    delay(100);
    digitalWrite(buzzer, HIGH);
    setColor(0, 0, 255); // Blue Color
    }
    
   }

   
   
    for(int i = 0; i < length; i ++)
    {
    if(reading > 50)
   {
    ClearRow(0);
    lcd.print(message2.substring(i,i+15));
    delay(100);
    digitalWrite(buzzer, LOW);
    setColor(255, 0, 0); // Red Color
   }
    }
    
   
  

  
  
   

  
  /*if((reading < 49)) 
  {
    lcd.clear();
    lcd.print("Welcome Aidi!");
     setColor(255, 0, 255); // purple Color
    
   }
   else if(reading > 50)
 {
   lcd.clear();
   lcd.print("Goodbye Aidi!");
   
   
   
     
  }
*/
  
  
  }
  
void ClearRow(int rowNum)
{
  lcd.setCursor(0,rowNum);
  lcd.print("                    ");
  lcd.setCursor(0,rowNum);
}

void setColor(int redValue, int greenValue, int blueValue) 
{
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
