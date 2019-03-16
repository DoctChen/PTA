# include<stdio.h>
struct student{
	char name[15];
	char num[15];
	int grade;
}stu[1050];
int main(void){
	freopen("in.txt", "r", stdin);
	int n;
	while(scanf("%d", &n)!=EOF){
		int max = -1, min = 101;
		for(int i=0;i<n;++i){
			scanf("%s %s %d", stu[i].name, stu[i].num, &stu[i].grade);
		}
		for(int i=0;i<n;++i){
			if(max<stu[i].grade)
				max = stu[i].grade;
			if(min>stu[i].grade)
				min = stu[i].grade;
		}
		for(int j=0;j<n;++j){
			if(max == stu[j].grade)
				printf("%s %s\n", stu[j].name, stu[j].num);
		}
		for(int j=0;j<n;++j){
			if(min == stu[j].grade)
				printf("%s %s\n", stu[j].name, stu[j].num);
		}
	}
	return 0; 
}
