#include <stdlib.h>

#define Main UselessMain
#include "pa3d.c"
#undef Main

// you cannot change the speed of a car
void test1() {
    InitRoad();
    for (int i = 2; i <= 10; ++i) {
        if (Fork() == 0) {
            Delay(i * 5);
            driveRoad(WEST, (i % 2 == 0 ? 40 : 20));
            Exit();
        }
    }

    driveRoad(WEST, 20);
}

// piazza 393
// should be: AB - E - CD
void test2() {
    InitRoad();
    if (Fork() == 0) {
        // A
        driveRoad(EAST, 20);
        Exit();
    }
    if (Fork() == 0) {
        // B
        Delay(10);
        driveRoad(EAST, 20);
        Exit();
    }
    if (Fork() == 0) {
        // C
        Delay(20);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0) {
        // D
        Delay(40);
        driveRoad(EAST, 40);
        Exit();
    }
    if (Fork() == 0) {
        // E
        Delay(300);
        driveRoad(WEST, 40);
        Exit();
    }
}

// piazza 414
// one car each side alternatively
void test3() {
    InitRoad();
    for (int i = 2; i <= 5; ++i) {
        if (Fork() == 0) {
            driveRoad(EAST, 40);
            Exit();
        }
    }
    for (int i = 6; i <= 9; ++i) {
        if (Fork() == 0) {
            driveRoad(WEST, 40);
            Exit();
        }
    }
}

// possibly deadlock
void test4() {
    InitRoad();
    for (int i = 2; i <= 5; ++i) {
        if (Fork() == 0) {
            if (i % 2 == 1) {
                Delay(5);
            }
            driveRoad(EAST, 40);
            Exit();
        }
    }
    for (int i = 6; i <= 9; ++i) {
        if (Fork() == 0) {
            if (i % 2 == 0) {
                Delay(5);
            }
            driveRoad(WEST, 40);
            Exit();
        }
    }
}

void Main(int argc, char* argv[]) {
    char* dummy;
    int idx = strtol(argv[1], &dummy, 10);
    if (dummy != NULL) {
        if (idx == 1) {
            DPrintf("Testing Case 1\n");
            test1();
        }
        else if (idx == 2) {
            DPrintf("Testing Case 2\n");
            test2();
        }
        else if (idx == 3) {
            DPrintf("Testing Case 3\n");
            test3();
        }
        else if (idx == 4) {
            DPrintf("Testing Case 4\n");
            test4();
        }
    }
    Exit();
}
