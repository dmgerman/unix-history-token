begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Tetsuya Isaki.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the NetBSD  *      Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * ScanLogic SL811HS/T USB Host Controller  */
end_comment

begin_define
define|#
directive|define
name|SL11_IDX_ADDR
value|(0x00)
end_define

begin_define
define|#
directive|define
name|SL11_IDX_DATA
value|(0x01)
end_define

begin_define
define|#
directive|define
name|SL11_PORTSIZE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|SL11_E0BASE
value|(0x00)
end_define

begin_comment
comment|/* Base of Control0 */
end_comment

begin_define
define|#
directive|define
name|SL11_E0CTRL
value|(0x00)
end_define

begin_comment
comment|/* Host Control Register */
end_comment

begin_define
define|#
directive|define
name|SL11_E0ADDR
value|(0x01)
end_define

begin_comment
comment|/* Host Base Address */
end_comment

begin_define
define|#
directive|define
name|SL11_E0LEN
value|(0x02)
end_define

begin_comment
comment|/* Host Base Length */
end_comment

begin_define
define|#
directive|define
name|SL11_E0STAT
value|(0x03)
end_define

begin_comment
comment|/* USB Status (Read) */
end_comment

begin_define
define|#
directive|define
name|SL11_E0PID
value|SL11_E0STAT
end_define

begin_comment
comment|/* Host PID, Device Endpoint (Write) */
end_comment

begin_define
define|#
directive|define
name|SL11_E0CONT
value|(0x04)
end_define

begin_comment
comment|/* Transfer Count (Read) */
end_comment

begin_define
define|#
directive|define
name|SL11_E0DEV
value|SL11_E0CONT
end_define

begin_comment
comment|/* Host Device Address (Write) */
end_comment

begin_define
define|#
directive|define
name|SL11_E1BASE
value|(0x08)
end_define

begin_comment
comment|/* Base of Control1 */
end_comment

begin_define
define|#
directive|define
name|SL11_E1CTRL
value|(SL11_E1BASE + SL11_E0CTRL)
end_define

begin_define
define|#
directive|define
name|SL11_E1ADDR
value|(SL11_E1BASE + SL11_E0ADDR)
end_define

begin_define
define|#
directive|define
name|SL11_E1LEN
value|(SL11_E1BASE + SL11_E0LEN)
end_define

begin_define
define|#
directive|define
name|SL11_E1STAT
value|(SL11_E1BASE + SL11_E0STAT)
end_define

begin_define
define|#
directive|define
name|SL11_E1PID
value|(SL11_E1BASE + SL11_E0PID)
end_define

begin_define
define|#
directive|define
name|SL11_E1CONT
value|(SL11_E1BASE + SL11_E0CONT)
end_define

begin_define
define|#
directive|define
name|SL11_E1DEV
value|(SL11_E1BASE + SL11_E0DEV)
end_define

begin_define
define|#
directive|define
name|SL11_CTRL
value|(0x05)
end_define

begin_comment
comment|/* Control Register1 */
end_comment

begin_define
define|#
directive|define
name|SL11_IER
value|(0x06)
end_define

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|SL11_ISR
value|(0x0d)
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|SL11_DATA
value|(0x0e)
end_define

begin_comment
comment|/* SOF Counter Low (Write) */
end_comment

begin_define
define|#
directive|define
name|SL11_REV
value|SL11_DATA
end_define

begin_comment
comment|/* HW Revision Register (Read) */
end_comment

begin_define
define|#
directive|define
name|SL811_CSOF
value|(0x0f)
end_define

begin_comment
comment|/* SOF Counter High(R), Control2(W) */
end_comment

begin_define
define|#
directive|define
name|SL11_MEM
value|(0x10)
end_define

begin_comment
comment|/* Memory Buffer (0x10 - 0xff) */
end_comment

begin_define
define|#
directive|define
name|SL11_EPCTRL_ARM
value|(0x01)
end_define

begin_define
define|#
directive|define
name|SL11_EPCTRL_ENABLE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|SL11_EPCTRL_DIRECTION
value|(0x04)
end_define

begin_define
define|#
directive|define
name|SL11_EPCTRL_ISO
value|(0x10)
end_define

begin_define
define|#
directive|define
name|SL11_EPCTRL_SOF
value|(0x20)
end_define

begin_define
define|#
directive|define
name|SL11_EPCTRL_DATATOGGLE
value|(0x40)
end_define

begin_define
define|#
directive|define
name|SL11_EPCTRL_PREAMBLE
value|(0x80)
end_define

begin_define
define|#
directive|define
name|SL11_EPPID_PIDMASK
value|(0xf0)
end_define

begin_define
define|#
directive|define
name|SL11_EPPID_EPMASK
value|(0x0f)
end_define

begin_define
define|#
directive|define
name|SL11_EPSTAT_ACK
value|(0x01)
end_define

