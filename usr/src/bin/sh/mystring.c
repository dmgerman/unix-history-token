begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)mystring.c	5.1 (Berkeley) %G%"
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
comment|/*  * String functions.  *  *	equal(s1, s2)		Return true if strings are equal.  *	scopy(from, to)		Copy a string.  *	scopyn(from, to, n)	Like scopy, but checks for overflow.  *	strchr(s, c)		Find first occurance of c in s.  *	bcopy(from, to, n)	Copy a block of memory.  *	number(s)		Convert a string of digits to an integer.  *	is_number(s)		Return true if s is a string of digits.  */
end_comment

begin_include
include|#
directive|include
file|"shell.h"
end_include

begin_include
include|#
directive|include
file|"syntax.h"
end_include

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"mystring.h"
end_include

begin_decl_stmt
name|char
name|nullstr
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zero length string */
end_comment

begin_comment
comment|/*  * scopyn - copy a string from "from" to "to", truncating the string  *		if necessary.  "To" is always nul terminated, even if  *		truncation is performed.  "Size" is the size of "to".  */
end_comment

begin_function
name|void
name|scopyn
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|size
parameter_list|)
specifier|register
name|char
specifier|const
modifier|*
name|from
decl_stmt|;
specifier|register
name|char
modifier|*
name|to
decl_stmt|;
specifier|register
name|int
name|size
decl_stmt|;
block|{
while|while
condition|(
operator|--
name|size
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|to
operator|++
operator|=
operator|*
name|from
operator|++
operator|)
operator|==
literal|'\0'
condition|)
return|return;
block|}
operator|*
name|to
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * strchr - find first occurrence of a character in a string.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS5
end_ifndef

begin_function
name|char
modifier|*
name|mystrchr
parameter_list|(
name|s
parameter_list|,
name|charwanted
parameter_list|)
name|char
specifier|const
modifier|*
name|s
decl_stmt|;
specifier|register
name|char
name|charwanted
decl_stmt|;
block|{
specifier|register
name|char
specifier|const
modifier|*
name|scan
decl_stmt|;
comment|/* 	 * The odd placement of the two tests is so NUL is findable. 	 */
for|for
control|(
name|scan
operator|=
name|s
init|;
operator|*
name|scan
operator|!=
name|charwanted
condition|;
control|)
comment|/* ++ moved down for opt. */
if|if
condition|(
operator|*
name|scan
operator|++
operator|==
literal|'\0'
condition|)
return|return
name|NULL
return|;
return|return
operator|(
name|char
operator|*
operator|)
name|scan
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * bcopy - copy bytes  *  * This routine was derived from code by Henry Spencer.  */
end_comment

begin_function
name|void
name|mybcopy
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|length
parameter_list|)
name|pointer
name|dst
decl_stmt|;
specifier|const
name|pointer
name|src
decl_stmt|;
specifier|register
name|int
name|length
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|d
init|=
name|dst
decl_stmt|;
specifier|register
name|char
modifier|*
name|s
init|=
name|src
decl_stmt|;
while|while
condition|(
operator|--
name|length
operator|>=
literal|0
condition|)
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * prefix -- see if pfx is a prefix of string.  */
end_comment

begin_function
name|int
name|prefix
parameter_list|(
name|pfx
parameter_list|,
name|string
parameter_list|)
specifier|register
name|char
specifier|const
modifier|*
name|pfx
decl_stmt|;
specifier|register
name|char
specifier|const
modifier|*
name|string
decl_stmt|;
block|{
while|while
condition|(
operator|*
name|pfx
condition|)
block|{
if|if
condition|(
operator|*
name|pfx
operator|++
operator|!=
operator|*
name|string
operator|++
condition|)
return|return
literal|0
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Convert a string of digits to an integer, printing an error message on  * failure.  */
end_comment

begin_function
name|int
name|number
parameter_list|(
name|s
parameter_list|)
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|is_number
argument_list|(
name|s
argument_list|)
condition|)
name|error2
argument_list|(
literal|"Illegal number"
argument_list|,
operator|(
name|char
operator|*
operator|)
name|s
argument_list|)
expr_stmt|;
return|return
name|atoi
argument_list|(
name|s
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Check for a valid number.  This should be elsewhere.  */
end_comment

begin_function
name|int
name|is_number
parameter_list|(
name|p
parameter_list|)
specifier|register
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
block|{
do|do
block|{
if|if
condition|(
operator|!
name|is_digit
argument_list|(
operator|*
name|p
argument_list|)
condition|)
return|return
literal|0
return|;
block|}
do|while
condition|(
operator|*
operator|++
name|p
operator|!=
literal|'\0'
condition|)
do|;
return|return
literal|1
return|;
block|}
end_function

end_unit

