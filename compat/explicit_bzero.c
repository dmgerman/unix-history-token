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
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

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
name|ATTR_UNUSED
parameter_list|(
name|buf
parameter_list|)
parameter_list|,
name|size_t
name|ATTR_UNUSED
parameter_list|(
name|len
parameter_list|)
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
ifdef|#
directive|ifdef
name|UB_ON_WINDOWS
name|SecureZeroMemory
argument_list|(
name|buf
argument_list|,
name|len
argument_list|)
expr_stmt|;
endif|#
directive|endif
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

