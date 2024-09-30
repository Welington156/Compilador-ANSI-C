#include "ExpressaoFloat.hpp"
#include <iostream>
#include <iomanip>
#include "../debug-util.hpp"

using namespace std;

ExpressaoFloat::ExpressaoFloat() {}

tuple<Tipo, int, float> ExpressaoFloat::avalia(stack<Tabela*> &stack_symbol_table) {
    if (numero == nullptr) {
        throw runtime_error("Erro: ExpressaoFloat com ponteiro nulo.");
    }
    return make_tuple(Tipo::FLOAT, 0, numero->valor);
}

void ExpressaoFloat::debug_com_tab(int tab) {
    cerr << std::fixed << std::setprecision(2) << numero->valor << " [FLOAT]" << endl;
}
