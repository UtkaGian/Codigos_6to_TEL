typedef enum{ 
  BUTTON_P,
  BUTTON_FALLING,
  BUTTON_UNP,
  BUTTON_RAISING,
} debounceState_t;

const byte Ds [16]{
  B10000000,  //0
  B11110010,  //1
  B01001000,  //2
  B01100000,  //3
  B00110010,  //4
  B00100100,  //5
  B00000100,  //6
  B11110000,  //7
  B00000000,  //8
  B00100000,  //9
  B00010000,  //A
  B00000110,  //b
  B10001100,  //C
  B01000010,  //d
  B00001100,  //E
  B00011100};  //F

static int Counter=0;

#define TEMPO 40
#define In 10
unsigned long Tiempo_Ahora = 0;
debounceState_t Actual_State;

void debounceFSM_init();

void debounceFSM_update(); 

void button_P();

void button_UNP();
 

void setup(){
  DDRD=B11111111;
  pinMode(10, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Tiempo_Ahora = millis();
  debounceFSM_init();
}

void loop(){
  debounceFSM_update();
}

void debounceFSM_init(){
    Actual_State = BUTTON_UNP;
}

 

void button_P(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  PORTD=Ds[Counter];
  Counter++;
  if(Counter==16){
    Counter=0;
  }
}

void button_UNP(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

 

void debounceFSM_update(){
  
  switch(Actual_State){

    case BUTTON_P:
      if(digitalRead(In)==HIGH){
        Actual_State = BUTTON_RAISING;
      }
      break;

    case BUTTON_FALLING:
      if(millis()-Tiempo_Ahora>=TEMPO){
        Tiempo_Ahora = millis();
        if(digitalRead(In)==LOW){
          Actual_State = BUTTON_P;
          button_P();
        }else{
          Actual_State = BUTTON_UNP;
        }
      }
      break;

    case BUTTON_UNP:
        if(digitalRead(In)){
          Actual_State = BUTTON_FALLING;
        }
      break;

    case BUTTON_RAISING:
     if(millis()-Tiempo_Ahora>=TEMPO){
       Tiempo_Ahora = millis();
       if(digitalRead(In)){
         Actual_State = BUTTON_UNP;
         button_UNP();
       }else{
         Actual_State = BUTTON_P;
       }
     }
     break;
  }
}
