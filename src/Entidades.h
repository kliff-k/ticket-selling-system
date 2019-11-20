//-------------------------DEF-------------------------//

#ifndef TP_CPP_ENTIDADES_H
#define TP_CPP_ENTIDADES_H

//----------------------INCLUDES-----------------------//

#include "Dominios.h"

//----------------------CLASSES------------------------//

/**
 * Usuário do sistema
 */
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

/**
 * Jogo cadastrado no sistema
 */
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

/**
 * Partida vinculada a um jogo cadastrado no sistema
 */
class Partida {
private:
    CodigoPartida codigoPartida;
    Data data;
    Horario horario;
    Preco preco;
    Disponibilidade disponibilidade;
public:
    Partida()= default;
    Partida(CodigoPartida, Data, Horario, Preco, Disponibilidade);
    CodigoPartida getCodigoPartida() const;
    void setCodigoPartida(const CodigoPartida&);
    Data getData() const;
    void setData(const Data&);
    Horario getHorario() const;
    void setHorario(const Horario&);
    Preco getPreco() const;
    void setPreco(const Preco&);
    Disponibilidade getDisponibilidade() const;
    void setDisponibilidade(const Disponibilidade&);
};

/**
 * Ingresso para um jogo no sistema
 */
class Ingresso {
private:
    CodigoIngresso codigoIngresso;
public:
    Ingresso()= default;
    Ingresso(CodigoIngresso);
    CodigoIngresso getCodigoIngresso() const;
    void setCodigoIngresso(const CodigoIngresso&);
};

/**
 * Cartão de crédito registrado no sistema para efetuar pagamentos/compras
 */
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

//----------------------INLINE-------------------------//

/**
 * Recupera CPF do usuário
 * @return Cpf
 */
inline Cpf Usuario::getCpf() const {
    return cpf;
}
/**
 * Recupera senha do usuário
 * @return Senha
 */
inline Senha Usuario::getSenha() const {
    return senha;
}

/**
 * Recupera código do jogo
 * @return CodigoJogo
 */
inline CodigoJogo Jogo::getCodigoJogo() const {
    return codigoJogo;
}

/**
 * Recupera nome do jogo
 * @return NomeJogo
 */
inline NomeJogo Jogo::getNomeJogo() const {
    return nomeJogo;
}

/**
 * Recupera cidade do jogo
 * @return Cidade
 */
inline Cidade Jogo::getCidade() const {
    return cidade;
}

/**
 * Recupera estado do jogo
 * @return Estado
 */
inline Estado Jogo::getEstado() const {
    return estado;
}

/**
 * Recupera tipo do jogo
 * @return Tipo
 */
inline Tipo Jogo::getTipo() const {
    return tipo;
}

/**
 * Recupera código do jogo
 * @return CodigoPartida
 */
inline CodigoPartida Partida::getCodigoPartida() const {
    return CodigoPartida();
}

/**
 * Recupera data da partida
 * @return Data
 */
inline Data Partida::getData() const {
    return Data();
}

/**
 * Recupera horário da partida
 * @return Horario
 */
inline Horario Partida::getHorario() const {
    return Horario();
}

/**
 * Recupera preço do ingresso da partida
 * @return Preco
 */
inline Preco Partida::getPreco() const {
    return Preco();
}

/**
 * Recupera número de assentos disponíveis na partida
 * @return Disponibilidade
 */
inline Disponibilidade Partida::getDisponibilidade() const {
    return Disponibilidade();
}

/**
 * Recupera código do ingresso
 * @return CodigoIngresso
 */
inline CodigoIngresso Ingresso::getCodigoIngresso() const {
    return CodigoIngresso();
}

/**
 * Recupera número do cartão de crédito
 * @return NumeroCartao
 */
inline NumeroCartao CartaoCredito::getNumeroCartao() const {
    return NumeroCartao();
}

/**
 * Recupera código de segurança do cartão de crédito
 * @return CodigoSeguranca
 */
inline CodigoSeguranca CartaoCredito::getCodigoSeguranca() const {
    return CodigoSeguranca();
}

/**
 * Recupera a data de validade do cartão de crédito
 * @return DataValidade
 */
inline DataValidade CartaoCredito::getDataValidade() const {
    return DataValidade();
}

//-------------------------DEF-------------------------//

#endif //TP_CPP_ENTIDADES_H
