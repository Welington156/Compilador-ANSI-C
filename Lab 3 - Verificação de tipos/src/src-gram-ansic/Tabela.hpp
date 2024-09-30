#ifndef _TABELA_HPP_
#define _TABELA_HPP_
#include "Variavel.hpp"
#include <string>
#include <map>
#include <vector>
#include <tuple>
#include <memory>

using namespace std;

enum class Tipo {
    INTEGER,
    FLOAT
};

typedef tuple<Tipo, int, float> Valor;

class Tabela {
public:
    Tabela();
    map<string, Valor*> tabela_simbolos;
    map<string, bool*> passoucomoparametro;

    void adicionar_parametros(const vector<Variavel*>& parametros, const vector<tuple<Tipo, int, float>>& valores);
    void adicionar_simbolo(string nome, Valor* valor);
    Valor* obter_valor(string nome);
    void imprimir_tabela_simbolos();
};

#endif
