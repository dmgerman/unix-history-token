begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Daniel Eischen<deischen@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NAMESPACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NAMESPACE_H_
end_define

begin_comment
comment|/*  * Adjust names so that headers declare "hidden" names.  */
end_comment

begin_comment
comment|/*  * ISO C (C90) section.  Most names in libc aren't in ISO C, so they  * should be here.  Most aren't here...  */
end_comment

begin_define
define|#
directive|define
name|err
value|_err
end_define

begin_define
define|#
directive|define
name|warn
value|_warn
end_define

begin_comment
comment|/*  * Prototypes for syscalls/functions that need to be overridden  * in libc_r/libpthread.  */
end_comment

begin_define
define|#
directive|define
name|accept
value|_accept
end_define

begin_define
define|#
directive|define
name|__acl_aclcheck_fd
value|___acl_aclcheck_fd
end_define

begin_define
define|#
directive|define
name|__acl_delete_fd
value|___acl_delete_fd
end_define

begin_define
define|#
directive|define
name|__acl_get_fd
value|___acl_get_fd
end_define

begin_define
define|#
directive|define
name|__acl_set_fd
value|___acl_set_fd
end_define

begin_define
define|#
directive|define
name|bind
value|_bind
end_define

begin_define
define|#
directive|define
name|__cap_get_fd
value|___cap_get_fd
end_define

begin_define
define|#
directive|define
name|__cap_set_fd
value|___cap_set_fd
end_define

begin_define
define|#
directive|define
name|close
value|_close
end_define

begin_define
define|#
directive|define
name|connect
value|_connect
end_define

begin_define
define|#
directive|define
name|dup
value|_dup
end_define

begin_define
define|#
directive|define
name|dup2
value|_dup2
end_define

begin_define
define|#
directive|define
name|execve
value|_execve
end_define

begin_define
define|#
directive|define
name|fcntl
value|_fcntl
end_define

begin_comment
comment|/*#define		flock				_flock */
end_comment

begin_define
define|#
directive|define
name|flockfile
value|_flockfile
end_define

begin_define
define|#
directive|define
name|fstat
value|_fstat
end_define

begin_define
define|#
directive|define
name|fstatfs
value|_fstatfs
end_define

begin_define
define|#
directive|define
name|fsync
value|_fsync
end_define

begin_define
define|#
directive|define
name|funlockfile
value|_funlockfile
end_define

begin_define
define|#
directive|define
name|getdirentries
value|_getdirentries
end_define

begin_define
define|#
directive|define
name|getlogin
value|_getlogin
end_define

begin_define
define|#
directive|define
name|getpeername
value|_getpeername
end_define

begin_define
define|#
directive|define
name|getsockname
value|_getsockname
end_define

begin_define
define|#
directive|define
name|getsockopt
value|_getsockopt
end_define

begin_define
define|#
directive|define
name|ioctl
value|_ioctl
end_define

begin_comment
comment|/* #define		kevent				_kevent */
end_comment

begin_define
define|#
directive|define
name|listen
value|_listen
end_define

begin_define
define|#
directive|define
name|nanosleep
value|_nanosleep
end_define

begin_define
define|#
directive|define
name|open
value|_open
end_define

begin_define
define|#
directive|define
name|poll
value|_poll
end_define

begin_define
define|#
directive|define
name|pthread_cond_signal
value|_pthread_cond_signal
end_define

begin_define
define|#
directive|define
name|pthread_cond_wait
value|_pthread_cond_wait
end_define

begin_define
define|#
directive|define
name|pthread_cond_init
value|_pthread_cond_init
end_define

begin_define
define|#
directive|define
name|pthread_exit
value|_pthread_exit
end_define

begin_define
define|#
directive|define
name|pthread_getspecific
value|_pthread_getspecific
end_define

begin_define
define|#
directive|define
name|pthread_key_create
value|_pthread_key_create
end_define

begin_define
define|#
directive|define
name|pthread_key_delete
value|_pthread_key_delete
end_define

begin_define
define|#
directive|define
name|pthread_main_np
value|_pthread_main_np
end_define

begin_define
define|#
directive|define
name|pthread_mutex_destroy
value|_pthread_mutex_destroy
end_define

begin_define
define|#
directive|define
name|pthread_mutex_init
value|_pthread_mutex_init
end_define

begin_define
define|#
directive|define
name|pthread_mutex_lock
value|_pthread_mutex_lock
end_define

begin_define
define|#
directive|define
name|pthread_mutex_trylock
value|_pthread_mutex_trylock
end_define

begin_define
define|#
directive|define
name|pthread_mutex_unlock
value|_pthread_mutex_unlock
end_define

begin_define
define|#
directive|define
name|pthread_mutexattr_init
value|_pthread_mutexattr_init
end_define

begin_define
define|#
directive|define
name|pthread_mutexattr_destroy
value|_pthread_mutexattr_destroy
end_define

