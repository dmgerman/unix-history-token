begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000,2001 Jonathan Chen.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register definitions for TDK 78Q2120  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_TDKPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_TDKPHYREG_H_
end_define

begin_define
define|#
directive|define
name|MII_VENDOR
value|16
end_define

begin_define
define|#
directive|define
name|VENDOR_RXCC
value|0x0001
end_define

begin_define
define|#
directive|define
name|VENDOR_PCSBP
value|0x0002
end_define

begin_define
define|#
directive|define
name|VENDOR_RVSPOL
value|0x0010
end_define

begin_define
define|#
directive|define
name|VENDOR_NOAPOL
value|0x0020
end_define

begin_define
define|#
directive|define
name|VENDOR_GPIO0DIR
value|0x0040
end_define

begin_define
define|#
directive|define
name|VENDOR_GPIO0DAT
value|0x0080
end_define

begin_define
define|#
directive|define
name|VENDOR_GPIO1DIR
value|0x0100
end_define

begin_define
define|#
directive|define
name|VENDOR_GPIO1DAT
value|0x0200
end_define

begin_define
define|#
directive|define
name|VENDOR_10BTLOOP
value|0x0400
end_define

begin_define
define|#
directive|define
name|VENDOR_NOSQE
value|0x0800
end_define

begin_define
define|#
directive|define
name|VENDOR_TXHIM
value|0x1000
end_define

begin_define
define|#
directive|define
name|VENDOR_INTLVL
value|0x4000
end_define

begin_define
define|#
directive|define
name|VENDOR_RPTR
value|0x8000
end_define

begin_define
define|#
directive|define
name|MII_INT
value|17
end_define

begin_define
define|#
directive|define
name|INT_STAT_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|INT_STAT_ACOMP
value|0x0001
end_define

begin_define
define|#
directive|define
name|INT_STAT_RFAULT
value|0x0002
end_define

begin_define
define|#
directive|define
name|INT_STAT_LSCHG
value|0x0004
end_define

begin_define
define|#
directive|define
name|INT_STAT_LPACK
value|0x0008
end_define

begin_define
define|#
directive|define
name|INT_STAT_PDF
value|0x0010
end_define

begin_define
define|#
directive|define
name|INT_STAT_PRX
value|0x0020
end_define

begin_define
define|#
directive|define
name|INT_STAT_RXERR
value|0x0040
end_define

begin_define
define|#
directive|define
name|INT_STAT_JABBER
value|0x0080
end_define

begin_define
define|#
directive|define
name|INT_CTRL_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|INT_CTRL_ACOMP
value|0x0100
end_define

begin_define
define|#
directive|define
name|INT_CTRL_RFAULT
value|0x0200
end_define

begin_define
define|#
directive|define
name|INT_CTRL_LSCHG
value|0x0400
end_define

begin_define
define|#
directive|define
name|INT_CTRL_LPACK
value|0x0800
end_define

begin_define
define|#
directive|define
name|INT_CTRL_PDF
value|0x1000
end_define

begin_define
define|#
directive|define
name|INT_CTRL_PRX
value|0x2000
end_define

begin_define
define|#
directive|define
name|INT_CTRL_RXERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|INT_CTRL_JABBER
value|0x8000
end_define

begin_define
define|#
directive|define
name|MII_DIAG
value|18
end_define

begin_define
define|#
directive|define
name|DIAG_RLOCK
value|0x0100
end_define

begin_define
define|#
directive|define
name|DIAG_RPASS
value|0x0200
end_define

begin_define
define|#
directive|define
name|DIAG_RATE_100
value|0x0400
end_define

begin_define
define|#
directive|define
name|DIAG_DUPLEX
value|0x0800
end_define

begin_define
define|#
directive|define
name|DIAG_NEGFAIL
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

