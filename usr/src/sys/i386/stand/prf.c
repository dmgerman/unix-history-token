begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.redist.c%  *  *	@(#)prf.c	7.5 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_macro
name|putchar
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|c
operator|==
literal|'\n'
condition|)
name|sput
argument_list|(
literal|'\r'
argument_list|)
expr_stmt|;
name|sput
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|wait
argument_list|(
argument|n
argument_list|)
end_macro

begin_block
block|{
while|while
condition|(
name|n
operator|--
condition|)
empty_stmt|;
block|}
end_block

end_unit

