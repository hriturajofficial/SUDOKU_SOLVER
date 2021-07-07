#include <iostream>
#include <set> 
#include <iterator>
#include <bitset> 
#include <bits/stdc++.h> 
using namespace std;
typedef  long long int ll;
ll mod=1000000007;
int N;
int mat[9][9];
int ans[9][9];
vector <set<int>> tru(9); 
int arr [] = {0,3,6};
vector <pair<int,int>> v;
void f(int level){
    
    
    //BASE CASE
    if(level==N)
    {   for(int j=0;j<N;j++){
            set <int> col;
            for(int i=0;i<N;i++){
                    col.insert(mat[i][j]);
                    
            }
            if(col.size()!=9)
                return ;
        }
        for(int l = 0;l<9;l++){
        pair<int,int> p = v[l];
        int x = p.first;
        int y=p.second;
        set <int > st;
        
        	for(int i=x;i<x+3;i++){
            	for(int j=y;j<y+3;j++){
                	if(mat[i][j]!=0 && st.find(mat[i][j])!=st.end()){
                    	return ;
					}
                	else if(mat[i][j]!=0 && st.find(mat[i][j])==st.end()){
                    	st.insert(mat[i][j]);
                	}
            	}
        	}
        
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans[i][j] = mat[i][j];
            }
        }
        return;
    }
    
    //PRUNING
    int flag = 1;
    for(int j=0;j<N;j++ ){
        set <int> m ;
        for(int i=0;i<=level;i++){
            if(m.find(mat[i][j])==m.end()){
                m.insert(mat[i][j]);
            }
            else{
                flag=0;
                break;
            }
        }
    }
   
    if(!flag){
        return;
    }
    for(int l = 0;l<9;l++){
        pair<int,int> p = v[l];
        int x = p.first;
        int y=p.second;
        set <int > st;
        flag=1;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(mat[i][j]!=0 && st.find(mat[i][j])!=st.end()){
                    flag=0;
                    return ;
                    //break;
                }
                else if(mat[i][j]!=0 && st.find(mat[i][j])==st.end())
                {
                    st.insert(mat[i][j]);
                }
            }
        }
        
    }
    
    vector <int> b;
    int a[10]={0};
    for(int i=0;i<N;i++){
        a[mat[level][i]] = 1;
    }
    
    
    for(int i=1;i<=N;i++){
        if(a[i]==0){
            b.push_back(i);
        }
    }
    
    do{ 
        int k =0;
       
        for(int i=0;i<N;i++){
            if(tru[level].find(i)!=tru[level].end()){
                
                mat[level][i] = b[k];
                
                k++;
            }
            
            
        }
       
        f(level+1);
        for(int i=0;i<N;i++){
            if(tru[level].find(i)!=tru[level].end()){
                mat[level][i] = 0;
            }
        }
         
    } while(next_permutation(b.begin(),b.end()));
    
    return;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>mat[i][j];
            if(mat[i][j] ==0){
                tru[i].insert(j);
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            v.push_back({arr[i],arr[j]});
        }
    }
    f(0);
    cout<<"\n"<<"\n";
    cout<<"SOLUTION : "<<"\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

