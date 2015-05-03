begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013, 2014 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_HYPERVISOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_HYPERVISOR_H_
end_define

begin_comment
comment|/*  * These registers are only useful when in hypervisor context,  * e.g. specific to EL2, or controlling the hypervisor.  */
end_comment

begin_comment
comment|/*  * Architecture feature trap register  */
end_comment

begin_define
define|#
directive|define
name|CPTR_RES0
value|0x7fefc800
end_define

begin_define
define|#
directive|define
name|CPTR_RES1
value|0x000033ff
end_define

begin_define
define|#
directive|define
name|CPTR_TFP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CPTR_TTA
value|0x00100000
end_define

begin_define
define|#
directive|define
name|CPTR_TCPAC
value|0x80000000
end_define

begin_comment
comment|/*  * Hypervisor Config Register  */
end_comment

begin_define
define|#
directive|define
name|HCR_VM
value|0x0000000000000001
end_define

begin_define
define|#
directive|define
name|HCR_SWIO
value|0x0000000000000002
end_define

begin_define
define|#
directive|define
name|HCR_PTW
value|0x0000000000000004
end_define

begin_define
define|#
directive|define
name|HCR_FMO
value|0x0000000000000008
end_define

begin_define
define|#
directive|define
name|HCR_IMO
value|0x0000000000000010
end_define

begin_define
define|#
directive|define
name|HCR_AMO
value|0x0000000000000020
end_define

begin_define
define|#
directive|define
name|HCR_VF
value|0x0000000000000040
end_define

begin_define
define|#
directive|define
name|HCR_VI
value|0x0000000000000080
end_define

begin_define
define|#
directive|define
name|HCR_VSE
value|0x0000000000000100
end_define

begin_define
define|#
directive|define
name|HCR_FB
value|0x0000000000000200
end_define

begin_define
define|#
directive|define
name|HCR_BSU_MASK
value|0x0000000000000c00
end_define

begin_define
define|#
directive|define
name|HCR_DC
value|0x0000000000001000
end_define

begin_define
define|#
directive|define
name|HCR_TWI
value|0x0000000000002000
end_define

begin_define
define|#
directive|define
name|HCR_TWE
value|0x0000000000004000
end_define

begin_define
define|#
directive|define
name|HCR_TID0
value|0x0000000000008000
end_define

begin_define
define|#
directive|define
name|HCR_TID1
value|0x0000000000010000
end_define

begin_define
define|#
directive|define
name|HCR_TID2
value|0x0000000000020000
end_define

begin_define
define|#
directive|define
name|HCR_TID3
value|0x0000000000040000
end_define

begin_define
define|#
directive|define
name|HCR_TSC
value|0x0000000000080000
end_define

begin_define
define|#
directive|define
name|HCR_TIDCP
value|0x0000000000100000
end_define

begin_define
define|#
directive|define
name|HCR_TACR
value|0x0000000000200000
end_define

begin_define
define|#
directive|define
name|HCR_TSW
value|0x0000000000400000
end_define

begin_define
define|#
directive|define
name|HCR_TPC
value|0x0000000000800000
end_define

begin_define
define|#
directive|define
name|HCR_TPU
value|0x0000000001000000
end_define

begin_define
define|#
directive|define
name|HCR_TTLB
value|0x0000000002000000
end_define

begin_define
define|#
directive|define
name|HCR_TVM
value|0x0000000004000000
end_define

begin_define
define|#
directive|define
name|HCR_TGE
value|0x0000000008000000
end_define

begin_define
define|#
directive|define
name|HCR_TDZ
value|0x0000000010000000
end_define

begin_define
define|#
directive|define
name|HCR_HCD
value|0x0000000020000000
end_define

begin_define
define|#
directive|define
name|HCR_TRVM
value|0x0000000040000000
end_define

begin_define
define|#
directive|define
name|HCR_RW
value|0x0000000080000000
end_define

begin_define
define|#
directive|define
name|HCR_CD
value|0x0000000100000000
end_define

begin_define
define|#
directive|define
name|HCR_ID
value|0x0000000200000000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

