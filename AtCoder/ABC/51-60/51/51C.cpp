/*
 * Created Date: Saturday, September 26th 2020, 3:04:42 pm
 * Author: ppdog
 */

#include<iostream>

using namespace std;

int sx, sy, tx, ty;

int main() {
    cin >> sx >> sy >> tx >> ty;
    int x = sx, y = sy;
    for(int i=sy; i<ty; ++i){
        cout<<"U";
    }
    for(int i=sx; i<tx; ++i){
        cout<<"R";
    }
    for(int i=sy; i<ty; ++i){
        cout<<"D";
    }
    for(int i=sx; i<tx; ++i){
        cout<<"L";
    }
 
    cout<<"L";
    for(int i=sy; i<ty+1; ++i){
        cout<<"U";
    }
    for(int i=sx; i<tx+1; ++i){
        cout<<"R";
    }
    cout<<"D";
 
    cout<<"R";
    for(int i=sy; i<ty+1; ++i){
        cout<<"D";
    }
    for(int i=sx; i<tx+1; ++i){
        cout<<"L";
    }
    cout<<"U";
    cout<<endl;
    return 0;
}