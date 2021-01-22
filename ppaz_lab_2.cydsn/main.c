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

int code [3] = {1011, 0000, 1010};

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    IDAC8_1_Start(); // Ініціалізація iDAC і початок його роботи.
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {

        HDB3_Codec(code, 3);
        
    }
}

void HDB3_Codec(int* code, int sizeArey)
{

    int i;
    for(i = 0; i < sizeArey; i++)
    {
        if (code[i] == 1011)
        {
          IDAC8_1_SetValue(LOW_LEVEL);
        CyDelay(100);
          IDAC8_1_SetValue(GND_LEVEL);
        CyDelay(100);
          IDAC8_1_SetValue(GND_LEVEL);
        CyDelay(100);
        }
        if(code[i] == 0000)
        {
           IDAC8_1_SetValue(HIGH_LEVEL);
        CyDelay(100);
           IDAC8_1_SetValue(GND_LEVEL);
        CyDelay(100);
           IDAC8_1_SetValue(LOW_LEVEL);
        CyDelay(100);
        }
        if(code[i] == 1010)
        {
           IDAC8_1_SetValue(LOW_LEVEL);
        CyDelay(100);
           IDAC8_1_SetValue(HIGH_LEVEL);
        CyDelay(100);
           IDAC8_1_SetValue(LOW_LEVEL);
        CyDelay(100);
        }
        CyDelay(100);
    }
}

/* [] END OF FILE */

