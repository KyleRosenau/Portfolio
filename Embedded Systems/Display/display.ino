#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
  lcd.begin(2,16);
  lcd.print("Hello world");
  delay(1000);
}
void loop()
{
  lcd.setCursor(0,1);
} 