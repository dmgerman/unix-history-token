begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)abort.c	5.4 (Berkeley) 9/30/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/* C library -- abort */
end_comment

begin_include
include|#
directive|include
file|"signal.h"
end_include

begin_macro
name|abort
argument_list|()
end_macro

begin_block
block|{
name|sigblock
argument_list|(
operator|~
literal|0L
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|sigsetmask
argument_list|(
operator|~
name|sigmask
argument_list|(
name|SIGILL
argument_list|)
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGILL
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

