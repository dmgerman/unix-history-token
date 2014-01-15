begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: elfts-initversion.c 223 2008-08-10 15:40:06Z jkoshy $  */
end_comment

begin_include
include|#
directive|include
file|<libelf.h>
end_include

begin_include
include|#
directive|include
file|"tet_api.h"
end_include

begin_comment
comment|/*  * A TET startup() function for test cases that need elf_version()  * to be called before each invocable component.  */
end_comment

begin_decl_stmt
name|int
name|elfts_tcinit
init|=
name|TET_PASS
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|elfts_init_version
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|elf_version
argument_list|(
name|EV_CURRENT
argument_list|)
operator|!=
name|EV_CURRENT
condition|)
block|{
name|tet_printf
argument_list|(
literal|"setup: elf_version() failed: %s"
argument_list|,
name|elf_errmsg
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|elfts_tcinit
operator|=
name|TET_UNRESOLVED
expr_stmt|;
block|}
block|}
end_function

end_unit

