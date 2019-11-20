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
    Janela::inicia();

    TelaInicial telaInicial;
    telaInicial.executar();

    Janela::finaliza();

    return 0;
}