/*
 * MainControl.c
 */
#include "aw_application_autoconf.h"
#include "aworks.h"
#include "string.h"
#include "aw_can.h"
#include "aw_task.h"
#include "aw_delay.h"
#include "aw_vdebug.h"
#include "aw_spinlock.h"
#include "aw_fcntl.h"
#include "rtk_autoconf.h"
#include "aw_unistd.h"
#include "aworks.h"
#include "aw_serial.h"
#include "modbus/aw_mb_slave.h"  /* modbus从站服务 */
#include "modbus/aw_mb_utils.h"  /* modbus从站工具 */
#include "aw_ioctl.h"
#include "aw_gpio.h"
#include "aw_pin.h"
#include "hpm_pin.h"

#define __CAN_TASK_STACK_SIZE     4096        /* CAN报文接收任务堆栈大小 */
#define __CAN_TASK_PRIO           6           /* CAN报文接收任务优先级 */

#define TCP_PORT CONFIG_TCP_PORT
#define __MB_TASK_STACK_SIZE      4096        /* 报文接收任务堆栈大小 */
#define __MB_TASK_PRIO            6           /* 报文接收任务优先级 */

#define __GPIO_TASK_STACK_SIZE    4096        /* 报文接收任务堆栈大小 */
#define __GPIO_TASK_PRIO          6           /* 报文接收任务优先级 */

#define __UART_TASK_STACK_SIZE    4096        /* 报文接收任务堆栈大小 */
#define __UART_TASK_PRIO          6           /* 报文接收任务优先级 */

#define __MAIN_TASK_STACK_SIZE    4096        /* 报文接收任务堆栈大小 */
#define __MAIN_TASK_PRIO          6           /* 报文接收任务优先级 */

#define MB_MASK_WRITE_REG_FUNCODE   22        /**< \brief 写寄存器掩码功能码 */
#define REG_HOLD_ADDR_START  1000             /**< \brief 保持寄存器起始地址 */
#define REG_HOLD_NUM         100              /**< \brief 保持寄存器个数 */
#define REG_INPUT_ADDR_START 1000             /**< \brief 输入寄存器起始地址 */
#define REG_INPUT_NUM        20               /**< \brief 输入寄存器个数 */
#define REG_COIL_ADDR_START  1000             /**< \brief 线圈起始地址 */
#define REG_COIL_NUM         10               /**< \brief 线圈寄存器个数 */

#define ERROR  PIN_PF00
#define LINK   PIN_PF04
#define RUN    PIN_PF08

#undef AW_INFOF
#define AW_INFOF(x) aw_kprintf(CONFIG_CAN0_DEVICE_NAME":"); aw_kprintf x

aw_local uint16_t g_holding_reg[REG_HOLD_NUM];    /**< \brief 保持寄存器 AI RTD TC */
aw_local uint8_t  g_coil_reg[REG_COIL_NUM];       /**< \brief 线圈个数 8 x REG_COIL_NUM = 80 bit  DI DO */
aw_local uint16_t g_input_reg[REG_INPUT_NUM] = {  /**< \brief 输入寄存器 AO */
    0,   1,  2,  3,  4,  5,  6,  7,  8,  9,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29 };

aw_local uint8_t Flag_DAC = 0;
aw_local uint8_t CH_DAC = 0;

uint8_t Flag_DO = 0;
uint8_t Bk_coil_reg[4] = {0, 0, 0, 0};

uint8_t SystemStatus = 0;
uint8_t Can3_Comm_Q = 0;   //板卡取数序列信号量
uint8_t Can3_Comm_Ban = 0; //板卡取数闩锁

/**
 * \brief CAN0 任务入口
 * \param[in] p_arg 任务参数
 * \return 无
 */
