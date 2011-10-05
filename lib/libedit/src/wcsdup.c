begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: wcsdup.c,v 1.3 2008/05/26 13:17:48 haad Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2006 Aleksey Cheusov  *  * This material is provided "as is", with absolutely no warranty expressed  * or implied. Any use is at your own risk.  *  * Permission to use or copy this software for any purpose is hereby granted  * without fee. Permission to modify the code and to distribute modified  * code is also granted without any restrictions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_WCSDUP
end_ifndef

begin_include
include|#
directive|include
file|"config.h"
end_include

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

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: wcsdup.c,v 1.3 2008/05/26 13:17:48 haad Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_function
name|wchar_t
modifier|*
name|wcsdup
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|str
parameter_list|)
block|{
name|wchar_t
modifier|*
name|copy
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|_DIAGASSERT
argument_list|(
name|str
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|len
operator|=
name|wcslen
argument_list|(
name|str
argument_list|)
operator|+
literal|1
expr_stmt|;
name|copy
operator|=
name|malloc
argument_list|(
name|len
operator|*
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|copy
condition|)
return|return
name|NULL
return|;
return|return
name|wmemcpy
argument_list|(
name|copy
argument_list|,
name|str
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

