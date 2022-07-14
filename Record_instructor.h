using namespace std;
#include<iostream>
#include<assert.h>

//ID TEXT char name[20] char dept_name[20] double salary;
class Record_instructor{
    public:
        string m_ID;
        string m_name;
        string m_dept_name;
        double m_salary;
    public:
        Record_instructor(string ID,string name,string dept_name,double salary){
            this->m_ID=ID;
            this->m_name=name;
            this->m_dept_name=dept_name;
            this->m_salary=salary;
        }
        void print(){
            cout<<this->m_ID<<" "<<this->m_name<<" "<<this->m_dept_name<<" "<<this-> m_salary;
        }
        unsigned int size_record()const{
            return (sizeof(this->m_ID)-1)+(sizeof(this->m_name)-1)+(sizeof(this->m_dept_name)-1)+sizeof(m_salary);
        }
        string return_record_str_format(){
            return this->m_ID+","+this->m_name+","+this->m_dept_name+","+to_string(this-> m_salary);
        }
        string return_names_columns_record_str_format(){
            return "ID,name,dept_name,salary";
        }
};