aw_local void* __can0_task_handle(void *p_arg)//电力变换模块通信
{
    int                  fd;//, fail_count = 0;
    aw_err_t             ret;
    aw_can_msg_t         can_msg;
    aw_can_work_mode_t   mode;
    aw_can_baudrate_t    can_baud;
    uint32_t             i = 0;
    int                  flag = 0;
    aw_can_bus_status_t  p_bus_status;

    memset(&mode, 0, sizeof(aw_can_work_mode_t));
    /* 配置工作模式 */
    mode.is_loopback = 0;
    mode.recv_self_send = 0;
    mode.is_listen_only = 0;

    memset(&can_msg, 0, sizeof(aw_can_msg_t));
    can_msg.msg_hdr.id = 0x0300;
    can_msg.msg_hdr.is_canfd = 0;
    can_msg.msg_hdr.length = 8;
    // can_msg.msg_hdr.is_send_once = 1;
    memset(&can_msg.msgbuff[0], 0x55, 8);

    /* 配置波特率 */
    can_baud.bps = 500000;
    can_baud.sample_point_factor_min = 800;
    can_baud.sample_point_factor_max = 900;
    can_baud.sample_point_factor = 875;
    can_baud.sample_point_divider = 1000;

    /* 打开CAN*/
    fd = aw_open(CONFIG_CAN0_DEVICE_NAME, AW_O_RDWR, 0);

    if (fd < 0)
    {
        AW_INFOF(("CAN0 open failed:%d!\n", fd));
        while(1);
    }

    /* 设置波特率 */
    ret = aw_can_baudrate_set(fd, &can_baud);
    if(ret != AW_OK)
    {
        AW_INFOF(("CAN0 baudrate set fail.(%d)", ret));
        while(1);
    }
    /* 设置工作模式 */
    ret = aw_can_workmode_set(fd, &mode);
    if(ret != AW_OK)
    {
        AW_INFOF(("CAN0 workmode set fail.(%d)", ret));
        while(1);
    }

    i = 0;
    while (1)
    {
    	//---------------------------------------------
    	//此处循环发送读取电力变换模块通信指令
    	//.....



    	//---------------------------------------------
        ret = aw_read(fd, &can_msg, sizeof(can_msg));
        if (ret > 0)
        {
            if (can_msg.msg_hdr.is_can_event)
            {
                // 其他错误帧暂时不做处理，只处理总线关闭
                ret = aw_can_bus_status_get(fd, &p_bus_status);
                if (AW_CAN_BUS_STATUS_OFF == p_bus_status)
                {break;}
            }
            else
            {
            	// 处理电力变换模块通信数据，发送到MB(ModBus)
            }
        }
    }

    aw_close(fd);
    return 0;
}
/**
 * \brief CAN2 任务入口
 * \param[in] p_arg 任务参数
 * \return 无
 */
aw_local void* __can2_task_handle(void *p_arg)//燃料电池模块通信
{
    int                  fd;//, fail_count = 0;
    aw_err_t             ret;
    aw_can_msg_t         can_msg;
    aw_can_work_mode_t   mode;
    aw_can_baudrate_t    can_baud;
    uint32_t             i = 0;
    int                  flag = 0;
    aw_can_bus_status_t  p_bus_status;

    memset(&mode, 0, sizeof(aw_can_work_mode_t));
    /* 配置工作模式 */
    mode.is_loopback = 0;
    mode.recv_self_send = 0;
    mode.is_listen_only = 0;
    mode.is_non_iso = 0;

    memset(&can_msg, 0, sizeof(aw_can_msg_t));
    can_msg.msg_hdr.id = 0x11;
    can_msg.msg_hdr.is_canfd = 0;
    can_msg.msg_hdr.length = 8;
    // can_msg.msg_hdr.is_send_once = 1;
    memset(&can_msg.msgbuff[0], 0xAA, 8);

    /* 配置波特率 */
    can_baud.bps = 500000;
    can_baud.sample_point_factor_min = 800;
    can_baud.sample_point_factor_max = 900;
    can_baud.sample_point_factor = 875;
    can_baud.sample_point_divider = 1000;
    /* 打开CAN*/
    fd = aw_open(CONFIG_CAN2_DEVICE_NAME, AW_O_RDWR, 0);

    if (fd < 0)
    {
        AW_INFOF(("CAN2 open failed:%d!\n", fd));
        while(1);
    }

    /* 设置波特率 */
    ret = aw_can_baudrate_set(fd, &can_baud);
    if(ret != AW_OK)
    {
        AW_INFOF(("CAN2 baudrate set fail.(%d)", ret));
        while(1);
    }
    /* 设置工作模式 */
    ret = aw_can_workmode_set(fd, &mode);
    if(ret != AW_OK)
    {
        AW_INFOF(("CAN2 workmode set fail.(%d)", ret));
        while(1);
    }

    i = 0;
    while (1)
    {
    	//---------------------------------------------
    	//此处循环发送读取燃料电池模块通信指令
    	//.....



    	//---------------------------------------------
    	//接收来自于燃料电池模块通信的数据帧
        ret = aw_read(fd, &can_msg, sizeof(can_msg));
        if (ret > 0)
        {
            if (can_msg.msg_hdr.is_can_event)
            {
                // 其他错误帧暂时不做处理，只处理总线关闭
                ret = aw_can_bus_status_get(fd, &p_bus_status);
                if (AW_CAN_BUS_STATUS_OFF == p_bus_status)
                {break;}
            }
            else
            {
            	//处理读取到的数据，发送到MB(ModBus)
            }
        }
    }

    aw_close(fd);
    return 0;
}
/**
 * \brief CAN3 任务入口
 * \param[in] p_arg 任务参数
 * \return 无
 */
