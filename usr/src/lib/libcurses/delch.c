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
literal|"@(#)delch.c	5.4 (Berkeley) %G%"
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
comment|/*  *	This routine performs an insert-char on the line, leaving  * (_cury,_curx) unchanged.  *  */
end_comment

begin_macro
name|wdelch
argument_list|(
argument|win
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|char
modifier|*
name|temp1
decl_stmt|,
modifier|*
name|temp2
decl_stmt|;
name|reg
name|char
modifier|*
name|end
decl_stmt|;
name|reg
name|int
name|lch
decl_stmt|;
name|end
operator|=
operator|&
name|win
operator|->
name|_y
index|[
name|win
operator|->
name|_cury
index|]
index|[
name|win
operator|->
name|_maxx
operator|-
literal|1
index|]
expr_stmt|;
name|temp1
operator|=
operator|&
name|win
operator|->
name|_y
index|[
name|win
operator|->
name|_cury
index|]
index|[
name|win
operator|->
name|_curx
index|]
expr_stmt|;
name|temp2
operator|=
name|temp1
operator|+
literal|1
expr_stmt|;
while|while
condition|(
name|temp1
operator|<
name|end
condition|)
operator|*
name|temp1
operator|++
operator|=
operator|*
name|temp2
operator|++
expr_stmt|;
operator|*
name|temp1
operator|=
literal|' '
expr_stmt|;
name|touchline
argument_list|(
name|win
argument_list|,
name|win
operator|->
name|_cury
argument_list|,
name|win
operator|->
name|_curx
argument_list|,
name|win
operator|->
name|_maxx
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|OK
return|;
block|}
end_block

end_unit

