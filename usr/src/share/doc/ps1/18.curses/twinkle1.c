begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1980 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)twinkle1.c	6.2 (Berkeley) 3/17/89"
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

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/*  * the idea for this program was a product of the imagination of  * Kurt Schoens.  Not responsible for minds lost or stolen.  */
end_comment

begin_define
define|#
directive|define
name|NCOLS
value|80
end_define

begin_define
define|#
directive|define
name|NLINES
value|24
end_define

begin_define
define|#
directive|define
name|MAXPATTERNS
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
block|}
name|LOCS
typedef|;
end_typedef

begin_decl_stmt
name|LOCS
name|Layout
index|[
name|NCOLS
operator|*
name|NLINES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current board layout */
end_comment

begin_decl_stmt
name|int
name|Pattern
decl_stmt|,
comment|/* current pattern number */
name|Numstars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of stars in pattern */
end_comment

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|die
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|()
block|{
name|srand
argument_list|(
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* initialize random sequence */
name|initscr
argument_list|()
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|die
argument_list|)
expr_stmt|;
name|noecho
argument_list|()
expr_stmt|;
name|nonl
argument_list|()
expr_stmt|;
name|leaveok
argument_list|(
name|stdscr
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|scrollok
argument_list|(
name|stdscr
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|makeboard
argument_list|()
expr_stmt|;
comment|/* make the board setup */
name|puton
argument_list|(
literal|'*'
argument_list|)
expr_stmt|;
comment|/* put on '*'s */
name|puton
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
comment|/* cover up with ' 's */
block|}
block|}
end_function

begin_comment
comment|/*  * On program exit, move the cursor to the lower left corner by  * direct addressing, since current location is not guaranteed.  * We lie and say we used to be at the upper right corner to guarantee  * absolute addressing.  */
end_comment

begin_macro
name|die
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|mvcur
argument_list|(
literal|0
argument_list|,
name|COLS
operator|-
literal|1
argument_list|,
name|LINES
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|endwin
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Make the current board setup.  It picks a random pattern and  * calls ison() to determine if the character is on that pattern  * or not.  */
end_comment

begin_macro
name|makeboard
argument_list|()
end_macro

begin_block
block|{
name|reg
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
name|reg
name|LOCS
modifier|*
name|lp
decl_stmt|;
name|Pattern
operator|=
name|rand
argument_list|()
operator|%
name|MAXPATTERNS
expr_stmt|;
name|lp
operator|=
name|Layout
expr_stmt|;
for|for
control|(
name|y
operator|=
literal|0
init|;
name|y
operator|<
name|NLINES
condition|;
name|y
operator|++
control|)
for|for
control|(
name|x
operator|=
literal|0
init|;
name|x
operator|<
name|NCOLS
condition|;
name|x
operator|++
control|)
if|if
condition|(
name|ison
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
condition|)
block|{
name|lp
operator|->
name|y
operator|=
name|y
expr_stmt|;
name|lp
operator|->
name|x
operator|=
name|x
expr_stmt|;
name|lp
operator|++
expr_stmt|;
block|}
name|Numstars
operator|=
name|lp
operator|-
name|Layout
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Return TRUE if (y, x) is on the current pattern.  */
end_comment

begin_macro
name|ison
argument_list|(
argument|y
argument_list|,
argument|x
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

begin_block
block|{
switch|switch
condition|(
name|Pattern
condition|)
block|{
case|case
literal|0
case|:
comment|/* alternating lines */
return|return
operator|!
operator|(
name|y
operator|&
literal|01
operator|)
return|;
case|case
literal|1
case|:
comment|/* box */
if|if
condition|(
name|x
operator|>=
name|LINES
operator|&&
name|y
operator|>=
name|NCOLS
condition|)
return|return
name|FALSE
return|;
if|if
condition|(
name|y
operator|<
literal|3
operator|||
name|y
operator|>=
name|NLINES
operator|-
literal|3
condition|)
return|return
name|TRUE
return|;
return|return
operator|(
name|x
operator|<
literal|3
operator|||
name|x
operator|>=
name|NCOLS
operator|-
literal|3
operator|)
return|;
case|case
literal|2
case|:
comment|/* holy pattern! */
return|return
operator|(
operator|(
name|x
operator|+
name|y
operator|)
operator|&
literal|01
operator|)
return|;
case|case
literal|3
case|:
comment|/* bar across center */
return|return
operator|(
name|y
operator|>=
literal|9
operator|&&
name|y
operator|<=
literal|15
operator|)
return|;
block|}
comment|/* NOTREACHED */
block|}
end_block

begin_macro
name|puton
argument_list|(
argument|ch
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|char
name|ch
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|LOCS
modifier|*
name|lp
decl_stmt|;
name|reg
name|int
name|r
decl_stmt|;
name|reg
name|LOCS
modifier|*
name|end
decl_stmt|;
name|LOCS
name|temp
decl_stmt|;
name|end
operator|=
operator|&
name|Layout
index|[
name|Numstars
index|]
expr_stmt|;
for|for
control|(
name|lp
operator|=
name|Layout
init|;
name|lp
operator|<
name|end
condition|;
name|lp
operator|++
control|)
block|{
name|r
operator|=
name|rand
argument_list|()
operator|%
name|Numstars
expr_stmt|;
name|temp
operator|=
operator|*
name|lp
expr_stmt|;
operator|*
name|lp
operator|=
name|Layout
index|[
name|r
index|]
expr_stmt|;
name|Layout
index|[
name|r
index|]
operator|=
name|temp
expr_stmt|;
block|}
for|for
control|(
name|lp
operator|=
name|Layout
init|;
name|lp
operator|<
name|end
condition|;
name|lp
operator|++
control|)
block|{
name|mvaddch
argument_list|(
name|lp
operator|->
name|y
argument_list|,
name|lp
operator|->
name|x
argument_list|,
name|ch
argument_list|)
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
block|}
block|}
end_block

end_unit

