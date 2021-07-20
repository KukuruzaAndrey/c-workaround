#include "stdio.h"
#include "stdint.h"
#include "string.h"

struct st {
    int a;
    int b;
};

void printbin(char *c) {
    char bits[8];
    unsigned char value = *c;

    for (int i = 7; i >= 0; i -= 1) {
        bits[i] = '0' + (value & 0x01);
        value >>= 1;
    }
//    puts(bits);
    printf("%s ", bits);
}

struct cargo_port_hub {
//    uint32_t objectId;
//    uint32_t firmWareVersion;
    unsigned state: 2;
    unsigned hubFireDobleImpulses: 1;
    unsigned armPreventionMode: 2;
    unsigned groupsEnabled: 1;
    unsigned hubStateWithGroups: 3;
    unsigned panicSirenTurnOn: 1;
    unsigned tamperAsAlarms: 1;
    unsigned fullArmProblem: 1;
    unsigned perimeterArmProblem: 1;
    unsigned blockedByServiceProvider: 1;
    unsigned frameLength: 16;
    unsigned lostDeviceCounter: 8;
    unsigned alarmHubBits: 8;
    unsigned fireInterconnected: 1;
    unsigned screamingSecondaryFire: 1;
    unsigned armDelay: 16;
    unsigned perimeterArmDelay: 16;
}  __attribute__((packed));

int main() {
    struct st c;
    struct st *pointer = &c;
    printf("%p %ld\n", pointer, sizeof(pointer));
    char *p = (char *) pointer;
    printf("%p %ld\n", p, sizeof(p));

    c = (struct st) {10, 2};
    printf("%d %d\n", c.a, c.b);
    for (int i = 0; i < 8; ++i) {
        printf("%d\n", *(p + i));
    }
    printf("%p %ld\n", p, sizeof(p));
    char src[] = "dUdU";
    memcpy(p, src, 4);


    printf("%p %ld\n", p, sizeof(p));
    printf("%d %d\n", c.a, c.b);
    for (int i = 0; i < 8; ++i) {
        printf("%d\n", *(p + i));
    }

    printf("====================\n");

    struct cargo_port_hub portHub;
    struct cargo_port_hub *pPortHub = &portHub;
    printf("%p %ld\n", pPortHub, sizeof(pPortHub));
    char *ppH = (char *) pPortHub;
    printf("%p %ld\n", ppH, sizeof(ppH));

    portHub = (struct cargo_port_hub) {
//            61,
//            208100,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            36,
            8,
            0,
            0,
            0,
            0,
            0,
    };
    for (int i = 0; i < 16; ++i) {
//        printf("%02x \n", *(ppH + i));
        printbin(ppH + i);
    }
//    printf("%d %d\n", c.a, c.b);
//    for (int i = 0; i < 8; ++i) {
//        printf("%d", *(p + i));
//    }
//    printf("%p %ld\n", p, sizeof(p));
//    char src[] = "dUdU";
//    memcpy(p, src, 4);
//
//
//    printf("%p %ld\n", p, sizeof(p));
//    printf("%d %d\n", c.a, c.b);
//    for (int i = 0; i < 8; ++i) {
//        printf("%d\n", *(p + i));
//    }
}
