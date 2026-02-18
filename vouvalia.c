/* Aristotelis Psaras
 Eleni Mavrogianni
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define d 1/8
#define d1 1/7
#define d2 1/6
#define d3 1/5

void easy(void);         //levels
void medium(void);
void hard(void);
void super_hard(void);

void rd(int buff_table[20][20],int bl[10][10],int final_buff[20][20] , int M,int N,int **ar, int buff, int total); 
void fmv(int x, int y,int buff_table[20][20],int M,int N);
void move(int M , int N, int buff_table[20][20],int bl[10][10], int x, int y, int buff);

void blanksp(int buff_table[20][20],int bl[10][10],int x, int y); 
void buffs(int buff_table[20][20],int M,int N);
void chrs(int buff_table[20][20],int bl[10][10],int final_buff[20][20], int M ,int N, int **ar, int buff, int total);

void table_game(int bl[10][10],int buff_table[20][20], int M,int N);
void final(int final_buff[20][20] , int M,int N);

void chrs2(int buff_table[20][20],int bl[10][10],int final_buff[20][20], int M ,int N,  int **ar,int buff, int total);
void chrs3(int buff_table[20][20],int bl[10][10],int final_buff[20][20], int M ,int N, int **ar3,int buff, int total);
void chrs4( int buff_table[20][20],int bl[10][10],int final_buff[20][20] , int M,int N,int **ar, int buff, int total);


void rd(int buff_table[20][20],int bl[10][10],int final_buff[20][20] , int M,int N,int **ar, int buff, int total)
{
  int i,j;
  buff=0;
  srand(time(NULL));                                
      for( j=0;j<N;j++ )                                     // for to put the '#' and the '.' in the table 
       {
        for( i=0;i<M; i++)
         {
            buff_table[i][j] = '#';
            bl[i][j] = buff_table[i][j];                    // put -->('.')  into the final table!
            final_buff[i][j] = buff_table[i][j];        
         }       
       }
   
    while(buff<total )                                      //put buffaloes into the table.
    {
        i = rand()%M;
        j = rand()%N;
        if( buff_table[i][j] != '@')                      //see if there is buffaloes, if not then it puts one.
        {
            buff_table[i][j] = '@';
            final_buff[i][j] = buff_table[i][j];
            buff++;                                           //counts the buffaloes
        }  
        }
       
     buffs(buff_table,M,N);
    chrs(buff_table, bl,final_buff,M,N,ar,buff,total);
}

int main(void)
{  
  int **ar,i,j;
  int M,N;
  int buff_table[20][20],bl[10][10],final_buff[20][20];                                   // total array      
  int buff;
  int total=0;
    do{
    printf("Please enter the size of the array you want\n");
    printf("value 1:");
    scanf("%d", &M);
 
    printf("Value 2:");
    scanf("%d", &N);
       }while(M<4 || N<4 || M>=11 || N>=11 );  
     
    ar=(int**)malloc(M*sizeof(int*));
    for(i=0;i<M;i++)
     {
       ar[i]=(int*)malloc(N*sizeof(int));
       if(ar[i]==NULL){printf("error"); exit(1);}
      }
       int l;
          printf("Levels:\n'1' for begginers,\n'2' for medium,\n'3' for the hard level,\n'4' for super hard\nEnter: ");
    scanf("%d", &l);
   
    switch (l)
    {
    case 1:
       total = (M * N )* d;    //amount of buffaloes
       rd(buff_table, bl,final_buff,M,N,ar,buff,total);
       break;
        
    case 2:
      total = (M * N )* d1 ;
     
     rd(buff_table, bl,final_buff,M,N,ar,buff,total);
        break;
        
    case 3:
       total = (M * N )* d2 ;       
     rd(buff_table, bl,final_buff,M,N,ar,buff,total);
        break;
        
    case 4:
        total = (M * N )* d3 ;       
      rd(buff_table, bl,final_buff,M,N,ar,buff,total);
        break;
        
    default:
        printf("Please select the level that you want to play");
        break;
    }
          return 0;
}

 void medium(void)                                  
{
   int **ar,i,j;
   int M,N;
   int buff_table[20][20],bl[10][10],final_buff[20][20];                                   // total array    
   int buff=0;
   int total=0;
     M=M+2;
     N=N+3;
       
    ar=(int**)malloc(M*sizeof(int*));
   for(i=0;i<M;i++)
     {
       ar[i]=(int*)malloc(N*sizeof(int));
       if(ar[i]==NULL){printf("error"); exit(1);}
      }
      
      total = (M * N )* d1;    
       srand(time(NULL));                                     
     for( j=0;j<N;j++ )                                      
       {
        for( i=0;i<M; i++)
         {
            buff_table[i][j] = '#';
            bl[i][j] = buff_table[i][j];                    
            final_buff[i][j] = buff_table[i][j];        
         }       
       }
      
    while(buff <total )                                      
    {
        i = rand()%M;
        j = rand()%N;
        if( buff_table[i][j] != '@')                      
        {
            buff_table[i][j] = '@';
            final_buff[i][j] = buff_table[i][j];
            buff++;                                                  
        }  
        }       
     buffs(buff_table,M,N);
     chrs2(buff_table, bl,final_buff,M,N,ar,buff,total);  
}
 void hard(void)                                  
{
   int **ar,i,j;
   int M,N;
   int buff_table[20][20],bl[10][10],final_buff[20][20];                                       
   int buff=0;
   int total=0;
     M=M+3;
     N=N+4;
       
    ar=(int**)malloc(M*sizeof(int*));
    
    for(i=0;i<M;i++)
     {
       ar[i]=(int*)malloc(N*sizeof(int));
       if(ar[i]==NULL){printf("error"); exit(1);}
      }
       
    total = (M * N )* d2;
       srand(time(NULL));                                
      for( j=0;j<N;j++ )                                      
       {
        for( i=0;i<M; i++)
         {
            buff_table[i][j] = '#';
            bl[i][j] = buff_table[i][j];                    
            final_buff[i][j] = buff_table[i][j];        
         }       
       }
   
    while(buff <total )                                      
    {
        i = rand()%M;
        j = rand()%N;
        if( buff_table[i][j] != '@')                      
        {
            buff_table[i][j] = '@';
            final_buff[i][j] = buff_table[i][j];
            buff++;                                           
        }  
     }
     buffs(buff_table,M,N);    
   chrs3(buff_table, bl,final_buff,M,N,ar,buff,total);
}
void super_hard(void)                                  
{
   int **ar,i,j;
   int M,N;
   int buff_table[20][20],bl[10][10],final_buff[20][20];                                       
   int buff=0;
   int total=0;
     M=M+4;
     N=N+5;
       
    ar=(int**)malloc(M*sizeof(int*));
    for(i=0;i<M;i++)
     {
       ar[i]=(int*)malloc(N*sizeof(int));
       if(ar[i]==NULL){printf("error"); exit(1);}
      }
       
    total = (M * N )* d3 ;
       srand(time(NULL));                                
      for( j=0;j<N;j++ )                                      
       {
        for( i=0;i<M; i++)
         {
            buff_table[i][j] = '#';
            bl[i][j] = buff_table[i][j];                    
            final_buff[i][j] = buff_table[i][j];        
         }       
       }
    while(buff <total )                                      
    {
        i = rand()%M;
        j = rand()%N;
        if( buff_table[i][j] != '@')                      
        {
            buff_table[i][j] = '@';
            final_buff[i][j] = buff_table[i][j];
            buff++;                                           
        }  
     }
     buffs(buff_table,M,N);     
   chrs4(buff_table, bl,final_buff,M,N,ar,buff,total);   
}
void buffs( int buff_table[20][20], int M, int N )                                   // generates the buffaloes
{  
  int k, l ;
 
    for(l=0;l<N;l++)                                                        //the numbers of the buffaloes near
    {
        for(k=0;k<M;k++)
        {
          if( buff_table[k][l] != '@')
           {        
              buff_table[k][l] = 0;                                   //if the is not buffaloes there then it must be blank '.'
                                                   
            if((buff_table[k-1][l-1] == '@') )
            {
                buff_table[k][l]++;                                  //counts the buffaloes there are around(numbers of how many of them)
            }
            if((buff_table[k+1][l-1] == '@') )
            {
                buff_table[k][l]++;
            }
            if((buff_table[k][l-1] == '@'))
            {
                buff_table[k][l]++;
            }
             if((buff_table[k+1][l+1] == '@') )
            {
                buff_table[k][l]++;
            }
            if((buff_table[k-1][l+1] == '@') )
            {
                buff_table[k][l]++;
            }
            if((buff_table[k-1][l] == '@'))
            {
                buff_table[k][l]++;
            }
            if((buff_table[k+1][l] == '@') )
            {
                buff_table[k][l]++;
            }
            if((buff_table[k][l+1] == '@') )
            {
                buff_table[k][l]++;
            }    
            }                                          
       }    
    }
}
void table_game(int bl[10][10],int buff_table[20][20], int M, int N)       //prints the table with buffaloes, blank spaces and numbers                                   
{  
    int k , l , z ;
    printf("\n\n");
    printf("   ");
    for(z=0; z < M;z++ )                                        //the numbers on top of the table 
    {
        printf(" %d ", z+1);      
    }
    printf("\n  -----------------------------------\n");

    for( l=0;l < N;l++ )                                                                      
    {   
        printf("%d| ", l+1);
         k=0;
        while( k < M)
        {
            if( bl[k][l] == '#')                             
            {
                printf(" %c ", bl[k][l]);
            }
            else if( buff_table[k][l] == 0 )                 // replace '0' with the'.' 
            {
                bl[k][l] = '.';                
                printf(" %c ", bl[k][l]);
            }
            else    if( bl[k][l] == '*')                             
            {
                printf(" %c ", bl[k][l]);
            }         
            else
            {
                printf(" %d ", bl[k][l]);               // else print the numbers of the buffaloes near
            }  
            k++;
        }
        printf("\n"); 
    }  
}
void move(int M , int N, int buff_table[20][20], int bl[10][10], int x, int y, int buff)
{   
     char p,i,j; 
     int k, l ;
    scanf("%c",&p);
    
    if(p=='x' || p=='X' ){printf("\n");exit(1);}
    if(p=='h' ||  p=='H'){ 

    for(l=1;l<N;l++)                                                        
    {
        for(k=0;k<M;k++)
        {
                 
            if((buff_table[k-1][l-1] != '@') )
            {
                printf(" ");                             
            }
            if((buff_table[k+1][l-1] != '@') )
            {
              printf(" ");
            }
            if((buff_table[k][l-1] != '@'))
            {
                printf(" ");
            }
             if((buff_table[k+1][l+1] != '@') )
            {
               printf(" ");
            }
            if((buff_table[k-1][l+1] != '@') )
            {
               printf(" ");
            }
            if((buff_table[k-1][l] != '@'))
            {
                printf(" ");
            }
            if((buff_table[k+1][l] != '@') )
            {
             printf(" ");
                
            }
            if((buff_table[k][l+1] != '@') )
             {
                printf(" ");
             }    
          
            }                                          
        
       printf("Best to stand: %d,%d\n",k,l);
    }
       
        /*for(i=1;i<M;i++){
         {
          for(j=1;j<N;j++)
           { 
            if( buff_table[i][j] =='@' )
              //{
                
                printf(" ");
               
             //}
             //else
             
           } printf("best: %d , %d\n", i,j);
         }  
        
       }*/  
   }
   
   int a,b;
   if(p=='b' ||  p=='B'){
   printf("Guess where is a buffalo\n");
scanf("%d,%d", &a, &b); 
    (a--);
    (b--);
      
      buff_table[a][b]='*';
     bl[a][b]=buff_table[a][b];
    if(buff_table[a][b]=='@')
      buff=buff-1;
   }
}
void final(int final_buff[20][20] , int M,int N)   
{ 
   int z,l,k;
   printf("\n\n\n");
   printf("   ");
    for(z=0;z<M;z++)                                 
    {
        printf(" %d ", z+1);
    }
    printf("\n  -----------------------------------\n");

    for( l=0;l < N;l++ )                                                                
    {   
        printf("%d| ", l+1);
         k=0;
        while( k < M)
        {
            printf(" %c ", final_buff[k][l]);         // prints the final table
            k++;
         }
        printf("\n");
      }         
    }
