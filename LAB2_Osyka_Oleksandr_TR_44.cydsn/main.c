#include "project.h"

/* Три рівні напруги: додатній, нульовий та від'ємний */
#define POSITIVE 255
#define ZERO 128
#define NEGATIVE 0

uint8 signal[] = {1,0,1,1,0,0,0,0,1,0,1,0};

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    VDAC8_Start();
    int temp = 1;

    for(;;)
    {
        /* Place your application code here. */
        for(int i = 0; i < 12; i++)
        {
            /* Логічні нулі кодуються нульовим рівнем напруги */
            if(signal[i] == 0)
            {
                VDAC8_SetValue(ZERO);
                CyDelay(10);
            }
            
            /* Логічні одиниці кодуються почергово додатнім та від'ємним рівнем напруги */
            if(signal[i] == 1)
            {
                if(temp == 1)
                {
                    VDAC8_SetValue(POSITIVE);
                    CyDelay(10);
                    temp = 0;
                }
                if(temp == 0)
                {
                    VDAC8_SetValue(NEGATIVE);
                    CyDelay(10);
                    temp = 1;
                }
                
            }
        }
    }
}


