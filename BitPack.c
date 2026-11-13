#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(){
	uint8_t data[] = {1,0,2,2,1,0,2};
	unsigned int length = 7;
	for(int i=0;i<length;i++)printf("%d,", data[i]);
	FILE *f = fopen("wt.dat", "wb");
	uint8_t pack = 0;
	for(int i=0;i<(length/4);i++){
		pack=0;
		for(int j=0;j<4;j++){
			pack = pack << 2;
			pack = pack | data[i*4+3-j];
			if((i*4+j)==(length-1)) break;
		}
		fwrite(&pack, sizeof(uint8_t), 1, f);
	}
	pack = 0;
	for(int j=0;j<(length%4);j++){
		pack = pack << 2;
		pack = pack | data[(length/4)*4+(length%4-1)-j];
		//if((i*4+j)==(length-1)) break;
	}
	fwrite(&pack, sizeof(uint8_t), 1, f);
	fclose(f);
	printf("\n");
	f = fopen("wt.dat", "rb");
	for(int i=0;i<(length/4);i++){
		uint8_t buff[4];
		fread(&pack, sizeof(uint8_t), 1, f);
		for(int j=0;j<4;j++){
			printf("%d,", pack & 3);
			pack = pack >> 2;
		}
	}
	pack=0;
	uint8_t buff[4];
	fread(&pack, sizeof(uint8_t), 1, f);
	for(int j=0;j<(length%4);j++){
		printf("%d,", pack & 3);
		pack = pack >> 2;
	}
	return 0;
}