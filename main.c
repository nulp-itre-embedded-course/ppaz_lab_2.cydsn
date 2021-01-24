/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

void HDB3_Codec(int* code, int sizeArey); // Прототип функції
//void outIDAC(int* code, int sizeArey);

#define HIGH_LEVEL 255
#define LOW_LEVEL  0
#define GND_LEVEL  128

int code [12] = {1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0};

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    IDAC8_1_Start(); // Ініціалізація iDAC і початок його роботи.
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {

        HDB3_Codec(code, 12);
        
    }
}


void HDB3_Codec(int* code, int sizeArey)
{
    int flagPoliariti = 0; // Змінна для зберігання полярності останнього біта 
    int counter = 0;       // Змінна для підрахунку кількості нулів що йдуть підряд
    int i;
    for(i = 0; i < sizeArey; i++)
    {
        if (code[i] == 1)
        {
            if (flagPoliariti == 0)
            {
                IDAC8_1_SetValue(HIGH_LEVEL);
                counter = 0;
            }
            if (flagPoliariti < 0)
            {
                IDAC8_1_SetValue(LOW_LEVEL);
                counter = 0;
            }
            flagPoliariti = ~flagPoliariti;
        }
        if(code[i] == 0)
        {
            counter++;
            if(counter < 4)
            {
                IDAC8_1_SetValue(GND_LEVEL);
            }
            if(counter == 4 && flagPoliariti < 0)
            {
                IDAC8_1_SetValue(HIGH_LEVEL);
                counter = 0;
            }
            if(counter == 4 && flagPoliariti == 0)
            {
                IDAC8_1_SetValue(LOW_LEVEL);
                counter = 0;
            }
        }
        CyDelay(100);
    }
}

/* [] END OF FILE */
