begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Private definitions for libc, libc_r and libpthread.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBC_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBC_PRIVATE_H_
end_define

begin_comment
comment|/*  * This global flag is non-zero when a process has created one  * or more threads. It is used to avoid calling locking functions  * when they are not required.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__isthreaded
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * File lock contention is difficult to diagnose without knowing  * where locks were set. Allow a debug library to be built which  * records the source file and line number of each lock call.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_FLOCK_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|_FLOCKFILE
parameter_list|(
name|x
parameter_list|)
value|_flockfile_debug(x, __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_FLOCKFILE
parameter_list|(
name|x
parameter_list|)
value|_flockfile(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros for locking and unlocking FILEs. These test if the  * process is threaded to avoid locking when not required.  */
end_comment

begin_define
define|#
directive|define
name|FLOCKFILE
parameter_list|(
name|fp
parameter_list|)
value|if (__isthreaded) _FLOCKFILE(fp)
end_define

begin_define
define|#
directive|define
name|FUNLOCKFILE
parameter_list|(
name|fp
parameter_list|)
value|if (__isthreaded) _funlockfile(fp)
end_define

begin_comment
comment|/*  * Indexes into the pthread jump table.  *  * Warning! If you change this type, you must also change the threads  * libraries that reference it (libc_r, libpthread).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PJT_COND_BROADCAST
block|,
name|PJT_COND_DESTROY
block|,
name|PJT_COND_INIT
block|,
name|PJT_COND_SIGNAL
block|,
name|PJT_COND_WAIT
block|,
name|PJT_GETSPECIFIC
block|,
name|PJT_KEY_CREATE
block|,
name|PJT_KEY_DELETE
block|,
name|PJT_MAIN_NP
block|,
name|PJT_MUTEX_DESTROY
block|,
name|PJT_MUTEX_INIT
block|,
name|PJT_MUTEX_LOCK
block|,
name|PJT_MUTEX_TRYLOCK
block|,
name|PJT_MUTEX_UNLOCK
block|,
name|PJT_MUTEXATTR_DESTROY
block|,
name|PJT_MUTEXATTR_INIT
block|,
name|PJT_MUTEXATTR_SETTYPE
block|,
name|PJT_ONCE
block|,
name|PJT_RWLOCK_DESTROY
block|,
name|PJT_RWLOCK_INIT
block|,
name|PJT_RWLOCK_RDLOCK
block|,
name|PJT_RWLOCK_TRYRDLOCK
block|,
name|PJT_RWLOCK_TRYWRLOCK
block|,
name|PJT_RWLOCK_UNLOCK
block|,
name|PJT_RWLOCK_WRLOCK
block|,
name|PJT_SELF
block|,
name|PJT_SETSPECIFIC
block|,
name|PJT_SIGMASK
block|,
name|PJT_MAX
block|}
name|pjt_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pthread_func_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_func_t
name|pthread_func_entry_t
index|[
literal|2
index|]
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|pthread_func_entry_t
name|__thr_jtable
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is a pointer in the C run-time startup code. It is used  * by getprogname() and setprogname().  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|__progname
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBC_PRIVATE_H_ */
end_comment

end_unit

