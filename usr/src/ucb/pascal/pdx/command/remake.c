begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)remake.c	5.1 (Berkeley) 6/7/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
literal|"/tmp/pdxXXXX"
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

