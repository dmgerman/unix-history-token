begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fenv.h>
end_include

begin_decl_stmt
specifier|const
name|fenv_t
name|__fe_dfl_env
init|=
literal|0x0009804c8a70033fULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * It doesn't pay to inline feupdateenv() because it includes one of  * the rare uses of feraiseexcept() where the argument is not a  * constant.  Thus, no dead code elimination can occur, resulting in  * significant bloat.  */
end_comment

begin_function
name|int
name|feupdateenv
parameter_list|(
specifier|const
name|fenv_t
modifier|*
name|envp
parameter_list|)
block|{
name|fenv_t
name|fpsr
decl_stmt|;
name|__stfpsr
argument_list|(
operator|&
name|fpsr
argument_list|)
expr_stmt|;
name|__ldfpsr
argument_list|(
operator|*
name|envp
argument_list|)
expr_stmt|;
name|feraiseexcept
argument_list|(
operator|(
name|fpsr
operator|>>
name|_FPUSW_SHIFT
operator|)
operator|&
name|FE_ALL_EXCEPT
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

