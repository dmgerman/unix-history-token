begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)stklval.c	5.1 (Berkeley) 6/5/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"whoami.h"
end_include

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"opcode.h"
end_include

begin_include
include|#
directive|include
file|"objfmt.h"
end_include

begin_include
include|#
directive|include
file|"tree_ty.h"
end_include

begin_comment
comment|/*  * Lvalue computes the address  * of a qualified name and  * leaves it on the stack.  */
end_comment

begin_function
name|struct
name|nl
modifier|*
name|stklval
parameter_list|(
name|r
parameter_list|,
name|modflag
parameter_list|)
name|struct
name|tnode
modifier|*
name|r
decl_stmt|;
name|int
name|modflag
decl_stmt|;
block|{
comment|/* 	 * For the purposes of the interpreter stklval 	 * is the same as an lvalue. 	 */
return|return
operator|(
name|lvalue
argument_list|(
name|r
argument_list|,
name|modflag
argument_list|,
name|LREQ
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

