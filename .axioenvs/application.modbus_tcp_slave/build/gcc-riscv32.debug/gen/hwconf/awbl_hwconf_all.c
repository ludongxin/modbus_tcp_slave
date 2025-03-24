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
#include "awbus.h"


#include "awbl_hwconf_plic0.h"
#include "awbl_hwconf_pin_1.h"
#include "awbl_hwconf_systmr.h"
#include "awbl_hwconf_uart0.h"
#include "awbl_hwconf_uart5.h"
#include "awbl_hwconf_xpi0.h"
#include "awbl_hwconf_eth0.h"
#include "awbl_hwconf_eth1.h"
#include "awbl_hwconf_yt8512h_0.h"
#include "awbl_hwconf_can0.h"
#include "awbl_hwconf_can2.h"
#include "awbl_hwconf_can3.h"
#include "awbl_hwconf_otp.h"
#include "awbl_hwconf_ptpc.h"


aw_const struct awb_devhcf g_awb_devhcf_list[] = {
    AWB_HWCONF_PLIC0,
    AWB_HWCONF_PIN_1,
    AWB_HWCONF_SYSTMR,
    AWB_HWCONF_UART0,
    AWB_HWCONF_UART5,
    AWB_HWCONF_XPI0,
    AWB_HWCONF_ETH0,
    AWB_HWCONF_ETH1,
    AWB_HWCONF_YT8512H_0,
    AWB_HWCONF_CAN0,
    AWB_HWCONF_CAN2,
    AWB_HWCONF_CAN3,
    AWB_HWCONF_OTP,
    AWB_HWCONF_PTPC,
};


const struct awb_devhcf *awb_devhcf_list_get(void)
{
    return &g_awb_devhcf_list[0];
}

uint32_t awb_devhcf_list_count_get(void)
{
    return AW_NELEMENTS(g_awb_devhcf_list);
}

/* end of file */

