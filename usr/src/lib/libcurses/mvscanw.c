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
literal|"@(#)mvscanw.c	5.4 (Berkeley) %G%"
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
comment|/*  * implement the mvscanw commands.  Due to the variable number of  * arguments, they cannot be macros.  Another sigh....  *  */
end_comment

begin_macro
name|mvscanw
argument_list|(
argument|y
argument_list|,
argument|x
argument_list|,
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|move
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|OK
condition|?
name|_sscans
argument_list|(
name|stdscr
argument_list|,
name|fmt
argument_list|,
operator|&
name|args
argument_list|)
else|:
name|ERR
return|;
block|}
end_block

begin_macro
name|mvwscanw
argument_list|(
argument|win
argument_list|,
argument|y
argument_list|,
argument|x
argument_list|,
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|reg
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|wmove
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
operator|==
name|OK
condition|?
name|_sscans
argument_list|(
name|win
argument_list|,
name|fmt
argument_list|,
operator|&
name|args
argument_list|)
else|:
name|ERR
return|;
block|}
end_block

end_unit

