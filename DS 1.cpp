#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct freq{
	int data;
    struct freq *next;
};
typedef struct node * Stack;
typedef struct freq * Freq ;
Stack push(int x,Stack top){
	Stack temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->num=x;
	temp->next=top;
	top=temp;
	return top;
}
Freq Push(int x,Freq head){
	Freq temp;
	temp=(struct freq*)malloc(sizeof(struct freq));
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
} 
void removedupilcates(Freq head){
	Freq p1=head,temp;
	if(p1 == NULL)
		return;
	while(p1->next!=NULL){
		if(p1->data==p1->next->data){
			temp=p1->next->next;
			free(p1->next);
			p1->next=temp;
		}
		else{
			p1=p1->next;
		}
	}
}
int search(int x,Stack top){
	Stack t=top;
	int count = 0;
    while (t!=NULL)
    {
        if (t->num==x)
        {
            count++;
        }
        else
        {
            t=t->next;
        }
    }
    return count;
	
}
void display(Stack top){
	Stack t=top;
	if(t!=NULL){
		while(t!=NULL){
			printf("%d  ",t->num);
			t=t->next;
		}
	}
	else{
		printf("\nStack is Empty.");
	}
}
void Disp(Freq head,Stack top){
	int r,x;
	printf("\n\nDisplaying Dup : ");
	Freq t=head;
	if(t!=NULL){
		while(t!=NULL){
			printf("\n%d       ",t->data);
			x=t->data;
			r=search(x,top);
			printf("%d       ",r);
			t=t->next;
		}
	}
	else{
		printf("\nStack is Empty.");
	}
}
int main(){
	Stack top = NULL;
	Freq head = NULL;
	int e,ch;#include<stdio.h>
#include<stdlib.h>
struct node{
	int * numb;
	int size;
	int * point;
};
typedef struct node * chef;
chef create(int max,chef c){
	c=(struct node *)malloc(sizeof(struct node));
	c->size=max;
	c->point=(int *)malloc(sizeof(int)*max);
	c->numb=(int *)malloc(sizeof(int)*max);
	for(int i=0;i<max;i++){
		c->numb[i]=i+1;
	}
	return c;
}
void insert(chef c){
	int i,m;
	for(i=0;i<c->size;i++){
		scanf("%d",&m);
		c->point[i]=m;
	}
}
void disp(chef c){
	for(int i=0;i<c->size;i++){
		printf("%d\t%d\n",c->numb[i],c->point[i]);
	}
}
chef compare(int a,int b,chef c){
	int p1=c->point[a-1],p2=c->point[b-1];
	if(p1<p2){
		c->numb[a-1]=b;
	}
	else{
		c->numb[b-1]=a;
	}
	return c;
}
void result(int y,chef c){
	printf("%d",(c->numb[y-1]));
}
int main(){
	chef c=NULL;
	int max,x,y,a,b;
	printf("Enter the No of Chef's : ");
	scanf("%d",&max);
	c=create(max,c);
	printf("Enter the Point's for Chef's : \n");
	insert(c);
	disp(c);
	
	do{
	printf("\n*********Menu*********\n1.Compare\n2.Result");
	scanf("\n%d",&x);
	if(x==0){
		printf("Enter the Number to Compare : ");
		scanf("%d",&a);
		printf("Enter the Another Number to Compare : ");
		scanf("%d",&b);
		c=compare(a,b,c);
		printf("Compare Successfully!!!\n\n");
	}
	if(x==1){
		printf("Enter the Number to print Result : ");
		scanf("%d",&y);
		printf("The Chef of the Dish is : ");
		result(y,c);
	}
	}while(x<2);
	return 0;
}
	do
    {
    	printf("Enter the Number : ");
    	scanf("%d",&e);
		top=push(e,top);
		head=Push(e,head);
		printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
	}while(ch!=0);
	removedupilcates(head);
	display(top);
	Disp(head,top);
}
