//-------------------------DEF-------------------------//

#ifndef TP_CPP_SERVICOS_H
#define TP_CPP_SERVICOS_H

//----------------------INCLUDES-----------------------//

#include "Entidades.h"

//----------------------CLASSES------------------------//

/**
 * Elementos (por coluna) retornados pela consulta
 */
class ElementoConsulta {
private:
    string nomeColuna;
    string valorColuna;
public:
    void setNomeColuna(const string&);
    string getNomeColuna() const;
    void setValorColuna(const string&);
    string getValorColuna() const;
};

/**
 * Superclasse de consulta ao banco Postgresql
 */
class Consulta {
private:
    const char *nomeBancoDados;
    string conParams;
    connection *bd;
    void conectar() noexcept(false);
    void desconectar() noexcept(false);
protected:
    static list<ElementoConsulta> listaResultado;
    string comandoSQL;
public:
    Consulta() {
        // Consulta o arquivo de configuração para recuperar a string de conexão
        ifstream inf("../config/db.conf");
        string strInput;
        getline(inf, strInput);

        nomeBancoDados = "S7 (Postgresql)";
        conParams = strInput;
        bd = nullptr;
    }
    void executar() noexcept(false);
};

/**
 * Operações READ sobre o usuário
 */
class ComandoPesquisarUsuario:public Consulta {
public:
    explicit ComandoPesquisarUsuario(Cpf);
    Usuario getResultado() noexcept(false);
};

/**
 * Operações CREATE sobre o usuário
 */
class ComandoCadastrarUsuario:public Consulta {
public:
    explicit ComandoCadastrarUsuario(Usuario);
};

/**
 * Operações UPDATE sobre o usuário
 */
class ComandoAtualizarUsuario:public Consulta {
public:
    explicit ComandoAtualizarUsuario(Usuario);
};

/**
 * Operações DELETE sobre o usuário
 */
class ComandoRemoverUsuario:public Consulta {
public:
    explicit ComandoRemoverUsuario(Cpf);
};

/**
 * Operações READ sobre o jogo
 */
class ComandoPesquisarJogo:public Consulta {
public:
    explicit ComandoPesquisarJogo(CodigoJogo);
    Jogo getResultado() noexcept(false);
};

/**
 * Operações CREATE sobre o jogo
 */
class ComandoCadastrarJogo:public Consulta {
public:
    explicit ComandoCadastrarJogo(Jogo);
};

/**
 * Operações UPDATE sobre o jogo
 */
class ComandoAtualizarJogo:public Consulta {
public:
    explicit ComandoAtualizarJogo(Jogo);
};

/**
 * Operações DELETE sobre o jogo
 */
class ComandoRemoverJogo:public Consulta {
public:
    explicit ComandoRemoverJogo(CodigoJogo);
};

/**
 * Operações READ sobre a partida
 */
class ComandoPesquisarPartida:public Consulta {
public:
    explicit ComandoPesquisarPartida(CodigoJogo);
    Partida getResultado() noexcept(false);
};

/**
 * Operações CREATE sobre a partida
 */
class ComandoCadastrarPartida:public Consulta {
public:
    explicit ComandoCadastrarPartida(Partida);
};

/**
 * Operações UPDATE sobre a partida
 */
class ComandoAtualizarPartida:public Consulta {
public:
    explicit ComandoAtualizarPartida(Partida);
};

/**
 * Operações DELETE sobre a partida
 */
class ComandoRemoverPartida:public Consulta {
public:
    explicit ComandoRemoverPartida(CodigoJogo);
};

/**
 * Operações READ sobre o ingresso
 */
class ComandoPesquisarIngresso:public Consulta {
public:
    explicit ComandoPesquisarIngresso(CodigoIngresso);
    Ingresso getResultado() noexcept(false);
};

/**
 * Operações CREATE sobre o ingresso
 */
class ComandoCadastrarIngresso:public Consulta {
public:
    explicit ComandoCadastrarIngresso(Ingresso);
};

/**
 * Operações UPDATE sobre o ingresso
 */
class ComandoAtualizarIngresso:public Consulta {
public:
    explicit ComandoAtualizarIngresso(Ingresso);
};

/**
 * Operações DELETE sobre o ingresso
 */
class ComandoRemoverIngresso:public Consulta {
public:
    explicit ComandoRemoverIngresso(CodigoIngresso);
};

/**
 * Operações READ sobre o cartão de crédito
 */
class ComandoPesquisarCartaoCredito:public Consulta {
public:
    explicit ComandoPesquisarCartaoCredito(NumeroCartao);
    CartaoCredito getResultado() noexcept(false);
};

/**
 * Operações CREATE sobre o cartão de crédito
 */
class ComandoCadastrarCartaoCredito:public Consulta {
public:
    explicit ComandoCadastrarCartaoCredito(CartaoCredito);
};

/**
 * Operações UPDATE sobre o cartão de crédito
 */
class ComandoAtualizarCartaoCredito:public Consulta {
public:
    explicit ComandoAtualizarCartaoCredito(CartaoCredito);
};

/**
 * Operações DELETE sobre o cartão de crédito
 */
class ComandoRemoverCartaoCredito:public Consulta {
public:
    explicit ComandoRemoverCartaoCredito(NumeroCartao);
};

//----------------------INLINE-------------------------//

/**
 * Recupera o nome da coluna
 * @return String com o nome da coluna
 */
inline string ElementoConsulta::getNomeColuna() const {
    return nomeColuna;
}

/**
 * Recupera o valor da coluna
 * @return String com o valor da coluna
 */
inline string ElementoConsulta::getValorColuna() const {
    return valorColuna;
}

//-------------------------DEF-------------------------//

#endif //TP_CPP_SERVICOS_H
