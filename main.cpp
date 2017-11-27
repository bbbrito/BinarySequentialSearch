#include <stdlib.h>
#include <ctime>
#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;
#include <math.h>

bool trocar ( int &, int & );
bool trocar ( double &, double & );
void outputVector( const vector< double > & );
void bubbleSort( vector< double > & );
void fillVector( vector< double > & );
void imprimeVetor ( vector< double > & );



int main( )
{
    int numberSearch = 0;
    srand( ( int ) time ( 0 ) );
    vector< double > vetorFinal;


    fillVector( vetorFinal );
    imprimeVetor( vetorFinal );
    
    bubbleSort( vetorFinal );
    imprimeVetor( vetorFinal );
    
    int myArray[ vetorFinal.size() ];
    
    for(int i = 0; i < vetorFinal.size( ); i++)
        myArray[ i ] = vetorFinal[ i ];
       
    cout << "Os valores do Array sao: " << '\n';
    for ( int i = 0; i < vetorFinal.size( ); i++ )
        cout << myArray[ i ] << '\n';       
    cout << '\n';



    //Sequencial Search 
    int step1 = 1;
    numberSearch = myArray[ vetorFinal.size( ) - 3 ];
    cout << "O numero a ser encontrado eh: " << numberSearch << '\n';
    for( int i = 0; i < vetorFinal.size( ); i++ )
    {
        if( numberSearch == myArray[ i ] )
        {
            cout << "Numero encontrado na Sequencial Search: " << myArray[ i ] << '\n';
            cout << "Numero de passos na Sequencial Search: " << step1 << '\n';
            break;
        }
        else
        {
            step1++;
        }
    }

    //Binary Search
    numberSearch = vetorFinal[ vetorFinal.size( ) - 3 ];
    int low = 0;
    int mid = vetorFinal[ ( vetorFinal.size( ) - 1 ) / 2 ];
    int high = 0;
    int middle = 0;
    int step2 = 1;
    
    while( numberSearch != mid )
    {
			low = vetorFinal[ 0 ];
            mid = vetorFinal[ ( vetorFinal.size( ) - 1 ) / 2 ];
            high = vetorFinal[ vetorFinal.size( ) - 1 ];
            
            cout << "Primeiro elemento: " << low << '\n';
            cout << "Elemento central: " << mid << '\n';
            cout << "Elemento final: " << high << '\n';
				           
            middle = ( vetorFinal.size( ) - 1 ) / 2;

            if( numberSearch < mid )
            {
                vetorFinal.erase( vetorFinal.begin( )+middle, vetorFinal.end( ) );
                step2++;
            }          
            else if ( numberSearch > mid )
            {               
                vetorFinal.erase( vetorFinal.begin( ), vetorFinal.begin( )+middle );
                step2++;
            }

    }
    if ( numberSearch == mid )
        {               
            cout << "Numero encontrado na Binary Search: " << mid << '\n';
    		cout << "Numero de passos na Binary Search: " << step2 << '\n';
        }
  
    system ("pause"); 
    return 0;

}


void bubbleSort( vector< double > & vetor)
{
    const int NITER = 21;
    int count = 0; 
    
    for (int i = 0; i < NITER - 1; i++)
    {
        for(int j = 1; j < vetor.size( ); j++)
        {
            trocar( vetor[ j - 1 ], vetor[ j ] );
            count++;
        }
    }
        
    cout << "Total de trocas: " << count << '\n';
    

}

void fillVector( vector< double > & vetor )
{
	int count = 0;
    int size = 0;
    cout << "Digite um inteiro para o tamanho do vetor: " << '\n';
    cin >> size;
    while( count < size )
    {        
        vetor.push_back( 100.0 * double(1 + rand() % 30) / 30.0 );      
        count++;        
    } 
}


bool trocar ( int & x, int & y )
{
    
    int temp;
    if( x > y )
    {

        temp = x;
        x = y;
        y = temp;
        return true;
    }
    else 
        return false;
}

bool trocar ( double & x, double & y )
{
    double temp;
    if( x > y )
    {    
        temp = x;
        x = y;
        y = temp;
        return true;
    }
    else 
        return false;
}

void imprimeVetor( vector< double > & vetor )
{
    cout << "Os valores do Vetor sao: " << '\n';
    for (int i = 0; i < vetor.size( ); i++)
        cout << vetor[ i ] << '\n';
}
