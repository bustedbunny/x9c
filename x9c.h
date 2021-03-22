
#ifndef x9c_h
#define x9c_h
//
// direction "sense" is set between Vh/Rh (pin 3) and Vw/Rw (pin 5) i.e. with x9c104,
//		setPotMin will give abt 220R - 330R between these pins
//      setPotMax should give abt 100k
//
#include <Arduino.h>

//
// stepPot explicilty does NOT save to NVRAM - allows reboot to old NVRAM value, with minor runtime tweaks
//
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
