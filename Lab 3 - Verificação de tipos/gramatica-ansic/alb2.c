float calcula_ultimo_valor(int a, float c, float result) {
    int b = 7;
    float d = 17.6;
    a = 7;
    c = 11.9;
    if (a < b){
        a = 18;
        c = 17.6;
    }else{
        a = 38;
        c = 75.6 / d;
    }
    if (c == d){
        b = 21 + d;
        d = 29.5;
    }else{
        b = 61 + d;
        d = 59.4;
    }
    if (b < a || d < c){
        a = 18;
        c = 17.6;
    }else{
        a = 38;
        c = 75.6;
    }
    if (a < b && c < d){
        a = 45;
        c = 87.6 * d;
    }else{
        a = 48;
        c = 65.6 + d;
    }
    if (b < a){
        a = 5;
        c = 7.6 * d;
    }else{
        a = 8;
        c = 5.6 + d;
    }
    result = a * c - b / d;
    return result;
}
