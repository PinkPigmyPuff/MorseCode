// what we are converting to Morse Code
String morseCode = "Hello, world! I'm a Morse Code Machine.";
// which LED we are using
int LED = 12;
int piezo = 11;
int freq = 200;

// basic unit of time in milliseconds
int unit = 50;
// time quantities for morse code
int dot = unit;
int dash = 3 * unit;
int space = 7 * unit;
int reset = 15 * unit;


//For letters
char* letters[] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};

//For Numbers
char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-", ".....",
"-....", "--...", "---..", "----."
};

void setup() {
  // make our string lower case (Morse code isn't case-sensitive)
  morseCode.toLowerCase();
  // initialize our LED
  pinMode(LED, OUTPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
  Serial.println("\n" + morseCode);
}

void loop() {
  // convert every letter to morse code, individually+
  for (int i = 0; i < morseCode.length(); i++)
  {
    //Serial.print("Length: ");
    //Serial.println(morseCode.length());
    //Serial.print("i: ");
    //Serial.println(i);
    //Serial.println(morseCode[i]);
    morseConverter(morseCode[i]);
  }
  delay(reset);
  Serial.println("\nreseting");
  Serial.println("\n\n");
}

void morseConverter(char c) 
{
  if (c >= 'a' && c <= 'z')
  {
    morseToLight(letters[c - 'a']);
  }
  else if (c >= 'A' && c <= 'Z')
  {
    morseToLight(letters[c - 'A']);
  }
  else if (c >= '0' && c <= '9')
  {
    morseToLight(numbers[c - '0']);
  }
  else if (c == ' ')
  {
    delay(space);
    Serial.print(" / ");
  }
}


void morseToLight(char* sequence)
{
  int i = 0;
  while (sequence[i] != NULL) 
  {
    if (sequence[i] == '-')
    {
      illuminate(dash);
      Serial.print("-");
    }
    else if(sequence[i] == '.')
    {
      illuminate(dot);
      Serial.print(".");
    }
    i++; 
  }
Serial.print(" ");
delay(dash);
}

void illuminate(int time)
{
  //tone(piezo, freq);
  digitalWrite(LED, HIGH);
  delay(time);
  digitalWrite(LED, LOW);
  noTone(piezo); 
}
