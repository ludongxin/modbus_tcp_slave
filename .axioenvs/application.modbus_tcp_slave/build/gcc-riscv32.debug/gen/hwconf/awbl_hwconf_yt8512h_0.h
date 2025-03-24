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


#ifndef __AWBL_HWCONF_YT8512H_PHY_0_H
#define __AWBL_HWCONF_YT8512H_PHY_0_H


#include "phy/awb_yt8512h_phy.h"

aw_local aw_const aw_dev_pm_pin_cfg_t  __g_yt8512h_phy_0_pm_pin_cfg[] = {
         { 205, 4,  4 , 4   },
};


/* 设备信息 */
aw_local aw_const awb_yt8512h_phy_devinfo_t __g_yt8512h_phy_0_devinfo = {
        &__g_yt8512h_phy_0_pm_pin_cfg[0],
        AW_NELEMENTS(__g_yt8512h_phy_0_pm_pin_cfg),
        0x2,
        PHY_INTERFACE_MODE_RMII,
        205,
        18,
        
        YT8512H_LED0,
        AW_FALSE,
        YT8512H_LED1,
        AW_FALSE,
};

/* 设备实例内存静态分配 */
aw_local awb_yt8512h_phy_dev_t    __g_yt8512h_phy_0_dev;

#define AWB_HWCONF_YT8512H_0                                  \
    {                                                   \
        AWB_DRV_PHY_YT8512H_NAME,                               \
        0,                                   \
        AWB_BUS_TYPE_ID_MII,                            \
        0,                                              \
        &__g_yt8512h_phy_0_dev.dev,               \
        &(__g_yt8512h_phy_0_devinfo),             \
        "yt8512h_0",                                    \
        "eth1",                     \
    }


#endif  /* __AWBL_HWCONF_YT8512H_PHY_0_H */

/* end of file */

