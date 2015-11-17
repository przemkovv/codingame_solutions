#include <iostream>
using namespace std;string N="N",S="S",W="W",E="E",o;main(){int k,j,m,n,e;cin>>k>>j>>m>>n;int X=k-m,Y=j-n;while(1){cin>>e;o="";if(Y<0){o+=N;Y++;}else if(Y){o+=S;Y--;}if(X<0){o+=W;X--;}else if(X){o+=E;X++;}cout<<o<<endl;}}
