begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  *  *	@(#)fvwrite.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * I/O descriptors for __sfvwrite().  */
end_comment

begin_struct
struct|struct
name|__siov
block|{
name|void
modifier|*
name|iov_base
decl_stmt|;
name|size_t
name|iov_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|__suio
block|{
name|struct
name|__siov
modifier|*
name|uio_iov
decl_stmt|;
name|int
name|uio_iovcnt
decl_stmt|;
name|int
name|uio_resid
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
specifier|extern
name|int
name|__sfvwrite
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|__suio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|__sfvwrite
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

