
// int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 3                    // outside leads to ground and +5V

int playerOne = 0;  // variable to store the value read
int playerTwo = 0;

void bubbleSort(int a[], int );
int findTheMedian();


void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {

  playerOne = findTheMedian(A0);
  playerTwo = findTheMedian(A2);

  
//  val = map(val, 350, 500, 0, 400);
//  Serial.println(val);          // debug value
  
  //Serial.print("%d %d", val, val);
  playerOne = map(playerOne, 300, 700, 0, 400);

  playerTwo = map(playerTwo, 400, 800, 0, 400);
  
  Serial.print(playerOne);
  Serial.print(" ");
  Serial.print(playerTwo);
  Serial.print("*");
  delay(100);
  }


int findTheMedian(int pin){
    int arrayOfValues[5];
    int sortedArray[5];
  
    for (int i=0;i<5;i++){
      arrayOfValues[i] = analogRead(pin);        
    }

    // sortedArray[0] = arrayOfValues[i];
    for (int i=0;i<5;i++){
      sortedArray[0] = min(arrayOfValues[i],sortedArray[0]);
      sortedArray[4] = max(arrayOfValues[i],sortedArray[0]);
    }
  bubbleSort(arrayOfValues,5);
  return arrayOfValues[3];   
}

void bubbleSort(int a[], int size) {
    for(int i=0; i<(size-1); i++) {
        for(int o=0; o<(size-(i+1)); o++) {
                if(a[o] > a[o+1]) {
                    int t = a[o];
                    a[o] = a[o+1];
                    a[o+1] = t;
                }
        }
    }
}
