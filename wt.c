#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef unsigned int ui;

typedef struct Unit{
	ui h;
	ui d;
	ui r;
	ui a;
}Unit;

void fight(Unit *t1, Unit *t2);

int main(){
	#include "UnitSpec.h"
	printf("tank dmg: %d", t.a);
	return 0;
}

void fight(Unit *t1, Unit *t2){
	for(int i=0;i<5;i++){
		if(i<=t2[i].r)
			t1[0].h-(t2.[i].d-t1[i].a);
		if(i<=t1[i].r)
			t2[0].h-(t1.[i].d-t2[i].a);
	}
	
}