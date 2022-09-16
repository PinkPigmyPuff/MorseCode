// what we are converting to Morse Code
String morseCode = "Hello, World";
// which LED we are using
int LED = 12;
// basic unit of time in milliseconds
int unit = 15;
// time quantities for morse code
int dot = unit;
int dash = 3 * unit;
int space = 7 * unit;
int reset = 15 * unit;
// conversion array for characters -> morse
String Morse[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",  //a through i
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // j through r
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."  // s through z
  ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"  // 1 through 0
};

void setup() {
  // make our string lower case (Morse code isn't case-sensitive)
  morseCode.toLowerCase();
  // initialize our LED
  pinMode(LED, OUTPUT);
  Serial.print("Hi");
}

void loop() {
  // convert every letter to morse code, individually
  for (int i = 0; i < morseCode.length(); i++)
  {
    morseConverter(morseCode[i]);
  }
  delay(reset);
}

void morseConverter(char c) 
{
  char index = c;
  if (isDigit(c))
  {
    index -= '0' + 24;
  }
  else if (isAlpha(c))
  {
    index -= 'a';
  }
  else if (c == 32)
  {
    illuminate(space);
  }
  Serial.println("index: " + index);
  
  for (int i = 0; i < Morse[index].length(); i++)
  {
    if (Morse[index][i] == '-') 
    {
      illuminate(dash);
    }
    else if (Morse[index][i] == '.') 
    {
      illuminate(dot);
    }
    // break between parts of the same letter
    illuminate(dash);
  }
}

void illuminate(int time)
{
  digitalWrite(LED, HIGH);
  delay(time);
  digitalWrite(LED, LOW); 
}
