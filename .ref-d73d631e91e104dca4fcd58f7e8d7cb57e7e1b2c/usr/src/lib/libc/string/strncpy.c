begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)strncpy.c	5.5 (Berkeley) %G%"
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdc.h>
end_include

begin_comment
comment|/*  * Copy src to dst, truncating or null-padding to always copy n bytes.  * Return dst.  */
end_comment

begin_function
name|char
modifier|*
name|strncpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|dst
decl_stmt|;
specifier|const
name|char
modifier|*
name|src
decl_stmt|;
specifier|register
name|size_t
name|n
decl_stmt|;
block|{
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
specifier|register
name|char
modifier|*
name|d
init|=
name|dst
decl_stmt|;
specifier|register
specifier|const
name|char
modifier|*
name|s
init|=
name|src
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|(
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* NUL pad the remaining n-1 bytes */
while|while
condition|(
operator|--
name|n
operator|!=
literal|0
condition|)
operator|*
name|d
operator|++
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
do|while
condition|(
operator|--
name|n
operator|!=
literal|0
condition|)
do|;
block|}
return|return
operator|(
name|dst
operator|)
return|;
block|}
end_function

end_unit

