begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)strxfrm.c	8.1 (Berkeley) %G%"
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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Transform src, storing the result in dst, such that  * strcmp() on transformed strings returns what strcoll()  * on the original untransformed strings would return.  */
end_comment

begin_function
name|size_t
name|strxfrm
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
specifier|register
name|char
modifier|*
name|dst
decl_stmt|;
specifier|const
name|char
modifier|*
name|src
decl_stmt|;
name|size_t
name|n
decl_stmt|;
block|{
specifier|register
name|size_t
name|srclen
decl_stmt|,
name|copysize
decl_stmt|;
comment|/* 	 * Since locales are unimplemented, this is just a copy. 	 */
name|srclen
operator|=
name|strlen
argument_list|(
name|src
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
name|copysize
operator|=
name|srclen
operator|<
name|n
condition|?
name|srclen
else|:
name|n
operator|-
literal|1
expr_stmt|;
operator|(
name|void
operator|)
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|copysize
argument_list|)
expr_stmt|;
name|dst
index|[
name|copysize
index|]
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
name|srclen
operator|)
return|;
block|}
end_function

end_unit

