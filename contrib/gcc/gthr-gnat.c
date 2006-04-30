begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Threads compatibility routines for libgcc2.  */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|"gthr-gnat.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
value|x __attribute__((unused))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|__gnat_default_lock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__gnat_default_unlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|__gnat_default_lock
parameter_list|(
name|void
parameter_list|)
block|{
return|return;
block|}
end_function

begin_function
name|void
name|__gnat_default_unlock
parameter_list|(
name|void
parameter_list|)
block|{
return|return;
block|}
end_function

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|__gnat_task_lock
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
operator|*
name|__gnat_default_lock
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|__gnat_task_unlock
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
operator|*
name|__gnat_default_unlock
function_decl|;
end_function_decl

begin_function
name|void
name|__gnat_install_locks
parameter_list|(
name|void
function_decl|(
modifier|*
name|lock
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|unlock
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|__gnat_task_lock
operator|=
name|lock
expr_stmt|;
name|__gnat_task_unlock
operator|=
name|unlock
expr_stmt|;
block|}
end_function

begin_function
name|int
name|__gthread_active_p
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|__gthread_mutex_lock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
name|__gnat_task_lock
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|__gthread_mutex_unlock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|UNUSED
parameter_list|(
name|mutex
parameter_list|)
parameter_list|)
block|{
name|__gnat_task_unlock
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

