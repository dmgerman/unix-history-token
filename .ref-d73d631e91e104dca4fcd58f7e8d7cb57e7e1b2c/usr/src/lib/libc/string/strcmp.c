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
literal|"@(#)strcmp.c	5.4 (Berkeley) %G%"
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
comment|/*  * Compare strings.  */
end_comment

begin_function
name|int
name|strcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
specifier|register
specifier|const
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_block
block|{
while|while
condition|(
operator|*
name|s1
operator|==
operator|*
name|s2
operator|++
condition|)
if|if
condition|(
operator|*
name|s1
operator|++
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s1
operator|-
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
operator|--
name|s2
operator|)
return|;
block|}
end_block

end_unit

