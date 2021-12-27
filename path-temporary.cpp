#include <iostream>

#define WIDTH 16
#define HEIGHT 16

#define MAXNODES 20

using namespace std;

void printArray(int (&arr)[HEIGHT][WIDTH] ){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void zeroArray(int (&arr)[HEIGHT][WIDTH]){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            arr[i][j] = 0;
        }
    }
}

void zeroArray(int (&arr)[MAXNODES][2]){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            arr[i][j] = 0;
        }
    }
}

int main(){
    const int entry[2] = {2, 2};
    const int exit[2] = {5, 13};
    static int pathArray[HEIGHT][WIDTH];
    zeroArray(pathArray);
    static int lastNode[MAXNODES][2];
    zeroArray(lastNode);

    int heightDirection = 0;
    int widthDirection = 0;
    
    for(int i = 0; i < 8; i++){
        pathArray[i][6] = 2;
    }

    pathArray[entry[0]][entry[1]] = 1;

    int currentNode = 0;

    int lookingAt[2] = {entry[0], entry[1]}; 
    while(lookingAt[0] != exit[0] || lookingAt[1] != exit[1]){
        if(lookingAt[0] != exit[0]){
            if(exit[0] > lookingAt[0]){
                lookingAt[0]++;
                heightDirection = 1;
            }else{
                lookingAt[0]--;
                heightDirection = -1;
            }
        }else{
            heightDirection = 0;
        }
        if(lookingAt[1] != exit[1]){
            if(exit[1] > lookingAt[1]){
                lookingAt[1]++;
                widthDirection = 1;
            }else{
                lookingAt[1]--;
                widthDirection = -1;
            }
        }else{
            widthDirection = 0;
        }

        if(pathArray[lookingAt[0]][lookingAt[1]] != 2){
            //lookingAt[0] += heightDirection;
            //lookingAt[1] += widthDirection;
            pathArray[lookingAt[0]][lookingAt[1]] = 1;

        }else{
            // saves node before collision
            lastNode[currentNode][0] = lookingAt[0] - heightDirection;
            lastNode[currentNode][1] = lookingAt[1] - widthDirection;
            
            //currentNode++;
            // find node in order of preference, 

            

        }

    }
    printArray(pathArray);

    while(1);
    return 0;
}