aw_local void* __can3_task_handle(void *p_arg)
{
    int                  fd;//, fail_count = 0;
    aw_err_t             ret;
    aw_can_msg_t         can_msg;
    aw_can_work_mode_t   mode;
    aw_can_baudrate_t    can_baud;
    uint32_t             i = 0;
    //int                  flag = 0;
    aw_can_bus_status_t  p_bus_status;
    uint64_t ts = 0;
    uint8_t Dat_index = 0;

    memset(&mode, 0, sizeof(aw_can_work_mode_t));
    /* 配置工作模式 */
    mode.is_loopback = 0;
    mode.recv_self_send = 0;
    mode.is_listen_only = 0;

    memset(&can_msg, 0, sizeof(aw_can_msg_t));
    can_msg.msg_hdr.id = 0x11;
    can_msg.msg_hdr.is_canfd = 0;
    can_msg.msg_hdr.length = 8;
    // can_msg.msg_hdr.is_send_once = 1;
    memset(&can_msg.msgbuff[0], 0x11, 8);

    /* 配置波特率 */
    can_baud.bps = 500000;
    can_baud.sample_point_factor_min = 800;
    can_baud.sample_point_factor_max = 900;
    can_baud.sample_point_factor = 875;
    can_baud.sample_point_divider = 1000;

    /* 打开CAN*/
    fd = aw_open(CONFIG_CAN3_DEVICE_NAME, AW_O_RDWR, 0);

    if (fd < 0)
    {
        AW_INFOF(("CAN3 open failed:%d!\n", fd));
        while(1);
    }

    /* 设置波特率 */
    ret = aw_can_baudrate_set(fd, &can_baud);
    if(ret != AW_OK)
    {
        AW_INFOF(("CAN3 baudrate set fail.(%d)", ret));
        while(1);
    }
    /* 设置工作模式 */
    ret = aw_can_workmode_set(fd, &mode);
    if(ret != AW_OK)
    {
        AW_INFOF(("CAN3 workmode set fail.(%d)", ret));
        while(1);
    }

    i = 0;
    while (1)
    {
    	if(Flag_DAC == 1) //接到MB传来的DAC信息信号量
    	{
    		Flag_DAC = 0;

    		can_msg.msg_hdr.id = 0x0400;
    		can_msg.msgbuff[0] = CH_DAC + 1;
    		can_msg.msgbuff[1] = g_holding_reg[CH_DAC] / 100;
    		can_msg.msgbuff[2] = g_holding_reg[CH_DAC] - can_msg.msgbuff[1] * 100;
    		can_msg.msgbuff[3] = 0;
    		can_msg.msgbuff[4] = 0;
    		can_msg.msgbuff[5] = 0;
    		can_msg.msgbuff[6] = 0;
    		can_msg.msgbuff[7] = 0;

    		ret = aw_can_sendmsg(fd, &can_msg, sizeof(can_msg), &ts, 8);
    		if (ret < 0){ AW_INFOF(("CAN3 send DAC failed:%d\n", ret)); }
    	}
    	//---------------------------------------------
    	if(Flag_DO == 1) //接到MB传来的DO信息信号量
    	{
    		Flag_DO = 0;

    		if(Bk_coil_reg[0] != g_coil_reg[0])
    		{
    			Dat_index = Bk_coil_reg[0] ^ g_coil_reg[0];

    			if((g_coil_reg[0] & Dat_index) == 0)
    			{
    				can_msg.msgbuff[1] = 0x00;
    			}
    			else
    			{
    				can_msg.msgbuff[1] = 0x01;
    			}

    			for(i=0;i<8;i++)
    			{
    				if(Dat_index != 0){	Dat_index >>= 1;}
    				else{break;}
    			}

		    	can_msg.msg_hdr.id = 0x0200;
		    	can_msg.msgbuff[0] = i;
		    	//can_msg.msgbuff[1] = 0;
		    	can_msg.msgbuff[2] = 0;
		    	can_msg.msgbuff[3] = 0;
		    	can_msg.msgbuff[4] = 0;
		    	can_msg.msgbuff[5] = 0;
		    	can_msg.msgbuff[6] = 0;
		    	can_msg.msgbuff[7] = 0;

		    	ret = aw_can_sendmsg(fd, &can_msg, sizeof(can_msg), &ts, 8);
		    	if (ret < 0){ AW_INFOF(("CAN3 send DO failed:%d\n", ret)); }

    			Bk_coil_reg[0] = g_coil_reg[0];
    			i = 0;
    		}
    	}
    	//---------------------------------------------
    	//此处循环发送读取DI板卡、AI板卡、RTD板卡*2、TC板卡指令
    	//.....



    	//---------------------------------------------
    	//接收来自于板卡的数据帧
        ret = aw_read(fd, &can_msg, sizeof(can_msg));
        if (ret > 0)
        {
            if (can_msg.msg_hdr.is_can_event)
            {
                // 其他错误帧暂时不做处理，只处理总线关闭
                ret = aw_can_bus_status_get(fd, &p_bus_status);
                if (AW_CAN_BUS_STATUS_OFF == p_bus_status)
                {break;}
            }
            else
            {
            	aw_gpio_toggle(RUN);
                // 处理接收到的板卡数据,仅为框架还需处理
            	switch(can_msg.msg_hdr.id)
            	{
            	case 101:
            		g_input_reg[i] = can_msg.msgbuff[i];
            		break;
            	case 201:
            		g_input_reg[i] = can_msg.msgbuff[i];
            		break;
            	case 301:
            		g_input_reg[i] = can_msg.msgbuff[i];
            		break;
            	case 401:
            		g_input_reg[i] = can_msg.msgbuff[i];
            		break;
            	case 501:
            		g_input_reg[i] = can_msg.msgbuff[i];
            		break;
            	case 601:
            		g_input_reg[i] = can_msg.msgbuff[i];
            		break;
            	}
            }
        }
    }

    aw_close(fd);
    return 0;
}
/**
 * \brief UART5 任务入口
 * \return 无
 */
