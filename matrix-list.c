
#ifndef MATRIXLIST_H_
#define MATRIXLIST_H_

typedef struct node {
    char name[3];
    double ** matrix;
    struct node * next;
} node_t;

typedef struct{
	int n,matcnt;
	node_t *head;
}list;
/*
 * @input :
 * name : matrix name
 * todo : get the matrix name from the client
 * */
int getMatrixName(char name[]);
/*
 * return the power number from the client */
int getPowNum();
/*
 * @input :
 * name : matrix name
 * todo : delete matrix from list
 */
void deleteMatrix(char name[]);
/*
 * @input :
 * name : matrix name
 * print matrix from list
 */
void printMatrix(char name[]);
/*
 * @input :
 * nameA : matrix A name
 * nameB : matrix B name
 * sum B=A+B*/
void sumMatrixs(char nameA[],char nameB[]);
/*
 *@input :
 * name : matrix name
 * num: power num
 * power A=A^num*/
void strongMatrixs(char name[],int num);
/*
 *@input :
 * nameA : matrix A name
 * nameB : matrix B name
 * sum B=A-B */
void subMatrixs(char nameA[],char nameB[]);
/*
 * input :
 * m : matrix to
 * res : matrix from
 * put matrix from elemnet in matrix to*/
void copyMatrix(double **m,double **res);
/*
 *@input :
 * nameA : matrix A name
 * nameB : matrix B name
 * sum B=A*B */
void mulMatrixs(char nameA[],char nameB[]);
/*
 *@input :
 * name : matrix  name
 * put the matrix in the list if the name not exist*/
void AddMatrix(char name[]);


#endif /* MATRIXLIST_H_ */
