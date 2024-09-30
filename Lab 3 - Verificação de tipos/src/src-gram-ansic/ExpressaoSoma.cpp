#include "ExpressaoSoma.hpp"
#include <iostream>
#include <stdexcept>
#include "ExpressaoNumero.hpp"
#include "ExpressaoFloat.hpp"
#include "../debug-util.hpp"

using namespace std;

ExpressaoSoma::ExpressaoSoma() {}

tuple<Tipo, int, float> ExpressaoSoma::avalia(stack<Tabela *> &pilha_de_tabelas)
{
    tuple<Tipo, int, float> resultado;

    // Avalia a expressão da esquerda
    auto esq = esquerda->avalia(pilha_de_tabelas);

    // Avalia a expressão da direita
    auto dir = direita->avalia(pilha_de_tabelas);

    // Se os dois operandos forem inteiros
    if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::INTEGER)
    {
        int soma = get<1>(esq) + get<1>(dir);
        resultado = make_tuple(Tipo::INTEGER, soma, 0.0f);
    }
    // Se os dois operandos forem floats
    else if (get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::FLOAT)
    {
        float soma = get<2>(esq) + get<2>(dir);
        resultado = make_tuple(Tipo::FLOAT, 0, soma);
    }
    // Se o operando da esquerda for INTEGER e o da direita for FLOAT
    else if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::FLOAT)
    {
        float soma = get<1>(esq) + get<2>(dir);
        resultado = make_tuple(Tipo::FLOAT, 0, soma);
    }
    // Se o operando da esquerda for FLOAT e o da direita for INTEGER
    else if (get<0>(esq) == Tipo::FLOAT && get<0>(dir) == Tipo::INTEGER)
    {
        float soma = get<2>(esq) + get<1>(dir);
        resultado = make_tuple(Tipo::FLOAT, 0, soma);
    }
    // Se houver tipos incompatíveis
    else
    {
        throw runtime_error("Erro: Expressao soma com tipos incompativeis");
    }

    return resultado;
}

void ExpressaoSoma::debug_com_tab(int tab)
{
    tab3(tab);
    cerr << "INICIO SOMA [ " << endl;
    esquerda->debug_com_tab(tab + 1);
    tab3(tab);
    cerr << " + " << endl;
    direita->debug_com_tab(tab + 1);
    tab3(tab);
    cerr << "] FIM Soma" << endl;
}
