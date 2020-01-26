#include<stdio.h>
//#include<cstd.h>
int sum=0;
struct node{
    int arr[8][8];
    int row;
    int column;
    struct node *next;
};
void print(struct node *a){
    int i,j;
    for( i=0;i<8;i++){
        for( j=0;j<8;j++){
            printf("%d ",a->arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int valid(struct node *a){
    int i,j;
    for(i=0;i<(a->row);i++){
        if(a->arr[i][a->column]==1){
            return 0;
        }
    }
    for( i=a->row-1,j=a->column-1;i>=0&&j>=0;i--,j--){
        if(a->arr[i][j]==1){
            return 0;
        }
    }
    for( i=a->row-1,j=a->column+1;i>=0&&j>=0;i--,j++){
        if(a->arr[i][j]==1){
            return 0;
        }
    }
    return 1;
}
void Queen8(struct node *a){
    int i,j,k,l;
    //printf("in queen\n");
    struct node *last;
    last=(struct node *)malloc(sizeof(struct node));
    int t=1;
    while(a->row<8){

        //printf("in while\n");
        for( i=0;i<8;i++){
            //printf("in for\n");
            struct node *b;
            b=(struct node *)malloc(sizeof(struct node));
            for( j=0;j<8;j++){
                for( k=0;k<8;k++){
                    b->arr[j][k]=a->arr[j][k];
                }
            }
            b->row=a->row+1;
            b->column=i;
            b->arr[b->row][i]=1;
            if(t==1&&valid(b)){
                sum++;
                a->next=b;
                last=b;
                last->next=NULL;
                t=0;
            }else if(valid(b)){
                sum++;
                last->next=b;
                last=b;
                last->next=NULL;
            }

        }
        if(a->next!=NULL)
            a=a->next;
        if(a->row==7){
            print(a);
            printf("total node explored : %d",sum);
            return;
        }
    }
}
int main(){
    int i,j;
    struct node *a;
    a=(struct node *)malloc(sizeof(struct node));
    for( i=0;i<8;i++){
        for(j=0;j<8;j++){
            a->arr[i][j]=0;
        }
    }
    a->row=-1;
    a->next=NULL;
    Queen8(a);
    return 0;
}
