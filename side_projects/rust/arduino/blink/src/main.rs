#![no_std]
#![no_main]

use arduino_hal::prelude::*;
use panic_halt as _;

#[arduino_hal::entry]
fn main() -> ! {
    let dp = arduino_hal::Peripherals::take().unwrap();
    let pins = arduino_hal::pins!(dp);
    
    // create serial
    let mut serial = arduino_hal::default_serial!(dp, pins, 57600);

    ufmt::uwriteln!(&mut serial, "Hello, world!\r").void_unwrap();

    let message: [&str; 4] = ["Hello", ", ", "arrays", "!\r\n"];
    for msg in message {
        ufmt::uwrite!(&mut serial, "{}", msg).void_unwrap();
    }

    loop {}
}

/*
 * Taking serial input and writing to digital pin example
use arduino_hal::{prelude::*, port::Pin, port::mode};
use panic_halt as _;
use embedded_hal::serial::Read;

#[arduino_hal::entry]
fn main() -> ! {
    let dp = arduino_hal::Peripherals::take().unwrap();
    let pins = arduino_hal::pins!(dp);

    let mut led = pins.d13.into_output().downgrade();
    let mut serial = arduino_hal::default_serial!(dp, pins, 57600);

    ufmt::uwriteln!(&mut serial, "Hello from Arduino!\n").void_unwrap();

    loop {
        let b = nb::block!(serial.read()).void_unwrap();
        set_led(&mut led, b);

        arduino_hal::delay_ms(1000);
    }
}

fn set_led(led: &mut Pin<mode::Output>, state: u8) {
    if state as char == 'h' {
        led.set_high();
    } else if state as char == 'l' {
        led.set_low();
    }
}
*/
