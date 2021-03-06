/**
 *!
 * \file        b_button.c
 * \version     v0.0.1
 * \date        2020/02/21
 * \author      Bean(notrynohigh@outlook.com)
 *******************************************************************************
 * @attention
 * 
 * Copyright (c) 2020 Bean
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO BUTTON SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *******************************************************************************
 */
   
/*Includes ----------------------------------------------*/
#include "b_button.h"
#include <string.h>
#if _FLEXIBLEBUTTON_ENABLE
/** 
 * \addtogroup BABYOS
 * \{
 */

/** 
 * \addtogroup BUTTON
 * \{
 */

/** 
 * \defgroup BUTTON_Private_TypesDefinitions
 * \{
 */
  
/**
 * \}
 */
   
/** 
 * \defgroup BUTTON_Private_Defines
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \defgroup BUTTON_Private_Macros
 * \{
 */

/**
 * \}
 */
   
/** 
 * \defgroup BUTTON_Private_Variables
 * \{
 */
static flex_button_t bButtonList[USER_BUTTON_MAX] = {
    [USER_BUTTON_1] = {
        .pressed_logic_level = 0,
    },
    [USER_BUTTON_2] = {
        .pressed_logic_level = 0,
    },
    [USER_BUTTON_3] = {
        .pressed_logic_level = 0,
    },
    [USER_BUTTON_WAKEUP] = {
        .pressed_logic_level = 0,
    },     
}; 
/**
 * \}
 */
   
/** 
 * \defgroup BUTTON_Private_FunctionPrototypes
 * \{
 */
   
/**
 * \}
 */
   
/** 
 * \defgroup BUTTON_Private_Functions
 * \{
 */

/**
 * \}
 */
   
/** 
 * \addtogroup BUTTON_Exported_Functions
 * \{
 */


int bButtonInit()
{
    int i;
    for (i = 0; i < USER_BUTTON_MAX; i++)
    {
        bButtonList[i].id = i;
        bButtonList[i].usr_button_read = bButtonRead;
        bButtonList[i].cb = bButtonCallback;
        bButtonList[i].short_press_start_tick = FLEX_MS_TO_SCAN_CNT(1500);
        bButtonList[i].long_press_start_tick = FLEX_MS_TO_SCAN_CNT(3000);
        bButtonList[i].long_hold_start_tick = FLEX_MS_TO_SCAN_CNT(4500);
        flex_button_register(&bButtonList[i]);
    }
    return 0;
}


#if __GNUC__ 
void __attribute__((weak)) bButtonCallback(void *p)
#else
__weak void bButtonCallback(void *p)
#endif
{
    flex_button_t *btn = (flex_button_t *)p;
    b_log("id: [%d]  event: [%d]  repeat: %d\n", btn->id,btn->event,btn->click_cnt);
}


#if __GNUC__ 
uint8_t __attribute__((weak)) bButtonRead(void *p)
#else
__weak uint8_t bButtonRead(void *p)
#endif
{
    uint8_t value = 0;
    flex_button_t *btn = (flex_button_t *)p;
    switch(btn->id)
    {
        case USER_BUTTON_1:
            //.....
            break;
        //...
    }
    return value;
}


/**
 * \}
 */

/**
 * \}
 */

/**
 * \}
 */
#endif

/************************ Copyright (c) 2019 Bean *****END OF FILE****/

