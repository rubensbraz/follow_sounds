int pino_rele = 7;
int pino_som = 2;
int porta_mic_a = A5; // Portas dos dispositivos

boolean rele = HIGH; // Booleano para poder usar a operacao NAO

void setup() {
  pinMode(pino_som, INPUT); // Pino do microfone como entrada
  pinMode(pino_rele, OUTPUT); // Pino do relé como saída
}
 
void loop() {
  int som = digitalRead(pino_som); // Verifica se a saída do microfone está ativa

  if(som){ // Se o som estiver alto
	rele = !rele; //Operacao NAO: Se estiver LOW, passa pra HIGH. Se estiver HIGH passa para LOW
	digitalWrite(pino_rele, rele); // Manda o valor da variável para o rele
	delay(75); // Aguarda 75 milisegundos para não ficar ligando e desligando sem parar
  }
}
