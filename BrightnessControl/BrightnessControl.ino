int lightPin = 0;  //define a pin for Photo resistor
//Resistor values
  //0 - 690 -- Day light
  // Upper -- Night
int upBlind = 11;
int downBlind = 12;
int stopBlind = 4;
int lightThreshold = 250; // Límite

boolean isDebuggerOn=true;



void setup(){
  
    //if(isDebuggerOn){
      Serial.begin(9600);  //Begin serial communcation
    //}
    pinMode(upBlind, OUTPUT);
    pinMode(stopBlind, OUTPUT);
    pinMode(downBlind, OUTPUT);

    digitalWrite(upBlind, LOW);
    digitalWrite(stopBlind, LOW);
    digitalWrite(downBlind, LOW);
}

void loop(){
    readBrightness();
}

void readBrightness(){
  
    //if(isDebuggerOn){
      Serial.println(analogRead(lightPin)); 
    //}
    if(analogRead(lightPin) >= lightThreshold ){
        digitalWrite(stopBlind, LOW);
        delay(1000);
        digitalWrite(upBlind, HIGH);
        //Serial.println("high"); 
    }else{
        digitalWrite(upBlind, LOW);
        delay(1000);
        digitalWrite(stopBlind, HIGH);
        //Serial.println("low"); 
    }

    delay(100);
}

