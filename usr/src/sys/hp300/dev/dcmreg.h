begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: dcmreg.h 1.7 92/01/21$  *  *	@(#)dcmreg.h	7.6 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<hp/dev/iotypes.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_struct
struct|struct
name|dcmdevice
block|{
comment|/* host address, only odd bytes addressed */
name|u_char
name|dcm_pad0
decl_stmt|;
name|vu_char
name|dcm_rsid
decl_stmt|;
comment|/* Reset / ID			0001 */
name|u_char
name|dcm_pad1
decl_stmt|;
name|vu_char
name|dcm_ic
decl_stmt|;
comment|/* Interrupt control register	0003 */
name|u_char
name|dcm_pad2
decl_stmt|;
name|vu_char
name|dcm_sem
decl_stmt|;
comment|/* Semaphore register		0005 */
name|u_char
name|dcm_pad3
index|[
literal|0x7ffa
index|]
decl_stmt|;
comment|/* Unaddressable	0006-7fff */
name|u_char
name|dcm_pad4
decl_stmt|;
name|vu_char
name|dcm_iir
decl_stmt|;
comment|/* Interrupt ident register	8001 */
name|u_char
name|dcm_pad5
decl_stmt|;
name|vu_char
name|dcm_cr
decl_stmt|;
comment|/* Command register		8003 */
name|u_char
name|dcm_pad6
index|[
literal|0x3fc
index|]
decl_stmt|;
comment|/* Card scratch		8004-83ff */
struct|struct
name|dcmrfifo
block|{
name|u_char
name|ptr_pad1
decl_stmt|;
name|vu_char
name|data_char
decl_stmt|;
name|u_char
name|ptr_pad2
decl_stmt|;
name|vu_char
name|data_stat
decl_stmt|;
block|}
name|dcm_rfifos
index|[
literal|4
index|]
index|[
literal|0x80
index|]
struct|;
comment|/* Receive queues		8400 */
struct|struct
block|{
name|u_char
name|ptr_pad1
decl_stmt|;
name|vu_char
name|data_data
decl_stmt|;
block|}
name|dcm_bmap
index|[
literal|0x100
index|]
struct|;
comment|/* Bitmap table			8c00 */
struct|struct
block|{
name|u_char
name|ptr_pad
decl_stmt|;
name|vu_char
name|ptr
decl_stmt|;
block|}
name|dcm_rhead
index|[
literal|4
index|]
struct|;
comment|/* Fifo head - receive		8e00 */
struct|struct
block|{
name|u_char
name|ptr_pad
decl_stmt|;
name|vu_char
name|ptr
decl_stmt|;
block|}
name|dcm_rtail
index|[
literal|4
index|]
struct|;
comment|/* Fifo tail - receive		8e08 */
struct|struct
block|{
name|u_char
name|ptr_pad
decl_stmt|;
name|vu_char
name|ptr
decl_stmt|;
block|}
name|dcm_thead
index|[
literal|4
index|]
struct|;
comment|/* Fifo head - transmit		8e10 */
struct|struct
block|{
name|u_char
name|ptr_pad
decl_stmt|;
name|vu_char
name|ptr
decl_stmt|;
block|}
name|dcm_ttail
index|[
literal|4
index|]
struct|;
comment|/* Fifo tail - transmit		8e18 */
struct|struct
block|{
name|u_char
name|pad1
decl_stmt|;
name|vu_char
name|dcm_conf
decl_stmt|;
name|u_char
name|pad2
decl_stmt|;
name|vu_char
name|dcm_baud
decl_stmt|;
block|}
name|dcm_data
index|[
literal|4
index|]
struct|;
comment|/* Configuration registers	8e20 */
struct|struct
name|modemreg
block|{
name|u_char
name|pad0
decl_stmt|;
name|vu_char
name|mdmin
decl_stmt|;
comment|/* Modem in			8e31 */
name|u_char
name|pad1
decl_stmt|;
name|vu_char
name|mdmout
decl_stmt|;
comment|/* Modem out			8e33 */
name|u_char
name|pad2
decl_stmt|;
name|vu_char
name|mdmmsk
decl_stmt|;
comment|/* Modem mask			8e35 */
block|}
name|dcm_modem0
struct|;
struct|struct
block|{
name|u_char
name|pad1
decl_stmt|;
name|vu_char
name|dcm_data
decl_stmt|;
block|}
name|dcm_cmdtab
index|[
literal|4
index|]
struct|;
comment|/* Command tables		8e36 */
struct|struct
block|{
name|u_char
name|pad1
decl_stmt|;
name|vu_char
name|dcm_data
decl_stmt|;
block|}
name|dcm_icrtab
index|[
literal|4
index|]
struct|;
comment|/* Interrupt data		8e3e */
name|u_char
name|dcm_pad10
decl_stmt|;
name|vu_char
name|dcm_stcon
decl_stmt|;
comment|/* Self test condition		8e47 */
name|struct
name|modemreg
name|dcm_modem1
decl_stmt|;
comment|/* 638 Modem port1		8e48 */
name|struct
name|modemreg
name|dcm_modem2
decl_stmt|;
comment|/* 638 Modem port2		8e4e */
name|struct
name|modemreg
name|dcm_modem3
decl_stmt|;
comment|/* 638 Modem port3		8e54 */
name|u_char
name|dcm_pad11
decl_stmt|;
name|vu_char
name|dcm_modemchng
decl_stmt|;
comment|/* 638 Modem change mask	8e5b */
name|u_char
name|dcm_pad12
decl_stmt|;
name|vu_char
name|dcm_modemintr
decl_stmt|;
comment|/* 638 Modem interrupt mask	8e5d */
name|u_char
name|dcm_pad13
index|[
literal|0x82
index|]
decl_stmt|;
comment|/* Undef Shared Ram	8e5e-8edf */
struct|struct
name|dcmtfifo
block|{
name|u_char
name|ptr_pad1
decl_stmt|;
name|vu_char
name|data_char
decl_stmt|;
block|}
name|dcm_tfifos
index|[
literal|4
index|]
index|[
literal|0x10
index|]
struct|;
comment|/* Transmit queues		8ee0 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Overlay structure for port specific queue "registers".  * Starts at offset 0x8E00+(port*2).  */
end_comment

begin_struct
struct|struct
name|dcmpreg
block|{
name|u_char
name|pad0
decl_stmt|;
comment|/* +00 */
name|vu_char
name|r_head
decl_stmt|;
comment|/* +01 */
name|u_char
name|pad1
index|[
literal|7
index|]
decl_stmt|;
comment|/* +02 */
name|vu_char
name|r_tail
decl_stmt|;
comment|/* +09 */
name|u_char
name|pad2
index|[
literal|7
index|]
decl_stmt|;
comment|/* +0A */
name|vu_char
name|t_head
decl_stmt|;
comment|/* +11 */
name|u_char
name|pad3
index|[
literal|7
index|]
decl_stmt|;
comment|/* +12 */
name|vu_char
name|t_tail
decl_stmt|;
comment|/* +19 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dcm_preg
parameter_list|(
name|d
parameter_list|,
name|p
parameter_list|)
value|((struct dcmpreg *)((u_int)(d)+0x8e00+(p)*2))
end_define

begin_comment
comment|/* interface reset/id */
end_comment

begin_define
define|#
directive|define
name|DCMCON
value|0x80
end_define

begin_comment
comment|/* REMOTE/LOCAL switch, read */
end_comment

begin_define
define|#
directive|define
name|DCMID
value|0x5
end_define

begin_comment
comment|/* hardwired card id, read */
end_comment

begin_define
define|#
directive|define
name|DCMRS
value|0x80
end_define

begin_comment
comment|/* software reset, write */
end_comment

begin_comment
comment|/* interrupt control */
end_comment

begin_define
define|#
directive|define
name|DCMIPL
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 4)& 3) + 3)
end_define

