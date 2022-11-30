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
    cout << "Approx subset sum" << endl;
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        merge_lists(l, v, x);
        float delta = e / (float)(2 * n);
        trim(l, delta);
        
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
    cout << "Exact subset sum" << endl;
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
    vector<int> v1, v2, v3, v4, v5;
    v1 = {104, 102, 201, 101};
    generateRandom(v2, 10);
    generateRandom(v3, 20);
    generateRandom(v4, 50);
    generateRandom(v5, 100);
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
    cout << endl << endl << endl;

    clock_t texact2;
    texact2 = clock();
    int exact2 = exact_subset_sum(v2, target);
    texact2 = clock() - texact2;
    clock_t tapprox2;
    tapprox2 = clock();
    int approx2 = approx_subset_sum(v2, target, 0.40);
    tapprox2 = clock() - tapprox2;
    cout << "Exact time needed " << ((float)texact2)/CLOCKS_PER_SEC << endl;
    cout << "Approx time needed " << ((float)tapprox2)/CLOCKS_PER_SEC << endl;


    clock_t texact3;
    texact3 = clock();
    int exact3 = exact_subset_sum(v3, target);
    texact3 = clock() - texact3;
    clock_t tapprox3;
    tapprox3 = clock();
    int approx3 = approx_subset_sum(v3, target, 0.40);
    tapprox3 = clock() - tapprox3;
    cout << "Exact time needed " << ((float)texact3)/CLOCKS_PER_SEC << endl;
    cout << "Approx time needed " << ((float)tapprox3)/CLOCKS_PER_SEC << endl;
    
    
    


    clock_t texact4;
    texact4 = clock();
    int exact4 = exact_subset_sum(v4, target);
    texact3 = clock() - texact4;
    clock_t tapprox4;
    tapprox4 = clock();
    int approx4 = approx_subset_sum(v4, target, 0.40);
    tapprox3 = clock() - tapprox4;
    cout << "Exact time needed " << ((float)texact4)/CLOCKS_PER_SEC << endl;
    cout << "Approx time needed " << ((float)tapprox4)/CLOCKS_PER_SEC << endl;
    



    clock_t texact5;
    texact5 = clock();
    int exact5 = exact_subset_sum(v5, target);
    texact5 = clock() - texact5;
    clock_t tapprox5;
    tapprox5 = clock();
    int approx5 = approx_subset_sum(v5, target, 0.40);
    tapprox3 = clock() - tapprox5;
    cout << "Exact time needed " << ((float)texact5)/CLOCKS_PER_SEC << endl;
    cout << "Approx time needed " << ((float)tapprox5)/CLOCKS_PER_SEC << endl;

    
    
    
    
    vector<float> y_exact, y_approx;
    y_exact = {((float)texact1)/CLOCKS_PER_SEC, 
                ((float)texact2)/CLOCKS_PER_SEC,
                ((float)texact3)/CLOCKS_PER_SEC,
                ((float)texact4)/CLOCKS_PER_SEC,
                ((float)texact5)/CLOCKS_PER_SEC};
    y_approx = {((float)tapprox1)/CLOCKS_PER_SEC,
                ((float)tapprox2)/CLOCKS_PER_SEC,
                ((float)tapprox3)/CLOCKS_PER_SEC,
                ((float)tapprox4)/CLOCKS_PER_SEC,
                ((float)tapprox5)/CLOCKS_PER_SEC};
    vector<int> x;
    x = {4, 10, 20, 50, 100};
    

    ofstream file;
    file.open ("data.txt");
    file << "# Dataset for exact times (index 0)\n# X   Y\n";
    for(int i = 0; i < 5; i++)
        file << "  " << x[i] << "   " << y_exact[i] << "\n";
    file << "\n\n";
    file << "# Dataset for approximate times (index 1)\n# X   Y\n";
    for(int i = 0; i < 5; i++)
        file << "  " << x[i] << "   " << y_approx[i] << "\n";
    


	return 0;
}
