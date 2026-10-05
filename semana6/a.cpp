#include<bits/stdc++.h>
using namespace std;

//encontra chefe do grupo da posição x
int find(int x, vector<int>& pais) {
    if (pais[x] == x) {
        return x; //chefe de si mesmo
    }
    return pais[x] = find(pais[x], pais); 
}

//função que une grupos e u e v
void unite(int u, int v, vector<int>& pais) {
    int chefeU = find(u, pais);
    int chefeV = find(v, pais);

    //se tem pais diferentes, juntamos os grupos
    if (chefeU != chefeV) {
        pais[chefeU] = chefeV; //chefe de um passa a ser chefe do outro também
    }
}

int main(){
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int tamanho, numPares;
    cin >> tamanho >> numPares;

    vector<int> valores(tamanho + 1);
    vector<int> pais(tamanho + 1);

    for(int i = 1; i <= tamanho; ++i){
        cin >> valores[i];
        pais[i] = i; //cada posicao começa como pai dela mesma
    }

    for(int i = 0; i < numPares; ++i){
        int u, v;
        cin >> u >> v;
        unite(u, v, pais);
    }
    //fila de prioridade pra cada chefe
    vector<priority_queue<int>> filas(tamanho + 1); //ordena automaticamente

    //distribui os valores para as filas corretas
    for(int i = 1; i <= tamanho; ++i){
        int chefe = find(i, pais); //maior chefe
        filas[chefe].push(valores[i]);
    }
    //imprime
    for(int i = 1; i <= tamanho; ++i){
        int chefe = find(i, pais); // Descobre a qual grupo a posição atual pertence
        
        cout << filas[chefe].top() << ' '; 
        
        //pop no maior da fila
        filas[chefe].pop(); 
    }
    return 0;
}