begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)stklval.c 1.1 8/27/80"
decl_stmt|;
end_decl_stmt

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
name|int
modifier|*
name|r
decl_stmt|,
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

