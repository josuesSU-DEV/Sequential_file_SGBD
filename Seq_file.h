#include<iostream>
// #include<fstream>
#include"Over_flow_block.h"
// #include<list>

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
            this->collector.is_db_overflow_void();
            



        }
        
        void is_db_void(){
            // ------------------This block is to dont rewrite the  file--------------
//------------------------------------------------------------------------
            ifstream check_the_block;
            check_the_block.open("instructor.db");
            char first_character;
            check_the_block>>first_character;
            
            string iterator_lines;
            if(first_character!='\0'){
                
                // El size del block:
                getline(check_the_block,iterator_lines);
                iterator_lines=first_character+iterator_lines;

                this->m_capicity_block=stoi(iterator_lines);

                //This getline is to ignore the line
                // of columns_name:  
                // ID TEXT char name[20] char dept_name[20] double salary;
                getline(check_the_block, iterator_lines);

                // ------------------------------
                while(!check_the_block.eof()){
                    getline(check_the_block,iterator_lines);
                    this->insert(new Record_instructor(iterator_lines));
                }
                

                check_the_block.close();
            }
            else {

                check_the_block.close();
                return;
            }
            
            
//------------------------------------------------------------------------            
//------------------------------------------------------------------------ 
        }
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
                // cout<<"There isn't space in the block\nInserted in the overflow block"<<endl;
                
                this->collector.insert(t);
                
            }
        }

        void print_Table(){
            auto it=this->m_seq_file.begin();
            
            cout<<(*it)->return_names_columns_record_str_format()<<endl;
            for(;it!=this->m_seq_file.end();it++){
                cout<<"(";
                (*it)->print();
                cout<<")"<<endl;
    
            }
        }

        void get_tuple_from_DDBB(int index){
            if(index<0){
                cout<<"Invalid Index\n";
                return;
            }
            if(this->m_seq_file.empty()){
                cout<<"Table is void\n";
                return;
            }
            int count=0;
            auto it=this->m_seq_file.begin();
            for(;it!=this->m_seq_file.end();it++){
                
                if(count==index)break;
                count++;
            }
            cout<<"(";
            (*it)->print();
            cout<<")\n";
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
            if(!this->collector.m_overlow_block.empty()){
                this->collector.charge();

            }
            
            
        }
        
};
