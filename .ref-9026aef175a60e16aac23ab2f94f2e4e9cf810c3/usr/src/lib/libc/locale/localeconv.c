begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)localeconv.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_comment
comment|/*  * Return the current locale conversion.  */
end_comment

begin_function
name|struct
name|lconv
modifier|*
name|localeconv
parameter_list|()
block|{
specifier|extern
name|struct
name|lconv
modifier|*
name|__lconv
decl_stmt|;
return|return
operator|(
name|__lconv
operator|)
return|;
block|}
end_function

end_unit

