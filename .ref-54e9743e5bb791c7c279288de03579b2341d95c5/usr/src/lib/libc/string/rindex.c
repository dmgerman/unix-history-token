begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)rindex.c	8.1 (Berkeley) %G%"
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
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_function
name|char
modifier|*
ifdef|#
directive|ifdef
name|STRRCHR
name|strrchr
parameter_list|(
name|p
parameter_list|,
name|ch
parameter_list|)
else|#
directive|else
function|rindex
parameter_list|(
name|p
parameter_list|,
name|ch
parameter_list|)
endif|#
directive|endif
specifier|register
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|ch
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|save
decl_stmt|;
for|for
control|(
name|save
operator|=
name|NULL
init|;
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
name|ch
condition|)
name|save
operator|=
operator|(
name|char
operator|*
operator|)
name|p
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|p
condition|)
return|return
operator|(
name|save
operator|)
return|;
block|}
comment|/* NOTREACHED */
block|}
end_function

end_unit

