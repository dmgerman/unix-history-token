begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* libc-internal interface for mutex locks.  LinuxThreads version.    Copyright (C) 1996 Free Software Foundation, Inc.    This file is part of the GNU C Library.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_LOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBC_LOCK_H
value|1
end_define

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_define
define|#
directive|define
name|__libc_lock_t
value|pthread_mutex_t
end_define

begin_comment
comment|/* Define a lock variable NAME with storage class CLASS.  The lock must be    initialized with __libc_lock_init before it can be used (or define it    with __libc_lock_define_initialized, below).  Use `extern' for CLASS to    declare a lock defined in another module.  In public structure    definitions you must use a pointer to the lock structure (i.e., NAME    begins with a `*'), because its storage size will not be known outside    of libc.  */
end_comment

begin_define
define|#
directive|define
name|__libc_lock_define
parameter_list|(
name|CLASS
parameter_list|,
name|NAME
parameter_list|)
define|\
value|CLASS __libc_lock_t NAME;
end_define

begin_comment
comment|/* Define an initialized lock variable NAME with storage class CLASS.  */
end_comment

begin_define
define|#
directive|define
name|__libc_lock_define_initialized
parameter_list|(
name|CLASS
parameter_list|,
name|NAME
parameter_list|)
define|\
value|CLASS __libc_lock_t NAME = PTHREAD_MUTEX_INITIALIZER;
end_define

begin_comment
comment|/* Initialize the named lock variable, leaving it in a consistent, unlocked    state.  */
end_comment

begin_define
define|#
directive|define
name|__libc_lock_init
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(__pthread_mutex_init != NULL ? __pthread_mutex_init (&(NAME), NULL) : 0);
end_define

begin_comment
comment|/* Same as last but this time we initialize a recursive mutex.  */
end_comment

begin_define
define|#
directive|define
name|__libc_lock_init_recursive
parameter_list|(
name|NAME
parameter_list|)
define|\
value|do {                                                                      \     if (__pthread_mutex_init != NULL)                                       \       {                                                                     \       pthread_mutexattr_t __attr;                                           \       __pthread_mutexattr_init (&__attr);                                   \       __pthread_mutexattr_setkind_np (&__attr, PTHREAD_MUTEX_RECURSIVE_NP); \       __pthread_mutex_init (&(NAME),&__attr);                              \       __pthread_mutexattr_destroy (&__attr);                                \       }                                                                             \   } while (0);
end_define

begin_comment
comment|/* Finalize the named lock variable, which must be locked.  It cannot be    used again until __libc_lock_init is called again on it.  This must be    called on a lock variable before the containing storage is reused.  */
end_comment

begin_define
define|#
directive|define
name|__libc_lock_fini
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(__pthread_mutex_destroy != NULL ? __pthread_mutex_destroy (&(NAME)) : 0);
end_define

begin_comment
comment|/* Lock the named lock variable.  */
end_comment

begin_define
define|#
directive|define
name|__libc_lock_lock
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(__pthread_mutex_lock != NULL ? __pthread_mutex_lock (&(NAME)) : 0);
end_define

begin_comment
comment|/* Try to lock the named lock variable.  */
end_comment

begin_define
define|#
directive|define
name|__libc_lock_trylock
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(__pthread_mutex_trylock != NULL ? __pthread_mutex_trylock (&(NAME)) : 0);
end_define

begin_comment
comment|/* Unlock the named lock variable.  */
end_comment

begin_define
define|#
directive|define
name|__libc_lock_unlock
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(__pthread_mutex_unlock != NULL ? __pthread_mutex_unlock (&(NAME)) : 0);
end_define

begin_comment
comment|/* Start critical region with cleanup.  */
end_comment

begin_define
define|#
directive|define
name|__libc_cleanup_region_start
parameter_list|(
name|FCT
parameter_list|,
name|ARG
parameter_list|)
define|\
value|{ struct _pthread_cleanup_buffer _buffer;                                 \     if (_pthread_cleanup_push_defer != NULL) {                              \       _pthread_cleanup_push_defer (&_buffer, (FCT), (ARG));                 \     }
end_define

begin_comment
comment|/* End critical region with cleanup.  */
end_comment

begin_define
define|#
directive|define
name|__libc_cleanup_region_end
parameter_list|(
name|DOIT
parameter_list|)
define|\
value|if (_pthread_cleanup_push_defer != NULL) {                              \       _pthread_cleanup_pop_restore (&_buffer, (DOIT));                      \     }                                                                       \   }
end_define

begin_comment
comment|/* Make the pthread functions weak so that we can elide them from    single-threaded processes.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_mutex_init
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_mutex_destroy
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_mutex_lock
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_mutex_trylock
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_mutex_unlock
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_mutexattr_init
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_mutexattr_destroy
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_mutexattr_setkind_np
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_key_create
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_setspecific
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_getspecific
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|__pthread_initialize
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|_pthread_cleanup_push_defer
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|_pthread_cleanup_pop_restore
end_pragma

begin_comment
comment|/* We need portable names for some functions.  E.g., when they are    used as argument to __libc_cleanup_region_start.  */
end_comment

begin_define
define|#
directive|define
name|__libc_mutex_unlock
value|__pthread_mutex_unlock
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* libc-lock.h */
end_comment

end_unit

