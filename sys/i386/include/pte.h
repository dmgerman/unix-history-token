begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)pte.h	5.5 (Berkeley) 5/9/91  * $FreeBSD$  */
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
value|1
end_define

begin_comment
comment|/*  * 386 page table entry and page table directory  * W.Jolitz, 8/89  *  * There are two major kinds of pte's: those which have ever existed (and are  * thus either now in core or on the swap device), and those which have  * never existed, but which will be filled on demand at first reference.  * There is a structure describing each.  There is also an ancillary  * structure used in page clustering.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|pde
block|{
name|unsigned
name|int
name|pd_v
range|:
literal|1
decl_stmt|,
comment|/* valid bit */
name|pd_prot
range|:
literal|2
decl_stmt|,
comment|/* access control */
name|pd_ncpwt
range|:
literal|1
decl_stmt|,
comment|/* page cache write through */
name|pd_ncpcd
range|:
literal|1
decl_stmt|,
comment|/* page cache disable */
name|pd_u
range|:
literal|1
decl_stmt|,
comment|/* hardware maintained 'used' bit */
name|pd_m
range|:
literal|1
decl_stmt|,
comment|/* not used */
name|pd_mbz2
range|:
literal|2
decl_stmt|,
comment|/* reserved, must be zero */
range|:
literal|3
decl_stmt|,
comment|/* reserved for software */
name|pd_pfnum
range|:
literal|20
decl_stmt|;
comment|/* physical page frame number of pte's*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pte
block|{
name|unsigned
name|int
name|pg_v
range|:
literal|1
decl_stmt|,
comment|/* valid bit */
name|pg_prot
range|:
literal|2
decl_stmt|,
comment|/* access control */
name|pg_ncpwt
range|:
literal|1
decl_stmt|,
comment|/* page cache write through */
name|pg_ncpcd
range|:
literal|1
decl_stmt|,
comment|/* page cache disable */
name|pg_u
range|:
literal|1
decl_stmt|,
comment|/* hardware maintained 'used' bit */
name|pg_m
range|:
literal|1
decl_stmt|,
comment|/* hardware maintained modified bit */
name|pg_mbz2
range|:
literal|2
decl_stmt|,
comment|/* reserved, must be zero */
range|:
literal|3
decl_stmt|,
comment|/* (unused) */
name|pg_pfnum
range|:
literal|20
decl_stmt|;
comment|/* physical page frame number */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PD_MASK
value|0xffc00000
end_define

begin_comment
comment|/* page directory address bits */
end_comment

begin_define
define|#
directive|define
name|PD_SHIFT
value|22
end_define

begin_comment
comment|/* page directory address bits */
end_comment

begin_define
define|#
directive|define
name|PT_MASK
value|0x003ff000UL
end_define

begin_comment
comment|/* page table address bits */
end_comment

begin_define
define|#
directive|define
name|PG_SHIFT
value|12
end_define

begin_comment
comment|/* page table address shift */
end_comment

begin_define
define|#
directive|define
name|PG_V
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PG_RW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PG_u
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_PROT
value|0x00000006
end_define

begin_comment
comment|/* all protection bits . */
end_comment

begin_define
define|#
directive|define
name|PG_NC_PWT
value|0x00000008
end_define

begin_comment
comment|/* page cache write through */
end_comment

begin_define
define|#
directive|define
name|PG_NC_PCD
value|0x00000010
end_define

begin_comment
comment|/* page cache disable */
end_comment

begin_define
define|#
directive|define
name|PG_N
value|0x00000018
end_define

begin_comment
comment|/* Non-cacheable */
end_comment

begin_define
define|#
directive|define
name|PG_U
value|0x00000020
end_define

begin_comment
comment|/* page was accessed */
end_comment

begin_define
define|#
directive|define
name|PG_M
value|0x00000040
end_define

begin_comment
comment|/* page was modified */
end_comment

begin_define
define|#
directive|define
name|PG_W
value|0x00000200
end_define

begin_comment
comment|/* "Wired" pseudoflag */
end_comment

begin_define
define|#
directive|define
name|PG_FRAME
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|PG_NOACC
value|0
end_define

begin_define
define|#
directive|define
name|PG_KR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PG_KW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PG_URKR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_URKW
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PG_UW
value|0x00000006
end_define

begin_define
define|#
directive|define
name|PG_FZERO
value|0
end_define

begin_define
define|#
directive|define
name|PG_FTEXT
value|1
end_define

begin_define
define|#
directive|define
name|PG_FMAX
value|(PG_FTEXT)
end_define

begin_comment
comment|/*  * Page Protection Exception bits  */
end_comment

begin_define
define|#
directive|define
name|PGEX_P
value|0x01
end_define

begin_comment
comment|/* Protection violation vs. not present */
end_comment

begin_define
define|#
directive|define
name|PGEX_W
value|0x02
end_define

begin_comment
comment|/* during a Write cycle */
end_comment

begin_define
define|#
directive|define
name|PGEX_U
value|0x04
end_define

begin_comment
comment|/* access from User mode (UPL) */
end_comment

begin_comment
comment|/*  * Pte related macros  */
end_comment

begin_define
define|#
directive|define
name|dirty
parameter_list|(
name|pte
parameter_list|)
value|((pte)& PG_M)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* utilities defined in pmap.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
modifier|*
name|Sysmap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PTE_H_ */
end_comment

end_unit

