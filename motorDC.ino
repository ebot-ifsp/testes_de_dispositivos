//Definicoes pinos Arduino ligados a entrada da Ponte H
//motor Esquerda

int IN1 = 2;
int IN2 = 3;

//motor Direita
int IN3 = 7;
int IN4 = 8;

//PWM
#define pwmAPin 4//Pino D9 saída PWM do motor Esquerdo
#define pwmBPin 9//Pino D10 saída PWM do motor Direito

// lendo sensor linha
#define sensorB A2 //EM QUAL PINO SENSOR ESTÁ DIREITA
#define sensorA A3 //EM QUAL PINO SENSOR ESTÁ ESQUERDA

int valorSensorB = 0; //PEGAR OS VALORES DO SENSOR
int valorSensorA = 0; //PEGAR OS VALORES DO SENSOR
int valorcorte = 700;
int valorpwmA = 130;
int valorpwmB = 70;
int desligado = 0;
boolean verifica =true;
char leitura;

void setup() {
  //Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  //PWM
  pinMode(pwmAPin, OUTPUT); // sets the pin as output
  pinMode(pwmBPin, OUTPUT); // sets the pin as output

  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);

  //Sentido Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  //Sentido Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  Serial.begin(9600); //inicia a porta serial
  
     analogWrite(pwmAPin, valorpwmA); 
     analogWrite(pwmBPin, valorpwmB);   

  
}

void loop()
{
leitura = Serial.read();

if (leitura == 'q'){
  valorpwmA = valorpwmA + 5;
  valorpwmB = valorpwmB + 5;

  analogWrite(pwmAPin, valorpwmA); 
  analogWrite(pwmBPin, valorpwmB);   
}
if (leitura == 'a'){
  valorpwmA = valorpwmA - 5;
  valorpwmB = valorpwmB - 5;

  analogWrite(pwmAPin, valorpwmA); 
  analogWrite(pwmBPin, valorpwmB);   
}

if (leitura == 'w'){
  //Para frente
  //Sentido Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //Sentido Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
if (leitura == 's'){
  //Para trás
  //Sentido Motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Sentido Motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  }
if (leitura == 'f'){
  //freio
  //Sentido Motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  //Sentido Motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
if (leitura == 'r'){
  //ponto morto
  //Sentido Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  //Sentido Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

if (leitura == 'e'){
  //vira esquerda
  //Sentido Motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Sentido Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  }
if (leitura == 'd'){
  //vira direita
  //Sentido Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //Sentido Motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  }

  
 /*
  valorSensorA = analogRead(sensorA);
  valorSensorB = analogRead(sensorB);

  Serial.println(valorSensorA);
  Serial.println(valorSensorB);

  if (valorSensorA > valorcorte && valorSensorB > valorcorte)
  {
     analogWrite(pwmAPin, valorpwmA); 
     analogWrite(pwmBPin, valorpwmB);      
  }
  else if ( valorSensorA > valorcorte && valorSensorB <= valorcorte)
  {
     analogWrite(pwmAPin, valorpwmA); 
     analogWrite(pwmBPin, desligado); 
  }
  else if ( valorSensorA <= valorcorte && valorSensorB > valorcorte)
  {
     analogWrite(pwmAPin, desligado); 
     analogWrite(pwmBPin, valorpwmB); 
  }
  else
  {
     analogWrite(pwmAPin, desligado); 
     analogWrite(pwmBPin, desligado); 
  }
  */
  
}
