# include <stdio.h>
# include <stdlib.h>

typedef struct _Pilha
{
    char op;
    struct _Pilha *proximo;
}Pilha;

void transfereTempPos( Pilha **pPos, Pilha **pTemp, Pilha *aux )
{
    aux = ( *pTemp ) -> proximo;
    ( *pTemp ) -> proximo = *pPos;
    *pPos = *pTemp;
    *pTemp = aux;
}

void alocaCharNaPilha( Pilha **pilha, Pilha *aux, char op )
{
    aux = ( Pilha *) malloc( sizeof( Pilha ) );
    aux -> op = op;  
    aux -> proximo = *pilha;
    *pilha = aux;
}

void leOperacao( Pilha **pPos, Pilha **pTemp )
{
    char op;
    Pilha *aux;
    
    scanf( "%c", &op );
    while( op != '\n' )
    {      

        switch( op )
        {
            case '+':
            case '-':

                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            case '*':
            case '/':

                while( ( *pTemp ) && ( (*pTemp) -> op != '+' && (*pTemp) -> op != '-'
                        && (*pTemp) -> op != '(' ) )
                {        
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            case ')':
                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                if( (*pTemp) && (*pTemp) -> op == '(' )
                {
                    aux = *pTemp;
                    *pTemp = (*pTemp) -> proximo;
                    free( aux );
                }
                
                break;

            case '(':
                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            default:
                alocaCharNaPilha( &( *pPos ), aux, op );
                
                break;
        }

        scanf( "%c", &op );
    }

    while( *pTemp )
    {
        alocaCharNaPilha( &( *pTemp ), aux, op );
    }
    
}

void imprime( Pilha *topo )
{
    if( topo )
    {
        imprime( topo -> proximo );
        printf( "%c", topo -> op );
    }   
}

int main()
{
    Pilha *pPos = NULL;
    Pilha *pTemp = NULL;

    printf( "Operacao Infixa: " );
    leOperacao( &pPos, &pTemp );
    printf( "Operacao Posfixa: " );
    imprime( pPos );
    printf( "\n" );

    return 0;
}