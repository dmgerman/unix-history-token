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
literal|"@(#)rand.c	5.3 (Berkeley) %G%"
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
file|<sys/stdc.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_decl_stmt
specifier|static
name|u_long
name|next
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|rand
parameter_list|()
block|{
return|return
operator|(
operator|(
name|next
operator|=
name|next
operator|*
literal|1103515245
operator|+
literal|12345
operator|)
operator|%
name|RAND_MAX
operator|)
return|;
block|}
end_function

begin_function
name|void
name|srand
parameter_list|(
name|seed
parameter_list|)
name|u_int
name|seed
decl_stmt|;
block|{
name|next
operator|=
name|seed
expr_stmt|;
block|}
end_function

end_unit

