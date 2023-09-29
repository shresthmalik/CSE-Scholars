//The following code written by Shresth Malik performs Process
//Scheduling algorithms only where all the processes are ready
//i.e. ALL processes have an arrival time = 0

#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){//assists the sorting function
    return a[2] < b[2] ;
}

void sjf_sort(vector<vector<int>> &mat){//sorts the processes in increasing order of Burst Time
    sort(mat.begin(), mat.end() ,cmp);
}

int main(){

    freopen("input.txt","r",stdin);
    /* Example input for text file (to be saved in the same folder as this cpp file)
    4
    1 0 7
    2 0 4
    3 0 6
    4 0 3
    */

    int n; cin>>n;
    vector<vector<int>> mat(n,vector<int>(5,0));
    //matrix represents columns P_ID, AT, BT, WT, TAT

    for(int i=0;i<n;++i){
        for(int j=0;j<3;++j){
            cin >> mat[i][j] ;
        }
    }

    //Comment the function call below will get you a First Come First Serve Algo
    //Not commenting will give you a Shortest Job First Algo (Non Preemptive)
    sjf_sort(mat);

    //waiting time
    mat[0][3] = 0 ;//waiting time of 1st operation is zero
    for(int i=1;i<n;++i){
        mat[i][3] = mat[i-1][3] + mat[i-1][2]; // WT = WTprev + BTprev
    }

    for(int i=0;i<n;++i){
        mat[i][4] = mat[i][3] + mat[i][2]; // TAT = WT + BT
    }

    cout<<"P_ID    AT     BT      WT     TAT\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<5;++j){
            cout<<mat[i][j]<<"\t";
        }cout<<endl;
    }

    //gantt chart
    cout<<"\nGantt Chart shown below :\n";
    cout<<"0";
    for(int i=0;i<n;++i){
        cout<<" p"<<mat[i][0]<<" "<<mat[i][4];
    }cout<<endl;
}
