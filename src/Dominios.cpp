//---------------------------------------------------------------------------
#include "Dominios.h"
//---------------------------------------------------------------------------

CodigoJogo::CodigoJogo(const string& codigoJogo) noexcept(false)
{
    validar(codigoJogo);
    valor = codigoJogo;
}

void CodigoJogo::validar(string codigoJogo) noexcept(false)
{
    if (codigoJogo.size() != 3)
        throw invalid_argument("Código do jogo em formato incorreto (XXX).");
    for (char i : codigoJogo) {
        if (!isdigit(i))
            throw invalid_argument("Código do jogo em formato incorreto (Somente números).");
    }
}

CodigoIngresso::CodigoIngresso(const string& codigoIngresso) noexcept(false)
{
    validar(codigoIngresso);
    valor = codigoIngresso;
}

void CodigoIngresso::validar(string codigoIngresso) noexcept(false)
{
    if (codigoIngresso.size() != 5)
        throw invalid_argument("Código de ingresso em formato incorreto (XXX).");
    for (char i : codigoIngresso) {
        if (!isdigit(i))
            throw invalid_argument("Código de ingresso em formato incorreto (Somente números).");
    }
}

NomeJogo::NomeJogo(const string& nomeJogo) noexcept(false)
{
    validar(nomeJogo);
    valor = nomeJogo;
}

void NomeJogo::validar(string nomeJogo) noexcept(false)
{
    bool possuiLetra = false;
    bool possuiSimbolo = false;
    char lastChar = '!';
    // TODO: Check if I can simply trim the length
//    string::iterator new_end = unique(nomeJogo.begin(), nomeJogo.end(), BothAreSpaces);
//    nomeJogo.erase(new_end, nomeJogo.end());

    // TODO: Check if it NEEDS to be 20 characters long, or just bellow 20 characters
    if (nomeJogo.size() > 20)
        throw invalid_argument("Nome do jogo em formato incorreto (20 dígitos).");
    for (char i : nomeJogo) {
        if (isalpha(i))
            possuiLetra = true;
        if ((!isalpha(i) && !isdigit(i)) && i != ' ')
            possuiSimbolo = true;
        if (lastChar == i && lastChar == ' ')
            throw invalid_argument("Nome do jogo em formato incorreto (Não pode possuir dois espaços em sequência).");
        lastChar = i;
    }
    if(!possuiLetra)
        throw invalid_argument("Nome do jogo em formato incorreto (Não possui letras).");
    if(possuiSimbolo)
        throw invalid_argument("Nome do jogo em formato incorreto (Possui simbolos diferentes de letra, espaço ou número).");
}

Data::Data(const string& data) noexcept(false)
{
    validar(data);
    valor = data;
}

void Data::validar(string data) noexcept(false)
{
    if (data.size() != 8 || (data.substr(2,1) != "/" && data.substr(5,1) != "/"))
        throw invalid_argument("Data em formato incorreto (DD/MM/AA).");

    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,2));

    if(dia < 1 || dia > 31)
        throw invalid_argument("Dia incorreto (01~31)");
    if(mes < 1 || mes > 12)
        throw invalid_argument("Mes incorreto (01~12)");
    if (ano < 0 || ano > 99)
        throw invalid_argument("Ano incorreto (00~99)");

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia == 31)
        throw invalid_argument("Dia não condiz com o mês.");
    if ((mes == 2) && (ano % 4 == 0) && dia > 29)
        throw invalid_argument("Dia não condiz com o mês/ano.");
    if ((mes == 2) && (ano % 4 != 0) && dia > 28)
        throw invalid_argument("Dia não condiz com o mês/ano.");
}

Horario::Horario(const string& horario) noexcept(false)
{
    validar(horario);
    valor = horario;
}

void Horario::validar(string horario) noexcept(false)
{

    if (horario.size() != 5 || horario.substr(2,1) != ":" )
        throw invalid_argument("Horário em formato incorreto (HH:MM).");

    int hora = stoi(horario.substr(0,2));
    string minuto = horario.substr(3,2);

    if(hora < 7 || hora > 22)
        throw invalid_argument("Hora fora do período válido (07~22).");
    if(minuto != "00" || minuto != "15" || minuto != "30" || minuto != "45")
        throw invalid_argument("Minuto fora do período válido (00, 15, 30, 45).");
}

