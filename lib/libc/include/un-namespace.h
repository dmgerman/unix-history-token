begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Daniel Eischen<deischen@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UN_NAMESPACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_UN_NAMESPACE_H_
end_define

begin_undef
undef|#
directive|undef
name|accept
end_undef

begin_undef
undef|#
directive|undef
name|__acl_aclcheck_fd
end_undef

begin_undef
undef|#
directive|undef
name|__acl_delete_fd
end_undef

begin_undef
undef|#
directive|undef
name|__acl_get_fd
end_undef

begin_undef
undef|#
directive|undef
name|__acl_set_fd
end_undef

begin_undef
undef|#
directive|undef
name|bind
end_undef

begin_undef
undef|#
directive|undef
name|__cap_get_fd
end_undef

begin_undef
undef|#
directive|undef
name|__cap_set_fd
end_undef

begin_undef
undef|#
directive|undef
name|close
end_undef

begin_undef
undef|#
directive|undef
name|connect
end_undef

begin_undef
undef|#
directive|undef
name|dup
end_undef

begin_undef
undef|#
directive|undef
name|dup2
end_undef

begin_undef
undef|#
directive|undef
name|execve
end_undef

begin_undef
undef|#
directive|undef
name|fcntl
end_undef

begin_undef
undef|#
directive|undef
name|flock
end_undef

begin_undef
undef|#
directive|undef
name|flockfile
end_undef

begin_undef
undef|#
directive|undef
name|fpathconf
end_undef

begin_undef
undef|#
directive|undef
name|fstat
end_undef

begin_undef
undef|#
directive|undef
name|fstatfs
end_undef

begin_undef
undef|#
directive|undef
name|fsync
end_undef

begin_undef
undef|#
directive|undef
name|funlockfile
end_undef

begin_undef
undef|#
directive|undef
name|getdirentries
end_undef

begin_undef
undef|#
directive|undef
name|getlogin
end_undef

begin_undef
undef|#
directive|undef
name|getpeername
end_undef

begin_undef
undef|#
directive|undef
name|getprogname
end_undef

begin_undef
undef|#
directive|undef
name|getsockname
end_undef

begin_undef
undef|#
directive|undef
name|getsockopt
end_undef

begin_undef
undef|#
directive|undef
name|ioctl
end_undef

begin_undef
undef|#
directive|undef
name|kevent
end_undef

begin_undef
undef|#
directive|undef
name|listen
end_undef

begin_undef
undef|#
directive|undef
name|nanosleep
end_undef

begin_undef
undef|#
directive|undef
name|open
end_undef

begin_undef
undef|#
directive|undef
name|poll
end_undef

begin_undef
undef|#
directive|undef
name|pthread_atfork
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_destroy
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_getdetachstate
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_getguardsize
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_getstackaddr
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_getstacksize
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_getinheritsched
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_getschedparam
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_getschedpolicy
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_getscope
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_init
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_setdetachstate
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_setguardsize
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_setstackaddr
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_setstacksize
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_setinheritsched
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_setschedparam
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_setschedpolicy
end_undef

begin_undef
undef|#
directive|undef
name|pthread_attr_setscope
end_undef

begin_undef
undef|#
directive|undef
name|pthread_cancel
end_undef

begin_undef
undef|#
directive|undef
name|pthread_cleanup_pop
end_undef

begin_undef
undef|#
directive|undef
name|pthread_cleanup_push
end_undef

begin_undef
undef|#
directive|undef
name|pthread_cond_broadcast
end_undef

begin_undef
undef|#
directive|undef
name|pthread_cond_destroy
end_undef

begin_undef
undef|#
directive|undef
name|pthread_cond_init
end_undef

begin_undef
undef|#
directive|undef
name|pthread_cond_signal
end_undef

begin_undef
undef|#
directive|undef
name|pthread_cond_timedwait
end_undef

begin_undef
undef|#
directive|undef
name|pthread_cond_wait
end_undef

begin_undef
undef|#
directive|undef
name|pthread_detach
end_undef

begin_undef
undef|#
directive|undef
name|pthread_equal
end_undef

begin_undef
undef|#
directive|undef
name|pthread_exit
end_undef

begin_undef
undef|#
directive|undef
name|pthread_getspecific
end_undef

begin_undef
undef|#
directive|undef
name|pthread_join
end_undef

begin_undef
undef|#
directive|undef
name|pthread_kill
end_undef

begin_undef
undef|#
directive|undef
name|pthread_key_create
end_undef

begin_undef
undef|#
directive|undef
name|pthread_key_delete
end_undef

begin_undef
undef|#
directive|undef
name|pthread_main_np
end_undef

begin_undef
undef|#
directive|undef
name|pthread_mutex_destroy
end_undef

begin_undef
undef|#
directive|undef
name|pthread_mutex_init
end_undef

begin_undef
undef|#
directive|undef
name|pthread_mutex_lock
end_undef

begin_undef
undef|#
directive|undef
name|pthread_mutex_trylock
end_undef

begin_undef
undef|#
directive|undef
name|pthread_mutex_unlock
end_undef

