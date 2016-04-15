#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

void printmap(map<string,string>&m)
{
    map<string, string>::iterator i;
    for(i = m.begin();i!=m.end();i++)
    {
        cout<<i->first<<"->"<<i->second<<endl;
    }
}

void printitinerary()
{
    map<string, string> m;
    m["Chennai"] = "Banglore";
    m["Bombay"] = "Delhi";
    m["Goa"] = "Chennai";
    m["Delhi"] = "Goa";

    map<string, string>::iterator i;
    map<string, string> re;
    for(i = m.begin();i!=m.end();i++)
    {
        re[(i->second)] = (i->first);
    }
    string start = "";
    printmap(m);
    cout<<endl;
    printmap(re);
    for(i = m.begin();i!=m.end();i++)
    {
        if(re[i->first]=="")
        {
            start = i->first;
        }
    }

    cout<<"Starting point is "<<start<<endl;
    cout<<endl;
    while(m[start]!="")
    {
        cout<<start<<"->"<<m[start]<<endl;
        start = m[start];
    }

}


void findItinary(char *str1[],char* str2[],int len){
    //Create map of two strings
    map<string,string> mapHash;
    for(int i=0;i<len;i++){
        mapHash[str1[i]]=str2[i];
    }

    //ReverseMap
    map<string,string> revmapHash;
    map<string,string>::iterator it1;
    for(it1=mapHash.begin();it1!=mapHash.end();it1++){
        revmapHash[it1->second]=it1->first;
    }

    for(it1=mapHash.begin();it1!=mapHash.end();it1++){
        cout<<it1->first<<"->"<<it1->second<<endl;
    }

    cout<<endl;
    for(it1=revmapHash.begin();it1!=revmapHash.end();it1++){
        cout<<it1->first<<"->"<<it1->second<<endl;
    }

//    cout<<"Map contents are:"<<endl;
//    for(it1=mapHash.begin();it1!=mapHash.end();it1++){
//            cout<<mapHash[it1->first]<<" "<<mapHash[it1->second]<<endl;
//        }
//    cout<<"----------------------------------------------------"<<endl;
//    cout<<"Reverse map contenets"<<endl;
//    for(it1=revmapHash.begin();it1!=revmapHash.end();it1++){
//            cout<<revmapHash[it1->second]<<"   "<<revmapHash[it1->first]<<endl;
//        }
//    //Compare map and reverse

//    for(it1=mapHash.begin();it1!=mapHash.end();it1++){
//        if(revmapHash[it1->second]=="NULL"){
//            cout<<endl<<revmapHash[it1->first]<<"is the source"<<endl;
//        }
//    }
}

int main(){
     char *str1[]={"Chennai","Bombay","Goa","Delhi"};
     char *str2[]={"Banglore","Delhi","Chennai","Goa"};
    int len=sizeof(str1)/sizeof(str1[0]);
    findItinary(str1,str2,len);
}
