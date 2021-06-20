/*
    DacSpindle.cpp

    This uses the Analog DAC in the ESP32 to generate a voltage
    proportional to the GCode S value desired. Some spindle uses
    a 0-5V or 0-10V value to control the spindle. You would use
    an Op Amp type circuit to get from the 0.3.3V of the ESP32 to that voltage.

    Part of Grbl_ESP32
    2020 -	Bart Dring

    Grbl is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Grbl.  If not, see <http://www.gnu.org/licenses/>.

*/
#include "DacSpindle.h"

namespace Spindles {
    // ======================================== Dac ======================================
    void Dac::init() {
        if (_output_pin.undefined()) {
            return;
        }

        _gpio_ok = true;

        if (!_output_pin.capabilities().has(Pin::Capabilities::DAC)) {  // DAC can only be used on these pins
            _gpio_ok = false;
            info_all("DAC spindle pin invalid %s (pin 25 or 26 only)", _output_pin.name().c_str());
            return;
        }

        _direction_pin.setAttr(Pin::Attr::Output);

        is_reversable = _direction_pin.defined();

        setupSpeeds(255);

        config_message();
    }

    void Dac::config_message() {
        info_all("%s spindle Output:%s, Dir:%s, Res:8bits", name(), _output_pin.name().c_str(), _direction_pin.name().c_str());
    }

    uint32_t Dac::mapSpeed(SpindleSpeed speed) {
        Spindle* s = static_cast<Spindle*>(this);
        return s->mapSpeed(speed);
    }

    void IRAM_ATTR Dac::setSpeedfromISR(uint32_t speed) { set_output(speed); };
    void IRAM_ATTR Dac::set_output(uint32_t duty) {
        if (_gpio_ok) {
            auto outputNative = _output_pin.getNative(Pin::Capabilities::DAC);

            dacWrite(outputNative, static_cast<uint8_t>(duty));
        }
    }

    // Configuration registration
    namespace {
        SpindleFactory::InstanceBuilder<Dac> registration("DAC");
    }
}
