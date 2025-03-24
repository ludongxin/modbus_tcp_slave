/*******************************************************************************
*                                 AWorks
*                       ---------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2012 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

#include "aworks.h"
#include "aw_delay.h"
#include "aw_vdebug.h"

void MainControl_entry(void);

int aw_main()
{
	//unsigned int total, free;

    aw_kprintf("\r\nApplication Start. \r\n");
    aw_mdelay(3000);

    MainControl_entry();

    while(1)
    {
    	aw_mdelay(100);
	}

    return 0;
}


/* end of file*/
