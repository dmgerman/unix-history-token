begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)putchar.c	8.2 (Berkeley) %G%"
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
file|"curses.h"
end_include

begin_function
name|void
name|__cputchar
parameter_list|(
name|ch
parameter_list|)
name|int
name|ch
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|__CTRACE
argument_list|(
literal|"__cputchar: %s\n"
argument_list|,
name|unctrl
argument_list|(
name|ch
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|putchar
argument_list|(
name|ch
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

