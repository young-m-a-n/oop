#pragma once
class queue {
public:
    queue() {
        NI = 9;
        NO = 9;
        capacity = 100;
    }
    queue(int a, int b, int c) {
        NI = a;
        NO = b;
        capacity = c;
    }
    int NI, NO, capacity;

};
