begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)TEOF.c	1.5 (Berkeley) %G%"
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
file|"h00vars.h"
end_include

begin_function
name|bool
name|TEOF
parameter_list|(
name|filep
parameter_list|)
specifier|register
name|struct
name|iorec
modifier|*
name|filep
decl_stmt|;
block|{
if|if
condition|(
name|filep
operator|->
name|fblk
operator|>=
name|MAXFILES
operator|||
name|_actfile
index|[
name|filep
operator|->
name|fblk
index|]
operator|!=
name|filep
operator|||
operator|(
name|filep
operator|->
name|funit
operator|&
name|FDEF
operator|)
condition|)
block|{
name|ERROR
argument_list|(
literal|"Reference to an inactive file\n"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|filep
operator|->
name|funit
operator|&
operator|(
name|EOFF
operator||
name|FWRITE
operator|)
condition|)
return|return
name|TRUE
return|;
name|IOSYNC
argument_list|(
name|filep
argument_list|)
expr_stmt|;
if|if
condition|(
name|filep
operator|->
name|funit
operator|&
name|EOFF
condition|)
return|return
name|TRUE
return|;
return|return
name|FALSE
return|;
block|}
end_function

end_unit

