#include <LiquidCrystal.h>

const int rs = 12, en = 11,d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*Val Saidas*/      
int vm = 9;
int az = 10;
int vd = 13;
int R1 = 1, R0 = 0;

/*Val Entradas*/
int btm1 = 7;
int btm2 = 8;

/*Val*/
int stateOperation = 0; // ligado ou desligado
int stateRotation = 0; // Horario ou Anti-Horario
int stateButton1;	int stateButton2;

/* toll to right*/  void rollRight()    {for (int positionCounter = 0; positionCounter < 16; positionCounter++) { lcd.scrollDisplayRight(); delay(100);}}
/*Start*/           void start()   		{lcd.begin(16,2);lcd.setCursor(4,0);lcd.print("LERN-DEV");lcd.setCursor(2,1);lcd.print("LuizVinicius"); delay(1000); rollRight(); delay(500);lcd.clear();}
/*Fabrica D'Cores*/ void defineColor  	(int r, int g, int b){digitalWrite(vm, r);digitalWrite(az, g);digitalWrite(vd, b);}
/*Desligado*/       void apagado()    	{defineColor(0,0,0);}
/*Verde*/         	void verde()    	{defineColor(0,0,1);}
/*Vermelho*/      	void vermelho()   	{defineColor(1,0,0);}
/*Amarelo*/       	void amarelo()    	{defineColor(1,0,1);}

// Controle de rele
void motorOf()		{digitalWrite(R1, LOW);  digitalWrite(R0, LOW);}
void horario()		{digitalWrite(R1, HIGH); digitalWrite(R0, LOW);}
void antiHorario()	{digitalWrite(R1, LOW);  digitalWrite(R0, HIGH);}

void ligadoHorario()    	{horario(); 	lcd.setCursor(0,0); lcd.print("Motor LIGADO     "); lcd.setCursor(0,1); lcd.print("Girando Horario "); verde();}
void desligado()      		{motorOf();  	lcd.setCursor(0,0); lcd.print("Motor DESLIGADO  "); lcd.setCursor(0,1); lcd.print("                "); vermelho();}
void ligadoAntihorario()  	{antiHorario(); lcd.setCursor(0,0); lcd.print("Motor LIGADO     "); lcd.setCursor(0,1); lcd.print("Girando AntiHora"); amarelo();}

void setup()
{  
  //Iniciar
  start();
  
  //Entradas
  pinMode(btm1,INPUT);      //  Botao ligar / desliga
  pinMode(btm2,INPUT);      //  Botao Inverter
  
  //Saidas
  pinMode(vm,OUTPUT);       //  LedRGB porta vermelha
  pinMode(az,OUTPUT);       //  LedRGB porta Azul
  pinMode(vd,OUTPUT);       //  LedRGB porta Verde
  pinMode(R1,OUTPUT);    	//  Rele
  pinMode(R0,OUTPUT);    	//  Rele
}

void loop()
{
  // Incrementar estados
  if(digitalRead(btm1) == HIGH && stateButton1 == 0){stateButton1 = 1; stateOperation++;} 
  if(digitalRead(btm1) == LOW) {stateButton1 = 0;}
  
  if(digitalRead(btm2) == HIGH && stateButton2 == 0){stateButton2 = 1; stateRotation++;} 
  if(digitalRead(btm2) == LOW) {stateButton2 = 0;}
  
  // Ciclar estados
  if(stateOperation > 1){stateOperation = 0;}
  if(stateRotation > 1){stateRotation = 0;}
 
  if(stateOperation == 1)
  {
    if(stateRotation == 1){ligadoAntihorario();}
  else {ligadoHorario();}
  } else {desligado();} 
  
}
