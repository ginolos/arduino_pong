class Paddle {
  float x;
  float y = height/2;
  float w = 20;
  float h = 100;

  float ychange = 0;

  Paddle(boolean left) {
    if (left) {
      x = w;
    } else {
      x = width - w;
    }
  }

  void move(float position) {
    y = position;
    y = constrain(y, h/2, height-h/2);
  }

  void show() {
    fill(255);
    rectMode(CENTER);
    rect(x, y, w, h);
  }
}
