#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal.h>

int sensor = 0;
int vee_lcd = 13;
int rs_lcd = 12;
int e_lcd = 11;
int d4_lcd = 9;
int d5_lcd = 8;
int d6_lcd = 7;
int d7_lcd = 6;
int temp;
int umidade;
String mensagem1 = "Sergio Baez ";
String mensagem2 = "OK ";

DHT dht(sensor, DHT11);
LiquidCrystal lcd(rs_lcd, e_lcd, d4_lcd, d5_lcd, d6_lcd, d7_lcd);
void setup(){
  dht.begin();
  lcd.begin(16, 2);
  analogWrite (vee_lcd, 50);  
  }

void loop(){
  int tam = mensagem1.length();
  int tam2 = mensagem2.length();
  umidade = dht.readHumidity();
  temp = dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Umidade: ");
  lcd.print(umidade);
  lcd.print("%");
  delay(5000);

  for (int i = 1; i <= tam; i++) {
    String texto = mensagem1.substring(i - 1);
    lcd.clear(); // Limpar a tela
    lcd.setCursor(0, 1); // Coluna 0 e linha 1
    lcd.print(texto);

    delay(182);
}

for (int i = 1; i <= tam2; i++) {
    String texto2 = mensagem2.substring(i - 1);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(texto2);

    delay(200);
}

}

