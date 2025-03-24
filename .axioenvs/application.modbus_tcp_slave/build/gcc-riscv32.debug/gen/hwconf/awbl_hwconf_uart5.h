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


#ifndef __AWBL_HWCONF_HPM_UART_4_H
#define __AWBL_HWCONF_HPM_UART_4_H


#include "uart/awb_hpm_uart.h"

aw_local aw_const aw_dev_pm_pin_cfg_t  __g_uart5_pm_pin_cfg[] = {
        { 152, 256|AW_PIN_CFG_PULL_UP, 256|AW_PIN_CFG_PULL_UP, 256|AW_PIN_CFG_PULL_UP },
        { 153, 256|AW_PIN_CFG_PULL_UP, 256|AW_PIN_CFG_PULL_UP, 256|AW_PIN_CFG_PULL_UP },
};

static uint8_t     __uart4_recv_buf[128];
aw_local awb_hpm_uart_devinfo_t aw_const __g_uart5_devinfo = {
    &__g_uart5_pm_pin_cfg[0],
    AW_NELEMENTS(__g_uart5_pm_pin_cfg),
    36,                              /**< \brief 中断编号 */
    0xF0054000,                     /**< \brief 寄存器基地址 */
    125,
    __uart4_recv_buf,
    sizeof(__uart4_recv_buf),
    NULL,
    0,
    115200,
    -1,
    0,
    0,                  /**< \brief rs485电平切换延时时间,单位ms */
};


aw_local awb_hpm_uart_dev_t __g_uart5_dev;

#define AWB_HWCONF_UART5                          \
    {                                           \
        AWB_HPM_UART_DRV_NAME  ,          \
        0,                                      \
        AWB_BUS_TYPE_ID_PLB,                    \
        0,                                      \
        &__g_uart5_dev.dev,       \
        &__g_uart5_devinfo,       \
        "uart5",                            \
        NULL,                                   \
    }


#endif  /* __AWBL_HWCONF_HPM_UART_4_H */

/* end of file */
