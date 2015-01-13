begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: explicit_bzero.c,v 1.3 2014/06/21 02:34:26 matthew Exp $ */
end_comment

begin_comment
comment|/*  * Public domain.  * Written by Matthew Dempsky.  */
end_comment

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
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

begin_function_decl
name|void
name|__explicit_bzero_hook
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

begin_function
name|void
name|__explicit_bzero_hook
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|explicit_bzero
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|memset
argument_list|(
name|buf
argument_list|,
literal|0
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|__explicit_bzero_hook
argument_list|(
name|buf
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

