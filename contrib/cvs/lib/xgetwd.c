begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xgetwd.c -- return current directory with unlimited length    Copyright (C) 1992, 1997 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
end_comment

begin_comment
comment|/* Derived from xgetcwd.c in e.g. the GNU sh-utils.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Amount by which to increase buffer size when allocating more space. */
end_comment

begin_define
define|#
directive|define
name|PATH_INCR
value|32
end_define

begin_function_decl
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the current directory, newly allocated, arbitrarily long.    Return NULL and set errno on error. */
end_comment

begin_function
name|char
modifier|*
name|xgetwd
parameter_list|()
block|{
name|char
modifier|*
name|cwd
decl_stmt|;
name|char
modifier|*
name|ret
decl_stmt|;
name|unsigned
name|path_max
decl_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|path_max
operator|=
operator|(
name|unsigned
operator|)
name|PATH_MAX
expr_stmt|;
name|path_max
operator|+=
literal|2
expr_stmt|;
comment|/* The getcwd docs say to do this. */
name|cwd
operator|=
name|xmalloc
argument_list|(
name|path_max
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|ret
operator|=
name|getcwd
argument_list|(
name|cwd
argument_list|,
name|path_max
argument_list|)
operator|)
operator|==
name|NULL
operator|&&
name|errno
operator|==
name|ERANGE
condition|)
block|{
name|path_max
operator|+=
name|PATH_INCR
expr_stmt|;
name|cwd
operator|=
name|xrealloc
argument_list|(
name|cwd
argument_list|,
name|path_max
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|ret
operator|==
name|NULL
condition|)
block|{
name|int
name|save_errno
init|=
name|errno
decl_stmt|;
name|free
argument_list|(
name|cwd
argument_list|)
expr_stmt|;
name|errno
operator|=
name|save_errno
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|cwd
return|;
block|}
end_function

end_unit

