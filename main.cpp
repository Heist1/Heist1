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
					
					for(int u = i-cont; u<=i+cont && !trovato; u++)
						for(int k = j-cont; k<=j+cont && !trovato; k++)
							if(k> 0 && k<n && mat[u][k] == '#')
							{
								trovato = true;
								break;
							}
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
