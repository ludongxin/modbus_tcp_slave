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


#ifndef __AWBL_HWCONF_HPM_GTMR_SYSTMR_0_H
#define __AWBL_HWCONF_HPM_GTMR_SYSTMR_0_H


#include "gtmr/awb_hpm_gtmr_systmr.h"


/** \brief systmr 设备信息 */
aw_local aw_const awb_hpm_gtmr_systmr_devinfo_t __g_systmr_devinfo = {
    0xF3008000,                     /**< \brief 寄存器基地址 */
    62,                              /**< \brief 中断号 */
    114
};

/** \brief 设备实例内存静态分配 */
aw_local awb_hpm_gtmr_systmr_dev_t __g_systmr_dev;

#define AWB_HWCONF_SYSTMR                      \
    {                                       \
        AWB_HPM_GTMR_SYSTMR_DRV_NAME,       \
        0,                                  \
        AWB_BUS_TYPE_ID_PLB,                \
        0,                                  \
        &__g_systmr_dev.dev,   \
        &__g_systmr_devinfo,   \
        NULL,                               \
        NULL,                               \
    }


#endif  /* __AWBL_HWCONF_HPM_GTMR_SYSTMR_0_H */

/* end of file */
