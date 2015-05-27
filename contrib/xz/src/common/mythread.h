begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       mythread.h
end_comment

begin_comment
comment|/// \brief      Some threading related helper macros and functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MYTHREAD_H
end_ifndef

begin_define
define|#
directive|define
name|MYTHREAD_H
end_define

begin_include
include|#
directive|include
file|"sysdefs.h"
end_include

begin_comment
comment|// If any type of threading is enabled, #define MYTHREAD_ENABLED.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MYTHREAD_POSIX
argument_list|)
operator|||
name|defined
argument_list|(
name|MYTHREAD_WIN95
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|MYTHREAD_VISTA
argument_list|)
end_if

begin_define
define|#
directive|define
name|MYTHREAD_ENABLED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MYTHREAD_ENABLED
end_ifdef

begin_comment
comment|////////////////////////////////////////
end_comment

begin_comment
comment|// Shared between all threading types //
end_comment

begin_comment
comment|////////////////////////////////////////
end_comment

begin_comment
comment|// Locks a mutex for a duration of a block.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Perform mythread_mutex_lock(&mutex) in the beginning of a block
end_comment

begin_comment
comment|// and mythread_mutex_unlock(&mutex) at the end of the block. "break"
end_comment

begin_comment
comment|// may be used to unlock the mutex and jump out of the block.
end_comment

begin_comment
comment|// mythread_sync blocks may be nested.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     mythread_sync(mutex) {
end_comment

begin_comment
comment|//         foo();
end_comment

begin_comment
comment|//         if (some_error)
end_comment

begin_comment
comment|//             break; // Skips bar()
end_comment

begin_comment
comment|//         bar();
end_comment

begin_comment
comment|//     }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// At least GCC optimizes the loops completely away so it doesn't slow
end_comment

begin_comment
comment|// things down at all compared to plain mythread_mutex_lock(&mutex)
end_comment

begin_comment
comment|// and mythread_mutex_unlock(&mutex) calls.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|mythread_sync
parameter_list|(
name|mutex
parameter_list|)
value|mythread_sync_helper1(mutex, __LINE__)
end_define

begin_define
define|#
directive|define
name|mythread_sync_helper1
parameter_list|(
name|mutex
parameter_list|,
name|line
parameter_list|)
value|mythread_sync_helper2(mutex, line)
end_define

begin_define
define|#
directive|define
name|mythread_sync_helper2
parameter_list|(
name|mutex
parameter_list|,
name|line
parameter_list|)
define|\
value|for (unsigned int mythread_i_ ## line = 0; \ 			mythread_i_ ## line \ 				? (mythread_mutex_unlock(&(mutex)), 0) \ 				: (mythread_mutex_lock(&(mutex)), 1); \ 			mythread_i_ ## line = 1) \ 		for (unsigned int mythread_j_ ## line = 0; \ 				!mythread_j_ ## line; \ 				mythread_j_ ## line = 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MYTHREAD_ENABLED
argument_list|)
end_if

begin_comment
comment|//////////////////
end_comment

begin_comment
comment|// No threading //
end_comment

begin_comment
comment|//////////////////
end_comment

begin_comment
comment|// Calls the given function once. This isn't thread safe.
end_comment

begin_define
define|#
directive|define
name|mythread_once
parameter_list|(
name|func
parameter_list|)
define|\
value|do { \ 	static bool once_ = false; \ 	if (!once_) { \ 		func(); \ 		once_ = true; \ 	} \ } while (0)
end_define

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|)
end_if

begin_comment
comment|// Use sigprocmask() to set the signal mask in single-threaded programs.
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_function
specifier|static
specifier|inline
name|void
name|mythread_sigmask
parameter_list|(
name|int
name|how
parameter_list|,
specifier|const
name|sigset_t
modifier|*
specifier|restrict
name|set
parameter_list|,
name|sigset_t
modifier|*
specifier|restrict
name|oset
parameter_list|)
block|{
name|int
name|ret
init|=
name|sigprocmask
argument_list|(
name|how
argument_list|,
name|set
argument_list|,
name|oset
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MYTHREAD_POSIX
argument_list|)
end_elif

begin_comment
comment|////////////////////
end_comment

begin_comment
comment|// Using pthreads //
end_comment

begin_comment
comment|////////////////////
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|MYTHREAD_RET_TYPE
value|void *
end_define

begin_define
define|#
directive|define
name|MYTHREAD_RET_VALUE
value|NULL
end_define

begin_typedef
typedef|typedef
name|pthread_t
name|mythread
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|mythread_mutex
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pthread_cond_t
name|cond
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_CLOCK_GETTIME
comment|// Clock ID (CLOCK_REALTIME or CLOCK_MONOTONIC) associated with
comment|// the condition variable.
name|clockid_t
name|clk_id
decl_stmt|;
endif|#
directive|endif
block|}
name|mythread_cond
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|timespec
name|mythread_condtime
typedef|;
end_typedef

