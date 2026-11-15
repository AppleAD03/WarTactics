#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

typedef unsigned int ui;

typedef struct Unit{
	int h;
	ui d;
	ui r;
	ui a;
}Unit;

void fight(Unit *t1, Unit *t2, ui *num1, ui *num2);
uint8_t tournament(Unit *t1, Unit *t2);

int main(){
	#include "UnitSpec.h"
	Unit u[3] = {s, a, t};
	FILE *f = fopen("wt.dat", "wb");
	for(int m=0;m<3;m++){
	for(int l=0;l<3;l++){
	for(int k=0;k<3;k++){
	for(int j=0;j<3;j++){
	for(int i=0;i<3;i++){
		int mm=m;
		bool ol = true;int ll;
		bool ok = true;int kk;
		bool oj = true;int jj;
		bool oi = true;int ii;
		while(mm<3){if(ol){ll=l;ol=false;} else ll=0;
		while(ll<3){if(ok){kk=k;ok=false;} else kk=0;
		while(kk<3){if(oj){jj=j;oj=false;} else jj=0;
		while(jj<3){if(oi){ii=i;oi=false;} else ii=0;
		while(ii<3){
			Unit t1[5] = {u[i], u[j], u[k], u[l], u[m]};
			Unit t2[5] = {u[ii], u[jj], u[kk], u[ll], u[mm]};
			uint8_t score = tournament(t1, t2);
			fwrite(&score, sizeof(uint8_t), 1, f);
		ii++;}
		jj++;}
		kk++;}
		ll++;}
		mm++;}
	}
	}
	}
	}
	}
	printf("Exact bytes written: %ld\n", ftell(f));
	fclose(f);
	printf("file written and closed");
	return 0;
}

void fight(Unit *t1, Unit *t2, ui *num1, ui *num2){
	for(int i=5-(*num2);i<5;i++){
		if(i<= (t2[i].r+(5-(*num2))) )
			t1[5-(*num1)].h-=(t2[i].d-t1[5-(*num1)].a);
	}
	for(int i=5-(*num1);i<5;i++){
		if(i<= (t1[i].r+(5-(*num1))) )
			t2[5-(*num2)].h-=(t1[i].d-t2[5-(*num2)].a);
	}
	if(t1[5-(*num1)].h<=0) --(*num1);
	if(t2[5-(*num2)].h<=0) --(*num2);
}

uint8_t tournament(Unit *t1, Unit *t2){
	ui num1=5;
	ui num2=5;
	while(true){
		fight(t1, t2, &num1, &num2);
		if((num1==0) && (num2 >0)) return 0;
		if((num1 >0) && (num2==0)) return 1;
		if((num1==0) && (num2==0)) return 2;
	}
}