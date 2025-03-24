/*******************************************************************************
*                                 AWorks
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-present Guangzhou ZHIYUAN Electronics Co., Ltd.
* ALL rights reserved.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
*
* The License of this software follows LGPL v2.1, See the LICENSE for more details:
* https://opensource.org/licenses/LGPL-2.1
* 
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

#include "aworks.h"
#include "gpio/awb_hpm_gpio.h"

aw_local aw_const aw_dev_pm_pin_cfg_t  __g_pin_1_pm_pin_cfg[] = {
        { 161, 0,  0 , 0   },
};

/**
 * \brief 设备信息
 */
aw_local aw_const awb_hpm_gpio_devinfo_t __g_pin_1_devinfo = {
        {
            0,
            491,
        },
        0xF0000000,
        0xF40DC000,
        0xF5014000,
        &__g_pin_1_pm_pin_cfg[0],
        AW_NELEMENTS(__g_pin_1_pm_pin_cfg)
};

static awb_hpm_gpio_dev_t __g_pin_1_dev;

#define AWB_HWCONF_PIN_1                    \
    {                                   \
         "hpm_gpio",                \
        0,                   \
        AWB_BUS_TYPE_ID_PLB,            \
        0,                              \
        &(__g_pin_1_dev.dev),     \
        &(__g_pin_1_devinfo),     \
        "hpm_pin",                   \
        NULL,                           \
    }

/* end of file */