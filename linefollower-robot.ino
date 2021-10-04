int IN_1 = 3;
int IN_2 = 5;
int  IN_3 = 6;
int IN_4 = 9;
int led=13;
//sensor kiri
int l1=A1; 
int l2=A3; 
//sensor kanan
int r2=A2; 
int r1=A4; 
int val;


void setup(){
  //pinMode (led, OUTPUT);
  Serial.begin(9600);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop(){
 int sl1=analogRead(l1);
int sl2=analogRead(l2);
int sr1=analogRead(r1);
int sr2=analogRead(r2);

Serial.print("Sensor1= "); Serial.print(sl1);
Serial.print("\n");
Serial.print("Sensor1= "); Serial.print(sl2);
Serial.print("\n");
Serial.print("Sensor1= "); Serial.print(sr1);
Serial.print("\n");
Serial.print("Sensor1= "); Serial.print(sr2);
Serial.print("\n");  
  //int val;
  if (Serial.available()){
  delay(100);

  while (Serial.available() > 0) {
      val=Serial.read();
      if(val == '0') { 
         analogWrite(IN_1, 0);  //kanan
         analogWrite(IN_2, 255);
         analogWrite(IN_3, 0);  //kiri
         analogWrite(IN_4, 255);
       
      }
      else if (val == '1') { 
        analogWrite(IN_1, 255);  //kanan
        analogWrite(IN_2, 0);
        analogWrite(IN_3, 255);  //kiri
        analogWrite(IN_4, 0);
       
      }
      else if (val == '2') { 
        analogWrite(IN_1, 0);  //kanan
        analogWrite(IN_2, 0);
        analogWrite(IN_3, 255);  //kiri
        analogWrite(IN_4, 0);
        
      }
      else if (val == '3') { 
        analogWrite(IN_1, 255);  //kanan
        analogWrite(IN_2, 0);
        analogWrite(IN_3, 0);  //kiri
        analogWrite(IN_4, 0);
       
      }

      else if (val == '4') { 
  
      digitalWrite(led, HIGH);
    }
    else if (val == '5') { 
  
      digitalWrite(led, LOW);
    }
  }
  
}

}

