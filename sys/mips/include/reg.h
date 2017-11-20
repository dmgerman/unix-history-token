begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: reg.h,v 1.1 1998/01/28 11:14:53 pefo Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Utah Hdr: reg.h 1.1 90/07/09  *	@(#)reg.h	8.2 (Berkeley) 1/11/94  *	JNPR: reg.h,v 1.6 2006/09/15 12:52:34 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_REG_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_STANDALONE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_compat.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Location of the users' stored registers relative to ZERO.  * must be visible to assembly code.  */
end_comment

begin_include
include|#
directive|include
file|<machine/regnum.h>
end_include

begin_comment
comment|/*  * Register set accessible via /proc/$pid/reg  */
end_comment

begin_struct
struct|struct
name|reg
block|{
name|register_t
name|r_regs
index|[
name|NUMSAVEREGS
index|]
decl_stmt|;
comment|/* numbered as above */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpreg
block|{
name|f_register_t
name|r_regs
index|[
name|NUMFPREGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Placeholder.  */
end_comment

begin_struct
struct|struct
name|dbreg
block|{
name|unsigned
name|long
name|junk
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_comment
comment|/* Must match struct trapframe */
end_comment

begin_struct
struct|struct
name|reg32
block|{
name|uint32_t
name|r_regs
index|[
name|NUMSAVEREGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpreg32
block|{
name|int32_t
name|r_regs
index|[
name|NUMFPREGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbreg32
block|{
name|uint32_t
name|junk
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|__HAVE_REG32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|fill_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_regs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_regs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

begin_struct_decl
struct_decl|struct
name|image_params
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|fill_regs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_regs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|reg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fill_fpregs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_fpregs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|fpreg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fill_dbregs32
parameter_list|(
name|td
parameter_list|,
name|reg
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|set_dbregs32
parameter_list|(
name|td
parameter_list|,
name|reg
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_REG_H_ */
end_comment

end_unit

