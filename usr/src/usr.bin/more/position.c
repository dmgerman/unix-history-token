begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Mark Nudleman and the University of California, Berkeley.  The  * name of Mark Nudleman or the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)position.c	5.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Routines dealing with the "position" table.  * This is a table which tells the position (in the input file) of the  * first char on each currently displayed line.  *  * {{ The position table is scrolled by moving all the entries.  *    Would be better to have a circular table   *    and just change a couple of pointers. }}  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<less.h>
end_include

begin_define
define|#
directive|define
name|NPOS
value|100
end_define

begin_comment
comment|/* {{ sc_height must be less than NPOS }} */
end_comment

begin_decl_stmt
specifier|static
name|off_t
name|table
index|[
name|NPOS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The position table */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sc_height
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return the starting file position of a line displayed on the screen.  * The line may be specified as a line number relative to the top  * of the screen, but is usually one of these special cases:  *	the top (first) line on the screen  *	the second line on the screen  *	the bottom line on the screen  *	the line after the bottom line on the screen  */
end_comment

begin_function
name|off_t
name|position
parameter_list|(
name|where
parameter_list|)
name|int
name|where
decl_stmt|;
block|{
switch|switch
condition|(
name|where
condition|)
block|{
case|case
name|BOTTOM
case|:
name|where
operator|=
name|sc_height
operator|-
literal|2
expr_stmt|;
break|break;
case|case
name|BOTTOM_PLUS_ONE
case|:
name|where
operator|=
name|sc_height
operator|-
literal|1
expr_stmt|;
break|break;
case|case
name|MIDDLE
case|:
name|where
operator|=
name|sc_height
operator|/
literal|2
expr_stmt|;
block|}
return|return
operator|(
name|table
index|[
name|where
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Add a new file position to the bottom of the position table.  */
end_comment

begin_macro
name|add_forw_pos
argument_list|(
argument|pos
argument_list|)
end_macro

begin_decl_stmt
name|off_t
name|pos
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* 	 * Scroll the position table up. 	 */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|sc_height
condition|;
name|i
operator|++
control|)
name|table
index|[
name|i
operator|-
literal|1
index|]
operator|=
name|table
index|[
name|i
index|]
expr_stmt|;
name|table
index|[
name|sc_height
operator|-
literal|1
index|]
operator|=
name|pos
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Add a new file position to the top of the position table.  */
end_comment

begin_macro
name|add_back_pos
argument_list|(
argument|pos
argument_list|)
end_macro

begin_decl_stmt
name|off_t
name|pos
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
comment|/* 	 * Scroll the position table down. 	 */
for|for
control|(
name|i
operator|=
name|sc_height
operator|-
literal|1
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
name|table
index|[
name|i
index|]
operator|=
name|table
index|[
name|i
operator|-
literal|1
index|]
expr_stmt|;
name|table
index|[
literal|0
index|]
operator|=
name|pos
expr_stmt|;
block|}
end_block

begin_macro
name|copytable
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
for|for
control|(
name|a
operator|=
literal|0
init|;
name|a
operator|<
name|sc_height
operator|&&
name|table
index|[
name|a
index|]
operator|==
name|NULL_POSITION
condition|;
name|a
operator|++
control|)
empty_stmt|;
for|for
control|(
name|b
operator|=
literal|0
init|;
name|a
operator|<
name|sc_height
condition|;
name|a
operator|++
operator|,
name|b
operator|++
control|)
block|{
name|table
index|[
name|b
index|]
operator|=
name|table
index|[
name|a
index|]
expr_stmt|;
name|table
index|[
name|a
index|]
operator|=
name|NULL_POSITION
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * Initialize the position table, done whenever we clear the screen.  */
end_comment

begin_macro
name|pos_clear
argument_list|()
end_macro

begin_block
block|{
specifier|register
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
name|sc_height
condition|;
name|i
operator|++
control|)
name|table
index|[
name|i
index|]
operator|=
name|NULL_POSITION
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * See if the byte at a specified position is currently on the screen.  * Check the position table to see if the position falls within its range.  * Return the position table entry if found, -1 if not.  */
end_comment

begin_macro
name|onscreen
argument_list|(
argument|pos
argument_list|)
end_macro

begin_decl_stmt
name|off_t
name|pos
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
if|if
condition|(
name|pos
operator|<
name|table
index|[
literal|0
index|]
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|sc_height
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|pos
operator|<
name|table
index|[
name|i
index|]
condition|)
return|return
operator|(
name|i
operator|-
literal|1
operator|)
return|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

end_unit

