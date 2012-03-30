begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OPENCORE_I2C_H__
end_ifndef

begin_define
define|#
directive|define
name|__OPENCORE_I2C_H__
end_define

begin_comment
comment|/* I2C specific registers */
end_comment

begin_define
define|#
directive|define
name|OC_I2C_PRESCALE_LO_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|OC_I2C_PRESCALE_HI_REG
value|0x01
end_define

begin_define
define|#
directive|define
name|OC_I2C_CTRL_REG
value|0x02
end_define

begin_define
define|#
directive|define
name|OC_I2C_TRANSMIT_REG
value|0x03
end_define

begin_comment
comment|/* tx and rx - same reg */
end_comment

begin_define
define|#
directive|define
name|OC_I2C_RECV_REG
value|0x03
end_define

begin_comment
comment|/* tx and rx - same reg */
end_comment

begin_define
define|#
directive|define
name|OC_I2C_DATA_REG
value|0x03
end_define

begin_comment
comment|/* tx and rx - same reg */
end_comment

begin_define
define|#
directive|define
name|OC_I2C_CMD_REG
value|0x04
end_define

begin_comment
comment|/* cmd and status - same reg */
end_comment

begin_define
define|#
directive|define
name|OC_I2C_STATUS_REG
value|0x04
end_define

begin_comment
comment|/* cmd and status - same reg */
end_comment

begin_define
define|#
directive|define
name|XLP_I2C_CLKFREQ
value|133333333
end_define

begin_comment
comment|/* XLP 133 MHz IO clock */
end_comment

begin_define
define|#
directive|define
name|XLP_I2C_FREQ
value|100000
end_define

begin_comment
comment|/* default 100kHz */
end_comment

begin_define
define|#
directive|define
name|I2C_TIMEOUT
value|500000
end_define

begin_comment
comment|/*  * These defines pertain to the OpenCores  * I2C Master Host Controller used in XLP  */
end_comment

begin_define
define|#
directive|define
name|OC_PRESCALER_LO
value|0
end_define

begin_define
define|#
directive|define
name|OC_PRESCALER_HI
value|1
end_define

begin_define
define|#
directive|define
name|OC_CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|OC_CONTROL_EN
value|0x80
end_define

begin_define
define|#
directive|define
name|OC_CONTROL_IEN
value|0x40
end_define

begin_define
define|#
directive|define
name|OC_DATA
value|3
end_define

begin_comment
comment|/* Data TX& RX Reg */
end_comment

begin_define
define|#
directive|define
name|OC_COMMAND
value|4
end_define

begin_define
define|#
directive|define
name|OC_COMMAND_START
value|0x90
end_define

begin_define
define|#
directive|define
name|OC_COMMAND_STOP
value|0x40
end_define

begin_define
define|#
directive|define
name|OC_COMMAND_READ
value|0x20
end_define

begin_define
define|#
directive|define
name|OC_COMMAND_WRITE
value|0x10
end_define

begin_define
define|#
directive|define
name|OC_COMMAND_RDACK
value|0x20
end_define

begin_define
define|#
directive|define
name|OC_COMMAND_RDNACK
value|0x28
end_define

begin_define
define|#
directive|define
name|OC_COMMAND_IACK
value|0x01
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|OC_STATUS
value|4
end_define

begin_comment
comment|/* Same as 'command' */
end_comment

begin_define
define|#
directive|define
name|OC_STATUS_NACK
value|0x80
end_define

begin_comment
comment|/* Did not get an ACK */
end_comment

begin_define
define|#
directive|define
name|OC_STATUS_BUSY
value|0x40
end_define

begin_define
define|#
directive|define
name|OC_STATUS_AL
value|0x20
end_define

begin_comment
comment|/* Arbitration Lost */
end_comment

begin_define
define|#
directive|define
name|OC_STATUS_TIP
value|0x02
end_define

begin_comment
comment|/* Transfer in Progress  */
end_comment

begin_define
define|#
directive|define
name|OC_STATUS_IF
value|0x01
end_define

begin_comment
comment|/* Intr. Pending Flag */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

