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

begin_if
if|#
directive|if
name|TIME_WITH_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|"f2c.h"
end_include

begin_comment
comment|/* may need sys/time.h& long arg for stime (bsd, svr1-3) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_comment
comment|/* Character */
end_comment

begin_decl_stmt
name|void
name|G77_ctime_0
argument_list|(
name|chtime
argument_list|,
name|Lchtime
argument_list|,
name|xstime
argument_list|)
name|char
modifier|*
name|chtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|longint
modifier|*
name|xstime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
name|Lchtime
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Character */
end_comment

begin_function
name|void
name|G77_ctime_0
parameter_list|(
name|char
modifier|*
name|chtime
parameter_list|,
specifier|const
name|ftnlen
name|Lchtime
parameter_list|,
name|longint
modifier|*
name|xstime
parameter_list|)
endif|#
directive|endif
block|{
name|int
name|i
decl_stmt|,
name|l
decl_stmt|;
name|int
name|s_copy
parameter_list|()
function_decl|;
name|time_t
name|stime
init|=
operator|*
name|xstime
decl_stmt|;
comment|/* Allow a length other than 24 for compatibility with what other      systems do, despite it being documented as 24. */
name|s_copy
argument_list|(
name|chtime
argument_list|,
name|ctime
argument_list|(
operator|&
name|stime
argument_list|)
argument_list|,
name|Lchtime
argument_list|,
literal|24
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

