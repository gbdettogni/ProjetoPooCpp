#include "Casamento.hpp"

#include "Festa.h"

namespace Sistema{
    void Casamento::imprimeCasamento() const {
      if(festa != NULL){
          festa->imprimeFesta();
      }
    }
}
