//ahmad abolil.212261267
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "MatrixList.h"
#define N 5

list matrixs ;//matrixs list


int main(){
	int choise,listsize =0,num,check1,check2;
	char nameA[N],nameB[N];
	printf("Enter the matrix size :");
	if(scanf("%d",&matrixs.n)<=0)return 0;
	matrixs.head=NULL;//start list with null
	matrixs.matcnt=0;

	do{//print choise list
		printf("choise your function :  \n");
		printf("1.Add new Matrix to List .\n");
		printf("2. Delete Matrix from List . \n");
		printf("3.Sum Two Matrixs .\n");
		printf("4.Sub two Matrixs . \n");
		printf("5.Mul two Matrixs . \n");
		printf("6.Power Matrixs . \n");
		printf("7.Print Matrix \n");
		printf("8.Exit \n");
		if(scanf("%d",&choise)<=0)return 0;

		switch (choise) {//make a function
		case 1://add new matrix
			check1 = getMatrixName(nameA);
			if(check1 != 0)
				AddMatrix(nameA);
			break;
		case 2://delete a matrix
			check1 = getMatrixName(nameA);
			if(check1 != 0)
				deleteMatrix(nameA);
			break;
		case 3://sum two matrixs
			check1 = getMatrixName(nameA);
			check2 = getMatrixName(nameB);
			if(check1 != 0 && check2!=0)
				sumMatrixs(nameA,nameB);
			break;
		case 4://sub two matrixs
			check1 = getMatrixName(nameA);
			check2 = getMatrixName(nameB);
			if(check1 != 0 && check2!=0)
				subMatrixs(nameA,nameB);
			break;
		case 5://mul two matrixs
			check1 = getMatrixName(nameA);
			check2 = getMatrixName(nameB);
			if(check1 != 0 && check2!=0)
				mulMatrixs(nameA,nameB);
			break;
		case 6:// pow a matrix
			check1 = getMatrixName(nameA);
			num = getPowNum();
			if(num<10&&check1!=0)
				strongMatrixs(nameA,num);
			break;

		case 7://print matrix
			check1 = getMatrixName(nameA);
			if(check1!=0)
				printMatrix(nameA);
			break;
		default ://false choise
			if(choise!=8)
				printf("ERROR :Invalid input, returning to menu.\n");
			break;
		}



	}while(choise!=8);
}

int getMatrixName(char name[]){
	node_t * tmp1 = matrixs.head,*tmp2;
	scanf("%s",name);//put matrix name
	if(name[0]<'A'||name[0]>'Z'||(name[1]<'0'||name[1]>'9')||strlen(name)>2){//not valid name
		printf("ERROR :Invalid input, returning to menu.\n");
		return 0;
	}
	return 1;

}

int getPowNum(){
	int num;
	scanf("%d",&num);//get a pow number
	if(num>10)//check
		printf("ERROR :Invalid input, returning to menu.\n");
	return num;
}

void deleteMatrix(char name[]){
	node_t * tmp1 = matrixs.head,*tmp2;

	if(tmp1 == NULL)//empty list
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",name);

	else if(strcmp(tmp1->name,name)==0){//found in the head
		matrixs.head = tmp1->next;
		printf("Matrix %s does not exist in the system. Returning to menu.\n",name);
	}
	else{
		tmp2 = tmp1->next;
		while(tmp2){//search on matrix
			if(strcmp(tmp2->name,name)==0){
				tmp1->next = tmp2->next;//delete matrix
				printf("Matrix %s does not exist in the system. Returning to menu.\n",name);
				matrixs.matcnt--;
				return;
			}
			tmp1=tmp2;
			tmp2=tmp2->next;
		}
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",name);
	}

}

void printMatrix(char name[]){

	int i,j;
	node_t *tmp2=matrixs.head;
	if(matrixs.matcnt ==0)return;

	while(tmp2){//search
		if(strcmp(tmp2->name,name)==0)break;
		tmp2=tmp2->next;
	}

	if(tmp2==NULL){//not found
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",name);
		return;
	}
	printf("%s: \n[",name);
	for(i=0;i<matrixs.n;i++){//print
		for(j=0;j<matrixs.n;j++){
			printf("%.2f ",tmp2->matrix[i][j]);
		}
		if(i==matrixs.n-1){
			printf("];");
		}
		printf("\n ");
	}
}

void sumMatrixs(char nameA[],char nameB[]){
	int i,j;
	node_t * tmp=matrixs.head,*tmp2=matrixs.head;
	if(matrixs.matcnt ==0)return;
	while(tmp){//search first one
		if(strcmp(tmp->name,nameA)==0)break;
		tmp=tmp->next;
	}
	while(tmp2){//search second
		if(strcmp(tmp2->name,nameB)==0)break;
		tmp2=tmp2->next;
	}
	if(tmp == NULL){//first not found
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",nameA);
		return;
	}
	if(tmp2==NULL){//second not found
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",nameB);
		return;
	}
	for(i=0;i<matrixs.n;i++)//sum matrixs
		for(j=0;j<matrixs.n;j++)
			tmp2->matrix[i][j]+=tmp->matrix[i][j];
}

