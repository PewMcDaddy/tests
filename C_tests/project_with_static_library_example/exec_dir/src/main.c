#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "func.h"
#include "other.h"

int main(void)
{
	printf("%s()\n",__func__);
	f();
	return 0;
}

