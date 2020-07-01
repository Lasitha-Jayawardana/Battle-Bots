//#include <Servo.h>
//Servo ESC;
int Acc=200;
void setup() {

  Serial.begin(115200);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(5, LOW);
  drive('N');
  //ESC.attach(9);
  //ESC.writeMicroseconds(1000);
}

void loop() {

  int ch1 = pulseIn(A1, HIGH);
  int ch2 = pulseIn(A2, HIGH);
  int ch3 = pulseIn(A3, HIGH);
  int ch4 = pulseIn(A4, HIGH);

  if (ch3 < 1580 && ch3 > 1450) {
    //Serial.println('S');
    drive('N');
  } else if (ch1 > 1600 && ch1 < 1950) {
    //Serial.println('R');
    drive('R');
  } else if (ch1 < 1400 && ch1 > 1080) {
    //Serial.println('L');
    drive('L');

  } else if (ch3 > 1600 && ch3 < 1900) {
    if (ch3 > 1600 && ch4 > 1650) {
      //Serial.println('r');
      drive('r');
    } else if ( (ch3 > 1600 && ch3 < 1900) && (ch4 < 1350 && ch4 > 1100) ) {
      //Serial.println('l');
      drive('l');
    } else {
      //Serial.println('f');
      drive('f');
    }


  } else if (ch3 < 1400 && ch3 > 1100) {
    if ((ch3 < 1400 && ch3 > 1100) && (ch4 > 1100 && ch4 < 1350)) {
      //Serial.println('n');
      drive('n');
    } else if ((ch3 < 1400 && ch3 > 1100) && (ch4 > 1650 && ch4 < 1900)) {
      //Serial.println('g');
      drive('g');
    } else {
      //Serial.println('b');
      drive('b');
    }
  }
  
  if (ch3 < 1580 && ch3 > 1450) {
  if (  ch4 < 2000 && ch4 > 1700 ) {
    drive('R');
    //Brushless(ch3);
    //Serial.println('M');
    //Acc = map(Acc, 100, 240, 1100, 1900);
  }else if (ch4<1350 && ch4 > 1000){
    drive('L');
  }
}

}


void drive(char Dir) {

  switch (Dir) {
    case 'f':
      
      analogWrite(5, Acc); digitalWrite(2, LOW);
      analogWrite(3, Acc); digitalWrite(4, LOW);
      break; // Goes Forward
    case 'b':
      
      analogWrite(2, Acc); digitalWrite(5, LOW);
      digitalWrite(3, LOW); analogWrite(4, Acc);
      break;  //Turns Left
    case 'r':
     
      analogWrite(5, Acc); digitalWrite(2, LOW);
      digitalWrite(3, LOW); digitalWrite(4, LOW);
      break; // Turns right
    case 'l':
      
      digitalWrite(5, LOW); digitalWrite(2, LOW);
      analogWrite(3, Acc); digitalWrite(4, LOW);
      break; // Goes Back
    case 'R':
      
      analogWrite(5, Acc); digitalWrite(2, LOW);
      digitalWrite(3, LOW); analogWrite(4, Acc);
      break;
    case 'L':
      
      digitalWrite(5, LOW); analogWrite(2, Acc);
      analogWrite(3, Acc); digitalWrite(4, LOW);
      break;
    case 'g':
     
      digitalWrite(5, LOW); analogWrite(2, Acc);
      digitalWrite(3, LOW); digitalWrite(4, LOW);
      break;
    case 'n':
      
      digitalWrite(5, LOW); digitalWrite(2, LOW);
      digitalWrite(3, LOW); analogWrite(4, Acc);
      break;
    case 'N':

      digitalWrite(5, LOW); digitalWrite(2, LOW);
      digitalWrite(3, LOW); digitalWrite(4, LOW);
      break;
  }

}



//void Brushless(int Acc) {

  //Acc = map(Acc, 1100, 1900, 1190, 2000);

   //ESC.writeMicroseconds(Acc);

 

//}

