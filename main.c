#include "USB.h"
#include "PID.h"
#include <avr/io.h>
#include "Descriptors.h"
#include <stdint.h>
#include "VirtualSerial.h"
#define F _CPU 16000000UL

int main(){
	uint32_t c;
	c=32;
	USB(c);
	return 0;
}