begin_define
define|#
directive|define
name|pthread_mutexattr_settype
value|_pthread_mutexattr_settype
end_define

begin_define
define|#
directive|define
name|pthread_once
value|_pthread_once
end_define

begin_define
define|#
directive|define
name|pthread_rwlock_init
value|_pthread_rwlock_init
end_define

begin_define
define|#
directive|define
name|pthread_rwlock_rdlock
value|_pthread_rwlock_rdlock
end_define

begin_define
define|#
directive|define
name|pthread_rwlock_wrlock
value|_pthread_rwlock_wrlock
end_define

begin_define
define|#
directive|define
name|pthread_rwlock_unlock
value|_pthread_rwlock_unlock
end_define

begin_define
define|#
directive|define
name|pthread_self
value|_pthread_self
end_define

begin_define
define|#
directive|define
name|pthread_setspecific
value|_pthread_setspecific
end_define

begin_define
define|#
directive|define
name|pthread_sigmask
value|_pthread_sigmask
end_define

begin_define
define|#
directive|define
name|read
value|_read
end_define

begin_define
define|#
directive|define
name|readv
value|_readv
end_define

begin_define
define|#
directive|define
name|recvfrom
value|_recvfrom
end_define

begin_define
define|#
directive|define
name|recvmsg
value|_recvmsg
end_define

begin_define
define|#
directive|define
name|select
value|_select
end_define

begin_define
define|#
directive|define
name|sendmsg
value|_sendmsg
end_define

begin_define
define|#
directive|define
name|sendto
value|_sendto
end_define

begin_define
define|#
directive|define
name|setsockopt
value|_setsockopt
end_define

begin_comment
comment|/*#define		sigaction			_sigaction*/
end_comment

begin_define
define|#
directive|define
name|sigprocmask
value|_sigprocmask
end_define

begin_define
define|#
directive|define
name|sigsuspend
value|_sigsuspend
end_define

begin_define
define|#
directive|define
name|socket
value|_socket
end_define

begin_define
define|#
directive|define
name|socketpair
value|_socketpair
end_define

begin_define
define|#
directive|define
name|wait4
value|_wait4
end_define

begin_define
define|#
directive|define
name|write
value|_write
end_define

begin_define
define|#
directive|define
name|writev
value|_writev
end_define

begin_comment
comment|/*  * Other hidden syscalls/functions that libc_r needs to override  * but are not used internally by libc.  *  * XXX - When modifying libc to use one of the following, remove  * the prototype from below and place it in the list above.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|creat
value|_creat
end_define

begin_define
define|#
directive|define
name|fchflags
value|_fchflags
end_define

begin_define
define|#
directive|define
name|fchmod
value|_fchmod
end_define

begin_define
define|#
directive|define
name|fpathconf
value|_fpathconf
end_define

begin_define
define|#
directive|define
name|ftrylockfile
value|_ftrylockfile
end_define

begin_define
define|#
directive|define
name|msync
value|_msync
end_define

begin_define
define|#
directive|define
name|nfssvc
value|_nfssvc
end_define

begin_define
define|#
directive|define
name|pause
value|_pause
end_define

begin_define
define|#
directive|define
name|pthread_rwlock_destroy
value|_pthread_rwlock_destroy
end_define

begin_define
define|#
directive|define
name|pthread_rwlock_tryrdlock
value|_pthread_rwlock_tryrdlock
end_define

begin_define
define|#
directive|define
name|pthread_rwlock_trywrlock
value|_pthread_rwlock_trywrlock
end_define

begin_define
define|#
directive|define
name|pthread_rwlockattr_init
value|_pthread_rwlockattr_init
end_define

begin_define
define|#
directive|define
name|pthread_rwlockattr_destroy
value|_pthread_rwlockattr_destroy
end_define

begin_define
define|#
directive|define
name|sched_yield
value|_sched_yield
end_define

begin_define
define|#
directive|define
name|sendfile
value|_sendfile
end_define

begin_define
define|#
directive|define
name|shutdown
value|_shutdown
end_define

begin_define
define|#
directive|define
name|sigaltstack
value|_sigaltstack
end_define

begin_define
define|#
directive|define
name|sigpending
value|_sigpending
end_define

begin_define
define|#
directive|define
name|sigreturn
value|_sigreturn
end_define

begin_define
define|#
directive|define
name|sigsetmask
value|_sigsetmask
end_define

begin_define
define|#
directive|define
name|sleep
value|_sleep
end_define

begin_define
define|#
directive|define
name|system
value|_system
end_define

begin_define
define|#
directive|define
name|tcdrain
value|_tcdrain
end_define

begin_define
define|#
directive|define
name|wait
value|_wait
end_define

begin_define
define|#
directive|define
name|waitpid
value|_waitpid
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
comment|/* _NAMESPACE_H_ */
end_comment

end_unit

