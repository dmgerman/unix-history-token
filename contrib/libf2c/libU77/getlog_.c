begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio.h>
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

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* getlogin not in svr1-3 */
end_comment

begin_comment
comment|/* SGI also has character*(*) function getlog() */
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

begin_comment
comment|/* Subroutine */
end_comment

begin_decl_stmt
name|int
name|G77_getlog_0
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

begin_comment
comment|/* Subroutine */
end_comment

begin_function
name|int
name|G77_getlog_0
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
name|size_t
name|i
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|status
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GETLOGIN
argument_list|)
name|p
operator|=
name|getlogin
argument_list|()
expr_stmt|;
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
block|{
name|i
operator|=
name|strlen
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|s_copy
argument_list|(
name|str
argument_list|,
name|p
argument_list|,
name|Lstr
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|s_copy
argument_list|(
name|str
argument_list|,
literal|" "
argument_list|,
name|Lstr
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|status
operator|=
literal|0
expr_stmt|;
else|#
directive|else
name|errno
operator|=
name|ENOSYS
expr_stmt|;
name|status
operator|=
operator|-
literal|1
expr_stmt|;
endif|#
directive|endif
return|return
name|status
return|;
block|}
end_function

end_unit

