begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1996  *	Berkeley Software Design, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Berkeley Software  *	Design, Inc.  *  * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	BSDI com.h,v 2.2 1996/04/08 19:32:21 bostic Exp  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* com.h for doscmd int14.c */
end_comment

begin_comment
comment|/* NS16550A register definitions */
end_comment

begin_comment
comment|/* interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|IE_NOP
value|0xF0
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|IE_MODEM_STAT
value|0x08
end_define

begin_comment
comment|/* modem status int. */
end_comment

begin_define
define|#
directive|define
name|IE_LINE_STAT
value|0x04
end_define

begin_comment
comment|/* receiver-line status int. */
end_comment

begin_define
define|#
directive|define
name|IE_TRANS_HLD
value|0x02
end_define

begin_comment
comment|/* transmitter holding register empty int. */
end_comment

begin_define
define|#
directive|define
name|IE_RCV_DATA
value|0x01
end_define

begin_comment
comment|/* received data available int. */
end_comment

begin_comment
comment|/* interrupt identification register */
end_comment

begin_define
define|#
directive|define
name|II_FIFOS_EN
value|0xC0
end_define

begin_comment
comment|/* if FIFOs are enabled */
end_comment

begin_define
define|#
directive|define
name|II_NOP
value|0x30
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|II_INT_ID
value|0x0E
end_define

begin_comment
comment|/* mask: bits see below */
end_comment

begin_define
define|#
directive|define
name|II_PEND_INT
value|0x01
end_define

begin_comment
comment|/* 1=no interrupt pending */
end_comment

begin_comment
comment|/* bit masks for II_INT_ID */
end_comment

begin_define
define|#
directive|define
name|II_TO
value|0x0C
end_define

begin_define
define|#
directive|define
name|II_LINE_STAT
value|0x06
end_define

begin_define
define|#
directive|define
name|II_RCV_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|II_TRANS_HLD
value|0x02
end_define

begin_define
define|#
directive|define
name|II_MODEM_STAT
value|0x00
end_define

begin_comment
comment|/* FIFO control reg */
end_comment

begin_define
define|#
directive|define
name|FC_FIFO_SZ_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|FC_FIFO_1B
value|0x80
end_define

begin_define
define|#
directive|define
name|FC_FIFO_4B
value|0x40
end_define

begin_define
define|#
directive|define
name|FC_FIFO_8B
value|0x80
end_define

begin_define
define|#
directive|define
name|FC_FIFO_14B
value|0xC0
end_define

begin_define
define|#
directive|define
name|FC_FIFO_CTR
value|0x04
end_define

begin_define
define|#
directive|define
name|FC_FIFO_CRV
value|0x02
end_define

begin_define
define|#
directive|define
name|FC_FIFO_EN
value|0x01
end_define

begin_comment
comment|/* line control register */
end_comment

begin_define
define|#
directive|define
name|LC_DIV_ACC
value|0x80
end_define

begin_comment
comment|/* divisor latch access bit */
end_comment

begin_define
define|#
directive|define
name|LC_BRK_CTRL
value|0x40
end_define

begin_comment
comment|/* set break control */
end_comment

begin_define
define|#
directive|define
name|LC_S_PAR
value|0x20
end_define

begin_comment
comment|/* stick parity */
end_comment

begin_define
define|#
directive|define
name|LC_EVEN_P
value|0x10
end_define

begin_comment
comment|/* even parity select */
end_comment

begin_define
define|#
directive|define
name|LC_PAR_E
value|0x08
end_define

begin_comment
comment|/* parity enable */
end_comment

begin_define
define|#
directive|define
name|LC_STOP_B
value|0x04
end_define

begin_comment
comment|/* number of stop bits (0 - 1 bit) */
end_comment

begin_define
define|#
directive|define
name|LC_W_LEN
value|0x03
end_define

begin_comment
comment|/* unsigned short length (00 - 5, 01 - 6 etc.) */
end_comment

