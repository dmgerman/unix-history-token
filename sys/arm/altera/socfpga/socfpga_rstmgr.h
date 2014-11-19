begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|RSTMGR_STAT
value|0x0
end_define

begin_comment
comment|/* Status */
end_comment

begin_define
define|#
directive|define
name|RSTMGR_CTRL
value|0x4
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|CTRL_SWWARMRSTREQ
value|(1<< 1)
end_define

begin_comment
comment|/* Trigger warm reset */
end_comment

begin_define
define|#
directive|define
name|RSTMGR_COUNTS
value|0x8
end_define

begin_comment
comment|/* Reset Cycles Count */
end_comment

begin_define
define|#
directive|define
name|RSTMGR_MPUMODRST
value|0x10
end_define

begin_comment
comment|/* MPU Module Reset */
end_comment

begin_define
define|#
directive|define
name|RSTMGR_PERMODRST
value|0x14
end_define

begin_comment
comment|/* Peripheral Module Reset */
end_comment

begin_define
define|#
directive|define
name|RSTMGR_PER2MODRST
value|0x18
end_define

begin_comment
comment|/* Peripheral 2 Module Reset */
end_comment

begin_define
define|#
directive|define
name|RSTMGR_BRGMODRST
value|0x1C
end_define

begin_comment
comment|/* Bridge Module Reset */
end_comment

begin_define
define|#
directive|define
name|BRGMODRST_FPGA2HPS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|BRGMODRST_LWHPS2FPGA
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|BRGMODRST_HPS2FPGA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RSTMGR_MISCMODRST
value|0x20
end_define

begin_comment
comment|/* Miscellaneous Module Reset */
end_comment

begin_function_decl
name|int
name|rstmgr_warmreset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