begin_undef
undef|#
directive|undef
name|pthread_mutexattr_destroy
end_undef

begin_undef
undef|#
directive|undef
name|pthread_mutexattr_init
end_undef

begin_undef
undef|#
directive|undef
name|pthread_mutexattr_destroy
end_undef

begin_undef
undef|#
directive|undef
name|pthread_mutexattr_settype
end_undef

begin_undef
undef|#
directive|undef
name|pthread_once
end_undef

begin_undef
undef|#
directive|undef
name|pthread_rwlock_destroy
end_undef

begin_undef
undef|#
directive|undef
name|pthread_rwlock_init
end_undef

begin_undef
undef|#
directive|undef
name|pthread_rwlock_rdlock
end_undef

begin_undef
undef|#
directive|undef
name|pthread_rwlock_wrlock
end_undef

begin_undef
undef|#
directive|undef
name|pthread_rwlock_tryrdlock
end_undef

begin_undef
undef|#
directive|undef
name|pthread_rwlock_trywrlock
end_undef

begin_undef
undef|#
directive|undef
name|pthread_rwlock_unlock
end_undef

begin_undef
undef|#
directive|undef
name|pthread_self
end_undef

begin_undef
undef|#
directive|undef
name|pthread_setcancelstate
end_undef

begin_undef
undef|#
directive|undef
name|pthread_setcanceltype
end_undef

begin_undef
undef|#
directive|undef
name|pthread_setspecific
end_undef

begin_undef
undef|#
directive|undef
name|pthread_sigmask
end_undef

begin_undef
undef|#
directive|undef
name|pthread_testcancel
end_undef

begin_undef
undef|#
directive|undef
name|read
end_undef

begin_undef
undef|#
directive|undef
name|readv
end_undef

begin_undef
undef|#
directive|undef
name|recvfrom
end_undef

begin_undef
undef|#
directive|undef
name|recvmsg
end_undef

begin_undef
undef|#
directive|undef
name|select
end_undef

begin_undef
undef|#
directive|undef
name|sendmsg
end_undef

begin_undef
undef|#
directive|undef
name|sendto
end_undef

begin_undef
undef|#
directive|undef
name|setsockopt
end_undef

begin_undef
undef|#
directive|undef
name|sigaction
end_undef

begin_undef
undef|#
directive|undef
name|sigprocmask
end_undef

begin_undef
undef|#
directive|undef
name|sigsuspend
end_undef

begin_undef
undef|#
directive|undef
name|socket
end_undef

begin_undef
undef|#
directive|undef
name|socketpair
end_undef

begin_undef
undef|#
directive|undef
name|usleep
end_undef

begin_undef
undef|#
directive|undef
name|wait4
end_undef

begin_undef
undef|#
directive|undef
name|waitpid
end_undef

begin_undef
undef|#
directive|undef
name|write
end_undef

begin_undef
undef|#
directive|undef
name|writev
end_undef

begin_if
if|#
directive|if
literal|0
end_if

begin_undef
undef|#
directive|undef
name|creat
end_undef

begin_undef
undef|#
directive|undef
name|fchflags
end_undef

begin_undef
undef|#
directive|undef
name|fchmod
end_undef

begin_undef
undef|#
directive|undef
name|ftrylockfile
end_undef

begin_undef
undef|#
directive|undef
name|msync
end_undef

begin_undef
undef|#
directive|undef
name|nfssvc
end_undef

begin_undef
undef|#
directive|undef
name|pause
end_undef

begin_undef
undef|#
directive|undef
name|pthread_rwlockattr_init
end_undef

begin_undef
undef|#
directive|undef
name|pthread_rwlockattr_destroy
end_undef

begin_undef
undef|#
directive|undef
name|sched_yield
end_undef

begin_undef
undef|#
directive|undef
name|sendfile
end_undef

begin_undef
undef|#
directive|undef
name|shutdown
end_undef

begin_undef
undef|#
directive|undef
name|sigaltstack
end_undef

begin_undef
undef|#
directive|undef
name|sigpending
end_undef

begin_undef
undef|#
directive|undef
name|sigreturn
end_undef

begin_undef
undef|#
directive|undef
name|sigsetmask
end_undef

begin_undef
undef|#
directive|undef
name|sleep
end_undef

begin_undef
undef|#
directive|undef
name|system
end_undef

begin_undef
undef|#
directive|undef
name|tcdrain
end_undef

begin_undef
undef|#
directive|undef
name|wait
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SIGNAL_H_
end_ifdef

begin_function_decl
name|int
name|_sigaction
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sigaction
modifier|*
parameter_list|,
name|struct
name|sigaction
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_EVENT_H_
end_ifdef

begin_function_decl
name|int
name|_kevent
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|kevent
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|kevent
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_FCNTL_H_
end_ifdef

begin_function_decl
name|int
name|_flock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|err
end_undef

begin_undef
undef|#
directive|undef
name|warn
end_undef

begin_undef
undef|#
directive|undef
name|nsdispatch
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UN_NAMESPACE_H_ */
end_comment

end_unit

