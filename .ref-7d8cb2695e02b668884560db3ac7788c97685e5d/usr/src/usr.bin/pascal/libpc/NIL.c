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
literal|"@(#)NIL.c	1.5 (Berkeley) %G%"
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

begin_decl_stmt
name|char
name|ENIL
index|[]
init|=
literal|"Pointer value out of legal range\n"
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|NIL
parameter_list|(
name|ptr
parameter_list|)
name|char
modifier|*
name|ptr
decl_stmt|;
comment|/* pointer to struct */
block|{
if|if
condition|(
name|ptr
operator|>
name|_maxptr
operator|||
name|ptr
operator|<
name|_minptr
condition|)
block|{
name|ERROR
argument_list|(
name|ENIL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
return|return
name|ptr
return|;
block|}
end_function

end_unit

