begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)ftruncate.c	8.1 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_comment
comment|/*  * This function provides 64-bit offset padding that  * is not supplied by GCC 1.X but is supplied by GCC 2.X.  */
end_comment

begin_function
name|int
name|ftruncate
parameter_list|(
name|fd
parameter_list|,
name|length
parameter_list|)
name|int
name|fd
decl_stmt|;
name|off_t
name|length
decl_stmt|;
block|{
return|return
operator|(
name|__indir
argument_list|(
operator|(
name|quad_t
operator|)
name|SYS_ftruncate
argument_list|,
name|fd
argument_list|,
literal|0
argument_list|,
name|length
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

