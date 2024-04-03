#include<stdio.h>
typedef enum {
	start,
	state_0,
	state_01,
	state_010,
} fsm_state;

void Check(int input) {
	static fsm_state currentstate = start;
	switch (currentstate) {
	
	case start:
		if (input == 0)
			currentstate = state_0;
		else currentstate = start;
		break;
	case state_0:
		if (input == 1)
			currentstate = state_01;
		else currentstate = state_0;
		break;
	case state_01:
		if (input == 0)
			currentstate = state_010;
		else currentstate = start;
		break;
	case state_010:
		if (input == 0) currentstate = state_0;
		else currentstate = state_01;
		break;
	
	}
	if (currentstate == state_010) printf("output = 1\n");
	else printf("output = 0\n");
	

}
int main() {
	int dauvao;
	void(* ptr)(int);
	ptr = Check;
	while (1) {
		(*ptr)(dauvao);
		printf("Nhap: ");
		scanf("%d", &dauvao);
		
	}
	return 0;
}
