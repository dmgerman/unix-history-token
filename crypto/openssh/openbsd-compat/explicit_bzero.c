begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OPENBSD ORIGINAL: lib/libc/string/explicit_bzero.c */
end_comment

begin_comment
comment|/*	$OpenBSD: explicit_bzero.c,v 1.1 2014/01/22 21:06:45 tedu Exp $ */
end_comment

begin_comment
comment|/*  * Public domain.  * Written by Ted Unangst  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXPLICIT_BZERO
end_ifndef

begin_comment
comment|/*  * explicit_bzero - don't let the compiler optimize away bzero  */
end_comment

begin_function
name|void
name|explicit_bzero
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
name|bzero
argument_list|(
name|p
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

