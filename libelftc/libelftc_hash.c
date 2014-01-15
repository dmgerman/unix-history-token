begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013, Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * An implementation of the Fowler-Noll-Vo hash function.  *  * References:  * - http://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function  * - http://www.isthe.com/chongo/tech/comp/fnv/  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|"_libelftc.h"
end_include

begin_expr_stmt
name|ELFTC_VCSID
argument_list|(
literal|"$Id: libelftc_hash.c 2870 2013-01-07 10:38:43Z jkoshy $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Use the size of an 'int' to determine the magic numbers used by the  * hash function.  */
end_comment

begin_if
if|#
directive|if
name|INT_MAX
operator|==
literal|2147483647UL
end_if

begin_define
define|#
directive|define
name|FNV_PRIME
value|16777619UL
end_define

begin_define
define|#
directive|define
name|FNV_OFFSET
value|2166136261UL
end_define

begin_elif
elif|#
directive|elif
name|INT_MAX
operator|==
literal|18446744073709551615ULL
end_elif

begin_define
define|#
directive|define
name|FNV_PRIME
value|1099511628211ULL
end_define

begin_define
define|#
directive|define
name|FNV_OFFSET
value|14695981039346656037ULL
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|sizeof(int) is unknown.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|unsigned
name|int
name|libelftc_hash_string
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|char
name|c
decl_stmt|;
name|unsigned
name|int
name|hash
decl_stmt|;
for|for
control|(
name|hash
operator|=
name|FNV_OFFSET
init|;
operator|(
name|c
operator|=
operator|*
name|s
operator|)
operator|!=
literal|'\0'
condition|;
name|s
operator|++
control|)
block|{
name|hash
operator|^=
name|c
expr_stmt|;
name|hash
operator|*=
name|FNV_PRIME
expr_stmt|;
block|}
return|return
operator|(
name|hash
operator|)
return|;
block|}
end_function

end_unit

