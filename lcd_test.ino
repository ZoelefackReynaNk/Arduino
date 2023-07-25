// Include the library code
#include <LiquidCrystal.h>
// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
// Set up the LCD's number of columns and rows
lcd.begin(16, 2);
// Print a message to the LCD

}
void loop() {

  lcd.print("ZoelefackRey");
delay(1000);
// Scroll 13 positions (string length) to the left
// to move it offscreen left
}
