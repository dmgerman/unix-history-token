begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   * match.c  *   * Author: Tatu Ylonen<ylo@cs.hut.fi>  *   * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *   * Created: Thu Jun 22 01:17:50 1995 ylo  *   * Simple pattern matching, with '*' and '?' as wildcards.  *   */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: match.c,v 1.4 1999/11/24 19:53:48 markus Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"ssh.h"
end_include

begin_comment
comment|/*  * Returns true if the given string matches the pattern (which may contain ?  * and * as wildcards), and zero if it does not match.  */
end_comment

begin_function
name|int
name|match_pattern
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|)
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* If at end of pattern, accept if also at end of string. */
if|if
condition|(
operator|!
operator|*
name|pattern
condition|)
return|return
operator|!
operator|*
name|s
return|;
if|if
condition|(
operator|*
name|pattern
operator|==
literal|'*'
condition|)
block|{
comment|/* Skip the asterisk. */
name|pattern
operator|++
expr_stmt|;
comment|/* If at end of pattern, accept immediately. */
if|if
condition|(
operator|!
operator|*
name|pattern
condition|)
return|return
literal|1
return|;
comment|/* If next character in pattern is known, optimize. */
if|if
condition|(
operator|*
name|pattern
operator|!=
literal|'?'
operator|&&
operator|*
name|pattern
operator|!=
literal|'*'
condition|)
block|{
comment|/* 				 * Look instances of the next character in 				 * pattern, and try to match starting from 				 * those. 				 */
for|for
control|(
init|;
operator|*
name|s
condition|;
name|s
operator|++
control|)
if|if
condition|(
operator|*
name|s
operator|==
operator|*
name|pattern
operator|&&
name|match_pattern
argument_list|(
name|s
operator|+
literal|1
argument_list|,
name|pattern
operator|+
literal|1
argument_list|)
condition|)
return|return
literal|1
return|;
comment|/* Failed. */
return|return
literal|0
return|;
block|}
comment|/* 			 * Move ahead one character at a time and try to 			 * match at each position. 			 */
for|for
control|(
init|;
operator|*
name|s
condition|;
name|s
operator|++
control|)
if|if
condition|(
name|match_pattern
argument_list|(
name|s
argument_list|,
name|pattern
argument_list|)
condition|)
return|return
literal|1
return|;
comment|/* Failed. */
return|return
literal|0
return|;
block|}
comment|/* 		 * There must be at least one more character in the string. 		 * If we are at the end, fail. 		 */
if|if
condition|(
operator|!
operator|*
name|s
condition|)
return|return
literal|0
return|;
comment|/* Check if the next character of the string is acceptable. */
if|if
condition|(
operator|*
name|pattern
operator|!=
literal|'?'
operator|&&
operator|*
name|pattern
operator|!=
operator|*
name|s
condition|)
return|return
literal|0
return|;
comment|/* Move to the next character, both in string and in pattern. */
name|s
operator|++
expr_stmt|;
name|pattern
operator|++
expr_stmt|;
block|}
comment|/* NOTREACHED */
block|}
end_function

end_unit