begin_comment
comment|/* interupt level, read */
end_comment

begin_define
define|#
directive|define
name|IC_IR
value|0x40
end_define

begin_comment
comment|/* interupt request, read */
end_comment

begin_define
define|#
directive|define
name|IC_IE
value|0x80
end_define

begin_comment
comment|/* interupt enable, write */
end_comment

begin_define
define|#
directive|define
name|IC_ID
value|0x00
end_define

begin_comment
comment|/* interupt disable, write */
end_comment

begin_comment
comment|/* Semaphore control */
end_comment

begin_define
define|#
directive|define
name|SEM_BSY
value|0x80
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|SEM_CLR
value|0xFF
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|SEM_LOCK
parameter_list|(
name|dcm
parameter_list|)
value|while ((dcm)->dcm_sem& SEM_BSY)
end_define

begin_define
define|#
directive|define
name|SEM_UNLOCK
parameter_list|(
name|dcm
parameter_list|)
value|(dcm)->dcm_sem = SEM_CLR
end_define

begin_comment
comment|/* command register */
end_comment

begin_define
define|#
directive|define
name|CR_PORT0
value|0x1
end_define

begin_define
define|#
directive|define
name|CR_PORT1
value|0x2
end_define

begin_define
define|#
directive|define
name|CR_PORT2
value|0x4
end_define

