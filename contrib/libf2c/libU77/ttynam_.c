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
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|STDC_HEADERS
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* POSIX for ttyname */
end_comment

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

begin_function_decl
specifier|extern
name|integer
name|G77_fnum_0
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Character */
end_comment

begin_decl_stmt
name|void
name|G77_ttynam_0
argument_list|(
name|ret_val
argument_list|,
name|ret_val_len
argument_list|,
name|lunit
argument_list|)
name|char
modifier|*
name|ret_val
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|ret_val_len
decl_stmt|;
end_decl_stmt

begin_function_decl
name|integer
modifier|*
name|lunit
else|#
directive|else
specifier|extern
name|integer
name|G77_fnum_0
parameter_list|(
name|integer
modifier|*
name|lunit
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* Character */
end_comment

begin_function
name|void
name|G77_ttynam_0
parameter_list|(
name|char
modifier|*
name|ret_val
parameter_list|,
name|ftnlen
name|ret_val_len
parameter_list|,
name|integer
modifier|*
name|lunit
parameter_list|)
endif|#
directive|endif
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TTYNAME
argument_list|)
name|size_t
name|i
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|ttyname
argument_list|(
name|G77_fnum_0
argument_list|(
name|lunit
argument_list|)
argument_list|)
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
name|ret_val
argument_list|,
name|p
argument_list|,
name|ret_val_len
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|s_copy
argument_list|(
name|ret_val
argument_list|,
literal|" "
argument_list|,
name|ret_val_len
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|errno
operator|=
name|ENOSYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
endif|#
directive|endif
block|}
end_function

end_unit

