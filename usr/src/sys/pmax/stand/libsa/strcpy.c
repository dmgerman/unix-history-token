begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)strcpy.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<pmax/stand/dec_prom.h>
end_include

begin_function
name|char
modifier|*
name|strcpy
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
name|char
modifier|*
name|s1
decl_stmt|,
decl|*
name|s2
decl_stmt|;
end_function

begin_block
block|{
return|return
operator|(
name|callv
operator|->
name|strcpy
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

