#include <LiquidCrystal.h>
#include <RTClib.h>

// LCD: RS=12, E=11, D4=10, D5=9, D6=8, D7=7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
RTC_DS1307 rtc;

const int LED_VERDE    = 2;
const int LED_AMARELO  = 3;
const int LED_VERMELHO = 4;
const int BUZZER       = 5;
const int POT_TEMP     = A0;
const int POT_MAG      = A1;

// Ícones
byte icoTemp[8]  = {0b00100,0b01010,0b01010,0b01110,0b11111,0b11111,0b01110,0b00000};
byte icoMag[8]   = {0b11011,0b11011,0b11011,0b11011,0b11011,0b01110,0b00100,0b00000};
byte icoOk[8]    = {0b00000,0b00001,0b00011,0b10110,0b11100,0b01000,0b00000,0b00000};
byte icoWarn[8]  = {0b00100,0b01110,0b01110,0b01110,0b11111,0b00000,0b00100,0b00000};

unsigned long ultimoLog  = 0;
unsigned long nRegistro  = 0;
int estadoAnt = -1;

void print2d(int n) {
  if (n < 10) Serial.print("0");
  Serial.print(n);
}

void setup() {
  lcd.createChar(0, icoTemp);
  lcd.createChar(1, icoMag);
  lcd.createChar(2, icoOk);
  lcd.createChar(3, icoWarn);

  lcd.begin(16, 2);

  pinMode(LED_VERDE,    OUTPUT);
  pinMode(LED_AMARELO,  OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER,       OUTPUT);

  Serial.begin(9600);

  // RTC usa horário real do Wokwi automaticamente
  rtc.begin();

  // Tela de abertura
  lcd.setCursor(3, 0);
  lcd.print("MAGNOSPACE");
  lcd.setCursor(0, 1);
  lcd.print(" Tetrataenita  ");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DataLogger  ON");
  lcd.setCursor(0, 1);
  lcd.print("Monitorando...  ");
  delay(1500);

  lcd.clear();

  Serial.println("registro,data_hora,T\xBA=,M=,estado");
}

void loop() {
  int tRaw = analogRead(POT_TEMP);
  int mRaw = analogRead(POT_MAG);

  int tPct = map(tRaw, 0, 1023, 0, 100);
  int mPct = map(mRaw, 0, 1023, 0, 100);

  // 0=Normal 1=Alerta 2=Critico
  int estado;
  if (tRaw < 350 && mRaw > 500)                     estado = 0; // NORMAL
  else if (tRaw >= 350 && tRaw < 700 && mRaw > 500) estado = 1; // ALERTA
  else                                               estado = 2; // CRITICO

  // LEDs e buzzer
  digitalWrite(LED_VERDE,    estado == 0 ? HIGH : LOW);
  digitalWrite(LED_AMARELO,  estado == 1 ? HIGH : LOW);
  digitalWrite(LED_VERMELHO, estado == 2 ? HIGH : LOW);
  if (estado == 2) tone(BUZZER, 1000);
  else             noTone(BUZZER);

  // LCD - só limpa quando muda de estado
  if (estado != estadoAnt) {
    lcd.clear();
    estadoAnt = estado;
  }

  // Linha 0: ícone + estado
  lcd.setCursor(0, 0);
  if (estado == 0) { lcd.write(byte(2)); lcd.print(" NORMAL         "); }
  if (estado == 1) { lcd.write(byte(3)); lcd.print(" ALERTA!        "); }
  if (estado == 2) { lcd.write(byte(3)); lcd.print(" CRITICO!       "); }

  // Linha 1: temperatura e campo
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.print(":");
  if (tPct < 100) lcd.print(" ");
  if (tPct < 10)  lcd.print(" ");
  lcd.print(tPct);
  lcd.print("%  ");
  lcd.write(byte(1));
  lcd.print(":");
  if (mPct < 100) lcd.print(" ");
  if (mPct < 10)  lcd.print(" ");
  lcd.print(mPct);
  lcd.print("%");

  // DataLogger: grava no Serial a cada 2s com data/hora real
  if (millis() - ultimoLog >= 2000) {
    ultimoLog = millis();
    nRegistro++;

    DateTime now = rtc.now();
    const char* estados[] = {"NORMAL","ALERTA","CRITICO"};

    Serial.print(nRegistro);
    Serial.print(",");
    print2d(now.day());    Serial.print("/");
    print2d(now.month());  Serial.print("/");
    Serial.print(now.year()); Serial.print(" ");
    print2d(now.hour());   Serial.print(":");
    print2d(now.minute()); Serial.print(":");
    print2d(now.second());
    Serial.print(",");
    Serial.print("T\xBA="); Serial.print(tPct); Serial.print("%");
    Serial.print(",");
    Serial.print("M="); Serial.print(mPct); Serial.print("%");
    Serial.print(",");
    Serial.println(estados[estado]);
  }

  delay(400);
}
