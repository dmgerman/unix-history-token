begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|RCSid
init|=
literal|"$Id: readline.c%v 3.50.1.9 1993/08/05 05:38:59 woo Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNUPLOT - readline.c */
end_comment

begin_comment
comment|/*  * Copyright (C) 1986 - 1993   Thomas Williams, Colin Kelley  *  * Permission to use, copy, and distribute this software and its  * documentation for any purpose with or without fee is hereby granted,   * provided that the above copyright notice appear in all copies and   * that both that copyright notice and this permission notice appear   * in supporting documentation.  *  * Permission to modify the software is granted, but not the right to  * distribute the modified code.  Modifications are to be distributed   * as patches to released version.  *    * This software is provided "as is" without express or implied warranty.  *   *  * AUTHORS  *  *   Original Software:  *     Tom Tkacik  *  *   Msdos port and some enhancements:  *     Gershon Elber and many others.  *   * There is a mailing list for gnuplot users. Note, however, that the  * newsgroup   *	comp.graphics.gnuplot   * is identical to the mailing list (they  * both carry the same set of messages). We prefer that you read the  * messages through that newsgroup, to subscribing to the mailing list.  * (If you can read that newsgroup, and are already on the mailing list,  * please send a message info-gnuplot-request@dartmouth.edu, asking to be  * removed from the mailing list.)  *  * The address for mailing to list members is  *	   info-gnuplot@dartmouth.edu  * and for mailing administrative requests is   *	   info-gnuplot-request@dartmouth.edu  * The mailing list for bug reports is   *	   bug-gnuplot@dartmouth.edu  * The list of those interested in beta-test versions is  *	   info-gnuplot-beta@dartmouth.edu  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|READLINE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ATARI
end_ifdef

begin_include
include|#
directive|include
file|"plot.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WINDOWS
end_ifdef

begin_define
define|#
directive|define
name|_Windows
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* a small portable version of GNU's readline */
end_comment

begin_comment
comment|/* this is not the BASH or GNU EMACS version of READLINE due to Copyleft  	restrictions */
end_comment

begin_comment
comment|/* do not need any terminal capabilities except backspace, */
end_comment

begin_comment
comment|/* and space overwrites a character */
end_comment

begin_comment
comment|/* NANO-EMACS line editing facility */
end_comment

begin_comment
comment|/* printable characters print as themselves (insert not overwrite) */
end_comment

begin_comment
comment|/* ^A moves to the beginning of the line */
end_comment

begin_comment
comment|/* ^B moves back a single character */
end_comment

begin_comment
comment|/* ^E moves to the end of the line */
end_comment

begin_comment
comment|/* ^F moves forward a single character */
end_comment

begin_comment
comment|/* ^K kills from current position to the end of line */
end_comment

begin_comment
comment|/* ^P moves back through history */
end_comment

begin_comment
comment|/* ^N moves forward through history */
end_comment

begin_comment
comment|/* ^H and DEL delete the previous character */
end_comment

begin_comment
comment|/* ^D deletes the current character, or EOF if line is empty */
end_comment

begin_comment
comment|/* ^L/^R redraw line in case it gets trashed */
end_comment

begin_comment
comment|/* ^U kills the entire line */
end_comment

begin_comment
comment|/* ^W kills last word */
end_comment

begin_comment
comment|/* LF and CR return the entire line regardless of the cursor postition */
end_comment

begin_comment
comment|/* EOF with an empty line returns (char *)NULL */
end_comment

begin_comment
comment|/* all other characters are ignored */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ATARI
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_Windows
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DOS386
argument_list|)
end_if

begin_comment
comment|/*  * Set up structures using the proper include file  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_IBMR2
argument_list|)
operator|||
name|defined
argument_list|(
name|alliant
argument_list|)
end_if

begin_define
define|#
directive|define
name|SGTTY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  submitted by Francois.Dagorn@cicb.fr */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SGTTY
end_ifdef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|sgttyb
name|orig_termio
decl_stmt|,
name|rl_termio
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* define terminal control characters */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|tchars
name|s_tchars
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VERASE
value|0
end_define

begin_define
define|#
directive|define
name|VEOF
value|1
end_define

begin_define
define|#
directive|define
name|VKILL
value|2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCGLTC
end_ifdef

begin_comment
comment|/* available only with the 'new' line discipline */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|ltchars
name|s_ltchars
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VWERASE
value|3
end_define

begin_define
define|#
directive|define
name|VREPRINT
value|4
end_define

begin_define
define|#
directive|define
name|VSUSP
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIOCGLTC */
end_comment

begin_define
define|#
directive|define
name|NCCS
value|6
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SGTTY */
end_comment

begin_comment
comment|/* SIGTSTP defines job control */
end_comment

begin_comment
comment|/* if there is job control then we need termios.h instead of termio.h */
end_comment

begin_comment
comment|/* (Are there any systems with job control that use termio.h?  I hope not.) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIGTSTP
end_ifdef

begin_define
define|#
directive|define
name|TERMIOS
end_define

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_comment
comment|/* Added by Robert Eckardt, RobertE@beta.TP2.Ruhr-Uni-Bochum.de */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC22
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ONOCR
end_ifndef

begin_comment
comment|/* taken from sys/termio.h */
end_comment

begin_define
define|#
directive|define
name|ONOCR
value|0000020
end_define

begin_comment
comment|/* true at least for ISC 2.2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IUCLC
end_ifndef

begin_define
define|#
directive|define
name|IUCLC
value|0001000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC22 */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|termios
name|orig_termio
decl_stmt|,
name|rl_termio
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|termio
name|orig_termio
decl_stmt|,
name|rl_termio
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* termio defines NCC instead of NCCS */
end_comment

begin_define
define|#
directive|define
name|NCCS
value|NCC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTSTP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SGTTY */
end_comment

