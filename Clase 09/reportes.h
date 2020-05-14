#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

fecha hoy(){
    time_t tm;
    tm = time(NULL);
    struct tm *f;
    f = localtime(&tm);
    fecha reg;
    reg.dia = f->tm_mday;
    reg.mes = f->tm_mon+1;
    reg.ano = f->tm_year+1900;
    return reg;
}

void mostrar_fecha(fecha f){
    cout << f.dia << "/" << f.mes << "/" << f.ano << endl;
}

int calcular_edad(fecha fnac){
    fecha actual = hoy();
    int edad;
    edad = actual.ano - fnac.ano;

    if ((actual.mes == fnac.mes && actual.dia < fnac.dia) || actual.mes < fnac.mes){
        edad--;
    }
    return edad;
}

bool hizo_pedido(int idCliente){
    int i, cantpedidos;
    cantpedidos = cantidadpedidos();

    for(i=0; i<cantpedidos; i++){
        pedido pe = leerpedido(i);
        if (pe.id_cliente == idCliente){
            return true;
        }
    }
    return false;
}

void reporte1(){
    cls();
    mostrar_fecha(hoy());
    cout << "Clientes sin pedidos" << endl;
    cout << "---------------------" << endl << endl;
    int i, cantclientes;

    cantclientes = cantidadclientes();
    for(i=0; i<cantclientes; i++){
        cliente cli = leercliente(i);

        //if (!(hizo_pedido(cli.id))){
        if (hizo_pedido(cli.id) == false){
            mostrarcliente(cli);
            cout << "Edad: " << calcular_edad(cli.nacimiento);
            cout << endl << endl;
            /*cout << "Cliente: ";
            cout << cli.apellido << ", " << cli.nombre << endl;
            cout << "Edad   : ";
            cout << calcular_edad(cli.nacimiento) << endl;
            cout << "Domicilio: ";
            cout << cli.domicilio << endl;
            cout << "---------------------" <<endl;*/
        }
    }
    cin.ignore();
    anykey();
}

#endif // REPORTES_H_INCLUDED
