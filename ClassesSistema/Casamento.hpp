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
            Casamento(string local, time_t data, string hora) : local(local), data(data), hora(hora){}

            void set_festa(Festa *festa) {
                this->festa = festa;
            }

            void imprimeCasamento() const;

            ~Casamento() {
                delete festa;
            };
    };
}

#endif // !CASAMENTO_H
