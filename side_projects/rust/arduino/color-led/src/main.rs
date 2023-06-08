#![no_std]
#![no_main]

mod rgbled;
use embedded_hal::prelude::*;
use arduino_hal::delay_ms;
use rgbled::ColorLED;

use panic_halt as _;

#[arduino_hal::entry]
fn main() -> ! {
    let dp = arduino_hal::Peripherals::take().unwrap();
    let pins = arduino_hal::pins!(dp);

    let mut led = ColorLED::new(
        pins.d8.into_output().downgrade(),
        pins.d9.into_output().downgrade(),
        pins.d10.into_output().downgrade());

    loop {
        led.set(true, false, false);
        delay_ms(500);
        led.off();
        delay_ms(500);
    }
}
