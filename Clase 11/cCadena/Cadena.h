#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

class Cadena{
    private:
        char *str;

    public:
        Cadena(int);
        ~Cadena();
        void setCadena(char *);
        char *getCadena();

};

#endif // CADENA_H_INCLUDED
