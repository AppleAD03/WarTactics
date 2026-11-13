#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

typedef unsigned int ui;

typedef struct Unit{
	ui h;
	ui d;
	ui r;
	ui a;
}Unit;

void fight(Unit *t1, Unit *t2, ui *num1, ui *num2);
ui tournament(Unit *t1, Unit *t2);

int main(){
	#include "UnitSpec.h"
	printf("tank dmg: %d", t.a);
	return 0;
}

void fight(Unit *t1, Unit *t2, ui *num1, ui *num2){
	for(int i=5-(*num1);i<5;i++){
		if(i<=t2[i].r)
			t1[5-(*num1)].h-=(t2[i].d-t1[i].a);
	}
	for(int i=5-(*num2);i<5;i++){
		if(i<=t1[i].r)
			t2[5-(*num2)].h-=(t1[i].d-t2[i].a);
	}
	if(t1[5-(*num1)].h<=0) --(*num1);
	if(t2[5-(*num2)].h<=0) --(*num2);
}

ui tournament(Unit *t1, Unit *t2){
	ui num1=5;
	ui num2=5;
	while(true){
		fight(t1, t2, &num1, &num2);
		if((num1==0) && (num2 >0)) return 0;
		if((num1 >0) && (num2==0)) return 1;
		if((num1==0) && (num2==0)) return 2;
	}
}