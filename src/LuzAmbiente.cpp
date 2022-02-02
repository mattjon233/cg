#include "LuzAmbiente.h"

Cor LuzAmbiente::luminancia(PontoColisao& ptcol) const {
    return _intensidade * ptcol.cor;
}