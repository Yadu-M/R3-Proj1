//Input Pins
int in1 = 2;
int in2 = 4;
int in3 = 7;
int in4 = 8;
int potentio = A5;

//Output Pins
int out1 = 3;
int out2 = 5;
int out3 = 9;
int out4 = 10;


void setup()
{
  //Declaring Input pins
  pinMode(in1, INPUT_PULLUP); 
  pinMode(in2, INPUT_PULLUP); 
  pinMode(in3, INPUT_PULLUP); 
  pinMode(in4, INPUT_PULLUP); 
  pinMode(potentio, INPUT_PULLUP);
  
  //Declaring Output pins
  pinMode(out1, OUTPUT); //Forward Pin for Motor 1
  pinMode(out2, OUTPUT); //Backward Pin for Motor 1
  pinMode(out3, OUTPUT); //Backward Pin for Motor 2
  pinMode(out4, OUTPUT); //Forward Pin for Motor 2
  
  Serial.begin(9600);
  
}

void loop()
{  
  int switch1 = digitalRead(in1); //Reading button State
  int switch2 = digitalRead(in2);
  int switch3 = digitalRead(in3);
  int switch4 = digitalRead(in4);  
  
  int speed = map(analogRead(potentio), 0, 1023, 0, 255);  
  Serial.println(speed);
  
  while (multipleSwitchOn() == true){ //Function checks if multiple buttons are on
  	digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);
    int speed = map(analogRead(potentio), 0, 1023, 0, 255);
  }
  
    
  if(switch1 == HIGH){ //Motors go forward
    digitalWrite(out1, speed);
    digitalWrite(out4, speed);
        delay(25);

   
  }
  else if(switch1 == LOW){
    digitalWrite(out1, LOW);
    digitalWrite(out4, LOW);
	delay(25);

  }
  
  if(switch2 == HIGH) { //Motors go backwards
   digitalWrite(out2, speed);
   digitalWrite(out3, speed);
	delay(25);

  }
  else if(switch2 == LOW) {
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
	delay(25);

  }
  
  if(switch3 == HIGH){ //Motors move left
    digitalWrite(out2, speed);
    digitalWrite(out4, speed); 
	delay(25);

  }
  
  
  if(switch4 == HIGH){ //Motors move right
   	digitalWrite(out1, speed);
    digitalWrite(out3, speed);
	delay(25);

  }
  delay(100);
 	
}

bool multipleSwitchOn(){
  int switchPins[] = {2,4,7,8}; //declaring pins in an array
  int onSwitches = 0;
  int pinCount = 4;
  
  for (int i = 0; i < pinCount; i++){ //for loop to check if buttons are on
    if (digitalRead(switchPins[i]) == HIGH){
   		onSwitches += 1; //if buttons are on, adds 1.
    }    
	
  }
  
  if(onSwitches >= 2){
  	return true; 
  }
  onSwitches = 0;
  return false;
  
  
  
}
