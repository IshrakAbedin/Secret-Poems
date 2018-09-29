#include <iostream>
using namespace std;

void cover_up(int row, int col);
void cover_down(int row, int col);
void put_right(int row, int col, int j);
void put_left(int row, int col, int j);
void put_down(int row, int col, int j);
void put_up(int row, int col, int j);

char arr[100][100];
char temp[10000];
int range;
int index;

int main(){
    cin >> range;
    index = 0;

    for(int i = 0; i < range; i++){
        for(int j = 0; j < range; j++){
            cin >> arr[i][j];
        }
        cin.ignore();
    }

    cover_up (0, 0);

    //for(int i = 0 ; i < index ; i++) cout << temp[i];

    for(int i = 0; i < range; i ++){
        for(int j = 0 ; j < range ; j ++){
            arr[i][j] = 0;
        }
    }

    put_right(0, 0, 0);

    for(int i = 0; i < range; i++){
        for(int j = 0; j < range; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}

void cover_up(int row, int col){
    temp[index] = arr[row][col];
    index ++;
    if(row == range - 1 && col == range-1) return;
    else if (col + 1 > range - 1) cover_down (row + 1, col);
    else if (row - 1 < 0) cover_down (row, col + 1);
    else cover_up (row - 1, col + 1);
}

void cover_down(int row, int col){
    temp[index] = arr[row][col];
    index ++;
    if(row == range - 1 && col == range-1) return;
    else if (row + 1 > range - 1) cover_up (row, col + 1);
    else if (col - 1 < 0) cover_up (row + 1, col);
    else cover_down (row + 1, col - 1);
}

void put_right(int row, int col, int j){
    arr[row][col] = temp[j];
    if(j == range*range - 1) return;
    else if(arr[row][col+1] == 0 && col+1 < range) put_right(row, col + 1, j + 1);
    else put_down(row + 1, col, j + 1);
}

void put_left(int row, int col, int j){
    arr[row][col] = temp[j];
    if(j == range*range - 1) return;
    else if(col - 1 >= 0 && arr[row][col - 1] == 0) put_left(row, col - 1, j + 1);
    else put_up(row - 1, col, j + 1);
}

void put_down(int row, int col, int j){
    arr[row][col] = temp[j];
    if(j == range*range - 1) return;
    else if(arr[row + 1][col] == 0 && row + 1 < range) put_down(row + 1, col, j + 1);
    else put_left(row, col - 1, j + 1);
}

void put_up(int row, int col, int j){
    arr[row][col] = temp[j];
    if(j == range*range - 1) return;
    else if(row - 1 >= 0 && arr[row - 1][col] == 0) put_up(row - 1, col, j+1);
    else put_right(row, col + 1, j + 1);
}
