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
literal|"@(#)addch.c	5.5 (Berkeley) %G%"
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

begin_comment
comment|/*  *	This routine adds the character to the current position  *  */
end_comment

begin_macro
name|waddch
argument_list|(
argument|win
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|waddbytes
argument_list|(
name|win
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_block

end_unit

