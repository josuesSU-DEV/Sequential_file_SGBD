#include<fstream>
#include<stack>
#include"Record_instructor.h"
class Over_flow_block{
    public:
        stack<Record_instructor*>m_overlow_block;
    public:
        Over_flow_block(){}
        void insert(Record_instructor *t){
            this->m_overlow_block.push(t);
        }
        void charge(){
            ofstream file;
            // file.open("E:/BBDD2_Lab/DDBB_blocks/overflow_block_instructor.db");

            file.open("overflow_block_instructor.db");
            file<<m_overlow_block.top()->return_names_columns_record_str_format()<<endl;
            while(!this->m_overlow_block.empty()){
                file<<this->m_overlow_block.top()->return_record_str_format();
                if(this->m_overlow_block.size()!=1)file<<endl;
                // if(this->m_overlow_block.size()==1)file<<this->m_overlow_block.top()->return_record_str_format();
                // else file<<this->m_overlow_block.top()->return_record_str_format()<<endl;
                // file<<this->m_overlow_block.top()->return_record_str_format()<<endl;
                this->m_overlow_block.pop();
            }
            file.close();
        }
};
