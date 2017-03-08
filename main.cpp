#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;
// C++ implemntation of search() and traverse() methods
#include<iostream>
using namespace std;

int main()
{
   BTree t(1); // A B-Tree with minium degree 3
   //t.insert(10);
   
   
   ifstream infile;
   int i=0;
   char cNum[10] ;
   char name[10];
   char lon[10];
   char lat[10];
   //t.insert(0,false,"hi",73.0,23.0);
   cout<<"hi1"<<endl;
   infile.open ("./USAirportCodes.csv", ifstream::in);
   if (infile.is_open())
   {
       int   c=0;
       while (infile.good() && c <= 1000)
       {
           //t[c] = new Airport();
           infile.getline(name, 256, ',');
           infile.getline(lon, 256, ',');
           //t[c]->lon = atof(cNum);
           infile.getline(lat, 256, '\n');
           //t[c]->lat = atof(cNum);
           string str(name);
           //cout<<"hi2"<<endl;
           if (c>0){
              t.insert(c,false,str,atof(lon),atof(lat));
              //cout<<str<<endl;
           }
           else
              t.insert(c,true,str,atof(lon),atof(lat));
           //t.insert(convertToASCII(str));
           //if (!(c % 1000))
               //cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;

           /*
           if (!(c % 1000))
           {
               cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
               cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
           }
           */

           
           i++;
           c++;
           //cout << "hi4" << endl;
           
       }
       infile.close();
   }
      t.traverse();
      cout<<" " << endl;
   for (int i=1000; i > 0; i--){
      cout << t.getN(i) << endl;
   }
}


