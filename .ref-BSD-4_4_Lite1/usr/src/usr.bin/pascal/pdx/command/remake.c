begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)remake.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Remake the object file from the source.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"object.h"
end_include

begin_comment
comment|/*  * Invoke "pi" on the dotpfile, then reread the symbol table information.  *  * We have to save tracing info before, and read it in after, because  * it might contain symbol table pointers.  *  * We also have to restart the process so that px dependent information  * is recomputed.  */
end_comment

begin_macro
name|remake
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|tmpfile
decl_stmt|;
if|if
condition|(
name|call
argument_list|(
literal|"pi"
argument_list|,
name|stdin
argument_list|,
name|stdout
argument_list|,
name|dotpfile
argument_list|,
name|NIL
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|objname
argument_list|,
literal|"obj"
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|call
argument_list|(
literal|"mv"
argument_list|,
name|stdin
argument_list|,
name|stdout
argument_list|,
literal|"obj"
argument_list|,
name|objname
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
block|}
name|tmpfile
operator|=
name|mktemp
argument_list|(
name|strdup
argument_list|(
literal|"/tmp/pdxXXXX"
argument_list|)
argument_list|)
expr_stmt|;
name|setout
argument_list|(
name|tmpfile
argument_list|)
expr_stmt|;
name|status
argument_list|()
expr_stmt|;
name|unsetout
argument_list|()
expr_stmt|;
name|bpfree
argument_list|()
expr_stmt|;
name|objfree
argument_list|()
expr_stmt|;
name|initstart
argument_list|()
expr_stmt|;
name|readobj
argument_list|(
name|objname
argument_list|)
expr_stmt|;
name|setinput
argument_list|(
name|tmpfile
argument_list|)
expr_stmt|;
name|unlink
argument_list|(
name|tmpfile
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|puts
argument_list|(
literal|"pi unsuccessful"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

