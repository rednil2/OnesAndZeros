#include <iostream>
#include <vector>

//Константы
constexpr int EMPTY_CELL = -1;

constexpr int WIN_SCORE = 100;
constexpr int LOSE_SCORE = -100;
constexpr int DRAW_SCORE = 0;

constexpr int PLAYER_WIN = 1;
constexpr int COMPUTER_WIN = 2;
constexpr int DRAW = 0;

int errCount = 0;


//Поиск пустых клеток
std::vector<int> findEmptyCells(
const std::vector<int>& board)
{
	std::vector<int> emptyCells;
	for (int i = 0; i < 9; ++i)
	    if (board[i] == EMPTY_CELL)
	        emptyCells.push_back(i);
	        
	return emptyCells;
}

//Поиск пустых клеток не включая одну
std::vector<int> findEmptyCells(
        int n,
        const std::vector<int>& board)
{
	std::vector<int> emptyCells;
	for (int i = 0; i < 9; ++i)
	    if (board[i] == EMPTY_CELL and i != n)
	        emptyCells.push_back(i);
	        
	return emptyCells;
}

//Проверка победы
int whoWin(
        const std::vector<int>& board)
{
	if (board[0] == board[1] and
	     board[1] == board[2] and
	     board[2] == 1 or
	     
	     board[3] == board[4] and
	     board[4] == board[5] and
	     board[5] == 1 or
	     
  	   board[6] == board[7] and
  	   board[7] == board[8] and
  	   board[8] == 1 or
  	   
  	   
  	   board[0] == board[3] and
   	  board[3] == board[6] and
   	  board[6] == 1 or
   	  
  	   board[1] == board[4] and
   	  board[4] == board[7] and
    	 board[7] == 1 or
    	 
  	   board[2] == board[5] and
  	   board[5] == board[8] and
   	  board[8] == 1 or
  	   
  	   
   	  board[0] == board[4] and
         board[4] == board[8] and
         board[8] == 1 or
         
    	 board[6] == board[4] and
     	board[4] == board[2] and 
     	board[2] == 1)
    	 {
    	 	return PLAYER_WIN;
    	 }
    	 else if (
    	 board[0] == board[1] and
	     board[1] == board[2] and
	     board[2] == 0 or
	     
	     board[3] == board[4] and
	     board[4] == board[5] and
	     board[5] == 0 or
	     
  	   board[6] == board[7] and
  	   board[7] == board[8] and
  	   board[8] == 0 or
  	   
  	   
  	   board[0] == board[3] and
   	  board[3] == board[6] and
   	  board[6] == 0 or
   	  
  	   board[1] == board[4] and
   	  board[4] == board[7] and
    	 board[7] == 0 or
    	 
  	   board[2] == board[5] and
  	   board[5] == board[8] and
   	  board[8] == 0 or
  	   
  	   
   	  board[0] == board[4] and
         board[4] == board[8] and
         board[8] == 0 or
         
    	 board[6] == board[4] and
     	board[4] == board[2] and 
     	board[2] == 0)
    	 {
    	 	return COMPUTER_WIN;
    	 } 
    	 std::vector<int> emptyCells = findEmptyCells(board);
    	 if (emptyCells.size() == 0)
    	 {
    	 	return DRAW;
    	 }
    	 
    	 return -1;
}

//Вывод вектора игрового поля в консоль
void printVectorBoard (
        const std::vector<int>& board)
{
	for (int i = 0; i < 9; ++i)
	    if (board[i] == 1 or board[i] == 0)
	        std::cout << i;
	std::cout << std::endl;
}

