begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ttynam_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * Return name of tty port associated with lunit  *  * calling sequence:  *	character*19 string, ttynam  * 	string = ttynam (lunit)  * where:  *	the character string will be filled with the name of  *	the port, preceded with '/dev/', and blank padded.  *	(19 is the max length ever required)  */
end_comment

begin_include
include|#
directive|include
file|"../libI77/fiodefs.h"
end_include

begin_decl_stmt
specifier|extern
name|unit
name|units
index|[]
decl_stmt|;
end_decl_stmt

begin_macro
name|ttynam_
argument_list|(
argument|name
argument_list|,
argument|strlen
argument_list|,
argument|lu
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|strlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
modifier|*
name|lu
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|t
init|=
name|NULL
decl_stmt|,
modifier|*
name|ttyname
argument_list|()
decl_stmt|;
if|if
condition|(
literal|0
operator|<=
operator|*
name|lu
operator|&&
operator|*
name|lu
operator|<
name|MXUNIT
operator|&&
name|units
index|[
operator|*
name|lu
index|]
operator|.
name|ufd
condition|)
name|t
operator|=
name|ttyname
argument_list|(
name|fileno
argument_list|(
name|units
index|[
operator|*
name|lu
index|]
operator|.
name|ufd
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|==
name|NULL
condition|)
name|t
operator|=
literal|""
expr_stmt|;
name|b_char
argument_list|(
name|t
argument_list|,
name|name
argument_list|,
name|strlen
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

