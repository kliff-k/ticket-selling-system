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
ComandoPesquisarUsuario::ComandoPesquisarUsuario(Cpf cpf) {
    comandoSQL = "SELECT * FROM usuarios WHERE cpf = '";
    comandoSQL += cpf.getValor() + "'";
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
ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario) {
    comandoSQL = "INSERT INTO usuarios VALUES (";
    comandoSQL += "'" + usuario.getCpf().getValor() + "', ";
    comandoSQL += "'" + usuario.getSenha().getValor() + "')";
}

/**
 * Remove o usuário do banco
 * @param cpf
 */
ComandoRemoverUsuario::ComandoRemoverUsuario(Cpf cpf) {
    comandoSQL = "DELETE FROM usuarios WHERE cpf = ";
    comandoSQL += cpf.getValor();
}

/**
 * Atualiza os dados do usuário
 * @param usuario
 */
ComandoAtualizarUsuario::ComandoAtualizarUsuario(Usuario usuario) {
    comandoSQL = "UPDATE usuarios ";
    comandoSQL += "SET cpf = '" + usuario.getCpf().getValor() + "',";
    comandoSQL += " senha = '" + usuario.getSenha().getValor() + "'";
    comandoSQL += " WHERE cpf = '" + usuario.getCpf().getValor() + "';";
}

/**
 * Busca os dados do jogo com base no seu código
 * @param codigoJogo
 */
