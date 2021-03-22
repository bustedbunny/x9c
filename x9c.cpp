#include <x9c.h>

x9c::x9c() {
	_pos = 0;
}

void x9c::_dsSave(){
	digitalWrite(_inc,HIGH);          //***********GADGET REBOOT CHANGED******************
	delayMicroseconds(1);             //***********GADGET REBOOT CHANGED******************
	digitalWrite(_cs,HIGH);             // unselect chip and write current value to NVRAM
	delay(20);
}

void x9c::_dsNoSave(){
	digitalWrite(_cs,HIGH);             // unselect chip
	digitalWrite(_inc,HIGH);            // always leave inc high - makes coding cleaner / easier
	delayMicroseconds(1);
}

void x9c::setPot(uint8_t pos){
	if (_pos==pos) {return;
	}
	digitalWrite(_cs, LOW);
	delayMicroseconds(1);
	uint8_t count = pos > 99 ? (count = 99):pos;
	if (count > _pos) {
		digitalWrite(_ud, HIGH);
		while (count != _pos) {
			digitalWrite(_inc, LOW);
			delayMicroseconds(1);
			if ((count - _pos) > 1) {
				digitalWrite(_inc, HIGH);
				delayMicroseconds(1);
			}
			_pos++;
		}
	}
	else if (count < _pos) {
		digitalWrite(_ud, LOW);
		while (count != _pos) {
			digitalWrite(_inc, LOW);
			delayMicroseconds(1);
			if ((_pos - count) > 1) {
				digitalWrite(_inc, HIGH);
				delayMicroseconds(1);
			}
			_pos--;
		}
	}
	_dsSave();
	
}

void x9c::begin(uint8_t cs,uint8_t inc,uint8_t ud, uint8_t pos = 0){
	_cs=cs;
	_inc=inc;
	_ud=ud;
	
	pinMode(_cs,OUTPUT);
	pinMode(_inc,OUTPUT);
	pinMode(_ud,OUTPUT);
	
	digitalWrite(_ud, LOW);
	digitalWrite(_inc, HIGH);
	digitalWrite(_cs, HIGH);
	delayMicroseconds(1);
	digitalWrite(_cs, LOW);
	delayMicroseconds(1);
	uint8_t count = 99;
	while (count--) {
		digitalWrite(_inc, LOW);
		delayMicroseconds(1);
		if (count != 1) {
			digitalWrite(_inc, HIGH);
			delayMicroseconds(1);
		}
	}
	if (pos) {
		uint8_t count2 = pos;
		digitalWrite(_ud, HIGH);
		while (count2--) {
			digitalWrite(_inc, LOW);
			delayMicroseconds(1);
			if (count2 != 1) {
				digitalWrite(_inc, HIGH);
				delayMicroseconds(1);
			}
			_pos++;
		}
		
	}
	delayMicroseconds(100);
	_dsSave();
	return (_pos);
	
}

uint8_t x9c::PotPos() {
	return _pos;
}


