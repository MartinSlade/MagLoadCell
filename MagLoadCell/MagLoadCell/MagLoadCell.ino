//#include <LiquidCrystal_I2C.h>
#include "./src/Arduino-LiquidCrystal-I2C-library-master/LiquidCrystal_I2C.h"

//#include <HX711_ADC.h>
#include "./src/HX711_ADC-master/src/HX711_ADC.h"
#include <Wire.h>



HX711_ADC LoadCell (4,5);

//LiquidCrystal_I2C lcd(0x27, 4, 5, 6, 0, 1, 2, 3, 7, POSITIVE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
LoadCell.begin();
LoadCell.start(2000);
LoadCell.setCalFactor(999.0);
lcd.begin();
lcd.backlight();
}

void loop() {
LoadCell.update();
float i = LoadCell.getData();
lcd.setCursor(0, 0);
 lcd.print("Weight[g]:");
 lcd.setCursor(0, 1);
 lcd.print(i);
}
