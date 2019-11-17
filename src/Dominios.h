//---------------------------------------------------------------------------
#ifndef TP_CPP_DOMINIOS_H
#define TP_CPP_DOMINIOS_H
//---------------------------------------------------------------------------
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <regex>
#include <numeric>
#include <utility>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------

/**
 * Domínios utilizados pelo sistema
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

inline void Dominios::setValor(const string& valor) noexcept(false) {
    validar(valor);
    this->valor = valor;
}

inline string Dominios::getValor() const {
    return valor;
}

class CodigoJogo:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    CodigoJogo()= default;
    explicit CodigoJogo(const string&) noexcept(false);
};

class CodigoIngresso:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    CodigoIngresso()= default;
    explicit CodigoIngresso(const string&) noexcept(false);
};

class NomeJogo:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    NomeJogo()= default;
    explicit NomeJogo(const string&) noexcept(false);
};

class Data:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    Data()= default;
    explicit Data(const string&) noexcept(false);
};

class Horario:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    Horario()= default;
    explicit Horario(const string&) noexcept(false);
};

class Preco:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    Preco()= default;
    explicit Preco(const string&) noexcept(false);
};

class NumeroSala:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    NumeroSala()= default;
    explicit NumeroSala(const string&) noexcept(false);
};

class Cidade:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    Cidade()= default;
    explicit Cidade(const string&) noexcept(false);
};

class Estado:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    Estado()= default;
    explicit Estado(const string&) noexcept(false);
};

class Disponibilidade:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    Disponibilidade()= default;
    explicit Disponibilidade(const string&) noexcept(false);
};

class Tipo:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    Tipo()= default;
    explicit Tipo(const string&) noexcept(false);
};

class Cpf:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    Cpf()= default;
    explicit Cpf(const string&) noexcept(false);
};

class Senha:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    Senha()= default;
    explicit Senha(const string&) noexcept(false);
};

class NumeroCartao:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    NumeroCartao()= default;
    explicit NumeroCartao(const string&) noexcept(false);
};

class CodigoSeguranca:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    CodigoSeguranca()= default;
    explicit CodigoSeguranca(const string&) noexcept(false);
};

class DataValidade:public Dominios {
private:
    void validar(string) noexcept(false);
public:
    DataValidade()= default;
    explicit DataValidade(const string&) noexcept(false);
};
#endif //TP_CPP_DOMINIOS_H
