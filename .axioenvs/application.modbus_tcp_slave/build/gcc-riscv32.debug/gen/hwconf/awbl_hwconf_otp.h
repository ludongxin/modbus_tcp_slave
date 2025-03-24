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


#ifndef __AWBL_HWCONF_HPM_OTP_0_H
#define __AWBL_HWCONF_HPM_OTP_0_H


#include "otp/awb_hpm_otp.h"


static aw_const struct awb_hpm_otp_devinfo __g_otp_devinfo = {
    0xF40C8000,
    0xF40C4000,
    "otp",
};


static struct awb_hpm_otp_dev __g_otp_dev;

#define AWB_HWCONF_OTP        \
    {                                       \
        AWB_DRV_HPM_OTP_NAME,          \
        0,                       \
        AWB_BUS_TYPE_ID_PLB,                \
        0,                                  \
        &(__g_otp_dev.dev), \
        &__g_otp_devinfo,   \
        "otp",                      \
        NULL,                               \
    }


#endif  /* __AWBL_HWCONF_HPM_OTP_0_H */

/* end of file */
