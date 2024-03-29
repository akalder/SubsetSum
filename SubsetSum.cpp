#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;


void generateRandom(vector<int> &v, int n)
{
    for(int i = 0; i < n; i++)
    {
        int temp = rand() % 1000;
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


void merge_lists(vector<int> &l,  int x)
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



int approx_subset_sum(vector<int> v, int target, float e, ofstream &f_output)
{
    int n = v.size();
    vector<int> l;
    l = {0};
    cout << "Approx subset sum" << endl;
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        merge_lists(l, x);
        float delta = e / (float)(2 * n);
        trim(l, delta);
        
        for(int j = l.size() - 1; j >= 0; j--)
        {
            if(l[j] > target)
                l.pop_back();
        }
        for(int j = 0; j < l.size(); j++)
        {
            cout << l[j] << " ";
            f_output << " " << l[j] << " ";
        }
        f_output << endl;
        cout << endl;
    
    }
    cout << l[l.size() - 1] << endl;
    cout << endl << endl;
    return l[l.size() - 1];
    
}



int exact_subset_sum(vector<int> v, int target, ofstream &f_output)
{
    int n = v.size();
    vector<int> l;
    l = {0};
    cout << "Exact subset sum" << endl;
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        merge_lists(l, x);
        for(int j = l.size() - 1; j >= 0; j--)
        {
            if(l[j] > target)
                l.pop_back();
        }
        for(int j = 0; j < l.size(); j++)
        {
            cout << l[j] << " ";
            f_output << " " << l[j] << " ";
        }
        f_output << endl;
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
    
    ofstream f_output;
    f_output.open ("output.txt");

    f_output << " For Exact Subset Sum 1(for 4 elements):" << endl;
    auto start1exact = high_resolution_clock::now();
    int exact1 = exact_subset_sum(v1, 308, f_output);
    auto stop1exact = high_resolution_clock::now();
    auto duration1exact = duration_cast<microseconds>(stop1exact - start1exact);
    f_output << endl << endl << endl;
    f_output << " For Approx Subset Sum 1(for 4 elements):" << endl;
    auto start1approx = high_resolution_clock::now();
    int approx1 = approx_subset_sum(v1, 308, 0.40, f_output);
    auto stop1approx = high_resolution_clock::now();
    auto duration1approx = duration_cast<microseconds>(stop1approx - start1approx);
    cout << "Exact time needed: " << (duration1exact.count() / 1000000.0) << " seconds" << endl;
    cout << "Approx time needed: " << (duration1approx.count() / 1000000.0) << " seconds" << endl;
    f_output << endl << endl << endl << endl << endl << endl;
    
    
    f_output << " For Exact Subset Sum 2(for 10 elements):" << endl;
    auto start2exact = high_resolution_clock::now();
    int exact2 = exact_subset_sum(v2, rand() % 1000, f_output);
    auto stop2exact = high_resolution_clock::now();
    auto duration2exact = duration_cast<microseconds>(stop2exact - start2exact);
    f_output << endl << endl << endl;
    f_output << " For Approx Subset Sum 2(for 10 elements):" << endl;
    auto start2approx = high_resolution_clock::now();
    int approx2 = approx_subset_sum(v2, rand() % 1000, 0.90, f_output);
    auto stop2approx = high_resolution_clock::now();
    auto duration2approx = duration_cast<microseconds>(stop2approx - start2approx);
    cout << "Exact time needed: " << (duration2exact.count() / 1000000.0) << " seconds" << endl;
    cout << "Approx time needed: " << (duration2approx.count() / 1000000.0) << " seconds" << endl;
    f_output << endl << endl << endl << endl << endl << endl;


    f_output << " For Exact Subset Sum 3(for 20 elements):" << endl;
    auto start3exact = high_resolution_clock::now();
    int exact3 = exact_subset_sum(v3, rand() % 1000, f_output);
    auto stop3exact = high_resolution_clock::now();
    auto duration3exact = duration_cast<microseconds>(stop3exact - start3exact);
    f_output << endl << endl << endl;
    f_output << " For Approx Subset Sum 3(for 20 elements):" << endl;
    auto start3approx = high_resolution_clock::now();
    int approx3 = approx_subset_sum(v3, rand() % 1000, 0.90, f_output);
    auto stop3approx = high_resolution_clock::now();
    auto duration3approx = duration_cast<microseconds>(stop3approx - start3approx);
    cout << "Exact time needed: " << (duration3exact.count() / 1000000.0) << " seconds" << endl;
    cout << "Approx time needed: " << (duration3approx.count() / 1000000.0) << " seconds" << endl;
    f_output << endl << endl << endl << endl << endl << endl;


    f_output << " For Exact Subset Sum 4(for 50 elements):" << endl;
    auto start4exact = high_resolution_clock::now();
    int exact4 = exact_subset_sum(v4, rand() % 1000, f_output);
    auto stop4exact = high_resolution_clock::now();
    auto duration4exact = duration_cast<microseconds>(stop4exact - start4exact);
    f_output << endl << endl << endl;
    f_output << " For Approx Subset Sum 4(for 50 elements):" << endl;
    auto start4approx = high_resolution_clock::now();
    int approx4 = approx_subset_sum(v4, rand() % 1000, 0.90, f_output);
    auto stop4approx = high_resolution_clock::now();
    auto duration4approx = duration_cast<microseconds>(stop4approx - start4approx);
    cout << "Exact time needed: " << (duration4exact.count() / 1000000.0) << " seconds" << endl;
    cout << "Approx time needed: " << (duration4approx.count() / 1000000.0) << " seconds" << endl;
    f_output << endl << endl << endl << endl << endl << endl;


    f_output << " For Exact Subset Sum 5(for 100 elements):" << endl;
    auto start5exact = high_resolution_clock::now();
    int exact5 = exact_subset_sum(v5, rand() % 1000, f_output);
    auto stop5exact = high_resolution_clock::now();
    auto duration5exact = duration_cast<microseconds>(stop5exact - start5exact);
    f_output << endl << endl << endl;
    f_output << " For Approx Subset Sum 5(for 100 elements):" << endl;
    auto start5approx = high_resolution_clock::now();
    int approx5 = approx_subset_sum(v5, rand() % 1000, 0.90, f_output);
    auto stop5approx = high_resolution_clock::now();
    auto duration5approx = duration_cast<microseconds>(stop5approx - start5approx);
    cout << "Exact time needed: " << (duration5exact.count() / 1000000.0) << " seconds" << endl;
    cout << "Approx time needed: " << (duration5approx.count() / 1000000.0) << " seconds" << endl;
    f_output << endl << endl << endl << endl << endl << endl;
    
    vector<float> y_exact, y_approx;
    y_exact = {(float)(duration1exact.count() / 1000000.0),
               (float)(duration2exact.count() / 1000000.0),
               (float)(duration3exact.count() / 1000000.0),
               (float)(duration4exact.count() / 1000000.0),
               (float)(duration5exact.count() / 1000000.0)};
    y_approx = {(float)(duration1approx.count() / 1000000.0),
               (float)(duration2approx.count() / 1000000.0),
               (float)(duration3approx.count() / 1000000.0),
               (float)(duration4approx.count() / 1000000.0),
               (float)(duration5approx.count() / 1000000.0)};
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
