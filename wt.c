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

int main(){
	#include "UnitSpec.h"
	printf("tank dmg: %d", t.a);
	return 0;
}