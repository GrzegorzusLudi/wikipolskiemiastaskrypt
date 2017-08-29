/*
 * 
 * PRZYKŁADOWY SKRYPT BASHOWY DO URUCHOMIENIA
m='Szklarska_Poręba';lynx -cookies -dump pl.wikipedia.org/wiki/$m | grep -A 3 -E 'Populacja|Na mapach:|Liczba ludności|Data założenia'

*/

//SKRYPT ZAMIENIAJĄCY DANE Z PROGRAMU LYNX NA REKORDY

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
bool numsp(char a){
    if((a>='0' && a<='9') || a==' ')
        return true;
    else
        return false;
}
string intToStr(int n)
{
     string tmp;
     if(n < 0) {
      tmp = "-";
      n = -n;
     }
     if(n > 9)
      tmp += intToStr(n / 10);
     tmp += n % 10 + 48;
     return tmp;
}
string wieki[] = {"I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII","XIII","XIV","XV","XVI","XVII","XVIII","XIX","XX","XXI"};
int main(){
    char c;
    string line = "";
    int lin = 0;
    int lez = -1;
    string latilongi = "";
    string nazwa = "";
    string populacja = "100";
    string datazalozenia = "-";
    while((c=getchar())!=EOF){
        if(c=='\n'){
            string now = "";
            bool mis = false;
            bool bra = false;
            for(int i = 0;i<line.length();i++){
                if(line.at(i)=='[' && (i>-line.length()-1 || line.at(i+1)!='e'))
                    bra = true;
                if(line.at(i)!=' ' || mis){
                    if(!bra)
                        now+=line.at(i);
                    mis = true;
                }
                if(line.at(i)==']')
                    bra = false;
            }
            if(lez<0){
                if(now.compare(0,10,"Na mapach:")==0){
                    mis = false;
                    for(int i = 1;i<now.length();i++){
                        if(now.at(i)=='/' || mis){
                            if(mis)
                                latilongi+=now.at(i);
                            mis = true;
                        }
                    }
                    lez = 3;
                } else if(now.compare(0,9,"Populacja")==0){
                    lez = 9;
                } else if(now.length()>=17 && now.compare(3,17,"]Liczba ludności")==0){
                    populacja = "";
                    bool wnaw = false;
                    for(int i = now.length()-1;i>0 && (numsp(now.at(i)) || now.at(i)=='[' || now.at(i)==']' || now.at(i)=='^');i--){
                        if(now.at(i)==']')
                            wnaw = true;
                        if(now.at(i)=='[')
                            wnaw = false;
                        if(now.at(i)>='0'&&now.at(i)<='9' && !wnaw)
                            populacja=now.at(i)+populacja;
                    }
                } else if(now.length()>=16 && now.compare(0,16,"Data założenia")==0){
                    
                    lez = 16;
                } else if(datazalozenia=="-") {
                    
                    string buf; 
                    stringstream ss(now);

                    vector<string> tokens;
                    
                    while (ss >> buf)
                        tokens.push_back(buf);
                    string spraw[] = {"wzmianka","wzmianki","Wzmiankowany","Wzmiankowane","Wzmiankowana","wzmiankowane","wzmiankowany","wzmiankowana","Założony","Założona","Założone","założony","założona","założone","Historia"};
                    for(int i = 0;i<sizeof(spraw)/sizeof(*spraw);i++)
                    if(find(tokens.begin(), tokens.end(), spraw[i]) != tokens.end()) {
                        lez = 25;
                    }
                }
            } else if(lez>=0){
                if(lez==2){
                    for(int i = 0;i<now.length();i++){
                        if(now.at(i)==' '){
                            nazwa+='_';
                        } else {
                            nazwa+=now.at(i);
                        }
                    }
                    lez = 0;
                }
                if(lez==7){
                    populacja = "";
                    for(int i = 0;i<now.length() && numsp(now.at(i));i++){
                        if(now.at(i)>='0'&&now.at(i)<='9')
                            populacja+=now.at(i);
                    }
                    lez = -2;
                }
                lez--;
                
            }
            if(lez>=19 && lez<=25){
                
                    string buf; 
                    stringstream ss(now);

                    vector<string> tokens;
                    
                    while (ss >> buf)
                        tokens.push_back(buf);
                    bool found = false;
                    for(int i = 0;!found && i<tokens.size();i++){
                        string sss = tokens.at(i);
                        string sas = "";
                        if(sss.length()>=3){
                            bool numer = true;
                            int j = 0;
                            while(j<4 && j<sss.length()){
                                if(sss.at(j)<'0' || sss.at(j)>'9')
                                    numer = false;
                                else
                                    sas+=sss.at(j);
                                j++;
                            }
                            if(numer && j>=3){
                                datazalozenia = sas;
                                found = true;
                                lez = -1;
                            }
                            
                        }
                    }
                    if(!found)
                    for(int i = 0;!found && i<tokens.size();i++){
                        string sss = tokens.at(i);
                        for(int j = 0;j<sizeof(wieki)/sizeof(*wieki);j++){
                            if(sss==wieki[j]){
                                datazalozenia = intToStr(j*100+1);
                                found = true;
                                lez = -1;
                            }
                        }
                        
                    }
            }
                if(lez==16){
                    int zaloz = 0;
                    
                    string buf; 
                    stringstream ss(now);

                    vector<string> tokens;
                    
                    while (ss >> buf)
                        tokens.push_back(buf);
                    bool found = false;
                    for(int i = 0;!found && i<tokens.size();i++){
                        string sss = tokens.at(i);
                        for(int j = 0;j<sizeof(wieki)/sizeof(*wieki);j++){
                            if(sss==wieki[j]){
                                datazalozenia = intToStr(j*100+1);
                                found = true;
                            }
                        }
                        if(sss.length()>=3 && sss.length()<=4){
                            bool numer = true;
                            for(int j = 0;j<sss.length();j++){
                                if(sss.at(j)<'0' || sss.at(j)>'9')
                                    numer = false;
                            }
                            if(numer){
                                datazalozenia = sss;
                                found = true;
                            }
                        }
                    }
                    lez = 0;
                }
            lin++;
            //cout<<"Lez "<<lez<<": "<<now<<endl;
            line = "";
        } else {
            line += c;
        }
    }
    if(populacja=="")
        populacja = "0";
    if(nazwa!="" && datazalozenia!="-")
            cout<<nazwa<<" "<<populacja<<" "<<latilongi<<" "<<datazalozenia<<endl;
    return 0;
}