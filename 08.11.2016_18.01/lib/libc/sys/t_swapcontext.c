begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_swapcontext.c,v 1.3 2013/05/05 10:28:11 skrll Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012 Emmanuel Dreyfus. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<ucontext.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<lwp.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_define
define|#
directive|define
name|STACKSIZE
value|65536
end_define

begin_decl_stmt
name|char
name|stack
index|[
name|STACKSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ucontext_t
name|nctx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ucontext_t
name|octx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|otls
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|ntls
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|val1
decl_stmt|,
name|val2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|alter_tlsbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARGSUSED0 */
end_comment

begin_function
specifier|static
name|void
name|swapfunc
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|ntls
operator|=
name|_lwp_getprivate
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"after swapcontext TLS pointer = %p\n"
argument_list|,
name|ntls
argument_list|)
expr_stmt|;
if|if
condition|(
name|alter_tlsbase
condition|)
block|{
name|ATF_REQUIRE_EQ
argument_list|(
name|ntls
argument_list|,
operator|&
name|val1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"TLS pointer modified by swapcontext()\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|ATF_REQUIRE_EQ
argument_list|(
name|ntls
argument_list|,
operator|&
name|val2
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"TLS pointer left untouched by swapcontext()\n"
argument_list|)
expr_stmt|;
block|}
comment|/* Go back in main */
name|ATF_REQUIRE
argument_list|(
name|swapcontext
argument_list|(
operator|&
name|nctx
argument_list|,
operator|&
name|octx
argument_list|)
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|mainfunc
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Testing if swapcontext() alters TLS pointer if _UC_TLSBASE "
literal|"is %s\n"
argument_list|,
operator|(
name|alter_tlsbase
operator|)
condition|?
literal|"left set"
else|:
literal|"cleared"
argument_list|)
expr_stmt|;
name|_lwp_setprivate
argument_list|(
operator|&
name|val1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"before swapcontext TLS pointer = %p\n"
argument_list|,
operator|&
name|val1
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|getcontext
argument_list|(
operator|&
name|nctx
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|nctx
operator|.
name|uc_stack
operator|.
name|ss_sp
operator|=
name|stack
expr_stmt|;
name|nctx
operator|.
name|uc_stack
operator|.
name|ss_size
operator|=
sizeof|sizeof
argument_list|(
name|stack
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|_UC_TLSBASE
name|ATF_REQUIRE_MSG
argument_list|(
literal|0
argument_list|,
literal|"_UC_TLSBASE is not defined"
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* _UC_TLSBASE */
name|ATF_REQUIRE
argument_list|(
name|nctx
operator|.
name|uc_flags
operator|&
name|_UC_TLSBASE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|alter_tlsbase
condition|)
name|nctx
operator|.
name|uc_flags
operator|&=
operator|~
name|_UC_TLSBASE
expr_stmt|;
endif|#
directive|endif
comment|/* _UC_TLSBASE */
name|makecontext
argument_list|(
operator|&
name|nctx
argument_list|,
name|swapfunc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_lwp_setprivate
argument_list|(
operator|&
name|val2
argument_list|)
expr_stmt|;
name|otls
operator|=
name|_lwp_getprivate
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"before swapcontext TLS pointer = %p\n"
argument_list|,
name|otls
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|swapcontext
argument_list|(
operator|&
name|octx
argument_list|,
operator|&
name|nctx
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Test completed\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ATF_TC
argument_list|(
name|swapcontext1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|swapcontext1
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Testing if swapcontext() can let "
literal|"TLS pointer untouched"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|swapcontext1
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|alter_tlsbase
operator|=
literal|0
expr_stmt|;
name|mainfunc
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|swapcontext2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|swapcontext2
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Testing if swapcontext() can "
literal|"modify TLS pointer"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|swapcontext2
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|alter_tlsbase
operator|=
literal|1
expr_stmt|;
name|mainfunc
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|swapcontext1
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|swapcontext2
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