aw_local void* __serial_task_handle (void *parg)
{
    char                      buf[32];
    int                       len = 0;
    struct  aw_serial_dcb     dcb;
    aw_err_t                  ret;
    struct aw_serial_timeout  timeout;
    int                       fd;

    fd = aw_open(CONFIG_DEMO_SERIAL_DEVICE_NAME, AW_O_RDWR, 0);
    if(fd < 0)
    {
        aw_kprintf("serial open failed\r\n");
        aw_close(fd);
        return 0;
    }

    /* 获取dcb的默认配置 */
    ret = aw_serial_dcb_get(fd, &dcb);
    if (AW_OK != ret)
    {
        aw_kprintf("serial get dcb failed: %d \r\n", ret);
        aw_close(fd);
        return 0;
    }

    /* 配置串口波特率为115200，8个数据位，1位停止位，无奇偶校验 */
    dcb.baud_rate = 115200;
    dcb.byte_size = 8;
    dcb.stop_bits = AW_SERIAL_ONESTOPBIT;
    dcb.f_parity = AW_FALSE;
    ret = aw_serial_dcb_set(fd, &dcb);
    if (AW_OK != ret)
    {
        aw_kprintf("serial set dcb failed: %d \r\n", ret);
        aw_close(fd);
        return 0;
    }

    /* 配置串口超时 */
    ret = aw_serial_timeout_get(fd, &timeout);
    if (AW_OK != ret)
    {
        aw_kprintf("serial get timeout failed: %d \r\n", ret);
        aw_close(fd);
        return 0;
    }

    timeout.rd_timeout = 1000;          /* 读总超时为1s */
    timeout.rd_interval_timeout = 50;   /* 码间超时为50ms */
    ret = aw_serial_timeout_set(fd, &timeout);
    if (AW_OK != ret)
    {
        aw_kprintf("serial set dcb failed: %d \r\n", ret);
        aw_close(fd);
        return 0;
    }

    /* 收到什么数据就发送什么数据 */
    AW_FOREVER
	{
    	//循环发送读取 氢气流量计、供料控制箱数据指令
    	//....
    	//aw_write(fd, buf, len);
    	//-------------------------------
        /* 读取串口缓冲区数据 */
        memset(buf, 0, sizeof(buf));
        len = aw_read(fd, buf, sizeof(buf));
        if (len > 0)
        {
        	//处理串口读到的数据，发送到MB
        	//....


            //aw_write(fd, buf, len);    //串口输出收到的信息
            //aw_kprintf("%s\r\n", buf); //调试口输出收到的信息
        }
    }

    aw_close(fd);
    return 0;
}
/**
 * \brief GPIO 任务入口
 * \return 无
 */
