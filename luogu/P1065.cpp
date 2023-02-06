#include<bits/stdc++.h>
using namespace std;
int m,n,order[410],machine_no[45][45],process_time[45][45],op[45],timeline[45][8010],last_time[45]; // 8010:所有工序都在同一个机器上 
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m*n;i++)scanf("%d",&order[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&machine_no[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&process_time[i][j]);
	for(int i=1;i<=m*n;i++)
		for(int no=order[i],mno=machine_no[no][++op[no]],tm=process_time[no][op[no]],t=1;/*不必检验*/;t++){
			int is_spare=1;
			for(int j=t;j<=t+tm-1;j++)is_spare&=!timeline[mno][j];
			if(!is_spare||t<=last_time[no])continue;
			for(int j=t;j<=t+tm-1;j++)timeline[mno][j]=1;
			last_time[no]=t+tm-1;
			break;
		}
	printf("%d\n",*max_element(last_time+1,last_time+n+1));
	return 0;
}
