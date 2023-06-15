typedef enum{
  BUTTON_P,
  BUTTON_FALLING,
  BUTTON_UNP,
  BUTTON_RAISING,
} debounceState_t;
#define TEMPO 40
unsigned long Tiempo_Ahora = 0;
#define In 7
debounceState_t Actual_State;

void debounceFSM_init();

void debounceFSM_update();

void button_P();

void button_UNP();

void setup(){
  pinMode(7, INPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  Tiempo_Ahora = millis();
  debounceFSM_init();
}

void loop(){
  
  debounceFSM_update();
}

void debounceFSM_init(){
  if(digitalRead(In)){
    Actual_State = BUTTON_P;
  }else{
    Actual_State = BUTTON_UNP;
  }
}

void button_P(){
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
}

void button_UNP(){
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
}

void debounceFSM_update(){
  switch(Actual_State){
    case BUTTON_P:
      if(digitalRead(In)==LOW){
        Actual_State = BUTTON_FALLING;
      }
      break;
    case BUTTON_FALLING:
      if(millis()-Tiempo_Ahora>TEMPO){
        if(digitalRead(In)==LOW){
          Actual_State = BUTTON_P;
          button_P();
        }else{
          Actual_State = BUTTON_UNP;
          button_UNP();
        }
      }
      break;
    case BUTTON_UNP:
        if(digitalRead(In)){
          Actual_State = BUTTON_RAISING;
        }
      break;
    case BUTTON_RAISING:
     if(millis()-Tiempo_Ahora>TEMPO){
       if(digitalRead(In)){
         Actual_State = BUTTON_UNP;
         button_UNP();
       }else{
         Actual_State = BUTTON_P;
         button_P();
       }
     }
     break;
  }
}