aw_local void* __gpio_task_handle(void *p_arg)
{
    int i = 0;

    aw_kprintf("\nGPIO demo testing...\r\n");

    aw_pin_cfg(ERROR, AW_PIN_CFG_GPIO_OUTPUT_HIGH);
    aw_pin_cfg(LINK, AW_PIN_CFG_GPIO_OUTPUT_HIGH);
    aw_pin_cfg(RUN, AW_PIN_CFG_GPIO_OUTPUT_HIGH);

    /* LED以1s的周期闪烁5次 */
    for (i = 0; i < 5; i++)
    {
        aw_gpio_set(ERROR, 0);
        aw_mdelay(500);

        aw_gpio_set(ERROR, 1);
        aw_mdelay(500);
    }

    /* LED以0.2s的周期持续闪烁 */
    for (i = 0; i < 40; i++)
    {
        aw_gpio_toggle(LINK);
        aw_mdelay(100);
    }

    while(1)
    {
    	//以下代码仅供测试使用------------------<
    	if(g_coil_reg[0] == 0x01)
    	{
        	aw_gpio_toggle(ERROR);
            aw_mdelay(1000);
            aw_kprintf("LED ERROR FLASH\r\n");
    	}
    	else if(g_coil_reg[0] == 0x02)
    	{
            aw_gpio_toggle(LINK);
            aw_mdelay(1000);
            aw_kprintf("LED LINK FLASH\r\n");
    	}
    	else if(g_coil_reg[0] == 0x04)
    	{
            aw_gpio_toggle(RUN);
            aw_mdelay(1000);
            aw_kprintf("LED RUN OK!\r\n");
    	}
    	else
    	{
    		aw_gpio_set(ERROR, 1);
    		aw_gpio_set(LINK, 1);
    		aw_gpio_set(RUN, 1);
    	}
    	//-------------------------------->
    }
    aw_kprintf("\nGPIO demo exit...\r\n");
    return 0;
}
/******************************************************************************/
/**
 * \brief 内存提取16位无符号数(大端模式)
 */
aw_local aw_inline uint16_t to_u16 (const uint8_t *buf)
{
    return ((uint16_t)buf[0] << 8) + buf[1];
}
/**
 * \brief 读线圈
 */
aw_local aw_mb_exception_t my_fun_rd_coil (aw_mb_slave_t  slave,
                                           uint8_t       *p_buf,
                                           uint16_t       addr,
                                           uint16_t       num)
{
    if ((addr < REG_COIL_ADDR_START) || num > (REG_COIL_NUM << 3))
    {
        return AW_MB_EXP_ILLEGAL_DATA_ADDRESS;
    }

    /* 读线圈值到buf中 */
    aw_mb_bits_cp_to_buf(p_buf, g_coil_reg, addr - REG_COIL_ADDR_START, num);
    return AW_MB_EXP_NONE;
}
/**
 * \brief 写线圈
 */
