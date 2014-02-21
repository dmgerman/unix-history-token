begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Steven Lawrance<stl@koffein.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FSL_OCOTPREG_H
end_ifndef

begin_define
define|#
directive|define
name|FSL_OCOTPREG_H
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CTRL
value|0x000
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CTRL_SET
value|0x004
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CTRL_CLR
value|0x008
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CTRL_TOG
value|0x00C
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_TIMING
value|0x010
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_DATA
value|0x020
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_READ_CTRL
value|0x030
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_READ_FUSE_DATA
value|0x040
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SW_STICKY
value|0x050
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SCS
value|0x060
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SCS_SET
value|0x064
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SCS_CLR
value|0x068
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SCS_TOG
value|0x06C
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_VERSION
value|0x090
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_LOCK
value|0x400
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG0
value|0x410
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG1
value|0x420
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG2
value|0x430
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG3
value|0x440
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG3_SPEED_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG3_SPEED_MASK
define|\
value|(0x03<< FSL_OCOTP_CFG3_SPEED_SHIFT)
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG3_SPEED_792MHZ
value|0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG3_SPEED_852MHZ
value|1
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG3_SPEED_996MHZ
value|2
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG3_SPEED_1200MHZ
value|3
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG4
value|0x450
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG5
value|0x460
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_CFG6
value|0x470
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_MEM0
value|0x480
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_MEM1
value|0x490
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_MEM2
value|0x4A0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_MEM3
value|0x4B0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_ANA0
value|0x4D0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_ANA1
value|0x4E0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_ANA2
value|0x4F0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SRK0
value|0x580
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SRK1
value|0x590
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SRK2
value|0x5A0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SRK3
value|0x5B0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SRK4
value|0x5C0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SRK5
value|0x5D0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SRK6
value|0x5E0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SRK7
value|0x5F0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_HSJC_RESP0
value|0x600
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_HSJC_RESP1
value|0x610
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_MAC0
value|0x620
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_MAC1
value|0x630
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_GP1
value|0x660
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_GP2
value|0x670
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_MISC_CONF
value|0x6D0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_FIELD_RETURN
value|0x6E0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_SRK_REVOKE
value|0x6F0
end_define

begin_define
define|#
directive|define
name|FSL_OCOTP_LAST_REG
value|FSL_OCOTP_SRK_REVOKE
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

