#include <iostream>
#include<cctype>
#include<vector>
using namespace std;

void reversestr(string &str){
    // reverse a string
    int n=str.length()-1;
    int i=0;
    while(i<n){
        char temp=str[i];
        str[i]=str[n];
        str[n]=temp;
        n--;
        i++;
    }
    cout<< str << endl;
}

bool palindrome(const string &str){
    //palindrome
    int l=str.length()-1;
    int r=0;
    while(r<l){
        if(tolower(str[r])!=tolower(str[l])){
            return false;
        }
        r++;
        l--;
    }
    return true;
}

void countfre(const string &str){
    vector<bool> visited(str.length(),false);
    int l=0;
    for(l=0;l<str.length();l++){
        if(!visited[l]){
            int fre=1;
            for(int j=l+1;j<str.length();j++){
                if(str[l]==str[j]){
                    fre++;
                    visited[j]=true;
                }
            }
            visited[l]=true;
            cout<<str[l]<<'='<<fre<<endl;
        }
    }
}

//optimization(hashing)
void countfre1(const string &str){
    int fre[256]={0};
    for(char c: str){
        fre[tolower(c)]++;
    }
    for(char c: str){
        if(fre[tolower(c)]!=0){
            cout<<c<<"="<<fre[tolower(c)]<<endl;
            fre[tolower(c)]=0;
        }
    }

}

void anagraml(){
    string str1="silent";
    string str2="listen";

    if(str1.length() != str2.length()){
        cout << "not";
        return;
    }

    int fre[256] = {0};

    for(int i = 0; i < str1.length(); i++){
        fre[str1[i]]++;
        fre[str2[i]]--;
    }

    for(int i = 0; i < 256; i++){
        if(fre[i] != 0){
            cout << "not";
            return;
        }
    }

    cout << "anagram" << endl;
}



int main(){
    string str;
    str="Malayalam";

    bool ans=palindrome(str);
    if(ans){
        cout<<"\npalindrome\n";
    }
    else{
        cout<<"\nnot";
    }

    countfre(str);

    reversestr(str);
    
    anagraml();
    
}