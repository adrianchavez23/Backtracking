#include <iostream>  
#include <vector>    
using namespace std; 

//Imprime el tablero
void printBoard(vector<vector<int>> &board, int N) {
    for (int i = 0; i < N; i++) {        
        for (int j = 0; j < N; j++) {     
            cout << board[i][j] << " ";   
        }
        cout << endl;                     
    }
    cout << endl;                         
}

//Comprueba si una reina se puede colocar
bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
    // Comprobar esta columna
    for (int i = 0; i < row; i++) {       
        if (board[i][col] == 1) {         
            return false;                 
        }
    }

    // Comprobar diagonal superior izquierda
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {           
            return false;                 
        }
    }

    // Comprobar diagonal superior derecha
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {           
            return false;                 
        }
    }

    return true;  
}

// Función de backtracking para resolver el problema de N reinas
bool solveNQueens(vector<vector<int>> &board, int row, int N) {
    if (row >= N) {                       //CASO BASE: 
        return true;                      //Se colocaron todas las reinas
    }

    for (int i = 0; i < N; i++) {         
        if (isSafe(board, row, i, N)) {   // Comprobar si es seguro colocar una reina aquí. CONDICIONES
            board[row][i] = 1;            // Colocar la reina. DESICIÓN

            if (solveNQueens(board, row + 1, N)) {  //Llamar a la función recursivamente para la siguiente fila 
                return true;                       // Si en esa fila no se pueden colocar, regresa falso
            }

            board[row][i] = 0;            // Quitar la reina (backtrack). DESHACER LA DESICIÓN.
        }
    }

    return false;    
}

int main() {     
                
    int n1 = 1;    //CASO 1
    int n2 = 4;    //CASO 2
    int n3 = 8;    //CASO 3
    int n4 = 10;   //CASO 4                                        

    vector<int> casos{n1,n2,n3,n4};
    

    for(int i = 0; i < 4; i++){
        cout << "CASO " << i+1 << endl;
        cout << "Tamanio del tablero y no. de reinas: " << casos[i] << endl;
        cout << "Resultado: " << endl;
        vector<vector<int>> board(casos[i], vector<int>(casos[i], 0)); 
        if (solveNQueens(board, 0, casos[i])) {    //Función de backtracking
            printBoard(board, casos[i]);            
        } else {
            cout << "No se encontró una solución." << endl; 
        cout << endl;
    }

    }

    return 0;

    // T(n) = O(N!) Depende de la cantidad de soluciones y es dificil de calcularla excatamente
    // El peor de los casos es si el algoritmo cosidera todas las combinaciones posibles                
}