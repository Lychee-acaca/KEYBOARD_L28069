#include "keyboard.h"

Uint8 KEY_PRESS = 0, KEY_OP_PRESS = 0, KEY_NUM_PRESS = 0;
Uint8 KEY_NUM = 0, KEY_OP = 0;

Uint8 KEY_HOLD = 0, KEY_HOLD_CNT = 0;

void Key_Init(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO27 = 0;
    //GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;

    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO26 = 0;
    //GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;

    GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO24 = 0;
    //GpioDataRegs.GPACLEAR.bit.GPIO24 = 1;

    GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO25 = 0;
    //GpioDataRegs.GPACLEAR.bit.GPIO25 = 1;

    GpioCtrlRegs.GPBPUD.bit.GPIO52 = 0;
    GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1;
    GpioDataRegs.GPBCLEAR.bit.GPIO52 = 1;

    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;

    GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0;
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO56 = 1;
    GpioDataRegs.GPBCLEAR.bit.GPIO56 = 1;

    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;
    GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;
    EDIS;
}

void Key_Scan(void)
{
    Uint8 check = 100;
    PA0 = 0; PA1 = 0; PA2 = 0; PA3 = 0;
    KEY_PRESS = 0, KEY_OP_PRESS = 0, KEY_NUM_PRESS = 0;
    KEY_NUM = 0, KEY_OP = 0;
    if (!PA4)
    {
        DELAY_US(5000L);
        if (!PA4)
        {
            if (KEY_HOLD)
                return;
            KEY_HOLD = 1;
            KEY_PRESS = 1;
            check = PA_Scan(4);
            if (check == 0)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 7;
            } else if (check == 1)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 4;
            } else if (check == 2)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 1;
            } else if (check == 3)
            {
                KEY_OP_PRESS = 1;
                KEY_OP = 1;
            }
        }
    }
    else if (!PA5)
    {
        DELAY_US(5000L);
        if (!PA5)
        {
            if (KEY_HOLD)
                return;
            KEY_HOLD = 1;
            KEY_PRESS = 1;
            check = PA_Scan(5);
            if (check == 0)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 8;
            } else if (check == 1)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 5;
            } else if (check == 2)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 2;
            } else if (check == 3)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 0;
            }
        }
    }
    else if (!PA6)
    {
        DELAY_US(5000L);
        if (!PA6)
        {
            if (KEY_HOLD)
                return;
            KEY_HOLD = 1;
            KEY_PRESS = 1;
            check = PA_Scan(6);
            if (check == 0)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 9;
            } else if (check == 1)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 6;
            } else if (check == 2)
            {
                KEY_NUM_PRESS = 1;
                KEY_NUM = 3;
            } else if (check == 3)
            {
                KEY_OP_PRESS = 1;
                KEY_OP = 3;
            }
        }
    }
    else if (!PA7)
    {
        DELAY_US(5000L);
        if (!PA7)
        {
            if (KEY_HOLD)
                return;
            KEY_HOLD = 1;
            KEY_PRESS = 1;
            check = PA_Scan(7);
            if (check == 0)
            {
                KEY_OP_PRESS = 1;
                KEY_OP = 4;
            } else if (check == 1)
            {
                KEY_OP_PRESS = 1;
                KEY_OP = 5;
            } else if (check == 2)
            {
                KEY_OP_PRESS = 1;
                KEY_OP = 6;
            } else if (check == 3)
            {
                KEY_OP_PRESS = 1;
                KEY_OP = 2;
            }
        }
    } else KEY_HOLD = 0;

}

Uint8 PA_Scan(Uint8 PAn)
{
    Uint8 check;
    PA0 = 1; PA1 = 0; PA2 = 0; PA3 = 0;
    check = PA_Check(PAn, 0);
    if (check != 100)
        return check;

    PA0 = 0; PA1 = 1; PA2 = 0; PA3 = 0;

    check = PA_Check(PAn, 1);
    if (check != 100)
        return check;

    PA0 = 0; PA1 = 0; PA2 = 1; PA3 = 0;
    check = PA_Check(PAn, 2);
    if (check != 100)
        return check;

    PA0 = 0; PA1 = 0; PA2 = 0; PA3 = 1;
    check = PA_Check(PAn, 3);
    if (check != 100)
        return check;
    return 100;
}

Uint8 PA_Check(Uint8 PAn, Uint8 c)
{
    if (PAn == 4 && PA4 == 1)
        return c;
    if (PAn == 5 && PA5 == 1)
        return c;
    if (PAn == 6 && PA6 == 1)
        return c;
    if (PAn == 7 && PA7 == 1)
        return c;
    return 100;
}