begin_comment
comment|/* line status register */
end_comment

begin_define
define|#
directive|define
name|LS_NOP
value|0x80
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|LS_X_DATA_E
value|0x40
end_define

begin_comment
comment|/* 1=empty */
end_comment

begin_define
define|#
directive|define
name|LS_X_HOLD_E
value|0x20
end_define

begin_comment
comment|/* 1=empty */
end_comment

begin_define
define|#
directive|define
name|LS_BREAK
value|0x10
end_define

begin_comment
comment|/* break received */
end_comment

begin_define
define|#
directive|define
name|LS_FRM_ERR
value|0x08
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|LS_PAR_ERR
value|0x04
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|LS_OVRN_ERR
value|0x02
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|LS_RCV_DATA_RD
value|0x01
end_define

begin_comment
comment|/* data received */
end_comment

begin_comment
comment|/* modem status register */
end_comment

begin_define
define|#
directive|define
name|MS_DCD
value|0x80
end_define

begin_comment
comment|/* Data Carrier Detect in */
end_comment

begin_define
define|#
directive|define
name|MS_RI
value|0x40
end_define

begin_comment
comment|/* Ring Indicator in */
end_comment

begin_define
define|#
directive|define
name|MS_DSR
value|0x20
end_define

begin_comment
comment|/* Data Set Ready in */
end_comment

begin_define
define|#
directive|define
name|MS_CTS
value|0x10
end_define

begin_comment
comment|/* Clear To Send in */
end_comment

begin_define
define|#
directive|define
name|MS_DELTA_DCD
value|0x08
end_define

begin_comment
comment|/* Data Carrier Detect changed state */
end_comment

begin_define
define|#
directive|define
name|MS_DELTA_RI
value|0x04
end_define

begin_comment
comment|/* Ring Indicator changed state */
end_comment

begin_define
define|#
directive|define
name|MS_DELTA_DSR
value|0x02
end_define

begin_comment
comment|/* Data Set Ready changed state */
end_comment

begin_define
define|#
directive|define
name|MS_DELTA_CTS
value|0x01
end_define

begin_comment
comment|/* Clear To Send changed state */
end_comment

begin_comment
comment|/* DOS definitions -- parameters */
end_comment

begin_define
define|#
directive|define
name|BITRATE_110
value|0x00
end_define

begin_define
define|#
directive|define
name|BITRATE_150
value|0x20
end_define

begin_define
define|#
directive|define
name|BITRATE_300
value|0x40
end_define

begin_define
define|#
directive|define
name|BITRATE_600
value|0x60
end_define

begin_define
define|#
directive|define
name|BITRATE_1200
value|0x80
end_define

begin_define
define|#
directive|define
name|BITRATE_2400
value|0xA0
end_define

begin_define
define|#
directive|define
name|BITRATE_4800
value|0xC0
end_define

begin_define
define|#
directive|define
name|BITRATE_9600
value|0xE0
end_define

begin_define
define|#
directive|define
name|PARITY_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PARITY_ODD
value|0x08
end_define

begin_define
define|#
directive|define
name|PARITY_EVEN
value|0x18
end_define

begin_define
define|#
directive|define
name|STOPBIT_1
value|0x00
end_define

begin_define
define|#
directive|define
name|STOPBIT_2
value|0x04
end_define

begin_define
define|#
directive|define
name|TXLEN_7BITS
value|0x02
end_define

begin_define
define|#
directive|define
name|TXLEN_8BITS
value|0x03
end_define

begin_define
define|#
directive|define
name|N_OF_COM_REGS
value|8
end_define

begin_comment
comment|/* DOS definitions -- return codes */
end_comment

begin_define
define|#
directive|define
name|LS_SW_TIME_OUT
value|LS_NOP
end_define

begin_comment
comment|/* return value used by DOS */
end_comment

begin_comment
comment|/* routine declarations */
end_comment

begin_function_decl
name|void
name|int14
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_com
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* end of file com.h */
end_comment

end_unit