begin_define
define|#
directive|define
name|SL11_EPSTAT_ERROR
value|(0x02)
end_define

begin_define
define|#
directive|define
name|SL11_EPSTAT_TIMEOUT
value|(0x04)
end_define

begin_define
define|#
directive|define
name|SL11_EPSTAT_SEQUENCE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|SL11_EPSTAT_SETUP
value|(0x10)
end_define

begin_define
define|#
directive|define
name|SL11_EPSTAT_OVERFLOW
value|(0x20)
end_define

begin_define
define|#
directive|define
name|SL11_EPSTAT_NAK
value|(0x40)
end_define

begin_define
define|#
directive|define
name|SL11_EPSTAT_STALL
value|(0x80)
end_define

begin_define
define|#
directive|define
name|SL11_CTRL_ENABLESOF
value|(0x01)
end_define

begin_define
define|#
directive|define
name|SL11_CTRL_EOF2
value|(0x04)
end_define

begin_define
define|#
directive|define
name|SL11_CTRL_RESETENGINE
value|(0x08)
end_define

begin_define
define|#
directive|define
name|SL11_CTRL_JKSTATE
value|(0x10)
end_define

begin_define
define|#
directive|define
name|SL11_CTRL_LOWSPEED
value|(0x20)
end_define

begin_define
define|#
directive|define
name|SL11_CTRL_SUSPEND
value|(0x40)
end_define

begin_define
define|#
directive|define
name|SL11_IER_USBA
value|(0x01)
end_define

begin_comment
comment|/* USB-A done */
end_comment

begin_define
define|#
directive|define
name|SL11_IER_USBB
value|(0x02)
end_define

begin_comment
comment|/* USB-B done */
end_comment

begin_define
define|#
directive|define
name|SL11_IER_BABBLE
value|(0x04)
end_define

begin_comment
comment|/* Babble detection */
end_comment

begin_define
define|#
directive|define
name|SL11_IER_SOFTIMER
value|(0x10)
end_define

begin_comment
comment|/* 1ms SOF timer */
end_comment

begin_define
define|#
directive|define
name|SL11_IER_INSERT
value|(0x20)
end_define

begin_comment
comment|/* Slave Insert/Remove detection */
end_comment

begin_define
define|#
directive|define
name|SL11_IER_RESET
value|(0x40)
end_define

begin_comment
comment|/* USB Reset/Resume */
end_comment

begin_define
define|#
directive|define
name|SL11_ISR_USBA
value|(0x01)
end_define

begin_comment
comment|/* USB-A done */
end_comment

begin_define
define|#
directive|define
name|SL11_ISR_USBB
value|(0x02)
end_define

begin_comment
comment|/* USB-B done */
end_comment

begin_define
define|#
directive|define
name|SL11_ISR_BABBLE
value|(0x04)
end_define

begin_comment
comment|/* Babble detection */
end_comment

begin_define
define|#
directive|define
name|SL11_ISR_SOFTIMER
value|(0x10)
end_define

begin_comment
comment|/* 1ms SOF timer */
end_comment

begin_define
define|#
directive|define
name|SL11_ISR_INSERT
value|(0x20)
end_define

begin_comment
comment|/* Slave Insert/Remove detection */
end_comment

begin_define
define|#
directive|define
name|SL11_ISR_RESET
value|(0x40)
end_define

begin_comment
comment|/* USB Reset/Resume */
end_comment

begin_define
define|#
directive|define
name|SL11_ISR_DATA
value|(0x80)
end_define

begin_comment
comment|/* Value of the Data+ pin */
end_comment

begin_define
define|#
directive|define
name|SL11_REV_USBA
value|(0x01)
end_define

begin_comment
comment|/* USB-A */
end_comment

begin_define
define|#
directive|define
name|SL11_REV_USBB
value|(0x02)
end_define

begin_comment
comment|/* USB-B */
end_comment

begin_define
define|#
directive|define
name|SL11_REV_REVMASK
value|(0xf0)
end_define

begin_comment
comment|/* HW Revision */
end_comment

begin_define
define|#
directive|define
name|SL11_REV_REVSL11H
value|(0x00)
end_define

begin_comment
comment|/* HW is SL11H */
end_comment

begin_define
define|#
directive|define
name|SL11_REV_REVSL811HS
value|(0x10)
end_define

begin_comment
comment|/* HW is SL811HS */
end_comment

begin_define
define|#
directive|define
name|SL811_CSOF_SOFMASK
value|(0x3f)
end_define

begin_comment
comment|/* SOF High Counter */
end_comment

begin_define
define|#
directive|define
name|SL811_CSOF_POLARITY
value|(0x40)
end_define

begin_comment
comment|/* Change polarity */
end_comment

begin_define
define|#
directive|define
name|SL811_CSOF_MASTER
value|(0x80)
end_define

begin_comment
comment|/* Master/Slave selection */
end_comment

end_unit

