begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Device driver for Specialix range (SI/XIO) of serial line multiplexors.  * 'C' definitions for Specialix serial multiplex driver.  *  * Copyright (C) 1990, 1992, 1998 Specialix International,  * Copyright (C) 1993, Andy Rutter<andy@acronym.co.uk>  * Copyright (C) 1995, Peter Wemm<peter@netplex.com.au>  *  * Derived from:	SunOS 4.x version  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notices, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notices, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Andy Rutter of  *	Advanced Methods and Tools Ltd. based on original information  *	from Specialix International.  * 4. Neither the name of Advanced Methods and Tools, nor Specialix  *    International may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN  * NO EVENT SHALL THE AUTHORS BE LIABLE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_comment
comment|/*  * We name devices with %r in make_dev() with a radix of 32.  */
end_comment

begin_define
define|#
directive|define
name|SI_MAXPORTPERCARD
value|32
end_define

begin_comment
comment|/* Buffer parameters */
end_comment

begin_define
define|#
directive|define
name|SI_BUFFERSIZE
value|256
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|BYTE
typedef|;
end_typedef

begin_comment
comment|/* Type cast for unsigned 8 bit */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|WORD
typedef|;
end_typedef

begin_comment
comment|/* Type cast for unsigned 16 bit */
end_comment

begin_comment
comment|/*  * Hardware `registers', stored in the shared memory.  * These are related to the firmware running on the Z280.  */
end_comment

