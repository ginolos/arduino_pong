int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int val = 0;  // variable to store the value read

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  val = map(val, 200, 600, 0, 400);
//  Serial.println(val);          // debug value
  
  //Serial.print("%d %d", val, val);
  Serial.print(val);
  Serial.print(" ");
  Serial.print(val);
  Serial.print("*");
  delay(500);
}
