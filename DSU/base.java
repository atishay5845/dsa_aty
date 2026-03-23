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
        int rootx = find(x);
        int rooty = find(y);

        if(rootx!=rooty){
            parent[rooty] = rootx;
        }
    }

    void unionByRank(int x,int y){
        int rootx = find(x);
        int rooty = find(y);

        if(rootx==rooty)return;
        if(rank[rootx]<rank[rooty]){
            parent[rootx] = rooty;
        }else if(rank[rootx]>rank[rooty]){
            parent[rooty] = rootx;
        }else{
            parent[rootx] = rooty;
            rank[rooty]++;
        }

    }
}

public static Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Disjoint ds = new Disjoint(n);
        ds.unionByRank(0,1);
        ds.unionByRank(1,4);
        ds.unionByRank(2,4);
        ds.unionByRank(2,5);

        // wheather 2 ele belong to same group or not
        if(ds.find(1)==ds.find(4)){
            System.out.print("1 nad 4 belong to same group");
        }else{
            System.out.print("1 nad 4 do not belong to same group");
        }
    }
}