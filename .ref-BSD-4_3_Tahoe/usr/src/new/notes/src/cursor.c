begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: cursor.c,v 1.7 85/01/18 15:07:42 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *  at(row,col) places cursor on hazeltine at row,col  *	row = 1 to 24    ( y coords )  * 	column = 1 to 80   ( x coords )  *  *	numbers<=0 will have "nrows" or "ncols" added to them so  *	as to allow "floating" positioning relative to the bottom  *	or right side of the screen  *  *	-- modified 18-nov-1981 R. Essick to handle different tty types   *  */
end_comment

begin_decl_stmt
specifier|static
name|short
name|ttyinit
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whether have gotten termcap */
end_comment

begin_decl_stmt
specifier|static
name|char
name|bufspace
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* term capabilities */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cm
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cursor motion */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cls
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clear screen string */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ti
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start cursor motion */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|te
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stop cursor motion */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ce
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clear to eol */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|BC
decl_stmt|,
modifier|*
name|UP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* backspace, upspave */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|BC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* backspaces */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|UP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* up 1 line */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|atrow
decl_stmt|,
name|atcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current position */
end_comment

begin_function_decl
name|char
modifier|*
name|tgoto
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* decodes the cursor via termcap */
end_comment

begin_comment
comment|/*	charout - output 1 character */
end_comment

begin_comment
comment|/*	used by tputs routine in at */
end_comment

begin_macro
name|charout
argument_list|(
argument|c
argument_list|)
end_macro

