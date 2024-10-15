#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 20, 4); // default address (for most modules)

// bobbin width
// (total)spins
// number of wires (in parallel)
// wire gauge
// circumference (bobbin)



void demo(){
  for(int i = 0; i<=100 ;i++){
    //spin value
    lcd.setCursor(5,0);
    lcd.print(i);

    //bobbin cir value
    lcd.setCursor(17,0);
    lcd.print(i-1);

    if(i<60){
      //wires value
      lcd.setCursor(6,1);
      lcd.print(i/10);
    }
    //width value
    lcd.setCursor(6,2);
    lcd.print(i-1);

    if(i<26){
      //gauge value
      lcd.setCursor(6,3);
      lcd.print(i-1);
      
    }



    delay(100);

  }
  delay(1000);
  
  // clear screen of numbers

    //spin
    lcd.setCursor(5,0);
    lcd.print("   ");
    //bobbin cir
    lcd.setCursor(17,0);
    lcd.print("   ");
    //wires
    lcd.setCursor(6,1);
    lcd.print("  ");
    //width
    lcd.setCursor(6,2);
    lcd.print("  ");
    //gauge
    lcd.setCursor(6,3);
    lcd.print("  ");


    delay(200);

}

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("Spin:");

  lcd.setCursor(9,0);
  lcd.print("Bob Cir:");
  
  lcd.setCursor(0,1);
  lcd.print("Wires:");

  lcd.setCursor(0,2);
  lcd.print("Width:");

  lcd.setCursor(0,3);
  lcd.print("Gauge:");

  lcd.setCursor(13,3);
  lcd.print("[START]");

}

void loop()
{
  demo();
  lcd.setCursor(0,3);
}