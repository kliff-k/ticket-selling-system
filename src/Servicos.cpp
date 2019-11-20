//----------------------INCLUDES-----------------------//

#include "Servicos.h"

//-------------------IMPLEMENTATIONS-------------------//

/**
 * Container List
 */
list<ElementoConsulta> Consulta::listaResultado;

/**
 * Atribui nome da coluna à elemento da lista de resultado
 * @param nomeColuna
 */
void ElementoConsulta::setNomeColuna(const string& nomeColunaNovo) {
    this->nomeColuna = nomeColunaNovo;
}

/**
 * Atribui valor da coluna à elemento da lista de resultado
 * @param valorColunaNovo
 */
void ElementoConsulta::setValorColuna(const string& valorColunaNovo){
    this->valorColuna = valorColunaNovo;
}

/**
 * Conecta ao banco de dados (Postgresql)
 */
void Consulta::conectar() noexcept(false) {
    bd = new connection(conParams);
    if(!bd->is_open())
        throw runtime_error("Erro na conexão ao banco de dados.");
}

/**
 * Desconecta do banco de dados (Postgresql)
 */
void Consulta::desconectar() noexcept(false) {
    bd->disconnect();
    if(bd->is_open())
        throw runtime_error("Erro na desconexão ao banco de dados.");
}

/**
 * Executa a consulta
 */
void Consulta::executar() noexcept(false) {
    conectar();
    nontransaction N(*bd);
    result R( N.exec( comandoSQL ));

    if(R.empty())
        throw runtime_error("Erro na execucao do comando SQL.");

    ElementoConsulta elemento;
    for (result::const_iterator c = R.begin(); c != R.end(); c++)
    {
        for (unsigned int i = 0; i < c.size(); i++)
        {
            elemento.setNomeColuna(c[i].name());
            elemento.setValorColuna(!c[i].as<string>().empty() ? c[i].as<string>(): "NULL");
            listaResultado.push_front(elemento);
        }
    }
    desconectar();
}

/**
 * Busca os dados do usuário com base em seu cpf
 * @param cpf
 */
ComandoPesquisarUsuario::ComandoPesquisarUsuario(const Cpf& cpf) {
    comandoSQL = "SELECT * FROM usuarios WHERE cpf = '" + cpf.getValor() + "'";
}

/**
 * Varre o resultado da consulta ao usuário e insere na lista de elementos
 * @return
 */
