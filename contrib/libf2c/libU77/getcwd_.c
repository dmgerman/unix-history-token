begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995, 1996 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* for NULL */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* for ENOSYS */
end_comment

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_if
if|#
directive|if
name|HAVE_GETCWD
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|getcwd
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
specifier|extern
name|void
name|s_copy
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|integer
name|G77_getcwd_0
argument_list|(
name|str
argument_list|,
name|Lstr
argument_list|)
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|Lstr
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|s_copy
parameter_list|(
specifier|register
name|char
modifier|*
name|a
parameter_list|,
specifier|register
name|char
modifier|*
name|b
parameter_list|,
name|ftnlen
name|la
parameter_list|,
name|ftnlen
name|lb
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|integer
name|G77_getcwd_0
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|ftnlen
name|Lstr
parameter_list|)
endif|#
directive|endif
block|{
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|ret
decl_stmt|;
name|ret
operator|=
name|getcwd
argument_list|(
name|str
argument_list|,
name|Lstr
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|NULL
condition|)
return|return
name|errno
return|;
for|for
control|(
name|i
operator|=
name|strlen
argument_list|(
name|str
argument_list|)
init|;
name|i
operator|<
name|Lstr
condition|;
name|i
operator|++
control|)
name|str
index|[
name|i
index|]
operator|=
literal|' '
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|HAVE_GETWD
end_elif

begin_comment
comment|/* HAVE_GETCWD */
end_comment

begin_comment
comment|/* getwd usage taken from SunOS4 man */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
specifier|extern
name|VOID
name|s_copy
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|integer
name|G77_getcwd_0
argument_list|(
name|str
argument_list|,
name|Lstr
argument_list|)
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|Lstr
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|s_copy
parameter_list|(
specifier|register
name|char
modifier|*
name|a
parameter_list|,
specifier|register
name|char
modifier|*
name|b
parameter_list|,
name|ftnlen
name|la
parameter_list|,
name|ftnlen
name|lb
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|integer
name|G77_getcwd_0
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|ftnlen
name|Lstr
parameter_list|)
endif|#
directive|endif
block|{
name|char
name|pathname
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|size_t
name|l
decl_stmt|;
if|if
condition|(
name|getwd
argument_list|(
name|pathname
argument_list|)
operator|==
name|NULL
condition|)
block|{
return|return
name|errno
return|;
block|}
else|else
block|{
name|s_copy
argument_list|(
name|str
argument_list|,
name|pathname
argument_list|,
name|Lstr
argument_list|,
name|strlen
argument_list|(
name|str
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_GETWD&& !HAVE_GETCWD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
specifier|extern
name|VOID
name|s_copy
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|integer
name|G77_getcwd_0
argument_list|(
name|str
argument_list|,
name|Lstr
argument_list|)
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|Lstr
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|s_copy
parameter_list|(
specifier|register
name|char
modifier|*
name|a
parameter_list|,
specifier|register
name|char
modifier|*
name|b
parameter_list|,
name|ftnlen
name|la
parameter_list|,
name|ftnlen
name|lb
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|integer
name|G77_getcwd_0
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|ftnlen
name|Lstr
parameter_list|)
endif|#
directive|endif
block|{
return|return
name|errno
operator|=
name|ENOSYS
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