begin_comment
comment|/* ULTRIX defines VRPRNT instead of VREPRINT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VRPRNT
end_ifdef

begin_define
define|#
directive|define
name|VREPRINT
value|VRPRNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* define characters to use with our input character handler */
end_comment

begin_decl_stmt
specifier|static
name|char
name|term_chars
index|[
name|NCCS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|term_set
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* =1 if rl_termio set */
end_comment

begin_define
define|#
directive|define
name|special_getc
parameter_list|()
value|ansi_getc()
end_define

begin_function_decl
specifier|static
name|char
name|ansi_getc
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MSDOS&& !ATARI&& !_Windows */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_Windows
end_ifdef

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|"win/wtext.h"
end_include

begin_include
include|#
directive|include
file|"win/wgnuplib.h"
end_include

begin_decl_stmt
specifier|extern
name|TW
name|textwin
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TEXTUSER
value|0xf1
end_define

begin_define
define|#
directive|define
name|TEXTGNUPLOT
value|0xf0
end_define

begin_define
define|#
directive|define
name|special_getc
parameter_list|()
value|msdos_getch()
end_define

begin_function_decl
specifier|static
name|char
name|msdos_getch
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|DOS386
argument_list|)
end_if

begin_comment
comment|/* MSDOS specific stuff */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DJGPP
end_ifdef

begin_include
include|#
directive|include
file|<pc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

begin_include
include|#
directive|include
file|<conio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|special_getc
parameter_list|()
value|msdos_getch()
end_define

begin_function_decl
specifier|static
name|char
name|msdos_getch
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATARI
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__PUREC__
end_ifdef

begin_include
include|#
directive|include
file|<tos.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<osbind.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|special_getc
parameter_list|()
value|tos_getch()
end_define

begin_function_decl
specifier|static
name|char
name|tos_getch
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MSDOS&& !ATARI&& !_Windows */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ATARI
argument_list|)
end_if

begin_comment
comment|/* is it<string.h> or<strings.h>?   just declare what we need */
end_comment

begin_function_decl
specifier|extern
name|int
name|strlen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|alloc
value|malloc
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|alloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* we'll use the safe malloc from misc.c */
end_comment

begin_define
define|#
directive|define
name|MAXBUF
value|1024
end_define

begin_define
define|#
directive|define
name|BACKSPACE
value|0x08
end_define

begin_comment
comment|/* ^H */
end_comment

begin_define
define|#
directive|define
name|SPACE
value|' '
end_define

