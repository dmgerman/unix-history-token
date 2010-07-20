begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2001 Wolfram Gloger Copyright (c) 2006 Cavium networks  Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that (i) the above copyright notices and this permission notice appear in all copies of the software and related documentation, and (ii) the name of Wolfram Gloger may not be used in any advertising or publicity relating to the software.  THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL WOLFRAM GLOGER BE LIABLE FOR ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
end_comment

begin_comment
comment|/* $Id: thread-m.h 30481 2007-12-05 21:46:59Z rfranz $    One out of _LIBC, USE_PTHREADS, USE_THR or USE_SPROC should be    defined, otherwise the token NO_THREADS and dummy implementations    of the macros will be defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_THREAD_M_H
end_ifndef

begin_define
define|#
directive|define
name|_THREAD_M_H
end_define

begin_undef
undef|#
directive|undef
name|thread_atfork_static
end_undef

begin_undef
undef|#
directive|undef
name|NO_THREADS
end_undef

begin_comment
comment|/* No threads, provide dummy macros */
end_comment

begin_typedef
typedef|typedef
name|int
name|thread_id
typedef|;
end_typedef

begin_comment
comment|/* The mutex functions used to do absolutely nothing, i.e. lock,    trylock and unlock would always just return 0.  However, even    without any concurrently active threads, a mutex can be used    legitimately as an `in use' flag.  To make the code that is    protected by a mutex async-signal safe, these macros would have to    be based on atomic test-and-set operations, for example. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__OCTEON__
end_ifdef

begin_typedef
typedef|typedef
name|cvmx_spinlock_t
name|mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MUTEX_INITIALIZER
value|CMVX_SPINLOCK_UNLOCKED_VAL
end_define

begin_define
define|#
directive|define
name|mutex_init
parameter_list|(
name|m
parameter_list|)
value|cvmx_spinlock_init(m)
end_define

begin_define
define|#
directive|define
name|mutex_lock
parameter_list|(
name|m
parameter_list|)
value|cvmx_spinlock_lock(m)
end_define

begin_define
define|#
directive|define
name|mutex_trylock
parameter_list|(
name|m
parameter_list|)
value|(cvmx_spinlock_trylock(m))
end_define

begin_define
define|#
directive|define
name|mutex_unlock
parameter_list|(
name|m
parameter_list|)
value|cvmx_spinlock_unlock(m)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MUTEX_INITIALIZER
value|0
end_define

begin_define
define|#
directive|define
name|mutex_init
parameter_list|(
name|m
parameter_list|)
value|(*(m) = 0)
end_define

begin_define
define|#
directive|define
name|mutex_lock
parameter_list|(
name|m
parameter_list|)
value|((*(m) = 1), 0)
end_define

begin_define
define|#
directive|define
name|mutex_trylock
parameter_list|(
name|m
parameter_list|)
value|(*(m) ? 1 : ((*(m) = 1), 0))
end_define

begin_define
define|#
directive|define
name|mutex_unlock
parameter_list|(
name|m
parameter_list|)
value|(*(m) = 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
modifier|*
name|tsd_key_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|tsd_key_create
parameter_list|(
name|key
parameter_list|,
name|destr
parameter_list|)
value|do {} while(0)
end_define

begin_define
define|#
directive|define
name|tsd_setspecific
parameter_list|(
name|key
parameter_list|,
name|data
parameter_list|)
value|((key) = (data))
end_define

begin_define
define|#
directive|define
name|tsd_getspecific
parameter_list|(
name|key
parameter_list|,
name|vptr
parameter_list|)
value|(vptr = (key))
end_define

begin_define
define|#
directive|define
name|thread_atfork
parameter_list|(
name|prepare
parameter_list|,
name|parent
parameter_list|,
name|child
parameter_list|)
value|do {} while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(_THREAD_M_H) */
end_comment

end_unit

