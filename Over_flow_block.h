#include<fstream>
#include<list>
#include<stack>
#include"Record_instructor.h"
class Over_flow_block{
    public:
        list<Record_instructor*>m_overlow_block;
    public:
        Over_flow_block(){}

        void is_db_overflow_void(){
            // ------------------This block is to dont rewrite the  file--------------
//------------------------------------------------------------------------
            ifstream check_the_block;
            check_the_block.open("overflow_block_instructor.db");
            char first_character;
            check_the_block>>first_character;
            
            string iterator_lines;
            if(first_character!='\0'){
                
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


        void insert(Record_instructor *t){
            if(this->m_overlow_block.empty()){
                this->m_overlow_block.push_front(t);
                return;
            }
            

            
            auto it_2=this->m_overlow_block.begin();
            
            int count_index=0;
            
            for(;it_2!=this->m_overlow_block.end();it_2++){
                if(stoi((*it_2)->m_ID)==stoi(t->m_ID))return;
                if(stoi((*it_2)->m_ID)>stoi(t->m_ID)){
                    // lista_numerica.insert(it_2,int_input);
                    break;
                }
                count_index++;
            }
            it_2=this->m_overlow_block.begin();
            advance(it_2,count_index);
            this->m_overlow_block.insert(it_2,t);
        
        }
        void charge(){

            if(this->m_overlow_block.empty())return;
            ofstream file;
            // file.open("E:/BBDD2_Lab/DDBB_blocks/overflow_block_instructor.db");

            file.open("overflow_block_instructor.db");

            auto it = this->m_overlow_block.begin();
            file<<(*it)->return_names_columns_record_str_format()<<endl;


            for( ; it != this->m_overlow_block.end(); ++it )
            {
                file<<(*it)->return_record_str_format();
                if((*it)!=this->m_overlow_block.back())file<<endl;
                
            }
            file.close();
        }
};
