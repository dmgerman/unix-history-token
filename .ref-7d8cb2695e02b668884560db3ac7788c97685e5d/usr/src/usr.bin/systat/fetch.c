begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)fetch.c	5.7 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"systat.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_function
name|int
name|kvm_ckread
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|)
name|void
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|kvm_read
argument_list|(
name|kd
argument_list|,
operator|(
name|u_long
operator|)
name|a
argument_list|,
name|b
argument_list|,
name|l
argument_list|)
operator|!=
name|l
condition|)
block|{
if|if
condition|(
name|verbose
condition|)
name|error
argument_list|(
literal|"error reading kmem at %x\n"
argument_list|,
name|a
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

