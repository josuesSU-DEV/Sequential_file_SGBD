#include<iostream>
// #include<fstream>
#include"Over_flow_block.h"
#include<list>

class Seq_file{
    private:
        list<Record_instructor*>m_seq_file;
        Over_flow_block collector;
        unsigned int m_capicity_block;
    public:
        // Seq_file(){
            
        //     // this->m_capicity_block=capicity_block;
        // }
        Seq_file(unsigned int capicity_block){
            
            this->m_capicity_block=capicity_block;
        }
        // bool is_db_void(){

        // }
        void insert(int position,Record_instructor* t){
            auto it = this->m_seq_file.begin();
            // ++it;
            // advance(it,pos);
            if(this->m_seq_file.size()*(*it)->size_record()+(*it)->size_record()<=this->m_capicity_block){
                // this->m_seq_file.insert(it,*t);
                if(position>=this->m_seq_file.size()){
                    this->m_seq_file.push_back(t);
                    return;
                }
                // else if(position<=0){

                // }
                advance(it,position);
                this->m_seq_file.insert(it,t);
            }
            else{
                cout<<"Ther's no space in the block\nInserted in the overflow block"<<endl;
                
                this->collector.insert(t);
                
            }
        }
        void insert(Record_instructor *t){
            if(this->m_seq_file.empty()){
                this->m_seq_file.push_front(t);
                return;
            }
            

            
            auto it_2=this->m_seq_file.begin();
            if(this->m_seq_file.size()*(*it_2)->size_record()+(*it_2)->size_record()<=this->m_capicity_block){
                int count_index=0;
                for(;it_2!=this->m_seq_file.end();it_2++){
                    if(stoi((*it_2)->m_ID)==stoi(t->m_ID))return;
                    if(stoi((*it_2)->m_ID)>stoi(t->m_ID)){
                        // lista_numerica.insert(it_2,int_input);
                        break;
                    }
                    count_index++;
                }
                it_2=this->m_seq_file.begin();
                advance(it_2,count_index);
                this->m_seq_file.insert(it_2,t);
            }
            else{
                cout<<"There isn't space in the block\nInserted in the overflow block"<<endl;
                
                this->collector.insert(t);
                
            }
        }
        
        void print(){
            for( auto it = this->m_seq_file.begin(); it != this->m_seq_file.end(); ++it )
            {
                (*it)->print();
                cout<<endl;
            }
        }
        void charge_to_disk(){
            
            
            
            
            
            if(this->m_seq_file.empty())return;


            // ifstream check_the_block;
            // check_the_block.open("instructor.db");
            // char first_character;
            // check_the_block>>first_character;
            
            // string first_line;
            // if(first_character!='\0'){
                
            //     // El size del block:
            //     getline(file,first_line);
            //     first_line=first_character+first_line;




            // }
            // check_the_block.close();
            
            
            
            ofstream file;
            // file.open("E:/BBDD2_Lab/DDBB_blocks/instructor.db");

            file.open("instructor.db");
            
            
            
            
            
            
            file<<this->m_capicity_block<<endl;
            
            auto it = this->m_seq_file.begin();
            file<<(*it)->return_names_columns_record_str_format()<<endl;
            
            for( ; it != this->m_seq_file.end(); ++it )
            {
                file<<(*it)->return_record_str_format();
                if((*it)!=this->m_seq_file.back())file<<endl;
                
            }
            file.close();
            if(!this->collector.m_overlow_block.empty())this->collector.charge();
            
            
        }
        
};
