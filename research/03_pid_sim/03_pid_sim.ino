// variabili

float pitch = 0.0;  //avanti - dietro
float roll = 0.0;   //sinistra - destra
float target_pitch = 0.0; // Vogliamo il drone piatto (0 gradi)
float target_roll = 0.0;

// Costanti ( valore in base al motore ) usati per PID 
float Kp = 2.0;    
float Ki = 0.05;
float Kd = 1.0;

// Variabili di memoria per il PID
float errore_precedente_pitch = 0.0;
float integrale_pitch = 0.0;
float errore_precedente_roll = 0.0;
float integrale_roll = 0.0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // 2. PASSAGGIO 1: Dati simulati (il drone oscilla)
  pitch = 15.0 * sin(millis() / 500.0);  //placeholder per simulare movimento
  roll = 15.0 * cos(millis() /500.0 );   //placeholder per simulare movimento

  // 3. PASSAGGIO 2: Algoritmo PID sul Pitch
  float errore_pitch = target_pitch - pitch;
  float errore_roll = target_roll - roll;
  
  float P_pitch = Kp * errore_pitch;                                // si occupa del errore immediato
  integrale_pitch = integrale_pitch + (Ki * errore_pitch);          // si occupa del piccolo errore nel tempo
  float D_pitch = Kd * (errore_pitch - errore_precedente_pitch);    // vede velocita per evitare di esagerare

  float P_roll = Kp * errore_roll;
  integrale_roll = integrale_roll + (Ki * errore_roll);
  float D_roll = Kd * (errore_roll - errore_precedente_roll);
  
  errore_precedente_pitch = errore_pitch;
  errore_precedente_roll = errore_roll;
  
  // potenze totali per raddrizzare pitch e roll
  float pid_pitch = P_pitch + integrale_pitch + D_pitch; 
  float pid_roll = P_roll + integrale_roll + D_roll;

  int throttle = 1400; //potenza base per galleggiare
  //  distribuzione delle potenze ai quattro motori
  int motore_FL = throttle + pid_pitch + pid_roll; // Anteriore Sinistra 
  int motore_FR = throttle + pid_pitch - pid_roll; 
  int motore_BL = throttle - pid_pitch + pid_roll; 
  int motore_BR = throttle - pid_pitch - pid_roll; // Posteriore Destra

  //da aggiungere fuori dalla simulazione -> motore_FL = constrain(motore_FL, 1000, 2000);, perche i motori hanno un limite massimo
  // grafico
  Serial.print("Motore_FL:");
  Serial.print(motore_FL);
  Serial.print(",");       // assegna un altra linea al successivo
  Serial.print("Motore_FR:");
  Serial.print(motore_FR);
  Serial.print(",");
  Serial.print("Motore_BL:");
  Serial.print(motore_BL);
  Serial.print(",");
  Serial.print("Motore_BR:");
  Serial.println(motore_BR);

  delay(20); //fuori dalla simulazione da sostistuire con micros in un certo modo
}