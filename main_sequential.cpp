#include<iostream>
#include"Seq_file.h"
using namespace std;

int main(){
    
    // Inicializacion de la estructura
    //Sequential file  
    // con el objeto Seq(PARAMETRO)
    // PARAMETRO:Cantidad de bytes que tendra nuestro file
    Seq_file Seq(101*6-1);

    // -------------------------------------------------------
    //------------ Creacion de nuestros registros-------------

    //Modelo Record_instrutor(ID TEXT char name[20] char dept_name[20] double salary;) 
    
    Record_instructor t("12345","Josue","C.Science",40000);
    Record_instructor t1("67890","Roberto","Ing.Electrica",5000);
    Record_instructor t2("7456","Javier","Ing.Civil",8000);
    Record_instructor t3("21133","Pedro","Matematica",29900);
    Record_instructor t4("76133","Jesus","Comunicaciones",8000);
    Record_instructor t5("76698040","Sergio","Literatura",4000);
    cout<<"Bytes per record: "<<t5.size_record()<<endl;
    
    // ----------------------------------------------------------------------
    //--------Insercion de nuestros registros en nuestra estructura----------
    
    Seq.insert(t);
    Seq.insert(t1);
    Seq.insert(t2);
    Seq.insert(t3);
    Seq.insert(t4);
    Seq.insert(t5);
    
    // -------------------------------------------------------
    // Metodo print nos enviara los mensajes de error y exito en las inserciones
    Seq.print();

    // -------------------------------------------------------
    // Metodo charge_to_disk carga nuestros datos del sequential al file
    Seq.charge_to_disk();

    return 0;
}