begin_define
define|#
directive|define
name|CR_PORT3
value|0x8
end_define

begin_define
define|#
directive|define
name|CR_MODM
value|0x10
end_define

begin_comment
comment|/* change modem output lines */
end_comment

begin_define
define|#
directive|define
name|CR_TIMER
value|0x20
end_define

begin_comment
comment|/* 16ms interrupt timer toggle */
end_comment

begin_define
define|#
directive|define
name|CR_SELFT
value|0x40
end_define

begin_comment
comment|/* run self test */
end_comment

begin_define
define|#
directive|define
name|CR_MASK
value|0x7f
end_define

begin_comment
comment|/* interrupt ident register */
end_comment

begin_define
define|#
directive|define
name|IIR_PORT0
value|0x1
end_define

begin_define
define|#
directive|define
name|IIR_PORT1
value|0x2
end_define

begin_define
define|#
directive|define
name|IIR_PORT2
value|0x4
end_define

begin_define
define|#
directive|define
name|IIR_PORT3
value|0x8
end_define

begin_define
define|#
directive|define
name|IIR_SELFT
value|0x10
end_define

begin_comment
comment|/* self test completed */
end_comment

begin_define
define|#
directive|define
name|IIR_MODM
value|0x20
end_define

begin_comment
comment|/* change in modem input lines */
end_comment

begin_define
define|#
directive|define
name|IIR_TIMEO
value|0x40
end_define

begin_comment
comment|/* Time out */
end_comment

begin_define
define|#
directive|define
name|IIR_MASK
value|0x7f
end_define

begin_comment
comment|/* self test cond reg */
end_comment

begin_define
define|#
directive|define
name|ST_OK
value|0xe0
end_define

begin_comment
comment|/* Line configuration register */
end_comment

begin_define
define|#
directive|define
name|LC_PNO
value|0x00
end_define

begin_define
define|#
directive|define
name|LC_PODD
value|0x01
end_define

begin_define
define|#
directive|define
name|LC_PEVEN
value|0x02
end_define

begin_define
define|#
directive|define
name|LC_PMSK
value|0x03
end_define

begin_define
define|#
directive|define
name|LC_1STOP
value|0x00
end_define

begin_define
define|#
directive|define
name|LC_1HSTOP
value|0x04
end_define

begin_define
define|#
directive|define
name|LC_2STOP
value|0x08
end_define

begin_define
define|#
directive|define
name|LC_STOPMSK
value|0x0b
end_define

begin_define
define|#
directive|define
name|LC_8BITS
value|0x30
end_define

begin_define
define|#
directive|define
name|LC_7BITS
value|0x20
end_define

begin_define
define|#
directive|define
name|LC_6BITS
value|0x10
end_define

begin_define
define|#
directive|define
name|LC_5BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|LC_BITMSK
value|0x30
end_define

begin_comment
comment|/* baud reg */
end_comment

begin_define
define|#
directive|define
name|BR_0
value|0x00
end_define

begin_define
define|#
directive|define
name|BR_50
value|0x01
end_define

