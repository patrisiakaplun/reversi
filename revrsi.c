//Name:patrisia kaplun.
//Date:25/04/21
// ID 314631474
//File name:revrsi02.c

#include<stdio.h>

#define NUMOFROWS 20
#define NUMOFCOLS 20

int chooseBoard();
void initBoard(char board[][NUMOFCOLS],int boardSize);
void showBoard(char board[][NUMOFCOLS],int boardSize);
void yourTurn(char board[][NUMOFCOLS],int boardSize,char playerNum);
char switch_Players(char PlayerNum);
void change(char board[][NUMOFCOLS],char playerNum,int rowNum,int colNum,int boardSize);
void score(char board[][NUMOFCOLS],int boardsize);
int true_move(char board[][NUMOFCOLS],int row,int col,int boardsize,char playerNum);
int moves(char board[][NUMOFCOLS],int boardsize,char player);

int main()
{
char board[NUMOFROWS][NUMOFCOLS];
char playerNum = 'X';
int boardSize,validMoves = 1;

boardSize = chooseBoard();
initBoard(board,boardSize);
showBoard(board,boardSize);

 while (boardSize != 0 && validMoves != 0)
 {
 yourTurn(board,boardSize,playerNum);
 showBoard(board,boardSize);
 playerNum = switch_Players(playerNum);
 validMoves = moves(board,boardSize,playerNum);

  if (validMoves == 0)
  {
    playerNum = switch_Players(playerNum);
    validMoves = moves(board,boardSize,playerNum); 

    if (validMoves == 0)
    score(board,boardSize);
  }
 }
printf("Thank you!\n");
}

//This function displays the game menu and lets the player choose the size he wants.
int chooseBoard()
{
 int size;

 printf("WELCOME!");
 printf("Please choose your play board:\n0. exit.\n1. 10X10.\n2. 15X15.\n3. 20X20.\n");
 scanf("%d", &size);

 while (size >= 4)
 {
  printf("Please try again!\n");
  printf("Please choose your play board:\n0. exit.\n1. 10X10.\n2. 15X15.\n3. 20X20.\n");
  scanf("%d", &size);
 }
 
 switch (size)
 {
  case 0 : size = 0;
  break;

  case 1 : size = 10;
  break;

  case 2 : size = 15;
  break;

  case 3 : size = 20;
  break;
 }

 return size; 
}

//This function initializes the board.
void initBoard(char board[][NUMOFCOLS],int boardSize)
{
	int i, j;
    int rows = boardSize -1;
    int cols = rows;

	for (i = 0; i <= rows; i++)
  {
	 for (j = 0; j <= cols; j++)
    {
     if (i ==  rows / 2 && j == cols / 2 )
     board[i][j] ='X';

     else if (i == rows / 2 && j == ( cols / 2 ) + 1 )
     board[i][j] ='O';

     else if (i == ( rows / 2 ) + 1 && j == cols / 2 )
     board[i][j] ='O';

     else if (i == ( rows / 2 ) + 1 && j == ( cols / 2 ) + 1 )
     board[i][j] ='X';

     else 
		 board[i][j] =' ';
    }
  }
} 

//This function shows the board.
void showBoard(char board[][NUMOFCOLS],int boardSize)
{
 int i , j , num = 1;
 int cols = boardSize - 1;
 int rows = cols; 

 printf(" ");
 
 for ( i = 1 ; i <= boardSize ; i++)
 printf(" %3d" , i);

 printf("\n");

 for (i = 0; i <= rows ; i++)
 { 
   for (j = 0 ; j <= cols ; j++)
   {  
    if(j == 0)
    {
     printf("%2d ", num);
     num ++;
    }
    printf(" %c |", board[i][j]);
   }
  printf("\n");
 }
}

