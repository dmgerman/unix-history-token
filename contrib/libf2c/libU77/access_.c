begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995, 1997 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_comment
comment|/* for SVR1-2 */
end_comment

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|W_OK
end_ifndef

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|X_OK
end_ifndef

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
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
name|void
name|g_char
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|integer
name|G77_access_0
argument_list|(
name|name
argument_list|,
name|mode
argument_list|,
name|Lname
argument_list|,
name|Lmode
argument_list|)
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|Lname
decl_stmt|,
name|Lmode
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|g_char
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
name|ftnlen
name|alen
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|integer
name|G77_access_0
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|,
name|ftnlen
name|Lname
parameter_list|,
name|ftnlen
name|Lmode
parameter_list|)
endif|#
directive|endif
block|{
name|char
modifier|*
name|buff
decl_stmt|;
name|char
modifier|*
name|bp
decl_stmt|,
modifier|*
name|blast
decl_stmt|;
name|int
name|amode
decl_stmt|,
name|i
decl_stmt|;
name|buff
operator|=
name|malloc
argument_list|(
name|Lname
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|buff
condition|)
return|return
operator|-
literal|1
return|;
name|g_char
argument_list|(
name|name
argument_list|,
name|Lname
argument_list|,
name|buff
argument_list|)
expr_stmt|;
name|amode
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|Lmode
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|mode
index|[
name|i
index|]
condition|)
block|{
case|case
literal|'r'
case|:
name|amode
operator||=
name|R_OK
expr_stmt|;
break|break;
case|case
literal|'w'
case|:
name|amode
operator||=
name|W_OK
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
name|amode
operator||=
name|X_OK
expr_stmt|;
break|break;
case|case
literal|' '
case|:
name|amode
operator||=
name|F_OK
expr_stmt|;
break|break;
comment|/* as per Sun, at least */
default|default:
return|return
name|EINVAL
return|;
block|}
block|}
name|i
operator|=
name|access
argument_list|(
name|buff
argument_list|,
name|amode
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|buff
argument_list|)
expr_stmt|;
return|return
name|i
return|;
block|}
end_function

end_unit

