#include "ExpressaoMod.hpp"
#include <iostream>
#include <cmath>
#include "../debug-util.hpp"

using namespace std;

ExpressaoMod::ExpressaoMod() {}

tuple<Tipo, int, float> ExpressaoMod::avalia(stack<Tabela*> &pilha_de_tabelas) {
    tuple<Tipo, int, float> resultado;

    // Avalia a expressão da esquerda
    auto esq = esquerda->avalia(pilha_de_tabelas);

    // Avalia a expressão da direita
    auto dir = direita->avalia(pilha_de_tabelas);

    // Se os dois operandos forem inteiros
    if (get<0>(esq) == Tipo::INTEGER && get<0>(dir) == Tipo::INTEGER) {
        int mod = get<1>(esq) % get<1>(dir);
        resultado = make_tuple(Tipo::INTEGER, mod, 0.0f);
    }
    // Se houver tipos incompatíveis
    else {
        throw runtime_error("Erro: Expressão mod com tipos incompatíveis");
    }

    return resultado;
}

void ExpressaoMod::debug_com_tab(int tab) {
    tab3(tab);
    cerr << "INICIO MOD [ " << endl;
    esquerda->debug_com_tab(tab + 1);
    tab3(tab);
    cerr << " % " << endl;
    direita->debug_com_tab(tab + 1);
    tab3(tab);
    cerr << "% ] FIM Mod" << endl;
}
