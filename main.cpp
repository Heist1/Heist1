#include <iostream>
#include <climits>
using namespace std;
int main()
{

	int n, m;
	cin>>n>>m;
	char mat[n][m];
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			cin>>mat[i][j];

	int min = INT_MIN;
	int x = 0, y= 0;
	for(int i = 0; i<n; i++)
	{	
		for(int j = 0; j<m; j++)
		{
			int cont = 0; 
			if(mat[i][j] == '-')
			{	
				bool trovato = false;
				while(!trovato)
				{
					if(i+cont < n && mat[i+cont][j]== '#')
						trovato = true;
					if(i-cont > 0 && mat[i-cont][j] == '#')
						trovato = true;
					if(i-cont > 0 && j-cont > 0 && mat[i-cont][j-cont] == '#')
						trovato = true;
					if(j-cont > 0 && mat[i][j-cont] == '#')
						trovato = true;
					if(j-cont > 0 && i+cont<n &&mat[i+cont][j-cont] == '#')
						trovato = true;
					if(i-cont > 0 && j+cont<n && mat[i-cont][j+cont] == '#')
						trovato = true;
					if(j+cont<n &&mat[i][j+cont] == '#')
						trovato = true;
					if(j+cont <n && i+cont<n &&mat[i+cont][j+cont] == '#')
						trovato = true;
					if(cont>n)
						break;
					cont++;
				}
				if(cont>min && trovato )
				{
					min = cont;
					x = i;
					y = j;
				}
			}
		}
	} 
	cout<<x<<" "<<y<<endl;
}
