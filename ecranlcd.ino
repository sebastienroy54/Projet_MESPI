
/*J’utilise un tableau de 16 cases car mon écran fait 16 caractères de large au maximum, et donc inutile de gaspiller de la mémoire en prenant un tableau plus grand que nécessaire.*/


#include <LiquidCrystal.h>


// Initalisation de la librairie
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  analogWrite(8,15);
  // Affiche un message
  lcd.print("Pas de doigt");
}

void loop() {

}
