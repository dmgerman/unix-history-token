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
literal|"@(#)getstr.c	5.4 (Berkeley) %G%"
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
comment|/*  *	This routine gets a string starting at (_cury,_curx)  *  */
end_comment

begin_macro
name|wgetstr
argument_list|(
argument|win
argument_list|,
argument|str
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
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
operator|(
operator|*
name|str
operator|=
name|wgetch
argument_list|(
name|win
argument_list|)
operator|)
operator|!=
name|ERR
operator|&&
operator|*
name|str
operator|!=
literal|'\n'
condition|)
name|str
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|str
operator|==
name|ERR
condition|)
block|{
operator|*
name|str
operator|=
literal|'\0'
expr_stmt|;
return|return
name|ERR
return|;
block|}
operator|*
name|str
operator|=
literal|'\0'
expr_stmt|;
return|return
name|OK
return|;
block|}
end_block

end_unit

