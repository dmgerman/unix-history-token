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
literal|"@(#)setbuffer.c	5.6 (Berkeley) %G%"
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
file|<stdio.h>
end_include

begin_function
name|void
name|setbuffer
parameter_list|(
name|fp
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|size
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|setvbuf
argument_list|(
name|fp
argument_list|,
name|buf
argument_list|,
name|buf
condition|?
name|_IOFBF
else|:
name|_IONBF
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * set line buffering  */
end_comment

begin_function
name|int
name|setlinebuf
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
return|return
operator|(
name|setvbuf
argument_list|(
name|fp
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|_IOLBF
argument_list|,
operator|(
name|size_t
operator|)
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

