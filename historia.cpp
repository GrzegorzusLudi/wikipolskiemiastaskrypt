#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string te[45] = {"A","Ą","B","C","Ć","D","E","Ę","F","G","H","I","J","K","L","Ł","M","N","Ń","O","Ó","P","R","S","Ś","T","U","W","Y","Z","Ź","Ż","_"," ","-","0","1","2","3","4","5","6","7","8","9"};

string const przeds[45][7] ={
    {" @@@ ",
     "@   @",
     "@   @",
     "@@@@@",
     "@   @",
     "@   @",
     "@   @"},

    {" @@@ ",
     "@   @",
     "@   @",
     "@@@@@",
     "@   @",
     "@   @",
     "    @"},

    {"@@@@ ",
     "@   @",
     "@   @",
     "@@@@@",
     "@   @",
     "@   @",
     "@@@@ "},

    {" @@@@",
     "@    ",
     "@    ",
     "@    ",
     "@    ",
     "@    ",
     " @@@@"},

    {"   @ ",
     "  @  ",
     " @@@@",
     "@    ",
     "@    ",
     "@    ",
     " @@@@"},

    {"@@@@ ",
     "@   @",
     "@   @",
     "@   @",
     "@   @",
     "@   @",
     "@@@@ "},

    {"@@@@@",
     "@    ",
     "@    ",
     "@@@@@",
     "@    ",
     "@    ",
     "@@@@@"},

    {"@@@@@",
     "@    ",
     "@@@@@",
     "@    ",
     "@@@@@",
     "    @"
     "    @"},

    {"@@@@@",
     "@    ",
     "@    ",
     "@@@@@",
     "@    ",
     "@    ",
     "@    "},

    {" @@@@",
     "@    ",
     "@    ",
     "@  @@",
     "@   @",
     "@   @",
     " @@@ "},

    {"@   @",
     "@   @",
     "@   @",
     "@@@@@",
     "@   @",
     "@   @",
     "@   @"},

    {" @@@ ",
     "  @  ",
     "  @  ",
     "  @  ",
     "  @  ",
     "  @  ",
     " @@@ "},

    {"@@@@@",
     "    @",
     "    @",
     "    @",
     "@   @",
     "@   @",
     " @@@ "},

    {"@   @",
     "@   @",
     "@  @ ",
     "@@@  ",
     "@  @ ",
     "@   @",
     "@   @"},

    {"@    ",
     "@    ",
     "@    ",
     "@    ",
     "@    ",
     "@    ",
     "@@@@@"},

    {"@    ",
     "@    ",
     "@  @ ",
     "@ @  ",
     "@@   ",
     "@    ",
     "@@@@@"},

    {"@@ @@",
     "@ @ @",
     "@ @ @",
     "@ @ @",
     "@   @",
     "@   @",
     "@   @"},

    {"@   @",
     "@@  @",
     "@ @ @",
     "@ @ @",
     "@ @ @",
     "@  @@",
     "@   @"},

    {"   @ ",
     "  @  ",
     "@   @",
     "@@  @",
     "@ @ @",
     "@  @@",
     "@   @"},

    {" @@@ ",
     "@   @",
     "@   @",
     "@   @",
     "@   @",
     "@   @",
     " @@@ "},

    {"   @ ",
     "  @  ",
     " @@@ ",
     "@   @",
     "@   @",
     "@   @",
     " @@@ "},

    {"@@@@ ",
     "@   @",
     "@   @",
     "@@@@ ",
     "@    ",
     "@    ",
     "@    "},

    {"@@@@ ",
     "@   @",
     "@   @",
     "@@@@ ",
     "@   @",
     "@   @",
     "@   @"},

    {" @@@ ",
     "@    ",
     "@    ",
     " @@@ ",
     "    @",
     "    @",
     " @@@ "},

    {"   @ ",
     "  @  ",
     " @@@ ",
     "@    ",
     " @@@ ",
     "    @",
     " @@@ "},

    {"@@@@@",
     "  @  ",
     "  @  ",
     "  @  ",
     "  @  ",
     "  @  ",
     "  @  "},

    {"@   @",
     "@   @",
     "@   @",
     "@   @",
     "@   @",
     "@   @",
     " @@@ "},

    {"@   @",
     "@   @",
     "@   @",
     "@ @ @",
     "@ @ @",
     "@ @ @",
     " @ @ "},

    {"@   @",
     "@   @",
     " @ @ ",
     "  @  ",
     "  @  ",
     "  @  ",
     "  @  "},

    {"@@@@@",
     "    @",
     "   @ ",
     "  @  ",
     " @   ",
     "@    ",
     "@@@@@"},

    {"   @ ",
     "  @  ",
     "@@@@@",
     "    @",
     " @@@ ",
     "@    ",
     "@@@@@"},

    {" @@@ ",
     "     ",
     "@@@@@",
     "    @",
     " @@@ ",
     "@    ",
     "@@@@@"},

    {"     ",
     "     ",
     "     ",
     "     ",
     "     ",
     "     ",
     "     "},

    {"     ",
     "     ",
     "     ",
     "     ",
     "     ",
     "     ",
     "     "},

    {"     ",
     "     ",
     "     ",
     " @@@ ",
     "     ",
     "     ",
     "     "},

    {" @@@ ",
     "@   @",
     "@   @",
     "@   @",
     "@   @",
     "@   @",
     " @@@ "},

    {"  @  ",
     "  @  ",
     "@@@  ",
     "  @  ",
     "  @  ",
     "  @  ",
     "@@@@@"},

    {" @@@ ",
     "@   @",
     "    @",
     "   @ ",
     "  @  ",
     " @   ",
     "@@@@@"},

    {" @@@ ",
     "@   @",
     "    @",
     "  @@ ",
     "    @",
     "@   @",
     " @@@ "},

    {"   @ ",
     "  @@ ",
     " @ @ ",
     "@  @ ",
     "@@@@@",
     "   @ ",
     "   @ "},

    {"@@@@@",
     "@    ",
     "@    ",
     "@@@@ ",
     "    @",
     "@   @",
     " @@@ "},

    {" @@@ ",
     "@    ",
     "@    ",
     "@@@@ ",
     "@   @",
     "@   @",
     " @@@ "},

    {"@@@@@",
     "@   @",
     "    @",
     "   @ ",
     "  @  ",
     " @   ",
     "@    "},

    {" @@@ ",
     "@   @",
     "@   @",
     " @@@ ",
     "@   @",
     "@   @",
     " @@@ "},

    {" @@@ ",
     "@   @",
     "@   @",
     " @@@@",
     "    @",
     "@   @",
     " @@@ "}};


