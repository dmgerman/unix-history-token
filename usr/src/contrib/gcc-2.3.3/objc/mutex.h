begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|_MUTEX_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WANT_MUTEX
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<cthreads.h>
end_include

begin_define
define|#
directive|define
name|MUTEX
value|mutex_t
end_define

begin_define
define|#
directive|define
name|MUTEX_ALLOC
parameter_list|(
name|mutex
parameter_list|)
value|{ *mutex = mutex_alloc (); }
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|mutex
parameter_list|)
value|mutex_init (mutex)
end_define

begin_define
define|#
directive|define
name|MUTEX_FREE
parameter_list|(
name|mutex
parameter_list|)
value|mutex_free (mutex)
end_define

begin_define
define|#
directive|define
name|MUTEX_LOCK
parameter_list|(
name|mutex
parameter_list|)
value|mutex_lock (mutex)
end_define

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|mutex
parameter_list|)
value|mutex_unlock (mutex)
end_define

begin_define
define|#
directive|define
name|MUTEX_ISLOCK
parameter_list|(
name|mutex
parameter_list|)
value|mutex->lock
end_define

begin_comment
comment|/* Gak */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OSF
argument_list|)
end_elif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|mach
argument_list|)
end_elif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sun
argument_list|)
end_elif

begin_comment
comment|/*  * Sun lwp uses monitors.  *  * Untested.  8-Dec-91, dennisg.  */
end_comment

begin_include
include|#
directive|include
file|<lwp/lwp.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|MUTEX
value|(mon_t)
end_define

begin_function
specifier|inline
name|MUTEX
name|MUTEX_ALLOC
parameter_list|(
name|mutex
parameter_list|)
block|{
name|MUTEX
name|mon
decl_stmt|;
name|mon_create
argument_list|(
operator|&
name|mon
argument_list|)
expr_stmt|;
return|return
name|mon
return|;
block|}
end_function

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|mutex
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MUTEX_FREE
parameter_list|(
name|mutex
parameter_list|)
value|mon_destroy (mutex)
end_define

begin_function
specifier|inline
name|void
name|MUTEX_LOCK
parameter_list|(
name|mutex
parameter_list|)
block|{
name|int
name|level
init|=
name|mon_enter
argument_list|(
name|mutex
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|level
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|mutex
parameter_list|)
value|mon_exit (mutex)
end_define

begin_function
specifier|inline
name|int
name|MUTEX_ISLOCK
parameter_list|(
name|mutex
parameter_list|)
block|{
name|thread_t
name|thread
decl_stmt|;
comment|/* Won't work? */
return|return
name|mon_waiters
argument_list|(
name|mutex
argument_list|,
operator|&
name|thread
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|COROUTINES
argument_list|)
end_elif

begin_comment
comment|/*  * A environment where threads are implemented as a  *  set of coroutines.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MUTEX
end_ifndef

begin_comment
comment|/*  * These are default mutex handler routines.  *  There is no mutex support.  *  * Let the optimizer get rid of mutexes.  */
end_comment

begin_define
define|#
directive|define
name|MUTEX
value|void *
end_define

begin_define
define|#
directive|define
name|MUTEX_ALLOC
parameter_list|(
name|mutex
parameter_list|)
value|(MUTEX)-1
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|mutex
parameter_list|)
value|(mutex)
end_define

begin_define
define|#
directive|define
name|MUTEX_FREE
parameter_list|(
name|mutex
parameter_list|)
value|(mutex)
end_define

begin_define
define|#
directive|define
name|MUTEX_LOCK
parameter_list|(
name|mutex
parameter_list|)
value|(mutex)
end_define

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|mutex
parameter_list|)
value|(mutex)
end_define

begin_define
define|#
directive|define
name|MUTEX_ISLOCK
parameter_list|(
name|mutex
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _MUTEX_H */
end_comment

end_unit

