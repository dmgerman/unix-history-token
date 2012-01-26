begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: gtxf2.c,v 1.2 2004/09/27 10:16:24 he Exp $ */
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

begin_ifdef
ifdef|#
directive|ifdef
name|FLOATX80
end_ifdef

begin_function_decl
name|flag
name|__gtxf2
parameter_list|(
name|floatx80
parameter_list|,
name|floatx80
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|flag
name|__gtxf2
parameter_list|(
name|floatx80
name|a
parameter_list|,
name|floatx80
name|b
parameter_list|)
block|{
comment|/* libgcc1.c says a> b */
return|return
name|floatx80_lt
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FLOATX80 */
end_comment

end_unit

