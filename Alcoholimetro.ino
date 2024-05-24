int valor_limite= 550;   // Fija el valor limite en el que se activa la alarma    
float valor_alcohol;    // Fije el valor despues de visualizar el nivel con el Monitor Serial


void setup() {

  pinMode(2, OUTPUT); //Abajo-Izquierda
  pinMode(3, OUTPUT); //Abajo-Abajo
  pinMode(4, OUTPUT); //Abajo-Derecha
  pinMode(5, OUTPUT); //Punto
  pinMode(6, OUTPUT); //Arriba-Derecha
  pinMode(7, OUTPUT); //Arriba-Arriba
  pinMode(8, OUTPUT); //Arriba-Izquierda
  pinMode(9, OUTPUT); //Centro

  Serial.begin(9600);   // Activa el puerto Serial a 9600 Baudios
}

void loop() { 
  valor_alcohol=analogRead(A0);
  delay(5000);
  Serial.println(valor_alcohol);       // Envia al Serial el valor leido del Sensor MQ3 
  float porcentaje=(valor_alcohol/10000);  //calcula el porcentaje
  Serial.println(porcentaje);            // Envia al Serial el porcentaje 
  Serial.println(' ');    
  
  if(valor_alcohol > valor_limite){    // Si la medida de gas metano es mayor de valor limite
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  }
  else{                                // Si es menor del valor limite apaga el display
  digitalWrite(10, HIGH); 
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10,LOW);
  }
  delay (500);                          // Espera 300ms para realizar la proxima medida
}


