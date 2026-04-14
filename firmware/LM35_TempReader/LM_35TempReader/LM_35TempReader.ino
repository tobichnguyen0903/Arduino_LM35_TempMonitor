/*
 * Du an: Doc nhiet do LM35 va gui qua Serial
 * Mon: Mang Cam Bien - Tuan 03
 */

// SỬA: Tăng kích thước mảng lên 3 và đổi tên thành adcValues cho khớp với loop
int adcValues[3];  
float nhietDo[3];
char chuoi[40]; // SỬA: Tăng kích thước chuỗi lên 40 để chứa thêm dữ liệu

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  // Đọc kênh A0
  adcValues[0] = analogRead(A0);
  nhietDo[0] = (adcValues[0] * 500.0) / 1023.0;

  // Đọc kênh A1
  adcValues[1] = analogRead(A1);
  nhietDo[1] = (adcValues[1] * 500.0) / 1023.0;

  // THÊM MỚI: Đọc kênh A2
  adcValues[2] = analogRead(A2);
  nhietDo[2] = (adcValues[2] * 500.0) / 1023.0;

  // SỬA: Thêm %d thứ 3 và đưa nhietDo[2] vào để in ra
  sprintf(chuoi, "%d,%d,%d\n", (int)nhietDo[0], (int)nhietDo[1], (int)nhietDo[2]);
  
  Serial.print(chuoi);
  delay(100);
}
