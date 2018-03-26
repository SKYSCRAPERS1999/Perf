#include <stdio.h>
int main(){
	void* fp = (void*)puts;
	fp("hello world\n");
	return 0;
}