Preco::Preco(const string& preco) noexcept(false)
{
    validar(preco);
    valor = preco;
}

void Preco::validar(string preco) noexcept(false)
{
    string replace = ".-";
    preco.erase(remove_if(preco.begin(), preco.end(),[&replace](const char& c) {
        return replace.find(c) != std::string::npos;
    }),preco.end());
    int total = stoi(preco);

    if(total < 0 || total > 100000)
        throw invalid_argument("Preço fora do permitido (R$ 0,00 ~ R$ 1000,00).");
}

NumeroSala::NumeroSala(const string& numeroSala) noexcept(false)
{
    validar(numeroSala);
    valor = numeroSala;
}

void NumeroSala::validar(string numeroSala) noexcept(false)
{
    int total = stoi(numeroSala);

    if(total < 1 || total > 10)
        throw invalid_argument("Sala não existente (1~10).");
}

Cidade::Cidade(const string& cidade) noexcept(false)
{
    validar(cidade);
    valor = cidade;
}

void Cidade::validar(string cidade) noexcept(false)
{
    bool possuiLetra = false;
    bool possuiSimbolo = false;
    char lastChar = '!';
    // TODO: Check if I can simply trim the length
//    string::iterator new_end = unique(nomeJogo.begin(), nomeJogo.end(), BothAreSpaces);
//    nomeJogo.erase(new_end, nomeJogo.end());

    // TODO: Check if it NEEDS to be 15 characters long, or just bellow 15 characters
    if (cidade.size() > 15)
        throw invalid_argument("Cidade em formato incorreto (15 dígitos).");
    for (char i : cidade) {
        if (isalpha(i))
            possuiLetra = true;
        if ((!isalpha(i) && !isdigit(i)) && i != ' ' && i != '.')
            possuiSimbolo = true;
        if (lastChar == i && lastChar == ' ')
            throw invalid_argument("Cidade em formato incorreto (Não pode possuir dois espaços em sequência).");
        if (!isalpha(lastChar) && i == '.')
            throw invalid_argument("Cidade em formato incorreto (Ponto deve ser precedido de letra).");
        lastChar = i;
    }
    if(!possuiLetra)
        throw invalid_argument("Cidade em formato incorreto (Não possui letras).");
    if(possuiSimbolo)
        throw invalid_argument("Cidade em formato incorreto (Possui simbolos diferentes de letra, espaço, ponto ou número).");
}

Estado::Estado(const string& estado) noexcept(false)
{
    validar(estado);
    valor = estado;
}

void Estado::validar(string estado) noexcept(false)
{
    vector<string> estados = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};
    if(!(find(estados.begin(), estados.end(), estado) != estados.end()))
        throw invalid_argument("Estado inválido (AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE, PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO).");

}

Disponibilidade::Disponibilidade(const string& disponibilidade) noexcept(false)
{
    validar(disponibilidade);
    valor = disponibilidade;
}

void Disponibilidade::validar(string disponibilidade) noexcept(false)
{
    int total = stoi(disponibilidade);

    if(total < 0 || total > 250)
        throw invalid_argument("Disponibilidade fora do disponível (0~250).");
}

Tipo::Tipo(const string& tipo) noexcept(false)
{
    validar(tipo);
    valor = tipo;
}

void Tipo::validar(string tipo) noexcept(false)
{
    int total = stoi(tipo);

    if(total < 0 || total > 4)
        throw invalid_argument("Tipo inválido (1~4).");
}

Cpf::Cpf(const string& cpf) noexcept(false)
{
    validar(cpf);
    valor = cpf;
}

void Cpf::validar(string cpf) noexcept(false)
{
    string replace = ".-";
    cpf.erase(remove_if(cpf.begin(), cpf.end(),[&replace](const char& c) {
                          return replace.find(c) != std::string::npos;
                      }),cpf.end());

    if(cpf.length() < 11)
        throw invalid_argument("Cpf inválido (XXX.XXX.XXX-XX).");

    char cpfArray[11];
    strcpy(cpfArray, cpf.c_str());

    int digito1, digito2, temp = 0;

    for(char i = 0; i < 9; i++)
        temp += ((cpfArray[i] - 48) * (10 - i));

    temp %= 11;

    if(temp < 2)
        digito1 = 0;
    else
        digito1 = 11 - temp;

    temp = 0;
    for(char i = 0; i < 10; i++)
        temp += ((cpfArray[i] - 48) * (11 - i));

    temp %= 11;

    if(temp < 2)
        digito2 = 0;
    else
        digito2 = 11 - temp;

    if(digito1 != (cpfArray[9] - 48) || digito2 != (cpfArray[10] - 48))
        throw invalid_argument("Cpf inválido (Digito verificador inválido).");
}

