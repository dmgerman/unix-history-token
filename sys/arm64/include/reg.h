begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner  * Copyright (c) 2014-2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_struct
struct|struct
name|reg
block|{
name|uint64_t
name|x
index|[
literal|30
index|]
decl_stmt|;
name|uint64_t
name|lr
decl_stmt|;
name|uint64_t
name|sp
decl_stmt|;
name|uint64_t
name|elr
decl_stmt|;
name|uint32_t
name|spsr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reg32
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpreg
block|{
name|__uint128_t
name|fp_q
index|[
literal|32
index|]
decl_stmt|;
name|uint32_t
name|fp_sr
decl_stmt|;
name|uint32_t
name|fp_cr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fpreg32
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbreg
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dbreg32
block|{
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|__HAVE_REG32
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * XXX these interfaces are MI, so they should be declared in a MI place.  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

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

begin_function_decl
name|int
name|fill_dbregs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_dbregs32
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|dbreg32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_MACHINE_REG_H_ */
end_comment

end_unit

