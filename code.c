#include <stdio.h>
#include <limits.h>

int optimalSearchTree(int keys[], int freq[], int n)
{
    int a, c, i, j, k, m;
    int cost[n][n];

    for(a=0; a<n; a++)
        cost[a][a]=freq[a];

    for(i=2; i<=n; i++){
        for(j=0; j<=n-i+1; j++){

            m = j+i-1;
            cost[j][m]=999;

            for(k=j; k<=m; k++){
                c = ((k>j)? cost[j][k-1]:0) + ((k<m)? cost[k+1][m]:0) + sum(freq, j, m);
                if( c<cost[j][m])
                    cost[j][m]=c;
            }
        }
    }
    return cost[0][n-1];
}

int sum(int freq[], int m, int n)
{
    int i, s = 0;
    for ( i = m; i <=n; i++)
       s = s + freq[i];
    return s;
}

int main()
{
   int i, n;
   printf("====== welcome to OPTIMAL BINARY SEARCH TREE finder ======\n\n");
   printf("\tHow many nodes in the tree : ");
   scanf("%d", &n);

   int keys[n], freq[n];

   printf("\nEnter keys : \n");
   for(i=0; i<n; i++){
        scanf("%d", &keys[i]);
   }
   printf("\nEnter frequency : \n");
   for(i=0; i<n; i++){
        scanf("%d", &freq[i]);
   }

    printf("\n\n\tCost of Optimal BST is : %d \n\n", optimalSearchTree(keys, freq, n));

    return 0;
}

