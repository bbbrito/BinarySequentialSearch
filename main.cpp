#include <stdlib.h>
#include <ctime>
#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;

bool trocar ( int &, int & );
bool trocar ( double &, double & );
void outputVector( const vector< double > & );
void bubbleSort( vector< double > & );
void fillVector( vector< double > & );
void imprimeVetor( vector< double > & );
void funcArray( int [], vector< double > & );
int sequentialSearch( int &, int [], int & );
int binarySearch( int &, vector< double > & );

int main( )
{
    int numberSearch = 0;
    int size = 0;
    srand( ( int ) time ( 0 ) );
    vector< double > vetorFinal;
	const int NITER = 5;
	int numberStep1 = 0;
	int numberStep2 = 0;
	double mediaSequential = 0.0;
	double mediaBinary = 0.0;
    	
	int totalStepsSequential = 0;
	int totalStepsBinary = 0;
    for (int i = 0; i <= NITER - 1; i++)
    {
	    fillVector( vetorFinal );
	    imprimeVetor( vetorFinal );
	    
	    bubbleSort( vetorFinal );
	    imprimeVetor( vetorFinal );
	    
	    int myArray[ vetorFinal.size() ];	    
	    funcArray( myArray, vetorFinal );

		//Sequential Search
		numberSearch = myArray[ rand() % ( vetorFinal.size( ) - 1 ) ];//Intervalo de acordo com o tamanho do vetor fornecido pelo usuario.
		size = 	vetorFinal.size();
        numberStep1 = sequentialSearch( numberSearch, myArray, size );
        
        //Binary Search
    	numberStep2 = binarySearch( numberSearch, vetorFinal );    	
    	totalStepsSequential += numberStep1;    	
        totalStepsBinary += numberStep2;
	}
    mediaSequential = (double)totalStepsSequential / (double)NITER; 
	mediaBinary = (double)totalStepsBinary / (double)NITER;
	
    cout << "Media de passos da Sequential Search: " << mediaSequential << '\n';
    cout << "Media de passos da Binary Search: " << mediaBinary << '\n';
 
    system ("pause"); 
    return 0;

}

int binarySearch( int & numberSearch, vector< double > & vetor2 )
{
	int low = 0;
    int mid = 0;
    int high = 0;
    int middle = 0;
    int step2 = 1;
    
    do
    {
        mid = vetor2[ ( vetor2.size( ) - 1 ) / 2 ];         
        middle = ( vetor2.size( ) - 1 ) / 2;
        if( numberSearch < mid )
        {
            vetor2.erase( vetor2.begin( )+middle, vetor2.end( ) );
            step2++;
        }          
        else if ( numberSearch > mid && vetor2.size( ) > 2 )
        {               
            vetor2.erase( vetor2.begin( ), vetor2.begin( )+middle );
            step2++;
        }
        else if ( numberSearch > mid && vetor2.size( ) <= 2 )
        {               
            vetor2.erase( vetor2.begin( ) );
            step2++;
        }
    } while( numberSearch != mid );       
    
	cout << "Numero encontrado na Binary Search: " << mid << '\n';
    cout << "Numero de passos na Binary Search: " << step2 << "\n\n";
    
    vetor2.erase( vetor2.begin( ), vetor2.end( ) );

    return step2;
}

int sequentialSearch( int & numberSearch, int myArray[ ], int & sizeMyArray )
{
    int step1 = 1;
    cout << "O numero a ser encontrado eh: " << numberSearch << "\n\n";
    for( int i = 0; i < sizeMyArray; i++ )
    {
        if( numberSearch == myArray[ i ] )
        {
            cout << "Numero encontrado na Sequential Search: " << myArray[ i ] << '\n';
            cout << "Numero de passos na Sequential Search: " << step1 << "\n\n";
            break;
        }
        else
        {
            step1++;
        }
    }
    return step1;
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
        
    cout << "Total de trocas: " << count << "\n\n";
    

}

void fillVector( vector< double > & vetor )
{
	cout << "............................................" << '\n';
	int count = 0;
    int size = 0;
    cout << "Digite um inteiro para o tamanho do vetor: " << '\n';
    cin >> size;
    while( count < size )
    {        
        vetor.push_back( 100.0 * (1 + rand() % 30) / 30.0 );      
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
        cout << vetor[ i ] << '\t';
    cout << "\n\n";
}

void funcArray(int array[], vector< double > & vetor1)
{
    for(int i = 0; i < vetor1.size( ); i++)
        array[ i ] = vetor1[ i ];
       
    cout << "Os valores do Array sao: " << '\n';
    for ( int i = 0; i < vetor1.size( ); i++ )
        cout << array[ i ] << '\t';       
    cout << "\n\n";
}

