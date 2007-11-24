begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Threads compatibility routines for libgcc2 and libobjc for VxWorks.  */
end_comment

begin_comment
comment|/* Compile this one with gcc.  */
end_comment

begin_comment
comment|/* Copyright (C) 1997, 1999, 2000 Free Software Foundation, Inc.    Contributed by Mike Stump<mrs@wrs.com>.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GTHR_VXWORKS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GTHR_VXWORKS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBOBJC
end_ifdef

begin_comment
comment|/* libobjc requires the optional pthreads component.  */
end_comment

begin_include
include|#
directive|include
file|"gthr-posix.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__GTHREADS
value|1
end_define

begin_define
define|#
directive|define
name|__gthread_active_p
parameter_list|()
value|1
end_define

begin_comment
comment|/* Mutexes are easy, except that they need to be initialized at runtime.  */
end_comment

begin_include
include|#
directive|include
file|<semLib.h>
end_include

begin_typedef
typedef|typedef
name|SEM_ID
name|__gthread_mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__GTHREAD_MUTEX_INIT_FUNCTION
value|__gthread_mutex_init_function
end_define

begin_function
specifier|static
specifier|inline
name|void
name|__gthread_mutex_init_function
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
operator|*
name|mutex
operator|=
name|semMCreate
argument_list|(
name|SEM_Q_PRIORITY
operator||
name|SEM_INVERSION_SAFE
operator||
name|SEM_DELETE_SAFE
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_mutex_lock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
return|return
name|semTake
argument_list|(
operator|*
name|mutex
argument_list|,
name|WAIT_FOREVER
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_mutex_trylock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
return|return
name|semTake
argument_list|(
operator|*
name|mutex
argument_list|,
name|NO_WAIT
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|__gthread_mutex_unlock
parameter_list|(
name|__gthread_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
return|return
name|semGive
argument_list|(
operator|*
name|mutex
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* pthread_once is complicated enough that it's implemented    out-of-line.  See config/vxlib.c.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|unsigned
name|char
name|busy
decl_stmt|;
specifier|volatile
name|unsigned
name|char
name|done
decl_stmt|;
block|}
name|__gthread_once_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__GTHREAD_ONCE_INIT
value|{ 0, 0 }
end_define

begin_function_decl
specifier|extern
name|int
name|__gthread_once
parameter_list|(
name|__gthread_once_t
modifier|*
name|once
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Thread-specific data requires a great deal of effort, since VxWorks    is not really set up for it.  See config/vxlib.c for the gory    details.  All the TSD routines are sufficiently complex that they    need to be implemented out of line.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__gthread_key_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|__gthread_key_create
parameter_list|(
name|__gthread_key_t
modifier|*
name|keyp
parameter_list|,
name|void
function_decl|(
modifier|*
name|dtor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__gthread_key_delete
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|__gthread_getspecific
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__gthread_setspecific
parameter_list|(
name|__gthread_key_t
name|key
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _LIBOBJC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gthr-vxworks.h */
end_comment

end_unit

