begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Margo Seltzer.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)hash_log2.c	8.1 (Berkeley) %G%"
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

begin_function
name|u_int
name|__log2
parameter_list|(
name|num
parameter_list|)
name|u_int
name|num
decl_stmt|;
block|{
specifier|register
name|u_int
name|i
decl_stmt|,
name|limit
decl_stmt|;
name|limit
operator|=
literal|1
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|limit
operator|<
name|num
condition|;
name|limit
operator|=
name|limit
operator|<<
literal|1
operator|,
name|i
operator|++
control|)
empty_stmt|;
return|return
operator|(
name|i
operator|)
return|;
block|}
end_function

end_unit

