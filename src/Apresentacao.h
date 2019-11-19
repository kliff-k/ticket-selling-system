//-------------------------DEF-------------------------//

#ifndef TP_CPP_APRESENTACAO_H
#define TP_CPP_APRESENTACAO_H

//----------------------INCLUDES-----------------------//

#include "Servicos.h"

//----------------------CLASSES------------------------//

/**
 * Superclasse para a construção da interface gráfica
 */
class Apresentacao {
    virtual void apresentarOpcoes() = 0;
protected:
    static void notificarErroAcesso();
    static void notificarErroDigitacao();
    static void notificarSucessoOperacao();
public:
    virtual void executar() = 0;
};

/**
 * Login do usuário no sistema
 */
class Login: public Apresentacao {
    void apresentarOpcoes() override;
public:
    Login()= default;
    void executar() override;
};

/**
 * Apresenta a tela principal da interface
 */
class TelaPrincipal: public Apresentacao {
    void apresentarOpcoes() override;
public:
    TelaPrincipal()= default;
    void executar() override;
};

/**
 * Tela com as opções de gerência de usuário
 */
class TelaUsuario: public Apresentacao {
    void apresentarOpcoes() override;
    void pesquisar();
    void cadastrar();
    void remover();
    void editar();
public:
    TelaUsuario()= default;
    void executar() override;
};

/**
 * Tela com as opções de gerência de jogo
 */
class TelaJogo: public Apresentacao {
    void apresentarOpcoes() override;
    void pesquisar();
    void cadastrar();
    void remover();
    void editar();
public:
    TelaJogo()= default;
    void executar() override;
};

/**
 * Tela com as opções de gerência de partida
 */
class TelaPartida: public Apresentacao {
    void apresentarOpcoes() override;
    void pesquisar();
    void cadastrar();
    void remover();
    void editar();
public:
    TelaPartida()= default;
    void executar() override;
};

/**
 * Tela com as opções de gerência de ingresso
 */
class TelaIngresso: public Apresentacao {
    void apresentarOpcoes() override;
    void pesquisar();
    void cadastrar();
    void remover();
    void editar();
public:
    TelaIngresso()= default;
    void executar() override;
};

/**
 * Tela com as opções de gerência de cartão
 */
class TelaCartao: public Apresentacao {
    void apresentarOpcoes() override;
    void pesquisar();
    void cadastrar();
    void remover();
    void editar();
public:
    TelaCartao()= default;
    void executar() override;
};

//-------------------------DEF-------------------------//

#endif //TP_CPP_APRESENTACAO_H
