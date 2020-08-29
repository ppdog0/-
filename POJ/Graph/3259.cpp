// #include<stdio.h>
// #define INF 0x7fffffff
// int F, N, M, W;
// int dis[10000], bak[10000];
// int u[10000], v[10000], t[10000];
// int main() {
//     scanf("%d", &F);
//     while(F--)
//     {
//         scanf("%d%d%d", &N, &M, &W);
//         for (int i = 1; i <= M; i++)
//             scanf("%d%d%d", &u[i], &v[i], &t[i]);
//         for (int i = M+1; i <= M + W;i++)
//         {
//             scanf("%d%d%d", &u[i], &v[i], &t[i]);
//             t[i] = -t[i];
//         }
//         for (int i = 1; i <= N; i++)
//             dis[i] = INF;
//         dis[1] = 0;
//         for (int k = 1; k < N; k++)
//         {
//             for (int i = 1; i <= N; i++)
//                 bak[i] = dis[i];
//             for (int i = 1; i <= M; i++)
//             {
//                 if(dis[v[i]] > dis[u[i]] + t[i])
//                     dis[v[i]] = dis[u[i]] + t[i];
//                 if(dis[u[i]] > dis[v[i]] + t[i])
//                     dis[u[i]] = dis[v[i]] + t[i];
//             }
//             for (int i = M+1; i <= M + W; i++)
//             {
//                 if(dis[v[i]] > dis[u[i]] + t[i])
//                     dis[v[i]] = dis[u[i]] + t[i];
//             }
//             int check = 0;
//             for (int i = 1; i <= N; i++)
//                 if(bak[i]!=dis[i])
//                 {
//                     check = 1;
//                     break;
//                 }
//             if(check==0)
//                 break;
//         }
//         int flag = 0;
//         for (int i = 1; i <= M; i++)
//             if(dis[v[i]] > dis[u[i]] + t[i])
//                 flag = 1;
//         if(flag)
//             printf("YES\n");
//         else
//             printf("NO\n");
//     }
//     return 0;
// }

// #include<stdio.h>
// #define INF 0x3f3f3f3f
// int dis[10000], bak[10000];
// int u[10000], v[10000], t[10000];
// int f, n, m, w;
// int main()
// {
//     scanf("%d",&f);
//     while(f--)
//     {
//         scanf("%d%d%d",&n,&m,&w);
//         for(int i=1;i<=m;i++)
//             scanf("%d%d%d",&u[i],&v[i],&t[i]);
//         for(int i=m+1;i<=m+w;i++)
//         {
//             scanf("%d%d%d",&u[i],&v[i],&t[i]);   //虫洞时间是负的·且单向
//             t[i]=-t[i];
//         }
//         for(int i=1;i<=n;i++)
//             dis[i]=INF;
//         dis[1]=0;
//         for(int k=1;k<n;k++)
//         {
//             for(int i=1;i<=n;i++)bak[i]=dis[i];  //将dis数组备份，可省时，提前跳出循环
//             for(int i=1;i<=m;i++)
//             {   
//                 if(dis[v[i]]>dis[u[i]]+t[i])    //农场两个方向都要判断
//                     dis[v[i]]=dis[u[i]]+t[i];
//                 if(dis[u[i]]>dis[v[i]]+t[i])
//                     dis[u[i]]=dis[v[i]]+t[i];
//             }
//             for(int i=m+1;i<=m+w;i++)
//             {
//                 if(dis[v[i]]>dis[u[i]]+t[i])    //注意！！！！！！！！！！！！！从v[i]-u[i]是正的，方向别弄错了。。
//                     dis[v[i]]=dis[u[i]]+t[i];
//             }
//             int check=0;
//             for(int i=1;i<=n;i++)
//                 if(bak[i]!=dis[i])
//             {
//                 check=1;
//                 break;
//             }
//             if(check==0)break;
//         }
//         int flag=0;
//         for(int i=1;i<=m;i++)               //虫洞不用判断，因为本身就是负的，判断m就好了.加上也行。
//             if(dis[v[i]]>dis[u[i]]+t[i])flag=1;
//         if(flag)
//             printf("YES\n");
//         else printf("NO\n");
//     }
//     return 0;
// }