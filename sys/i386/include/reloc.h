begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)reloc.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_MACHINE_RELOC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_MACHINE_RELOC_H_
end_define

begin_comment
comment|/* Relocation format. */
end_comment

begin_struct
struct|struct
name|relocation_info
block|{
name|int
name|r_address
decl_stmt|;
comment|/* offset in text or data segment */
name|unsigned
name|int
name|r_symbolnum
range|:
literal|24
decl_stmt|,
comment|/* ordinal number of add symbol */
name|r_pcrel
range|:
literal|1
decl_stmt|,
comment|/* 1 if value should be pc-relative */
name|r_length
range|:
literal|2
decl_stmt|,
comment|/* log base 2 of value's width */
name|r_extern
range|:
literal|1
decl_stmt|,
comment|/* 1 if need to add symbol to value */
name|r_baserel
range|:
literal|1
decl_stmt|,
comment|/* linkage table relative */
name|r_jmptable
range|:
literal|1
decl_stmt|,
comment|/* relocate to jump table */
name|r_relative
range|:
literal|1
decl_stmt|,
comment|/* load address relative */
name|r_copy
range|:
literal|1
decl_stmt|;
comment|/* run time copy */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

