begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)putchar.c	5.4 (Berkeley) %G%"
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
file|"curses.ext"
end_include

begin_function
name|char
name|_putchar
parameter_list|(
name|c
parameter_list|)
name|reg
name|char
name|c
decl_stmt|;
block|{
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|outf
argument_list|,
literal|"_PUTCHAR(%s)\n"
argument_list|,
name|unctrl
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