begin_struct
struct|struct
name|hist
block|{
name|char
modifier|*
name|line
decl_stmt|;
name|struct
name|hist
modifier|*
name|prev
decl_stmt|;
name|struct
name|hist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|hist
modifier|*
name|history
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no history yet */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|hist
modifier|*
name|cur_entry
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|cur_line
index|[
name|MAXBUF
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current contents of the line */
end_comment

begin_decl_stmt
specifier|static
name|int
name|cur_pos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current position of the cursor */
end_comment

begin_decl_stmt
specifier|static
name|int
name|max_pos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum character position */
end_comment

begin_function_decl
name|void
name|add_history
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|fix_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|redraw_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|clear_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|clear_eoline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|copy_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|set_termio
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_termio
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* user_putc and user_puts should be used in the place of  * fputc(ch,stderr) and fputs(str,stderr) for all output  * of user typed characters.  This allows MS-Windows to   * display user input in a different color. */
end_comment

begin_function
name|int
name|user_putc
parameter_list|(
name|ch
parameter_list|)
name|int
name|ch
decl_stmt|;
block|{
name|int
name|rv
decl_stmt|;
ifdef|#
directive|ifdef
name|_Windows
name|TextAttr
argument_list|(
operator|&
name|textwin
argument_list|,
name|TEXTUSER
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|rv
operator|=
name|fputc
argument_list|(
name|ch
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_Windows
name|TextAttr
argument_list|(
operator|&
name|textwin
argument_list|,
name|TEXTGNUPLOT
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|rv
return|;
block|}
end_function

begin_function
name|int
name|user_puts
parameter_list|(
name|str
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
block|{
name|int
name|rv
decl_stmt|;
ifdef|#
directive|ifdef
name|_Windows
name|TextAttr
argument_list|(
operator|&
name|textwin
argument_list|,
name|TEXTUSER
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|rv
operator|=
name|fputs
argument_list|(
name|str
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_Windows
name|TextAttr
argument_list|(
operator|&
name|textwin
argument_list|,
name|TEXTGNUPLOT
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|rv
return|;
block|}
end_function

begin_comment
comment|/* This function provides a centralized non-destructive backspace capability */
end_comment

begin_comment
comment|/* M. Castro */
end_comment

begin_macro
name|backspace
argument_list|()
end_macro

begin_block
block|{
name|user_putc
argument_list|(
name|BACKSPACE
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|char
modifier|*
name|readline
parameter_list|(
name|prompt
parameter_list|)
name|char
modifier|*
name|prompt
decl_stmt|;
block|{
name|unsigned
name|char
name|cur_char
decl_stmt|;
name|char
modifier|*
name|new_line
decl_stmt|;
comment|/* unsigned char *new_line; */
comment|/* set the termio so we can do our own input processing */
name|set_termio
argument_list|()
expr_stmt|;
comment|/* print the prompt */
name|fputs
argument_list|(
name|prompt
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|cur_line
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
name|cur_pos
operator|=
literal|0
expr_stmt|;
name|max_pos
operator|=
literal|0
expr_stmt|;
name|cur_entry
operator|=
name|NULL
expr_stmt|;
comment|/* get characters */
for|for
control|(
init|;
condition|;
control|)
block|{
name|cur_char
operator|=
name|special_getc
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
comment|/* for emx: remap scan codes for cursor keys */
if|if
condition|(
name|cur_char
operator|==
literal|0
condition|)
block|{
name|cur_char
operator|=
name|getc
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cur_char
condition|)
block|{
case|case
literal|75
case|:
comment|/* left, map to ^B */
name|cur_char
operator|=
literal|2
expr_stmt|;
break|break ;
case|case
literal|77
case|:
comment|/* right, map to ^F */
name|cur_char
operator|=
literal|6
expr_stmt|;
break|break ;
case|case
literal|115
case|:
comment|/* ctrl left */
case|case
literal|71
case|:
comment|/* home, map to ^A */
name|cur_char
operator|=
literal|1
expr_stmt|;
break|break ;
case|case
literal|116
case|:
comment|/* ctrl right */
case|case
literal|79
case|:
comment|/* end, map to ^E */
name|cur_char
operator|=
literal|5
expr_stmt|;
break|break ;
case|case
literal|72
case|:
comment|/* up, map to ^P */
name|cur_char
operator|=
literal|16
expr_stmt|;
break|break ;
case|case
literal|80
case|:
comment|/* down, map to ^N */
name|cur_char
operator|=
literal|14
expr_stmt|;
break|break ;
case|case
literal|83
case|:
comment|/* delete, map to ^D */
name|cur_char
operator|=
literal|4
expr_stmt|;
break|break ;
default|default:
comment|/* ignore */
name|cur_char
operator|=
literal|0
expr_stmt|;
continue|continue ;
block|}
block|}
endif|#
directive|endif
comment|/*OS2*/
if|if
condition|(
operator|(
name|isprint
argument_list|(
name|cur_char
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|ATARI
argument_list|)
operator|||
name|defined
argument_list|(
name|_Windows
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|DOS386
argument_list|)
comment|/* this should be used for all 8bit ASCII machines, I guess */
operator|||
operator|(
operator|(
name|unsigned
name|char
operator|)
name|cur_char
operator|>
literal|0x7f
operator|)
endif|#
directive|endif
operator|)
operator|&&
name|max_pos
operator|<
name|MAXBUF
operator|-
literal|1
condition|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
name|max_pos
init|;
name|i
operator|>
name|cur_pos
condition|;
name|i
operator|--
control|)
block|{
name|cur_line
index|[
name|i
index|]
operator|=
name|cur_line
index|[
name|i
operator|-
literal|1
index|]
expr_stmt|;
block|}
name|user_putc
argument_list|(
name|cur_char
argument_list|)
expr_stmt|;
name|cur_line
index|[
name|cur_pos
index|]
operator|=
name|cur_char
expr_stmt|;
name|cur_pos
operator|+=
literal|1
expr_stmt|;
name|max_pos
operator|+=
literal|1
expr_stmt|;
if|if
condition|(
name|cur_pos
operator|<
name|max_pos
condition|)
name|fix_line
argument_list|()
expr_stmt|;
name|cur_line
index|[
name|max_pos
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* else interpret unix terminal driver characters */
ifdef|#
directive|ifdef
name|VERASE
block|}
elseif|else
if|if
condition|(
name|cur_char
operator|==
name|term_chars
index|[
name|VERASE
index|]
condition|)
block|{
comment|/* DEL? */
if|if
condition|(
name|cur_pos
operator|>
literal|0
condition|)
block|{
name|int
name|i
decl_stmt|;
name|cur_pos
operator|-=
literal|1
expr_stmt|;
name|backspace
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
name|cur_pos
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|cur_line
index|[
name|i
index|]
operator|=
name|cur_line
index|[
name|i
operator|+
literal|1
index|]
expr_stmt|;
name|max_pos
operator|-=
literal|1
expr_stmt|;
name|fix_line
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* VERASE */
ifdef|#
directive|ifdef
name|VEOF
block|}
elseif|else
if|if
condition|(
name|cur_char
operator|==
name|term_chars
index|[
name|VEOF
index|]
condition|)
block|{
comment|/* ^D? */
if|if
condition|(
name|max_pos
operator|==
literal|0
condition|)
block|{
name|reset_termio
argument_list|()
expr_stmt|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|NULL
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|cur_pos
operator|<
name|max_pos
operator|)
operator|&&
operator|(
name|cur_char
operator|==
literal|004
operator|)
condition|)
block|{
comment|/* ^D */
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
name|cur_pos
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|cur_line
index|[
name|i
index|]
operator|=
name|cur_line
index|[
name|i
operator|+
literal|1
index|]
expr_stmt|;
name|max_pos
operator|-=
literal|1
expr_stmt|;
name|fix_line
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* VEOF */
ifdef|#
directive|ifdef
name|VKILL
block|}
elseif|else
if|if
condition|(
name|cur_char
operator|==
name|term_chars
index|[
name|VKILL
index|]
condition|)
block|{
comment|/* ^U? */
name|clear_line
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VKILL */
ifdef|#
directive|ifdef
name|VWERASE
block|}
elseif|else
if|if
condition|(
name|cur_char
operator|==
name|term_chars
index|[
name|VWERASE
index|]
condition|)
block|{
comment|/* ^W? */
while|while
condition|(
operator|(
name|cur_pos
operator|>
literal|0
operator|)
operator|&&
operator|(
name|cur_line
index|[
name|cur_pos
operator|-
literal|1
index|]
operator|==
name|SPACE
operator|)
condition|)
block|{
name|cur_pos
operator|-=
literal|1
expr_stmt|;
name|backspace
argument_list|()
expr_stmt|;
block|}
while|while
condition|(
operator|(
name|cur_pos
operator|>
literal|0
operator|)
operator|&&
operator|(
name|cur_line
index|[
name|cur_pos
operator|-
literal|1
index|]
operator|!=
name|SPACE
operator|)
condition|)
block|{
name|cur_pos
operator|-=
literal|1
expr_stmt|;
name|backspace
argument_list|()
expr_stmt|;
block|}
name|clear_eoline
argument_list|()
expr_stmt|;
name|max_pos
operator|=
name|cur_pos
expr_stmt|;
endif|#
directive|endif
comment|/* VWERASE */
ifdef|#
directive|ifdef
name|VREPRINT
block|}
elseif|else
if|if
condition|(
name|cur_char
operator|==
name|term_chars
index|[
name|VREPRINT
index|]
condition|)
block|{
comment|/* ^R? */
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
comment|/* go to a fresh line */
name|redraw_line
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VREPRINT */
ifdef|#
directive|ifdef
name|VSUSP
block|}
elseif|else
if|if
condition|(
name|cur_char
operator|==
name|term_chars
index|[
name|VSUSP
index|]
condition|)
block|{
name|reset_termio
argument_list|()
expr_stmt|;
name|kill
argument_list|(
literal|0
argument_list|,
name|SIGTSTP
argument_list|)
expr_stmt|;
comment|/* process stops here */
name|set_termio
argument_list|()
expr_stmt|;
comment|/* print the prompt */
name|redraw_line
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VSUSP */
block|}
else|else
block|{
comment|/* do normal editing commands */
comment|/* some of these are also done above */
name|int
name|i
decl_stmt|;
switch|switch
condition|(
name|cur_char
condition|)
block|{
case|case
name|EOF
case|:
name|reset_termio
argument_list|()
expr_stmt|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|NULL
operator|)
return|;
case|case
literal|001
case|:
comment|/* ^A */
while|while
condition|(
name|cur_pos
operator|>
literal|0
condition|)
block|{
name|cur_pos
operator|-=
literal|1
expr_stmt|;
name|backspace
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
literal|002
case|:
comment|/* ^B */
if|if
condition|(
name|cur_pos
operator|>
literal|0
condition|)
block|{
name|cur_pos
operator|-=
literal|1
expr_stmt|;
name|backspace
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
literal|005
case|:
comment|/* ^E */
while|while
condition|(
name|cur_pos
operator|<
name|max_pos
condition|)
block|{
name|user_putc
argument_list|(
name|cur_line
index|[
name|cur_pos
index|]
argument_list|)
expr_stmt|;
name|cur_pos
operator|+=
literal|1
expr_stmt|;
block|}
break|break;
case|case
literal|006
case|:
comment|/* ^F */
if|if
condition|(
name|cur_pos
operator|<
name|max_pos
condition|)
block|{
name|user_putc
argument_list|(
name|cur_line
index|[
name|cur_pos
index|]
argument_list|)
expr_stmt|;
name|cur_pos
operator|+=
literal|1
expr_stmt|;
block|}
break|break;
case|case
literal|013
case|:
comment|/* ^K */
name|clear_eoline
argument_list|()
expr_stmt|;
name|max_pos
operator|=
name|cur_pos
expr_stmt|;
break|break;
case|case
literal|020
case|:
comment|/* ^P */
if|if
condition|(
name|history
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|cur_entry
operator|==
name|NULL
condition|)
block|{
name|cur_entry
operator|=
name|history
expr_stmt|;
name|clear_line
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
name|copy_line
argument_list|(
name|cur_entry
operator|->
name|line
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|cur_entry
operator|->
name|prev
operator|!=
name|NULL
condition|)
block|{
name|cur_entry
operator|=
name|cur_entry
operator|->
name|prev
expr_stmt|;
name|clear_line
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
name|copy_line
argument_list|(
name|cur_entry
operator|->
name|line
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
case|case
literal|016
case|:
comment|/* ^N */
if|if
condition|(
name|cur_entry
operator|!=
name|NULL
condition|)
block|{
name|cur_entry
operator|=
name|cur_entry
operator|->
name|next
expr_stmt|;
name|clear_line
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
if|if
condition|(
name|cur_entry
operator|!=
name|NULL
condition|)
name|copy_line
argument_list|(
name|cur_entry
operator|->
name|line
argument_list|)
expr_stmt|;
else|else
name|cur_pos
operator|=
name|max_pos
operator|=
literal|0
expr_stmt|;
block|}
break|break;
case|case
literal|014
case|:
comment|/* ^L */
case|case
literal|022
case|:
comment|/* ^R */
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
comment|/* go to a fresh line */
name|redraw_line
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0177
case|:
comment|/* DEL */
case|case
literal|010
case|:
comment|/* ^H */
if|if
condition|(
name|cur_pos
operator|>
literal|0
condition|)
block|{
name|cur_pos
operator|-=
literal|1
expr_stmt|;
name|backspace
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
name|cur_pos
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|cur_line
index|[
name|i
index|]
operator|=
name|cur_line
index|[
name|i
operator|+
literal|1
index|]
expr_stmt|;
name|max_pos
operator|-=
literal|1
expr_stmt|;
name|fix_line
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
literal|004
case|:
comment|/* ^D */
if|if
condition|(
name|max_pos
operator|==
literal|0
condition|)
block|{
name|reset_termio
argument_list|()
expr_stmt|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|NULL
operator|)
return|;
block|}
if|if
condition|(
name|cur_pos
operator|<
name|max_pos
condition|)
block|{
for|for
control|(
name|i
operator|=
name|cur_pos
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|cur_line
index|[
name|i
index|]
operator|=
name|cur_line
index|[
name|i
operator|+
literal|1
index|]
expr_stmt|;
name|max_pos
operator|-=
literal|1
expr_stmt|;
name|fix_line
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
literal|025
case|:
comment|/* ^U */
name|clear_line
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
break|break;
case|case
literal|027
case|:
comment|/* ^W */
while|while
condition|(
operator|(
name|cur_pos
operator|>
literal|0
operator|)
operator|&&
operator|(
name|cur_line
index|[
name|cur_pos
operator|-
literal|1
index|]
operator|==
name|SPACE
operator|)
condition|)
block|{
name|cur_pos
operator|-=
literal|1
expr_stmt|;
name|backspace
argument_list|()
expr_stmt|;
block|}
while|while
condition|(
operator|(
name|cur_pos
operator|>
literal|0
operator|)
operator|&&
operator|(
name|cur_line
index|[
name|cur_pos
operator|-
literal|1
index|]
operator|!=
name|SPACE
operator|)
condition|)
block|{
name|cur_pos
operator|-=
literal|1
expr_stmt|;
name|backspace
argument_list|()
expr_stmt|;
block|}
name|clear_eoline
argument_list|()
expr_stmt|;
name|max_pos
operator|=
name|cur_pos
expr_stmt|;
break|break;
case|case
literal|'\n'
case|:
comment|/* ^J */
case|case
literal|'\r'
case|:
comment|/* ^M */
name|cur_line
index|[
name|max_pos
operator|+
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|new_line
operator|=
operator|(
name|char
operator|*
operator|)
name|alloc
argument_list|(
call|(
name|unsigned
name|long
call|)
argument_list|(
name|strlen
argument_list|(
name|cur_line
argument_list|)
operator|+
literal|1
argument_list|)
argument_list|,
literal|"history"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|new_line
argument_list|,
name|cur_line
argument_list|)
expr_stmt|;
name|reset_termio
argument_list|()
expr_stmt|;
return|return
operator|(
name|new_line
operator|)
return|;
default|default:
break|break;
block|}
block|}
block|}
block|}
end_function

begin_comment
comment|/* fix up the line from cur_pos to max_pos */
end_comment

begin_comment
comment|/* do not need any terminal capabilities except backspace, */
end_comment

begin_comment
comment|/* and space overwrites a character */
end_comment

begin_function
specifier|static
name|void
name|fix_line
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|/* write tail of string */
for|for
control|(
name|i
operator|=
name|cur_pos
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|user_putc
argument_list|(
name|cur_line
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|/* write a space at the end of the line in case we deleted one */
name|user_putc
argument_list|(
name|SPACE
argument_list|)
expr_stmt|;
comment|/* backup to original position */
for|for
control|(
name|i
operator|=
name|max_pos
operator|+
literal|1
init|;
name|i
operator|>
name|cur_pos
condition|;
name|i
operator|--
control|)
name|backspace
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* redraw the entire line, putting the cursor where it belongs */
end_comment

begin_function
specifier|static
name|void
name|redraw_line
parameter_list|(
name|prompt
parameter_list|)
name|char
modifier|*
name|prompt
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|fputs
argument_list|(
name|prompt
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|user_puts
argument_list|(
name|cur_line
argument_list|)
expr_stmt|;
comment|/* put the cursor where it belongs */
for|for
control|(
name|i
operator|=
name|max_pos
init|;
name|i
operator|>
name|cur_pos
condition|;
name|i
operator|--
control|)
name|backspace
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* clear cur_line and the screen line */
end_comment

begin_function
specifier|static
name|void
name|clear_line
parameter_list|(
name|prompt
parameter_list|)
name|char
modifier|*
name|prompt
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|cur_line
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
name|cur_pos
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
name|backspace
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|putc
argument_list|(
name|SPACE
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\r'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|prompt
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|cur_pos
operator|=
literal|0
expr_stmt|;
name|max_pos
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* clear to end of line and the screen end of line */
end_comment

begin_function
specifier|static
name|void
name|clear_eoline
parameter_list|(
name|prompt
parameter_list|)
name|char
modifier|*
name|prompt
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
name|cur_pos
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|cur_line
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
name|cur_pos
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|putc
argument_list|(
name|SPACE
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|cur_pos
init|;
name|i
operator|<
name|max_pos
condition|;
name|i
operator|++
control|)
name|backspace
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* copy line to cur_line, draw it and set cur_pos and max_pos */
end_comment

begin_function
specifier|static
name|void
name|copy_line
parameter_list|(
name|line
parameter_list|)
name|char
modifier|*
name|line
decl_stmt|;
block|{
name|strcpy
argument_list|(
name|cur_line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|user_puts
argument_list|(
name|cur_line
argument_list|)
expr_stmt|;
name|cur_pos
operator|=
name|max_pos
operator|=
name|strlen
argument_list|(
name|cur_line
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* add line to the history */
end_comment

begin_function
name|void
name|add_history
parameter_list|(
name|line
parameter_list|)
name|char
modifier|*
name|line
decl_stmt|;
block|{
name|struct
name|hist
modifier|*
name|entry
decl_stmt|;
name|entry
operator|=
operator|(
expr|struct
name|hist
operator|*
operator|)
name|alloc
argument_list|(
operator|(
name|unsigned
name|long
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|hist
argument_list|)
argument_list|,
literal|"history"
argument_list|)
expr_stmt|;
name|entry
operator|->
name|line
operator|=
name|alloc
argument_list|(
call|(
name|unsigned
name|long
call|)
argument_list|(
name|strlen
argument_list|(
name|line
argument_list|)
operator|+
literal|1
argument_list|)
argument_list|,
literal|"history"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|entry
operator|->
name|line
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|entry
operator|->
name|prev
operator|=
name|history
expr_stmt|;
name|entry
operator|->
name|next
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|history
operator|!=
name|NULL
condition|)
block|{
name|history
operator|->
name|next
operator|=
name|entry
expr_stmt|;
block|}
name|history
operator|=
name|entry
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Convert ANSI arrow keys to control characters */
end_comment

begin_function
specifier|static
name|char
name|ansi_getc
parameter_list|()
block|{
name|char
name|c
init|=
name|getc
argument_list|(
name|stdin
argument_list|)
decl_stmt|;
if|if
condition|(
name|c
operator|==
literal|033
condition|)
block|{
name|c
operator|=
name|getc
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
comment|/* check for CSI */
if|if
condition|(
name|c
operator|==
literal|'['
condition|)
block|{
name|c
operator|=
name|getc
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
comment|/* get command character */
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'D'
case|:
comment|/* left arrow key */
name|c
operator|=
literal|002
expr_stmt|;
break|break;
case|case
literal|'C'
case|:
comment|/* right arrow key */
name|c
operator|=
literal|006
expr_stmt|;
break|break;
case|case
literal|'A'
case|:
comment|/* up arrow key */
name|c
operator|=
literal|020
expr_stmt|;
break|break;
case|case
literal|'B'
case|:
comment|/* down arrow key */
name|c
operator|=
literal|016
expr_stmt|;
break|break;
block|}
block|}
block|}
return|return
name|c
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|_Windows
argument_list|)
operator|||
name|defined
argument_list|(
name|DOS386
argument_list|)
end_if

begin_comment
comment|/* Convert Arrow keystrokes to Control characters: */
end_comment

begin_function
specifier|static
name|char
name|msdos_getch
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|DJGPP
name|char
name|c
decl_stmt|;
name|int
name|ch
init|=
name|getkey
argument_list|()
decl_stmt|;
name|c
operator|=
operator|(
name|ch
operator|&
literal|0xff00
operator|)
condition|?
literal|0
else|:
name|ch
operator|&
literal|0xff
expr_stmt|;
else|#
directive|else
name|char
name|c
init|=
name|getch
argument_list|()
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|c
operator|==
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|DJGPP
name|c
operator|=
name|ch
operator|&
literal|0xff
expr_stmt|;
else|#
directive|else
name|c
operator|=
name|getch
argument_list|()
expr_stmt|;
comment|/* Get the extended code. */
endif|#
directive|endif
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|75
case|:
comment|/* Left Arrow. */
name|c
operator|=
literal|002
expr_stmt|;
break|break;
case|case
literal|77
case|:
comment|/* Right Arrow. */
name|c
operator|=
literal|006
expr_stmt|;
break|break;
case|case
literal|72
case|:
comment|/* Up Arrow. */
name|c
operator|=
literal|020
expr_stmt|;
break|break;
case|case
literal|80
case|:
comment|/* Down Arrow. */
name|c
operator|=
literal|016
expr_stmt|;
break|break;
case|case
literal|115
case|:
comment|/* Ctl Left Arrow. */
case|case
literal|71
case|:
comment|/* Home */
name|c
operator|=
literal|001
expr_stmt|;
break|break;
case|case
literal|116
case|:
comment|/* Ctl Right Arrow. */
case|case
literal|79
case|:
comment|/* End */
name|c
operator|=
literal|005
expr_stmt|;
break|break;
case|case
literal|83
case|:
comment|/* Delete */
name|c
operator|=
literal|004
expr_stmt|;
break|break;
default|default:
name|c
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|033
condition|)
block|{
comment|/* ESC */
name|c
operator|=
literal|025
expr_stmt|;
block|}
return|return
name|c
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATARI
end_ifdef

begin_comment
comment|/* Convert Arrow keystrokes to Control characters: TOS version */
end_comment

begin_comment
comment|/* the volatile could be necessary to keep gcc from reordering     the two Super calls */
end_comment

begin_define
define|#
directive|define
name|CONTERM
value|((
comment|/*volatile*/
value|char *)0x484L)
end_define

begin_function
specifier|static
name|void
name|remove_conterm
parameter_list|()
block|{
name|void
modifier|*
name|ssp
init|=
operator|(
name|void
operator|*
operator|)
name|Super
argument_list|(
literal|0L
argument_list|)
decl_stmt|;
operator|*
name|CONTERM
operator|&=
operator|~
literal|0x8
expr_stmt|;
name|Super
argument_list|(
name|ssp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|char
name|tos_getch
parameter_list|()
block|{
name|long
name|rawkey
decl_stmt|;
name|char
name|c
decl_stmt|;
name|int
name|scan_code
decl_stmt|;
name|void
modifier|*
name|ssp
decl_stmt|;
specifier|static
name|int
name|init
init|=
literal|1
decl_stmt|;
specifier|static
name|int
name|in_help
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|in_help
condition|)
block|{
switch|switch
condition|(
name|in_help
condition|)
block|{
case|case
literal|1
case|:
case|case
literal|5
case|:
name|in_help
operator|++
expr_stmt|;
return|return
literal|'e'
return|;
case|case
literal|2
case|:
case|case
literal|6
case|:
name|in_help
operator|++
expr_stmt|;
return|return
literal|'l'
return|;
case|case
literal|3
case|:
case|case
literal|7
case|:
name|in_help
operator|++
expr_stmt|;
return|return
literal|'p'
return|;
case|case
literal|4
case|:
name|in_help
operator|=
literal|0
expr_stmt|;
return|return
literal|0x0d
return|;
case|case
literal|8
case|:
name|in_help
operator|=
literal|0
expr_stmt|;
return|return
literal|' '
return|;
block|}
block|}
if|if
condition|(
name|init
condition|)
block|{
name|ssp
operator|=
operator|(
name|void
operator|*
operator|)
name|Super
argument_list|(
literal|0L
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
operator|*
name|CONTERM
operator|&
literal|0x8
operator|)
condition|)
block|{
operator|*
name|CONTERM
operator||=
literal|0x8
expr_stmt|;
block|}
else|else
block|{
name|init
operator|=
literal|0
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|Super
argument_list|(
name|ssp
argument_list|)
expr_stmt|;
if|if
condition|(
name|init
condition|)
block|{
name|atexit
argument_list|(
name|remove_conterm
argument_list|)
expr_stmt|;
name|init
operator|=
literal|0
expr_stmt|;
block|}
block|}
operator|(
name|void
operator|)
name|Cursconf
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* cursor on */
name|rawkey
operator|=
name|Cnecin
argument_list|()
expr_stmt|;
name|c
operator|=
operator|(
name|char
operator|)
name|rawkey
expr_stmt|;
name|scan_code
operator|=
operator|(
call|(
name|int
call|)
argument_list|(
name|rawkey
operator|>>
literal|16
argument_list|)
operator|)
operator|&
literal|0xff
expr_stmt|;
comment|/* get the scancode */
if|if
condition|(
name|rawkey
operator|&
literal|0x07000000
condition|)
name|scan_code
operator||=
literal|0x80
expr_stmt|;
comment|/* shift or control */
switch|switch
condition|(
name|scan_code
condition|)
block|{
case|case
literal|0x62
case|:
comment|/* HELP		*/
if|if
condition|(
name|max_pos
operator|==
literal|0
condition|)
block|{
name|in_help
operator|=
literal|1
expr_stmt|;
return|return
literal|'h'
return|;
block|}
else|else
block|{
return|return
literal|0
return|;
block|}
case|case
literal|0xe2
case|:
comment|/* shift HELP	*/
if|if
condition|(
name|max_pos
operator|==
literal|0
condition|)
block|{
name|in_help
operator|=
literal|5
expr_stmt|;
return|return
literal|'h'
return|;
block|}
else|else
block|{
return|return
literal|0
return|;
block|}
case|case
literal|0x48
case|:
comment|/* Up Arrow */
return|return
literal|0x10
return|;
comment|/* ^P */
case|case
literal|0x50
case|:
comment|/* Down Arrow */
return|return
literal|0x0e
return|;
comment|/* ^N */
case|case
literal|0x4b
case|:
comment|/* Left Arrow */
return|return
literal|0x02
return|;
comment|/* ^B */
case|case
literal|0x4d
case|:
comment|/* Right Arrow */
return|return
literal|0x06
return|;
comment|/* ^F */
case|case
literal|0xcb
case|:
comment|/* Shift Left Arrow */
case|case
literal|0xf3
case|:
comment|/* Ctrl Left Arrow (TOS-bug ?) */
case|case
literal|0x47
case|:
comment|/* Home */
return|return
literal|0x01
return|;
comment|/* ^A */
case|case
literal|0xcd
case|:
comment|/* Shift Right Arrow */
case|case
literal|0xf4
case|:
comment|/* Ctrl Right Arrow (TOS-bug ?) */
case|case
literal|0xc7
case|:
comment|/* Shift Home */
case|case
literal|0xf7
case|:
comment|/* Crtl Home */
return|return
literal|0x05
return|;
comment|/* ^E */
case|case
literal|0x61
case|:
comment|/* Undo - redraw line */
return|return
literal|0x0c
return|;
comment|/* ^L */
default|default:
if|if
condition|(
name|c
operator|==
literal|0x1b
condition|)
return|return
literal|0x15
return|;
comment|/* ESC becomes ^U */
if|if
condition|(
name|c
operator|==
literal|0x7f
condition|)
return|return
literal|0x04
return|;
comment|/* Del becomes ^D */
break|break;
block|}
return|return
name|c
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATARI */
end_comment

begin_comment
comment|/* set termio so we can do our own input processing */
end_comment

begin_function
specifier|static
name|void
name|set_termio
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ATARI
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_Windows
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DOS386
argument_list|)
comment|/* set termio so we can do our own input processing */
comment|/* and save the old terminal modes so we can reset them later */
if|if
condition|(
name|term_set
operator|==
literal|0
condition|)
block|{
comment|/* 		 * Get terminal modes. 		 */
ifdef|#
directive|ifdef
name|SGTTY
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETP
argument_list|,
operator|&
name|orig_termio
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* SGTTY */
ifdef|#
directive|ifdef
name|TERMIOS
ifdef|#
directive|ifdef
name|TCGETS
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCGETS
argument_list|,
operator|&
name|orig_termio
argument_list|)
expr_stmt|;
else|#
directive|else
name|tcgetattr
argument_list|(
literal|0
argument_list|,
operator|&
name|orig_termio
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TCGETS */
else|#
directive|else
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|orig_termio
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TERMIOS */
endif|#
directive|endif
comment|/* SGTTY */
comment|/* 		 * Save terminal modes 		 */
name|rl_termio
operator|=
name|orig_termio
expr_stmt|;
comment|/* 		 * Set the modes to the way we want them 		 *  and save our input special characters 		 */
ifdef|#
directive|ifdef
name|SGTTY
name|rl_termio
operator|.
name|sg_flags
operator||=
name|CBREAK
expr_stmt|;
name|rl_termio
operator|.
name|sg_flags
operator|&=
operator|~
operator|(
name|ECHO
operator||
name|XTABS
operator|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETN
argument_list|,
operator|&
name|rl_termio
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGETC
argument_list|,
operator|&
name|s_tchars
argument_list|)
expr_stmt|;
name|term_chars
index|[
name|VERASE
index|]
operator|=
name|orig_termio
operator|.
name|sg_erase
expr_stmt|;
name|term_chars
index|[
name|VEOF
index|]
operator|=
name|s_tchars
operator|.
name|t_eofc
expr_stmt|;
name|term_chars
index|[
name|VKILL
index|]
operator|=
name|orig_termio
operator|.
name|sg_kill
expr_stmt|;
ifdef|#
directive|ifdef
name|TIOCGLTC
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCGLTC
argument_list|,
operator|&
name|s_ltchars
argument_list|)
expr_stmt|;
name|term_chars
index|[
name|VWERASE
index|]
operator|=
name|s_ltchars
operator|.
name|t_werasc
expr_stmt|;
name|term_chars
index|[
name|VREPRINT
index|]
operator|=
name|s_ltchars
operator|.
name|t_rprntc
expr_stmt|;
name|term_chars
index|[
name|VSUSP
index|]
operator|=
name|s_ltchars
operator|.
name|t_suspc
expr_stmt|;
comment|/* disable suspending process on ^Z */
name|s_ltchars
operator|.
name|t_suspc
operator|=
literal|0
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSLTC
argument_list|,
operator|&
name|s_ltchars
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TIOCGLTC */
else|#
directive|else
comment|/* SGTTY */
ifdef|#
directive|ifdef
name|IUCLC
name|rl_termio
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|BRKINT
operator||
name|PARMRK
operator||
name|INPCK
operator||
name|IUCLC
operator||
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
else|#
directive|else
name|rl_termio
operator|.
name|c_iflag
operator|&=
operator|~
operator|(
name|BRKINT
operator||
name|PARMRK
operator||
name|INPCK
operator||
name|IXON
operator||
name|IXOFF
operator|)
expr_stmt|;
endif|#
directive|endif
name|rl_termio
operator|.
name|c_iflag
operator||=
operator|(
name|IGNBRK
operator||
name|IGNPAR
operator|)
expr_stmt|;
comment|/* rl_termio.c_oflag&= ~(ONOCR); Costas Sphocleous Irvine,CA */
name|rl_termio
operator|.
name|c_lflag
operator|&=
operator|~
operator|(
name|ICANON
operator||
name|ECHO
operator||
name|ECHOE
operator||
name|ECHOK
operator||
name|ECHONL
operator||
name|NOFLSH
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|OS2
comment|/* for emx: remove default terminal processing */
name|rl_termio
operator|.
name|c_lflag
operator|&=
operator|~
operator|(
name|IDEFAULT
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* OS2 */
name|rl_termio
operator|.
name|c_lflag
operator||=
operator|(
name|ISIG
operator|)
expr_stmt|;
name|rl_termio
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
literal|1
expr_stmt|;
name|rl_termio
operator|.
name|c_cc
index|[
name|VTIME
index|]
operator|=
literal|0
expr_stmt|;
ifndef|#
directive|ifndef
name|VWERASE
define|#
directive|define
name|VWERASE
value|3
endif|#
directive|endif
name|term_chars
index|[
name|VERASE
index|]
operator|=
name|orig_termio
operator|.
name|c_cc
index|[
name|VERASE
index|]
expr_stmt|;
name|term_chars
index|[
name|VEOF
index|]
operator|=
name|orig_termio
operator|.
name|c_cc
index|[
name|VEOF
index|]
expr_stmt|;
name|term_chars
index|[
name|VKILL
index|]
operator|=
name|orig_termio
operator|.
name|c_cc
index|[
name|VKILL
index|]
expr_stmt|;
ifdef|#
directive|ifdef
name|TERMIOS
name|term_chars
index|[
name|VWERASE
index|]
operator|=
name|orig_termio
operator|.
name|c_cc
index|[
name|VWERASE
index|]
expr_stmt|;
ifdef|#
directive|ifdef
name|VREPRINT
name|term_chars
index|[
name|VREPRINT
index|]
operator|=
name|orig_termio
operator|.
name|c_cc
index|[
name|VREPRINT
index|]
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VRPRNT
name|term_chars
index|[
name|VRPRNT
index|]
operator|=
name|orig_termio
operator|.
name|c_cc
index|[
name|VRPRNT
index|]
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|term_chars
index|[
name|VSUSP
index|]
operator|=
name|orig_termio
operator|.
name|c_cc
index|[
name|VSUSP
index|]
expr_stmt|;
comment|/* disable suspending process on ^Z */
name|rl_termio
operator|.
name|c_cc
index|[
name|VSUSP
index|]
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* TERMIOS */
endif|#
directive|endif
comment|/* SGTTY */
comment|/* 		 * Set the new terminal modes. 		 */
ifdef|#
directive|ifdef
name|SGTTY
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSLTC
argument_list|,
operator|&
name|s_ltchars
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|TERMIOS
ifdef|#
directive|ifdef
name|TCSETSW
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETSW
argument_list|,
operator|&
name|rl_termio
argument_list|)
expr_stmt|;
else|#
directive|else
name|tcsetattr
argument_list|(
literal|0
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|rl_termio
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TCSETSW */
else|#
directive|else
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|rl_termio
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TERMIOS */
endif|#
directive|endif
comment|/* SGTTY */
name|term_set
operator|=
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* !MSDOS&& !ATARI&& !defined(_Windows) */
block|}
end_function

begin_function
name|void
name|reset_termio
parameter_list|()
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ATARI
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_Windows
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DOS386
argument_list|)
comment|/* reset saved terminal modes */
if|if
condition|(
name|term_set
operator|==
literal|1
condition|)
block|{
ifdef|#
directive|ifdef
name|SGTTY
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSETN
argument_list|,
operator|&
name|orig_termio
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|TIOCGLTC
comment|/* enable suspending process on ^Z */
name|s_ltchars
operator|.
name|t_suspc
operator|=
name|term_chars
index|[
name|VSUSP
index|]
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSLTC
argument_list|,
operator|&
name|s_ltchars
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TIOCGLTC */
else|#
directive|else
comment|/* SGTTY */
ifdef|#
directive|ifdef
name|TERMIOS
ifdef|#
directive|ifdef
name|TCSETSW
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETSW
argument_list|,
operator|&
name|orig_termio
argument_list|)
expr_stmt|;
else|#
directive|else
name|tcsetattr
argument_list|(
literal|0
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|orig_termio
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TCSETSW */
else|#
directive|else
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|orig_termio
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TERMIOS */
endif|#
directive|endif
comment|/* SGTTY */
name|term_set
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* !MSDOS&& !ATARI&& !_Windows */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READLINE */
end_comment

end_unit

