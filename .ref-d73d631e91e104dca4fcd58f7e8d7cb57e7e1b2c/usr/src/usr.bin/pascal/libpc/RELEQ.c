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
literal|"@(#)RELEQ.c	1.3 (Berkeley) %G%"
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
name|RELEQ
parameter_list|(
name|siz
parameter_list|,
name|str1
parameter_list|,
name|str2
parameter_list|)
name|long
name|siz
decl_stmt|;
specifier|register
name|char
modifier|*
name|str1
decl_stmt|;
specifier|register
name|char
modifier|*
name|str2
decl_stmt|;
block|{
specifier|register
name|int
name|size
init|=
name|siz
decl_stmt|;
while|while
condition|(
operator|*
name|str1
operator|++
operator|==
operator|*
name|str2
operator|++
operator|&&
operator|--
name|size
condition|)
comment|/* void */
empty_stmt|;
if|if
condition|(
name|size
operator|==
literal|0
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

