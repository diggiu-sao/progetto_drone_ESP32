import processing.serial.*;

Serial myPort;
float roll = 0;
float pitch = 0;

void setup() {
  size(800, 600, P3D); 
  
  // Cambia lo 0 nell'array se l'ESP32 si trova su una porta diversa
  String portName = Serial.list()[0]; 
  myPort = new Serial(this, portName, 115200);
  myPort.bufferUntil('\n'); 
}

void draw() {
  background(40); 
  lights();       
  
  translate(width/2, height/2, 0);
  
  rotateX(radians(-pitch)); 
  rotateZ(radians(roll));
  
  // Telaio del drone (azzurro)
  fill(50, 150, 255);
  box(300, 10, 300);
  
  // Indicatore frontale (rosso)
  translate(150, 0, 0);
  fill(255, 50, 50);
  box(20, 20, 20);
}

void serialEvent(Serial myPort) {
  String inString = myPort.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);
    float[] values = float(split(inString, ','));
    if (values.length == 2) {
      roll = values[0];
      pitch = values[1];
    }
  }
}