begin_block
block|{
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|at
argument_list|(
argument|row
argument_list|,
argument|col
argument_list|)
end_macro

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|ttyinit
operator|==
literal|0
condition|)
name|cursget
argument_list|()
expr_stmt|;
comment|/* initialize termcap */
if|if
condition|(
name|cm
operator|!=
name|NULL
condition|)
comment|/* was there a cm field? */
block|{
if|if
condition|(
name|row
operator|<=
literal|0
condition|)
name|row
operator|+=
name|nrows
expr_stmt|;
comment|/* wraparound - cute */
if|if
condition|(
name|col
operator|<=
literal|0
condition|)
name|col
operator|+=
name|ncols
expr_stmt|;
name|p
operator|=
name|tgoto
argument_list|(
name|cm
argument_list|,
name|col
operator|-
literal|1
argument_list|,
name|row
operator|-
literal|1
argument_list|)
expr_stmt|;
name|tputs
argument_list|(
name|p
argument_list|,
literal|1
argument_list|,
name|charout
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|atrow
operator|!=
name|row
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|atrow
operator|=
name|row
expr_stmt|;
name|atcol
operator|=
name|col
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * erase()  erases the screen  *	modified R. Essick 18-nov-81 - allow different tty types   *	Modified R Kolstad Jan '84 for true erase-abort function  */
end_comment

begin_macro
name|erase
argument_list|()
end_macro

begin_block
block|{
name|clearerr
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
comment|/* to be sure */
if|if
condition|(
name|ttyinit
operator|==
literal|0
condition|)
name|cursget
argument_list|()
expr_stmt|;
comment|/* initialize termcap */
ifdef|#
directive|ifdef
name|BSD4x
block|{
include|#
directive|include
file|<sgtty.h>
name|int
name|flusher
init|=
literal|2
decl_stmt|;
comment|/*  *	2 is magic constant used in kernel to mean flush write buffers  *	only.  */
name|ioctl
argument_list|(
literal|1
argument_list|,
name|TIOCFLUSH
argument_list|,
operator|&
name|flusher
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|BSD4x
if|if
condition|(
name|cls
operator|!=
name|NULL
condition|)
name|tputs
argument_list|(
name|cls
argument_list|,
literal|1
argument_list|,
name|charout
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"\n\n"
argument_list|)
expr_stmt|;
name|atrow
operator|=
literal|1
expr_stmt|;
comment|/* back in top of screen */
name|atcol
operator|=
literal|1
expr_stmt|;
comment|/* on left hand side */
block|}
end_block

begin_comment
comment|/*  *	cmstart, cmstop  *  *	prepare fancy tty's for cursor motion stuff   *  */
end_comment

begin_macro
name|cmstart
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|ttyinit
operator|==
literal|0
condition|)
name|cursget
argument_list|()
expr_stmt|;
if|if
condition|(
name|ti
operator|!=
name|NULL
condition|)
name|tputs
argument_list|(
name|ti
argument_list|,
literal|1
argument_list|,
name|charout
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cmstop
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|ttyinit
operator|==
literal|0
condition|)
name|cursget
argument_list|()
expr_stmt|;
if|if
condition|(
name|te
operator|!=
name|NULL
condition|)
name|tputs
argument_list|(
name|te
argument_list|,
literal|1
argument_list|,
name|charout
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *	clear to end of line if the capability exists.  *  *	FIX FOR DUMB TERMINALS  */
end_comment

begin_macro
name|ceol
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|ttyinit
operator|==
literal|0
condition|)
name|cursget
argument_list|()
expr_stmt|;
if|if
condition|(
name|ce
operator|!=
name|NULL
condition|)
name|tputs
argument_list|(
name|ce
argument_list|,
literal|1
argument_list|,
name|charout
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|cursget
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|tgetstr
argument_list|()
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
specifier|extern
name|char
modifier|*
name|histty
decl_stmt|;
comment|/* tty type on control card */
specifier|register
name|int
name|i
decl_stmt|;
comment|/* rows, cols */
name|char
name|bp
index|[
literal|1024
index|]
decl_stmt|;
comment|/* termcap stuff */
comment|/*	bp made dynamic to give the pdp-11 breathing room */
name|ttyinit
operator|=
literal|1
expr_stmt|;
comment|/* say we got it */
comment|/*  *	ttyinit set now so don't loop on ttystop/cmstop/cursget/ttystop...  */
if|if
condition|(
operator|(
name|p
operator|=
name|histty
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|p
operator|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
comment|/* a terminal ?? */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"You have no TERM environmental variable.  This variable tells the\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"system what type of terminal you are using so it's features may be used.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"To set this variable:\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"	From csh type 'setenv TERM<term-type>'.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"	From sh type 'TERM=<termtype>;export TERM'.\n\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Where<term-type> is the system designation for your terminal.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"(E.g. hp2621, adm3a, aaa40, etc).\n"
argument_list|)
expr_stmt|;
name|ttystop
argument_list|()
expr_stmt|;
comment|/* make sure tty is in normal state */
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
comment|/* and terminate */
block|}
block|}
if|if
condition|(
name|tgetent
argument_list|(
name|bp
argument_list|,
name|p
argument_list|)
operator|!=
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't find capabilities for terminal type \"%s\"\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|ttystop
argument_list|()
expr_stmt|;
comment|/* reset tty states */
name|exit
argument_list|(
name|BAD
argument_list|)
expr_stmt|;
block|}
name|q
operator|=
name|bufspace
expr_stmt|;
name|cm
operator|=
name|tgetstr
argument_list|(
literal|"cm"
argument_list|,
operator|&
name|q
argument_list|)
expr_stmt|;
comment|/* get cursor motion */
name|cls
operator|=
name|tgetstr
argument_list|(
literal|"cl"
argument_list|,
operator|&
name|q
argument_list|)
expr_stmt|;
comment|/* clear screen */
name|ti
operator|=
name|tgetstr
argument_list|(
literal|"ti"
argument_list|,
operator|&
name|q
argument_list|)
expr_stmt|;
comment|/* start cursor motion */
name|te
operator|=
name|tgetstr
argument_list|(
literal|"te"
argument_list|,
operator|&
name|q
argument_list|)
expr_stmt|;
comment|/* stop cursor motion */
name|UP
operator|=
name|tgetstr
argument_list|(
literal|"up"
argument_list|,
operator|&
name|q
argument_list|)
expr_stmt|;
comment|/* cursor up */
name|BC
operator|=
name|tgetstr
argument_list|(
literal|"bc"
argument_list|,
operator|&
name|q
argument_list|)
expr_stmt|;
comment|/* cursor left */
name|ce
operator|=
name|tgetstr
argument_list|(
literal|"ce"
argument_list|,
operator|&
name|q
argument_list|)
expr_stmt|;
comment|/* clear to eol */
if|if
condition|(
operator|(
name|i
operator|=
name|tgetnum
argument_list|(
literal|"li"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
name|nrows
operator|=
name|i
expr_stmt|;
comment|/* rows on screen */
if|if
condition|(
name|nrows
operator|!=
literal|24
condition|)
comment|/* different screen size */
block|{
name|Nindex
operator|=
name|nrows
operator|-
literal|12
expr_stmt|;
comment|/* header, trailer, prompt */
block|}
if|if
condition|(
operator|(
name|i
operator|=
name|tgetnum
argument_list|(
literal|"co"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
name|ncols
operator|=
name|i
expr_stmt|;
comment|/* cols on screen */
block|}
end_block

begin_comment
comment|/*  * miscellaneous output routines for the terminal  *  * center(p,len,row,col) takes a character string pointed at by p and centers it  *    within a field of length n.  it is printed on screen at row,col  *    (centered).  It is also assumed that p's string is BLANK TERMINATED  *  * prdate(w) struct when_f *w;  prints the date.  Assumes 'at' is already done  *  * sprdate(w,str) struct when_f *w; char str[]; formats the date and returns  *		the result in the string pointed to by str.  *  */
end_comment

begin_macro
name|center
argument_list|(
argument|p
argument_list|,
argument|len
argument_list|,
argument|row
argument_list|,
argument|col
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|r
decl_stmt|;
name|i
operator|=
name|strlen
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* get length */
if|if
condition|(
name|i
operator|!=
literal|0
condition|)
block|{
name|at
argument_list|(
name|row
argument_list|,
name|col
operator|+
operator|(
name|len
operator|-
name|i
operator|)
operator|/
literal|2
argument_list|)
expr_stmt|;
name|fwrite
argument_list|(
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|,
name|i
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
comment|/* write it */
block|}
block|}
end_block

end_unit

