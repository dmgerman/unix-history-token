begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)kdb_access.c	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Access data in kernel address space.  */
end_comment

begin_include
include|#
directive|include
file|"../kdb/defs.h"
end_include

begin_comment
comment|/*  * Primitives: put a value in a space, get a value from a space  * and get a word or byte not returning if an error occurred.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|kdbput
argument_list|(
argument|addr
argument_list|,
argument|space
argument_list|,
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|off_t
name|addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|value
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|(
name|void
operator|)
name|kdbpoke
argument_list|(
operator|(
name|caddr_t
operator|)
name|addr
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|u_int
name|kdbget
parameter_list|(
name|addr
parameter_list|,
name|space
parameter_list|)
name|off_t
name|addr
decl_stmt|;
block|{
return|return
operator|(
name|kdbpeek
argument_list|(
operator|(
name|caddr_t
operator|)
name|addr
argument_list|)
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|u_int
name|kdbchkget
parameter_list|(
name|addr
parameter_list|,
name|space
parameter_list|)
name|off_t
name|addr
decl_stmt|;
block|{
name|u_int
name|w
init|=
name|kdbget
argument_list|(
name|addr
argument_list|,
name|space
argument_list|)
decl_stmt|;
name|kdbchkerr
argument_list|()
expr_stmt|;
return|return
operator|(
name|w
operator|)
return|;
block|}
end_function

begin_function
name|u_int
name|kdbbchkget
parameter_list|(
name|addr
parameter_list|,
name|space
parameter_list|)
name|off_t
name|addr
decl_stmt|;
block|{
return|return
operator|(
name|byte
argument_list|(
name|kdbchkget
argument_list|(
name|addr
argument_list|,
name|space
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

