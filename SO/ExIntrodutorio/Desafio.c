#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t sigint_count = 0;
volatile sig_atomic_t esperando_resposta = 0;
volatile sig_atomic_t timeout_ocorreu = 0;

// Converte inteiro simples para string (0-9)
void intToStr(int num, char *str) {
    str[0] = num + '0';
    str[1] = '\0';
}

// Handler do Ctrl+C
void handler_sigint(int signum) {
    sigint_count++;
}

// Handler do Ctrl+Z
void handler_sigtstp(int signum) {
    char msg1[] = "\nVocê apertou Ctrl-C '";
    char msg2[2];
    char msg3[] = "' vezes\n";

    intToStr(sigint_count, msg2);

    write(1, msg1, strlen(msg1));
    write(1, msg2, strlen(msg2));
    write(1, msg3, strlen(msg3));
}

// Handler do alarme de 20s
void handler_sigalrm(int signum) {
    timeout_ocorreu = 1;
}

int main() {
    // Instala os handlers
    signal(SIGINT, handler_sigint);
    signal(SIGTSTP, handler_sigtstp);
    signal(SIGALRM, handler_sigalrm);

    char pergunta[] = "\nRealmente deseja sair? [Y/n]: ";
    char saida[] = "\nSaindo...\n";
    char continuando[] = "\nContinuando...\n";
    char timeout_msg[] = "\nDemorou muito para responder. Saindo......\n";

    while (1) {
        pause(); // espera por sinais

        if (sigint_count >= 3 && !esperando_resposta) {
            esperando_resposta = 1;
            timeout_ocorreu = 0;

            write(1, pergunta, strlen(pergunta));
            alarm(20);

            char resposta[4] = {0};
            int lido = read(0, resposta, sizeof(resposta));
            alarm(0); // cancela o alarme se respondeu

            if (timeout_ocorreu) {
                write(1, timeout_msg, strlen(timeout_msg));
                exit(0);
            }

            if (lido > 0 && (resposta[0] == 'y' || resposta[0] == 'Y' || resposta[0] == '\n')) {
                write(1, saida, strlen(saida));
                exit(0);
            } else {
                write(1, continuando, strlen(continuando));
                sigint_count = 0;
                esperando_resposta = 0;
            }
        }
    }

    return 0;
}