void blanksp(int buff_table[20][20],int bl[10][10],int x, int y)
{
     bl[x][y] = buff_table[x][y];
    if( bl[x][y] == 0 )                       // checks if there is '.' (blank)
     {                                         
       if( buff_table[x-1][y-1] == 0 )    
         {
            bl[x-1][y] = buff_table[x-1][y];     
         }
       if( buff_table[x-1][y] == 0 )
         {
            bl[x-1][y] = buff_table[x-1][y];
         }
       if( buff_table[x][y-1] == 0 )
         {
            bl[x][y-1] = buff_table[x][y-1];
         }
       if( buff_table[x-1][y+1] == 0 )
         {
            bl[x-1][y+1] = buff_table[x-1][y+1];
         }
       if( buff_table[x+1][y-1] == 0 )
         {
            bl[x+1][y-1] = buff_table[x+1][y-1];
         }
      if( buff_table[x+1][y] == 0 )
         {
            bl[x+1][y] = buff_table[x+1][y];
         }
      if( buff_table[x][y+1] == 0 )
         {
             bl[x][y+1] = buff_table[x][y+1];
         }
      if( buff_table[x+1][y+1] == 0 )
         {
             bl[x+1][y+1] = buff_table[x+1][y+1];
         }
     }
}
void chrs( int buff_table[20][20],int bl[10][10],int final_buff[20][20] , int M,int N,int **ar, int buff, int total)
{
     int x,y,q,i,j,s;    
    s=0;     
    table_game(bl,buff_table,M,N);
      for(j=0; j < N;j++ )                                          // Test if he user has step on '.' in the buff field
    {
        for(i=0;i<M;i++)
       
        {
            if(buff_table[i][j] == bl[i][j])
            {
                s++;
            }
           
        }
    } 
    while(s != ((M * N) - total))                 
    { 
     
    printf("\n\nLevel:1");
    printf("\nDifficulty:easy");
   printf("\nUncoverd buffaloes:%d",buff);
    printf("\nMake your move (px 3,4):\n");
     scanf("%d,%d", &x, &y); 
    (x--);
    (y--);

    move(M ,  N, buff_table,bl,x,y,buff);
    int q,i,j;
  q=0;    
  if(q=0)
   {
     if( buff_table[M][N] == '@' )          //first move not a buff.
      { 
       for(i=0;i<N;i++)
        { 
          for(j=0;j<M;j++)
           {
             if( buff_table[i][j] != '@')
              { 
                buff_table[i][j] == '@';
                buff_table[M][N] == '#';
                
              }
            }
         }     
       }
    }
     
printf("\n\npress 'x' or 'X' for exit\n");
                                          
    if((x < 0) ||(x >= M) || (y < 0) || (y >= N))
    {
        printf("\nWrong move, try again!\n"); // within the limits 
       chrs(buff_table, bl,final_buff,M,N,ar,buff,total);
    } 
    
    if( bl[x][y] != '#' )    // if it is already open
    {
        printf("\nWrong move, try again!Already open.\n");
       chrs(buff_table, bl,final_buff,M,N,ar,buff,total);
    }
    if(buff_table[x][y] == '@')                            
    {   
         buff=buff-1;                          // uncovered buffaloes counter,every time you step into one the counter is decreases 
      
      final(final_buff, M,N);
      printf("\n\nLevel:1");
     printf("\nDifficulty:easy");
     printf("\nUncoverd buffaloes:%d",buff);
    printf("\nBuffalo on your head, you probably feel dizzy!\n\n" );
    exit(1);
      //printf("%ls\n\n",*buff_table);  
      
    }
    
   else                                                      
      { 
           blanksp(buff_table,bl, x,  y);   
        chrs(buff_table, bl,final_buff,M,N,ar,buff,total);      
      }
      }
      for(i=0;i<M;i++)                                            //free malloc
      free(ar[i]);
     free(ar);
        medium();   
}

