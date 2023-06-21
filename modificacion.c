





void modificarCliente(){
    stCliente cliente;
    char dni[12];
    int flag = 0;
    char option = 's';
    char opcion = 0;
    char opcion2 = 's';
    int limpiar = 0;

    FILE* archi=fopen(ARCHI_CLIENTE,"rb");
    if(archi){

        do{
        system("cls");
        printf("\n Ingrese el DNI del cliente a modificar: ");
        fflush(stdin);
        gets(dni);
        flag=buscarDni(archi,dni);
        if(flag==0){
            printf("\n El DNI no se encuentra registrado...");
        }else{
            fseek(archi,0,SEEK_SET);
            while(flag==1 && fread(&cliente,sizeof(stCliente),1,archi)>0){
                if(strcmp(dni,cliente.dni)==0){
                        mostrarCliente(cliente);
                    do{
                        if(limpiar == 1){system("cls");}
                        printf("\n 1 = Modificar el nombre");
                        printf("\n 2 = Modificar el apellido");
                        printf("\n 3 = Modificar el dni");
                        printf("\n 4 = Modificar el email");
                        printf("\n 5 = Modificar el domicilio");
                        printf("\n 6 = Modificar el telefono\n");
                        printf("\n Ingrese una opcion: ");
                        fflush(stdin);
                        opcion = getch();
                        switch(opcion){
                            case 49:
                               printf("\n Ingrese un nuevo nombre: ");
                               scanf("%s",&cliente.nombre);
                               int pos=ftell(archi)-sizeof(stCliente);
                               fseek(archi,pos,SEEK_SET);
                               fwrite(&cliente, sizeof(stCliente), 1, archi);
                               printf("\nSe modifico el nombre.\n");
                               printf("\n Nombre:..............: %s", cliente.nombre);
                                break;
                            case 50:
                                printf("\n Ingrese un nuevo apellido: ");
                               scanf("%s",&cliente.apellido);
                               int pos2=ftell(archi)-sizeof(stCliente);
                               fseek(archi,pos2,SEEK_SET);
                               fwrite(&cliente, sizeof(stCliente), 1, archi);
                               printf(" Se modifico el apellido.\n");
                               printf("\n Apellido:..............: %s", cliente.apellido);
                                break;
                            case 51:
                               printf("\n Ingrese un nuevo dni: ");
                               scanf("%s",&cliente.dni);
                               int pos3=ftell(archi)-sizeof(stCliente);
                               fseek(archi,pos3,SEEK_SET);
                               fwrite(&cliente, sizeof(stCliente), 1, archi);
                               printf(" Se modifico el dni.\n");
                               printf("\n Dni:..............: %s", cliente.dni);
                               mostrarCliente(cliente);
                                break;

                            case 52:
                               printf("\n Ingrese un nuevo email: ");
                               scanf("%s",&cliente.email);
                               int pos4=ftell(archi)-sizeof(stCliente);
                               fseek(archi,pos4,SEEK_SET);
                               fwrite(&cliente, sizeof(stCliente), 1, archi);
                               printf(" Se modifico el email.\n");
                               printf("\n Email:..............: %s", cliente.email);
                               mostrarCliente(cliente);
                                break;

                            case 53:
                               printf("\n Ingrese un nuevo domicilio: ");
                               scanf("%s",&cliente.domicilio);
                               int pos5=ftell(archi)-sizeof(stCliente);
                               fseek(archi,pos5,SEEK_SET);
                               fwrite(&cliente, sizeof(stCliente), 1, archi);
                               printf(" Se modifico el domicilio.\n");
                               printf("\n Domicilio:..............: %s", cliente.domicilio);
                               mostrarCliente(cliente);
                                break;

                            case 54:
                               printf("\n Ingrese un nuevo telefono: ");
                               scanf("%s",&cliente.telefono);
                               int pos6=ftell(archi)-sizeof(stCliente);
                               fseek(archi,pos6,SEEK_SET);
                               fwrite(&cliente, sizeof(stCliente), 1, archi);
                               printf(" Se modifico el telefono.\n");
                               printf("\n Telefono:..............: %s", cliente.telefono);
                               mostrarCliente(cliente);
                            }
                            printf("\n Desea realizar otra modificacion? s/n: ");
                            opcion2 = getch();
                            limpiar = 1;
                    }while(opcion2 == 's');

                    flag=0;
                }
            }
        }
        printf("\n Desea buscar otro dni? s/n: ");
        fflush(stdin);
        option = getch();
        } while(option == 's');

        fclose(archi);
    }
}
