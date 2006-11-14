begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: unordsf2.c,v 1.1 2003/05/06 08:58:20 rearnsha Exp $ */
end_comment

begin_comment
comment|/*  * Written by Richard Earnshaw, 2003.  This file is in the Public Domain.  */
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
name|__unordsf2
parameter_list|(
name|float32
parameter_list|,
name|float32
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|flag
name|__unordsf2
parameter_list|(
name|float32
name|a
parameter_list|,
name|float32
name|b
parameter_list|)
block|{
comment|/* 	 * The comparison is unordered if either input is a NaN. 	 * Test for this by comparing each operand with itself. 	 * We must perform both comparisons to correctly check for 	 * signalling NaNs. 	 */
return|return
literal|1
operator|^
operator|(
name|float32_eq
argument_list|(
name|a
argument_list|,
name|a
argument_list|)
operator|&
name|float32_eq
argument_list|(
name|b
argument_list|,
name|b
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

