# AUTHOR: HAOCHEN GOU


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void eliminate(int row,int col);
void solve(void);
void fill(void);
int total_zero,a[9][9];
int check[9]= {1,2,3,4,5,6,7,8,9};
int row,col;

int main(void){
  	total_zero = 0;
  	for(row=0;row<9;row++){
    	for(col=0;col<9;col++){
      		if (scanf("%d", &a[row][col]) != 1){ 
				return -1;
      			}
      		}
      	}
    for(row=0;row<9;row++){
    	for(col=0;col<9;col++){
      		if(a[row][col]==0){
				total_zero+=1;
      			}		
   		 	}
  		}	
  	fill();
    return 0; 
}			

void fill(void){
  	int num_zero,i;
  	for(row=0;row<9;row++){
    	for(col=0;col<9;col++){
      		if (a[row][col] == 0){
				num_zero = 0;
				eliminate(row,col);
				for (i=0;i<9;i++){
	  				if(check[i]==0){
	    				num_zero+=1;
	  					}
					}	
				if (num_zero == 8){
	  				for (i=0;i<9;i++){
	    				if(check[i]!=0){
	      					a[row][col] = check[i];
	      					total_zero-=1;
	    					}
					  	}
					}
     			 }
     		int num = 1;
     		for (i=0;i<9;i++){
     			check[i]=num;
     			num++;
     		}
    	}
  	}
	if (total_zero != 0){
   		fill();
 		}
 	else{
 	  solve();
 		}	
}

void eliminate(int row,int col){
   	int r_1,r_2,c_1,c_2,m,i;
   	for (m = 0;m<9;m++){
    	 for(i = 0; i<9;i++){
       		if (check[i]==a[row][m]||check[i]==a[m][col]){
	 			check[i]=0;		 	
       			}
     		}
   		}
   	if (row%3 == 0){
    	r_1 = row+1;
     	r_2 = row+2;
   	}
   	else if (row%3 == 1){
     	r_1 = row-1;
     	r_2 = row+1;
   	}
   	else if (row%3 == 2){
     	r_1 = row-1;
     	r_2 = row-2;
   	}
   	if (col%3 == 0){
     	c_1 = col+1;
     	c_2 = col+2;
   	}
   	else if (col%3 == 1){
     	c_1 = col-1;
     	c_2 = col+1;
   	}
   	else if (col%3 == 2){
     	c_1 = col-1;
     	c_2 = col-2;
   	}
   	for( i = 0; i<9;i++){
     	if (check[i] == a[r_1][c_1]||check[i]==a[r_1][c_2]){
       	check[i]=0;
     	}
   	}
   	for(i = 0; i<9;i++){
     	if (check[i] == a[r_2][c_1]||check[i]==a[r_2][c_2]){
       	check[i]=0;
     	}
   	}
}

void solve(){
	printf("\n");
   	for(row=0;row<9;row++){
   		printf("\n");
     	for(col=0;col<9;col++){
       		printf("%d ", a[row][col]);
     }
   }
   	printf("\n");
}
