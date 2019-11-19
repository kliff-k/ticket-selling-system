#include "Apresentacao.h"

/**
 * Função principal do sistema:
 * SUPER STAR SOCCER STADIUM STICKER SELLING SYSTEM (S7)
 * Contact: murilo.mm.moraes@gmail.com
 * @brief Função principal
 * @author Murilo Moraes
 * @version 1.7
 * @date 16/11/2019
 * @return 0
 */
int main() {
    // Exibe a tela de login da aplicação
    Login login;
    login.executar();
    // Exibe a tela principal e inicia a navegação
    TelaPrincipal telaPrincipal;
    telaPrincipal.executar();

    return 0;
}