#define button_1_pin 1
#define button_2_pin 2
#define buzzer_pin 3

int frequency = 2000;
int check = 0;

void SOS(int freq) {
  int frequency = freq;
  const int point = 100;
  const int dash = 200;
  tone(buzzer_pin, frequency, point);
  delay(200);
  tone(buzzer_pin, frequency, point);
  delay(200);
  tone(buzzer_pin, frequency, point);
  delay(200);
  tone(buzzer_pin, frequency, dash);
  delay(300);
  tone(buzzer_pin, frequency, dash);
  delay(300);
  tone(buzzer_pin, frequency, dash);
  delay(300);
  tone(buzzer_pin, frequency, point);
  delay(200);
  tone(buzzer_pin, frequency, point);
  delay(200);
  tone(buzzer_pin, frequency, point);
  delay(100);
}



void setup() {
pinMode(button_1_pin,INPUT);
pinMode(button_2_pin,INPUT);
pinMode(buzzer_pin,OUTPUT);

}

void loop() {
  if (!digitalRead(button_1_pin)) {
    check = 1;
    delay(200);
  }
  if (!digitalRead(button_2_pin)) {
    check = 0;
    delay(200);
  }
  if(check) {
    SOS(frequency);
    delay(2000);
  }
} 