aw_local aw_mb_exception_t my_fun_wr_coil (aw_mb_slave_t  slave,
                                           uint8_t       *p_buf,
                                           uint16_t       addr,
                                           uint16_t       num)
{

    if ((addr < REG_COIL_ADDR_START) || num > (REG_COIL_NUM << 3))
    {
        return AW_MB_EXP_ILLEGAL_DATA_ADDRESS;
    }

    /* 将buf缓冲区值写到指定线圈 */
    aw_mb_bits_set_from_buf(g_coil_reg, p_buf, addr-REG_COIL_ADDR_START, num);

    Flag_DO = 1;
    //CH_DO = addr - REG_COIL_ADDR_START;
    return AW_MB_EXP_NONE;
}
/**
 * \brief 读保持寄存器
 */
aw_local aw_mb_exception_t my_fun_rd_holdreg (aw_mb_slave_t  slave,
                                              uint8_t       *p_buf,
                                              uint16_t       addr,
                                              uint16_t       num)
{
    uint8_t index;

    if ((addr < REG_HOLD_ADDR_START) ||
        (addr+num) > (REG_HOLD_ADDR_START+REG_HOLD_NUM))
    {
        return AW_MB_EXP_ILLEGAL_DATA_ADDRESS;
    }

    index = (uint8_t)(addr - REG_HOLD_ADDR_START);

    /* 读取保持寄存器数据到buf中 */
    aw_mb_regcpy(p_buf, &g_holding_reg[index], num);

    return AW_MB_EXP_NONE;
}
/**
 * \brief 写保持寄存器
 */
aw_local aw_mb_exception_t my_fun_wr_holdreg (aw_mb_slave_t  slave,
                                              uint8_t       *p_buf,
                                              uint16_t       addr,
                                              uint16_t       num)
{
    uint8_t index;

    if ((addr < REG_HOLD_ADDR_START) ||
        (addr+num) > (REG_HOLD_ADDR_START+REG_HOLD_NUM))
    {
        return AW_MB_EXP_ILLEGAL_DATA_ADDRESS;
    }

    index = (uint8_t)(addr - REG_HOLD_ADDR_START);

    /* 将buf数据写到保持寄存器数据 */
    aw_mb_regcpy(&g_holding_reg[index], p_buf, num);

    Flag_DAC = 1;
    CH_DAC = index;

    return AW_MB_EXP_NONE;
}
/**
 * \brief 读输入寄存器
 */
aw_local aw_mb_exception_t my_fun_rd_inputreg (aw_mb_slave_t  slave,
                                               uint8_t       *p_buf,
                                               uint16_t       addr,
                                               uint16_t       num)
{
    uint8_t index;

    if ((addr < REG_INPUT_ADDR_START) ||
        (addr + num) > (REG_INPUT_ADDR_START+REG_INPUT_NUM))
    {
        return AW_MB_EXP_ILLEGAL_DATA_ADDRESS;
    }

    index = (uint8_t)(addr - REG_INPUT_ADDR_START);

    /* 读取输入寄存器数据到buf中 */
    aw_mb_regcpy(p_buf, &g_input_reg[index], num);

    return AW_MB_EXP_NONE;
}
/**
 * \brief 扩展写寄存器功能码掩码
 */
aw_local aw_mb_exception_t my_mask_write (aw_mb_slave_t  slave,
                                          uint8_t       *p_pdu,
                                          uint16_t      *p_len)
{
    uint16_t addr, and, or;

    if (*p_len != 7)
    {
        return AW_MB_EXP_ILLEGAL_DATA_VALUE;
    }

    addr = to_u16(p_pdu + 1);
    and  = to_u16(p_pdu + 3);
    or   = to_u16(p_pdu + 5);

    if ((addr < REG_HOLD_ADDR_START) || (addr > REG_HOLD_ADDR_START+REG_HOLD_NUM) )
    {
        return AW_MB_EXP_ILLEGAL_DATA_ADDRESS;
    }

    g_holding_reg[addr - REG_HOLD_ADDR_START] &= and;
    g_holding_reg[addr - REG_HOLD_ADDR_START] |= or;

    return AW_MB_EXP_NONE;
}
/******************************************************************************/
/**
 * \brief Modbus tcp 从站任务入口
 * \param[in] p_arg : 任务参数
 * \return 无
 */
