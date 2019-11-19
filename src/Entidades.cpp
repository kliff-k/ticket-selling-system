//----------------------INCLUDES-----------------------//

#include "Entidades.h"

//-------------------IMPLEMENTATIONS-------------------//

/**
 * Construtor do Usuario
 * @param cpf
 * @param senha
 */
Usuario::Usuario(Cpf cpf, Senha senha):cpf(move(cpf)), senha(move(senha)){}

/**
 * Atribui CPF ao Usuário
 * @param cpf
 */
void Usuario::setCpf(const Cpf& cpfNovo) {
    this->cpf = cpfNovo;
}

/**
 * Atribui senha ao usuário
 * @param senha
 */
void Usuario::setSenha(const Senha& senhaNova) {
    this->senha = senhaNova;
}

/**
 * Construtor do Jogo
 * @param codigoJogo
 * @param nomeJogo
 * @param cidade
 * @param estado
 * @param tipo
 */
Jogo::Jogo(CodigoJogo codigoJogo, NomeJogo nomeJogo, Cidade cidade, Estado estado, Tipo tipo): codigoJogo(move(codigoJogo)), nomeJogo(move(nomeJogo)), cidade(move(cidade)), estado(move(estado)), tipo(move(tipo)){}

/**
 * Atribui código ao jogo
 * @param codigoJogo
 */
void Jogo::setCodigoJogo(const CodigoJogo& codigoJogoNovo) {
    this->codigoJogo = codigoJogoNovo;
}

/**
 * Atribui nome ao jogo
 * @param nomeJogo
 */
void Jogo::setNomeJogo(const NomeJogo& nomeJogoNovo) {
    this->nomeJogo = nomeJogoNovo;
}

/**
 * Atribui cidade ao jogo
 * @param cidade
 */
void Jogo::setCidade(const Cidade& cidadeNova) {
    this->cidade = cidadeNova;
}

/**
 * Atribui estado ao jogo
 * @param estado
 */
void Jogo::setEstado(const Estado& estadoNovo) {
    this->estado = estadoNovo;
}

/**
 * Atribui tipo ao jogo
 * @param tipo
 */
void Jogo::setTipo(const Tipo& tipoNovo) {
    this->tipo = tipoNovo;
}

/**
 * Contrutor da Partida
 * @param codigoJogo
 * @param data
 * @param horario
 * @param preco
 * @param disponibilidade
 */
Partida::Partida(CodigoJogo codigoJogo, Data data, Horario horario, Preco preco, Disponibilidade disponibilidade): codigoJogo(move(codigoJogo)), data(move(data)), horario(move(horario)), preco(move(preco)), disponibilidade(move(disponibilidade)){}

/**
 * Atribui código à partida
 * @param codigoJogo
 */
void Partida::setCodigoJogo(const CodigoJogo & codigoJogoNovo) {
    this->codigoJogo = codigoJogoNovo;
}

/**
 * Atribui data à partida
 * @param data
 */
void Partida::setData(const Data& dataNova) {
    this->data = dataNova;
}

/**
 * Atribui horário à partida
 * @param horario
 */
void Partida::setHorario(const Horario& horarioNovo) {
    this->horario = horarioNovo;
}

/**
 * Atribui preço à partida
 * @param preco
 */
void Partida::setPreco(const Preco& precoNovo) {
    this->preco = precoNovo;
}

/**
 * Atribui disponibilidade à partida
 * @param disponibilidade
 */
void Partida::setDisponibilidade(const Disponibilidade& disponibilidadeNova) {
    this->disponibilidade = disponibilidadeNova;
}

/**
 * Construtor do Ingresso
 * @param codigoIngresso
 */
Ingresso::Ingresso(CodigoIngresso codigoIngresso): codigoIngresso(move(codigoIngresso)){}

/**
 * Atribui código ao ingresso
 * @param codigoIngresso
 */
void Ingresso::setCodigoIngresso(const CodigoIngresso& codigoIngressoNovo) {
    this->codigoIngresso = codigoIngressoNovo;
}

/**
 * Construtor do CartaoCredito
 * @param numeroCartao
 * @param codigoSeguranca
 * @param dataValidade
 */
CartaoCredito::CartaoCredito(NumeroCartao numeroCartao, CodigoSeguranca codigoSeguranca, DataValidade dataValidade): numeroCartao(move(numeroCartao)), codigoSeguranca(move(codigoSeguranca)), dataValidade(move(dataValidade)){}

/**
 * Atribui número ao cartão de crédito
 * @param numeroCartao
 */
void CartaoCredito::setNumeroCartao(const NumeroCartao& numeroCartaoNovo) {
    this->numeroCartao = numeroCartaoNovo;
}

/**
 * Atribui código de segurança ao cartão de crédito
 * @param codigoSeguranca
 */
void CartaoCredito::setCodigoSeguranca(const CodigoSeguranca& codigoSegurancaNovo) {
    this->codigoSeguranca = codigoSegurancaNovo;
}

/**
 * Atribui data de validade ao cartão de crédito
 * @param dataValidade
 */
void CartaoCredito::setDataValidade(const DataValidade& dataValidadeNova) {
    this->dataValidade = dataValidadeNova;
}
