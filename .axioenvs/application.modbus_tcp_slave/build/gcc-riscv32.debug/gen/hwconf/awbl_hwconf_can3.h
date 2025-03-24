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


#ifndef __AWBL_HWCONF_HPM_CAN_3_H
#define __AWBL_HWCONF_HPM_CAN_3_H


#include "can/awb_hpm_can.h"



aw_local aw_const aw_dev_pm_pin_cfg_t  __g_can3_pm_pin_cfg[] = {
         { 133, 896,  896 , 896   },
         { 44, 896,  896 , 896   },
};
aw_local uint8_t __can3_rx_msg_buf[((sizeof(aw_can_msg_t) * 256) + 1)];
aw_local uint8_t __can3_err_msg_buf[((sizeof(aw_can_msg_t) * 16) + 1)];

/* can 设备信息 */
aw_local awb_hpm_can_dev_info_t aw_const __g_can3_devinfo = {
    &__g_can3_pm_pin_cfg[0],
    AW_NELEMENTS(__g_can3_pm_pin_cfg),
    0xF008C000,                     /**< \brief 寄存器基地址 */
    50,                              /**< \brief 中断编号 */
    57,                                     /**< \brief 输入时钟id */ 
    147,
    AW_FALSE,
    AW_TRUE,
      
    {
        500 * 1000,
        80,
        70,
        85,
        100,
    },
    {
        0,
        0,
        0,
        0,
        0,
    },
    &__can3_rx_msg_buf[0],
    sizeof(__can3_rx_msg_buf),
    &__can3_err_msg_buf[0],
    sizeof(__can3_err_msg_buf),
    {
        0,
        0,                  // 默认处于iso mode
        0,
        0,
    }
};

/* 设备实例内存静态分配 */
aw_local awb_hpm_can_dev_t __g_can3_dev;

#define AWB_HWCONF_CAN3     \
    {                                         \
        AWB_HPM_CAN_DRV_NAME  ,          \
        0,                                    \
        AWB_BUS_TYPE_ID_PLB,                  \
        0,                                    \
        &__g_can3_dev.dev,     \
        &__g_can3_devinfo,     \
        "can3",                          \
        NULL,                                 \
    }



#endif  /* __AWBL_HWCONF_HPM_CAN_3_H */

/* end of file */
