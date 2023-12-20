#include "stdafx.h"
#include <stdio.h>
#include <conio.h>


#define ON_AREA1 1
#define ON_AREA2 2
#define ON_AREA3 3
#define ON_AREA4 4
#define ON_AREA5 5
#define ON_AREA6 6
#define ON_LINE1 7
#define ON_LINE2 8
#define ON_LINE3 9
#define ON_CENTER 10

int place(float x, float y);
void print(int result);

int main(){
	float x, y;
	printf("Enter x and y:\n");
	if (scanf("%f%f", &x, &y)!=2){
		printf("Error\n");
		getch();
		return 1;
	}
	int result = place(x,y);
	print(result);
	getch();
	return 0;
}
int place(float x, float y){
	float y1 = x + 2;
	float y2 = -0.5 * x - 1;
	float y3 = -2 * x + 2;

	if (y>y1 && y>y2 && y>y3) return ON_AREA1;
	else if (y>y1 && y>y2 && y<y3) return ON_AREA2;
	else if (y>y1 && y<y2 && y<y3) return ON_AREA3;
	else if (y<y1 && y<y2 && y<y3) return ON_AREA4;
	else if (y<y1 && y<y2 && y>y3) return ON_AREA5;
	else if (y<y1 && y>y2 && y>y3) return ON_AREA6;
	else if (y==y1) return ON_LINE1;
	else if (y==y2) return ON_LINE2;
	else if (y==y3) return ON_LINE3;
	return ON_CENTER;
}

void print(int result){
	switch (result){
	case ON_AREA1:
		printf("Area 1\n");
		break;
	case ON_AREA2:
		printf("Area 2\n");
		break;
	case ON_AREA3:
		printf("Area 3\n");
		break;
	case ON_AREA4:
		printf("Area 4\n");
		break;
	case ON_AREA5:
		printf("Area 5\n");
		break;
	case ON_AREA6:
		printf("Area 6\n");
		break;
	case ON_LINE1:
		printf("y = x+2\n");
		break;
	case ON_LINE2:
		printf("y = -0.5x-1\n");
		break;
	case ON_LINE3:
		printf("y = -2x+2\n");
		break;
	case ON_CENTER:
		printf("Center\n");
		break;
	default:
		printf("%d\n", result);
	}
}
