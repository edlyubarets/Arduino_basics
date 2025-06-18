#define led_pin_1 2
#define led_pin_10 11
#define up_pin 12
#define down_pin 13

int number = 0;
int out = led_pin_1;

void setup() {
  // ініціалізація виводів плати, як виходів
  for (int i = led_pin_1; i <= led_pin_10; i++) {
    pinMode(i, OUTPUT);
  }
  // ініціалізація виводу як входу
  pinMode(up_pin, INPUT);
  pinMode(down_pin, INPUT);
}

void loop() {
  // опитування виводу, до якого підключено кнопку:
  if (!digitalRead(up_pin) && number < led_pin_10) {
    number++;
    delay(200); // Затримка для усування ефекту вібрації контакту
  }
  if (!digitalRead(down_pin) && number > (led_pin_1 - 2)) {
    number--;
    delay(200);
  }
  for(int i = led_pin_1; i <= led_pin_10; i++) {
    if(i <= number + 1) {
      digitalWrite(i, HIGH);
    } 
    else {
      digitalWrite(i, LOW);
    }
  }  
}
