#include<iostream>
#include"Seq_file.h"
using namespace std;

int main(){
    
    // Inicializacion de la estructura
    //Sequential file  
    // con el objeto Seq(PARAMETRO)
    // PARAMETRO:Cantidad de bytes que tendra nuestro file
    // Seq_file Seq(101*6-1);
    Seq_file Seq(101*6);
    Seq.is_db_void();
    // -------------------------------------------------------
    //------------ Creacion de nuestros registros-------------

    //Modelo Record_instrutor(ID TEXT char name[20] char dept_name[20] double salary;) 
    
    Record_instructor *t=new Record_instructor("12345","Josue","C.Science",40000);
    Record_instructor *t1=new Record_instructor("67890","Roberto","Ing.Electrica",5000);
    Record_instructor *t2=new Record_instructor("7456","Javier","Ing.Civil",8000);
    Record_instructor *t3=new Record_instructor("31133","Pedro","Matematica",29900);
    Record_instructor *t4=new Record_instructor("76133","Jesus","Comunicaciones",8000);
    Record_instructor *t5=new Record_instructor("76698040","Sergio","Literatura",4000);
    Record_instructor *t6=new Record_instructor("7777777","Pedro","Computer",800000);
     Record_instructor *t7=new Record_instructor("987654321","Julian","Alvarez",600);
    // cout<<"Bytes per record: "<<t5->size_record()<<endl;
    
    // ----------------------------------------------------------------------
    //--------Insercion de nuestros registros en nuestra estructura----------
    
    Seq.insert(t);
    Seq.insert(t1);
    Seq.insert(t2);
    Seq.insert(t3);
    Seq.insert(t4);
    Seq.insert(t5);
    Seq.insert(t6);
    Seq.insert(t7);
    // -------------------------------------------------------
    // Metodo print nos enviara los mensajes de error y exito en las inserciones
    // Seq.print();

    // -------------------------------------------------------
    // Metodo charge_to_disk carga nuestros datos del sequential al file
    Seq.charge_to_disk();
    cout<<"----------------Welcom to your DATABASE-----------------"<<endl;
    int opciones=0;
    while(opciones!=3){
        cout<<"1.Imprimir tabla completa "<<endl;
        cout<<"2.Obtener registro por indice "<<endl;
        cout<<"3.Salir "<<endl;
        cout<<"->Ingrese el numero de la opcion: ";
        cin>>opciones;
        cout<<"-----------------------------------------------------------\n";
        switch (opciones)
        {
        case 1:
            Seq.print_Table();
            cout<<"-----------------------------------------------------------\n";
            break;
        case 2:
            Seq.print_Table();
            int index;
            cout<<"->Ingrese el indice: ";
            cin>>index;
            Seq.get_tuple_from_DDBB(index);
            cout<<"-----------------------------------------------------------\n";
            break;
        case 3:
            
            break;
        default:
            cout<<"Opcion incorrecta\n";
            cout<<"-----------------------------------------------------------\n";
            break;
        }
    }
    

    
    
    return 0;
}