//This function lets you choose your next step.
void yourTurn(char board[][NUMOFCOLS],int boardSize,char playerNum)
{
 int rowNum , colNum ,move ,newMove = 1 , countO = 2, countX = 2;
 
 while (newMove == 1)
 { 
  printf("Player %c Please enter num Of rows and num of cols: \n", playerNum);
  scanf("%d%d" , &rowNum, &colNum);
  move = true_move(board,rowNum,colNum,boardSize,playerNum);

  if(move == 1 && board[rowNum - 1][colNum - 1] == ' ')
  {
   board[rowNum - 1][colNum - 1] = playerNum;
   newMove = 0;
  } 

  else
  printf("Invalid move. Please try again.\n");
 } 
 change(board,playerNum,rowNum,colNum,boardSize);
}

//This function checks if the step is possible.
int true_move(char board[][NUMOFCOLS],int row,int col,int boardsize,char playerNum)
{
  int playerNum2 = 'O';
  int i ,j;

  if (playerNum == 'O')
  playerNum2 = 'X';

  if (board[row][col - 1] == playerNum2)
   {
    for ( i = row + 1 ; i < boardsize ; i++)
    {
     if (board[i][col - 1] == playerNum && board[row + 1][col - 1] != ' ' )
     return  1; 
    }
   }

  if (board[row - 2][col - 1] == playerNum2)
   {
    for ( i = row - 3 ; 0 <= i ; i--)
    {
     if (board[i][col - 1] == playerNum && board[row - 3][col - 1] != ' ' )
     return  1; 
    }
   }

   if (board[row - 1][col] == playerNum2)
   {
    for ( i = col + 1 ; i < boardsize ; i++)
    {
     if (board[row - 1][i] == playerNum && board[row - 1][col + 1] != ' ')
     return  1; 
    }
   }
   
   if (board[row - 1][col - 2] == playerNum2)
   {
    for ( i = col - 3  ; 0 <= i ; i--)
    {
     if (board[row - 1][i] == playerNum && board[row - 1][col - 3] != ' ')
     return  1; 
    }
   }
   
   if (board[row][col] == playerNum2)
   {
    for ( i = row + 1 , j = col + 1 ; i < boardsize && j < boardsize ; i++ ,j++)
    {
     if (board[i][j] == playerNum && board[row + 1][col + 1] != ' ')
     return  1; 
    }
   }

   if (board[row - 2][col - 2] == playerNum2)
   {
    for ( i = row - 3 , j = col - 3 ; 0 <= i && 0 <= j ; i-- ,j--)
    {
     if (board[i][j] == playerNum && board[row - 3][col - 3] != ' ')
     return  1; 
    }
   }

    if (board[row - 2][col] == playerNum2)
   {
    for ( i = row - 3 , j = col + 1 ; 0 <= i && j < boardsize ; i-- ,j++)
    {
     if (board[i][j] == playerNum && board[row - 3][col + 1] != ' ')
     return  1; 
    }
   }

    if (board[row][col - 2] == playerNum2)
   {
    for ( i = row + 1 , j = col - 3 ; i < boardsize && 0 <= j ; i++ ,j--)
    {
     if (board[i][j] == playerNum && board[row + 1][col - 3] != ' ')
     return  1; 
    }
   }

  else 
   return 0;   
}

//This function replaces the player at the end of each turn.
char switch_Players(char PlayerNum)
{
	if (PlayerNum == 'X')
		PlayerNum = 'O';
	else
		PlayerNum = 'X';

	return (PlayerNum);
}

