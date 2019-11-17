#include "Entidades.h"
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
    Usuario usuario;
    Cpf cpf;
    cpf.setValor("024.429.761-45");
    usuario.setCpf(cpf);
    return 0;
}