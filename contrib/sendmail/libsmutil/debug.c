begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: debug.c,v 8.2 1999/07/26 04:04:09 gshapiro Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_include
include|#
directive|include
file|<sendmail.h>
end_include

begin_decl_stmt
name|u_char
name|tTdvect
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trace vector */
end_comment

begin_if
if|#
directive|if
name|_FFR_DPRINTF_
end_if

begin_function
name|void
comment|/*VARARGS1*/
ifdef|#
directive|ifdef
name|__STDC__
name|dprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
comment|/* __STDC__ */
function|dprintf
parameter_list|(
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
comment|/* __STDC__ */
block|{
name|VA_LOCAL_DECL
expr_stmt|;
operator|(
name|void
operator|)
name|vfprintf
argument_list|(
name|stdout
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|dflush
parameter_list|()
block|{
return|return
name|fflush
argument_list|(
name|stdout
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_DPRINTF_ */
end_comment

end_unit

