begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  *	$Id: db_output.c,v 1.15 1995/12/10 19:08:03 bde Exp $  */
end_comment

begin_comment
comment|/*  * 	Author: David B. Golub, Carnegie Mellon University  *	Date:	7/90  */
end_comment

begin_comment
comment|/*  * Printf and character output for debugger.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/cons.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_output.h>
end_include

begin_comment
comment|/*  *	Character output - tracks position in line.  *	To do this correctly, we should know how wide  *	the output device is - then we could zero  *	the line position when the output device wraps  *	around to the start of the next line.  *  *	Instead, we count the number of spaces printed  *	since the last printing character so that we  *	don't print trailing spaces.  This avoids most  *	of the wraparounds.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|db_output_position
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output column */
end_comment

begin_decl_stmt
specifier|static
name|int
name|db_last_non_space
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last non-space character */
end_comment

begin_decl_stmt
name|int
name|db_tab_stop_width
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how wide are tab stops? */
end_comment

begin_define
define|#
directive|define
name|NEXT_TAB
parameter_list|(
name|i
parameter_list|)
define|\
value|((((i) + db_tab_stop_width) / db_tab_stop_width) * db_tab_stop_width)
end_define

begin_decl_stmt
name|int
name|db_max_width
init|=
literal|80
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output line width */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|db_ksprintn
name|__P
argument_list|(
operator|(
name|u_long
name|ul
operator|,
name|int
name|base
operator|,
name|int
operator|*
name|lenp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|db_printf_guts
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Force pending whitespace.  */
end_comment

begin_function
name|void
name|db_force_whitespace
parameter_list|()
block|{
specifier|register
name|int
name|last_print
decl_stmt|,
name|next_tab
decl_stmt|;
name|last_print
operator|=
name|db_last_non_space
expr_stmt|;
while|while
condition|(
name|last_print
operator|<
name|db_output_position
condition|)
block|{
name|next_tab
operator|=
name|NEXT_TAB
argument_list|(
name|last_print
argument_list|)
expr_stmt|;
if|if
condition|(
name|next_tab
operator|<=
name|db_output_position
condition|)
block|{
while|while
condition|(
name|last_print
operator|<
name|next_tab
condition|)
block|{
comment|/* DON'T send a tab!!! */
name|cnputc
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|last_print
operator|++
expr_stmt|;
block|}
block|}
else|else
block|{
name|cnputc
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|last_print
operator|++
expr_stmt|;
block|}
block|}
name|db_last_non_space
operator|=
name|db_output_position
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Output character.  Buffer whitespace.  */
end_comment

begin_function
name|void
name|db_putchar
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
comment|/* character to output */
block|{
if|if
condition|(
name|c
operator|>
literal|' '
operator|&&
name|c
operator|<=
literal|'~'
condition|)
block|{
comment|/* 	     * Printing character. 	     * If we have spaces to print, print them first. 	     * Use tabs if possible. 	     */
name|db_force_whitespace
argument_list|()
expr_stmt|;
name|cnputc
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|db_output_position
operator|++
expr_stmt|;
name|db_last_non_space
operator|=
name|db_output_position
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
block|{
comment|/* Newline */
name|cnputc
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|db_output_position
operator|=
literal|0
expr_stmt|;
name|db_last_non_space
operator|=
literal|0
expr_stmt|;
name|db_check_interrupt
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|'\r'
condition|)
block|{
comment|/* Return */
name|cnputc
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|db_output_position
operator|=
literal|0
expr_stmt|;
name|db_last_non_space
operator|=
literal|0
expr_stmt|;
name|db_check_interrupt
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|'\t'
condition|)
block|{
comment|/* assume tabs every 8 positions */
name|db_output_position
operator|=
name|NEXT_TAB
argument_list|(
name|db_output_position
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|' '
condition|)
block|{
comment|/* space */
name|db_output_position
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
literal|'\007'
condition|)
block|{
comment|/* bell */
name|cnputc
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
comment|/* other characters are assumed non-printing */
block|}
end_function

begin_comment
comment|/*  * Return output position  */
end_comment

begin_function
name|int
name|db_print_position
parameter_list|()
block|{
return|return
operator|(
name|db_output_position
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Printing  */
end_comment

begin_function
name|void
name|db_printf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|listp
decl_stmt|;
name|va_start
argument_list|(
name|listp
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|kvprintf
argument_list|(
name|fmt
argument_list|,
name|db_putchar
argument_list|,
name|NULL
argument_list|,
name|db_radix
argument_list|,
name|listp
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|listp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * End line if too long.  */
end_comment

begin_function
name|void
name|db_end_line
parameter_list|()
block|{
if|if
condition|(
name|db_output_position
operator|>=
name|db_max_width
condition|)
name|db_printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Put a number (base<= 16) in a buffer in reverse order; return an  * optional length and a pointer to the NULL terminated (preceded?)  * buffer.  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|db_ksprintn
parameter_list|(
name|ul
parameter_list|,
name|base
parameter_list|,
name|lenp
parameter_list|)
specifier|register
name|u_long
name|ul
decl_stmt|;
specifier|register
name|int
name|base
decl_stmt|,
decl|*
name|lenp
decl_stmt|;
end_function

begin_block
block|{
comment|/* A long in base 8, plus NULL. */
specifier|static
name|char
name|buf
index|[
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|*
name|NBBY
operator|/
literal|3
operator|+
literal|2
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|buf
expr_stmt|;
do|do
block|{
operator|*
operator|++
name|p
operator|=
literal|"0123456789abcdef"
index|[
name|ul
operator|%
name|base
index|]
expr_stmt|;
block|}
do|while
condition|(
name|ul
operator|/=
name|base
condition|)
do|;
if|if
condition|(
name|lenp
condition|)
operator|*
name|lenp
operator|=
name|p
operator|-
name|buf
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_block

end_unit