begin_struct
struct|struct
name|si_reg
block|{
name|BYTE
name|initstat
decl_stmt|;
name|BYTE
name|memsize
decl_stmt|;
name|WORD
name|int_count
decl_stmt|;
name|WORD
name|revision
decl_stmt|;
name|BYTE
name|rx_int_count
decl_stmt|;
comment|/* isr_count on Jet */
name|BYTE
name|main_count
decl_stmt|;
comment|/* spare on Z-280 */
name|WORD
name|int_pending
decl_stmt|;
name|WORD
name|int_counter
decl_stmt|;
name|BYTE
name|int_scounter
decl_stmt|;
name|BYTE
name|res
index|[
literal|0x80
operator|-
literal|13
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Per module control structure, stored in shared memory.  */
end_comment

begin_struct
struct|struct
name|si_module
block|{
name|WORD
name|sm_next
decl_stmt|;
comment|/* Next module */
name|BYTE
name|sm_type
decl_stmt|;
comment|/* Number of channels */
name|BYTE
name|sm_number
decl_stmt|;
comment|/* Module number on cable */
name|BYTE
name|sm_dsr
decl_stmt|;
comment|/* Private dsr copy */
name|BYTE
name|sm_res
index|[
literal|0x80
operator|-
literal|5
index|]
decl_stmt|;
comment|/* Reserve space to 128 bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	The 'next' pointer& with 0x7fff + SI base address give  *	the address of the next module block if fitted. (else 0)  *	Note that next points to the TX buffer so 0x60 must be  *	subtracted to find the true base.  */
end_comment

begin_define
define|#
directive|define
name|TA4
value|0x00
end_define

begin_define
define|#
directive|define
name|TA8
value|0x08
end_define

begin_define
define|#
directive|define
name|TA4_ASIC
value|0x0A
end_define

begin_define
define|#
directive|define
name|TA8_ASIC
value|0x0B
end_define

begin_define
define|#
directive|define
name|MTA
value|0x28
end_define

begin_define
define|#
directive|define
name|SXDC
value|0x48
end_define

begin_comment
comment|/*  *	Per channel(port) control structure, stored in shared memory.  */
end_comment

begin_struct
struct|struct
name|si_channel
block|{
comment|/* 	 * Generic stuff 	 */
name|WORD
name|next
decl_stmt|;
comment|/* Next Channel */
name|WORD
name|addr_uart
decl_stmt|;
comment|/* Uart address */
name|WORD
name|module
decl_stmt|;
comment|/* address of module struct */
name|BYTE
name|type
decl_stmt|;
comment|/* Uart type */
name|BYTE
name|fill
decl_stmt|;
comment|/* 	 * Uart type specific stuff 	 */
name|BYTE
name|x_status
decl_stmt|;
comment|/* XON / XOFF status */
name|BYTE
name|c_status
decl_stmt|;
comment|/* cooking status */
name|BYTE
name|hi_rxipos
decl_stmt|;
comment|/* stuff into rx buff */
name|BYTE
name|hi_rxopos
decl_stmt|;
comment|/* stuff out of rx buffer */
name|BYTE
name|hi_txopos
decl_stmt|;
comment|/* Stuff into tx ptr */
name|BYTE
name|hi_txipos
decl_stmt|;
comment|/* ditto out */
name|BYTE
name|hi_stat
decl_stmt|;
comment|/* Command register */
name|BYTE
name|dsr_bit
decl_stmt|;
comment|/* Magic bit for DSR */
name|BYTE
name|txon
decl_stmt|;
comment|/* TX XON char */
name|BYTE
name|txoff
decl_stmt|;
comment|/* ditto XOFF */
name|BYTE
name|rxon
decl_stmt|;
comment|/* RX XON char */
name|BYTE
name|rxoff
decl_stmt|;
comment|/* ditto XOFF */
name|BYTE
name|hi_mr1
decl_stmt|;
comment|/* mode 1 image */
name|BYTE
name|hi_mr2
decl_stmt|;
comment|/* mode 2 image */
name|BYTE
name|hi_csr
decl_stmt|;
comment|/* clock register */
name|BYTE
name|hi_op
decl_stmt|;
comment|/* Op control */
name|BYTE
name|hi_ip
decl_stmt|;
comment|/* Input pins */
name|BYTE
name|hi_state
decl_stmt|;
comment|/* status */
name|BYTE
name|hi_prtcl
decl_stmt|;
comment|/* Protocol */
name|BYTE
name|hi_txon
decl_stmt|;
comment|/* host copy tx xon stuff */
name|BYTE
name|hi_txoff
decl_stmt|;
name|BYTE
name|hi_rxon
decl_stmt|;
name|BYTE
name|hi_rxoff
decl_stmt|;
name|BYTE
name|close_prev
decl_stmt|;
comment|/* Was channel previously closed */
name|BYTE
name|hi_break
decl_stmt|;
comment|/* host copy break process */
name|BYTE
name|break_state
decl_stmt|;
comment|/* local copy ditto */
name|BYTE
name|hi_mask
decl_stmt|;
comment|/* Mask for CS7 etc. */
name|BYTE
name|mask_z280
decl_stmt|;
comment|/* Z280's copy */
name|BYTE
name|res
index|[
literal|0x60
operator|-
literal|36
index|]
decl_stmt|;
name|BYTE
name|hi_txbuf
index|[
name|SI_BUFFERSIZE
index|]
decl_stmt|;
name|BYTE
name|hi_rxbuf
index|[
name|SI_BUFFERSIZE
index|]
decl_stmt|;
name|BYTE
name|res1
index|[
literal|0xA0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Register definitions  */
end_comment

begin_comment
comment|/*  *	Break input control register definitions  */
end_comment

begin_define
define|#
directive|define
name|BR_IGN
value|0x01
end_define

begin_comment
comment|/* Ignore any received breaks */
end_comment

begin_define
define|#
directive|define
name|BR_INT
value|0x02
end_define

begin_comment
comment|/* Interrupt on received break */
end_comment

begin_define
define|#
directive|define
name|BR_PARMRK
value|0x04
end_define

begin_comment
comment|/* Enable parmrk parity error processing */
end_comment

begin_define
define|#
directive|define
name|BR_PARIGN
value|0x08
end_define

begin_comment
comment|/* Ignore chars with parity errors */
end_comment

begin_comment
comment|/*  *	Protocol register provided by host for XON/XOFF and cooking  */
end_comment

begin_define
define|#
directive|define
name|SP_TANY
value|0x01
end_define

begin_comment
comment|/* Tx XON any char */
end_comment

begin_define
define|#
directive|define
name|SP_TXEN
value|0x02
end_define

begin_comment
comment|/* Tx XON/XOFF enabled */
end_comment

begin_define
define|#
directive|define
name|SP_CEN
value|0x04
end_define

begin_comment
comment|/* Cooking enabled */
end_comment

begin_define
define|#
directive|define
name|SP_RXEN
value|0x08
end_define

begin_comment
comment|/* Rx XON/XOFF enabled */
end_comment

begin_define
define|#
directive|define
name|SP_DCEN
value|0x20
end_define

begin_comment
comment|/* DCD / DTR check */
end_comment

begin_define
define|#
directive|define
name|SP_PAEN
value|0x80
end_define

begin_comment
comment|/* Parity checking enabled */
end_comment

begin_comment
comment|/*  *	HOST STATUS / COMMAND REGISTER  */
end_comment

begin_define
define|#
directive|define
name|IDLE_OPEN
value|0x00
end_define

begin_comment
comment|/* Default mode, TX and RX polled 				   buffer updated etc */
end_comment

begin_define
define|#
directive|define
name|LOPEN
value|0x02
end_define

begin_comment
comment|/* Local open command (no modem ctl */
end_comment

begin_define
define|#
directive|define
name|MOPEN
value|0x04
end_define

begin_comment
comment|/* Open and monitor modem lines (blocks 				   for DCD */
end_comment

begin_define
define|#
directive|define
name|MPEND
value|0x06
end_define

begin_comment
comment|/* Wating for DCD */
end_comment

begin_define
define|#
directive|define
name|CONFIG
value|0x08
end_define

begin_comment
comment|/* Channel config has changed */
end_comment

begin_define
define|#
directive|define
name|CLOSE
value|0x0A
end_define

begin_comment
comment|/* Close channel */
end_comment

begin_define
define|#
directive|define
name|SBREAK
value|0x0C
end_define

begin_comment
comment|/* Start break */
end_comment

begin_define
define|#
directive|define
name|EBREAK
value|0x0E
end_define

begin_comment
comment|/* End break */
end_comment

begin_define
define|#
directive|define
name|IDLE_CLOSE
value|0x10
end_define

begin_comment
comment|/* Closed channel */
end_comment

begin_define
define|#
directive|define
name|IDLE_BREAK
value|0x12
end_define

begin_comment
comment|/* In a break */
end_comment

begin_define
define|#
directive|define
name|FCLOSE
value|0x14
end_define

begin_comment
comment|/* Force a close */
end_comment

begin_define
define|#
directive|define
name|RESUME
value|0x16
end_define

begin_comment
comment|/* Clear a pending xoff */
end_comment

begin_define
define|#
directive|define
name|WFLUSH
value|0x18
end_define

begin_comment
comment|/* Flush output buffer */
end_comment

begin_define
define|#
directive|define
name|RFLUSH
value|0x1A
end_define

begin_comment
comment|/* Flush input buffer */
end_comment

begin_comment
comment|/*  *	Host status register  */
end_comment

begin_define
define|#
directive|define
name|ST_BREAK
value|0x01
end_define

begin_comment
comment|/* Break received (clear with config) */
end_comment

begin_comment
comment|/*  *	OUTPUT PORT REGISTER  */
end_comment

begin_define
define|#
directive|define
name|OP_CTS
value|0x01
end_define

begin_comment
comment|/* Enable CTS */
end_comment

begin_define
define|#
directive|define
name|OP_DSR
value|0x02
end_define

begin_comment
comment|/* Enable DSR */
end_comment

begin_comment
comment|/*  *	INPUT PORT REGISTER  */
end_comment

begin_define
define|#
directive|define
name|IP_DCD
value|0x04
end_define

begin_comment
comment|/* DCD High */
end_comment

begin_define
define|#
directive|define
name|IP_DTR
value|0x20
end_define

begin_comment
comment|/* DTR High */
end_comment

begin_define
define|#
directive|define
name|IP_RTS
value|0x02
end_define

begin_comment
comment|/* RTS High */
end_comment

begin_define
define|#
directive|define
name|IP_RI
value|0x40
end_define

begin_comment
comment|/* RI  High */
end_comment

begin_comment
comment|/*  *	Mode register and uart specific stuff  */
end_comment

begin_comment
comment|/*  *	MODE REGISTER 1  */
end_comment

begin_define
define|#
directive|define
name|MR1_5_BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|MR1_6_BITS
value|0x01
end_define

begin_define
define|#
directive|define
name|MR1_7_BITS
value|0x02
end_define

begin_define
define|#
directive|define
name|MR1_8_BITS
value|0x03
end_define

begin_comment
comment|/*  *	Parity  */
end_comment

begin_define
define|#
directive|define
name|MR1_ODD
value|0x04
end_define

begin_define
define|#
directive|define
name|MR1_EVEN
value|0x00
end_define

begin_comment
comment|/*  *	Parity mode  */
end_comment

begin_define
define|#
directive|define
name|MR1_WITH
value|0x00
end_define

begin_define
define|#
directive|define
name|MR1_FORCE
value|0x08
end_define

begin_define
define|#
directive|define
name|MR1_NONE
value|0x10
end_define

begin_define
define|#
directive|define
name|MR1_SPECIAL
value|0x18
end_define

begin_comment
comment|/*  *	Error mode  */
end_comment

begin_define
define|#
directive|define
name|MR1_CHAR
value|0x00
end_define

begin_define
define|#
directive|define
name|MR1_BLOCK
value|0x20
end_define

begin_comment
comment|/*  *	Request to send line automatic control  */
end_comment

begin_define
define|#
directive|define
name|MR1_CTSCONT
value|0x80
end_define

begin_comment
comment|/*  *	MODE REGISTER 2  */
end_comment

begin_comment
comment|/*  *	Number of stop bits  */
end_comment

begin_define
define|#
directive|define
name|MR2_1_STOP
value|0x07
end_define

begin_define
define|#
directive|define
name|MR2_2_STOP
value|0x0F
end_define

begin_comment
comment|/*  *	Clear to send automatic testing before character sent  */
end_comment

begin_define
define|#
directive|define
name|MR2_RTSCONT
value|0x10
end_define

begin_comment
comment|/*  *	Reset RTS automatically after sending character?  */
end_comment

begin_define
define|#
directive|define
name|MR2_CTSCONT
value|0x20
end_define

begin_comment
comment|/*  *	Channel mode  */
end_comment

begin_define
define|#
directive|define
name|MR2_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|MR2_AUTO
value|0x40
end_define

begin_define
define|#
directive|define
name|MR2_LOCAL
value|0x80
end_define

begin_define
define|#
directive|define
name|MR2_REMOTE
value|0xC0
end_define

begin_comment
comment|/*  *	CLOCK SELECT REGISTER - this and the code assumes ispeed == ospeed  */
end_comment

begin_comment
comment|/*  * Clocking rates are in lower and upper nibbles.. R = upper, T = lower  */
end_comment

begin_define
define|#
directive|define
name|CLK75
value|0x0
end_define

begin_define
define|#
directive|define
name|CLK110
value|0x1
end_define

begin_comment
comment|/* 110 on XIO!! */
end_comment

begin_define
define|#
directive|define
name|CLK38400
value|0x2
end_define

begin_comment
comment|/* out of sequence */
end_comment

begin_define
define|#
directive|define
name|CLK150
value|0x3
end_define

begin_define
define|#
directive|define
name|CLK300
value|0x4
end_define

begin_define
define|#
directive|define
name|CLK600
value|0x5
end_define

begin_define
define|#
directive|define
name|CLK1200
value|0x6
end_define

begin_define
define|#
directive|define
name|CLK2000
value|0x7
end_define

begin_define
define|#
directive|define
name|CLK2400
value|0x8
end_define

begin_define
define|#
directive|define
name|CLK4800
value|0x9
end_define

begin_define
define|#
directive|define
name|CLK7200
value|0xa
end_define

begin_comment
comment|/* unchecked */
end_comment

begin_define
define|#
directive|define
name|CLK9600
value|0xb
end_define

begin_define
define|#
directive|define
name|CLK19200
value|0xc
end_define

begin_define
define|#
directive|define
name|CLK57600
value|0xd
end_define

begin_comment
comment|/*  * Per-port (channel) soft information structure, stored in the driver.  * This is visible via ioctl()'s.  */
end_comment

begin_struct
struct|struct
name|si_port
block|{
specifier|volatile
name|struct
name|si_channel
modifier|*
name|sp_ccb
decl_stmt|;
name|struct
name|tty
modifier|*
name|sp_tty
decl_stmt|;
name|int
name|sp_pend
decl_stmt|;
comment|/* pending command */
name|int
name|sp_last_hi_ip
decl_stmt|;
comment|/* cached DCD */
name|int
name|sp_state
decl_stmt|;
name|int
name|sp_delta_overflows
decl_stmt|;
name|struct
name|callout_handle
name|lstart_ch
decl_stmt|;
comment|/* For canceling our timeout */
name|int
name|sp_debug
decl_stmt|;
comment|/* debug mask */
name|char
name|sp_name
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sp_state */
end_comment

begin_comment
comment|/*			0x0001	--					*/
end_comment

begin_comment
comment|/*			0x0002	--					*/
end_comment

begin_comment
comment|/*			0x0004	--					*/
end_comment

begin_comment
comment|/*			0x0008	--					*/
end_comment

begin_comment
comment|/*			0x0010	--					*/
end_comment

begin_comment
comment|/*			0x0020	--					*/
end_comment

begin_comment
comment|/*			0x0040	-- 	 				*/
end_comment

begin_comment
comment|/*			0x0080	-- 	 				*/
end_comment

begin_define
define|#
directive|define
name|SS_LSTART
value|0x0100
end_define

begin_comment
comment|/* lstart timeout pending		*/
end_comment

begin_comment
comment|/*			0x0200	--					*/
end_comment

begin_comment
comment|/*			0x0400	--					*/
end_comment

begin_comment
comment|/*			0x0800	--					*/
end_comment

begin_comment
comment|/*  *	Command post flags  */
end_comment

begin_define
define|#
directive|define
name|SI_NOWAIT
value|0x00
end_define

begin_comment
comment|/* Don't wait for command */
end_comment

begin_define
define|#
directive|define
name|SI_WAIT
value|0x01
end_define

begin_comment
comment|/* Wait for complete */
end_comment

begin_comment
comment|/*  *	SI ioctls  */
end_comment

begin_comment
comment|/*  * struct for use by Specialix ioctls - used by siconfig(8)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|sid_port
range|:
literal|5
decl_stmt|,
comment|/* 0 - 31 ports per card */
name|sid_card
range|:
literal|2
decl_stmt|,
comment|/* 0 - 3 cards */
name|sid_control
range|:
literal|1
decl_stmt|;
comment|/* controlling device (all cards) */
block|}
name|sidev_t
typedef|;
end_typedef

begin_struct
struct|struct
name|si_tcsi
block|{
name|sidev_t
name|tc_dev
decl_stmt|;
union|union
block|{
name|int
name|x_int
decl_stmt|;
name|int
name|x_dbglvl
decl_stmt|;
block|}
name|tc_action
union|;
define|#
directive|define
name|tc_card
value|tc_dev.sid_card
define|#
directive|define
name|tc_port
value|tc_dev.sid_port
define|#
directive|define
name|tc_int
value|tc_action.x_int
define|#
directive|define
name|tc_dbglvl
value|tc_action.x_dbglvl
block|}
struct|;
end_struct

begin_struct
struct|struct
name|si_pstat
block|{
name|sidev_t
name|tc_dev
decl_stmt|;
union|union
block|{
name|struct
name|si_port
name|x_siport
decl_stmt|;
name|struct
name|si_channel
name|x_ccb
decl_stmt|;
name|struct
name|tty
name|x_tty
decl_stmt|;
block|}
name|tc_action
union|;
define|#
directive|define
name|tc_siport
value|tc_action.x_siport
define|#
directive|define
name|tc_ccb
value|tc_action.x_ccb
define|#
directive|define
name|tc_tty
value|tc_action.x_tty
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOCTL_MIN
value|96
end_define

begin_define
define|#
directive|define
name|TCSIDEBUG
value|_IOW('S', 96, struct si_tcsi)
end_define

begin_comment
comment|/* Toggle debug */
end_comment

begin_define
define|#
directive|define
name|TCSIRXIT
value|_IOW('S', 97, struct si_tcsi)
end_define

begin_comment
comment|/* RX int throttle */
end_comment

begin_define
define|#
directive|define
name|TCSIIT
value|_IOW('S', 98, struct si_tcsi)
end_define

begin_comment
comment|/* TX int throttle */
end_comment

begin_comment
comment|/* 99 defunct */
end_comment

begin_comment
comment|/* 100 defunct */
end_comment

begin_comment
comment|/* 101 defunct */
end_comment

begin_comment
comment|/* 102 defunct */
end_comment

begin_comment
comment|/* 103 defunct */
end_comment

begin_comment
comment|/* 104 defunct */
end_comment

begin_define
define|#
directive|define
name|TCSISTATE
value|_IOWR('S', 105, struct si_tcsi)
end_define

begin_comment
comment|/* get current state of RTS 						   DCD and DTR pins */
end_comment

begin_comment
comment|/* 106 defunct */
end_comment

begin_define
define|#
directive|define
name|TCSIPORTS
value|_IOR('S', 107, int)
end_define

begin_comment
comment|/* Number of ports found */
end_comment

begin_define
define|#
directive|define
name|TCSISDBG_LEVEL
value|_IOW('S', 108, struct si_tcsi)
end_define

begin_comment
comment|/* equivalent of TCSIDEBUG which sets a 					 * particular debug level (DBG_??? bit 					 * mask), default is 0xffff */
end_comment

begin_define
define|#
directive|define
name|TCSIGDBG_LEVEL
value|_IOWR('S', 109, struct si_tcsi)
end_define

begin_define
define|#
directive|define
name|TCSIGRXIT
value|_IOWR('S', 110, struct si_tcsi)
end_define

begin_define
define|#
directive|define
name|TCSIGIT
value|_IOWR('S', 111, struct si_tcsi)
end_define

begin_comment
comment|/* 112 defunct */
end_comment

begin_comment
comment|/* 113 defunct */
end_comment

begin_comment
comment|/* 114 defunct */
end_comment

begin_comment
comment|/* 115 defunct */
end_comment

begin_comment
comment|/* 116 defunct */
end_comment

begin_comment
comment|/* 117 defunct */
end_comment

begin_define
define|#
directive|define
name|TCSISDBG_ALL
value|_IOW('S', 118, int)
end_define

begin_comment
comment|/* set global debug level */
end_comment

begin_define
define|#
directive|define
name|TCSIGDBG_ALL
value|_IOR('S', 119, int)
end_define

begin_comment
comment|/* get global debug level */
end_comment

begin_comment
comment|/* 120 defunct */
end_comment

begin_comment
comment|/* 121 defunct */
end_comment

begin_comment
comment|/* 122 defunct */
end_comment

begin_comment
comment|/* 123 defunct */
end_comment

begin_define
define|#
directive|define
name|TCSIMODULES
value|_IOR('S', 124, int)
end_define

begin_comment
comment|/* Number of modules found */
end_comment

begin_comment
comment|/* Various stats and monitoring hooks per tty device */
end_comment

begin_define
define|#
directive|define
name|TCSI_PORT
value|_IOWR('S', 125, struct si_pstat)
end_define

begin_comment
comment|/* get si_port */
end_comment

begin_define
define|#
directive|define
name|TCSI_CCB
value|_IOWR('S', 126, struct si_pstat)
end_define

begin_comment
comment|/* get si_ccb */
end_comment

begin_define
define|#
directive|define
name|IOCTL_MAX
value|127
end_define

begin_define
define|#
directive|define
name|IS_SI_IOCTL
parameter_list|(
name|cmd
parameter_list|)
value|((u_int)((cmd)&0xff00) == ('S'<<8)&& \ 		(u_int)((cmd)&0xff)>= IOCTL_MIN&& \ 		(u_int)((cmd)&0xff)<= IOCTL_MAX)
end_define

begin_define
define|#
directive|define
name|CONTROLDEV
value|"/dev/si_control"
end_define

end_unit

