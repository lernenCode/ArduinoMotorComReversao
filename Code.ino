// AUTOR: LUIZ VINICIUS
// DESCRIÇÃO: MOTOR 127V COM REVERSAO ARDUINO
// DATA: 25/08/2022

//Entradas
int bt1 = 9, bt2 = 5, bt3 = 11; // botoes
// Saidas
int vm = 4;             //  LedRGB porta vermelha
int az = 3;             //  LedRGB porta Azul
int vd = 2;             //  LedRGB porta Verde

int motor = 13;         // motor
int inverter1 = 6;      // Fase + motor invertido
int inverter2 = 7;      // Fase - motor invertido

// Variaveis
int estado = 1;         // Estado de giro 1 = horario || 2 = anti horario

bool ligado, desligado;	// Estado Ligado || Desligado

/*LIGAR MOTOR*/   	void ligar()    {digitalWrite(motor, HIGH);}
/*DESLIGAR MOTOR*/  void desligar()   {digitalWrite(motor, LOW);}
/*INVERTER MOTOR*/  void antiHorario()  {digitalWrite(inverter1, HIGH); digitalWrite(inverter2, HIGH);}
/*INVERTER MOTOR*/  void horario()    {digitalWrite(inverter1, LOW); digitalWrite(inverter2, LOW);}
/*Fabrica D'Cores*/ void defineColor  (int r, int g, int b){digitalWrite(vm, r);digitalWrite(az, g);digitalWrite(vd, b);}
/*Desligado*/     	void apagado()    {defineColor(0,0,0);}
/*Verde*/       	void verde()    {defineColor(0,0,1);}
/*Azul*/      		void azul()     {defineColor(0,1,0);}
/*Ciano*/      		void ciano()    {defineColor(0,1,1);}
/*Vermelho*/    	void vermelho()   {defineColor(1,0,0);}
/*Amarelo*/     	void amarelo()    {defineColor(1,0,1);}
/*Magenta*/     	void magenta()    {defineColor(1,1,0);}
/*Branco*/      	void branco()   {defineColor(1,1,1);}
/*Sinalizar ligado*/void piscar()   {if(estado == 2){azul(); delay(500); magenta(); delay(500);}else{amarelo(); delay(500); vermelho(); delay(500);}}

void setup()
{
  //Entradas
  pinMode(bt1,INPUT);     	//  Botao ligar
  pinMode(bt2,INPUT);     	//  Botao desligar
  pinMode(bt3,INPUT);     	//  Botao Inverter
  
  //Saidas
  pinMode(vm,OUTPUT);     	//  LedRGB porta vermelha
  pinMode(az,OUTPUT);     	//  LedRGB porta Azul
  pinMode(vd,OUTPUT);     	//  LedRGB porta Verde
  pinMode(motor,OUTPUT);    //  Motor
  pinMode(inverter1,OUTPUT);//  Motor fase + Ivertido
  pinMode(inverter2,OUTPUT);//  Motor fase - Ivertido
  
}

void loop()
{
  // Verificar entradas
  if(digitalRead(bt1) == HIGH){ligado = true;    desligado = false;}
  if(digitalRead(bt2) == HIGH){desligado = true; ligado = false;}
  if(digitalRead(bt3) == HIGH){estado = estado +1; if(estado > 2){estado = 1;} delay(300);}
  
  // Girar horario
  if(estado == 1)
  {
    if(ligado == true)
    {ligar(); piscar(); horario();} else {desligar(); apagado();}
  }
  
  // Girar anti-horario
  if(estado == 2)
  {
    if(ligado == true)
    {ligar(); piscar(); antiHorario();} else {desligar(); apagado();}
  }
}

