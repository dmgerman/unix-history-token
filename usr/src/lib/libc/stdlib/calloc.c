begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)calloc.c	5.5 (Berkeley) %G%"
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
file|<stdlib.h>
end_include

begin_function
name|void
modifier|*
name|calloc
parameter_list|(
name|num
parameter_list|,
name|size
parameter_list|)
name|size_t
name|num
decl_stmt|;
specifier|register
name|size_t
name|size
decl_stmt|;
block|{
specifier|register
name|void
modifier|*
name|p
decl_stmt|;
name|size
operator|*=
name|num
expr_stmt|;
if|if
condition|(
name|p
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
condition|)
name|bzero
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_function
name|void
name|cfree
parameter_list|(
name|p
parameter_list|,
name|num
parameter_list|,
name|size
parameter_list|)
name|void
modifier|*
name|p
decl_stmt|;
name|size_t
name|num
decl_stmt|,
name|size
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

