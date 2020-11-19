void settup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void on() {
  digitalWrite(LED_BUILTIN, HIGH);
}

void off() {
  digitalWrite(LED_BUILTIN, LOW);
}

void dott() {

}

void line() {

}

void long_pause() {

}

#define SIZE 26
const int ledPin=8;
const int speakerPin=12;
const int dotButton=2;
const int dashButton=7;

//Array of Morse code from A to Z
String letters [SIZE]={
  
// A to I
//".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
// J to R 
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
// S to Z
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
};

const int led = 13;
const int buz = 8;
String code = "";
int len = 0;
char ch;
char new_char;
int unit_delay = 250;
void dot()

{
Serial.print(".");
digitalWrite(led, HIGH);
digitalWrite(buz, HIGH);
delay(unit_delay);
digitalWrite(led, LOW);
digitalWrite(buz, LOW);
delay(unit_delay);
}
void dash()
{
Serial.print("-");
digitalWrite(led, HIGH);
digitalWrite(buz, HIGH);
delay(unit_delay * 3);
digitalWrite(led, LOW);
digitalWrite(buz, LOW);
delay(unit_delay);
}

void I()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}

void L()
{
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
}

void O()
{
dash();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}

void V()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
}

void E()
{
dot();
delay(unit_delay);
}

void Y()
{
dash();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
dash();
delay(unit_delay);
}

void U()
{
dot();
delay(unit_delay);
dot();
delay(unit_delay);
dash();
delay(unit_delay);
}

void morse()
{
if (ch == 'E' || ch == 'e')
{
E();
Serial.print(" ");
}
else if (ch == 'I' || ch == 'i')
{
I();
Serial.print(" ");
}
else if (ch == 'L' || ch == 'l')
{
L();
Serial.print(" ");
}
else if (ch == 'O' || ch == 'o')
{
O();
Serial.print(" ");
}
else if (ch == 'U' || ch == 'u')
{
U();
Serial.print(" ");
}
else if (ch == 'V' || ch == 'v')
{
V();
Serial.print(" ");
}
else if (ch == 'Y' || ch == 'y')
{
Y();
Serial.print(" ");
}
else if(ch == ' ')
{
delay(unit_delay*7);
Serial.print("/ ");
}
else
Serial.println("Unknown symbol!");
}

void String2Morse()
{
len = code.length();
for (int i = 0; i < len; i++)
{
ch = code.charAt(i);
morse();
}
}

void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(buz, OUTPUT);
Serial.println("I love you");
}
void loop() {
while (Serial.available())
{
code = Serial.readString();
Serial.print(code);
Serial.print(" = ");
String2Morse();
Serial.println("");
}
delay(1000);
}