Senha::Senha(const string& senha) noexcept(false)
{
    validar(senha);
    valor = senha;
}

void Senha::validar(string senha) noexcept(false)
{
    bool possuiLetraMinuscula = false;
    bool possuiLetraMaisucula = false;
    bool possuiDigito = false;
    bool possuiSimbolo = false;
    char lastChar = '!';
    // TODO: Check if I can simply trim the length
//    string::iterator new_end = unique(nomeJogo.begin(), nomeJogo.end(), BothAreSpaces);
//    nomeJogo.erase(new_end, nomeJogo.end());

    // TODO: Check if it NEEDS to be 6 characters long, or just above 6 characters
    if (senha.size() != 6)
        throw invalid_argument("Senha em formato incorreto (6 dígitos).");
    for (char i : senha) {
        if (isalpha(i))
        {
            if(isupper(i))
                possuiLetraMaisucula = true;
            if(islower(i))
                possuiLetraMinuscula = true;
        }
        if (isdigit(i))
            possuiDigito = true;
        if ((!isalpha(i) && !isdigit(i)))
            possuiSimbolo = true;
        if (lastChar == i && lastChar == ' ')
            throw invalid_argument("Senha em formato incorreto (Não pode possuir espaços em sequência).");
        lastChar = i;
    }
    if(!possuiLetraMaisucula || !possuiLetraMinuscula || !possuiDigito)
        throw invalid_argument("Senha em formato incorreto (É necessário pelo menos um número, uma letra maiúscula e uma letra minúscula).");
    if(possuiSimbolo)
        throw invalid_argument("Senha em formato incorreto (Possui simbolos não alfanuméricos).");
}

NumeroCartao::NumeroCartao(const string& numeroCartao) noexcept(false)
{
    validar(numeroCartao);
    valor = numeroCartao;
}

void NumeroCartao::validar(string numeroCartao) noexcept(false)
{
    int total = stoi(numeroCartao);

    if(total < 0 || total > 16)
        throw invalid_argument("Número do cartão inválido possui formato inválido (XXXXXXXXXXXXXXXX).");

    static const int m[10]  = {0,2,4,6,8,1,3,5,7,9};
    bool impar = false;
    auto lambda = [&](int a, char c) {return a + ((impar = !impar) ? c-'0' : m[c-'0']);};
    int s = accumulate(numeroCartao.rbegin(), numeroCartao.rend(), 0, lambda);
    if(0 == s%10)
        throw invalid_argument("Número do cartão inválido (Falha na verificação).");
}

CodigoSeguranca::CodigoSeguranca(const string& codigoSeguranca) noexcept(false)
{
    validar(codigoSeguranca);
    valor = codigoSeguranca;
}

void CodigoSeguranca::validar(string codigoSeguranca) noexcept(false)
{
    if (codigoSeguranca.size() != 3)
        throw invalid_argument("Código de segurança em formato incorreto (XXX).");
    for (char i : codigoSeguranca) {
        if (!isdigit(i))
            throw invalid_argument("Código de segurança em formato incorreto (Somente dígitos).");
    }
}

DataValidade::DataValidade(const string& dataValidade) noexcept(false)
{
    validar(dataValidade);
    valor = dataValidade;
}

void DataValidade::validar(string dataValidade) noexcept(false)
{
    if (dataValidade.size() != 5 || dataValidade.substr(2,1) != "/")
        throw invalid_argument("Data de validade em formato incorreto (MM/AA).");

    int mes = stoi(dataValidade.substr(0,2));
    int ano = stoi(dataValidade.substr(3,2));

    if(mes < 1 || mes > 12)
        throw invalid_argument("Mes incorreto (01~12)");
    if (ano < 0 || ano > 99)
        throw invalid_argument("Ano incorreto (00~99)");
}




//bool BothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }