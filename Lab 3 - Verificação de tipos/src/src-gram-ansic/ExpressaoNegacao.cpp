#include "ExpressaoNegacao.hpp"
#include "Expressao.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoNegacao::ExpressaoNegacao() {}

tuple<Tipo, int, float> ExpressaoNegacao::avalia(stack<Tabela*> &pilha_de_tabelas) {
    if (!direita) {
        throw runtime_error("Erro: Expressão à direita é nula.");
    }

    // Avaliando a expressão à direita
    auto dir = direita->avalia(pilha_de_tabelas);

    if (get<0>(dir) == Tipo::INTEGER) {
        int valor = get<1>(dir);  // Pega o valor inteiro
        int resultado = (valor == 0) ? 1 : 0;  // Se for 0, retorna 1; caso contrário, retorna 0
        return make_tuple(Tipo::INTEGER, resultado, 0.0f);
    }

    throw runtime_error("Erro: ExpressaoNegacao com tipo incompatível.");
}

void ExpressaoNegacao::debug_com_tab(int tab) {
    tab3(tab);
    cerr << "! [ INI Negacao" << endl;

    // Verifica se o ponteiro 'direita' não é nulo
    if (direita) {
        direita->debug_com_tab(tab + 1);
    } else {
        cerr << "Erro: Expressão à direita é nula" << endl;
    }

    tab3(tab);
    cerr << "! ] FIM Negacao" << endl;
}