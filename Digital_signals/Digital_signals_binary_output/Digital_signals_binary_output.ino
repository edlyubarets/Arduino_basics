#define led_pin_1 2
#define led_pin_10 11
#define up_pin 12
#define down_pin 13

int number = 0;
int out = led_pin_1;

//converts a given number into binary
String intToBinary(int n) {
  String r;
  while(n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r; 
    n /= 2;
  }
  return r;
}

//outputs the binary string to the lights (not expecting numbers larger than     9)
void printBinary(String binaryNumber) {
  for (int i = 0; i < sizeof(binaryNumber); i++) {
    digitalWrite(led_pin_1 + i, (binaryNumber[i] == '0' ? LOW : HIGH));
  }
}

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
  if (!digitalRead(down_pin) && number > led_pin_1) {
    number--;
    delay(200);
  }
  printBinary(intToBinary(number));
   
}
