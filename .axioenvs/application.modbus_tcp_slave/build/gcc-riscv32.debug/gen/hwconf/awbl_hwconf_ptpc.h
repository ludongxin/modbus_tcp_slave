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


#ifndef __AWBL_HWCONF_HPM_PTPC_TIMESTAMP_0_H
#define __AWBL_HWCONF_HPM_PTPC_TIMESTAMP_0_H


#include "ptpc/awb_hpm_ptpc_timestamp.h"


/* PTPC 设备信息 */
aw_local aw_const awb_hpm_ptpc_stamp_devinfo_t __g_ptpc_devinfo = {
    148,                                            // 输入时钟id
    51,
    0xF00B0000,
};

/* PTPC 设备实例内存静态分配*/
aw_local awb_hpm_ptpc_stamp_dev_t __g_ptpc_dev;

#define AWB_HWCONF_PTPC   \
    {                              \
        AWB_HPM_PTPC_STAMP_DRV_NAME,      \
        0,                         \
        AWB_BUS_TYPE_ID_PLB,            \
        0,                         \
        (struct awb_dev *)&__g_ptpc_dev, \
        &__g_ptpc_devinfo,    \
        NULL,        \
        NULL                        \
    }



#endif  /* __AWBL_HWCONF_HPM_PTPC_TIMESTAMP_0_H */

/* end of file */
