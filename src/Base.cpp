#include "Base.h"

string data_atual() {
    struct tm *data;  
    time_t segundos;

    time(&segundos);     
    data = localtime(&segundos); 

    return to_string(data->tm_mday)+"-"+
           to_string(data->tm_mon+1)+"-"+
           to_string(data->tm_year+1900)+"_"+
           to_string(data->tm_hour)+"h"+
           to_string(data->tm_min)+"m"+
           to_string(data->tm_sec)+"s";
}

float graus_em_radianos(float grau) {
    return grau * PI / 180.0;
}

float min(float a, float b) {
    if (a < b)
        return a;
    return b;
}

float max(float a, float b) {
    if (a > b)
        return a;
    return b;
}

bool pertence_intervalo(float x, float a, float b) {
    return (x >= a && x <= b);
}