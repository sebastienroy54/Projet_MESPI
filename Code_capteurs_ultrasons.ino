/* Ultrason droite */
const byte TRIGGER_PIN_dr = 22; // Broche TRIGGER
const byte ECHO_PIN_dr = 24;    // Broche ECHO

/* Ultrason gauche */
const byte TRIGGER_PIN_gauch = 32; // Broche TRIGGER
const byte ECHO_PIN_gauch = 30;    // Broche ECHO

/* Ultrason devant */
const byte TRIGGER_PIN_dvt = 28; // Broche TRIGGER
const byte ECHO_PIN_dvt = 26;    // Broche ECHO

/* Constantes pour le timeout: le temps a  partir duquel le capteur considere qu'il n'y a aucun obstacle a  portee (temps de parcours d'environ 25 ms soit 8m aller-retour. Le capteur n'est pas sensible au dela de 4 m.) */
const unsigned long MEASURE_TIMEOUT = 50000UL; // 25ms = ~8m a 340m/s

/* Vitesse du son dans l'air en mm/microsecondes */
const float SOUND_SPEED = 340.0 / 1000;


void setup() {
  /* Initialise le port serie */
  Serial.begin(115200);

  /* Initialise les broches */
  pinMode(TRIGGER_PIN_dr, OUTPUT);
  digitalWrite(TRIGGER_PIN_dr, LOW); // La broche TRIGGER doit etre LOW au repos
  pinMode(ECHO_PIN_dr, INPUT);

  pinMode(TRIGGER_PIN_gauch, OUTPUT);
  digitalWrite(TRIGGER_PIN_gauch, LOW); // La broche TRIGGER doit etre LOW au repos
  pinMode(ECHO_PIN_gauch, INPUT);

  pinMode(TRIGGER_PIN_dvt, OUTPUT);
  digitalWrite(TRIGGER_PIN_dvt, LOW); // La broche TRIGGER doit etre LOW au repos
  pinMode(ECHO_PIN_dvt, INPUT);

}

void loop() {
 /* Ultrason droite */
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10 microsec sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN_dr , HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_dr , LOW);
 
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son echo (s'il existe) */
  long measured = pulseIn(ECHO_PIN_dr, HIGH, MEASURE_TIMEOUT);
 
  /* 3. Calcule la distance Ã  partir du temps mesurÃ© */
  float distance_droite = measured / 2.0 * SOUND_SPEED;


/* Ultrason gauche */
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10 microsec sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN_gauch, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_gauch, LOW);
 
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son echo (s'il existe) */
  long measureg = pulseIn(ECHO_PIN_gauch, HIGH, MEASURE_TIMEOUT);
 
  /* 3. Calcule la distance Ã  partir du temps mesuré */
  float distance_gauche = measureg / 2.0 * SOUND_SPEED;


/* Ultrason devant */
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10 microsec sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN_dvt, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_dvt, LOW);
 
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son echo (s'il existe) */
  long measuredv = pulseIn(ECHO_PIN_dvt, HIGH, MEASURE_TIMEOUT);
 
  /* 3. Calcule la distance Ã  partir du temps mesuré */
  float distance_devant = measuredv / 2.0 * SOUND_SPEED;
  if(distance_droite/1000 < 1){ // CHANGER ICI LA DISTANCE DE DETECTION D'OBSTACLES
      // Affiche un message
      lcd.print("Obstacle a droite "); // si un obstacle est a moins de 1m
      delay(2000);
      temps+=2;
      lcd.clear();
      }
    
  if(distance_gauche/1000 < 1){ // CHANGER ICI LA DISTANCE DE DETECTION D'OBSTACLES
      // Affiche un message
      lcd.print("Obstacle a gauche "); // si un obstacle est a moins de 1m
      delay(2000);
      temps+=2;
      lcd.clear();
      }
    
  if(distance_devant/1000 < 1){ // CHANGER ICI LA DISTANCE DE DETECTION D'OBSTACLES
      // Affiche un message
      lcd.print("Obstacle devant "); // si un obstacle est a moins de 1m
      delay(2000);
      temps+=2;
      lcd.clear();
      }
  // Affiche les resultats en m et le temps
  Serial.print(F("Distance: "));
  Serial.print(distance_devant / 1000.0, 2);
  Serial.println(F("m"));
}
