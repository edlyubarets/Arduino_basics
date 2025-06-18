#include<TM1637.h>
#include <DHT11.h>

#define CLK 3 
#define DIO 2
#define DHT 4
#define button_pin 5
DHT11 dht11(DHT); 
TM1637 tm1637(CLK, DIO);
 
void setup() {
tm1637.init();
tm1637.set(BRIGHT_TYPICAL);

pinMode(button_pin, INPUT);

Serial.begin(9600);
}

void loop() {
  
  if(!digitalRead(button_pin)) {
    int temperature = 0;
    int humidity = 0;

    int result = dht11.readTemperatureHumidity(temperature, humidity);

    if (result == 0) {
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" °C\tHumidity: ");
      Serial.print(humidity);
      Serial.println(" %");
    } 
    else {
      Serial.println(DHT11::getErrorString(result));
    }

    int t_single = temperature % 10;
    int t_decimal = temperature / 10;
    int h_single = humidity % 10;
    int h_decimal = humidity / 10;
    

    tm1637.display(0, t_decimal);
    tm1637.display(1, t_single);
    tm1637.displayByte(3, 185); //10111001
    delay(2000);
    tm1637.clearDisplay();
    tm1637.display(0, h_decimal);
    tm1637.display(1, h_single);
    tm1637.displayByte(3, 118); //1110110
    delay(2000);
    tm1637.clearDisplay();
  }  
}