aw_local void* __modbus_task_handle (void *p_arg)
{
    uint8_t       again;
    aw_mb_err_t   err;
    aw_mb_slave_t slave;
    int           param = TCP_PORT;  /* tcp端口号  */
    /* Modbus从机RTU模式初始化 */

    slave = aw_mb_slave_init(AW_MB_TCP, &param, &err);

    AW_INFOF(("\nModbus tcp Slave init =  %d \n", slave));

    if (err != AW_MB_ERR_NOERR)
    {
        return 0;
    }

    /* 读线圈回调 */
    aw_mb_slave_register_callback(slave,
                                  AW_MB_FUNC_COILS_CALLBACK,
                                  AW_MB_FUNC_CALLBACK_READ,
                                  my_fun_rd_coil);

    /* 读离散量回调 */
    aw_mb_slave_register_callback(slave,
                                  AW_MB_FUNC_DISCRETEINPUTS_CALLBACK,
                                  AW_MB_FUNC_CALLBACK_READ,
                                  my_fun_rd_coil);

    /* 写线圈回调 */
    aw_mb_slave_register_callback(slave,
                                  AW_MB_FUNC_COILS_CALLBACK,
                                  AW_MB_FUNC_CALLBACK_WRITE,
                                    my_fun_wr_coil);

    /* 读保持寄存器回调 */
    aw_mb_slave_register_callback(slave,
                                  AW_MB_FUNC_HOLDREGISTERS_CALLBACK,
                                  AW_MB_FUNC_CALLBACK_READ,
                                  my_fun_rd_holdreg);

    /* 写保持寄存器回调 */
    aw_mb_slave_register_callback(slave,
                                  AW_MB_FUNC_HOLDREGISTERS_CALLBACK,
                                  AW_MB_FUNC_CALLBACK_WRITE,
                                  my_fun_wr_holdreg);

    /* 读输入寄存器回调 */
    aw_mb_slave_register_callback(slave,
                                  AW_MB_FUNC_INPUTREGISTERS_CALLBACK,
                                  AW_MB_FUNC_CALLBACK_READ,
                                  my_fun_rd_inputreg);

    /* 注册扩展功能码处理函数 */
    aw_mb_slave_register_handler(slave,
                                 MB_MASK_WRITE_REG_FUNCODE,
                                 my_mask_write);

    /* 开始运行 */
    err = aw_mb_slave_start(slave);
    if (err != AW_MB_ERR_NOERR)
    {
        return 0;
    }

    AW_INFOF(("\nModbus tcp Slave start.\n"));

    again = 0;
    AW_FOREVER
	{
        err = aw_mb_slave_poll(slave);    /* 从机轮询操作 */
        if (err != AW_MB_ERR_NOERR )
        {
            again++;
        }

        if (again > 20)
        {
            break;
        }
        aw_mdelay(5);
    }

    AW_INFOF(("\nModbus Slave exit.\n"));
    aw_mb_slave_stop(slave);    /* 停止从机 */
    aw_mb_slave_close(slave);   /* 关闭从机，退出 */

    return 0;
}
/**
 * \brief Main 任务入口
 * \param[in] p_arg : 任务参数
 * \return 无
 */
