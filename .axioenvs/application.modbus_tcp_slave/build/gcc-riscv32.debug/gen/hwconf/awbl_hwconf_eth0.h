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


#ifndef __AWBL_HWCONF_HPM_ENET_0_H
#define __AWBL_HWCONF_HPM_ENET_0_H

#include "hpm_pin.h"
#include "enet/awb_hpm_enet.h"

aw_local aw_const aw_dev_pm_pin_cfg_t  __g_eth0_pm_pin_cfg[] = {
{ 127, 2304,  2304 , 2304   },
{ 132, 2304,  2304 , 2304   },
{ 126, 2304,  2304 , 2304   },
{ 134, 2304,  2304 , 2304   },
{ 125, 2304,  2304 , 2304   },
{ 128, 2304,  2304 , 2304   },
    { 159, 2304 | HPM_PIN_LOOP_BACK(_HPM_PIN_LOOP_BACK_ON),  2304 |HPM_PIN_LOOP_BACK(_HPM_PIN_LOOP_BACK_ON) , 2304 |HPM_PIN_LOOP_BACK(_HPM_PIN_LOOP_BACK_ON)},


};

static uint32_t __g_eth0_rx_tx_buff[(FEC_DMA_ALIGN + FEC_PER_PKT_SIZE * (64 + 24))/4 ];
#if CONFIG_DRV_ENET_1588_TIMESTAMP_EN
static aw_net_buf_t *__g_eth0_tx_netbufs[24];
#endif

#if CONFIG_AWB_NETIF_RECV_RAW_PACKETS
static awb_netif_recv_packet_node_t __g_eth0_raw_packet_nodes[64];
static uint32_t  __g_eth0_raw_packet_buf[64][FEC_PER_PKT_SIZE / 4];

#endif

/* 设备信息 */
aw_local aw_const awb_hpm_enet_devinfo_t __g_eth0_devinfo = {
        {
                1,
                
                "192.168.3.251",
                "255.255.255.0",
                "192.168.3.1",

        },    
        &__g_eth0_pm_pin_cfg[0],
        AW_NELEMENTS(__g_eth0_pm_pin_cfg),
        0xF2000000,
        108,
        170,
        68,
        70,
        18,
        2,
        64,
        24,
        0,  /**< \brief 默认：禁能通过所有多播 */
        0,  /**< \brief 默认：禁能混杂模式  */
        1,
        
        0,
        0,
        4060348424u,
        4060348416u,
        0,
        "yt8512h_0",
        &__g_eth0_rx_tx_buff[0],
#if CONFIG_AWB_NETIF_RECV_RAW_PACKETS
        &__g_eth0_raw_packet_nodes[0],
        (uint8_t *)&__g_eth0_raw_packet_buf[0][0],
        FEC_PER_PKT_SIZE,
        64,
        AW_NETIF_RAW_RECV_ALL,

#else
        NULL,
        NULL,
        0,
        0,
        AW_NETIF_RAW_RECV_ALL,
#endif
#if CONFIG_DRV_ENET_1588_TIMESTAMP_EN
        &__g_eth0_tx_netbufs[0],
#else
        NULL,
#endif
        0, 
};

/* 设备实例内存静态分配 */
aw_local awb_hpm_enet_dev_t     __g_eth0_dev;

#define AWB_HWCONF_ETH0                                  \
    {                                                   \
        "hpm_enet",                               \
        0,                                   \
        AWB_BUS_TYPE_ID_PLB,                            \
        0,                                              \
        &__g_eth0_dev.dev,\
        &(__g_eth0_devinfo),              \
        "eth0",                          \
        NULL,                                 \
    }


#endif  /* __AWBL_HWCONF_HPM_ENET_0_H */

/* end of file */