int w =1000,h = 1000;
void drawRekt(int x,int y,int siz,int czarny,char* r[],char* g[],char* b[]){
    char re = 255*czarny;
    char ge = 0;
    char be = 0;
    if(x>siz && y>siz && x<w-siz && y<h-siz){
    for(int i = -siz;i<=siz;i++){

        for(int j = -siz;j<=siz;j++){

                r[i+x][j+y] = re;
                g[i+x][j+y]=ge;
                b[i+x][j+y]=be;
        }
    }
    }
}
void drawLetter(int x,int y,int index,int sizi,char* r[],char* g[],char* b[]){
    char re = 0;
    char ge = 0;
    char be = 0;
    int siz = 7;
    if(x>siz && y>siz && x<w-siz && y<h-siz){
    for(int i = 0;i<7;i++){

        for(int j = 0;j<przeds[index][i].length();j++){
            if(przeds[index][i].at(j)=='@'){
                for(int a = 0;a<sizi;a++)
                for(int c = 0;c<sizi;c++){
                r[j*sizi+a+x][-i*sizi+c+y] = re;
                g[j*sizi+a+x][-i*sizi+c+y]=ge;
                b[j*sizi+a+x][-i*sizi+c+y]=be;
                }
            }
        }
    }
    }
}
int distance(int x1,int y1,int x2,int y2){
    float ix = (float)(x2-x1);
    float iy = (float)(y2-y1);
    return (int)sqrt(ix*ix+iy*iy);
}
void drawLine(int x1,int y1,int x2,int y2,char* r[],char* g[],char* b[],int miast){
    int m = miast*255*5/2400;
    char re = (char)max(0,255-abs(255/2-m/2));
    char ge = (char)max(0,255-abs(255*2/2-m/2));
    char be = (char)max(0,255-abs(255*3/2-m/2));

    if(x2-x1==0 && y2-y1==0){
        r[x1][y1]=re;
        g[x1][y1]=ge;
        b[x1][y1]=be;
    } else if(abs(x2-x1)>abs(y2-y1)){
        if(x2>=x1){
            for(int i = x1;i<=x2;i++){
                int y = y1+(y2-y1)*(i-x1)/(x2-x1);
                r[i][y] = re;
                g[i][y]=ge;
                b[i][y]=be;
            }
        } else {
            for(int i = x2;i<=x1;i++){
                int y = y1+(y2-y1)*(i-x1)/(x2-x1);
                r[i][y] = re;
                g[i][y]=ge;
                b[i][y]=be;
            }
        }
    } else {

        if(y2>=y1){
            for(int i = y1;i<=y2;i++){
                int x = x1+(x2-x1)*(i-y1)/(y2-y1);
                r[x][i] = re;
                g[x][i]=ge;
                b[x][i]=be;
            }
        } else {
            for(int i = y2;i<=y1;i++){
                int x = x1+(x2-x1)*(i-y1)/(y2-y1);
                r[x][i] = re;
                g[x][i]=ge;
                b[x][i]=be;
            }
        }
    }
}
float nn = 50/60+54+1;
float ww = 7/60+14;
float ee = 9/60+24;
float ss = 49;
int qrt(int a){
    int b = 0;
    while(b*b<a){
        b++;
    }
    return b;
}
string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}
int main(){
FILE *f;
unsigned char *img = NULL;
int filesize = 54 + 3*w*h;  //w is your image width, h is image height, both int
if( img )
    free( img );
img = (unsigned char *)malloc(3*w*h);
memset(img,0,sizeof(img));
char** red;
char** green;
char** blue;
red = new char*[w];
green = new char*[w];
blue = new char*[w];
for(int i=0; i<w; i++)
{
red[i] = new char[h];
green[i] = new char[h];
blue[i] = new char[h];
    for(int j=0; j<h; j++)
{
  red[i][j] = 255;
  green[i][j] = 255;
  blue[i][j] = 255;
}
}

string* miaston = new string[10000];
float* miastox = new float[10000];
float* miastoy = new float[10000];
int* miastop = new int[10000];
int* miastoz = new int[10000];
int miast = 0;

  std::ifstream is("sortowane.txt");     // open file
  int stan = 0; // 0 - wczytywanie
  char c;
  int loni = 0;
  int lati = 0;
  string linia;
  while (getline(is,linia)){          // loop getting single characters

    string buf; // Have a buffer string
    stringstream ss(linia); // Insert the string into a stream
    vector<string> tokens; // Create vector to hold our words

        while (ss >> buf)
            tokens.push_back(buf);
            if(tokens.size()>=4){
        miaston[miast] = tokens.at(0);
        miastop[miast] = atoi(tokens.at(1).c_str());
        miastox[miast] = atof(tokens.at(2).c_str());
        miastoy[miast] = atof(tokens.at(3).c_str());
        miastoz[miast] = atoi(tokens.at(4).c_str());
        miast++;
            }
  }
  for(int rok = 600;rok<=2000;rok+=100){
    int m = 0;
    while(m<miast){
        float ix = (miastoy[m]-ww)/(ee-ww)*w;
        float iy = h-(nn-miastox[m])/(nn-ss)*h;
        int ip = 10000;
        //cout<<miastox[m]<<" "<<miastoy[m]<<" "<<miastop[m]<<endl;
        cout<<ix<<" "<<iy<<" "<<ip<<endl;
        //drawLine(ix,iy,miastox[lds],miastoy[lds],red,green,blue,miast);
        if(miastoz[m]<rok){
            string sas = miaston[m];
                cout<<sas<<endl;
            int xax = (int)ix-sas.length()*3;
            int xay = (int)iy+15;
            if(miastoz[m]>=rok-100){
            for(int i = 0;i<sas.length();i++){
                for(int j = 0;j<35;j++){
                    if(sas.length()-i>=te[j].length() && sas.compare(i,te[j].length(),te[j])==0){
                        drawLetter(xax+i*6,xay,j,1,red,green,blue);
                        if(te[j].length()>1){
                        for(int k = i;k<sas.length()-1;k++){
                            sas.at(k)=sas.at(k+1);
                        }
                        sas.resize(sas.length()-1);
                        }
                    }
                }
            }
            }
            drawRekt((int)ix,(int)iy,qrt(ip/640),0,red,green,blue);
            drawRekt((int)ix,(int)iy,qrt(ip/640)-1,1,red,green,blue);
        }
        m++;
    }

  is.close();

            string sas = "ROK "+IntToString(rok);
            int xax = 40;
            int xay = 40;
            for(int i = 0;i<sas.length();i++){
                for(int j = 0;j<45;j++){
                    if(sas.length()-i>=te[j].length() && sas.compare(i,te[j].length(),te[j])==0){
                        drawLetter(xax+i*18,xay,j,3,red,green,blue);
                        if(te[j].length()>1){
                        for(int k = i;k<sas.length()-1;k++){
                            sas.at(k)=sas.at(k+1);
                        }
                        sas.resize(sas.length()-1);
                        }
                    }
                }
            }




//drawLine(200,200,300,250,red,green,blue);
int x,y,r,g,b;
for(int i=0; i<w; i++)
{
    for(int j=0; j<h; j++)
{
    x=i; y=(h-1)-j;
    r = red[i][j]%255;
    g = green[i][j]%255;
    b = blue[i][j]%255;
    if (r > 255) r=255;
    if (g > 255) g=255;
    if (b > 255) b=255;
    img[(x+y*w)*3+2] = (unsigned char)(r);
    img[(x+y*w)*3+1] = (unsigned char)(g);
    img[(x+y*w)*3+0] = (unsigned char)(b);
}
}

unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
unsigned char bmppad[3] = {0,0,0};

bmpfileheader[ 2] = (unsigned char)(filesize    );
bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
bmpfileheader[ 4] = (unsigned char)(filesize>>16);
bmpfileheader[ 5] = (unsigned char)(filesize>>24);

bmpinfoheader[ 4] = (unsigned char)(       w    );
bmpinfoheader[ 5] = (unsigned char)(       w>> 8);
bmpinfoheader[ 6] = (unsigned char)(       w>>16);
bmpinfoheader[ 7] = (unsigned char)(       w>>24);
bmpinfoheader[ 8] = (unsigned char)(       h    );
bmpinfoheader[ 9] = (unsigned char)(       h>> 8);
bmpinfoheader[10] = (unsigned char)(       h>>16);
bmpinfoheader[11] = (unsigned char)(       h>>24);
string nazwa = "polska"+IntToString(rok)+".bmp";
f = fopen(nazwa.c_str(),"wb");
fwrite(bmpfileheader,1,14,f);
fwrite(bmpinfoheader,1,40,f);
for(int i=0; i<h; i++)
{
    fwrite(img+(w*(h-i-1)*3),3,w,f);
    fwrite(bmppad,1,(4-(w*3)%4)%4,f);
}
fclose(f);

for(int i=0; i<w; i++)
{
    for(int j=0; j<h; j++)
{
  red[i][j] = 255;
  green[i][j] = 255;
  blue[i][j] = 255;
}
}

  }
return 0;
}
