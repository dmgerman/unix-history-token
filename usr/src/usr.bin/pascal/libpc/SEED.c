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
literal|"@(#)SEED.c	1.6 (Berkeley) %G%"
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
name|long
name|SEED
parameter_list|(
name|value
parameter_list|)
name|long
name|value
decl_stmt|;
block|{
name|long
name|tmp
decl_stmt|;
name|tmp
operator|=
name|_seed
expr_stmt|;
name|_seed
operator|=
name|value
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function

end_unit

