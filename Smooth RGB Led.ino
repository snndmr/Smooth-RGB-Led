const int pinR = 9;
const int pinG = 10;
const int pinB = 11;

void setup() {
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
    smoothTransition(random(0, 256), random(0, 256), random(0, 256));
}

void smoothTransition(int red, int green, int blue) {
  const int MIN = min(red, min(green, blue));
  const int MAX = max(red, max(green, blue));

  float stepSizeR = (float)red / MIN;
  float stepSizeG = (float)green / MIN;
  float stepSizeB = (float)blue / MIN;

  for (float r = 0, g = 0, b = 0;
       r <= stepSizeR * MIN || g <= stepSizeG * MIN || b <= stepSizeB * MIN;
       r += stepSizeR, g += stepSizeG, b += stepSizeB) {
    setColor(r, g, b);
    delay(1024.0 / MIN);
  }

  for (float r = red, g = green, b = blue; r > 0 || g > 0 || b > 0;
       r -= stepSizeR, g -= stepSizeG, b -= stepSizeB) {
    setColor(r, g, b);
    delay(1024 .0 / MIN);
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(pinR, red);
  analogWrite(pinG, green);
  analogWrite(pinB, blue);
}