void chrs2( int buff_table[20][20],int bl[10][10],int final_buff[20][20] , int M,int N,int **ar, int buff, int total)
{
     int x,y,q,i,j,s;    
    s=0;    
  
    table_game(bl,buff_table,M,N);
         for(j=0; j < N;j++ )                                          // Test if he user has step on '.' in the buff field
    {
        for(i=0;i<M;i++)
       
        {
            if(buff_table[i][j] == bl[i][j])
            {
                s++;
            }
           
        }
    }
    while(s != ((M * N) - total))                 
    { 
     
    printf("\n\nLevel:1");
    printf("\nDifficulty:medium");
   printf("\nUncoverd buffaloes:%d",buff);
    printf("\nMake your move (px 3,4):\n");
     scanf("%d,%d", &x, &y); 
    (x--);
    (y--);

    move(M ,  N, buff_table,bl,x,y,buff);
    int q,i,j;
  q=0;    
  if(q=0)
   {
     if( buff_table[M][N] == '@' )          //first move not a buff.
      { 
       for(i=0;i<N;i++)
        { 
          for(j=0;j<M;j++)
           {
             if( buff_table[i][j] != '@')
              { 
                buff_table[i][j] == '@';
                buff_table[M][N] == '#';
                
              }
            }
         }     
       }
    }
      q++;
     
printf("\n\npress 'x' or 'X' for exit\n");
                                          
    if((x < 0) ||(x >= M) || (y < 0) || (y >= N))
    {
        printf("\nWrong move, try again!\n"); // within the limits 
       chrs2(buff_table, bl,final_buff,M,N,ar,buff,total);
    } 
    
    if( bl[x][y] != '#' )    // if it is already open
    {
        printf("\nWrong move, try again!Already open.\n");
       chrs2(buff_table, bl,final_buff,M,N,ar,buff,total);
    }
    if(buff_table[x][y] == '@')                            
    {   
         buff=buff-1;                          
      
      final(final_buff, M,N);
      printf("\n\nLevel:1");
     printf("\nDifficulty:medium");
     printf("\nUncoverd buffaloes:%d",buff);
    printf("\nBuffalo on your head, you probably feel dizzy!\n\n" );
    exit(1);
      //printf("%ls\n\n",*buff_table);     
    }
    
   else                                                      
      { 
           blanksp(buff_table,bl, x,  y);   
        chrs2(buff_table, bl,final_buff,M,N,ar,buff,total);      
      }
      }
      for(i=0;i<M;i++)                                            //free malloc
      free(ar[i]);
     free(ar);
        hard();     
}

