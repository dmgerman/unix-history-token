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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
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
file|"f2c.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRERROR
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|strerror
parameter_list|(
name|i
parameter_list|)
value|(sys_errlist[i])
end_define

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

begin_comment
comment|/* Subroutine */
end_comment

begin_decl_stmt
name|int
name|G77_gerror_0
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
name|G77_gerror_0
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|ftnlen
name|Lstr
parameter_list|)
endif|#
directive|endif
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|s
operator|=
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
name|s_copy
argument_list|(
name|str
argument_list|,
name|s
argument_list|,
name|Lstr
argument_list|,
name|strlen
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

