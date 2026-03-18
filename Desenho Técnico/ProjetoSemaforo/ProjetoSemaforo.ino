int verde = 10;
int amarelo = 11;
int vermelho = 12;
int botao = 7;
int vermelho_pedestre = 3;
int verde_pedestre = 2;
int est = 1;
byte estado_botao = 0;
byte estado_anterior = 0;
byte latencia = 0;
byte estado_latencia = 0;
unsigned long tempo_anterior = 0;
unsigned long tempo_atual = 0;

void setup() {
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(verde_pedestre, OUTPUT);
  pinMode(vermelho_pedestre, OUTPUT);
  pinMode(botao, INPUT);
  tempo_anterior = millis();

  digitalWrite(verde, HIGH);
  digitalWrite(vermelho_pedestre, HIGH);
}

void loop() {
  estado_botao = digitalRead(botao);

  if (estado_botao == HIGH) {
    estado_anterior = estado_botao;
  }

  if (estado_anterior == HIGH) {
      tempo_atual = millis();
      if (tempo_atual - tempo_anterior <= 3000 && est == 1) {
        tempo_anterior = tempo_atual;
      digitalWrite(verde, LOW);
      digitalWrite(amarelo, HIGH);
      est = 2;
      } else if (tempo_atual - tempo_anterior > 3000 && est == 2) {
        tempo_anterior = tempo_atual;
      digitalWrite(amarelo, LOW);
      digitalWrite(vermelho, HIGH);
      est = 3;
     
    } else if (tempo_atual - tempo_anterior > 2000 && est == 3) {
      tempo_anterior = tempo_atual;
      digitalWrite(verde_pedestre, HIGH);
      digitalWrite(vermelho_pedestre, LOW);
      est = 4;
     
    } else if (tempo_atual - tempo_anterior > 5000 && est == 4) {
      tempo_anterior = tempo_atual;
      for(int i = 0; i < 3; i++) {
        digitalWrite(verde_pedestre, LOW);
        delay(1000);
        digitalWrite(verde_pedestre, HIGH);
        delay(1000);    
      } est = 5;

      } else if (tempo_atual - tempo_anterior > 1000 && est == 5) {
      tempo_anterior = millis();
      digitalWrite(vermelho, LOW);
      digitalWrite(verde_pedestre, LOW);
      digitalWrite(verde, HIGH);
      digitalWrite(vermelho_pedestre, HIGH);
      est = 6;
    } while(millis() <= tempo_anterior + 5000 && est == 6) {
      estado_latencia = digitalRead(botao);
      if (estado_latencia == HIGH && latencia == LOW && est == 6) {
        latencia = estado_latencia;
        estado_botao = HIGH;
        latencia = HIGH;
      }
    }
  }
}//loop