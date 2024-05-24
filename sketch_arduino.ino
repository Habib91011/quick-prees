
#define NUMBER_OF_LEDS 2

#define BTN_pin 2
#define LedR 4
#define LedG 5

int  LedsPin[NUMBER_OF_LEDS]={LedR,LedG};
bool LedIsOn[NUMBER_OF_LEDS];
void setup() {
  Serial.begin(9600);
  pinMode(BTN_pin,INPUT_PULLUP);
  for(int k = 0; k<NUMBER_OF_LEDS; k++){
    pinMode(LedsPin[k],OUTPUT);
    TurnLedOFF(k);
  }
}

void loop() {
  if(digitalRead(BTN_pin) == LOW){
    ToggleLed(0);
    ToggleLed(1);
    while(digitalRead(BTN_pin) == LOW){delay(50);}
 }

}
void ToggleLed(int chnl){
  if(LedIsOn[chnl]){
    TurnLedOFF(chnl);
  } else {
    TurnLedOn(chnl);
  }
}
void TurnLedOn(int chnl){
  LedIsOn[chnl] = true;
  digitalWrite(LedsPin[chnl],HIGH);
}
void TurnLedOFF(int chnl){
  LedIsOn[chnl]=false;
  digitalWrite(LedsPin[chnl],LOW);
}

