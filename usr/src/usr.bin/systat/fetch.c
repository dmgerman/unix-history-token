begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)fetch.c	5.5 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"systat.h"
end_include

begin_macro
name|kvm_ckread
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|l
argument_list|)
end_macro

begin_decl_stmt
name|void
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|int
name|verbose
decl_stmt|;
if|if
condition|(
name|kvm_read
argument_list|(
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

