begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: pte.h,v 1.2 1998/08/31 14:43:40 tsubai Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PTE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PTE_H_
end_define

begin_comment
comment|/*  * Page Table Entries  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|pte
block|{
name|u_int
name|pte_hi
decl_stmt|;
name|u_int
name|pte_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pteg
block|{
name|struct
name|pte
name|pt
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_comment
comment|/* High word: */
end_comment

begin_define
define|#
directive|define
name|PTE_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PTE_VSID_SHFT
value|7
end_define

begin_define
define|#
directive|define
name|PTE_HID
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PTE_API
value|0x0000003f
end_define

begin_comment
comment|/* Low word: */
end_comment

begin_define
define|#
directive|define
name|PTE_RPGN
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|PTE_REF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PTE_CHG
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PTE_WIMG
value|0x00000078
end_define

begin_define
define|#
directive|define
name|PTE_W
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PTE_I
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PTE_M
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PTE_G
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PTE_PP
value|0x00000003
end_define

begin_define
define|#
directive|define
name|PTE_SO
value|0x00000000
end_define

begin_comment
comment|/* Super. Only       (U: XX, S: RW) */
end_comment

begin_define
define|#
directive|define
name|PTE_SW
value|0x00000001
end_define

begin_comment
comment|/* Super. Write-Only (U: RO, S: RW) */
end_comment

begin_define
define|#
directive|define
name|PTE_BW
value|0x00000002
end_define

begin_comment
comment|/* Supervisor        (U: RW, S: RW) */
end_comment

begin_define
define|#
directive|define
name|PTE_BR
value|0x00000003
end_define

begin_comment
comment|/* Both Read Only    (U: RO, S: RO) */
end_comment

begin_define
define|#
directive|define
name|PTE_RW
value|PTE_BW
end_define

begin_define
define|#
directive|define
name|PTE_RO
value|PTE_BR
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|pte
name|pte_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_comment
comment|/*  * Extract bits from address  */
end_comment

begin_define
define|#
directive|define
name|ADDR_SR_SHFT
value|28
end_define

begin_define
define|#
directive|define
name|ADDR_PIDX
value|0x0ffff000
end_define

begin_define
define|#
directive|define
name|ADDR_PIDX_SHFT
value|12
end_define

begin_define
define|#
directive|define
name|ADDR_API_SHFT
value|22
end_define

begin_define
define|#
directive|define
name|ADDR_POFF
value|0x00000fff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|pte_t
modifier|*
name|ptable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ptab_cnt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_comment
comment|/*  * Bits in DSISR:  */
end_comment

begin_define
define|#
directive|define
name|DSISR_DIRECT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DSISR_NOTFOUND
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DSISR_PROTECT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DSISR_INVRX
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DSISR_STORE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DSISR_DABR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DSISR_SEGMENT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DSISR_EAR
value|0x00100000
end_define

begin_comment
comment|/*  * Bits in SRR1 on ISI:  */
end_comment

begin_define
define|#
directive|define
name|ISSRR1_NOTFOUND
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ISSRR1_DIRECT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ISSRR1_PROTECT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ISSRR1_SEGMENT
value|0x00200000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_function_decl
specifier|extern
name|u_int
name|dsisr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PTE_H_ */
end_comment

end_unit