begin_define
define|#
directive|define
name|BR_75
value|0x02
end_define

begin_define
define|#
directive|define
name|BR_110
value|0x03
end_define

begin_define
define|#
directive|define
name|BR_134
value|0x04
end_define

begin_define
define|#
directive|define
name|BR_150
value|0x05
end_define

begin_define
define|#
directive|define
name|BR_300
value|0x06
end_define

begin_define
define|#
directive|define
name|BR_600
value|0x07
end_define

begin_define
define|#
directive|define
name|BR_900
value|0x08
end_define

begin_define
define|#
directive|define
name|BR_1200
value|0x09
end_define

begin_define
define|#
directive|define
name|BR_1800
value|0x0a
end_define

begin_define
define|#
directive|define
name|BR_2400
value|0x0b
end_define

begin_define
define|#
directive|define
name|BR_3600
value|0x0c
end_define

begin_define
define|#
directive|define
name|BR_4800
value|0x0d
end_define

begin_define
define|#
directive|define
name|BR_7200
value|0x0e
end_define

begin_define
define|#
directive|define
name|BR_9600
value|0x0f
end_define

begin_define
define|#
directive|define
name|BR_19200
value|0x10
end_define

begin_define
define|#
directive|define
name|BR_38400
value|0x11
end_define

begin_comment
comment|/* modem input register */
end_comment

begin_define
define|#
directive|define
name|MI_CTS
value|0x08
end_define

begin_define
define|#
directive|define
name|MI_DM
value|0x04
end_define

begin_define
define|#
directive|define
name|MI_CD
value|0x02
end_define

begin_define
define|#
directive|define
name|MI_RI
value|0x01
end_define

begin_comment
comment|/* modem output register */
end_comment

begin_define
define|#
directive|define
name|MO_SR
value|0x04
end_define

begin_define
define|#
directive|define
name|MO_DTR
value|0x02
end_define

begin_define
define|#
directive|define
name|MO_RTS
value|0x01
end_define

begin_define
define|#
directive|define
name|MO_ON
value|((MO_DTR) | (MO_RTS))
end_define

begin_define
define|#
directive|define
name|MO_OFF
value|0x00
end_define

begin_comment
comment|/* cmd-tab values, write */
end_comment

begin_define
define|#
directive|define
name|CT_CON
value|0x1
end_define

begin_comment
comment|/* configuration change */
end_comment

begin_define
define|#
directive|define
name|CT_TX
value|0x2
end_define

begin_comment
comment|/* transmit buffer not empty */
end_comment

begin_define
define|#
directive|define
name|CT_BRK
value|0x4
end_define

begin_comment
comment|/* toggle BREAK */
end_comment

begin_comment
comment|/* icr-tab values, read */
end_comment

begin_define
define|#
directive|define
name|IT_TX
value|0x1
end_define

begin_comment
comment|/* transmit buffer empty */
end_comment

begin_define
define|#
directive|define
name|IT_SPEC
value|0x2
end_define

begin_comment
comment|/* special character received */
end_comment

begin_comment
comment|/* data errors */
end_comment

begin_define
define|#
directive|define
name|RD_OVF
value|0x08
end_define

begin_define
define|#
directive|define
name|RD_BD
value|0x10
end_define

begin_define
define|#
directive|define
name|RD_PE
value|0x20
end_define

begin_define
define|#
directive|define
name|RD_OE
value|0x40
end_define

begin_define
define|#
directive|define
name|RD_FE
value|0x80
end_define

begin_define
define|#
directive|define
name|RD_MASK
value|0xf8
end_define

begin_comment
comment|/* Transmit/Receive masks */
end_comment

begin_define
define|#
directive|define
name|TX_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|RX_MASK
value|0xff
end_define

begin_comment
comment|/*  * WARNING: Serial console is assumed to be the lowest select-code card  * and that card must be logical unit 0 in the kernel.  Also, CONUNIT must  * be 1, the port affected by the REMOTE/LOCAL switch.  */
end_comment

begin_define
define|#
directive|define
name|CONUNIT
value|(1)
end_define

end_unit

