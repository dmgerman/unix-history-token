begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*	From: NetBSD: crtbegin.c,v 1.2 1997/03/21 05:47:28 cgd Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ECOFF_COMPAT
end_ifndef

begin_comment
comment|/*  * XXX EVENTUALLY SHOULD BE MERGED BACK WITH c++rt0.c  */
end_comment

begin_comment
comment|/*  * Run-time module which handles constructors and destructors,  * and NetBSD identification.  *  * The linker constructs the following arrays of pointers to global  * constructors and destructors. The first element contains the  * number of pointers in each or -1 to indicate that the run-time  * code should figure out how many there are.  The tables are also  * null-terminated.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec_elf.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* #include "sysident.h" */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*__CTOR_LIST__[
literal|1
argument|]
argument_list|)
name|__P
argument_list|(
argument|(void)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".ctors"
argument_list|)
operator|)
argument_list|)
operator|=
block|{
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*__DTOR_LIST__[
literal|1
argument|]
argument_list|)
name|__P
argument_list|(
argument|(void)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".dtors"
argument_list|)
operator|)
argument_list|)
operator|=
block|{
operator|(
name|void
operator|*
operator|)
operator|-
literal|1
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
specifier|static
name|void
name|__dtors
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|__ctors
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|__dtors
parameter_list|()
block|{
name|unsigned
name|long
name|i
init|=
operator|(
name|unsigned
name|long
operator|)
name|__DTOR_LIST__
index|[
literal|0
index|]
decl_stmt|;
name|void
function_decl|(
modifier|*
modifier|*
name|p
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
if|if
condition|(
name|i
operator|==
operator|-
literal|1
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|1
init|;
name|__DTOR_LIST__
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
empty_stmt|;
name|i
operator|--
expr_stmt|;
block|}
name|p
operator|=
name|__DTOR_LIST__
operator|+
name|i
expr_stmt|;
while|while
condition|(
name|i
operator|--
condition|)
operator|(
operator|*
operator|*
name|p
operator|--
operator|)
operator|(
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|__ctors
parameter_list|()
block|{
name|void
function_decl|(
modifier|*
modifier|*
name|p
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|__CTOR_LIST__
operator|+
literal|1
function_decl|;
while|while
condition|(
operator|*
name|p
condition|)
operator|(
operator|*
operator|*
name|p
operator|++
operator|)
operator|(
operator|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|__init
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(section
parameter_list|(
function_decl|".init"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|__init
parameter_list|()
block|{
specifier|static
name|int
name|initialized
init|=
literal|0
decl_stmt|;
comment|/* 	 * Call global constructors. 	 * Arrange to call global destructors at exit. 	 */
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|initialized
operator|=
literal|1
expr_stmt|;
name|__ctors
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|__fini
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(section
parameter_list|(
function_decl|".fini"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|__fini
parameter_list|()
block|{
comment|/* 	 * Call global destructors. 	 */
name|__dtors
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ECOFF_COMPAT */
end_comment

end_unit

