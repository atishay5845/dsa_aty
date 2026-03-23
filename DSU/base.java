import java.util.*;

class Disjoint{
    int parent[];
    int rank[];
    Disjoint(int n){
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionNormal(int x,int y){
        
    }

    void unionByRank(int x,int y){

    }
}
