#ifndef CASAMENTO_H
#define CASAMENTO_H

#include <string>

#include "Festa.h"

using namespace std;
namespace Sistema{
    class Festa;

    class Casamento{
        private:
            string local;
            time_t data;
            string hora;
            Festa* festa;

        public:
            Casamento(string local, time_t data, string hora);

            void setFesta(Festa *festa) {
                this->festa = festa;
            }
            
            Festa* getFesta();

            void imprimeCasamento() const;

            ~Casamento() {
                delete festa;
            }

            Parcela *getParcelasFesta();;
    };
}

#endif // !CASAMENTO_H
