begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995, 1996, 2001 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_comment
comment|/* VMS and Irix versions (at least) differ from libU77 elsewhere */
end_comment

begin_comment
comment|/* VMS style: */
end_comment

begin_comment
comment|/* Subroutine */
end_comment

begin_function
name|int
name|G77_vxtidate_y2kbug_0
parameter_list|(
name|integer
modifier|*
name|m
parameter_list|,
name|integer
modifier|*
name|d
parameter_list|,
name|integer
modifier|*
name|y
parameter_list|)
block|{
name|struct
name|tm
modifier|*
name|lt
decl_stmt|;
name|time_t
name|tim
decl_stmt|;
name|tim
operator|=
name|time
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|lt
operator|=
name|localtime
argument_list|(
operator|&
name|tim
argument_list|)
expr_stmt|;
operator|*
name|y
operator|=
name|lt
operator|->
name|tm_year
operator|%
literal|100
expr_stmt|;
operator|*
name|m
operator|=
name|lt
operator|->
name|tm_mon
operator|+
literal|1
expr_stmt|;
operator|*
name|d
operator|=
name|lt
operator|->
name|tm_mday
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|G77_Non_Y2K_Compliance_Message
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|G77_vxtidate_y2kbuggy_0
argument_list|(
name|integer
operator|*
name|m
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|,
name|integer
operator|*
name|d
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|,
name|integer
operator|*
name|y
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
argument_list|)
block|{
specifier|extern
name|int
name|G77_abort_0
parameter_list|()
function_decl|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|G77_Non_Y2K_Compliance_Message
argument_list|)
expr_stmt|;
name|G77_abort_0
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

