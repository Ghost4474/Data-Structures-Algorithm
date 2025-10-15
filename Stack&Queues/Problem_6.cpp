#include<iostream>
#include<vector>
using namespace std;
vector<int> asteroidcollisions(vector<int>asteroids){
    vector<int> res;
    for(int i= 0; i<asteroids.size(); i++){
        if(res.empty() || asteroids[i] > 0){
            res.push_back(asteroids[i]);
        }
        else{
            while(!res.empty() && res.back() > 0 && res.back() < abs(asteroids[i])){
                res.pop_back();
            }
            if(!res.empty() && res.back() + asteroids[i] == 0){
                res.pop_back();
            }
            else if(res.empty() || res.back() < 0){
                res.push_back(asteroids[i]);
            }
        }
    }
    return res;
}
int main(){
    vector<int> asteroids = {5,10,-5};
    vector<int> result = asteroidcollisions(asteroids);
    cout<<"The result of the asteroid_collision is ";
    for(auto i:result)
    {
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}