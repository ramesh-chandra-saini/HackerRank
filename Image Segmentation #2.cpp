#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool isBoundary(int i,int j,int N,int M){
    return i<0 || i>=N || j<0 || j>=M;
}
void solve(int i,int j,vector<string>&image){
    int N = image.size();
    int M = image[0].length();
    for(int a=-1;a<=1;a++){
        for(int b=-1;b<=1;b++){
            if(a==0 && b==0)
                continue;
            if(!isBoundary(i+a,j+b,N,M) && image[i+a][j+b]=='1'){
                image[i+a][j+b]='0';
                solve(i+a,j+b,image);
            }
        }
    }
}
int main() {
    vector<string> image={
                        "000110001010",
                        "111011110001",
                        "111010010010",
                        "100000000100"
                        };
    int segments = 0;
        for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].length();j++){
            if(image[i][j]=='0')
                continue;
            segments++;
            image[i][j]='0';//just to ensure
            solve(i,j,image);
        }
    }
    printf("%d\n",segments);
    return 0;
}