void chrs3( int buff_table[20][20],int bl[10][10],int final_buff[20][20] , int M,int N,int **ar, int buff, int total)
{
     int x,y,q,i,j,s;    
    s=0;     
    table_game(bl,buff_table,M,N);
            for(j=0; j < N;j++ )                                          // Test if he user has step on '.' in the buff field
    {
        for(i=0;i<M;i++)
       
        {
            if(buff_table[i][j] == bl[i][j])
            {
                s++;
            }      
        }
    }
   while(s != ((M * N) - total))                 
   { 
   
    printf("\n\nLevel:1");
    printf("\nDifficulty:easy");
    printf("\nUncoverd buffaloes:%d",buff);
    printf("\nMake your move (px 3,4):\n");
     scanf("%d,%d", &x, &y); 
    (x--);
    (y--);

   move(M ,  N, buff_table,bl,x,y,buff);
    int q,i,j;
  if(q=0)
   {
     if( buff_table[M][N] == '@' )          //first move not a buff.
      { 
       for(i=0;i<N;i++)
        { 
          for(j=0;j<M;j++)
           {
             if( buff_table[i][j] != '@')
              { 
                buff_table[i][j] == '@';
                buff_table[M][N] == '#';
                
              }
            }
         }     
       }
    }
      q++;
     
  
printf("\n\npress 'x' or 'X' for exit\n");
                                          
    if((x < 0) ||(x >= M) || (y < 0) || (y >= N))
    {
        printf("\nWrong move, try again!\n"); // within the limits 
       chrs3(buff_table, bl,final_buff,M,N,ar,buff,total);
    } 
    
    if( bl[x][y] != '#' )    // if it is already open
    {
        printf("\nWrong move, try again!Already open.\n");
       chrs3(buff_table, bl,final_buff,M,N,ar,buff,total);
    }
    if(buff_table[x][y] == '@')                            
    {   
         buff=buff-1;                          
      
      final(final_buff, M,N);
      printf("\n\nLevel:1");
     printf("\nDifficulty:easy");
     printf("\nUncoverd buffaloes:%d",buff);
    printf("\nBuffalo on your head, you probably feel dizzy!\n\n" );
    exit(1);
      //printf("%ls\n\n",*buff_table);  
      
    }
    
   else                                                      
      { 
           blanksp(buff_table,bl, x,  y);   
        chrs3(buff_table, bl,final_buff,M,N,ar,buff,total);      
      }
      }
      for(i=0;i<M;i++)                                            
      free(ar[i]);
     free(ar);      
       super_hard();     
}

