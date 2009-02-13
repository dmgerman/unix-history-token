begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2007 Daniel Roethlisberger<daniel@roe.ch>  * Copyright (c) 2000-2004 OMNIKEY GmbH (www.omnikey.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* I/O port registers */
end_comment

begin_define
define|#
directive|define
name|REG_OFFSET_DTR
value|0
end_define

begin_comment
comment|/* data transfer register */
end_comment

begin_define
define|#
directive|define
name|REG_OFFSET_BSR
value|1
end_define

begin_comment
comment|/* buffer status register */
end_comment

begin_define
define|#
directive|define
name|REG_OFFSET_SCR
value|2
end_define

begin_comment
comment|/* sync control register  */
end_comment

begin_comment
comment|/* buffer status register flags */
end_comment

begin_define
define|#
directive|define
name|BSR_BULK_OUT_FULL
value|0x01
end_define

begin_define
define|#
directive|define
name|BSR_BULK_IN_FULL
value|0x02
end_define

begin_comment
comment|/* sync control register flags */
end_comment

begin_define
define|#
directive|define
name|SCR_POWER_DOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|SCR_PULSE_INTERRUPT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCR_HOST_TO_READER_DONE
value|0x04
end_define

begin_define
define|#
directive|define
name|SCR_READER_TO_HOST_DONE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCR_ACK_NOTIFY
value|0x10
end_define

begin_define
define|#
directive|define
name|SCR_EN_NOTIFY
value|0x20
end_define

begin_define
define|#
directive|define
name|SCR_ABORT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCR_HOST_TO_READER_START
value|0x80
end_define

begin_comment
comment|/* CCID commands */
end_comment

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_SETPARAMETERS
value|0x61
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_ICCPOWERON
value|0x62
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_ICCPOWEROFF
value|0x63
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_GETSLOTSTATUS
value|0x65
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_SECURE
value|0x69
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_ESCAPE
value|0x6B
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_GETPARAMETERS
value|0x6C
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_RESETPARAMETERS
value|0x6D
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_ICCCLOCK
value|0x6E
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_XFRBLOCK
value|0x6F
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_TEST_SECURE
value|0x74
end_define

begin_define
define|#
directive|define
name|CMD_PC_TO_RDR_OK_SECURE
value|0x89
end_define

begin_define
define|#
directive|define
name|CMD_RDR_TO_PC_DATABLOCK
value|0x80
end_define

begin_define
define|#
directive|define
name|CMD_RDR_TO_PC_SLOTSTATUS
value|0x81
end_define

begin_define
define|#
directive|define
name|CMD_RDR_TO_PC_PARAMETERS
value|0x82
end_define

begin_define
define|#
directive|define
name|CMD_RDR_TO_PC_ESCAPE
value|0x83
end_define

begin_define
define|#
directive|define
name|CMD_RDR_TO_PC_OK_SECURE
value|0x89
end_define

end_unit

