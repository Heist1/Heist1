#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <list>
#include <cstring>
#include "Grafo.h"
int camminoMinimale(Grafo g,int i, int j);
using namespace std;
int main()
{
	int n,m;
	string in;
	getline(cin,in);
	char* token=strtok(&in[0]," ");
	n=atoi(token);
	token=strtok(NULL," ");
	m=atoi(token);

	Grafo g(n*m);
	vector<bool> vertici_corpi(g.n()+1,false);
	bool matrice_mappa[n][m]={false};	
	char letto;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>letto;
			if(letto == '#'){
				vertici_corpi[(i*m)+j+1]=true;
				matrice_mappa[i][j]=true;
			}
			int nodo_esaminato=(i*m)+j+1;		
			for(int s=i-1;s<i+2;s++)
				for(int t=j-1;t<j+2;t++)
					if(s>=0 && s<n && t>=0 && t<m && (s!=i  || j!=t))				
					{
						g(nodo_esaminato,(s*m)+t+1,true);
						g((s*m)+t+1,nodo_esaminato,true);
					}
		}
	int nodoMax;
	int valoreMax=INT_MIN;
	for(int i=1;i<=g.n();i++)
		if(!vertici_corpi[i])
		{
			int minimo_corrente=INT_MAX;
			for(int j=1;j<=g.n();j++)
				if(vertici_corpi[j])
				{
					int tmp=camminoMinimale(g,i,j);
					if(tmp<minimo_corrente)
						minimo_corrente=tmp;
				}
			if(minimo_corrente>valoreMax){
				valoreMax=minimo_corrente;
				nodoMax=i;
			}
		}
	cout<<(nodoMax-1)/m<<" "<<(nodoMax-1)%m;		
					
}
int camminoMinimale(Grafo G, int start, int end)
{
	int costo=0;
	list<int> coda;
	coda.push_back(start);
	vector<int> padri(G.n()+1, -1);
	vector<bool> visitati(G.n()+1, false);
	visitati[start] = true;

	bool found = false;

	while(!coda.empty() && !found)
	{
		int current = coda.front();
		coda.pop_front();
		for(int i = 1; i<= G.n() && !found; i++)
			if(G(current, i) && i != current && !visitati[i])//visitati di dim+1
			{
				visitati[i] = true;
				coda.push_back(i);
				padri[i] = current;
				if(i == end)	
					found = true;
			}
	}
	list<int> cammino;
	
	cammino.push_front(end);
	int genitore = padri[end];
	while(genitore!=-1)
	{
		cammino.push_front(genitore);
		genitore = padri[genitore];
	}
	return cammino.size();

}

