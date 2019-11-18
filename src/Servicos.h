//---------------------------------------------------------------------------
#ifndef TP_CPP_SERVICOS_H
#define TP_CPP_SERVICOS_H
//---------------------------------------------------------------------------
#include "Entidades.h"
//---------------------------------------------------------------------------

class ElementoResultado {
private:
    string nomeColuna;
    string valorColuna;
public:
    void setNomeColuna(const string&);
    string getNomeColuna() const;
    void setValorColuna(const string&);
    string getValorColuna() const;
};

//---------------------------------------------------------------------------
//Classe ComandoSQL.

class ComandoSQL {
private:
    const char *nomeBancoDados;
    connection *bd;
    void conectar() noexcept(false);
    void desconectar() noexcept(false);
protected:
    static list<ElementoResultado> listaResultado;
    string comandoSQL;
public:
    ComandoSQL() {
        nomeBancoDados = "testedb";
    }
    void executar() noexcept(false);
};


//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

class ComandoLerSenha:public ComandoSQL {
public:
    ComandoLerSenha(Cpf);
    string getResultado() noexcept(false);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarAluno.

class ComandoPesquisarUsuario:public ComandoSQL {
public:
    ComandoPesquisarUsuario(Cpf);
    Usuario getResultado() noexcept(false);
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarAluno.

class ComandoCadastrarUsuario:public ComandoSQL {
public:
    ComandoCadastrarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarAluno.

class ComandoAtualizarUsuario:public ComandoSQL {
public:
    ComandoAtualizarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoRemoverAluno.

class ComandoRemoverUsuario:public ComandoSQL {
public:
    ComandoRemoverUsuario(Cpf);
};

inline string ElementoResultado::getNomeColuna() const {
    return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
    return valorColuna;
}

#endif //TP_CPP_SERVICOS_H
