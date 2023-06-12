#include<stdio.h>

int order[10];
int visit[10];
int a[10][10], n;
int s[10], top;

void topsort()
{
    int indegree[10], order[10];
    int i, j, k, v;
    top = -1;
    for(i=1;i<=n;i++)
        indegree[i] = 0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            indegree[j]++;

    for(i=0;i<=n;i++)
        if(indegree[i]==0)
            push(i);
    
    v=0;

    while(!isempty())
    {
        k = pop();
        order[v++] = k;
        for(j=1;j<=n;j++)
        {
            if(a[k][j] == 1)
                indegree[j]--;
            if(indegree[j]==0)
                push(j);
        }
    }
    if(v==n)
        printf("Topological sorting is possibel\n");
    else
        printf("Not possible\n");
    
    for(j=0;j<n;j++)
        printf("%d", order[j]);
    
}

void push(int i)
{
    s[++top] = i;
}

int pop()
{
    int x;
    x = s[top--];
    return x;
}

int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void dfs(int v)
{
    int w, k;
    visit[v]=1;
    for(w=1;w<=n;w++)
    {
        if(a[v][w]==1 && visit[w]==0)
            dfs(w);
    }
    order[k++] = v;
}
 
int main()
{

}