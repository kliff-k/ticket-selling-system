//----------------------INCLUDES-----------------------//

#include "Apresentacao.h"

//-------------------IMPLEMENTATIONS-------------------//


/**
 * Notifica erros de acesso ao banco
 */
void Apresentacao::notificarErroAcesso(){

}

/**
 * Notifica erros de entrada
 */
void Apresentacao::notificarErroDigitacao() {

}

/**
 * Notifica sucesso na execução
 */
void Apresentacao::notificarSucessoOperacao() {

}

/**
 * Inicia e prepara a janela com a biblioteca curses
 */
void Janela::inicia() {

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

}

/**
 * Finaliza a janela com a biblioteca curses
 */
void Janela::finaliza() {

    endwin();

}

/**
 * Constroi a tela de login
 */
void TelaInicial::apresentarOpcoes(){

    char welcome[] = "SUPER STAR SOCCER STADIUM STICKER SELLING SYSTEM (S7)";
    int x, y;

    getmaxyx(stdscr, x, y);

    move(x/2, (y-strlen(welcome)) / 2);

    printw (welcome);

    refresh();

    menuwin = newwin (7, y-12, x-9, 6);
    box(menuwin, 0, 0);

    refresh();
    wrefresh(menuwin);
    keypad(menuwin, TRUE);

    char * options[] = {
            "Login",
            "Se cadastre",
            "Sair"
    };
    int choice;
    int select = 0;

    while (true)
    {
        for(int i = 0; i <3; i ++) {
            if (i == select)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, options[i]);
            if (i == select)
                wattroff(menuwin, A_REVERSE);
        }

        choice = wgetch(menuwin);
        switch (choice)
        {
            case KEY_UP:
                select--;
                if (select <0) select = 0;
                break;
            case KEY_DOWN:
                select++;
                if (select> 2) select = 2;
                break;
            default:
                break;
        }

        if (choice == 10) break;
    }

    printw ("\n Selected:% s", options[select]);
    refresh();

}

/**
 * Exibe a tela de login do usuário
 */
void TelaInicial::executar(){
    apresentarOpcoes();
}

/**
 * Constroi a tela de login
 */
void Login::apresentarOpcoes(){

}

/**
 * Exibe a tela de login do usuário
 */
void Login::executar(){

}

/**
 * Constroi a tela principal do sistema
 */
void TelaPrincipal::apresentarOpcoes(){

}

/**
 * Exibe a tela principal do sistema
 */
void TelaPrincipal::executar(){

}

/**
 * Constroi a tela do usuário
 */
void TelaUsuario::apresentarOpcoes(){

}

/**
 * Exibe a tela do usuário
 */
void TelaUsuario::executar(){

}

/**
 * Exibe os dados do usuário
 */
void TelaUsuario::pesquisar() {

}

/**
 * Cadastra um novo usuário
 */
void TelaUsuario::cadastrar() {

}

/**
 * Remove um usuário
 */
void TelaUsuario::remover() {

}

/**
 * Edita um usuário
 */
void TelaUsuario::editar() {

}