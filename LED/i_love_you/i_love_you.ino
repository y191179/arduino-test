void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void on() {
  digitalWrite(LED_BUILTIN, HIGH);
}

void off() {
  digitalWrite(LED_BUILTIN, LOW);
}

void dot() {

}

void line() {

}

void long_pause() {

}

void loop() {
  on();
  delay(500);
  off();
  delay(500);
}
