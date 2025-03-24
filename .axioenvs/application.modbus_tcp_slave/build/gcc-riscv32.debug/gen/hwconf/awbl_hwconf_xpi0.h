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


#ifndef __AWBL_HWCONF_HPM_NOR_XPI_0_H
#define __AWBL_HWCONF_HPM_NOR_XPI_0_H


#include "nor_api/awb_hpm_nor_xpi.h"

extern uint32_t __flash_map_start;
extern uint32_t __flash_map_size;
extern uint32_t __flash_code_region_offset;
extern uint32_t __flash_code_region_size;
extern uint32_t __flash_data_region_offset;
extern uint32_t __flash_data_region_size;

static awb_hpm_nor_xpi_ram_info_t __g_xpi0_ram_info = {
    .p_xpi_type = (XPI_Type*)0xF3040000,
    .xpi_option = {
        .header.U  = 0xFCF90001U,
        .option0.U = 0x7U,
        .option1.U = 0x0U,
    },
    .xip_flash_info = {
        .code = {
            .p_name = "xpi0_code",
            .offset = (uint32_t)&__flash_code_region_offset,
            .size   = (uint32_t)&__flash_code_region_size,
        },
        .data = {
            .p_name = "xpi0_data",
            .offset = (uint32_t)&__flash_data_region_offset,
            .size   = (uint32_t)&__flash_data_region_size,
        },
        .mul_part_number = 0,
        .type = 0,
        
    },
    .memory_map_base_address = (uint32_t)&__flash_map_start,
    .memory_map_size         = (uint32_t)&__flash_map_size,
};

static const awb_hpm_nor_xpi_devinfo_t __g_xpi0_devinfo = {
    98,
    .p_flash_name     = "xpi0",
    .p_flash_ram_info = &__g_xpi0_ram_info,
};

static awb_hpm_nor_xpi_dev_t __g_xpi0_dev;

#define AWB_HWCONF_XPI0                                  \
    {                                                   \
        AWB_HPM_NOR_XPI_DRV_NAME,                       \
        0,                                   \
        AWB_BUS_TYPE_ID_PLB,                                \
        0,                                  \
        &(__g_xpi0_dev.dev),               \
        &__g_xpi0_devinfo,                 \
        "xpi0",                                    \
        NULL,                                           \
    }


#endif  /* __AWBL_HWCONF_HPM_NOR_XPI_0_H */

/* end of file */
