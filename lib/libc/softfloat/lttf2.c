begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: lttf2.c,v 1.1 2011/01/17 10:08:35 matt Exp $ */
end_comment

begin_comment
comment|/*  * Written by Matt Thomas, 2011.  This file is in the Public Domain.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|FLOAT128
end_ifdef

begin_function_decl
name|flag
name|__lttf2
parameter_list|(
name|float128
parameter_list|,
name|float128
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|flag
name|__lttf2
parameter_list|(
name|float128
name|a
parameter_list|,
name|float128
name|b
parameter_list|)
block|{
comment|/* libgcc1.c says -(a< b) */
return|return
operator|-
name|float128_lt
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FLOAT128 */
end_comment

end_unit

