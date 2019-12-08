//https://leetcode.com/problems/employee-importance/

/*
// Employee info
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int get_num_id(int id, vector<Employee*> empl){
        for (int i=0; i<empl.size(); i++)
            if(empl[i]->id == id) return i;
        return 0;
    }
    
    void count (vector<Employee*> empl, int id, int &imp){
        imp += empl[get_num_id(id,empl)]->importance;
        for (int i=0; i<empl[get_num_id(id,empl)]->subordinates.size(); i++){
            count(empl, empl[get_num_id(id,empl)]->subordinates[i], imp);
        }
    }
    
    int getImportance(vector<Employee*> empl, int id) {
        int imp = 0;
        count(empl, id, imp);
        return imp;
    }
};