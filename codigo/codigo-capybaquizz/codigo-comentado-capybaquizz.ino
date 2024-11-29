#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuração dos LCDs
LiquidCrystal_I2C lcd20x4(0x27, 20, 4); // LCD 20x4 para exibir perguntas e respostas
LiquidCrystal_I2C lcd16x2(0x3F, 16, 2); // LCD 16x2 para mensagens adicionais

// Pinos dos botões
const int botaoSim = 2; // Pino digital para o botão "Sim"
const int botaoNao = 3; // Pino digital para o botão "Não"

// Variáveis de controle do jogo
int acertos = 0;               // Contador de respostas corretas
bool respostaSelecionada = false; // Flag para verificar se o jogador respondeu
int perguntaAtual = 1;         // Controle da pergunta atual no quiz

void setup() {
  // Inicialização dos LCDs
  lcd20x4.begin(20, 4); // Configura o LCD 20x4
  lcd20x4.backlight();  // Ativa a luz de fundo do LCD 20x4
  lcd16x2.begin(16, 2); // Configura o LCD 16x2
  lcd16x2.backlight();  // Ativa a luz de fundo do LCD 16x2

  // Configuração dos botões como entradas
  pinMode(botaoSim, INPUT); 
  pinMode(botaoNao, INPUT);

  // Exibição da tela inicial do jogo
  mostrarTelaInicial();
}

void loop() {
  // Aguardar a resposta do jogador para a questão atual
  if (!respostaSelecionada) {
    if (digitalRead(botaoSim) == HIGH) {
      respostaSelecionada = true; // Define como respondido
      verificarResposta(true);    // Checa se "Sim" é correto
    }
    if (digitalRead(botaoNao) == HIGH) {
      respostaSelecionada = true; // Define como respondido
      verificarResposta(false);   // Checa se "Não" é correto
    }
  }
}

// Exibe a tela inicial do jogo
void mostrarTelaInicial() {
  lcd20x4.clear(); // Limpa o display
  lcd20x4.setCursor(2, 0); // Define posição para centralizar
  lcd20x4.print("Bem-vindo ao");
  lcd20x4.setCursor(4, 1);
  lcd20x4.print("CapybaQuizz!");
  lcd20x4.setCursor(0, 3);
  lcd20x4.print("Pressione Sim ou Nao");

  // Aguarda que o jogador pressione algum botão
  while (digitalRead(botaoSim) == LOW && digitalRead(botaoNao) == LOW) {
    delay(100); // Reduz consumo de processamento
  }

  // Reinicia variáveis para o início do jogo
  acertos = 0;
  respostaSelecionada = false;
  perguntaAtual = 1;

  // Breve pausa antes de exibir a primeira questão
  delay(500);
  mostrarQuestao1(); // Exibe a primeira pergunta
}

// Funções para exibir as perguntas
void mostrarQuestao1() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 1:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Bolo de rolo e");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("comida pernambucana?");
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
}

void mostrarQuestao4() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 4:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("A Emparedada da");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("Rua Nova ficou gravida?");
}

void mostrarQuestao5() {
  lcd20x4.clear();
  lcd20x4.setCursor(0, 0);
  lcd20x4.print("Questao 5:");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Brennand fez o");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("Parque das Esculturas?");
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
  lcd20x4.print("Recife influenciado");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print("por Espanha e Alemanha?");
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

// Função para verificar a resposta do jogador
void verificarResposta(bool resposta) {
  lcd20x4.clear();

  // Variável para armazenar se a resposta está correta
  bool correto = false;

  // Define a resposta correta para cada pergunta
  switch (perguntaAtual) {
    case 1: correto = resposta; break;  // "Sim" é correto
    case 2: correto = !resposta; break; // "Não" é correto
    case 3: correto = !resposta; break; // "Não" é correto
    case 4: correto = resposta; break;  // "Sim" é correto
    case 5: correto = resposta; break;  // "Sim" é correto
    case 6: correto = resposta; break;  // "Sim" é correto
    case 7: correto = !resposta; break; // "Não" é correto
    case 8: correto = !resposta; break; // "Não" é correto
    case 9: correto = !resposta; break; // "Não" é correto
    case 10: correto = !resposta; break; // "Não" é correto
  }

  if (correto) {
    acertos++;
    lcd20x4.setCursor(0, 0);
    lcd20x4.print("Correto!");
  } else {
    lcd20x4.setCursor(0, 0);
    lcd20x4.print("Incorreto!");
  }

  delay(2000); // Tempo para exibir o feedback

  // Próxima pergunta ou tela final
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

// Tela final
void mostrarTelaFinal() {
  lcd20x4.clear();
  lcd20x4.setCursor(2, 0);
  lcd20x4.print("Fim do Quiz!");
  lcd20x4.setCursor(0, 1);
  lcd20x4.print("Voce acertou:");
  lcd20x4.setCursor(0, 2);
  lcd20x4.print(acertos);
  lcd20x4.print(" de 10 perguntas");

  while (digitalRead(botaoSim) == LOW && digitalRead(botaoNao) == LOW) {
    delay(200);
  }

  delay(500);
  mostrarTelaInicial();
}
