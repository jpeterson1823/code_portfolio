// HalfAdder.hpp

class HalfAdder {
    private:
        bool a, b, c, s;
    public:
        HalfAdder(bool a=0, bool b=0);
        bool getC();
        bool getS();
};