Usuario ComandoPesquisarUsuario::getResultado() noexcept(false) {
    ElementoConsulta resultado;
    Usuario usuario;

    if (listaResultado.empty())
        throw runtime_error("Lista de resultados vazia.");

    resultado = listaResultado.back();
    listaResultado.pop_back();
    usuario.setCpf(Cpf(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    usuario.setSenha(Senha(resultado.getValorColuna()));

    return usuario;
}

/**
 * Cadastra o usuário no banco
 * @param usuario
 */
ComandoCadastrarUsuario::ComandoCadastrarUsuario(const Usuario& usuario) {
    comandoSQL = "INSERT INTO usuarios VALUES ('" + usuario.getCpf().getValor() + "', '" + usuario.getSenha().getValor() + "')";
}

/**
 * Remove o usuário do banco
 * @param cpf
 */
ComandoRemoverUsuario::ComandoRemoverUsuario(const Cpf& cpf) {
    comandoSQL = "DELETE FROM usuarios WHERE cpf = '" + cpf.getValor() + "';";
}

/**
 * Atualiza os dados do usuário
 * @param usuario
 */
ComandoAtualizarUsuario::ComandoAtualizarUsuario(const Usuario& usuario) {
    comandoSQL = "UPDATE usuarios SET cpf = '" + usuario.getCpf().getValor() + "', senha = '" + usuario.getSenha().getValor() + "' WHERE cpf = '" + usuario.getCpf().getValor() + "';";
}

/**
 * Busca os dados do jogo com base no seu código
 * @param codigoJogo
 */
ComandoPesquisarJogo::ComandoPesquisarJogo(const CodigoJogo& codigoJogo) {
    comandoSQL = "SELECT * FROM jogos WHERE codigoJogo = '" + codigoJogo.getValor() + "';";
}

/**
 * Varre o resultado da consulta ao jogo e insere na lista de elementos
 * @return
 */
Jogo ComandoPesquisarJogo::getResultado() noexcept(false) {
    ElementoConsulta resultado;
    Jogo jogo;

    if (listaResultado.empty())
        throw runtime_error("Lista de resultados vazia.");

    resultado = listaResultado.back();
    listaResultado.pop_back();
    jogo.setCodigoJogo(CodigoJogo(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    jogo.setNomeJogo(NomeJogo(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    jogo.setCidade(Cidade(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    jogo.setEstado(Estado(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    jogo.setTipo(Tipo(resultado.getValorColuna()));

    return jogo;
}

/**
 * Cadastra um novo jogo no banco
 * @param jogo
 */
ComandoCadastrarJogo::ComandoCadastrarJogo(const Jogo& jogo) {
    comandoSQL = "INSERT INTO jogos VALUES ('" + jogo.getNomeJogo().getValor() + "', '" + jogo.getCidade().getValor() + "', '" + jogo.getEstado().getValor() + "', '" + jogo.getTipo().getValor() + "') ";
}

/**
 * Remove um jogo do banco
 * @param codigoJogo
 */
ComandoRemoverJogo::ComandoRemoverJogo(const CodigoJogo& codigoJogo) {
    comandoSQL = "DELETE FROM jogos WHERE codigoJogo = '" + codigoJogo.getValor() + "';";
}

/**
 * Atualiza os dados de um jogo
 * @param jogo
 */
ComandoAtualizarJogo::ComandoAtualizarJogo(const Jogo& jogo) {
    comandoSQL = "UPDATE jogos SET nomeJogo = '" + jogo.getNomeJogo().getValor() + "', cidade = '" + jogo.getCidade().getValor() + "', estado = '" + jogo.getEstado().getValor() + "', tipo = '" + jogo.getTipo().getValor() + "' WHERE codigoJogo = '" + jogo.getCodigoJogo().getValor() + "';";
}

/**
 * Busca os dados de uma partida
 * @param codigoJogo
 */
ComandoPesquisarPartida::ComandoPesquisarPartida(const CodigoJogo& codigoJogo) {
    comandoSQL = "SELECT * FROM partidas WHERE codigoJogo = '" + codigoJogo.getValor() + "';";
}

/**
 * Varre o resultado da consulta à partida e insere na lista de elementos
 * @return
 */
Partida ComandoPesquisarPartida::getResultado() noexcept(false) {
    ElementoConsulta resultado;
    Partida partida;

    if (listaResultado.empty())
        throw runtime_error("Lista de resultados vazia.");

    resultado = listaResultado.back();
    listaResultado.pop_back();
    partida.setCodigoPartida(CodigoPartida(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    partida.setData(Data(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    partida.setHorario(Horario(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    partida.setPreco(Preco(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    partida.setDisponibilidade(Disponibilidade(resultado.getValorColuna()));

    return partida;
}

/**
 * Cadastra uma nova partida no banco
 * @param partida
 */
ComandoCadastrarPartida::ComandoCadastrarPartida(const Partida& partida) {
    comandoSQL = "INSERT INTO partidas VALUES ('" + partida.getData().getValor() + "', '" + partida.getHorario().getValor() + "', '" + partida.getPreco().getValor() + "', '" + partida.getDisponibilidade().getValor() + "') ";
}

/**
 * Remove uma partida do banco
 * @param codigoJogo
 */
ComandoRemoverPartida::ComandoRemoverPartida(const CodigoJogo& codigoJogo) {
    comandoSQL = "DELETE FROM partidas WHERE codigoJogo = '" + codigoJogo.getValor() + "';";
}

/**
 * Atualiza uma partida no banco
 * @param partida
 */
ComandoAtualizarPartida::ComandoAtualizarPartida(const Partida& partida) {
    comandoSQL = "UPDATE partidas SET data = '" + partida.getData().getValor() + "', horario = '" + partida.getHorario().getValor() + "', preco = '" + partida.getPreco().getValor() + "', disponibilidade = '" + partida.getDisponibilidade().getValor() + "' WHERE codigoPartida = '" + partida.getCodigoPartida().getValor() + "';";
}

/**
 * Busca os dados de um ingresso no banco
 * @param codigoIngresso
 */
ComandoPesquisarIngresso::ComandoPesquisarIngresso(const CodigoIngresso& codigoIngresso) {
    comandoSQL = "SELECT * FROM ingressos WHERE codigoIngresso = '" + codigoIngresso.getValor() + "';";
}

/**
 * Varre o resultado da consulta ao ingresso e insere na lista de elementos
 * @return
 */
Ingresso ComandoPesquisarIngresso::getResultado() noexcept(false) {
    ElementoConsulta resultado;
    Ingresso ingresso;

    if (listaResultado.empty())
        throw runtime_error("Lista de resultados vazia.");

    resultado = listaResultado.back();
    listaResultado.pop_back();
    ingresso.setCodigoIngresso(CodigoIngresso(resultado.getValorColuna()));

    return ingresso;
}

/**
 * Cadastra um novo ingresso no banco
 * @param ingresso
 */
ComandoCadastrarIngresso::ComandoCadastrarIngresso(const Ingresso& ingresso) {
    comandoSQL = "INSERT INTO ingressos VALUES ('" + ingresso.getCodigoIngresso().getValor() + "');";
}

/**
 * Remove um ingresso do banco
 * @param codigoIngresso
 */
ComandoRemoverIngresso::ComandoRemoverIngresso(const CodigoIngresso& codigoIngresso) {
    comandoSQL = "DELETE FROM ingressos WHERE codigoIngresso = '" + codigoIngresso.getValor() + "';";
}

/**
 * Atualiza dados do ingresso no banco
 * @param ingresso
 */
ComandoAtualizarIngresso::ComandoAtualizarIngresso(const Ingresso& ingresso) {
    comandoSQL = "UPDATE jogos SET codigoIngresso = '" + ingresso.getCodigoIngresso().getValor() + "' WHERE codigoIngresso = '" + ingresso.getCodigoIngresso().getValor() + "';";
}

/**
 * Busca dados de cartão de crédito no banco
 * @param numeroCartao
 */
ComandoPesquisarCartaoCredito::ComandoPesquisarCartaoCredito(const NumeroCartao& numeroCartao) {
    comandoSQL = "SELECT * FROM cartoes WHERE numeroCartao = '" + numeroCartao.getValor() + "';";
}

/**
 * Varre o resultado da consulta ao cartão de crédito e insere na lista de elementos
 * @return
 */
CartaoCredito ComandoPesquisarCartaoCredito::getResultado() noexcept(false) {
    ElementoConsulta resultado;
    CartaoCredito cartaoCredito;

    if (listaResultado.empty())
        throw runtime_error("Lista de resultados vazia.");

    resultado = listaResultado.back();
    listaResultado.pop_back();
    cartaoCredito.setNumeroCartao(NumeroCartao(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    cartaoCredito.setCodigoSeguranca(CodigoSeguranca(resultado.getValorColuna()));

    resultado = listaResultado.back();
    listaResultado.pop_back();
    cartaoCredito.setDataValidade(DataValidade(resultado.getValorColuna()));

    return cartaoCredito;
}

/**
 * Cadastra novo cartão de crédito no banco
 * @param cartaoCredito
 */
ComandoCadastrarCartaoCredito::ComandoCadastrarCartaoCredito(const CartaoCredito& cartaoCredito) {
    comandoSQL = "INSERT INTO cartoes VALUES ('" + cartaoCredito.getNumeroCartao().getValor() + "', '" + cartaoCredito.getDataValidade().getValor() + "', '" + cartaoCredito.getCodigoSeguranca().getValor() + "');";
}

/**
 * Remove cartão de crédito do banco
 * @param numeroCartao
 */
ComandoRemoverCartaoCredito::ComandoRemoverCartaoCredito(const NumeroCartao& numeroCartao) {
    comandoSQL = "DELETE FROM cartoes WHERE numeroCartao = '" + numeroCartao.getValor() + "';";
}

/**
 * Atualiza dados do cartão de crédito no banco
 * @param cartaoCredito
 */
ComandoAtualizarCartaoCredito::ComandoAtualizarCartaoCredito(const CartaoCredito& cartaoCredito) {
    comandoSQL = "UPDATE jogos SET codigoSeguranca = '" + cartaoCredito.getCodigoSeguranca().getValor() + "', dataValidade = '" + cartaoCredito.getDataValidade().getValor() + "' WHERE numeroCartao = '" + cartaoCredito.getNumeroCartao().getValor() + "';";
}