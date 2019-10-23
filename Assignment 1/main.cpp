/**
* Rielle Dizon
* Student ID: 2282971
* Student Email: dizon110@mail.chapman.edu
*
* CPSC 380-01
* Assignment 1 (Sudoku Solution Validator)
*
* main.cpp – Checks a given txt file with a 9x9 sudoku grid for duplicates.
* Gives users suggested answers to fix the puzzle.
*
**/
#include <stdio.h>
#include <pthread.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct thread_data
{
    int row;
    int col;
    char (* grid)[9];
};

char grid[9][9];

/**
* Create sudoku grid as 2d array
**/
void createGrid(char* argv)
{
  ifstream fileName;
  fileName.open(argv);
  string line;
  int row = 0;
  int column = 0;
  if(fileName.is_open())
  {
    while(getline(fileName, line))
    {
      for(int character = 0; character < line.size(); ++character)
      {
        if(line[character] != ',')
        {
          grid[row][column] = line[character];
          column++;
        }
      }
      row++;
      column = 0;
    }
  }
}

/**
* Checks for duplicates in the column
**/
void *columnChecker(void * arguments)
{
    struct thread_data *args;
    args = (struct thread_data *) arguments;
    int startRow = 0;
    int startCol = 0;
    bool correct = true;
    for(int i = startCol; i < 9; ++i)
    {
      bool check[9] = {false};
      for(int j = startRow; j < 9; ++j)
      {
        char c = grid[j][i];
        switch (c)
        {
          case '1':
            if(check[0] != true)
              check[0] = true;
            else
              cout << "Duplicate number " << 1 << " found at column " << i+1 << " row " << j+1 << endl;
            break;
          case '2':
            if(check[1] != true)
              check[1] = true;
            else
              cout << "Duplicate number " << 2 << " found at column " << i+1 << " row " << j+1 << endl;
            break;
          case '3':
            if(check[2] != true)
              check[2] = true;
            else
              cout << "Duplicate number " << 3 << " found at column " << i+1 << " row " << j+1 << endl;
            break;
          case '4':
            if(check[3] != true)
              check[3] = true;
            else
              cout << "Duplicate number " << 4 << " found at column " << i+1 << " row " << j+1 << endl;
            break;
          case '5':
            if(check[4] != true)
              check[4] = true;
            else
              cout << "Duplicate number " << 5 << " found at column " << i+1 << " row " << j+1 << endl;
            break;
          case '6':
            if(check[5] != true)
              check[5] = true;
            else
              cout << "Duplicate number " << 6 << " found at column " << i+1 << " row " << j+1 << endl;
            break;
          case '7':
            if(check[6] != true)
              check[6] = true;
            else
              cout << "Duplicate number " << 7 << " found at column " << i+1 << " row " << j+1 << endl;
            break;
          case '8':
            if(check[7] != true)
              check[7] = true;
            else
              cout << "Duplicate number " << 8 << " found at column " << i+1 << " row " << j+1 << endl;
            break;
          case '9':
            if(check[8] != true)
              check[8] = true;
            else
              cout << "Duplicate number " << 9 << " found at column " << i+1 << " row " << j+1 << endl;
            break;
          default:
            break;
        }
      }

      for(int x = 0; x < 9; ++x)
      {
        if(check[x] == false)
        {
          cout << "SUGGESTED SOLUTION: " << x+1 << " is missing from column " << i+1 << endl;
        }
      }
    }
    cout << endl;
    return 0;
}

/**
* Checks for duplicates within each 3x3 subgrid
**/
void *gridChecker(void * arguments)
{
  char sqrs[9][9];
  int gridCount = 0;
  int row = 0;
  int col = 0;
  bool loop = true;
  while(loop)
  {
    int count = 0;
    //get values for subgrids
    for(int i = row; i < row + 3; ++i)
    {
      for(int j = col; j < col + 3; ++j)
      {
        sqrs[gridCount][count] = grid[i][j];
        count++;
      }
    }
    gridCount++;
    if(gridCount == 1 || gridCount == 2 || gridCount == 4 || gridCount == 5 || gridCount == 7 || gridCount == 8)
    {
      col += 3;
    }
    if(gridCount == 3 || gridCount == 6)
    {
      row += 3;
      col = 0;
    }
    if(gridCount == 9)
    {
        loop = false;
        break;
    }
  }

  //start error checking
  for(int i = 0; i < 9; ++i)
  {
    bool check[9] = {false};
    for(int j = 0; j < 9; ++j)
    {
      char c = sqrs[i][j];
      switch (c)
      {
        case '1':
          if(check[0] != true)
            check[0] = true;
          else
            cout << "Duplicate number " << 1 << " found in grid " << i+1 << endl;
          break;
        case '2':
          if(check[1] != true)
            check[1] = true;
          else
            cout << "Duplicate number " << 2 << " found in grid " << i+1 << endl;
          break;
        case '3':
          if(check[2] != true)
            check[2] = true;
          else
            cout << "Duplicate number " << 3 << " found in grid "<< i+1 << endl;
          break;
        case '4':
          if(check[3] != true)
            check[3] = true;
          else
            cout << "Duplicate number " << 4 << " found in grid " << i+1 << endl;
          break;
        case '5':
          if(check[4] != true)
            check[4] = true;
          else
            cout << "Duplicate number " << 5 << " found in grid " << i+1 << endl;
          break;
        case '6':
          if(check[5] != true)
            check[5] = true;
          else
            cout << "Duplicate number " << 6 << " found in grid " << i+1 << endl;
          break;
        case '7':
          if(check[6] != true)
            check[6] = true;
          else
            cout << "Duplicate number " << 7 << " found in grid " << i+1 << endl;
          break;
        case '8':
          if(check[7] != true)
            check[7] = true;
          else
            cout << "Duplicate number " << 8 << " found in grid " << i+1 << endl;
          break;
        case '9':
          if(check[8] != true)
            check[8] = true;
          else
            cout << "Duplicate number " << 9 << " found in grid " << i+1 << endl;
          break;
        default:
          break;
      }
    }
    for(int x = 0; x < 9; ++x)
    {
      if(check[x] == false)
      {
        cout << "SUGGESTED SOLUTION: " << x+1 << " is missing from grid " << i+1 << endl;
      }
    }
  }
  cout << endl;
  return 0;
}