aw_local void* __Main_task_handle (void *p_arg)
{
    AW_FOREVER
	{
    	//运行状态判断
    	//.....读取MB数组数据进行比较

    	//顺序控制状态机 SystemStatus 可以通过MB总线写入
    	switch(SystemStatus)
    	{
    	case 0://预检

    		break;
    	case 1://联锁

    		break;
    	case 2://起动

    		break;
    	case 3://运行

    		break;
    	case 4://停机

    		break;
    	case 5://热待机

    		break;
    	case 6://复位

    		break;
    	case 7://急停

    		break;
    	case 8:

    		break;
    	case 9:

    		break;
    	case 10:

    		break;
    	}
	}
	return 0;
}
/*----------------------------------------------------------------------------*/
/*--------------------------------任务实例---------------------------------------*/
/*----------------------------------------------------------------------------*/
AW_TASK_DECL(_modbus_task, __MB_TASK_STACK_SIZE);
AW_TASK_DECL(_can0_task, __CAN_TASK_STACK_SIZE);
AW_TASK_DECL(_can2_task, __CAN_TASK_STACK_SIZE);
AW_TASK_DECL(_can3_task, __CAN_TASK_STACK_SIZE);
AW_TASK_DECL(_serial_tsk, __UART_TASK_STACK_SIZE);
AW_TASK_DECL(_gpio_task, __GPIO_TASK_STACK_SIZE);
AW_TASK_DECL(_Main_task, __GPIO_TASK_STACK_SIZE);
/*----------------------------------------------------------------------------*/
/*--------------------------------主控入口---------------------------------------*/
/*----------------------------------------------------------------------------*/
void MainControl_entry(void)
{
    aw_task_id_t tsk;
    //ModBus 收发任务，用于上位机通信
    tsk = AW_TASK_INIT(_modbus_task, "MB TASK", __MB_TASK_PRIO, __MB_TASK_STACK_SIZE, __modbus_task_handle, (void *)NULL);
    if (tsk == NULL){ AW_INFOF(("MB task create failed\r\n")); return; }
    if (aw_task_startup(tsk) != AW_OK){ AW_TASK_TERMINATE(_modbus_task); }
    //CAN0口收发任务，电力变换模块通信
    tsk = AW_TASK_INIT(_can0_task, "CAN0 TASK", __CAN_TASK_PRIO, __CAN_TASK_STACK_SIZE, __can0_task_handle, (void *)NULL);
    if (tsk == NULL){ AW_INFOF(("CAN0 task create failed\r\n")); return; }
    if (aw_task_startup(tsk) != AW_OK){ AW_TASK_TERMINATE(_can0_task); }
    //CAN2口收发任务，燃料电池模块通信
    tsk = AW_TASK_INIT(_can2_task, "CAN2 TASK", __CAN_TASK_PRIO, __CAN_TASK_STACK_SIZE, __can2_task_handle, (void *)NULL);
    if (tsk == NULL){ AW_INFOF(("CAN2 task create failed\r\n")); return; }
    if (aw_task_startup(tsk) != AW_OK){ AW_TASK_TERMINATE(_can2_task); }
    //CAN3口收发任务，用于板卡控制
    tsk = AW_TASK_INIT(_can3_task, "CAN3 TASK", __CAN_TASK_PRIO, __CAN_TASK_STACK_SIZE, __can3_task_handle, (void *)NULL);
    if (tsk == NULL){ AW_INFOF(("CAN3 task create failed\r\n")); return; }
    if (aw_task_startup(tsk) != AW_OK){ AW_TASK_TERMINATE(_can3_task); }
    //串口5收发任务，用于氢气流量计、供料控制箱
    tsk = AW_TASK_INIT(_serial_tsk, "UART5 TASK", __UART_TASK_PRIO, __UART_TASK_STACK_SIZE, __serial_task_handle, (void *)NULL);
    if (tsk == NULL){ AW_INFOF(("UART5 task create failed\r\n")); return; }
    if (aw_task_startup(tsk) != AW_OK){	AW_TASK_TERMINATE(_serial_tsk); }
    //GPIO控制任务，用于指示灯显示
    tsk = AW_TASK_INIT(_gpio_task, "GPIO TASK", __GPIO_TASK_PRIO, __GPIO_TASK_STACK_SIZE, __gpio_task_handle, (void *)NULL);
    if (tsk == NULL){ AW_INFOF(("GPIO task create failed\r\n")); return; }
    if (aw_task_startup(tsk) != AW_OK){ AW_TASK_TERMINATE(_gpio_task); }
    //顺序控制任务
    tsk = AW_TASK_INIT(_Main_task, "MAIN TASK", __MAIN_TASK_PRIO, __MAIN_TASK_STACK_SIZE, __Main_task_handle, (void *)NULL);
    if (tsk == NULL){ AW_INFOF(("MAIN  task create failed\r\n")); return; }
    if (aw_task_startup(tsk) != AW_OK){ AW_TASK_TERMINATE(_Main_task); }
}
















