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

begin_comment
comment|/*  * explicit_bzero - don't let the compiler optimize away bzero  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EXPLICIT_BZERO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MEMSET_S
end_ifdef

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
operator|(
name|void
operator|)
name|memset_s
argument_list|(
name|p
argument_list|,
name|n
argument_list|,
literal|0
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_MEMSET_S */
end_comment

begin_comment
comment|/*  * Indirect bzero through a volatile pointer to hopefully avoid  * dead-store optimisation eliminating the call.  */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
operator|*
specifier|volatile
name|ssh_bzero
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|size_t
argument_list|)
operator|=
name|bzero
expr_stmt|;
end_expr_stmt

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
name|ssh_bzero
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

begin_comment
comment|/* HAVE_MEMSET_S */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_EXPLICIT_BZERO */
end_comment

end_unit