//This function changes the board after the step.
void change(char board[][NUMOFCOLS],char playerNum,int rowNum,int colNum,int boardsize)
{
  int i ,j;
  int row = rowNum;
  int col = colNum;

  char playerNum2 = 'O';

  if (playerNum == 'O')
  playerNum2 = 'X';  

  for (i = row ; i < boardsize ; i++)
  {
   if (board[i][col - 1] == playerNum)
   {
    while (board[row][col - 1] == playerNum2 && board[row][col - 1] != ' ' )
    {
     board[row][col -1] = playerNum;
     row++;
    }
    row = rowNum;
    break;
   }
  } 

  for (i = row - 2 ; 0 <= i ; i--)
  {
   if (board[i][col - 1] == playerNum)
   {
    while (board[row - 2][col - 1] == playerNum2 && board[row - 2][col - 1] != ' ')
    {
     board[row - 2][col -1] = playerNum;
     row--;
    }
    row = rowNum;
    break; 
   }
  }
  
  for (j = col ; j < boardsize ; j++)
  {
   if (board[row - 1][j] == playerNum)
   {
    while (board[row - 1][col] == playerNum2 && board[row - 1][col] != ' ')
    {
     board[row - 1][col] = playerNum;
     col++;
    }
    col = colNum;
    break;
   }
  }

  for (j = col - 2 ; j >= 0; j--)
  {
   if (board[row - 1][j] == playerNum)
   {
    while (board[row - 1][col - 2] == playerNum2 && board[row - 1][col - 2] != ' ')
    {
     board[row - 1][col - 2] = playerNum;
     col--;
    }
    col = colNum;
    break;
   }
  }

  for (i = row , j = col ; i < boardsize && j < boardsize ; i++ ,j++)
  {
    if (board[i][j] == playerNum)
    {
     while (board[row][col] == playerNum2  && board[row][col] != ' ')
     {
      board[row][col] = playerNum;
      col++;
      row++;
     }
      col = colNum;
      row = rowNum;
      break;
    }
  }

  for (i = row - 2, j = col - 2 ; 0 <= i && 0<= j ; i-- ,j--)
  {
    if (board[i][j] == playerNum)
    {
     while (board[row - 2][col - 2] == playerNum2 && board[row - 2][col - 2] != ' ' )
     {
      board[row - 2][col - 2] = playerNum;
      col--;
      row--;
     }
     col = colNum;
     row = rowNum;
     break; 
    } 
  }

  for (i = row - 2 , j = col  ; 0 <= i && j < boardsize ; i-- , j++)
  {
    if (board[i][j] == playerNum)
    {
     while (board[row - 2][col] == playerNum2 && board[row - 2][col] != ' ')
     {
     board[row - 2][col] = playerNum;
     col++;
     row--;
     }
     col = colNum;
     row = rowNum; 
     break; 
    } 
  }

  for (i = row , j = col - 2 ; i < boardsize && 0 <= j ; i++ , j--) 
  {
    if (board[i][j] == playerNum)
    {
     while (board[row][col - 2] == playerNum2 && board[row][col - 2] != ' ')
     {
     board[row][col - 2] = playerNum;
     col--;
     row++;
     }
     col = colNum;
     row = rowNum;  
     break; 
    }
  }
} 

//This function checks if there are Are steps left available.
int moves(char board[][NUMOFCOLS],int boardsize,char playerNum)
{
 int i , j ,row , col ;
 int move = 0;

 for (i = 0; i < boardsize && move != 1; i++)
 { 
   for (j = 0 ; j < boardsize && move !=1 ; j++)
   {  
    if (board[i][j] == ' ')
    {
    row = i + 1;
    col = j + 1;
    move = true_move(board,row,col,boardsize,playerNum);
    }
   }
 }
 if (move == 1)
 return 1;

 else
 return 0;
}

//This function shows the score and the winner.
void score(char board[][NUMOFCOLS],int boardsize)
{
 int i , j ,countO = 0, countX = 0;
 
 for (i = 0; i < boardsize ; i++)
  {
	 for (j = 0; j < boardsize ; j++)
   {
    if(board[i][j] == 'O')
    countO++;
    
    else if(board[i][j] == 'X')
    countX++;
   }
  }

  printf("The score is:\nPlayer O: %d\nPlayer X: %d\n", countO , countX);
  
  if (countO > countX)
   printf("Player 0 won!\n");

  if (countO < countX)
   printf("Player X won!\n");

  if (countO == countX)
   printf("Tie Tie !\n");
}