void strongMatrixs(char name[],int num){
	int i,j;
	node_t *tmp2=matrixs.head;
	if(matrixs.matcnt ==0)return;
	while(tmp2){//search matrix
		if(strcmp(tmp2->name,name)==0)break;
		tmp2=tmp2->next;
	}

	if(tmp2==NULL){//not found
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",name);
		return;
	}
	for(i=0;i<matrixs.n;i++)//power matrix elemnet
		for(j=0;j<matrixs.n;j++)
			tmp2->matrix[i][j]=pow(tmp2->matrix[i][j],num);
}

void subMatrixs(char nameA[],char nameB[]){
	int i,j;
	node_t * tmp=matrixs.head,*tmp2=matrixs.head;
	if(matrixs.matcnt ==0)return;

	while(tmp){//search first one
		if(strcmp(tmp->name,nameA)==0)break;
		tmp=tmp->next;
	}
	while(tmp2){//search second
		if(strcmp(tmp2->name,nameB)==0)break;
		tmp2=tmp2->next;
	}
	if(tmp == NULL){//first not found
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",nameA);
		return;
	}
	if(tmp2==NULL){//second not found
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",nameB);
		return;
	}

	for(i=0;i<matrixs.n;i++)//sub matrixs
		for(j=0;j<matrixs.n;j++)
			tmp2->matrix[i][j]-=tmp->matrix[i][j];
}


void copyMatrix(double **m,double **res){
	int i,j;
	for(i=0;i<matrixs.n;i++)//copy m in res
		for(j=0;j<matrixs.n;j++)
			m[i][j]=res[i][j];
}

void mulMatrixs(char nameA[],char nameB[]){
	int i,j,k;
	double **res;
	node_t * tmp=matrixs.head,*tmp2=matrixs.head;
	if(matrixs.matcnt ==0)return;
	while(tmp){//search first
		if(strcmp(tmp->name,nameA)==0)break;
		tmp=tmp->next;
	}
	while(tmp2){//search second
		if(strcmp(tmp2->name,nameB)==0)break;
		tmp2=tmp2->next;
	}
	if(tmp == NULL){//first not found
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",nameA);
		return;
	}
	if(tmp2==NULL){//second not found
		printf("ERROR :Matrix %s does not exist in the system. Returning to menu.\n",nameB);
		return;
	}
	res = (double **)malloc(matrixs.n * sizeof(double *));
	for (i = 0; i < matrixs.n; i++)
		res[i] = (double *)malloc(matrixs.n * sizeof(double));
	for (i = 0; i < matrixs.n; i++) {//mul matrixs
		for (j = 0; j < matrixs.n; j++) {
			res[i][j] = 0;
			for (k = 0; k < matrixs.n; k++)
				res[i][j] += tmp->matrix[i][k] * tmp2->matrix[k][j];
		}
	}
	copyMatrix(tmp2->matrix,res);//copy result
}

void AllocateMatrix(node_t *tmp,double **mat){
	int i,j;
	tmp->matrix=(double **)malloc(matrixs.n*sizeof(double *));
	for(i=0;i<matrixs.n;i++)
		tmp->matrix[i] = (double *)malloc(matrixs.n*sizeof(double));

	for(i=0;i<matrixs.n;i++)//copy matrix
		for(j=0;j<matrixs.n;j++)
			tmp->matrix[i][j]=mat[i][j];
}

void AddMatrix(char name[]){
	char newline;
	int i,j;
	node_t * tmp=matrixs.head;
	double ** mat ;

	while(tmp){
		if(strcmp(tmp->name,name)==0){
			printf("ERROR :Matrix %s exist in the system. Returning to menu.\n",name);
			return;
		}
		tmp=tmp->next;
	}
	mat=(double **)malloc(matrixs.n*sizeof(double *));
	for(i=0;i<matrixs.n;i++)
		mat[i] = (double *)malloc(matrixs.n*sizeof(double));

	for(i=0;i<matrixs.n;i++){//get element
		for(j=0;j<matrixs.n;j++){
			scanf("%lf",&mat[i][j]);
		}
		scanf("%c",&newline);
		if(newline != '\n'){
			printf("ERROR :Invalid input, returning to menu.\n");
			return;
		}
	}
	if(matrixs.head == NULL){//insert in list
		matrixs.head = (node_t *)malloc(sizeof(node_t));
		strcpy(matrixs.head->name,name);
		AllocateMatrix(matrixs.head,mat);
		matrixs.head->next =NULL;
		matrixs.matcnt++;
		return;
	}
	tmp=matrixs.head;
	while(tmp->next)tmp=tmp->next;
	tmp->next = (node_t *)malloc(sizeof(node_t));
	strcpy(tmp->next->name,name);
	AllocateMatrix(tmp->next,mat);
	tmp->next->next =NULL;
	matrixs.matcnt++;
}

