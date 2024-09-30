#include "ExpressaoVariavel.hpp"
#include <iostream>
#include "../debug-util.hpp"
#include <stdexcept> // Incluir a biblioteca para usar std::runtime_error

using namespace std;

ExpressaoVariavel::ExpressaoVariavel() {}

tuple<Tipo, int, float> ExpressaoVariavel::avalia(stack<Tabela*>& stack_symbol_table) {
    auto tabela = stack_symbol_table.top(); // Obtém a tabela de símbolos do topo da pilha
    
    // Verifica se a variável está na tabela de símbolos
    if (tabela->tabela_simbolos.count(nome->nome) > 0) {
        auto simbolo = *(tabela->tabela_simbolos[nome->nome]);
        Tipo tipo = get<0>(simbolo);
        int valor_inteiro = 0;
        float valor_float = 0.0f;

        // Obtém o valor correspondente ao tipo
        switch (tipo) {
            case Tipo::INTEGER:
                valor_inteiro = get<1>(simbolo);
                break;
            case Tipo::FLOAT:
                valor_float = get<2>(simbolo);
                break;
            default:
                throw std::runtime_error("Tipo de variável não suportado.");
        }

        return make_tuple(tipo, valor_inteiro, valor_float);
    }

    // Lança uma exceção caso a variável não esteja na tabela de símbolos
    throw std::runtime_error("Variável não encontrada na tabela de símbolos");
}

void ExpressaoVariavel::debug_com_tab(int tab) {
    //tab3(tab);
    cerr << nome->nome << "[VARIAVEL]";
}
