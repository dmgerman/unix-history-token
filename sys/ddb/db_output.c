begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
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
file|<sys/cons.h>
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
name|db_expr_t
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
name|db_expr_t
name|db_max_width
init|=
literal|79
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output line width */
end_comment

begin_function_decl
specifier|static
name|void
name|db_putchar
parameter_list|(
name|int
name|c
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

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
specifier|static
name|void
name|db_putchar
parameter_list|(
name|c
parameter_list|,
name|arg
parameter_list|)
name|int
name|c
decl_stmt|;
comment|/* character to output */
name|void
modifier|*
name|arg
decl_stmt|;
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
if|#
directive|if
name|__STDC__
name|db_printf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|db_printf
parameter_list|(
name|fmt
parameter_list|)
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
endif|#
directive|endif
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

begin_decl_stmt
name|int
name|db_indent
decl_stmt|;
end_decl_stmt

begin_function
name|void
if|#
directive|if
name|__STDC__
name|db_iprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|db_iprintf
parameter_list|(
name|fmt
parameter_list|)
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
endif|#
directive|endif
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|va_list
name|listp
decl_stmt|;
for|for
control|(
name|i
operator|=
name|db_indent
init|;
name|i
operator|>=
literal|8
condition|;
name|i
operator|-=
literal|8
control|)
name|db_printf
argument_list|(
literal|"\t"
argument_list|)
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
name|db_printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
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

end_unit

