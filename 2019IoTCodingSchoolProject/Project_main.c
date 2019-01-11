/***********************************
 *  file name: Project_main.c
 *	Author: r0ya1je11y
 *  Created on: 2019. 1. 11.
 *  Release date: 2019. 1. 11.
 *  version: 1.0
 ***********************************/

#include <tinyara/config.h>
#include <apps/shell/tash.h>
#include <stdio.h>
#include <time.h>
#include "hext.h"
#include "keys.h"
#include "A053BasicKit.h"



int Detect_IR(int argc, FAR char *argv[]){
	int32_t val;
	int i;
	int pin_ir;
	int max = 0;
	char *adc0 = "0";
	char *adc1 = "1";

	max = atoi(argv[3]);

	if (strcmp(argv[2], adc0)==0 )
	{
		pin_ir = A0;
	}
	else if (strcmp(argv[2], adc1)==0 )
	{
		pin_ir = A2;
	}
	else
	{
		show_help_basic_hext(argv);
	}

	val = read_adc(pin_ir);

	if(val > 500){
		return 1;
	}
	else {
		return 0;
	}
}

int Detect_User(int argc, FAR char *argv[]){
	int init_time, present;
	time(&init_time);
	while(difftime(time(&present), init_time) <= 3000){
		if(Detect_IR(argc, argv) == 0){
			return 0;
		}
	}
	return 1;
}





int main(int argc, FAR char *argv[]){
	int state = 0;
	while(1){
		state = Detect_User(argc, argv);
		if (state == 1){

		}

		up_medelay(2000);

	}
}

