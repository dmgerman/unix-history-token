begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)getenv.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<pmax/stand/dec_prom.h>
end_include

begin_function
name|char
modifier|*
name|getenv
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
return|return
operator|(
name|callv
operator|->
name|getenv
argument_list|(
name|s
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

