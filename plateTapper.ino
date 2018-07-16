#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float time;
int sec;
int ms;
int start;
int count=0;
int button1 = 0; 
int button2 = 0; 
int turn=0;
const int knockSensor1 = A0; 
const int knockSensor2 = A1;
const int threshold = 100; 
  
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Zaman:");
  lcd.setCursor(0,1);
  lcd.print("Sayi:");
  start=millis()/100;
}

void loop() {
  button1 = analogRead(knockSensor1);
  button2 = analogRead(knockSensor2);


  if (button1 >= threshold && turn == 0 && count<51) {
    turn=1;
    count++;
  }
  if (button2 >= threshold && turn == 1 && count<51) {
    turn=0;
    count++;
  }
      
  if(count==0)
  {
    lcd.setCursor(5,1);
    lcd.print(0);
    lcd.setCursor(7, 0);
    lcd.print(0);
    lcd.setCursor(13, 0);
    lcd.print("s");
    start=millis();
    }
  if(count==1)
  {
    lcd.setCursor(5,1);
    lcd.print(0);
    lcd.setCursor(7,0);
    time=(millis()-start);
    time=(time/1000.0);
    lcd.print(time,2);
    
  }
  if( count>1 && count<51)
  {
     lcd.setCursor(5,1);
     lcd.print(count-1);
     lcd.setCursor(7,0);
    time=(millis()-start);
    time=(time/1000.0);
    lcd.print(time,2);
    }
   if(count==51)
   {
      lcd.setCursor(5,1);
      lcd.print(count-1);
      lcd.setCursor(8,1);
      lcd.print("Hiz:");
      lcd.setCursor(12,1);
      lcd.print(((50.0*0.8))/time,2);
      
    }

}

