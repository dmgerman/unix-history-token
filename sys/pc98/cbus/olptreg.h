begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 TAKAHASHI Yoshihiro  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * modified for PC9801 by A.Kojima  *			Kyoto University Microcomputer Club (KMC)  */
end_comment

begin_define
define|#
directive|define
name|lpt_pstb_ctrl
value|(-9)
end_define

begin_comment
comment|/* PSTB enable control */
end_comment

begin_define
define|#
directive|define
name|LPC_EN_PSTB
value|0xc
end_define

begin_comment
comment|/* PSTB enable */
end_comment

begin_define
define|#
directive|define
name|LPC_DIS_PSTB
value|0xd
end_define

begin_comment
comment|/* PSTB disable */
end_comment

begin_define
define|#
directive|define
name|lpt_data
value|0
end_define

begin_comment
comment|/* Data to/from printer (R/W) */
end_comment

begin_define
define|#
directive|define
name|lpt_status
value|2
end_define

begin_comment
comment|/* Status of printer (R) */
end_comment

begin_define
define|#
directive|define
name|LPS_NBSY
value|0x4
end_define

begin_comment
comment|/* printer no ack of data */
end_comment

begin_define
define|#
directive|define
name|lpt_control
value|6
end_define

begin_comment
comment|/* Control printer (W) */
end_comment

begin_define
define|#
directive|define
name|LPC_MODE8255
value|0x82
end_define

begin_comment
comment|/* 8255 mode */
end_comment

begin_define
define|#
directive|define
name|LPC_IRQ8
value|0x6
end_define

begin_comment
comment|/* IRQ8 active */
end_comment

begin_define
define|#
directive|define
name|LPC_NIRQ8
value|0x7
end_define

begin_comment
comment|/* IRQ8 inactive */
end_comment

begin_define
define|#
directive|define
name|LPC_PSTB
value|0xe
end_define

begin_comment
comment|/* PSTB active */
end_comment

begin_define
define|#
directive|define
name|LPC_NPSTB
value|0xf
end_define

begin_comment
comment|/* PSTB inactive */
end_comment

end_unit

