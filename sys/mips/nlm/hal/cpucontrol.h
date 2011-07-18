begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  * NETLOGIC_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_CPUCONTROL_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_CPUCONTROL_H__
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_IFU
value|0
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_ICU
value|1
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_IEU
value|2
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_LSU
value|3
end_define

begin_define
define|#
directive|define
name|XLP_LSU_DEFEATURE
value|0x304
end_define

begin_define
define|#
directive|define
name|XLP_LSU_CERRLOG_REGID
value|0x09
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_MMU
value|4
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_PRF
value|5
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_SCH
value|7
end_define

begin_define
define|#
directive|define
name|XLP_SCHED_DEFEATURE
value|0x700
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_SCU
value|8
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_FPU
value|9
end_define

begin_define
define|#
directive|define
name|XLP_CPU_BLOCKID_MAP
value|10
end_define

begin_comment
comment|/* Offsets of interest from the 'MAP' Block */
end_comment

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_THREADMODE
value|0x00
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_EXT_EBASE_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_CCDI_CONFIG
value|0x08
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_THRD0_CCDI_STATUS
value|0x0c
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_THRD1_CCDI_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_THRD2_CCDI_STATUS
value|0x14
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_THRD3_CCDI_STATUS
value|0x18
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_THRD0_DEBUG_MODE
value|0x1c
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_THRD1_DEBUG_MODE
value|0x20
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_THRD2_DEBUG_MODE
value|0x24
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_THRD3_DEBUG_MODE
value|0x28
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_MISC_STATE
value|0x60
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_DEBUG_READ_CTL
value|0x64
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_DEBUG_READ_REG0
value|0x68
end_define

begin_define
define|#
directive|define
name|XLP_BLKID_MAP_DEBUG_READ_REG1
value|0x6c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NLM_CPUCONTROL_H__ */
end_comment

end_unit

