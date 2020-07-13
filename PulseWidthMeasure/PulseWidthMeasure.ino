#define pulsePin 7

void setup() {
  pinMode(pulsePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Measuring...");
  Serial.flush();

  noInterrupts();
  double width = pulseIn(pulsePin, HIGH, 3000000UL);
  interrupts();
  
  if(width){
    Serial.print("Time High: ");
    Serial.print(width/1000000);
    Serial.println(" sec");
    Serial.println("");
  }
  else
    Serial.println("No pulse detected!!!");
}
