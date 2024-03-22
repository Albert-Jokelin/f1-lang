#include <iostream>

using namespace std;

int main(){
    int hamilton = 15, verstappen = 10;

    while(hamilton != false){
        hamilton--;

        if(verstappen > hamilton){
            hamilton = 0;
            printf("Hamilton overtakes Verstappen\n");
            break;
        }
    }

    return hamilton;
}
