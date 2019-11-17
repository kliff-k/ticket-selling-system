//---------------------------------------------------------------------------
#ifndef TP_CPP_ENTIDADES_H
#define TP_CPP_ENTIDADES_H
//---------------------------------------------------------------------------
#include "Dominios.h"
//---------------------------------------------------------------------------

class Usuario {
private:
    Cpf cpf;
    Senha senha;
public:
    Usuario()= default;
    Usuario(Cpf, Senha);
    Cpf getCpf() const;
    void setCpf(const Cpf&);
    Senha getSenha() const;
    void setSenha(const Senha&);
};

class Jogo {
private:
    CodigoJogo codigoJogo;
    NomeJogo nomeJogo;
    Cidade cidade;
    Estado estado;
    Tipo tipo;
public:
    Jogo()= default;
    Jogo(CodigoJogo, NomeJogo, Cidade, Estado, Tipo);
    CodigoJogo getCodigoJogo() const;
    void setCodigoJogo(const CodigoJogo&);
    NomeJogo getNomeJogo() const;
    void setNomeJogo(const NomeJogo&);
    Cidade getCidade() const;
    void setCidade(const Cidade&);
    Estado getEstado() const;
    void setEstado(const Estado&);
    Tipo getTipo() const;
    void setTipo(const Tipo&);
};

// TODO: Qual a diferença de partida de Jogo??
class Partida {
private:
    CodigoJogo codigoJogo;
    Data data;
    Horario horario;
    Preco preco;
    Disponibilidade disponibilidade;
public:
    Partida()= default;
    Partida(CodigoJogo, Data, Horario, Preco, Disponibilidade);
    CodigoJogo getCodigoJogo() const;
    void setCodigoJogo(const CodigoJogo&);
    Data getData() const;
    void setData(const Data&);
    Horario getHorario() const;
    void setHorario(const Horario&);
    Preco getPreco() const;
    void setPreco(const Preco&);
    Disponibilidade getDisponibilidade() const;
    void setDisponibilidade(const Disponibilidade&);
};

class Ingresso {
private:
    CodigoIngresso codigoIngresso;
public:
    Ingresso()= default;
    Ingresso(CodigoIngresso);
    CodigoIngresso getCodigoIngresso() const;
    void setCodigoIngresso(const CodigoIngresso&);
};

class CartaoCredito {
private:
    NumeroCartao numeroCartao;
    CodigoSeguranca codigoSeguranca;
    DataValidade dataValidade;
public:
    CartaoCredito()= default;
    CartaoCredito(NumeroCartao, CodigoSeguranca, DataValidade);
    NumeroCartao getNumeroCartao() const;
    void setNumeroCartao(const NumeroCartao&);
    CodigoSeguranca getCodigoSeguranca() const;
    void setCodigoSeguranca(const CodigoSeguranca&);
    DataValidade getDataValidade() const;
    void setDataValidade(const DataValidade&);
};

inline Cpf Usuario::getCpf() const {
    return cpf;
}

inline Senha Usuario::getSenha() const {
    return senha;
}

inline CodigoJogo Jogo::getCodigoJogo() const {
    return codigoJogo;
}

inline NomeJogo Jogo::getNomeJogo() const {
    return nomeJogo;
}

inline Cidade Jogo::getCidade() const {
    return cidade;
}

inline Estado Jogo::getEstado() const {
    return estado;
}

inline Tipo Jogo::getTipo() const {
    return tipo;
}

inline CodigoJogo Partida::getCodigoJogo() const {
    return CodigoJogo();
}

inline Data Partida::getData() const {
    return Data();
}

inline Horario Partida::getHorario() const {
    return Horario();
}

inline Preco Partida::getPreco() const {
    return Preco();
}

inline Disponibilidade Partida::getDisponibilidade() const {
    return Disponibilidade();
}

inline CodigoIngresso Ingresso::getCodigoIngresso() const {
    return CodigoIngresso();
}

inline NumeroCartao CartaoCredito::getNumeroCartao() const {
    return NumeroCartao();
}

inline CodigoSeguranca CartaoCredito::getCodigoSeguranca() const {
    return CodigoSeguranca();
}

inline DataValidade CartaoCredito::getDataValidade() const {
    return DataValidade();
}

#endif //TP_CPP_ENTIDADES_H
