begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)convert.c	1.1 */
end_comment

begin_comment
comment|/*  *   CONVERT.C  *  *  *   LTOU (STR1, STR2)  *        Copy STR1 to STR2, changing lower case to upper case.  *  *   UTOL (STR1, STR2)  *        Copy STR1 to STR2, changing upper case to lower case.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KSHELL
end_ifdef

begin_include
include|#
directive|include
file|"shtype.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KSHELL */
end_comment

begin_comment
comment|/*   *   LTOU (STR1, STR2)  *        char *STR1;  *        char *STR2;  *  *   Copy STR1 to STR2, converting uppercase alphabetics to  *   lowercase.  STR2 should be big enough to hold STR1.  *  *   STR1 and STR2 may point to the same place.  *  */
end_comment

begin_function
name|void
name|ltou
parameter_list|(
name|str1
parameter_list|,
name|str2
parameter_list|)
name|char
modifier|*
name|str1
decl_stmt|,
decl|*
name|str2
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|d
decl_stmt|;
for|for
control|(
name|s
operator|=
name|str1
operator|,
name|d
operator|=
name|str2
init|;
operator|*
name|s
condition|;
name|s
operator|++
operator|,
name|d
operator|++
control|)
block|{
if|if
condition|(
name|islower
argument_list|(
operator|*
name|s
argument_list|)
condition|)
operator|*
name|d
operator|=
name|toupper
argument_list|(
operator|*
name|s
argument_list|)
expr_stmt|;
else|else
operator|*
name|d
operator|=
operator|*
name|s
expr_stmt|;
block|}
operator|*
name|d
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  *   UTOL (STR1, STR2)  *        char *STR1;  *        char *STR2;  *  *   Copy STR1 to STR2, converting lowercase alphabetics to  *   uppercase.  STR2 should be big enough to hold STR1.  *  *   STR1 and STR2 may point to the same place.  *  */
end_comment

begin_function
name|void
name|utol
parameter_list|(
name|str1
parameter_list|,
name|str2
parameter_list|)
name|char
modifier|*
name|str1
decl_stmt|,
decl|*
name|str2
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|d
decl_stmt|;
for|for
control|(
name|s
operator|=
name|str1
operator|,
name|d
operator|=
name|str2
init|;
operator|*
name|s
condition|;
name|s
operator|++
operator|,
name|d
operator|++
control|)
block|{
if|if
condition|(
name|isupper
argument_list|(
operator|*
name|s
argument_list|)
condition|)
operator|*
name|d
operator|=
name|tolower
argument_list|(
operator|*
name|s
argument_list|)
expr_stmt|;
else|else
operator|*
name|d
operator|=
operator|*
name|s
expr_stmt|;
block|}
operator|*
name|d
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

