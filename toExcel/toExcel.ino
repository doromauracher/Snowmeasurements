int rowCount = 500;
int rowNumber = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (rowNumber < rowCount) {
    Serial.print(++rowNumber);
    Serial.print('\t');
    if (rowNumber % 2 == 0) {
      Serial.print("even\t");
    } else {
      Serial.print("odd\t");
    }
    Serial.println(random(16000), HEX);
  }
}
