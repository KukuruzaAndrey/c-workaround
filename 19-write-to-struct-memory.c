#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

// Based on https://stackoverflow.com/a/23898449/266720
void hextobin(const char * str, uint8_t * bytes, size_t blen){
   uint8_t  pos;
   uint8_t  idx0;
   uint8_t  idx1;

   // mapping of ASCII characters to hex values
   const uint8_t hashmap[] =
   {
     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, //>
     0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //>
     0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, //>
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //>
   };

   memset(bytes, 0, blen);
   for (pos = 0; ((pos < (blen*2)) && (pos < strlen(str))); pos += 2)
   {
      idx0 = ((uint8_t)str[pos+0] & 0x1F) ^ 0x10;
      idx1 = ((uint8_t)str[pos+1] & 0x1F) ^ 0x10;
      bytes[pos/2] = (uint8_t)(hashmap[idx0] << 4) | hashmap[idx1];
   };
}

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
    uint32_t objectId;
    uint32_t firmWareVersion;
// 10 bytes
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
    unsigned autoBypassTimer: 8;
    unsigned autoBypassCounter: 8;
    unsigned twoStageArming: 1;
    unsigned twoStageArmingStatus: 4;
    unsigned interconnectDelayTimeout: 10;
    unsigned interconnectState: 2;
    unsigned alarmHappened: 5;
    unsigned postAlarmIndicationRules: 3;
    unsigned disarmingByKeypad: 1;
    unsigned restoreRequired: 5;
    unsigned reportAlarmRestore: 1;
    unsigned interconnectModes: 8;
}  __attribute__((packed));

void print_cargo_port_hub(struct cargo_port_hub *cargoPortHub) {
    printf("hub.objectId: %d\n", cargoPortHub->objectId);
    printf("hub.firmWareVersion: %d\n", cargoPortHub->firmWareVersion);
    printf("hub.state: %d\n", cargoPortHub->state);
    printf("hub.hubFireDobleImpulses: %d\n", cargoPortHub->hubFireDobleImpulses);
    printf("hub.armPreventionMode: %d\n", cargoPortHub->armPreventionMode);
    printf("hub.groupsEnabled: %d\n", cargoPortHub->groupsEnabled);
    printf("hub.hubStateWithGroups: %d\n", cargoPortHub->hubStateWithGroups);
    printf("hub.panicSirenTurnOn: %d\n", cargoPortHub->panicSirenTurnOn);
    printf("hub.tamperAsAlarms: %d\n", cargoPortHub->tamperAsAlarms);
    printf("hub.fullArmProblem: %d\n", cargoPortHub->fullArmProblem);
    printf("hub.perimeterArmProblem: %d\n", cargoPortHub->perimeterArmProblem);
    printf("hub.blockedByServiceProvider: %d\n", cargoPortHub->blockedByServiceProvider);
    printf("hub.frameLength: %d\n", cargoPortHub->frameLength);
    printf("hub.lostDeviceCounter: %d\n", cargoPortHub->lostDeviceCounter);
    printf("hub.alarmHubBits: %d\n", cargoPortHub->alarmHubBits);
    printf("hub.fireInterconnected: %d\n", cargoPortHub->fireInterconnected);
    printf("hub.screamingSecondaryFire: %d\n", cargoPortHub->screamingSecondaryFire);
    printf("hub.armDelay: %d\n", cargoPortHub->armDelay);
    printf("hub.perimeterArmDelay: %d\n", cargoPortHub->perimeterArmDelay);
    printf("hub.autoBypassTimer: %d\n", cargoPortHub->autoBypassTimer);
    printf("hub.autoBypassCounter: %d\n", cargoPortHub->autoBypassCounter);
    printf("hub.twoStageArming: %d\n", cargoPortHub->twoStageArming);
    printf("hub.twoStageArmingStatus: %d\n", cargoPortHub->twoStageArmingStatus);
    printf("hub.interconnectDelayTimeout: %d\n", cargoPortHub->interconnectDelayTimeout);
    printf("hub.interconnectState: %d\n", cargoPortHub->interconnectState);
    printf("hub.alarmHappened: %d\n", cargoPortHub->alarmHappened);
    printf("hub.postAlarmIndicationRules: %d\n", cargoPortHub->postAlarmIndicationRules);
    printf("hub.disarmingByKeypad: %d\n", cargoPortHub->disarmingByKeypad);
    printf("hub.restoreRequired: %d\n", cargoPortHub->restoreRequired);
    printf("hub.reportAlarmRestore: %d\n", cargoPortHub->reportAlarmRestore);
    printf("hub.interconnectModes: %d\n", cargoPortHub->interconnectModes);
}

int main() {
/*    struct st c;
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
    } */

    printf("====================\n");

    struct cargo_port_hub portHub;
    struct cargo_port_hub *pPortHub = &portHub;
    printf("%p %ld\n", pPortHub, sizeof(pPortHub));
    char *ppH = (char *) pPortHub;
    printf("%p %ld\n", ppH, sizeof(ppH));

    portHub = (struct cargo_port_hub) {
            61,
            208100,
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
            1,
            2,
            0,
            0,
            10,
            0,
            1,
            0,
            0,
            5,
            0,
            4
    };
    for (int i = 0; i < 18; ++i) {
//        printf("%02x \n", *(ppH + i));
        printbin(ppH + i);
    }
    printf("\n");
    for (int i = 0; i < 18; ++i) {
        printf("%02x ", *(ppH + i));
//        printbin(ppH + i);
    }
    printf("\n");
    print_cargo_port_hub(pPortHub);
    printf("===========================\n");
    // 1E5D0009D33E000338A52018090002400000000000008107C0020000
    char hub_port_mem[] = "0009D33E000338A52018090002400000000000008107C0020000";
    int bytes = strlen(hub_port_mem)/2;
    uint8_t * mem = (uint8_t*)malloc(bytes * sizeof(uint8_t));
    hextobin(hub_port_mem, mem, bytes);

    memcpy(ppH, mem, 26);
    print_cargo_port_hub(mem);

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
    printf("\n");
}
