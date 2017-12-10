#include "main.h"

int main(void)
{	
  uint8_t i = 0;
	
	i = 0;
	
	g_fnAppTaskAry[i++]();
	
	
	for(;;){
		g_fnAppTaskAry[i++]();
		if(i >= APP_MAX_FUNCITEM ){
			i = 1;
		}
	}

}

