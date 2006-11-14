begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2002 Benno Rice.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_access.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_sym.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_variables.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_watch.h>
end_include

begin_function_decl
name|int
name|db_md_set_watchpoint
parameter_list|(
name|db_expr_t
parameter_list|,
name|db_expr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_md_clr_watchpoint
parameter_list|(
name|db_expr_t
parameter_list|,
name|db_expr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_md_list_watchpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|db_md_set_watchpoint
parameter_list|(
name|db_expr_t
name|addr
parameter_list|,
name|db_expr_t
name|size
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|db_md_clr_watchpoint
parameter_list|(
name|db_expr_t
name|addr
parameter_list|,
name|db_expr_t
name|size
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|db_md_list_watchpoints
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

