// GMM.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>


std::vector<float> full(int qtdClusters, float fill_value);
std::vector<std::vector<float>> fullMatrix(int linha, int coluna, float fill_value);
std::vector<int>randomVector(int min, int max, int size);
std::vector<std::vector<int>>meanGaussians(std::vector<int> random_row, std::vector<std::vector<double>>matriz);


int main()
{
    int n = 0;
    int m = 0;
    int qtdClusters = 7;

    //pesos iniciais para cada cluster phi ou P(Ci = j)
    std::vector<float> phi;
    //pesos inicias para cada registro wrt para cada cluster, ou P(Xi/Ci=j)
    std::vector<std::vector<float>> weights;
    //valores inicias das médias do k gaussianos
    std::vector<std::vector<int>> mu;


    std::vector<double> valores;
    std::vector<std::vector<double>>matriz;

    valores.push_back(2);
    valores.push_back(52);
    valores.push_back(7);
    valores.push_back(12);

    matriz.push_back(valores);
    valores.clear();

    valores.push_back(25);
    valores.push_back(5);
    valores.push_back(5);
    valores.push_back(18);

    matriz.push_back(valores);
    valores.clear();


    valores.push_back(32);
    valores.push_back(5);
    valores.push_back(41);
    valores.push_back(67);

    matriz.push_back(valores);
    valores.clear();


    valores.push_back(22);
    valores.push_back(5);
    valores.push_back(81);
    valores.push_back(6);

    matriz.push_back(valores);
    
    
    //############################
    //####### INITIALIZE #########
    //############################
    n = matriz.size();
    m = matriz[0].size();
        
    phi = full(qtdClusters, 1.0 / qtdClusters);
    weights = fullMatrix(n, m, 1.0 / qtdClusters);

    std::vector<int> random_row = randomVector(0,n,qtdClusters);
    
    mu = meanGaussians(random_row, matriz);

    //SIGMA...

}


std::vector<float> full(int shape,float fill_value) {
    std::vector<float> retorno;
    for (int i = 0; i < shape; i++) {
        retorno.push_back(fill_value);
    }
    return retorno;
}

std::vector<std::vector<float>> fullMatrix(int linha, int coluna,float fill_value ) {
        
    std::vector<std::vector<float>> retorno;
    
    for (int i = 0; i < linha; i++) {

        std::vector<float>valores;
        for (int j = 0; j < coluna; j++) {
            valores.push_back(fill_value);
        }
        retorno.push_back(valores);
    }

    return retorno;
}

std::vector<int>randomVector(int min, int max, int size) {

    std::vector<int>retorno;
    for (int i = 0; i < size; i++) {        
        int range = max - min + 1;
        retorno.push_back(rand() % range + min);
    }
    return retorno;
}


std::vector<std::vector<int>>meanGaussians(std::vector<int> random_row, std::vector<std::vector<double>>matriz) {

    std::vector<std::vector<int>> retorno;
    
    for (int indxRand = 0; indxRand < random_row.size(); indxRand++) {
    
        std::vector<int>valores;
        int linha = random_row[indxRand];

        for (int coluna = 0; coluna < matriz[linha].size(); coluna++) {
            valores.push_back(matriz[linha][coluna]);
        }
        retorno.push_back(valores);
    }

    return retorno;
}