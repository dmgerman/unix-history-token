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
literal|"@(#)IN.c	1.3 (Berkeley) %G%"
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
name|IN
parameter_list|(
name|element
parameter_list|,
name|lower
parameter_list|,
name|upper
parameter_list|,
name|setptr
parameter_list|)
name|long
name|element
decl_stmt|;
comment|/* element to check */
name|long
name|lower
decl_stmt|;
comment|/* lowest element of set */
name|long
name|upper
decl_stmt|;
comment|/* upper - lower of set */
name|char
name|setptr
index|[]
decl_stmt|;
comment|/* pointer to set */
block|{
specifier|register
name|int
name|indx
decl_stmt|;
if|if
condition|(
operator|(
name|indx
operator|=
name|element
operator|-
name|lower
operator|)
operator|<
literal|0
operator|||
name|indx
operator|>
name|upper
condition|)
return|return
name|FALSE
return|;
if|if
condition|(
name|setptr
index|[
name|indx
operator|>>
name|LG2BITSBYTE
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|indx
operator|&
name|MSKBITSBYTE
operator|)
operator|)
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