begin_comment
comment|// Calls the given function once in a thread-safe way.
end_comment

begin_define
define|#
directive|define
name|mythread_once
parameter_list|(
name|func
parameter_list|)
define|\
value|do { \ 		static pthread_once_t once_ = PTHREAD_ONCE_INIT; \ 		pthread_once(&once_,&func); \ 	} while (0)
end_define

begin_comment
comment|// Use pthread_sigmask() to set the signal mask in multi-threaded programs.
end_comment

begin_comment
comment|// Do nothing on OpenVMS since it lacks pthread_sigmask().
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|mythread_sigmask
parameter_list|(
name|int
name|how
parameter_list|,
specifier|const
name|sigset_t
modifier|*
specifier|restrict
name|set
parameter_list|,
name|sigset_t
modifier|*
specifier|restrict
name|oset
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__VMS
operator|(
name|void
operator|)
name|how
expr_stmt|;
operator|(
name|void
operator|)
name|set
expr_stmt|;
operator|(
name|void
operator|)
name|oset
expr_stmt|;
else|#
directive|else
name|int
name|ret
init|=
name|pthread_sigmask
argument_list|(
name|how
argument_list|,
name|set
argument_list|,
name|oset
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// Creates a new thread with all signals blocked. Returns zero on success
end_comment

begin_comment
comment|// and non-zero on error.
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|mythread_create
parameter_list|(
name|mythread
modifier|*
name|thread
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|sigset_t
name|old
decl_stmt|;
name|sigset_t
name|all
decl_stmt|;
name|sigfillset
argument_list|(
operator|&
name|all
argument_list|)
expr_stmt|;
name|mythread_sigmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|all
argument_list|,
operator|&
name|old
argument_list|)
expr_stmt|;
specifier|const
name|int
name|ret
init|=
name|pthread_create
argument_list|(
name|thread
argument_list|,
name|NULL
argument_list|,
name|func
argument_list|,
name|arg
argument_list|)
decl_stmt|;
name|mythread_sigmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|old
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|// Joins a thread. Returns zero on success and non-zero on error.
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|mythread_join
parameter_list|(
name|mythread
name|thread
parameter_list|)
block|{
return|return
name|pthread_join
argument_list|(
name|thread
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Initiatlizes a mutex. Returns zero on success and non-zero on error.
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|mythread_mutex_init
parameter_list|(
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
return|return
name|pthread_mutex_init
argument_list|(
name|mutex
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_mutex_destroy
parameter_list|(
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
name|int
name|ret
init|=
name|pthread_mutex_destroy
argument_list|(
name|mutex
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_mutex_lock
parameter_list|(
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
name|int
name|ret
init|=
name|pthread_mutex_lock
argument_list|(
name|mutex
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_mutex_unlock
parameter_list|(
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
name|int
name|ret
init|=
name|pthread_mutex_unlock
argument_list|(
name|mutex
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
block|}
end_function

begin_comment
comment|// Initializes a condition variable.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Using CLOCK_MONOTONIC instead of the default CLOCK_REALTIME makes the
end_comment

begin_comment
comment|// timeout in pthread_cond_timedwait() work correctly also if system time
end_comment

begin_comment
comment|// is suddenly changed. Unfortunately CLOCK_MONOTONIC isn't available
end_comment

begin_comment
comment|// everywhere while the default CLOCK_REALTIME is, so the default is
end_comment

begin_comment
comment|// used if CLOCK_MONOTONIC isn't available.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If clock_gettime() isn't available at all, gettimeofday() will be used.
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|mythread_cond_init
parameter_list|(
name|mythread_cond
modifier|*
name|mycond
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_CLOCK_GETTIME
comment|// NOTE: HAVE_DECL_CLOCK_MONOTONIC is always defined to 0 or 1.
if|#
directive|if
name|defined
argument_list|(
name|HAVE_PTHREAD_CONDATTR_SETCLOCK
argument_list|)
operator|&&
name|HAVE_DECL_CLOCK_MONOTONIC
name|struct
name|timespec
name|ts
decl_stmt|;
name|pthread_condattr_t
name|condattr
decl_stmt|;
comment|// POSIX doesn't seem to *require* that pthread_condattr_setclock()
comment|// will fail if given an unsupported clock ID. Test that
comment|// CLOCK_MONOTONIC really is supported using clock_gettime().
if|if
condition|(
name|clock_gettime
argument_list|(
name|CLOCK_MONOTONIC
argument_list|,
operator|&
name|ts
argument_list|)
operator|==
literal|0
operator|&&
name|pthread_condattr_init
argument_list|(
operator|&
name|condattr
argument_list|)
operator|==
literal|0
condition|)
block|{
name|int
name|ret
init|=
name|pthread_condattr_setclock
argument_list|(
operator|&
name|condattr
argument_list|,
name|CLOCK_MONOTONIC
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
condition|)
name|ret
operator|=
name|pthread_cond_init
argument_list|(
operator|&
name|mycond
operator|->
name|cond
argument_list|,
operator|&
name|condattr
argument_list|)
expr_stmt|;
name|pthread_condattr_destroy
argument_list|(
operator|&
name|condattr
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
condition|)
block|{
name|mycond
operator|->
name|clk_id
operator|=
name|CLOCK_MONOTONIC
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
comment|// If anything above fails, fall back to the default CLOCK_REALTIME.
comment|// POSIX requires that all implementations of clock_gettime() must
comment|// support at least CLOCK_REALTIME.
endif|#
directive|endif
name|mycond
operator|->
name|clk_id
operator|=
name|CLOCK_REALTIME
expr_stmt|;
endif|#
directive|endif
return|return
name|pthread_cond_init
argument_list|(
operator|&
name|mycond
operator|->
name|cond
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_cond_destroy
parameter_list|(
name|mythread_cond
modifier|*
name|cond
parameter_list|)
block|{
name|int
name|ret
init|=
name|pthread_cond_destroy
argument_list|(
operator|&
name|cond
operator|->
name|cond
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_cond_signal
parameter_list|(
name|mythread_cond
modifier|*
name|cond
parameter_list|)
block|{
name|int
name|ret
init|=
name|pthread_cond_signal
argument_list|(
operator|&
name|cond
operator|->
name|cond
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_cond_wait
parameter_list|(
name|mythread_cond
modifier|*
name|cond
parameter_list|,
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
name|int
name|ret
init|=
name|pthread_cond_wait
argument_list|(
operator|&
name|cond
operator|->
name|cond
argument_list|,
name|mutex
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
block|}
end_function

begin_comment
comment|// Waits on a condition or until a timeout expires. If the timeout expires,
end_comment

begin_comment
comment|// non-zero is returned, otherwise zero is returned.
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|mythread_cond_timedwait
parameter_list|(
name|mythread_cond
modifier|*
name|cond
parameter_list|,
name|mythread_mutex
modifier|*
name|mutex
parameter_list|,
specifier|const
name|mythread_condtime
modifier|*
name|condtime
parameter_list|)
block|{
name|int
name|ret
init|=
name|pthread_cond_timedwait
argument_list|(
operator|&
name|cond
operator|->
name|cond
argument_list|,
name|mutex
argument_list|,
name|condtime
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
operator|||
name|ret
operator|==
name|ETIMEDOUT
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|// Sets condtime to the absolute time that is timeout_ms milliseconds
end_comment

begin_comment
comment|// in the future. The type of the clock to use is taken from cond.
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|mythread_condtime_set
parameter_list|(
name|mythread_condtime
modifier|*
name|condtime
parameter_list|,
specifier|const
name|mythread_cond
modifier|*
name|cond
parameter_list|,
name|uint32_t
name|timeout_ms
parameter_list|)
block|{
name|condtime
operator|->
name|tv_sec
operator|=
name|timeout_ms
operator|/
literal|1000
expr_stmt|;
name|condtime
operator|->
name|tv_nsec
operator|=
operator|(
name|timeout_ms
operator|%
literal|1000
operator|)
operator|*
literal|1000000
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_CLOCK_GETTIME
name|struct
name|timespec
name|now
decl_stmt|;
name|int
name|ret
init|=
name|clock_gettime
argument_list|(
name|cond
operator|->
name|clk_id
argument_list|,
operator|&
name|now
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
name|condtime
operator|->
name|tv_sec
operator|+=
name|now
operator|.
name|tv_sec
expr_stmt|;
name|condtime
operator|->
name|tv_nsec
operator|+=
name|now
operator|.
name|tv_nsec
expr_stmt|;
else|#
directive|else
operator|(
name|void
operator|)
name|cond
expr_stmt|;
name|struct
name|timeval
name|now
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|now
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|condtime
operator|->
name|tv_sec
operator|+=
name|now
operator|.
name|tv_sec
expr_stmt|;
name|condtime
operator|->
name|tv_nsec
operator|+=
name|now
operator|.
name|tv_usec
operator|*
literal|1000L
expr_stmt|;
endif|#
directive|endif
comment|// tv_nsec must stay in the range [0, 999_999_999].
if|if
condition|(
name|condtime
operator|->
name|tv_nsec
operator|>=
literal|1000000000L
condition|)
block|{
name|condtime
operator|->
name|tv_nsec
operator|-=
literal|1000000000L
expr_stmt|;
operator|++
name|condtime
operator|->
name|tv_sec
expr_stmt|;
block|}
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MYTHREAD_WIN95
argument_list|)
operator|||
name|defined
argument_list|(
name|MYTHREAD_VISTA
argument_list|)
end_elif

begin_comment
comment|/////////////////////
end_comment

begin_comment
comment|// Windows threads //
end_comment

begin_comment
comment|/////////////////////
end_comment

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MYTHREAD_VISTA
end_ifdef

begin_undef
undef|#
directive|undef
name|_WIN32_WINNT
end_undef

begin_define
define|#
directive|define
name|_WIN32_WINNT
value|0x0600
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_define
define|#
directive|define
name|MYTHREAD_RET_TYPE
value|unsigned int __stdcall
end_define

begin_define
define|#
directive|define
name|MYTHREAD_RET_VALUE
value|0
end_define

begin_typedef
typedef|typedef
name|HANDLE
name|mythread
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CRITICAL_SECTION
name|mythread_mutex
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|MYTHREAD_WIN95
end_ifdef

begin_typedef
typedef|typedef
name|HANDLE
name|mythread_cond
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|CONDITION_VARIABLE
name|mythread_cond
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
comment|// Tick count (milliseconds) in the beginning of the timeout.
comment|// NOTE: This is 32 bits so it wraps around after 49.7 days.
comment|// Multi-day timeouts may not work as expected.
name|DWORD
name|start
decl_stmt|;
comment|// Length of the timeout in milliseconds. The timeout expires
comment|// when the current tick count minus "start" is equal or greater
comment|// than "timeout".
name|DWORD
name|timeout
decl_stmt|;
block|}
name|mythread_condtime
typedef|;
end_typedef

begin_comment
comment|// mythread_once() is only available with Vista threads.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MYTHREAD_VISTA
end_ifdef

begin_define
define|#
directive|define
name|mythread_once
parameter_list|(
name|func
parameter_list|)
define|\
value|do { \ 		static INIT_ONCE once_ = INIT_ONCE_STATIC_INIT; \ 		BOOL pending_; \ 		if (!InitOnceBeginInitialize(&once_, 0,&pending_, NULL)) \ 			abort(); \ 		if (pending_) \ 			func(); \ 		if (!InitOnceComplete(&once, 0, NULL)) \ 			abort(); \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// mythread_sigmask() isn't available on Windows. Even a dummy version would
end_comment

begin_comment
comment|// make no sense because the other POSIX signal functions are missing anyway.
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|int
name|mythread_create
argument_list|(
name|mythread
operator|*
name|thread
argument_list|,
name|unsigned
name|int
argument_list|(
name|__stdcall
operator|*
name|func
argument_list|)
argument_list|(
name|void
operator|*
name|arg
argument_list|)
argument_list|,
name|void
operator|*
name|arg
argument_list|)
block|{
name|uintptr_t
name|ret
init|=
name|_beginthreadex
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|func
argument_list|,
name|arg
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
condition|)
return|return
operator|-
literal|1
return|;
operator|*
name|thread
operator|=
operator|(
name|HANDLE
operator|)
name|ret
expr_stmt|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|mythread_join
parameter_list|(
name|mythread
name|thread
parameter_list|)
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|WaitForSingleObject
argument_list|(
name|thread
argument_list|,
name|INFINITE
argument_list|)
operator|!=
name|WAIT_OBJECT_0
condition|)
name|ret
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|CloseHandle
argument_list|(
name|thread
argument_list|)
condition|)
name|ret
operator|=
operator|-
literal|1
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|mythread_mutex_init
parameter_list|(
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
name|InitializeCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_mutex_destroy
parameter_list|(
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
name|DeleteCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_mutex_lock
parameter_list|(
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
name|EnterCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_mutex_unlock
parameter_list|(
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
name|LeaveCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|mythread_cond_init
parameter_list|(
name|mythread_cond
modifier|*
name|cond
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|MYTHREAD_WIN95
operator|*
name|cond
operator|=
name|CreateEvent
argument_list|(
name|NULL
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
operator|*
name|cond
operator|==
name|NULL
condition|?
operator|-
literal|1
else|:
literal|0
return|;
else|#
directive|else
name|InitializeConditionVariable
argument_list|(
name|cond
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_cond_destroy
parameter_list|(
name|mythread_cond
modifier|*
name|cond
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|MYTHREAD_WIN95
name|CloseHandle
argument_list|(
operator|*
name|cond
argument_list|)
expr_stmt|;
else|#
directive|else
operator|(
name|void
operator|)
name|cond
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_cond_signal
parameter_list|(
name|mythread_cond
modifier|*
name|cond
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|MYTHREAD_WIN95
name|SetEvent
argument_list|(
operator|*
name|cond
argument_list|)
expr_stmt|;
else|#
directive|else
name|WakeConditionVariable
argument_list|(
name|cond
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_cond_wait
parameter_list|(
name|mythread_cond
modifier|*
name|cond
parameter_list|,
name|mythread_mutex
modifier|*
name|mutex
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|MYTHREAD_WIN95
name|LeaveCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
name|WaitForSingleObject
argument_list|(
operator|*
name|cond
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
name|EnterCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
else|#
directive|else
name|BOOL
name|ret
init|=
name|SleepConditionVariableCS
argument_list|(
name|cond
argument_list|,
name|mutex
argument_list|,
name|INFINITE
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ret
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|mythread_cond_timedwait
parameter_list|(
name|mythread_cond
modifier|*
name|cond
parameter_list|,
name|mythread_mutex
modifier|*
name|mutex
parameter_list|,
specifier|const
name|mythread_condtime
modifier|*
name|condtime
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|MYTHREAD_WIN95
name|LeaveCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|DWORD
name|elapsed
init|=
name|GetTickCount
argument_list|()
operator|-
name|condtime
operator|->
name|start
decl_stmt|;
name|DWORD
name|timeout
init|=
name|elapsed
operator|>=
name|condtime
operator|->
name|timeout
condition|?
literal|0
else|:
name|condtime
operator|->
name|timeout
operator|-
name|elapsed
decl_stmt|;
ifdef|#
directive|ifdef
name|MYTHREAD_WIN95
name|DWORD
name|ret
init|=
name|WaitForSingleObject
argument_list|(
operator|*
name|cond
argument_list|,
name|timeout
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|==
name|WAIT_OBJECT_0
operator|||
name|ret
operator|==
name|WAIT_TIMEOUT
argument_list|)
expr_stmt|;
name|EnterCriticalSection
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
name|ret
operator|==
name|WAIT_TIMEOUT
return|;
else|#
directive|else
name|BOOL
name|ret
init|=
name|SleepConditionVariableCS
argument_list|(
name|cond
argument_list|,
name|mutex
argument_list|,
name|timeout
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|ret
operator|||
name|GetLastError
argument_list|()
operator|==
name|ERROR_TIMEOUT
argument_list|)
expr_stmt|;
return|return
operator|!
name|ret
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mythread_condtime_set
parameter_list|(
name|mythread_condtime
modifier|*
name|condtime
parameter_list|,
specifier|const
name|mythread_cond
modifier|*
name|cond
parameter_list|,
name|uint32_t
name|timeout
parameter_list|)
block|{
operator|(
name|void
operator|)
name|cond
expr_stmt|;
name|condtime
operator|->
name|start
operator|=
name|GetTickCount
argument_list|()
expr_stmt|;
name|condtime
operator|->
name|timeout
operator|=
name|timeout
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

