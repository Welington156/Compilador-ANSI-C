#include "Expressao.hpp"
#include "ExpressaoFloat.hpp"
#include "ExpressaoVariavel.hpp"
#include "ExpressaoNumero.hpp"
#include "ExpressaoDivisao.hpp"
#include "ExpressaoMod.hpp"
#include "ExpressaoMultiplicacao.hpp"
#include "ExpressaoSoma.hpp"
#include "ExpressaoSubtracao.hpp"
#include "ExpressaoIgual.hpp"
#include "ExpressaoMenor.hpp"
#include "ExpressaoAnd.hpp"
#include "ExpressaoOr.hpp"
#include "ExpressaoNegacao.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

Expressao* Expressao::extrai_expressao(No_arv_parse* no) {
  
  switch(no->regra) {
    case 40: case 42: case 44: case 47: case 52: case 55: case 59: case 61:
      return Expressao::extrai_expressao(no->filhos[0]);

    case 53:{
        //F -> F PLUS G
        //cout << "Soma" << endl;
      ExpressaoSoma* res23 = new ExpressaoSoma();
      res23->esquerda = extrai_expressao(no->filhos[0]);
      res23->direita = extrai_expressao(no->filhos[2]);
      return res23;
    }
    case 54: { // F -> F MINUS G
      ExpressaoSubtracao* res24 = new ExpressaoSubtracao();
      res24->esquerda = extrai_expressao(no->filhos[0]);
      res24->direita = extrai_expressao(no->filhos[2]);
      return res24;
    }
    case 56: { //G -> G MULT H
      ExpressaoMultiplicacao* res27 = new ExpressaoMultiplicacao();
      res27->esquerda = extrai_expressao(no->filhos[0]);
      res27->direita = extrai_expressao(no->filhos[2]);
      return res27;
    }
    case 57: {//G -> G DIV H
      ExpressaoDivisao* res28 = new ExpressaoDivisao();
      res28->esquerda = extrai_expressao(no->filhos[0]);
      res28->direita = extrai_expressao(no->filhos[2]);
      return res28;
    }
    case 58: { //G -> G MOD H
      ExpressaoMod* res30 = new ExpressaoMod();
      res30->esquerda = extrai_expressao(no->filhos[0]);
      res30->direita = extrai_expressao(no->filhos[2]);
      return res30;
    }
    case 69: { //I -> FLOAT_CONSTANT
      ExpressaoFloat* res34 = new ExpressaoFloat();
      res34->numero = FLOAT::extrai_FLOAT(no->filhos[0]);
      return res34;
    }
    case 65: {//I -> ID
      ExpressaoVariavel* res35 = new ExpressaoVariavel();
      res35->nome = ID::extrai_ID(no->filhos[0]);
      return res35;
    }
    case 66: case 67:{ //I -> INT_DECIMAL // I -> INT_OCTAL
      ExpressaoNumero* res = new ExpressaoNumero();
      res->numero = INTEGER::extrai_INTEGER(no->filhos[0]);
      //cout << "Numero " << endl;
      return res;
    }
    case 45:{ //D -> D EQ E
      ExpressaoIgual* res = new ExpressaoIgual();
      res->esquerda = extrai_expressao(no->filhos[0]);
      res->direita = extrai_expressao(no->filhos[2]);
      //cout<<"entrou aqui"<<endl;
      return res;
    }
    case 48:{//E -> E LESS_THAN F
      ExpressaoMenor* res = new ExpressaoMenor();
      res->esquerda = extrai_expressao(no->filhos[0]);
      res->direita = extrai_expressao(no->filhos[2]);
      return res;
    }

    case 43 :{//C -> C LOGICAL_AND D
      ExpressaoAnd* res = new ExpressaoAnd();
      res->esquerda = extrai_expressao(no->filhos[0]);
      res->direita = extrai_expressao(no->filhos[2]);
      return res;
    }
    case 41:{//B -> B LOGICAL_OR C
      ExpressaoOr* res = new ExpressaoOr();
      res->esquerda = extrai_expressao(no->filhos[0]);
      res->direita = extrai_expressao(no->filhos[2]);
      return res;
    }
    case 60:{//H -> NOT H
      ExpressaoNegacao* res = new ExpressaoNegacao();
      res->direita = extrai_expressao(no->filhos[1]);
      return res;
    }

    default: {
      return NULL;
    }
  }
}

tuple<Tipo, int, float> Expressao::avalia(stack < Tabela*> & pilha_de_tabelas){
  return make_tuple(Tipo::INTEGER,0,0);
}

void Expressao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "Expressao generica" << endl;
}