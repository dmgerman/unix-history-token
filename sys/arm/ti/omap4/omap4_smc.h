begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Olivier Houchard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OMAP4_SMC_H_
end_ifndef

begin_define
define|#
directive|define
name|OMAP4_SMC_H_
end_define

begin_comment
comment|/* Define the various function IDs used by the OMAP4 */
end_comment

begin_define
define|#
directive|define
name|L2CACHE_WRITE_DEBUG_REG
value|0x100
end_define

begin_define
define|#
directive|define
name|L2CACHE_CLEAN_INV_RANG
value|0x101
end_define

begin_define
define|#
directive|define
name|L2CACHE_WRITE_CTRL_REG
value|0x102
end_define

begin_define
define|#
directive|define
name|READ_AUX_CORE_REGS
value|0x103
end_define

begin_define
define|#
directive|define
name|MODIFY_AUX_CORE_0
value|0x104
end_define

begin_define
define|#
directive|define
name|WRITE_AUX_CORE_1
value|0x105
end_define

begin_define
define|#
directive|define
name|READ_WKG_CTRL_REG
value|0x106
end_define

begin_define
define|#
directive|define
name|CLEAR_WKG_CTRL_REG
value|0x107
end_define

begin_define
define|#
directive|define
name|SET_POWER_STATUS_REG
value|0x108
end_define

begin_define
define|#
directive|define
name|WRITE_AUXCTRL_REG
value|0x109
end_define

begin_define
define|#
directive|define
name|LOCKDOWN_TLB
value|0x10a
end_define

begin_define
define|#
directive|define
name|SELECT_TLB_ENTRY_FOR_WRITE
value|0x10b
end_define

begin_define
define|#
directive|define
name|READ_TLB_VA_ENTRY
value|0x10c
end_define

begin_define
define|#
directive|define
name|WRITE_TLB_VA_ENTRY
value|0x10d
end_define

begin_define
define|#
directive|define
name|READ_TLB_PA_ENTRY
value|0x10e
end_define

begin_define
define|#
directive|define
name|WRITE_TLB_PA_ENTRY
value|0x10f
end_define

begin_define
define|#
directive|define
name|READ_TLB_ATTR_ENTRY
value|0x110
end_define

begin_define
define|#
directive|define
name|WRITE_TLB_ATTR_ENTRY
value|0x111
end_define

begin_define
define|#
directive|define
name|WRITE_LATENCY_CTRL_REG
value|0x112
end_define

begin_define
define|#
directive|define
name|WRITE_PREFETCH_CTRL_REG
value|0x113
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OMAP4_SMC_H_ */
end_comment

end_unit

