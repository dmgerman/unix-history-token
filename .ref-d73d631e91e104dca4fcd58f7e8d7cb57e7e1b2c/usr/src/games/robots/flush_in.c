begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)flush_in.c	5.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_comment
comment|/*  * flush_in:  *	Flush all pending input.  */
end_comment

begin_macro
name|flush_in
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|TIOCFLUSH
name|ioctl
argument_list|(
name|fileno
argument_list|(
name|stdin
argument_list|)
argument_list|,
name|TIOCFLUSH
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
else|#
directive|else
else|TIOCFLUSH
name|crmode
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|TIOCFLUSH
block|}
end_block

end_unit