//Вывод игрового поля в консоль
void printBoard(
        const std::vector<int>& board)
{	    
	    for (int i = 0; i < 3; ++i)
	    {
	    	std::cout 
	    	    << "                                     ";
	    	for (int j = 0; j < 3; ++j)
	    	{
	    		if (board[i * 3 + j] == EMPTY_CELL)
	    		    std::cout << " ";
	    		else 
	    		    std::cout << board[i * 3 + j];
	    		    
	    		if (j != 2)
	    		    std::cout << " | " ;
	    	}
	    	if (i != 2)
	    	{
	        	std::cout
	        	    << std::endl
	        	    << "                                     "
	                << "—————————" 
    	            << std::endl;
	    	}
	    }
	    
	    std::cout
	        << std::endl 
	        << std::endl
	        << std::endl;
}

//Ход игрока
void makePlayerMove (
        std::vector <int>& board,
        int& isEnd)
{
	int i;
	std::cin >> i;
	if (i < 10 and i > 0 
	and board[i - 1] != 0
    and board[i - 1] != 1)
    {
	    board[i - 1] = 1;
	    isEnd = whoWin(board);
    }
	else 
	{
		std::cout << "Error, try again" << std::endl;
		makePlayerMove(board, isEnd);
	}
}

//Ход компьютера рекурсивный
int makeMySubmove(
        int n,
        std::vector <int> board)
{
	std::vector<int> emptyCells = findEmptyCells(n, board);
	std::vector<int> emptyCellsScore(emptyCells.size());
	
	if (emptyCells.size() == 0)
	{
	    return 0;
	}
	else 
	{
		board[n] = 0;
		if (whoWin(board) == COMPUTER_WIN)
    	{
    	    return 10;
    	}
    	else if (whoWin(board) == PLAYER_WIN)
    	{
    	    return -10;
    	}
    	else 
    	{
	    	int maxCount = -100000;
	    	int maxIndex = -1;
		
    	    for (int i = 0; i < emptyCells.size(); ++i)
    	    {
    	    	
    	    }
	        
	        for (int i = 0; i < emptyCells.size(); ++i)
    	    {
	            if (emptyCellsScore[i] > maxCount)
	            {
	                maxCount = emptyCellsScore[i];
	                maxIndex = emptyCells[i];
    	        }
    	    }
	    
	        return maxIndex;
    	}
	}
}

//Ход компьютера общий
void makeMyMove(
        std::vector <int>& board, 
        int& isEnd)
{
	std::vector<int> emptyCells = findEmptyCells(board);
	std::vector<int> emptyCellsScore(emptyCells.size());
	
	if (emptyCells.size() == 0)
	    isEnd = 1;
	else
	{
		int maxCount = -100000;
		int maxIndex = -1;
		
	    for (int i = 0; i < emptyCells.size(); ++i)
	        emptyCellsScore[i] = makeMySubmove(i, board);
	        
	    for (int i = 0; i < emptyCells.size(); ++i)
	    {
	        if (emptyCellsScore[i] > maxCount)
	        {
	            maxCount = emptyCellsScore[i];
	            maxIndex = emptyCells[i];
	        }
	    }
	    
	    board[maxIndex] = 0;
	    
	    isEnd = whoWin(board);
	}
}

//Старт игрового процесса
void playOnesAndZeros()
{
	std::vector<int> board(9);
	for (int i = 0; i < 9; ++i)
	    board[i] = EMPTY_CELL;
	
	std::cout << "You first?" <<  std::endl;
	bool isFirst;
	std::cin >> isFirst;
	
	int isEnd = -1;
	
	printBoard(board);
	
	if (!isFirst)
	{
	    board[0] = 0;
	    printBoard(board);
	}
	    
	while (isEnd == -1)
	{
		makePlayerMove(board, isEnd);
		printBoard(board);
		makeMyMove(board, isEnd);
		printBoard(board);
	}
	
	if (isEnd == DRAW)
	    std::cout 
	        << "Draw" << std::endl;
	else if (isEnd == COMPUTER_WIN)
	    std::cout 
	        << "Computer win" << std::endl;
	else if (isEnd == PLAYER_WIN)
	    std::cout 
	        << "Player win" << std::endl;
}


//main
int main()
{
	playOnesAndZeros();
	
	return 0;
}
