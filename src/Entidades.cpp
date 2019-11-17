//---------------------------------------------------------------------------
#include "Entidades.h"
//---------------------------------------------------------------------------

Usuario::Usuario(Cpf cpf, Senha senha):
    cpf(move(cpf)), senha(move(senha)){}

void Usuario::setCpf(const Cpf& cpf) {
    this->cpf = cpf;
}

void Usuario::setSenha(const Senha& senha) {
    this->senha = senha;
}
//---------------------------------------------------------------------------

Jogo::Jogo(CodigoJogo codigoJogo, NomeJogo nomeJogo, Cidade cidade, Estado estado, Tipo tipo):
    codigoJogo(move(codigoJogo)), nomeJogo(move(nomeJogo)), cidade(move(cidade)), estado(move(estado)), tipo(move(tipo)){}

void Jogo::setCodigoJogo(const CodigoJogo& codigoJogo) {
    this->codigoJogo = codigoJogo;
}

void Jogo::setNomeJogo(const NomeJogo& nomeJogo) {
    this->nomeJogo = nomeJogo;
}

void Jogo::setCidade(const Cidade& cidade) {
    this->cidade = cidade;
}

void Jogo::setEstado(const Estado& estado) {
    this->estado = estado;
}

void Jogo::setTipo(const Tipo& tipo) {
    this->tipo = tipo;
}
//---------------------------------------------------------------------------

Partida::Partida(CodigoJogo codigoJogo, Data data, Horario horario, Preco preco, Disponibilidade disponibilidade):
    codigoJogo(move(codigoJogo)), data(move(data)), horario(move(horario)), preco(move(preco)), disponibilidade(move(disponibilidade)){}

void Partida::setCodigoJogo(const CodigoJogo & codigoJogo) {
    this->codigoJogo = codigoJogo;
}

void Partida::setData(const Data& data) {
    this->data = data;
}

void Partida::setHorario(const Horario& horario) {
    this->horario = horario;
}

void Partida::setPreco(const Preco& preco) {
    this->preco = preco;
}

void Partida::setDisponibilidade(const Disponibilidade& disponibilidade) {
    this->disponibilidade = disponibilidade;
}
//---------------------------------------------------------------------------

Ingresso::Ingresso(CodigoIngresso codigoIngresso):
    codigoIngresso(move(codigoIngresso)){}

void Ingresso::setCodigoIngresso(const CodigoIngresso& codigoIngresso) {
    this->codigoIngresso = codigoIngresso;
}
//---------------------------------------------------------------------------

CartaoCredito::CartaoCredito(NumeroCartao numeroCartao, CodigoSeguranca codigoSeguranca, DataValidade dataValidade):
    numeroCartao(move(numeroCartao)), codigoSeguranca(move(codigoSeguranca)), dataValidade(move(dataValidade)){}

void CartaoCredito::setNumeroCartao(const NumeroCartao& numeroCartao) {
    this->numeroCartao = numeroCartao;
}

void CartaoCredito::setCodigoSeguranca(const CodigoSeguranca& codigoSeguranca) {
    this->codigoSeguranca = codigoSeguranca;
}

void CartaoCredito::setDataValidade(const DataValidade& dataValidade) {
    this->dataValidade = dataValidade;
}
