const float Lmax = 865;
const float Lmin = 175;

void setup() {
pinMode(3, OUTPUT);
Serial.begin(9600);

}

void loop() {
  float L = analogRead(A0);
  Serial.println (L);
  float LED = (Lmax - L) * 255.0 / (Lmax - Lmin);
  if(LED <= 0) {
    LED = 0;
  }
  if(LED >= 255) {
    LED =255;
  }
  analogWrite(3, LED);

}
