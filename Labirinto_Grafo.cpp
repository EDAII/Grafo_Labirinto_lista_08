#include <bits/stdc++.h>

using namespace std;
#define INF 10000

typedef pair<int, int> ii;

vector <vector <ii>> grafo;
vector <int> dist;
int linhas, colunas;

void dijkstra(int source){
	dist.clear();
	dist.assign(colunas * colunas + 2, INF);
	dist[source] = 0;

	priority_queue<ii, vector<ii>, greater<ii>> pq;

	pq.push(ii(0, source));

	while(!pq.empty()){
		ii v = pq.top();
		pq.pop();

		for (int i = 0 ; i < grafo[v.second].size(); i++){
			if (dist[grafo[v.second][i].second] > dist[v.second] + 1){
				dist[grafo[v.second][i].second] = dist[v.second] + 1;
				pq.push(ii(dist[grafo[v.second][i].second], grafo[v.second][i].second));
			}
		}
	}
}

int main(){

	cout << endl << "O Labirinto" << endl << endl;

	vector<string> aux;

	string x;

	char c;
	ios_base :: sync_with_stdio(0); cin.tie(0);

	cout << "Entre com o numero de linhas e colunas do labirinto" << endl;

	cin >> linhas >> colunas;

	cout << "Agora construa o seu labirinto 	com a quantidade de linhas e colunas correta." << endl;
	cout << "Coloque \"#\" para fazer uma parede" << endl;
	cout << "Coloque \".\" para uma passagem livre" << endl;

	grafo.assign(colunas * colunas + 2, vector<ii> ());

	for (int i = 0 ; i < linhas ; i++){
		cin >> x;
		aux.push_back(x);
	}

	for (int i = 0 ; i < linhas; i++){
		for (int j = 0; j < colunas; j++){
			if (aux[i][j] == '.'){
				if (i > 0){
					if (aux[i - 1][j] == '.')
					grafo[colunas * i + j].push_back(make_pair(1, colunas * (i - 1) + j));
				}

				if (i < linhas - 1){
					if (aux[i + 1][j] == '.')
					grafo[colunas * i + j].push_back(make_pair(1, colunas * (i + 1) + j));
				}
				if (j > 0){
					if (aux[i][j - 1] == '.')
					grafo[colunas * i + j].push_back(make_pair(1, colunas * i + j - 1));
				}
				if (j < colunas - 1){
					if (aux[i][j + 1] == '.')
					grafo[colunas * i + j].push_back(make_pair(1, colunas * i + j + 1));
				}
			}
		}
	}

	int p;
	for (p = 0; p < grafo.size(); ++p) if (grafo[p].size()) break;
	dijkstra(p);
	int mx = INT_MIN;
	for (int i = 0 ; i < dist.size(); ++i){
		if (dist[i] != INF && dist[i] > mx)
		mx = dist[i], p = i;
	}
	dijkstra(p);
	mx = INT_MIN;
	for (int i = 0 ; i < dist.size(); ++i){
		if (dist[i] != INF && dist[i] > mx)
		mx = dist[i];
	}

	cout << "A quantidade minima de passos para chegar ao fim do labirinto é "<< mx << endl;

}
