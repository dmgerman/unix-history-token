begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: negsf2.c,v 1.1 2000/06/06 08:15:07 bjh21 Exp $ */
end_comment

begin_comment
comment|/*  * Written by Ben Harris, 2000.  This file is in the Public Domain.  */
end_comment

begin_include
include|#
directive|include
file|"softfloat-for-gcc.h"
end_include

begin_include
include|#
directive|include
file|"milieu.h"
end_include

begin_include
include|#
directive|include
file|"softfloat.h"
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|float32
name|__negsf2
parameter_list|(
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|float32
name|__negsf2
parameter_list|(
name|float32
name|a
parameter_list|)
block|{
comment|/* libgcc1.c says INTIFY(-a) */
return|return
name|a
operator|^
literal|0x80000000
return|;
block|}
end_function

end_unit

