begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)strcmp.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<pmax/stand/dec_prom.h>
end_include

begin_macro
name|strcmp
argument_list|(
argument|s1
argument_list|,
argument|s2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s1
decl_stmt|,
modifier|*
name|s2
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|callv
operator|->
name|strcmp
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

