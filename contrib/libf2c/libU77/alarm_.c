begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1997 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|RETSIGTYPE
end_ifndef

begin_comment
comment|/* we shouldn't rely on this... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_define
define|#
directive|define
name|RETSIGTYPE
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|RETSIGTYPE
function_decl|(
modifier|*
name|sig_type
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
specifier|extern
name|sig_type
name|signal
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|integer
name|G77_alarm_0
argument_list|(
name|seconds
argument_list|,
name|proc
argument_list|)
name|integer
modifier|*
name|seconds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sig_type
name|proc
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sig_proc
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_function
name|integer
name|G77_alarm_0
parameter_list|(
name|integer
modifier|*
name|seconds
parameter_list|,
name|sig_proc
name|proc
parameter_list|)
endif|#
directive|endif
block|{
name|int
name|status
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ALARM
argument_list|)
operator|&&
name|defined
argument_list|(
name|SIGALRM
argument_list|)
if|if
condition|(
name|signal
argument_list|(
name|SIGALRM
argument_list|,
operator|(
name|sig_type
operator|)
name|proc
argument_list|)
operator|==
name|SIG_ERR
condition|)
name|status
operator|=
operator|-
literal|1
expr_stmt|;
else|else
name|status
operator|=
name|alarm
argument_list|(
operator|*
name|seconds
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* ! HAVE_ALARM || ! SIGALRM */
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

