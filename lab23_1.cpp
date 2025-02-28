#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string &file,vector<string> &names,vector<int> &scores,
    vector<char> &grades){

        ifstream source("name_score.txt");
        string s;
        int score1,score2,score3;
        char name[100];
       
        char format[] = "%[^:]:%d %d %d";
        
        while(getline(source,s)){
            const char *cStr = s.c_str();
            sscanf(cStr,format,name,&score1,&score2,&score3);
            
            names.push_back(name);
            scores.push_back(score1+score2+score3);
            grades.push_back(score2grade(score1+score2+score3));
         
        }




}

void getCommand(string &command, string &key){

  
    cout << "Please input your command: " << endl;
    cin >> command;
    
      command = toUpperStr(command);
    
    if(command == "GRADE"){
        cin >> key;
    }else if(command == "NAME"){
        cin.ignore();
        getline(cin,key);

    }


}

void searchName(vector<string> &names,vector<int> &scores,vector<char> &grades,string key){

 
    int ok =0;
    
    int size = names.size();
    
    for(int i=0; i<size; i++){
        
        if(key == toUpperStr(names[i])){
            
            cout << "---------------------------------" <<"\n";
            cout << names[i] << "'s score = " << scores[i]<<"\n";
            cout << names[i] << "'s grade = " << grades[i]<<"\n";
            cout << "---------------------------------"<<"\n";
            ok++;
            
        }
        
    
        
    }
    
     if(ok==0){
            
            cout << "---------------------------------"<<"\n";
            cout <<"Cannot found."<<"\n";
            cout << "---------------------------------""\n";
           
            
        }


}

void searchGrade(vector<string> &names,vector<int> &scores,vector<char> &grades,string key){


    int size = grades.size();
    int ok=0;
    
  
    
    cout << "---------------------------------" << endl;
    
    for(int i=0; i<size; i++){
        
       if(*key.c_str()==grades[i]){
           
           cout << names[i] <<" (" << scores[i] <<")" << endl;
           ok++;
           
       }
        
        
    }
    
    if(ok==0){
        cout << "Cannot found." << endl;
    }
    
    cout << "---------------------------------" << endl;
    

}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
