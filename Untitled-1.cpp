int ledVermelho = 10;   // Estou criando uma variável chamada 'ledVermelho' e colocando o número do pino 10 nela
int ledAmarelo = 9;    // Mesma coisa para o LED amarelo, que está no pino 9
int ledVerde = 8;     // E aqui eu faço isso para o LED verde, que está no pino 8
int sensorPIR = 7;     // O sensor de movimento (PIR) está conectado no pino 7

int tempoVerde = 9;    // Aqui eu coloco o tempo que o LED verde vai ficar aceso, que é controlado pelo sensor  PIR

void setup() {
  pinMode(ledVermelho, OUTPUT);  // Configuro o pino do LED vermelho, amarelo e verde  como saída
  pinMode(ledAmarelo, OUTPUT);   
  pinMode(ledVerde, OUTPUT);  
  pinMode(sensorPIR, INPUT);     // Configuro o pino do sensor PIR como entrada, para que eu possa ler o que ele detecta
}

void loop() {
  int presenca = digitalRead(sensorPIR); // leio o valor do sensor PIR e vejo se ele detecta um objeto( veículo) ou não

  if (presenca == HIGH) {                 // Se o sensor detectar um carro (HIGH)
    digitalWrite(ledVerde, HIGH);         // Eu ligo o LED verde
    delay(tempoVerde * 1000);             // Mantenho o LED verde aceso por 'tempoVerde' segundos
  } else {                                // Se o sensor não detectar nada (LOW)
    digitalWrite(ledVerde, HIGH);         // Ainda ligo o LED verde
    delay(tempoVerde * 500);              // Mas desta vez, o tempo é menor (metade do tempo base)
  }

  digitalWrite(ledVerde, LOW);            // Agora, desligo o LED verde
  digitalWrite(ledAmarelo, HIGH);         // Ligo o LED amarelo
  delay(2000);                            // Deixo o LED amarelo aceso por 2 segundos

  digitalWrite(ledAmarelo, LOW);          // Desligo o LED amarelo
  digitalWrite(ledVermelho, HIGH);        // Ligo o LED vermelho
  delay(5000);                            // Deixo o LED vermelho aceso por 5 segundos

  digitalWrite(ledVermelho, LOW);         // Desligo o LED vermelho e começo tudo de novo
}