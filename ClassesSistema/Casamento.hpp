#ifndef CASAMENTO_H
#define CASAMENTO_H

#include <string>

using namespace std;
namespace Sistema{
    class Casamento{
        private:
            string local;
            time_t data;
            string hora;

        public:
            Casamento(string local, time_t data, string hora) : local(local), data(data), hora(hora){}
    };
}

#endif // !CASAMENTO_H