/**
* Prints grid to console
**/
void printGrid()
{
  cout << "\n    Soduko Grid" << endl;
  cout << "---------------------" << endl;
  for(int r = 0; r < 9; ++r)
  {
    for(int c = 0; c < 9; ++c)
    {
      cout << grid[r][c] << " ";
      if(c%3 == 2 && c != 8)
      {
	cout << "| ";
      }
    }
    cout << endl;
    if(r%3 == 2 && r < 8)
    {
	cout << "---------------------" << endl;
    }
  }
  cout << "---------------------" << endl;
  cout << endl;
}

/**
* Checks for duplicates in the row
**/
void *rowChecker(void * arguments)
{
  struct thread_data *args;
  args = (struct thread_data *) arguments;
  int startRow = 0;
  int startCol = 0;
  bool correct = true;

  for(int i = startRow; i < 9; ++i)
  {
    bool check[9] = {false};
    for(int j = startCol; j < 9; ++j)
    {
      char c = grid[i][j];
      switch (c)
      {
        case '1':
          if(check[0] != true)
            check[0] = true;
          else
            cout << "Duplicate number " << 1 << " found at row " << i+1 << " column " << j+1 << endl;
          break;
        case '2':
          if(check[1] != true)
            check[1] = true;
          else
            cout << "Duplicate number " << 2 << " found at row " << i+1 << " column " << j+1 << endl;
          break;
        case '3':
          if(check[2] != true)
            check[2] = true;
          else
            cout << "Duplicate number " << 3 << " found at row " << i+1 << " column " << j+1 << endl;
          break;
        case '4':
          if(check[3] != true)
            check[3] = true;
          else
            cout << "Duplicate number " << 4 << " found at row " << i+1 << " column " << j+1 << endl;
          break;
        case '5':
          if(check[4] != true)
            check[4] = true;
          else
            cout << "Duplicate number " << 5 << " found at row " << i+1 << " column " << j+1 << endl;
          break;
        case '6':
          if(check[5] != true)
            check[5] = true;
          else
            cout << "Duplicate number " << 6 << " found at row " << i+1 << " column " << j+1 << endl;
          break;
        case '7':
          if(check[6] != true)
            check[6] = true;
          else
            cout << "Duplicate number " << 7 << " found at row " << i+1 << " column " << j+1 << endl;
          break;
        case '8':
          if(check[7] != true)
            check[7] = true;
          else
            cout << "Duplicate number " << 8 << " found at row " << i+1 << " column " << j+1 << endl;
          break;
        case '9':
          if(check[8] != true)
            check[8] = true;
          else
            cout << "Duplicate number " << 9 << " found at row " << i+1 << " column " << j+1 << endl;
          break;
        default:
          break;
      }
    }
    for(int x = 0; x < 9; ++x)
    {
      if(check[x] == false)
      {
        cout << "SUGGESTED SOLUTION: " << x+1 << " is missing from row " << i+1 << endl;
      }
    }
  }
  cout << endl;
  return 0;
}

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    cout << "Yikes. Do that again by rerunning a.out with the txt file you want"
    " analyzed" << endl;
    exit(0);
  }
  createGrid(argv[1]);
  printGrid();

  pthread_t threadRows,threadColumns, threadSubgrids;
  struct thread_data args;
  args.row = 0;
  args.col = 0;
  cout << "Any existing errors and their suggested answers will be printed below."
  "\nIf no errors print, the puzzle is correct!\n" << endl;

  pthread_create(&threadRows, NULL, rowChecker, (void *) &args);
  pthread_create(&threadColumns, NULL, columnChecker, (void *) &args);
  pthread_create(&threadSubgrids, NULL, gridChecker, (void *) &args);

  pthread_join(threadRows, NULL);
  pthread_join(threadColumns, NULL);
  pthread_join(threadSubgrids, NULL);
}