ComandoPesquisarJogo::ComandoPesquisarJogo(CodigoJogo codigoJogo) {
    comandoSQL = "SELECT * FROM jogos WHERE codigoJogo = ";
    comandoSQL += codigoJogo.getValor();
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
ComandoCadastrarJogo::ComandoCadastrarJogo(Jogo jogo) {
    comandoSQL = "INSERT INTO jogos VALUES (";
    comandoSQL += "'" + jogo.getNomeJogo().getValor() + "', ";
    comandoSQL += "'" + jogo.getCidade().getValor() + "', ";
    comandoSQL += "'" + jogo.getEstado().getValor() + "', ";
    comandoSQL += "'" + jogo.getTipo().getValor() + "') ";
}

/**
 * Remove um jogo do banco
 * @param codigoJogo
 */
ComandoRemoverJogo::ComandoRemoverJogo(CodigoJogo codigoJogo) {
    comandoSQL = "DELETE FROM jogos WHERE codigoJogo = ";
    comandoSQL += codigoJogo.getValor();
}

/**
 * Atualiza os dados de um jogo
 * @param jogo
 */
ComandoAtualizarJogo::ComandoAtualizarJogo(Jogo jogo) {
    comandoSQL = "UPDATE jogos ";
    comandoSQL += "SET nomeJogo = '" + jogo.getNomeJogo().getValor() + "',";
    comandoSQL += " cidade = '" + jogo.getCidade().getValor() + "',";
    comandoSQL += " estado = '" + jogo.getEstado().getValor() + "',";
    comandoSQL += " tipo = '" + jogo.getTipo().getValor() + "'";
    comandoSQL += " WHERE cpf = '" + jogo.getCodigoJogo().getValor() + "';";
}

/**
 * Busca os dados de uma partida
 * @param codigoJogo
 */
ComandoPesquisarPartida::ComandoPesquisarPartida(CodigoJogo codigoJogo) {
    comandoSQL = "SELECT * FROM partidas WHERE codigoJogo = ";
    comandoSQL += codigoJogo.getValor();
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
    partida.setCodigoJogo(CodigoJogo(resultado.getValorColuna()));

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
ComandoCadastrarPartida::ComandoCadastrarPartida(Partida partida) {
    comandoSQL = "INSERT INTO partidas VALUES (";
    comandoSQL += "'" + partida.getData().getValor() + "', ";
    comandoSQL += "'" + partida.getHorario().getValor() + "', ";
    comandoSQL += "'" + partida.getPreco().getValor() + "', ";
    comandoSQL += "'" + partida.getDisponibilidade().getValor() + "') ";
}

/**
 * Remove uma partida do banco
 * @param codigoJogo
 */
ComandoRemoverPartida::ComandoRemoverPartida(CodigoJogo codigoJogo) {
    comandoSQL = "DELETE FROM partidas WHERE codigoJogo = ";
    comandoSQL += codigoJogo.getValor();
}

/**
 * Atualiza uma partida no banco
 * @param partida
 */
ComandoAtualizarPartida::ComandoAtualizarPartida(Partida partida) {
    comandoSQL = "UPDATE partidas ";
    comandoSQL += "SET data = '" + partida.getData().getValor() + "',";
    comandoSQL += " horario = '" + partida.getHorario().getValor() + "',";
    comandoSQL += " preco = '" + partida.getPreco().getValor() + "',";
    comandoSQL += " disponibilidade = '" + partida.getDisponibilidade().getValor() + "'";
    comandoSQL += " WHERE cpf = '" + partida.getCodigoJogo().getValor() + "';";
}

/**
 * Busca os dados de um ingresso no banco
 * @param codigoIngresso
 */
ComandoPesquisarIngresso::ComandoPesquisarIngresso(CodigoIngresso codigoIngresso) {
    comandoSQL = "SELECT * FROM ingressos WHERE codigoIngresso = ";
    comandoSQL += codigoIngresso.getValor();
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
ComandoCadastrarIngresso::ComandoCadastrarIngresso(Ingresso ingresso) {
    comandoSQL = "INSERT INTO ingressos VALUES (";
    comandoSQL += "'" + ingresso.getCodigoIngresso().getValor() + "') ";
}

/**
 * Remove um ingresso do banco
 * @param codigoIngresso
 */
ComandoRemoverIngresso::ComandoRemoverIngresso(CodigoIngresso codigoIngresso) {
    comandoSQL = "DELETE FROM ingressos WHERE codigoIngresso = ";
    comandoSQL += codigoIngresso.getValor();
}

/**
 * Atualiza dados do ingresso no banco
 * @param ingresso
 */
ComandoAtualizarIngresso::ComandoAtualizarIngresso(Ingresso ingresso) {
    comandoSQL = "UPDATE jogos ";
    comandoSQL += "SET codigoIngresso = '" + ingresso.getCodigoIngresso().getValor() + "'";
    comandoSQL += " WHERE codigoIngresso = '" + ingresso.getCodigoIngresso().getValor() + "';";
}

/**
 * Busca dados de cartão de crédito no banco
 * @param numeroCartao
 */
ComandoPesquisarCartaoCredito::ComandoPesquisarCartaoCredito(NumeroCartao numeroCartao) {
    comandoSQL = "SELECT * FROM cartoes WHERE numeroCartao = ";
    comandoSQL += numeroCartao.getValor();
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
ComandoCadastrarCartaoCredito::ComandoCadastrarCartaoCredito(CartaoCredito cartaoCredito) {
    comandoSQL = "INSERT INTO cartoes VALUES (";
    comandoSQL += "'" + cartaoCredito.getNumeroCartao().getValor() + "', ";
    comandoSQL += "'" + cartaoCredito.getDataValidade().getValor() + "', ";
    comandoSQL += "'" + cartaoCredito.getCodigoSeguranca().getValor() + "') ";
}

/**
 * Remove cartão de crédito do banco
 * @param numeroCartao
 */
ComandoRemoverCartaoCredito::ComandoRemoverCartaoCredito(NumeroCartao numeroCartao) {
    comandoSQL = "DELETE FROM cartoes WHERE numeroCartao = ";
    comandoSQL += numeroCartao.getValor();
}

/**
 * Atualiza dados do cartão de crédito no banco
 * @param cartaoCredito
 */
ComandoAtualizarCartaoCredito::ComandoAtualizarCartaoCredito(CartaoCredito cartaoCredito) {
    comandoSQL = "UPDATE jogos ";
    comandoSQL += "SET codigoSeguranca = '" + cartaoCredito.getCodigoSeguranca().getValor() + "'";
    comandoSQL += "SET dataValidade = '" + cartaoCredito.getDataValidade().getValor() + "'";
    comandoSQL += " WHERE numeroCartao = '" + cartaoCredito.getNumeroCartao().getValor() + "';";
}