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


#ifndef __AWBL_HWCONF_HPM_UART_DEBUG_0_H
#define __AWBL_HWCONF_HPM_UART_DEBUG_0_H


#include "uart/awb_hpm_uart_debug.h"

aw_local aw_const aw_dev_pm_pin_cfg_t  __g_uart0_pm_pin_cfg[] = {
        { 190, 256,  256 , 256   },
        { 189, 256,  256 , 256   },
};
static uint8_t   uart0_send_buf[128];


/* uart设备信息 */
static uint8_t     __uart0_dbg_recv_buf[128];
aw_local awb_hpm_uart_devinfo_t aw_const __g_uart0_devinfo = {
    &__g_uart0_pm_pin_cfg[0],
    AW_NELEMENTS(__g_uart0_pm_pin_cfg),
    31,                              /**< \brief 中断编号 */
    0xF0040000,                     /**< \brief 寄存器基地址 */
    120,
    __uart0_dbg_recv_buf,
    sizeof(__uart0_dbg_recv_buf),
    uart0_send_buf,
    sizeof(uart0_send_buf),

    115200,
    -1,
    0,
    0,
};

aw_local awb_hpm_uart_debug_dev_t __g_uart0_dev;

#define AWB_HWCONF_UART0                          \
    {                                           \
        AWB_HPM_UART_DEBUG_DRV_NAME  ,    \
        0,                                      \
        AWB_BUS_TYPE_ID_PLB,                    \
        0,                                      \
        &__g_uart0_dev.uart_dev.dev, \
        &__g_uart0_devinfo,       \
        "uart0",                            \
        NULL,                                   \
    }


#endif  /* __AWBL_HWCONF_HPM_UART_DEBUG_0_H */

/* end of file */
