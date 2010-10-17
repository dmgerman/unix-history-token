begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utilities to execute a program in a subprocess (possibly linked by pipes    with other subprocesses), and wait for it.  DJGPP specialization.    Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003    Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"pex-common.h"
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

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_DECLARATION_ERRNO
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_comment
comment|/* Use ECHILD if available, otherwise use EINVAL.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ECHILD
end_ifdef

begin_define
define|#
directive|define
name|PWAIT_ERROR
value|ECHILD
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PWAIT_ERROR
value|EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS doesn't multitask, but for the sake of a consistent interface    the code behaves like it does.  pexecute runs the program, tucks the    exit code away, and returns a "pid".  pwait must be called to fetch the    exit code.  */
end_comment

begin_comment
comment|/* For communicating information from pexecute to pwait.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|last_pid
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|last_status
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|last_reaped
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|pexecute
parameter_list|(
name|program
parameter_list|,
name|argv
parameter_list|,
name|this_pname
parameter_list|,
name|temp_base
parameter_list|,
name|errmsg_fmt
parameter_list|,
name|errmsg_arg
parameter_list|,
name|flags
parameter_list|)
specifier|const
name|char
modifier|*
name|program
decl_stmt|;
name|char
modifier|*
specifier|const
modifier|*
name|argv
decl_stmt|;
specifier|const
name|char
modifier|*
name|this_pname
decl_stmt|;
specifier|const
name|char
modifier|*
name|temp_base
decl_stmt|;
name|char
modifier|*
modifier|*
name|errmsg_fmt
decl_stmt|,
decl|*
modifier|*
name|errmsg_arg
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|flags
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|rc
decl_stmt|;
name|last_pid
operator|++
expr_stmt|;
if|if
condition|(
name|last_pid
operator|<
literal|0
condition|)
name|last_pid
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|PEXECUTE_ONE
operator|)
operator|!=
name|PEXECUTE_ONE
condition|)
name|abort
argument_list|()
expr_stmt|;
comment|/* ??? What are the possible return values from spawnv?  */
name|rc
operator|=
operator|(
name|flags
operator|&
name|PEXECUTE_SEARCH
condition|?
name|spawnvp
else|:
name|spawnv
operator|)
operator|(
name|P_WAIT
operator|,
name|program
operator|,
name|argv
operator|)
expr_stmt|;
if|if
condition|(
name|rc
operator|==
operator|-
literal|1
condition|)
block|{
operator|*
name|errmsg_fmt
operator|=
name|install_error_msg
expr_stmt|;
operator|*
name|errmsg_arg
operator|=
operator|(
name|char
operator|*
operator|)
name|program
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/* Tuck the status away for pwait, and return a "pid".  */
name|last_status
operator|=
name|rc
operator|<<
literal|8
expr_stmt|;
return|return
name|last_pid
return|;
block|}
end_block

begin_function
name|int
name|pwait
parameter_list|(
name|pid
parameter_list|,
name|status
parameter_list|,
name|flags
parameter_list|)
name|int
name|pid
decl_stmt|;
name|int
modifier|*
name|status
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|{
comment|/* On MSDOS each pexecute must be followed by its associated pwait.  */
if|if
condition|(
name|pid
operator|!=
name|last_pid
comment|/* Called twice for the same child?  */
operator|||
name|pid
operator|==
name|last_reaped
condition|)
block|{
name|errno
operator|=
name|PWAIT_ERROR
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/* ??? Here's an opportunity to canonicalize the values in STATUS.      Needed?  */
operator|*
name|status
operator|=
operator|(
name|last_status
operator|>>
literal|8
operator|)
expr_stmt|;
name|last_reaped
operator|=
name|last_pid
expr_stmt|;
return|return
name|last_pid
return|;
block|}
end_function

end_unit

