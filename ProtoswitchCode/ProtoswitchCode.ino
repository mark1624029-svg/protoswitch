int ledpins[] = {D4, D5, D6};
int buttonpins[] = {D0, D1, D2};

int currentled = 0;
int level =1;
int speed = 600;

void setup() {
for (int i = 0; i< 3 ; i++) {
  pinMode(buttonpins[i], INPUT_PULLUP);
}
for (int i = 0; i < 3; i++) {
  pinMode(ledpins[i], OUTPUT);
}


randomSeed(analogRead(A0));

}

void loop() {
currentled = random(0, 3);

digitalWrite(ledpins[currentled], HIGH);
delay (speed);
digitalWrite (ledpins[currentled], LOW);

int pressed = waitForButton();

if (pressed == currentled) {
  level++;
  speed = max(150, speed - 40 );
  delay(300);
}else {
  gameOver();
}
}


int waitForButton() {
  while(true) {
    for (int i= 0; i < 3 ; i ++ ) {
      if (digitalRead(buttonpins[i]) == LOW ) {
        delay (180);
        return i;
      }
    }
  }
}
void gameOver() {
  for (int i =0; i<5; i ++){
    for (int j = 0; j < 3; j++) digitalWrite(ledpins[j], HIGH);
    delay(200);
    for (int j=0; j<3; j++) digitalWrite(ledpins[j], LOW);
    delay(200);
  }

level =1;
speed = 600;
delay(500);
}
