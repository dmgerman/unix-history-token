begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_SPARC64_FPU_FPU_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBC_SPARC64_FPU_FPU_REG_H_
end_define

begin_comment
comment|/*  * These are not really of type char[]. They are are arrays of functions defined  * in fpu_reg.S; each array member loads/stores a certain fpu register of the  * given size.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|__fpu_ld32
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|__fpu_st32
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|__fpu_ld64
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|__fpu_st64
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of the functions in the arrays. */
end_comment

begin_define
define|#
directive|define
name|FPU_LD32_SZ
value|8
end_define

begin_define
define|#
directive|define
name|FPU_ST32_SZ
value|8
end_define

begin_define
define|#
directive|define
name|FPU_LD64_SZ
value|8
end_define

begin_define
define|#
directive|define
name|FPU_ST64_SZ
value|8
end_define

begin_comment
comment|/* Typedefs for convenient casts in the functions below. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|fp_ldst32_fn
function_decl|)
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|fp_ldst64_fn
function_decl|)
parameter_list|(
name|u_int64_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * These are the functions that are actually used in the fpu emulation code to  * access the fp registers. They are usually not used more than once, so  * cacheing needs not be done here.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int32_t
name|__fpu_getreg
parameter_list|(
name|int
name|r
parameter_list|)
block|{
name|u_int32_t
name|rv
decl_stmt|;
operator|(
operator|(
name|fp_ldst32_fn
operator|*
operator|)
operator|&
name|__fpu_st32
index|[
name|r
operator|*
name|FPU_ST32_SZ
index|]
operator|)
operator|(
operator|&
name|rv
operator|)
expr_stmt|;
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|__fpu_getreg64
parameter_list|(
name|int
name|r
parameter_list|)
block|{
name|u_int64_t
name|rv
decl_stmt|;
operator|(
operator|(
name|fp_ldst64_fn
operator|*
operator|)
operator|&
name|__fpu_st64
index|[
operator|(
name|r
operator|>>
literal|1
operator|)
operator|*
name|FPU_ST64_SZ
index|]
operator|)
operator|(
operator|&
name|rv
operator|)
expr_stmt|;
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__fpu_setreg
parameter_list|(
name|int
name|r
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
operator|(
operator|(
name|fp_ldst32_fn
operator|*
operator|)
operator|&
name|__fpu_ld32
index|[
name|r
operator|*
name|FPU_LD32_SZ
index|]
operator|)
operator|(
operator|&
name|v
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|__fpu_setreg64
parameter_list|(
name|int
name|r
parameter_list|,
name|u_int64_t
name|v
parameter_list|)
block|{
operator|(
operator|(
name|fp_ldst64_fn
operator|*
operator|)
operator|&
name|__fpu_ld64
index|[
operator|(
name|r
operator|>>
literal|1
operator|)
operator|*
name|FPU_LD64_SZ
index|]
operator|)
operator|(
operator|&
name|v
operator|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBC_SPARC64_FPU_FPU_REG_H_ */
end_comment

end_unit

