#include "project.h"
#define SIZE(x) sizeof(x)/sizeof(x[0])
#define ZERO 0
#define MINUS 128
#define PLUS 255
uint8 signal[]={1,0,1,1,0,0,0,0,1,0,1,0};
int main(void)
{
    CyGlobalIntEnable;
    if( SIZE(signal)%3 == 0)    // якщо сигнал не буде кратний 3, ЦАП не ініціалізується.
        VDAC8_Start();
    for(;;)
    {
        for(uint8 i = 0; i < SIZE(signal); i+=3)
        {
            if(signal[i] == 0 && signal[i+1] == 0 && signal[i+2] == 0)  //000
            {
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
            }
            else if(signal[i] == 0 && signal[i+1] == 0 && signal[i+2] == 1)  //001
            {
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(MINUS);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
            }
            else if(signal[i] == 0 && signal[i+1] == 1 && signal[i+2] == 0)  //010
            {
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(PLUS);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
            }
            else if(signal[i] == 0 && signal[i+1] == 1 && signal[i+2] == 1)  //011
            {
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(MINUS);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(PLUS);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
            }
            else if(signal[i] == 1 && signal[i+1] == 0 && signal[i+2] == 0)  //100
            {
                VDAC8_SetValue(PLUS);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
    
            }
            else if(signal[i] == 1 && signal[i+1] == 0 && signal[i+2] == 1)  //101
            {
                VDAC8_SetValue(MINUS);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                VDAC8_SetValue(PLUS);
                CyDelay(1000);
                VDAC8_SetValue(ZERO);
                CyDelay(1000);
                
            }
            else if(signal[i] == 1 && signal[i+1] == 1 && signal[i+2] == 0)  //110
            {
                {
                    VDAC8_SetValue(MINUS);
                    CyDelay(1000);
                    VDAC8_SetValue(ZERO);
                    CyDelay(1000);
                    VDAC8_SetValue(PLUS);
                    CyDelay(1000);
                    VDAC8_SetValue(ZERO);
                    CyDelay(1000);
                    VDAC8_SetValue(ZERO);
                    CyDelay(1000);
                    VDAC8_SetValue(ZERO);
                    CyDelay(1000);
                    VDAC8_SetValue(ZERO);
                    CyDelay(1000);
                }
            }
        }
    }   
}
