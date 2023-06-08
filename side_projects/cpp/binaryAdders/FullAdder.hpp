// FullAdder.hpp

class FullAdder {
    private:
        bool a0, b0, a1, b1;
        bool c, s;
    public:
        FullAdder(bool a0=0, bool b0=0, bool a1=0, bool b1=0);
        bool getC();
        bool getS();
};
