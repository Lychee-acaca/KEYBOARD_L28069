#include "DSP28x_Project.h"
#include "keyboard.h"

Uint8 press = 0;

int main(void)
{
    InitSysCtrl();
    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;

    Key_Init();

    while(1)
    {
        Key_Scan();
        if (KEY_PRESS)
        {
            if (KEY_OP_PRESS)
            {
                press = KEY_OP;
            } else if (KEY_NUM_PRESS)
            {
                press = KEY_NUM;
            }
        }

    }
}