void chrs4( int buff_table[20][20],int bl[10][10],int final_buff[20][20] , int M,int N,int **ar, int buff, int total)
{
     int x,y,q,i,j,s;    
    s=0;     
    table_game(bl,buff_table,M,N);
        for(j=0; j < N;j++ )                                          // Test if he user has step on '.' in the buff field
    {
        for(i=0;i<M;i++)
       
        {
            if(buff_table[i][j] == bl[i][j])
            {
                s++;
            }
           
        }
    }
    while(s != ((M * N) - total))                 
    { 
     
    printf("\n\nLevel:1");
    printf("\nDifficulty:easy");
   printf("\nUncoverd buffaloes:%d",buff);
    printf("\nMake your move (px 3,4):\n");
     scanf("%d,%d", &x, &y); 
    (x--);
    (y--);

    move(M ,  N, buff_table,bl,x,y,buff);
    int q,i,j;
  q=0;    
  if(q=0)
   {
     if( buff_table[M][N] == '@' )          
      { 
       for(i=0;i<N;i++)
        { 
          for(j=0;j<M;j++)
           {
             if( buff_table[i][j] != '@')
              { 
                buff_table[i][j] == '@';
                buff_table[M][N] == '#';
                
              }
            }
         }     
       }
    }
      q++;
     
printf("\n\npress 'x' or 'X' for exit\n");
                                          
    if((x < 0) ||(x >= M) || (y < 0) || (y >= N))
    {
        printf("\nWrong move, try again!\n"); 
       chrs4(buff_table, bl,final_buff,M,N,ar,buff,total);
    } 
    
    if( bl[x][y] != '#' )   
    {
        printf("\nWrong move, try again!Already open.\n");
       chrs4(buff_table, bl,final_buff,M,N,ar,buff,total);
    }
    if(buff_table[x][y] == '@')                            
    {   
         buff=buff-1;                           
      
      final(final_buff, M,N);
      printf("\n\nLevel:1");
     printf("\nDifficulty:easy");
     printf("\nUncoverd buffaloes:%d",buff);
    printf("\nBuffalo on your head, you probably feel dizzy!\n\n" );
    exit(1);
      //printf("%ls\n\n",*buff_table);  
      
    }
    
   else                                                      
      { 
           blanksp(buff_table,bl, x,  y);   
        chrs4(buff_table, bl,final_buff,M,N,ar,buff,total);      
      }
      }
      for(i=0;i<M;i++)                                           
        free(ar[i]);
        free(ar);      
        printf("End\n\n");     
        exit(1);
}



