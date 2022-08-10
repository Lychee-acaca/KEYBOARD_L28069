#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "DSP28x_Project.h"

extern Uint8 KEY_PRESS, KEY_OP_PRESS, KEY_NUM_PRESS;
extern Uint8 KEY_NUM, KEY_OP;

/* 按键示意图（按键正对自己）
 * 9  8  7  R1
 * 4  5  6  R2
 * 1  2  3  R3
 * D1 0  .  D2
 *
 * D1被按下时，KEY_OP = 1
 * D2被按下时，KEY_OP = 2
 * .被按下时，KEY_OP = 3
 * R1被按下时，KEY_OP = 4
 * R2被按下时，KEY_OP = 5
 * R3被按下时，KEY_OP = 6
 *
 * LaunchPadXL_F28069M接线（矩阵按键引脚从上到下顺序）
 * PA7 GPIO27
 * PA6 GPIO26
 * PA5 GPIO24
 * PA4 GPIO25
 * PA0 GPIO52
 * PA1 GPIO10
 * PA2 GPIO56
 * PA3 GPIO11
 */

#define PA0 GpioDataRegs.GPBDAT.bit.GPIO52
#define PA1 GpioDataRegs.GPADAT.bit.GPIO10
#define PA2 GpioDataRegs.GPBDAT.bit.GPIO56
#define PA3 GpioDataRegs.GPADAT.bit.GPIO11

#define PA4 GpioDataRegs.GPADAT.bit.GPIO25
#define PA5 GpioDataRegs.GPADAT.bit.GPIO24
#define PA6 GpioDataRegs.GPADAT.bit.GPIO26
#define PA7 GpioDataRegs.GPADAT.bit.GPIO27

void Key_Init(void);
void Key_Scan(void);
Uint8 PA_Scan(Uint8 PAn);
Uint8 PA_Check(Uint8 PAn, Uint8 c);

#endif
