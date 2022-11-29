#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void generateRandom(vector<int> &v, int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp = rand();
        if(i != 0)
        {
            auto it = find(v.begin(), v.end(), temp);
            while(it != v.end())
            {
                temp = rand();
                it = find(v.begin(), v.end(), temp);
            }
                
        }
        v.push_back(temp);
    }
}

void merge_lists(vector<int> &l, vector<int> v, int x)
{
    int n = l.size();
    for(int i = 0; i < n; i++) 
    {
        int element = l[i] + x;
        if(find(l.begin(), l.end(), element) == l.end())
            l.push_back(element);
    }
    sort(l.begin(), l.end());
    //     l.push_back(l[i] + x);
    // set<int> s;
    // for(int i = 0; i < l.size(); i++)
    //     s.insert(l[i]);
    // l.clear();
    // for(auto it = s.begin(); it != s.end(); it++)
    //     l.push_back(*it);
}




void trim(vector<int> &l, float delta)
{
    int m = l.size();
    vector<int> l_;
    l_ = {l[0]};
    int last = l[0];
    
    for(int i = 1; i < m; i++)
    {
        if(l[i] > last * (1 + delta))
        {
            l_.push_back(l[i]);
            last = l[i];
        }
    }
    
    l.clear();
    l = l_;
}

int approx_subset_sum(vector<int> v, int target, float e)
{
    int n = v.size();
    vector<int> l;
    l = {0};
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        merge_lists(l, v, x);
        float delta = e / (float)(2 * n);
        trim(l, delta);
        cout << "delta is : " << delta << endl;
        // trim(l, 0.05);
        for(int i = l.size() - 1; i >= 0; i--)
        {
            if(l[i] > target)
                l.pop_back();
        }
        for(int i = 0; i < l.size(); i++)
            cout << l[i] << " ";
        
        cout << endl;
        
    }
    cout << l[l.size() - 1] << endl;
    cout << endl << endl;
    return l[l.size() - 1];
    
}








int exact_subset_sum(vector<int> v, int target)
{
    int n = v.size();
    vector<int> l;
    l = {0};
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        merge_lists(l, v, x);
        for(int i = l.size() - 1; i >= 0; i--)
        {
            if(l[i] > target)
                l.pop_back();
        }
        for(int i = 0; i < l.size(); i++)
            cout << l[i] << " ";
        
        cout << endl;
        
    }
    cout << l[l.size() - 1];
    cout << endl << endl;
    return l[l.size() - 1];
    
}




int main() {
	// your code goes here
    vector<int> v1, v2, v3, v4;
    v1 = {104, 102, 201, 101};
    generateRandom(v2, 10);
    generateRandom(v3, 50);
    generateRandom(v4, 100);
    int target;
    cout << "Enter target value" << endl;
    cin >> target;
    clock_t texact1;
    texact1 = clock();
    int exact1 = exact_subset_sum(v1, target);
    texact1 = clock() - texact1;
    clock_t tapprox1;
    tapprox1 = clock();
    int approx1 = approx_subset_sum(v1, target, 0.40);
    tapprox1 = clock() - tapprox1;
    cout << "Exact time needed " << ((float)texact1)/CLOCKS_PER_SEC << endl;
    cout << "Approx time needed " << ((float)tapprox1)/CLOCKS_PER_SEC << endl;
    // int exact2 = exact_subset_sum(v2, target);
    // int approx2 = approx_subset_sum(v2, target, 0.40);
    // int exact3 = exact_subset_sum(v3, target);
    // int approx3 = approx_subset_sum(v3, target, 0.40);
    // int exact4 = exact_subset_sum(v4, target);
    // int approx4 = approx_subset_sum(v4, target, 0.40);
    
	return 0;
}
