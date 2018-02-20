#include <iostream>
using namespace std;
int main() {
    float array3d[3][3] = {
          0.0f,  1.0f, 0.0f,
         -0.5f, -0.5f, 0.0f,
          0.5f, -0.5f, 0.0f
    };
    for (int i=0; i<4; i++) {
        cout << array3d[i][0] << "\t\t" << array3d[i][1] << "\t\t" << array3d[i][2] << endl;
    }
}