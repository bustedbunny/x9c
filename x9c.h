
#ifndef x9c_h
#define x9c_h

#include <Arduino.h>

class x9c {
public:
	x9c();
	void begin(uint8_t cs,uint8_t inc,uint8_t ud, uint8_t pos = 0);
	void setPot(uint8_t pos);
	uint8_t PotPos();
private:
	uint8_t _cs, _inc, _ud;
	uint8_t _pos;
	void _dsSave();
	void _dsNoSave();
};

#endif // X9C_H
