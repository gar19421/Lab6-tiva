//************************************************************************** 
// Author: Brandon Garrido 
// Carnet: 19421
// Fecha de creación: 13/09/2021
// Ultima modificación: ...
//**************************************************************************


//declaración de variables iniciales
int start_game = 0;
int start_semaf = 0;

volatile byte state = LOW;

//se definen como constantes las variables asociadas a cada led para los pines
const int LED1_J1 = 3;
const int LED2_J1 = 4;
const int LED3_J1 = 5;
const int LED4_J1 = 6;
const int LED5_J1 = 7;
const int LED6_J1 = 8;
const int LED7_J1 = 9;
const int LED8_J1 = 10;


const int LED1_J2 = 23;
const int LED2_J2 = 24;
const int LED3_J2 = 25;
const int LED4_J2 = 26;
const int LED5_J2 = 27;
const int LED6_J2 = 28;
const int LED7_J2 = 29;
const int LED8_J2 = 11;

//pines de mostrar jugador ganador
const int P1_WINN = 36;
const int P2_WINN = 37;

//push button integrados en la tiva
const int P1 = PB_3;
const int P2 = PE_0;

int contador1 = 0;
int contador2 = 0;

void setup() {
  //se inicializan los pines de los leds integrados y pines de leds externas como salida
  // y los push integrados como entradas en pullup interno
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);

  pinMode(LED1_J1, OUTPUT);
  pinMode(LED2_J1, OUTPUT);
  pinMode(LED3_J1, OUTPUT);
  pinMode(LED4_J1, OUTPUT);
  pinMode(LED5_J1, OUTPUT);
  pinMode(LED6_J1, OUTPUT);
  pinMode(LED7_J1, OUTPUT);
  pinMode(LED8_J1, OUTPUT);

  pinMode(LED1_J2, OUTPUT);
  pinMode(LED2_J2, OUTPUT);
  pinMode(LED3_J2, OUTPUT);
  pinMode(LED4_J2, OUTPUT);
  pinMode(LED5_J2, OUTPUT);
  pinMode(LED6_J2, OUTPUT);
  pinMode(LED7_J2, OUTPUT);
  pinMode(LED8_J2, OUTPUT);

  //pinMode(P1, INPUT);
  //pinMode(P2, INPUT);

  pinMode(P1_WINN, OUTPUT);
  pinMode(P2_WINN, OUTPUT);

//se declaran las interrupciones y asocian los eventos a cada push button
  attachInterrupt(digitalPinToInterrupt(PUSH1), button1, RISING);
  attachInterrupt(digitalPinToInterrupt(PUSH2), button2, RISING);

  //attachInterrupt(digitalPinToInterrupt(P1), inter1, RISING);
  //attachInterrupt(digitalPinToInterrupt(P2), inter2, RISING);
}

void loop() {
  //en cada ciclo se verifica en que estado se encuentra de secuencia de semaforo o jugando
  if (start_semaf == 1){
    start_semaf = 2;
    semaforo();
    }
  if (start_game == 1) {
    player1();
    player2();
    }
}

void button1() {
//evento para aumentar el jugador 1 si el semaforo esta en verde
  if (start_semaf !=2){
  start_semaf = 1;
  }

  if (start_game ==1) {
  contador1++;
  delay(100);
  }
}

void button2() {
  //evento para aumentar el jugador 2 si el semaforo esta en verde
  if (start_semaf !=2){
  start_semaf = 1;
  }

  if (start_game==1){
  contador2++;
  delay(100);
  }  
  
}



void player2(){
  //se fijan las configuraciones de enendido de led, según el valor del contador para player2
      switch (contador2){
        case 1: 
          digitalWrite(LED1_J2, HIGH);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 2: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, HIGH);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 3: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, HIGH);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 4: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, HIGH);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 5: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, HIGH);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 6: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, HIGH);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);
          break;
        case 7: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, HIGH);
          digitalWrite(LED8_J2, LOW);
          break;
        case 8: 
          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, HIGH);

          digitalWrite(P2_WINN, HIGH);
          start_game = 0;
          break;         
      }
}

void player1(){
    //se fijan las configuraciones de enendido de led, según el valor del contador para player1
  switch (contador1){
        case 1: 
          digitalWrite(LED1_J1, HIGH);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 2: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, HIGH);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 3: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, HIGH);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 4: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, HIGH);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 5: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, HIGH);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 6: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, HIGH);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          break;
        case 7: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, HIGH);
          digitalWrite(LED8_J1, LOW);
          break;
        case 8: 
          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, HIGH);

          digitalWrite(P1_WINN, HIGH);
          start_game = 0;
          break;         
      }
}


void resetear(){
  //para inicializar los valores por default al empezar el juego
          contador1 = 0;
          contador2 = 0;

          digitalWrite(LED1_J1, LOW);
          digitalWrite(LED2_J1, LOW);
          digitalWrite(LED3_J1, LOW);
          digitalWrite(LED4_J1, LOW);
          digitalWrite(LED5_J1, LOW);
          digitalWrite(LED6_J1, LOW);
          digitalWrite(LED7_J1, LOW);
          digitalWrite(LED8_J1, LOW);
          digitalWrite(P1_WINN, LOW);

          digitalWrite(LED1_J2, LOW);
          digitalWrite(LED2_J2, LOW);
          digitalWrite(LED3_J2, LOW);
          digitalWrite(LED4_J2, LOW);
          digitalWrite(LED5_J2, LOW);
          digitalWrite(LED6_J2, LOW);
          digitalWrite(LED7_J2, LOW);
          digitalWrite(LED8_J2, LOW);

          digitalWrite(P2_WINN, LOW);

}

void semaforo() {
  //secuencia del semáforo con los leds rgb internos del tiva
  resetear();
  digitalWrite (RED_LED, HIGH);
  digitalWrite (GREEN_LED, LOW);
  delay(1000);
  digitalWrite (RED_LED, HIGH);  // El RGB para amarillo es 0% azul, 100% rojo y 100% verde
  digitalWrite (GREEN_LED, HIGH);
  delay(1000);
  digitalWrite (RED_LED, LOW);
  digitalWrite (GREEN_LED, HIGH);
  start_game = 1;
}
