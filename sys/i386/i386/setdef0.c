begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 John D. Polstra  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_sets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/*  * BEGIN_SET creates the section and label for a set, and emits the  * count word at the front of it.  The count word initially contains 0,  * but is filled in with the correct value at runtime by init_sets().  */
end_comment

begin_define
define|#
directive|define
name|BEGIN_SET
parameter_list|(
name|set
parameter_list|)
define|\
value|__asm__(".section .set." #set ",\"aw\"");	\ 	__asm__(".globl " #set);			\ 	__asm__(".type " #set ",@object");		\ 	__asm__(".p2align 2");				\ 	__asm__(#set ":");				\ 	__asm__(".long 0");				\ 	__asm__(".previous")
end_define

begin_comment
comment|/*  * DEFINE_SET calls BEGIN_SET and also enters the set into the mother  * of all sets, `set_of_sets'.  */
end_comment

begin_define
define|#
directive|define
name|DEFINE_SET
parameter_list|(
name|set
parameter_list|)
value|BEGIN_SET(set); DATA_SET(set_of_sets, set)
end_define

begin_comment
comment|/*  * Define a set that contains a list of all the other linker sets.  */
end_comment

begin_expr_stmt
name|BEGIN_SET
argument_list|(
name|set_of_sets
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<i386/i386/setdefs.h>
end_include

begin_comment
comment|/* Contains a `DEFINE_SET' for each set */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|linker_set
name|set_of_sets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Fill in the leading "ls_length" fields of all linker sets.  This is  * needed for ELF.  For a.out, it is already done by the linker.  */
end_comment

begin_function
name|void
name|init_sets
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|linker_set
modifier|*
modifier|*
name|lspp
init|=
operator|(
expr|struct
name|linker_set
operator|*
operator|*
operator|)
name|set_of_sets
operator|.
name|ls_items
decl_stmt|;
name|struct
name|linker_set
modifier|*
name|lsp
decl_stmt|;
for|for
control|(
init|;
operator|(
name|lsp
operator|=
operator|*
name|lspp
operator|)
operator|!=
name|NULL
condition|;
name|lspp
operator|++
control|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|lsp
operator|->
name|ls_items
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
comment|/* Count items */
empty_stmt|;
name|lsp
operator|->
name|ls_length
operator|=
name|i
expr_stmt|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! __ELF__ */
end_comment

begin_function
name|void
name|init_sets
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ELF__ */
end_comment

end_unit

