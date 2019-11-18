//---------------------------------------------------------------------------
#include "Servicos.h"
//---------------------------------------------------------------------------

//Atributo estático container List.

list<ElementoResultado> ComandoSQL::listaResultado;

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
    this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
    this->valorColuna = valorColuna;
}

void ComandoSQL::conectar() noexcept(false) {
    bd = new connection("dbname=s7_db user=s7_user password=s7_pass hostaddr=127.0.0.1 port=5432");
    if(!bd->is_open())
        throw runtime_error("Erro na conexao ao banco de dados.");
}

void ComandoSQL::desconectar() noexcept(false) {
    bd->disconnect();
    if(bd->is_open())
        throw runtime_error("Erro na desconexao ao banco de dados.");
}

void ComandoSQL::executar() noexcept(false) {
    conectar();
    nontransaction N(*bd);
    result R( N.exec( comandoSQL ));

    if(R.empty())
        throw runtime_error("Erro na execucao do comando SQL.");

    ElementoResultado elemento;
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

//---------------------------------------------------------------------------
//Classe ComandoLerSenha.

ComandoLerSenha::ComandoLerSenha(Cpf cpf) {
    comandoSQL = "SELECT senha FROM usuarios WHERE cpf = ";
    comandoSQL += "'"+cpf.getValor()+"'";
}

string ComandoLerSenha::getResultado() noexcept(false) {
    ElementoResultado resultado;
    string senha;

    if (listaResultado.empty())
        throw runtime_error("Lista de resultados vazia.");

    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha = resultado.getValorColuna();

    return senha;
}

//---------------------------------------------------------------------------
//Classe ComandoPesquisarAluno.

ComandoPesquisarUsuario::ComandoPesquisarUsuario(Cpf cpf) {
    comandoSQL = "SELECT * FROM usuarios WHERE cpf = ";
    comandoSQL += cpf.getValor();
}

Usuario ComandoPesquisarUsuario::getResultado() noexcept(false) {
    ElementoResultado resultado;
    Usuario usuario;

    if (listaResultado.empty())
        throw runtime_error("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    usuario.setCpf(Cpf(resultado.getValorColuna()));

    return usuario;

}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarAluno.

ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario) {
    comandoSQL = "INSERT INTO usuarios VALUES (";
    comandoSQL += "'" + usuario.getCpf().getValor() + "', ";
    comandoSQL += "'" + usuario.getSenha().getValor() + "')";
}

//---------------------------------------------------------------------------
//Classe ComandoRemoverAluno.

ComandoRemoverUsuario::ComandoRemoverUsuario(Cpf cpf) {
    comandoSQL = "DELETE FROM usuarios WHERE cpf = ";
    comandoSQL += cpf.getValor();
}

//---------------------------------------------------------------------------
//Classe ComandoEditarAluno.

ComandoAtualizarUsuario::ComandoAtualizarUsuario(Usuario usuario) {
    comandoSQL = "UPDATE usuarios ";
    comandoSQL += "SET cpf = '" + usuario.getCpf().getValor();
    comandoSQL += "', senha = '" + usuario.getSenha().getValor();
}