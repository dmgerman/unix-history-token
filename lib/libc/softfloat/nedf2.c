begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: nedf2.c,v 1.1 2000/06/06 08:15:07 bjh21 Exp $ */
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
name|flag
name|__nedf2
parameter_list|(
name|float64
parameter_list|,
name|float64
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|flag
name|__nedf2
parameter_list|(
name|float64
name|a
parameter_list|,
name|float64
name|b
parameter_list|)
block|{
comment|/* libgcc1.c says a != b */
return|return
operator|!
name|float64_eq
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

