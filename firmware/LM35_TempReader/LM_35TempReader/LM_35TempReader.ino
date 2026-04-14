/*
 * Du an: Doc nhiet do LM35 va gui qua Serial
 * Mon: Mang Cam Bien - Tuan 03
 */

int adcValues[3];  // Dùng 3 để chứa A0, A1, A2
float nhietDo[3];
char chuoi[100];   

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  //SV A
  // Đọc kênh A0
  adcValues[0] = analogRead(A0);
  nhietDo[0] = (adcValues[0] * 500.0) / 1023.0;

  // Đọc kênh A1
  adcValues[1] = analogRead(A1);
  nhietDo[1] = (adcValues[1] * 500.0) / 1023.0;

  // THÊM MỚI: Đọc kênh A2
  adcValues[2] = analogRead(A2);
  nhietDo[2] = (adcValues[2] * 500.0) / 1023.0;

  //SV B
  // Xuat dinh dang JSON cho ca 3 kenh
  sprintf(chuoi, "{\"T1\":%d, \"T2\":%d, \"T3\":%d}\n", (int)nhietDo[0], (int)nhietDo[1], (int)nhietDo[2])
  

  Serial.print(chuoi);
  delay(100);
}
