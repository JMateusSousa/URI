#include <stdio.h>
#include <stdlib.h>
int sum=0;

typedef struct aux{
	int chave;
	struct aux *left, *right;
}NO;

typedef NO* PONT;

PONT newno(int ch){
	PONT newn= (PONT)malloc(sizeof(NO));
	newn->left=NULL;
	newn->right=NULL;
	newn->chave=ch;
	return (newn);
}

PONT add(PONT raiz, PONT no){
	if(raiz==NULL){
		return no;
	}
	if(no->chave < raiz->chave){
		raiz->left=add(raiz->left,no);
	}
	else
		raiz->right=add(raiz->right,no);
		
	return raiz;
}


PONT search(int ch, PONT raiz){
	if(raiz==NULL){
		return NULL;
	}
	else if(raiz->chave == ch){
		return raiz;
	}
	else if(raiz->chave > ch){
		sum+=raiz->chave;
		printf("SUM =  %d",sum);
		return search(ch, raiz->left);
	}
	else{
		return search(ch, raiz->right);
	}
	
}

PONT search_no(PONT raiz, int ch, PONT *pai){
	PONT atual = raiz;
	*pai=NULL;
	while(atual){
		if(atual->chave==ch){
			return atual;
			*pai = atual;
		}
		else if(ch < atual->chave){
			atual = atual->left;
		}
		else{
			sum=0;
			atual = atual->right;
		}
	}
	return NULL;
}
PONT re(int ch, PONT raiz){
	PONT pai, no, p, q;
	no = search_no(raiz,ch,&pai);
	if(no==NULL){
		return raiz;
	}
	else if(!no->left || !no->right){
		if(!no->left){
		q=no->right;
		}
		else{
			q=no->left;
		}
	}
	else{
		p=no;
		q=no->left;
		while(q->right){
			p=q;
			q= q->right;
		}
		if(p != no){
			p->right = q->left;
			q->left=no->left;
		}
		q->right=no->right;
	}
	if(!pai){
		free(no);
		return q;
	}
	if(ch < pai->chave){
		pai->left=q;
	}
	else{
		pai->right=q;
	}
	free(no);
	return raiz;
}


int main(){
	int n,j,i=0;
	char t;
	PONT three;
	three=NULL;
	printf("LUL");
	scanf("%d",&n);
	int v[n];
	while(i<n){
		scanf("%d",&v[i]);
		printf("teste %d\n",i);
		newno(v[i]);
		add(three,three);
		i++;
	}
	while(1){
		printf("Digite");
		scanf("%c",&t);
		scanf("%d",&j);
		if(t=='a'){
			re(v[j-1],three);
		}
		if(t=='?'){
			search(v[j-1],three);
			printf("%d\n",sum);
		}
	}
	printf("%d\n",sum);
	
	return 0;
}


