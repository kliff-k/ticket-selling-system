//-------------------------DEF-------------------------//

#ifndef TP_CPP_DOMINIOS_H
#define TP_CPP_DOMINIOS_H

//----------------------INCLUDES-----------------------//

#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <regex>
#include <numeric>
#include <utility>
#include <list>
#include <fstream>
#include <pqxx/pqxx>

//---------------------NAMESPACES----------------------//

using namespace std;
using namespace pqxx;

//----------------------CLASSES------------------------//

/**
 * Superclasse dos domínios utilizados no sistema
 */
class Dominios {
    virtual void validar(string) noexcept(false) = 0;
protected:
    string valor;
public:
    Dominios()= default;
    void setValor(const string&) noexcept(false);
    string getValor() const;
};

/**
 * Código do jogo
 */
class CodigoJogo:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    CodigoJogo()= default;
    explicit CodigoJogo(const string&) noexcept(false);
};
/**
 * Código do ingresso
 */
class CodigoIngresso:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    CodigoIngresso()= default;
    explicit CodigoIngresso(const string&) noexcept(false);
};
/**
 * Nome do jogo
 */
class NomeJogo:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    NomeJogo()= default;
    explicit NomeJogo(const string&) noexcept(false);
};
/**
 * Data do evento do jogo
 */
class Data:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    Data()= default;
    explicit Data(const string&) noexcept(false);
};

/**
 * Horário de início do jogo
 */
class Horario:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    Horario()= default;
    explicit Horario(const string&) noexcept(false);
};

/**
 * Preço do ingresso
 */
class Preco:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    Preco()= default;
    explicit Preco(const string&) noexcept(false);
};

/**
 * Número da sala vinculada ao ingresso
 */
class NumeroSala:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    NumeroSala()= default;
    explicit NumeroSala(const string&) noexcept(false);
};

/**
 * Cidade onde acontecerá o jogo
 */
class Cidade:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    Cidade()= default;
    explicit Cidade(const string&) noexcept(false);
};

/**
 * Estado onde acontecerá o jogo
 */
class Estado:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    Estado()= default;
    explicit Estado(const string&) noexcept(false);
};

/**
 * Número de assentos disponíveis para o jogo
 */
class Disponibilidade:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    Disponibilidade()= default;
    explicit Disponibilidade(const string&) noexcept(false);
};

/**
 * Tipo (categoria) do jogo
 * 1 - LOCAL
 * 2 - ESTADUAL
 * 3 - NACIONAL
 * 4 - INTERNACIONAL
 */
class Tipo:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    Tipo()= default;
    explicit Tipo(const string&) noexcept(false);
};

/**
 * CPF do usuário do sistema
 */
class Cpf:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    Cpf()= default;
    explicit Cpf(const string&) noexcept(false);
};

/**
 * Senha do usuário do sistema
 */
class Senha:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    Senha()= default;
    explicit Senha(const string&) noexcept(false);
};

/**
 * Número do cartão de crédito a ser utilizado
 */
class NumeroCartao:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    NumeroCartao()= default;
    explicit NumeroCartao(const string&) noexcept(false);
};

/**
 * Código de segurança do cartão de crédito a ser utilizado
 */
class CodigoSeguranca:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    CodigoSeguranca()= default;
    explicit CodigoSeguranca(const string&) noexcept(false);
};

/**
 * Data de validade do cartão de crédito a ser utilizado
 */
class DataValidade:public Dominios {
private:
    void validar(string) noexcept(false) override;
public:
    DataValidade()= default;
    explicit DataValidade(const string&) noexcept(false);
};

//----------------------INLINE-------------------------//

/**
 * Atribui valor ao membros protegidos da classe
 * @param valorNovo
 */
inline void Dominios::setValor(const string& valorNovo) noexcept(false) {
    validar(valorNovo);
    this->valor = valorNovo;
}

/**
 * Recupera o valor dos membros protegidos da classe
 * @return String com o valor do membro
 */
inline string Dominios::getValor() const {
    return valor;
}

//-------------------------DEF-------------------------//

#endif //TP_CPP_DOMINIOS_H
