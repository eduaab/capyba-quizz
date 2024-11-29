#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuração dos LCDs
LiquidCrystal_I2C lcd20x4(0x27, 20, 4); // LCD 20x4 para questões e respostas
LiquidCrystal_I2C lcd16x2(0x3F, 16, 2); // LCD 16x2 para mensagens adicionais

// Pinos dos botões
const int botaoSim = 2;
const int botaoNao = 3;

// Variáveis de controle
int acertos = 0;
bool respostaSelecionada = false;
int perguntaAtual = 1; // Variável para controlar qual questão está sendo feita

void setup() {
  // Inicializa os LCDs
  lcd20x4.begin(20, 4);
  lcd20x4.backlight();
  lcd16x2.begin(16, 2);
  lcd16x2.backlight();

  // Configura os botões como entrada
  pinMode(botaoSim, INPUT);
  pinMode(botaoNao, INPUT);

  // Mostra a tela inicial
  mostrarTelaInicial();
}

void loop() {
  // Verifica a resposta da questão atual
  if (!respostaSelecionada) {
    if (digitalRead(botaoSim) == HIGH) {
      respostaSelecionada = true;
      verificarResposta(true);
    }
    if (digitalRead(botaoNao) == HIGH) {
      respostaSelecionada = true;
      verificarResposta(false);
    }
  }
}

void mostrarTelaInicial() {
  lcd20x4.clear();
  lcd20x4.setCursor(2, 0);
  lcd20x4.print("Bem-vindo ao");
  lcd20x4.setCursor(4, 1);
  lcd20x4.print("CapybaQuizz!");
  lcd20x4.setCursor(0, 3);
  lcd20x4.print("Pressione Sim ou Nao");

  // Aguarda o usuário pressionar um botão
  while (digitalRead(botaoSim) == LOW && digitalRead(botaoNao) == LOW) {
    delay(100); // Aguarda para evitar loop excessivamente rápido
  }

  // Reseta variáveis para o próximo jogo
  acertos = 0;
  respostaSelecionada = false;
  perguntaAtual = 1;

  // Breve pausa antes de iniciar o quiz
  delay(500);

  // Mostra a primeira questão
  mostrarQuestao1();
}

void mostrarQuestao1() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 1:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Bolo de rolo e");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("comida pernambucana?");
  lcd20x4.setCursor(0, 3);

}

void mostrarQuestao2() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 2:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("O Cesar e o");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("responsavel pelo");
  lcd20x4.setCursor(0, 3);
  lcd20x4.print("rec n' play?");
}

void mostrarQuestao3() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 3:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Cartola leva");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("queijo prato?");
  lcd20x4.setCursor(0, 3);

}

void mostrarQuestao4() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 4:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("A Emparedada da");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("Rua Nova ficou");
  lcd20x4.setCursor(0, 3);
  lcd20x4.print(" gravida?");
}

void mostrarQuestao5() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 5:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Brennand fez o");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("Parque das ");
  lcd20x4.setCursor(0, 3);
  lcd20x4.print("Esculturas?");
}
void mostrarQuestao6() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 6:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Frevo mistura marcha,");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("maxixe e capoeira?");
}
void mostrarQuestao7() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 7:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Rio Sao Francisco");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("corta o Recife?");
}
void mostrarQuestao8() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 8:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Frevo tem batuques");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("e alfaias?");
}
void mostrarQuestao9() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 9:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("A estrutura Recifense");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("foi influenciada por");
  lcd20x4.setCursor(0, 3);
  lcd20x4.print("Espanha e Alemanha?");
}
void mostrarQuestao10() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 10:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Torre Malakoff era");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("um teatro?");
}
void verificarResposta(bool resposta) {
  lcd20x4.clear();

  // Verifica a resposta de acordo com a pergunta atual
  bool correto = false;
  switch (perguntaAtual) {
    case 1: correto = resposta; break;
    case 2: correto = !resposta; break;
    case 3: correto = !resposta; break;
    case 4: correto = resposta; break;
    case 5: correto = resposta; break;
    case 6: correto = resposta; break;
    case 7: correto = !resposta; break;
    case 8: correto = !resposta; break;
    case 9: correto = !resposta; break;
    case 10: correto = !resposta; break;
  }

  if (correto) {
    acertos++;
    lcd20x4.setCursor(0, 0);
    lcd20x4.print("Correto!");
  } else {
    lcd20x4.setCursor(0, 0);
    lcd20x4.print("Incorreto!");
  }

  delay(2000); // Pausa para mostrar o resultado

  // Passa para a próxima pergunta ou finaliza o quiz
  if (perguntaAtual < 10) {
    perguntaAtual++;
    respostaSelecionada = false;
    switch (perguntaAtual) {
      case 2: mostrarQuestao2(); break;
      case 3: mostrarQuestao3(); break;
      case 4: mostrarQuestao4(); break;
      case 5: mostrarQuestao5(); break;
      case 6: mostrarQuestao6(); break;
      case 7: mostrarQuestao7(); break;
      case 8: mostrarQuestao8(); break;
      case 9: mostrarQuestao9(); break;
      case 10: mostrarQuestao10(); break;
    }
  } else {
    mostrarTelaFinal();
  }
}

void mostrarTelaFinal() {
  lcd20x4.clear();
  lcd20x4.setCursor(2, 0);
  lcd20x4.print("Fim do Quiz!");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Voce acertou:");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print(acertos);
  lcd20x4.print(" de 10 perguntas");

  lcd20x4.setCursor(0, 3);
  lcd20x4.print("Pressione um botao");

  // Reduz o tempo de pausa antes de aceitar interação
  delay(1500); // Aguarda 1.5 segundos antes de permitir o botão

  // Aguarda o usuário pressionar um botão para voltar à tela inicial
  while (digitalRead(botaoSim) == LOW && digitalRead(botaoNao) == LOW) {
    delay(200); // Aguarda sem consumir processamento excessivo
  }

  // Breve pausa após o botão ser pressionado
  delay(500);

  // Retorna à tela inicial
  mostrarTelaInicial();
}
