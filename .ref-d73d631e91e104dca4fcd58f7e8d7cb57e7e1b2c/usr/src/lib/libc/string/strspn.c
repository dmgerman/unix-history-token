begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)strspn.c	5.7 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/stdc.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Span the string s2 (skip characters that are in s2).  */
end_comment

begin_function
name|size_t
name|strspn
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
specifier|const
name|char
modifier|*
name|s1
decl_stmt|;
specifier|register
specifier|const
name|char
modifier|*
name|s2
decl_stmt|;
block|{
specifier|register
specifier|const
name|char
modifier|*
name|p
init|=
name|s1
decl_stmt|,
modifier|*
name|spanp
decl_stmt|;
specifier|register
name|char
name|c
decl_stmt|,
name|sc
decl_stmt|;
comment|/* 	 * Skip any characters in s2, excluding the terminating \0. 	 */
name|cont
label|:
name|c
operator|=
operator|*
name|p
operator|++
expr_stmt|;
for|for
control|(
name|spanp
operator|=
name|s2
init|;
operator|(
name|sc
operator|=
operator|*
name|spanp
operator|++
operator|)
operator|!=
literal|0
condition|;
control|)
if|if
condition|(
name|sc
operator|==
name|c
condition|)
goto|goto
name|cont
goto|;
return|return
operator|(
name|p
operator|-
literal|1
operator|-
name|s1
operator|)
return|;
block|}
end_function

end_unit

