begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Sean Eric Fagan.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IC_ESP_H_
end_ifndef

begin_define
define|#
directive|define
name|_IC_ESP_H_
end_define

begin_comment
comment|/*  * Definitions for Hayes ESP serial cards.  */
end_comment

begin_comment
comment|/*  * CMD1 and CMD2 are the command ports, offsets from<esp_iobase>.  */
end_comment

begin_define
define|#
directive|define
name|ESP_CMD1
value|4
end_define

begin_define
define|#
directive|define
name|ESP_CMD2
value|5
end_define

begin_comment
comment|/*  * STAT1 and STAT2 are to get return values and status bytes;  * they overload CMD1 and CMD2.  */
end_comment

begin_define
define|#
directive|define
name|ESP_STATUS1
value|ESP_CMD1
end_define

begin_define
define|#
directive|define
name|ESP_STATUS2
value|ESP_CMD2
end_define

begin_comment
comment|/*  * Commands.  Commands are given by writing the command value to  * ESP_CMD1 and then writing or reading some number of bytes from  * ESP_CMD2 or ESP_STATUS2.  */
end_comment

begin_define
define|#
directive|define
name|ESP_GETTEST
value|0x01
end_define

begin_comment
comment|/* self-test command (1 byte + extras) */
end_comment

begin_define
define|#
directive|define
name|ESP_GETDIPS
value|0x02
end_define

begin_comment
comment|/* get on-board DIP switches (1 byte) */
end_comment

begin_define
define|#
directive|define
name|ESP_SETFLOWTYPE
value|0x08
end_define

begin_comment
comment|/* set type of flow-control (2 bytes) */
end_comment

begin_define
define|#
directive|define
name|ESP_SETRXFLOW
value|0x0a
end_define

begin_comment
comment|/* set Rx FIFO flow control levels (4 bytes) */
end_comment

begin_define
define|#
directive|define
name|ESP_SETMODE
value|0x10
end_define

begin_comment
comment|/* set board mode (1 byte) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|ESP_SETCLOCK
value|0x23
end_define

begin_comment
comment|/* set UART clock prescaler */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Mode bits (ESP_SETMODE). */
end_comment

begin_define
define|#
directive|define
name|ESP_MODE_FIFO
value|0x02
end_define

begin_comment
comment|/* act like a 16550 (compatibility mode) */
end_comment

begin_define
define|#
directive|define
name|ESP_MODE_RTS
value|0x04
end_define

begin_comment
comment|/* use RTS hardware flow control */
end_comment

begin_define
define|#
directive|define
name|ESP_MODE_SCALE
value|0x80
end_define

begin_comment
comment|/* scale FIFO trigger levels */
end_comment

begin_comment
comment|/* Flow control type bits (ESP_SETFLOWTYPE). */
end_comment

begin_define
define|#
directive|define
name|ESP_FLOW_RTS
value|0x04
end_define

begin_comment
comment|/* cmd1: local Rx sends RTS flow control */
end_comment

begin_define
define|#
directive|define
name|ESP_FLOW_CTS
value|0x10
end_define

begin_comment
comment|/* cmd2: local transmitter responds to CTS */
end_comment

begin_comment
comment|/* Used by ESP_SETRXFLOW. */
end_comment

begin_define
define|#
directive|define
name|HIBYTE
parameter_list|(
name|w
parameter_list|)
value|(((w)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|LOBYTE
parameter_list|(
name|w
parameter_list|)
value|((w)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IC_ESP_H_ */
end_comment

end_unit

