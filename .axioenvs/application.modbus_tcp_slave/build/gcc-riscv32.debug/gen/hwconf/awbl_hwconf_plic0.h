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


#ifndef __AWBL_HWCONF_RISCV_HPM_PLIC_0_H
#define __AWBL_HWCONF_RISCV_HPM_PLIC_0_H


/*******************************************************************************
  中断控制器配置信息
*******************************************************************************/
#include "plic/awb_hpm_plic.h"

/* ISR 信息内存静态分配 */
aw_local struct awb_common_isrinfo __g_plic0_isrinfos[127];

/* event 设备信息 */
aw_local aw_const struct awb_plic_devinfo __g_plic0_devinfo = {
    127,
    &__g_plic0_isrinfos[0], /* ISR 信息槽内存(大小等于isrinfo_cnt) */
    0x7,
    0xE4000004,
    0xE4002000,
    0xE4001000,
    0xE4200000
};

/* event 设备实例内存静态分配*/
aw_local struct awb_plic_dev __g_plic0_dev;

#define AWB_HWCONF_PLIC0   \
    {                              \
        AWB_HPM_PLIC_DRV_NAME,      \
        0,                         \
        AWB_BUS_TYPE_ID_PLB,            \
        0,                         \
        (struct awb_dev *)&__g_plic0_dev, \
        &__g_plic0_devinfo,    \
        "riscv_hpm_plic_0",        \
        NULL                        \
    }


#endif  /* __AWBL_HWCONF_RISCV_HPM_PLIC_0_H */

/* end of file */
