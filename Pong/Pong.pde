import processing.serial.*;
import java.util.*;

Puck puck;
Paddle left;
Paddle right;
Serial mySerial;
String currentString = null;
int leftscore = 0;
int rightscore = 0;
int count = 0;

void setup() {
  size(600, 500);
  puck = new Puck();
  left = new Paddle(true);
  right = new Paddle(false);
  mySerial = new Serial(this, "/dev/cu.usbmodem1411", 9600);
}

void draw() {
  background(0);
  get_serial();
  puck.checkPaddleRight(right);
  puck.checkPaddleLeft(left);
  left.show();
  right.show();
  puck.update();
  puck.edges();
  puck.show();
  
  fill(255);
  textSize(32);
  text(leftscore, 32, 40);
  text(rightscore, width-64, 40);
}

void get_serial() {
  if((mySerial.available()>0)) {
    currentString = mySerial.readStringUntil('*');
    if (currentString != null) {
      currentString = currentString.replace("*","");
      String[] s = split(currentString,' ');
      if (s.length > 1){
        if(s[0] != null && !s[0].equals("")) {
          int leftcord = Integer.parseInt(s[0]);
          left.move(leftcord);
        }
        if(s[1] != null && !s[1].equals("")) {
          int rightcord = Integer.parseInt(s[1]);
          right.move(rightcord);
        }
      }
    }
  }
}

void keyReleased() {
  if (keyCode == LEFT){
    leftscore = 0;
    rightscore = 0;
  }
  if (keyCode == RIGHT) {
    if (looping)  noLoop();
    else          loop();
    }
}
