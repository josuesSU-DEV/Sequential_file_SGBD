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
        Record_instructor(string tuple_record){
            this->m_ID="";
            int i=0;
            for (;i<tuple_record.size();i++){
                if(tuple_record[i]==','){
                    i++;
                    break;
                }
                this->m_ID+=tuple_record[i];
            }
            this->m_name="";
            for (;i<tuple_record.size();i++){
                if(tuple_record[i]==','){
                    i++;
                    break;
                }
                this->m_name+=tuple_record[i];
            }
            this->m_dept_name="";
            for (;i<tuple_record.size();i++){
                if(tuple_record[i]==','){
                    i++;
                    break;
                }
                this->m_dept_name+=tuple_record[i];
            }
            this->m_salary=0;
            string salary_str="";
            for (;i<tuple_record.size();i++){
                
                salary_str+=tuple_record[i];
            }
            this->m_salary=stod(salary_str);
        }

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
