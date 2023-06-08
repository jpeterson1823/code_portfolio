use arduino_hal::port::{mode::Output, Pin};

pub struct ColorLED {
    rpin: Pin<Output>,
    bpin: Pin<Output>,
    gpin: Pin<Output>,
}

impl ColorLED {
    pub fn new(rpin: Pin<Output>, bpin: Pin<Output>, gpin: Pin<Output>) -> Self {
        Self {
            rpin,
            bpin,
            gpin,
        }
    }

    pub fn set(&mut self, r: bool, g: bool, b: bool) {
        if r { self.rpin.set_high(); }
        if g { self.gpin.set_high(); }
        if b { self.bpin.set_high(); }
    }

    pub fn off(&mut self) {
        self.rpin.set_low();
        self.gpin.set_low();
        self.bpin.set_low();
    }
}
